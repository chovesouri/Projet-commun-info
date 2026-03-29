<?php
// page_inscription.php - Page d'inscription
session_start();
require_once 'fonctions_utilitaires.php';

// Rediriger si déjà connecté
if (est_connecte()) {
    header('Location: page_accueil.php');
    exit;
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Inscripti<img src="images/maki-o.png" class="o-sushi">n</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<?php include 'bandeau_dynamique.php'; ?>

<div class="connexion">
<div class="login-container">
    <div id="message" class="message"></div>
    
    <form id="form-inscription" class="login-form" method="POST">
        <h2>Inscripti<img src="images/maki-o.png" class="o-sushi">n</h2>

        <label>Email</label>
        <input type="email" name="email" placeholder="Votre email" required>

        <label>Prénom</label>
        <input type="text" name="prenom" placeholder="Votre prénom">

        <label>Nom</label>
        <input type="text" name="nom" placeholder="Votre nom">

        <label>Adresse</label>
        <input type="text" name="adresse" placeholder="Votre adresse">

        <label>Numéro de téléphone</label>
        <input type="tel" name="telephone" placeholder="Votre numéro de téléphone">

        <label>Mot de passe</label>
        <input type="password" name="password" id="password-input" placeholder="Votre mot de passe" required>
        <div class="password-requirements">
            <p>Le mot de passe doit contenir :</p>
            <ul>
                <li id="req-length"><span class="requirement-icon">○</span> Au moins 8 caractères</li>
                <li id="req-digit"><span class="requirement-icon">○</span> Au moins un chiffre (0-9)</li>
                <li id="req-special"><span class="requirement-icon">○</span> Au moins un caractère spécial (!@#$%^&*...)</li>
            </ul>
        </div>

        <button type="submit">S'inscrire</button>
        
        <div class="loading" id="loading-inscription" style="display:none;">
            <p>Création du compte en cours...</p>
        </div>

        <p class="register-link">
            Déjà un compte ? <a href="page_connexion.php">Se connecter</a>
        </p>
    </form>
</div>
</div>

<script>
    // Fonction pour valider le mot de passe
    function validerMotDePasse(password) {
        const requirements = {
            length: password.length >= 8,
            digit: /[0-9]/.test(password),
            special: /[!@#$%^&*()_+\-=\[\]{};:'"",.<>?\/\\|`~]/.test(password)
        };
        return requirements;
    }

    // Mettre à jour les indicateurs visuels du mot de passe
    function mettreAJourRequetes(requirements) {
        const icons = {
            length: document.getElementById('req-length').querySelector('.requirement-icon'),
            digit: document.getElementById('req-digit').querySelector('.requirement-icon'),
            special: document.getElementById('req-special').querySelector('.requirement-icon')
        };

        // Mettre à jour l'icône de longueur
        if (requirements.length) {
            icons.length.textContent = '✓';
            icons.length.style.color = '#4CAF50';
            document.getElementById('req-length').style.color = '#4CAF50';
        } else {
            icons.length.textContent = '○';
            icons.length.style.color = '#999';
            document.getElementById('req-length').style.color = '#999';
        }

        // Mettre à jour l'icône de chiffre
        if (requirements.digit) {
            icons.digit.textContent = '✓';
            icons.digit.style.color = '#4CAF50';
            document.getElementById('req-digit').style.color = '#4CAF50';
        } else {
            icons.digit.textContent = '○';
            icons.digit.style.color = '#999';
            document.getElementById('req-digit').style.color = '#999';
        }

        // Mettre à jour l'icône de caractère spécial
        if (requirements.special) {
            icons.special.textContent = '✓';
            icons.special.style.color = '#4CAF50';
            document.getElementById('req-special').style.color = '#4CAF50';
        } else {
            icons.special.textContent = '○';
            icons.special.style.color = '#999';
            document.getElementById('req-special').style.color = '#999';
        }
    }

    // Écouter les changements dans le champ de mot de passe
    const passwordInput = document.getElementById('password-input');
    passwordInput.addEventListener('input', (e) => {
        const requirements = validerMotDePasse(e.target.value);
        mettreAJourRequetes(requirements);
    });

    // Valider le formulaire avant l'envoi
    const formInscription = document.getElementById('form-inscription');
    const messageDiv = document.getElementById('message');
    const loadingDiv = document.getElementById('loading-inscription');

    formInscription.addEventListener('submit', async (e) => {
        e.preventDefault();
        
        const email = document.querySelector('input[name="email"]').value.trim();
        const password = document.querySelector('input[name="password"]').value;
        
        // Valider l'email
        if (!email.includes('@') || !email.includes('.')) {
            messageDiv.className = 'message message-error';
            messageDiv.innerHTML = '✗ Veuillez entrer une adresse email valide';
            return;
        }
        
        // Valider le mot de passe côté client
        const requirements = validerMotDePasse(password);
        if (!requirements.length || !requirements.digit || !requirements.special) {
            const missing = [];
            if (!requirements.length) missing.push('8 caractères minimum');
            if (!requirements.digit) missing.push('un chiffre');
            if (!requirements.special) missing.push('un caractère spécial');
            messageDiv.className = 'message message-error';
            messageDiv.innerHTML = '✗ Le mot de passe doit contenir: ' + missing.join(', ');
            return;
        }

        const formData = new FormData(formInscription);
        formData.append('action', 'inscription');

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
                messageDiv.innerHTML = `✓ Bienvenue ! Votre numéro client est: <strong>${data.num_client}</strong><br>Redirection...`;
                
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
