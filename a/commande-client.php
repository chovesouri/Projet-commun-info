<?php
session_start();
require_once 'fonctions_utilitaires.php';

$utilisateur = obtenir_utilisateur_connecte();
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Yumland - Commande</title>
    <link rel="stylesheet" href="style.css">
    <meta name="description" content="Yumland - Commande de sushis créatifs">
</head>
<body>
    <?php include 'bandeau_dynamique.php'; ?>

    <main class="menu-section" id="menu">
        <div class="container">
            <h2>Nos menus</h2>
            <div class="sushi-grid">
                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/menu_degustation.png" alt="Menu Dégustation">
                    </div>
                    <div class="card-body">
                        <h3>Menu Dégustation</h3>
                        <p class="desc">2 Nuttela-Roquefort, 2 Nuttela-Chorizo, 2 Raclette-Ananas, 2 Cookie-Wasabi, 2 Foie-gras-Pop-corn, 2 Saucisson-Cornichon, 1 shot mystère.</p>
                        <div class="card-foot">
                            <span class="price">8€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/menu_bout_du_rouleau.png" alt="Menu Bout du Rouleau">
                    </div>
                    <div class="card-body">
                        <h3>Menu Bout du Rouleau</h3>
                        <p class="desc">2 maki Banane-Jambon-cru, 2 Suhsi Foie-gras Popcorn-Caramel, 2Maki Pate à cookie crue -wasabi sucrée, 2 Maki Boursin-bonbons, 2 Sushis Mystères du chef, 1 boisson "Potion interdite"</p>
                        <div class="card-foot">
                            <span class="price">8€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/menu_du_brave.png" alt="Menu du brave">
                    </div>
                    <div class="card-body">
                        <h3>Menu du brave</h3>
                        <p class="desc">2 Sushi Raclette-Ananas, 2 Maki Nutella-Chorizo, 3 Sushi Bacon-Sirop d'érable, 6 Sushi Roulette ultra pimenté, un coktail Wasabi Kiss</p>
                        <div class="card-foot">
                            <span class="price">8€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>
            </div>

            <h2>Nos Sushis à la carte</h2>
            <div class="sushi-grid">
                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/Nutella-Roquefort.png" alt="Nutella Roquefort">
                    </div>
                    <div class="card-body">
                        <h3>Nutella Roquefort</h3>
                        <p class="desc">Nutella et Roquefort — une touche sucrée-salée originale.</p>
                        <div class="card-foot">
                            <span class="price">8€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/FoieGras-Popcorn.png" alt="Foie gras Popcorn">
                    </div>
                    <div class="card-body">
                        <h3>Foie gras Popcorn</h3>
                        <p class="desc">Foie gras et popcorn — contraste croustillant.</p>
                        <div class="card-foot">
                            <span class="price">9,00€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/Pate-cookie-wasabi.png" alt="Pâte à cookie crue wasabi sucrée">
                    </div>
                    <div class="card-body">
                        <h3>Pâte à Cookie Wasabi</h3>
                        <p class="desc">Pâte à cookie crue relevée d'une pointe de wasabi.</p>
                        <div class="card-foot">
                            <span class="price">8,00€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>
            </div>

            <h2>Boissons</h2>
            <div class="sushi-grid">
                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/the-glace.png" alt="Thé glacé">
                    </div>
                    <div class="card-body">
                        <h3>Thé glacé maison</h3>
                        <p class="desc">Thé infusé, citron et touche de miel.</p>
                        <div class="card-foot">
                            <span class="price">3,00€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/coca.png" alt="coca">
                    </div>
                    <div class="card-body">
                        <h3>Coca-Cola</h3>
                        <p class="desc">Canette de soda (33cl).</p>
                        <div class="card-foot">
                            <span class="price">2,50€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>

                <article class="sushi-card">
                    <div class="img-wrap">
                        <img src="images/cocktail-melange-malicieux.png" alt="Cocktail mélange malicieux">
                    </div>
                    <div class="card-body">
                        <h3>Cocktail "mélange malicieux" maison</h3>
                        <p class="desc">Cocktail de saveurs toutes plus originales les unes que les autres. Ingrédients: mangue, banane, ananas, kiwi, grenade, cacahuette, fraise, caramel, chocolat</p>
                        <div class="card-foot">
                            <span class="price">8,00€</span>
                            <button class="add-button">Ajouter</button>
                        </div>
                    </div>
                </article>
            </div>

        </div>
    </main>

    <footer class="site-footer">
        <div class="container">© 2026 Yumland — Livraison & retrait</div>
    </footer>

</body>
</html>