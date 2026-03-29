<?php
session_start();
require_once 'fonctions_utilitaires.php';
require_once 'verifier_connexion.php';

// Vérifier si l'utilisateur est admin
if (!est_admin()) {
    echo "Accès refusé: seuls les administrateurs peuvent accéder à cette page.";
    exit;
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Travaux - Yumland</title>
    <link rel="stylesheet" href="style.css">
</head>
<body class="profile-page">
<header class="welcome-banner">
    <div class="left">
        <img class="logo-sushine" src="images/logo.png" alt="Logo Sushine">
    </div>

    <div class="center">
        <div class="button-container">
            <a class="menu-link" href="page_administrateur.php">Gestion des utilisateurs</a>
            <a class="menu-link" href="travaux.php" style="font-weight: bold;">Travaux</a>
        </div>
    </div>

    <div class="right">
        <button class="mon-compte-button"><a href="deconnexion.php">Déconnexion</a></button>
    </div>
</header>

<div class="container">
    <div class="travaux-container">
        <div class="construction-icon">🚧</div>
        <h2>En construction</h2>
        <p>Cette page est actuellement en développement.</p>
        <p>Les fonctionnalités seront ajoutées prochainement.</p>
    </div>
</div>
</body>
</html>
