<?php
session_start();
header('Content-Type: application/json');

require_once 'fonctions_utilitaires.php';

// Vérifier que l'utilisateur est connecté
if (!est_connecte()) {
    http_response_code(401);
    echo json_encode([
        'success' => false,
        'message' => 'Non authentifié'
    ]);
    exit;
}

// Vérifier que l'utilisateur est admin
if (!est_admin()) {
    http_response_code(403);
    echo json_encode([
        'success' => false,
        'message' => 'Accès refusé: seuls les administrateurs peuvent modifier les rôles'
    ]);
    exit;
}

// Récupérer l'action demandée
$action = $_POST['action'] ?? $_GET['action'] ?? null;

if ($action === 'modifier_role') {
    // Récupérer les paramètres
    $email = $_POST['email'] ?? null;
    $nouveau_role = $_POST['nouveau_role'] ?? null;
    
    if (!$email || !$nouveau_role) {
        http_response_code(400);
        echo json_encode([
            'success' => false,
            'message' => 'Paramètres manquants: email et nouveau_role requis'
        ]);
        exit;
    }
    
    // Modifier le rôle
    $resultat = modifier_role_utilisateur($email, $nouveau_role);
    
    if ($resultat['success']) {
        http_response_code(200);
    } else {
        http_response_code(400);
    }
    
    echo json_encode($resultat);
    exit;
}

if ($action === 'lister_utilisateurs') {
    $utilisateurs = obtenir_tous_les_utilisateurs();
    
    echo json_encode([
        'success' => true,
        'utilisateurs' => $utilisateurs
    ]);
    exit;
}

// Action non reconnue
http_response_code(400);
echo json_encode([
    'success' => false,
    'message' => 'Action non reconnue'
]);
?>
