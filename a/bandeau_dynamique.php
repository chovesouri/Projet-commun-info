<?php
session_start();
require_once 'fonctions_utilitaires.php';
?>
<header class="welcome-banner">
    <div class="left">
        <img class="logo-sushine" src="images/logo.png" alt="Logo Sushine">
    </div>

    <div class="center">
        <div class="button-container">
            <?php if (est_connecte()): ?>
                <?php $user = obtenir_utilisateur_connecte(); ?>
                <?php if ($user['role'] === 'admin'): ?>
                    <!-- Menu pour admin -->
                    <a class="menu-link" href="page_administrateur.php">Gestion des utilisateurs</a>
                    <a class="menu-link" href="travaux.php">Travaux</a>
                <?php else: ?>
                    <!-- Menu pour clients -->
                    <a class="menu-link" href="page_accueil.php">Accueil</a>
                    <a class="menu-link" href="commande-client.php">Commande</a>
                <?php endif; ?>
            <?php else: ?>
                <!-- Menu pour non connectés -->
                <a class="menu-link" href="page_accueil.php">Accueil</a>
                <a class="menu-link" href="commande-client.php">Commande</a>
            <?php endif; ?>
        </div>
    </div>

    <div class="right">
        <?php if (est_connecte()): ?>
            <?php $user = obtenir_utilisateur_connecte(); ?>
            <?php if ($user['role'] !== 'admin'): ?>
                <button class="mon-compte-button"><a href="page_profil.php">Mon Compte</a></button>
            <?php endif; ?>
            <button class="mon-compte-button"><a href="deconnexion.php">Déconnexion</a></button>
        <?php else: ?>
            <button class="mon-compte-button"><a href="page_connexion.php">Connexion</a></button>
        <?php endif; ?>
    </div>
</header>
