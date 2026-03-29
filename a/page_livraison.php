<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=1024">
    <title>Livraison</title>
    <!-- lien vers le fichier global de styles déjà présent -->
    <link rel="stylesheet" href="style.css">
</head>
<body class="profile-page" style="min-width:1024px">
    <!-- page width fixed, desktop only -->
    <?php 
    session_start();
    require_once 'fonctions_utilitaires.php';
    include 'bandeau_dynamique.php';
    ?>

    <!-- main container like admin page -->
    <div class="container">
        <h2>Livraison</h2>
        <ul class="orders-list livraison-info">
            <!-- exemples statiques de commandes de livraison -->
            <li class="order">
                <div>Commande : #2026001</div>
                <div>Téléphone : <a href="tel:0612345678">06 12 34 56 78</a></div>
                <div>Adresse : <a href="https://www.google.com/maps/search/?api=1&query=12+rue+des+Fleurs+75001+Paris" target="_blank">12 rue des Fleurs, 75001 Paris</a></div>
            </li>
            <li class="order">
                <div>Commande : #2026002</div>
                <div>Téléphone : <a href="tel:0698765432">06 98 76 54 32</a></div>
                <div>Adresse : <a href="https://www.google.com/maps/search/?api=1&query=34+avenue+du+Soleil+75002+Paris" target="_blank">34 avenue du Soleil, 75002 Paris</a></div>
            </li>
        </ul>
    </div>

</body>
</html>