<?php
session_start();
require_once 'fonctions_utilitaires.php';
require_once 'verifier_connexion.php';

// Vérifier si l'utilisateur est admin
if (!est_admin()) {
    echo "Accès refusé: seuls les administrateurs peuvent accéder à cette page.";
    exit;
}

$utilisateurs = obtenir_tous_les_utilisateurs();

// Trier les utilisateurs par rôles
$utilisateurs_par_roles = [
    'admin' => [],
    'restaurateur' => [],
    'livreur' => [],
    'client' => []
];

foreach ($utilisateurs as $user) {
    $role = $user['role'] ?? 'client';
    if (isset($utilisateurs_par_roles[$role])) {
        $utilisateurs_par_roles[$role][] = $user;
    }
}

// Labels pour les rôles
$role_labels = [
    'admin' => 'Administrateurs',
    'restaurateur' => 'Restaurateurs',
    'livreur' => 'Livreurs',
    'client' => 'Clients'
];
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Page administrateur - Yumland</title>
    <link rel="stylesheet" href="style.css">
</head>
<body class="profile-page">
<header class="welcome-banner">
    <div class="left">
        <img class="logo-sushine" src="images/logo.png" alt="Logo Sushine">
    </div>

    <div class="center">
        <div class="button-container">
            <a class="menu-link" href="page_administrateur.php" style="font-weight: bold;">Gestion des utilisateurs</a>
            <a class="menu-link" href="travaux.php">Travaux</a>
        </div>
    </div>

    <div class="right">
        <button class="mon-compte-button"><a href="deconnexion.php">Déconnexion</a></button>
    </div>
</header>

<!-- Contenu principal de la page administrateur -->
<div class="container">
    <h2>Gestion des utilisateurs et des rôles</h2>
    <p>Bienvenue, <?php echo htmlspecialchars($_SESSION['utilisateur']['prenom'] ?? 'Admin'); ?>. Vous êtes connecté en tant qu'<strong>administrateur</strong>.</p>
    
    <div id="successMessage" class="success-message"></div>
    <div id="errorMessage" class="error-message"></div>
    
    <div class="users-container">
        <?php foreach ($role_labels as $role => $label): ?>
            <?php if (!empty($utilisateurs_par_roles[$role])): ?>
                <div class="role-group">
                    <div class="role-group-title">
                        <?php echo htmlspecialchars($label); ?> (<?php echo count($utilisateurs_par_roles[$role]); ?>)
                    </div>
                    
                    <?php foreach ($utilisateurs_par_roles[$role] as $user): ?>
                        <div class="user-item">
                            <div class="user-info">
                                <div class="user-details">
                                    <p><strong><?php echo htmlspecialchars($user['prenom'] . ' ' . $user['nom']); ?></strong></p>
                                    <p>Email: <code><?php echo htmlspecialchars($user['mail']); ?></code></p>
                                    <p>Numéro client: #<?php echo htmlspecialchars($user['num_client'] ?? 'N/A'); ?></p>
                                    <p>Adresse: <?php echo htmlspecialchars($user['adresse'] ?? 'Non renseignée'); ?></p>
                                    <p>Téléphone: <?php echo htmlspecialchars($user['num_téléphone'] ?? 'Non renseigné'); ?></p>
                                    <p>Date création: <?php echo htmlspecialchars($user['date_creation'] ?? 'N/A'); ?></p>
                                </div>
                                
                                <div class="role-section">
                                    <div>
                                        <span class="role-badge role-<?php echo htmlspecialchars(strtolower($user['role'])); ?>">
                                            <?php echo htmlspecialchars(strtoupper($user['role'])); ?>
                                        </span>
                                    </div>
                                    
                                    <?php if ($user['role'] !== 'admin'): ?>
                                        <div class="action-buttons">
                                            <div class="role-selector">
                                                <select class="role-select" data-email="<?php echo htmlspecialchars($user['mail']); ?>">
                                                    <option value="">-- Modifier le rôle --</option>
                                                    <option value="client">Client</option>
                                                    <option value="restaurateur">Restaurateur</option>
                                                    <option value="livreur">Livreur</option>
                                                    <option value="admin">Admin</option>
                                                </select>
                                                <button class="change-role-btn" data-email="<?php echo htmlspecialchars($user['mail']); ?>">
                                                    Changer
                                                </button>
                                                <span class="loading" data-email="<?php echo htmlspecialchars($user['mail']); ?>">Traitement...</span>
                                            </div>
                                            
                                            <button class="delete-btn" data-email="<?php echo htmlspecialchars($user['mail']); ?>" data-name="<?php echo htmlspecialchars($user['prenom'] . ' ' . $user['nom']); ?>">
                                                Supprimer
                                            </button>
                                        </div>
                                    <?php endif; ?>
                                </div>
                            </div>
                        </div>
                    <?php endforeach; ?>
                </div>
            <?php endif; ?>
        <?php endforeach; ?>
    </div>
