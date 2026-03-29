<?php
session_start();
require_once 'fonctions_utilitaires.php';

// Fonction pour afficher des résultats de test
function test_result($nom, $result, $expected = true) {
    $status = ($result === $expected) ? '✓ PASS' : '✗ FAIL';
    $css_class = ($result === $expected) ? 'pass' : 'fail';
    echo "<div class='test-result $css_class'><strong>$status:</strong> $nom</div>";
}

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Test Page - Systèmes d'Authentification</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<h1>🧪 Test du système d'authentification</h1>

<div class="test-section">
    <h2>1️⃣ Vérification des fichiers</h2>
    <?php
    test_result("Fichier fonctions_utilitaires.php existe", file_exists('fonctions_utilitaires.php'));
    test_result("Fichier traitement_auth.php existe", file_exists('traitement_auth.php'));
    test_result("Fichier base_de_profils.json existe", file_exists('base_de_profils.json'));
    test_result("Fichier README_AUTHENTIFICATION.md existe", file_exists('README_AUTHENTIFICATION.md'));
    ?>
</div>

<div class="test-section">
    <h2>2️⃣ Vérification des données</h2>
    <?php
    $profils = charger_profils();
    test_result("Profils chargés avec succès", is_array($profils), true);
    test_result("Au moins un profil existe", count($profils) > 0, true);
    
    if (count($profils) > 0) {
        echo "<p><strong>Profils présents dans base_de_profils.json:</strong></p>";
        foreach ($profils as $i => $p) {
            $email = $p['mail'] ?? 'N/A';
            $nom = ($p['prenom'] ?? '') . ' ' . ($p['nom'] ?? '');
            $num = $p['num_client'] ?? 'N/A';
            echo "<div class='profile-item'>";
            echo "<strong>#$num</strong> - $email - $nom";
            echo "</div>";
        }
    }
    ?>
</div>

<div class="test-section">
    <h2>3️⃣ Vérification des fonctions</h2>
    <?php
    // Tester la fonction de recherche
    if (count($profils) > 0 && isset($profils[0]['mail'])) {
        $email_test = $profils[0]['mail'];
        $user = chercher_utilisateur_par_email($email_test);
        test_result("Fonction chercher_utilisateur_par_email fonctionne", 
                   !is_null($user) && $user['mail'] === $email_test, true);
    }
    
    // Tester la générations de numéro client
    $next_num = generer_num_client();
    test_result("Fonction generer_num_client fonctionne", is_numeric($next_num), true);
    echo "<p>Prochain numéro client sera: <strong>#$next_num</strong></p>";
    ?>
</div>

<div class="test-section">
    <h2>4️⃣ Vérification des sessions</h2>
    <?php
    if (est_connecte()) {
        $user = obtenir_utilisateur_connecte();
        echo "<div class='test-info test-info-success'>";
        echo "<p style='margin: 0;'><strong>✓ Vous êtes connecté</strong></p>";
        echo "<p style='margin: 5px 0;'>Email: " . htmlspecialchars($user['email']) . "</p>";
        echo "<p style='margin: 5px 0;'>Client #" . htmlspecialchars($user['num_client'] ?? 'N/A') . "</p>";
        echo "</div>";
    } else {
        echo "<div class='test-info test-info-neutral'>";
        echo "<p style='margin: 0;'><span>ℹ</span> Aucune session active</p>";
        echo "</div>";
    }
    ?>
</div>

<div class="test-section">
    <h2>🔗 Liens de navigation</h2>
    <a href="page_accueil.php" class="nav-button nav-button-home">↪ Accueil</a>
    <a href="page_connexion.php" class="nav-button nav-button-connexion">↪ Connexion</a>
    <?php if (est_connecte()): ?>
        <a href="page_profil.php" class="nav-button nav-button-profil">↪ Mon Profil</a>
        <a href="deconnexion.php" class="nav-button nav-button-logout">→ Déconnexion</a>
    <?php endif; ?>
</div>

</body>
</html>
