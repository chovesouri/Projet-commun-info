<?php
session_start();
require_once 'fonctions_utilitaires.php';

// Récupérer l'utilisateur s'il est connecté
$utilisateur = obtenir_utilisateur_connecte();
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Yumland - Accueil</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php include 'bandeau_dynamique.php'; ?>

    <?php if (est_connecte()): ?>
    <div class="user-welcome">
        <h3>👋 Bienvenue, <?php echo htmlspecialchars($utilisateur['prenom'] ?? $utilisateur['email']); ?> !</h3>
        <div class="user-info">
            <p>Connecté en tant que: <strong><?php echo htmlspecialchars($utilisateur['email']); ?></strong></p>
        </div>
    </div>
    <?php endif; ?>

    <!-- Section Sushi du mois -->
    <section class="sushi-section">
        <h2 class="sushi-du-mois-title">Sushis et Makis du Mois !</h2>
        <div class="sushi-cards-container">
            <div class="sushi-card">
                <img src="images/maki_caramel.png" alt="Maki Caramel">
                <div class="sushi-content">
                    <p>Maki caramel et œufs de saumon</p>
                </div>
            </div>
            <div class="sushi-card">
                <img src="images/maki_banane.png" alt="Maki banane">
                <div class="sushi-content">
                    <p>maki banane truite</p>
                </div>
            </div>
            <div class="sushi-card">
                <img src="images/maki_boursin_sprinkles.png" alt="Maki boursin sprinkles">
                <div class="sushi-content">
                    <p>maki boursin sprinkles</p>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Recette Incontournable -->
    <section class="recette-incontournable-section">
        <h2 class="recette-incontournable-title">Recette Incontournable</h2>
        <div class="recette-card">
            <img src="images/maki_wasabi.jpeg" alt="Sushi Incontournable">
            <div class="recette-content">
                <p>maki pâte à cookie crue et wasabi sucré</p>
            </div>
        </div>
    </section>
</body>
</html>
