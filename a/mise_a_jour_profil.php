<?php
// mise_a_jour_profil.php - Traite les modifications de profil

session_start();
require_once 'fonctions_utilitaires.php';

// Vérifier que l'utilisateur est connecté
if (!est_connecte()) {
    http_response_code(401);
    die(json_encode(['error' => 'Non authentifié']));
}

if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    http_response_code(405);
    die(json_encode(['error' => 'Méthode non autorisée']));
}

$utilisateur = obtenir_utilisateur_connecte();
$email = $utilisateur['email'];

// Récupérer les données
$nom = trim($_POST['nom'] ?? '');
$prenom = trim($_POST['prenom'] ?? '');
$adresse = trim($_POST['adresse'] ?? '');
$telephone = trim($_POST['telephone'] ?? '');

// Charger tous les profils
$profils = charger_profils();

// Trouver et mettre à jour le profil
$found = false;
foreach ($profils as &$p) {
    if (isset($p['mail']) && $p['mail'] === $email) {
        $p['nom'] = $nom;
        $p['prenom'] = $prenom;
        $p['adresse'] = $adresse;
        $p['num_téléphone'] = $telephone;
        $found = true;
        break;
    }
}

if (!$found) {
    http_response_code(404);
    die(json_encode(['success' => false, 'message' => 'Profil non trouvé']));
}

// Sauvegarder les modifications
sauvegarder_profils($profils);

// Mettre à jour la session
$_SESSION['utilisateur']['nom'] = $nom;
$_SESSION['utilisateur']['prenom'] = $prenom;

header('Content-Type: application/json');
echo json_encode([
    'success' => true,
    'message' => '✓ Profil mis à jour avec succès'
]);
?>
