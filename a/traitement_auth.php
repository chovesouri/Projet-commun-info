<?php
// Démarrer la session
session_start();

// Inclure les fonctions utilitaires
require_once 'fonctions_utilitaires.php';

$response = [
    'success' => false,
    'message' => '',
    'type' => '' // 'connexion' ou 'inscription'
];

// Vérifier que c'est une requête POST
if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    http_response_code(405);
    die(json_encode(['error' => 'Méthode non autorisée']));
}

// Récupérer les données
$email = trim($_POST['email'] ?? '');
$password = trim($_POST['password'] ?? '');
$action = $_POST['action'] ?? 'connexion'; // 'connexion' ou 'inscription'

// Validation basique
if (empty($email) || empty($password)) {
    $response['message'] = 'Email et mot de passe requis';
    echo json_encode($response);
    exit;
}

// Valider l'email
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    $response['message'] = 'Email invalide';
    echo json_encode($response);
    exit;
}

if ($action === 'connexion') {
    // ===== PHASE DE CONNEXION =====
    $result = verifier_identifiants($email, $password);
    
    if ($result['success']) {
        demarrer_session_utilisateur($result['profil']);
        $response['success'] = true;
        $response['type'] = 'connexion';
        $response['message'] = 'Connexion réussie';
        $response['redirect'] = 'page_accueil.php';
    } else {
        $response['message'] = $result['message'];
    }
    
} elseif ($action === 'inscription') {
    // ===== PHASE D'INSCRIPTION =====
    
    // Valider l'email avec la fonction complète
    $validation_email = valider_email($email);
    if (!$validation_email['valide']) {
        $response['message'] = $validation_email['message'];
        echo json_encode($response);
        exit;
    }
    
    // Valider le mot de passe
    $validation_password = valider_mot_de_passe($password);
    if (!$validation_password['valide']) {
        $response['message'] = $validation_password['message'];
        echo json_encode($response);
        exit;
    }
    
    // Vérifier si l'utilisateur existe déjà
    if (chercher_utilisateur_par_email($email) !== null) {
        $response['message'] = 'Cet email est déjà utilisé';
        echo json_encode($response);
        exit;
    }
    
    // Récupérer les données optionnelles d'inscription
    $nom = trim($_POST['nom'] ?? '');
    $prenom = trim($_POST['prenom'] ?? '');
    $adresse = trim($_POST['adresse'] ?? '');
    $telephone = trim($_POST['telephone'] ?? '');
    
    // Créer le nouveau profil
    try {
        $nouveau_profil = creer_profil_client($email, $password, $nom, $prenom, $adresse, $telephone);
        demarrer_session_utilisateur($nouveau_profil);
        
        $response['success'] = true;
        $response['type'] = 'inscription';
        $response['message'] = 'Inscription réussie !';
        $response['redirect'] = 'page_accueil.php';
        $response['num_client'] = $nouveau_profil['num_client'];
        
    } catch (Exception $e) {
        $response['message'] = 'Erreur lors de l\'inscription: ' . $e->getMessage();
    }
} else {
    $response['message'] = 'Action non reconnue';
}

// Retourner la réponse
header('Content-Type: application/json');
echo json_encode($response);
?>