</div>

<script>
// Gérer les changements de rôle
document.querySelectorAll('.change-role-btn').forEach(button => {
    button.addEventListener('click', function() {
        const email = this.getAttribute('data-email');
        const selectElement = document.querySelector(`.role-select[data-email="${email}"]`);
        const nouveauRole = selectElement.value;
        const loadingSpan = document.querySelector(`.loading[data-email="${email}"]`);
        
        if (!nouveauRole) {
            alert('Veuillez sélectionner un rôle');
            return;
        }
        
        // Afficher le chargement
        button.disabled = true;
        selectElement.disabled = true;
        loadingSpan.style.display = 'inline';
        
        // Envoyer la requête
        fetch('traitement_roles.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: 'action=modifier_role&email=' + encodeURIComponent(email) + '&nouveau_role=' + encodeURIComponent(nouveauRole)
        })
        .then(response => response.json())
        .then(data => {
            loadingSpan.style.display = 'none';
            button.disabled = false;
            selectElement.disabled = false;
            
            const successMsg = document.getElementById('successMessage');
            const errorMsg = document.getElementById('errorMessage');
            
            if (data.success) {
                successMsg.textContent = data.message;
                successMsg.style.display = 'block';
                errorMsg.style.display = 'none';
                
                // Réinitialiser le select
                selectElement.value = '';
                
                // Rafraîchir la page après 2 secondes
                setTimeout(() => {
                    window.location.reload();
                }, 2000);
            } else {
                errorMsg.textContent = data.message;
                errorMsg.style.display = 'block';
                successMsg.style.display = 'none';
                
                // Réinitialiser le select
                selectElement.value = '';
            }
        })
        .catch(error => {
            console.error('Erreur:', error);
            const errorMsg = document.getElementById('errorMessage');
            errorMsg.textContent = 'Une erreur est survenue lors de la modification du rôle';
            errorMsg.style.display = 'block';
            
            loadingSpan.style.display = 'none';
            button.disabled = false;
            selectElement.disabled = false;
        });
    });
});

// Gérer la suppression de profils
document.querySelectorAll('.delete-btn').forEach(button => {
    button.addEventListener('click', function() {
        const email = this.getAttribute('data-email');
        const name = this.getAttribute('data-name');
        
        if (!confirm(`Êtes-vous sûr de vouloir supprimer le profil de ${name} ?\nCette action est irréversible.`)) {
            return;
        }
        
        // Afficher le chargement
        button.disabled = true;
        button.textContent = 'Suppression...';
        
        // Envoyer la requête
        fetch('traitement_suppression.php', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: 'action=supprimer_profil&email=' + encodeURIComponent(email)
        })
        .then(response => response.json())
        .then(data => {
            const successMsg = document.getElementById('successMessage');
            const errorMsg = document.getElementById('errorMessage');
            
            if (data.success) {
                successMsg.textContent = data.message;
                successMsg.style.display = 'block';
                errorMsg.style.display = 'none';
                
                // Rafraîchir la page après 2 secondes
                setTimeout(() => {
                    window.location.reload();
                }, 2000);
            } else {
                errorMsg.textContent = data.message;
                errorMsg.style.display = 'block';
                successMsg.style.display = 'none';
                
                button.disabled = false;
                button.textContent = 'Supprimer';
            }
        })
        .catch(error => {
            console.error('Erreur:', error);
            const errorMsg = document.getElementById('errorMessage');
            errorMsg.textContent = 'Une erreur est survenue lors de la suppression du profil';
            errorMsg.style.display = 'block';
            
            button.disabled = false;
            button.textContent = 'Supprimer';
        });
    });
});
</script>
</body>
</html>