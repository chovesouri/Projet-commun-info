<?php
session_start();
require_once 'fonctions_utilitaires.php';

// Vérifier la connexion
if (!est_connecte()) {
    header('Location: page_connexion.php');
    exit;
}

$utilisateur = obtenir_utilisateur_connecte();
$email = $utilisateur['email'];

// Récupérer le profil complet pour afficher les infos
$profils = charger_profils();
$profil_complet = null;
foreach ($profils as $p) {
    if (isset($p['mail']) && $p['mail'] === $email) {
        $profil_complet = $p;
        break;
    }
}

// Extraire les initiales pour l'avatar
$initiales = strtoupper(
    substr($profil_complet['prenom'] ?? '', 0, 1) . 
    substr($profil_complet['nom'] ?? '', 0, 1)
);
if (strlen($initiales) < 2) {
    $initiales = strtoupper(substr($email, 0, 2));
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Mon Profil - Yumland</title>
    <link rel="stylesheet" href="style.css">
</head>
<body class="profile-page">
    <?php include 'bandeau_dynamique.php'; ?>
    <!-- Conteneur principal de la page -->
    <div class="container">
        <!-- En-tête : avatar + nom + statut -->
        <div class="profile-header">
            <div class="avatar"><?php echo htmlspecialchars($initiales); ?></div>
            <div>
                <h2><?php echo htmlspecialchars($profil_complet['prenom'] ?? '') . ' ' . htmlspecialchars($profil_complet['nom'] ?? ''); ?></h2>
                <div style="color:#666;font-size:14px">Numéro client: #<?php echo htmlspecialchars($profil_complet['num_client'] ?? 'N/A'); ?></div>
            </div>
        </div>

        <section class="personal-info">
            <h3>Informations personnelles</h3>
            <div id="profil-message" class="profil-message"></div>
            
            <div class="info-grid">
                <!-- Prénom -->
                <div class="field" data-field="prenom">
                    <label>Prénom</label>
                    <div class="value">
                        <span id="display-prenom" class="display-value"><?php echo htmlspecialchars($profil_complet['prenom'] ?? ''); ?></span>
                        <input type="text" id="edit-prenom" class="edit-value" style="display:none;" value="<?php echo htmlspecialchars($profil_complet['prenom'] ?? ''); ?>">
                    </div>
                </div>

                <!-- Nom -->
                <div class="field" data-field="nom">
                    <label>Nom</label>
                    <div class="value">
                        <span id="display-nom" class="display-value"><?php echo htmlspecialchars($profil_complet['nom'] ?? ''); ?></span>
                        <input type="text" id="edit-nom" class="edit-value" style="display:none;" value="<?php echo htmlspecialchars($profil_complet['nom'] ?? ''); ?>">
                    </div>
                </div>

                <!-- Email -->
                <div class="field" data-field="email">
                    <label>Email</label>
                    <div class="value">
                        <span id="display-email" class="display-value"><?php echo htmlspecialchars($profil_complet['mail'] ?? ''); ?></span>
                    </div>
                </div>

                <!-- Téléphone -->
                <div class="field" data-field="telephone">
                    <label>Téléphone</label>
                    <div class="value">
                        <span id="display-tel" class="display-value"><?php echo htmlspecialchars($profil_complet['num_téléphone'] ?? ''); ?></span>
                        <input type="text" id="edit-tel" class="edit-value" style="display:none;" value="<?php echo htmlspecialchars($profil_complet['num_téléphone'] ?? ''); ?>">
                    </div>
                </div>

                <!-- Adresse (occupe les deux colonnes) -->
                <div class="field" style="grid-column:1/3" data-field="adresse">
                    <label>Adresse</label>
                    <div class="value">
                        <span id="display-adresse" class="display-value"><?php echo htmlspecialchars($profil_complet['adresse'] ?? ''); ?></span>
                        <input type="text" id="edit-adresse" class="edit-value" style="display:none;" value="<?php echo htmlspecialchars($profil_complet['adresse'] ?? ''); ?>">
                    </div>
                </div>
            </div>

            <div class="profil-actions">
                <button id="btn-modifier" class="btn-modifier" onclick="activerEdition()">✎ Modifier mes infos</button>
                <button id="btn-sauvegarder" class="btn-sauvegarder" style="display:none;" onclick="sauvegarderProfil()">✓ Sauvegarder</button>
                <button id="btn-annuler" class="btn-annuler" style="display:none;" onclick="annulerEdition()">✕ Annuler</button>
            </div>
        </section>
    </div>

    <script>
    let isEditing = false;

    function activerEdition() {
        isEditing = true;
        
        // Masquer les spans et afficher les inputs
        document.getElementById('display-prenom').style.display = 'none';
        document.getElementById('edit-prenom').style.display = 'block';
        
        document.getElementById('display-nom').style.display = 'none';
        document.getElementById('edit-nom').style.display = 'block';
        
        document.getElementById('display-tel').style.display = 'none';
        document.getElementById('edit-tel').style.display = 'block';
        
        document.getElementById('display-adresse').style.display = 'none';
        document.getElementById('edit-adresse').style.display = 'block';
        
        // Changer les boutons
        document.getElementById('btn-modifier').style.display = 'none';
        document.getElementById('btn-sauvegarder').style.display = 'block';
        document.getElementById('btn-annuler').style.display = 'block';
    }

    function annulerEdition() {
        isEditing = false;
        
        // Afficher les spans et masquer les inputs
        document.getElementById('display-prenom').style.display = 'inline';
        document.getElementById('edit-prenom').style.display = 'none';
        
        document.getElementById('display-nom').style.display = 'inline';
        document.getElementById('edit-nom').style.display = 'none';
        
        document.getElementById('display-tel').style.display = 'inline';
        document.getElementById('edit-tel').style.display = 'none';
        
        document.getElementById('display-adresse').style.display = 'inline';
        document.getElementById('edit-adresse').style.display = 'none';
        
        // Changer les boutons
        document.getElementById('btn-modifier').style.display = 'block';
        document.getElementById('btn-sauvegarder').style.display = 'none';
        document.getElementById('btn-annuler').style.display = 'none';
        
        // Effacer le message
        document.getElementById('profil-message').innerHTML = '';
    }

    async function sauvegarderProfil() {
        const prenom = document.getElementById('edit-prenom').value;
        const nom = document.getElementById('edit-nom').value;
        const telephone = document.getElementById('edit-tel').value;
        const adresse = document.getElementById('edit-adresse').value;
        const messageDiv = document.getElementById('profil-message');

        try {
            const formData = new FormData();
            formData.append('prenom', prenom);
            formData.append('nom', nom);
            formData.append('telephone', telephone);
            formData.append('adresse', adresse);

            const response = await fetch('mise_a_jour_profil.php', {
                method: 'POST',
                body: formData
            });

            const data = await response.json();
            messageDiv.innerHTML = data.message;
            messageDiv.className = 'profil-message ' + (data.success ? 'success' : 'error');

            if (data.success) {
                // Mettre à jour l'affichage
                document.getElementById('display-prenom').textContent = prenom;
                document.getElementById('display-nom').textContent = nom;
                document.getElementById('display-tel').textContent = telephone;
                document.getElementById('display-adresse').textContent = adresse;

                // Quitter le mode édition
                setTimeout(() => annulerEdition(), 1500);
            }
        } catch (error) {
            messageDiv.innerHTML = '✗ Erreur lors de la sauvegarde';
            messageDiv.className = 'profil-message error';
            console.error('Erreur:', error);
        }
    }
    </script>

</body>
</html>