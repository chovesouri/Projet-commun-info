<?php
// verifier_connexion.php - À inclure au début de chaque page protégée

session_start();
require_once 'fonctions_utilitaires.php';

// Vérifier si l'utilisateur est connecté
if (!est_connecte()) {
    // Rediriger vers la page de connexion
    header('Location: page_connexion.php');
    exit;
}

// Récupérer l'utilisateur connecté
$utilisateur = obtenir_utilisateur_connecte();
?>
