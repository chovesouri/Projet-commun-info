<?php
// Fichier de fonctions utilitaires pour la gestion des utilisateurs

const FICHIER_PROFILS = 'base_de_profils.json';

/**
 * Charger les profils depuis le fichier JSON
 */
function charger_profils() {
    if (!file_exists(FICHIER_PROFILS)) {
        return [];
    }
    $contenu = file_get_contents(FICHIER_PROFILS);
    return json_decode($contenu, true) ?: [];
}

/**
 * Sauvegarder les profils dans le fichier JSON
 */
function sauvegarder_profils($profils) {
    $json = json_encode($profils, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE);
    file_put_contents(FICHIER_PROFILS, $json);
}

/**
 * Chercher un utilisateur par email
 */
function chercher_utilisateur_par_email($email) {
    $profils = charger_profils();
    foreach ($profils as $profil) {
        if (isset($profil['mail']) && $profil['mail'] === $email) {
            return $profil;
        }
    }
    return null;
}

/**
 * Générer un numéro de client unique
 */
function generer_num_client() {
    $profils = charger_profils();
    // Chercher le numéro le plus élevé
    $num_max = 0;
    foreach ($profils as $profil) {
        if (isset($profil['num_client']) && is_numeric($profil['num_client'])) {
            $num_max = max($num_max, (int)$profil['num_client']);
        }
    }
    return $num_max + 1;
}

/**
 * Créer un nouveau profil client
 */
function creer_profil_client($email, $password, $nom = '', $prenom = '', $adresse = '', $telephone = '') {
    $profils = charger_profils();
    
    $nouveau_profil = [
        'num_client' => generer_num_client(),
        'mail' => $email,
        'password' => password_hash($password, PASSWORD_DEFAULT),
        'nom' => $nom,
        'prenom' => $prenom,
        'adresse' => $adresse,
        'num_téléphone' => $telephone,
        'role' => 'client',
        'date_creation' => date('Y-m-d H:i:s')
    ];
    
    $profils[] = $nouveau_profil;
    sauvegarder_profils($profils);
    
    return $nouveau_profil;
}

/**
 * Vérifier les identifiants
 */
function verifier_identifiants($email, $password) {
    $profil = chercher_utilisateur_par_email($email);
    
    if ($profil === null) {
        return ['success' => false, 'message' => 'Email non trouvé'];
    }
    
    // Support des deux formats de password (hashmé et non hashmé pour compatibilité)
    if (password_verify($password, $profil['password']) || $profil['password'] === $password) {
        unset($profil['password']); // Ne pas retourner le mot de passe
        return ['success' => true, 'profil' => $profil];
    }
    
    return ['success' => false, 'message' => 'Mot de passe incorrect'];
}

/**
 * Démarrer une session utilisateur
 */
function demarrer_session_utilisateur($profil) {
    $_SESSION['utilisateur'] = [
        'num_client' => $profil['num_client'] ?? null,
        'email' => $profil['mail'],
        'nom' => $profil['nom'],
        'prenom' => $profil['prenom'],
        'role' => $profil['role']
    ];
}

/**
 * Vérifier si l'utilisateur est connecté
 */
function est_connecte() {
    return isset($_SESSION['utilisateur']);
}

/**
 * Obtenir l'utilisateur connecté
 */
function obtenir_utilisateur_connecte() {
    return $_SESSION['utilisateur'] ?? null;
}

/**
 * Déconnecter l'utilisateur
 */
function deconnecter_utilisateur() {
    session_destroy();
    header('Location: page_connexion.php');
    exit;
}

/**
 * Vérifier si l'utilisateur connecté est admin
 */
function est_admin() {
    $utilisateur = obtenir_utilisateur_connecte();
    return $utilisateur && isset($utilisateur['role']) && $utilisateur['role'] === 'admin';
}

/**
 * Modifier le rôle d'un utilisateur
 * Rôles autorisés: client, restaurateur, admin, livreur
 */
