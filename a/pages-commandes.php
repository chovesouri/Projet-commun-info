<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Commandes - Restaurateur</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<?php 
session_start();
require_once 'fonctions_utilitaires.php';
include 'bandeau_dynamique.php';
?>

<div class="profile-page">
    <div class="container">

        <div class="section">
            <h3>Commandes en attente de préparation</h3>

            <ul class="orders-list">

                <li class="order attente">
                    
                    <button class="mon-compte-button">
                        Passer en livraison
                    </button>
                </li>

                <li class="order attente">
                    
                    <button class="mon-compte-button">
                        Passer en livraison
                    </button>
                </li>

            </ul>
        </div>


        <div class="section">
            <h3>Commandes en cours de livraison</h3>

            <ul class="orders-list">

                <li class="order livraison">
                  
                    <button class="menu-button">
                        Marquer comme livrée
                    </button>
                </li>

            </ul>
        </div>

    </div>
</div>

</body>
</html>
