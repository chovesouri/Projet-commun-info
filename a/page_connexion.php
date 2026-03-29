<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Page de connexion</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<?php 
session_start();
require_once 'fonctions_utilitaires.php';
include 'bandeau_dynamique.php';
?>
<div class="connexion">
<div class="login-container">
    <div id="message" class="message"></div>
    
    <form id="form-connexion" class="login-form" method="POST">
        <h2>C<img src="images/maki-o.png" class="o-sushi">nnexion</h2>

        <label>Email</label>
        <input type="email" name="email" placeholder="Votre email" required>

        <label>Mot de passe</label>
        <input type="password" name="password" placeholder="Votre mot de passe" required>

        <button type="submit">Se connecter</button>
        
        <div class="loading" id="loading-connexion" style="display:none;">
            <p>Connexion en cours...</p>
        </div>

        <p class="register-link">
            Pas de compte ? <a href="page_inscription.php">Créer un compte</a>
        </p>
    </form>
</div>
</div>

<script>
    const formConnexion = document.getElementById('form-connexion');
    const messageDiv = document.getElementById('message');
    const loadingDiv = document.getElementById('loading-connexion');

    formConnexion.addEventListener('submit', async (e) => {
        e.preventDefault();
        const formData = new FormData(formConnexion);
        formData.append('action', 'connexion');

        try {
            loadingDiv.style.display = 'block';
            
            const response = await fetch('traitement_auth.php', {
                method: 'POST',
                body: formData
            });

            const data = await response.json();
            loadingDiv.style.display = 'none';

            messageDiv.className = 'message';
            messageDiv.innerHTML = data.message;

            if (data.success) {
                messageDiv.classList.add('message-success');
                setTimeout(() => {
                    window.location.href = data.redirect;
                }, 1500);
            } else {
                messageDiv.classList.add('message-error');
            }

        } catch (error) {
            loadingDiv.style.display = 'none';
            messageDiv.className = 'message message-error';
            messageDiv.innerHTML = '✗ Erreur de communication avec le serveur';
            console.error('Erreur:', error);
        }
    });
</script>

</body>
</html>

