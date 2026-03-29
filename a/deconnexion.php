<?php
// deconnexion.php - Page de déconnexion

session_start();
require_once 'fonctions_utilitaires.php';

// Détruire la session
session_destroy();

// Rediriger vers la page d'accueil
header('Location: page_accueil.php');
exit;
?>