function modifier_role_utilisateur($email, $nouveau_role) {
    $roles_valides = ['client', 'restaurateur', 'admin', 'livreur'];
    
    // Vérifier que le rôle est valide
    if (!in_array($nouveau_role, $roles_valides)) {
        return [
            'success' => false,
            'message' => 'Rôle invalide. Rôles autorisés: ' . implode(', ', $roles_valides)
        ];
    }
    
    $profils = charger_profils();
    $trouve = false;
    
    // Chercher et modifier le profil
    foreach ($profils as &$profil) {
        if (isset($profil['mail']) && $profil['mail'] === $email) {
            $ancien_role = $profil['role'] ?? 'client';
            $profil['role'] = $nouveau_role;
            $profil['date_derniere_modification_role'] = date('Y-m-d H:i:s');
            $trouve = true;
            
            sauvegarder_profils($profils);
            
            return [
                'success' => true,
                'message' => "Rôle modifié avec succès de '$ancien_role' à '$nouveau_role'",
                'profil' => $profil
            ];
        }
    }
    
    if (!$trouve) {
        return [
            'success' => false,
            'message' => 'Utilisateur non trouvé'
        ];
    }
}

/**
 * Obtenir tous les utilisateurs avec leurs rôles
 */
function obtenir_tous_les_utilisateurs() {
    $profils = charger_profils();
    
    // Retirer les mots de passe et ne garder que les infos utiles
    $utilisateurs = [];
    foreach ($profils as $profil) {
        $utilisateurs[] = [
            'num_client' => $profil['num_client'] ?? null,
            'mail' => $profil['mail'],
            'nom' => $profil['nom'] ?? '',
            'prenom' => $profil['prenom'] ?? '',
            'role' => $profil['role'] ?? 'client',
            'adresse' => $profil['adresse'] ?? '',
            'num_téléphone' => $profil['num_téléphone'] ?? '',
            'date_creation' => $profil['date_creation'] ?? ''
        ];
    }
    
    return $utilisateurs;
}

/**
 * Valider le format d'une adresse email
 */
function valider_email($email) {
    // Utiliser filter_var pour la validation basique
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        return ['valide' => false, 'message' => 'Format d\'email invalide'];
    }
    
    // Vérifier que l'email n'est pas trop long
    if (strlen($email) > 254) {
        return ['valide' => false, 'message' => 'L\'email est trop long'];
    }
    
    return ['valide' => true, 'message' => ''];
}

/**
 * Valider le mot de passe
 * Doit contenir au moins un chiffre et un caractère spécial
 */
function valider_mot_de_passe($password) {
    $messages = [];
    
    // Vérifier la longueur minimale
    if (strlen($password) < 8) {
        $messages[] = 'Au moins 8 caractères';
    }
    
    // Vérifier qu'il y a au moins un chiffre
    if (!preg_match('/[0-9]/', $password)) {
        $messages[] = 'Au moins un chiffre';
    }
    
    // Vérifier qu'il y a au moins un caractère spécial
    if (!preg_match('/[!@#$%^&*()_+\-=\[\]{};:\'",.<>?\/\\|`~]/', $password)) {
        $messages[] = 'Au moins un caractère spécial (!@#$%^&*...)';
    }
    
    if (empty($messages)) {
        return ['valide' => true, 'message' => ''];
    } else {
        return ['valide' => false, 'message' => 'Le mot de passe doit contenir: ' . implode(', ', $messages)];
    }
}

/**
 * Supprimer un utilisateur par email
 * Les admins ne peuvent pas être supprimés par un autre utilisateur
 */
function supprimer_utilisateur($email) {
    $profils = charger_profils();
    
    // Trouver l'utilisateur
    $utilisateur_index = -1;
    $utilisateur = null;
    
    foreach ($profils as $index => $profil) {
        if (isset($profil['mail']) && $profil['mail'] === $email) {
            $utilisateur_index = $index;
            $utilisateur = $profil;
            break;
        }
    }
    
    // Vérifier que l'utilisateur existe
    if ($utilisateur_index === -1) {
        return [
            'success' => false,
            'message' => 'Utilisateur non trouvé'
        ];
    }
    
    // Vérifier que ce n'est pas un admin
    if (isset($utilisateur['role']) && $utilisateur['role'] === 'admin') {
        return [
            'success' => false,
            'message' => 'Impossible de supprimer un profil administrateur'
        ];
    }
    
    // Supprimer l'utilisateur
    array_splice($profils, $utilisateur_index, 1);
    sauvegarder_profils($profils);
    
    return [
        'success' => true,
        'message' => 'Profil de ' . htmlspecialchars($utilisateur['prenom'] . ' ' . $utilisateur['nom']) . ' supprimé avec succès'
    ];
}
?>
