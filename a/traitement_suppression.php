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
        'message' => 'Accès refusé: seuls les administrateurs peuvent supprimer des profils'
    ]);
    exit;
}

// Récupérer l'action demandée
$action = $_POST['action'] ?? $_GET['action'] ?? null;

if ($action === 'supprimer_profil') {
    // Récupérer l'email de l'utilisateur à supprimer
    $email = $_POST['email'] ?? null;
    
    if (!$email) {
        http_response_code(400);
        echo json_encode([
            'success' => false,
            'message' => 'Email manquant'
        ]);
        exit;
    }
    
    // Supprimer l'utilisateur
    $resultat = supprimer_utilisateur($email);
    
    if ($resultat['success']) {
        http_response_code(200);
    } else {
        http_response_code(400);
    }
    
    echo json_encode($resultat);
    exit;
}

// Action non reconnue
http_response_code(400);
echo json_encode([
    'success' => false,
    'message' => 'Action non reconnue'
]);
?>
