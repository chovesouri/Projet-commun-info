# Système de Connexion et Inscription - Yumland

## 📋 Vue d'ensemble

Ce système gère l'authentification des clients sur le site Yumland. Les clients peuvent se connecter s'ils ont un compte ou en créer un nouveau. Tous les profils sont stockés dans `base_de_profils.json`.

## 🔧 Architecture

### Fichiers créés/modifiés:

**Fichiers de logique PHP:**
- **`fonctions_utilitaires.php`** - Fonctions réutilisables pour la gestion des profils
- **`traitement_auth.php`** - Traite les requêtes POST de connexion/inscription
- **`verifier_connexion.php`** - À inclure pour protéger les pages
- **`deconnexion.php`** - Déconnecte l'utilisateur

**Pages PHP:**
- **`page_connexion.php`** - Page principale avec onglets Connexion/Inscription (formulaire AJAX)
- **`page_accueil.php`** - Accueil avec détection de connexion
- **`page_profil.php`** - Affiche le profil de l'utilisateur connecté
- **`page_inscription.php`** - Redirige vers page_connexion.php

## 🚀 Fonctionnalités

### Connexion
1. L'utilisateur entre son email et mot de passe
2. Le système vérifie si le profil existe dans `base_de_profils.json`
3. Si trouvé, le mot de passe est vérifié (supporte les formats hashés et non-hashés)
4. Une session PHP est créée
5. L'utilisateur est redirigé vers `page_accueil.php`

### Inscription
1. L'utilisateur remplit le formulaire (email, mot de passe, infos personnelles)
2. Le système vérifie que l'email n'existe pas déjà
3. Un numéro de client unique est généré automatiquement
4. Le nouveau profil est créé et sauvegardé dans `base_de_profils.json`
5. Une session PHP est créée
6. L'utilisateur reçoit son numéro de client et est redirigé vers `page_accueil.php`

## 📊 Structure du JSON

Chaque profil dans `base_de_profils.json` contient:

```json
{
  "num_client": 1,
  "mail": "email@example.com",
  "password": "hashed_password_or_plain",
  "nom": "Dupont",
  "prenom": "Jean",
  "adresse": "123 Rue de Paris",
  "num_téléphone": "0612345678",
  "role": "client",
  "date_creation": "2026-03-28 10:30:00"
}
```

## 🔐 Sécurité

- Les mots de passe sont hashés with `password_hash()` (algo: PASSWORD_DEFAULT)
- Support legacy des mots de passe non-hashés pour la migration
- Utilisation de sessions PHP sécurisées
- Validation des entrées avec `filter_var()` pour les emails
- Échappement HTML avec `htmlspecialchars()` lors de l'affichage

## 📱 Utilisation

### Pour protéger une page:

```php
<?php
session_start();
require_once 'fonctions_utilitaires.php';

if (!est_connecte()) {
    header('Location: page_connexion.php');
    exit;
}

$utilisateur = obtenir_utilisateur_connecte();
echo "Bienvenue " . $utilisateur['prenom'];
?>
```

### Pour afficher des infos de l'utilisateur:

```php
<?php
if (est_connecte()) {
    $utilisateur = obtenir_utilisateur_connecte();
    echo "Client #" . $utilisateur['num_client'];
}
?>
```

## 🔄 Flux utilisateur

```
Non connecté
    ↓
page_connexion.php ← → Onglet Connexion ou Inscription
    ↓
traitement_auth.php (AJAX)
    ↓ Succès
page_accueil.php (connecté)
    ↓
page_profil.php
    ↓
deconnexion.php → page_connexion.php
```

## 📝 Notes

- Les numéros de client sont générés automatiquement (séquentiel)
- Les sessions expirent selon la configuration PHP (par défaut: inactivité)
- Le fichier JSON est sauvegardé à chaque nouvelle inscription
- La page d'accueil affiche un message personnalisé si vous êtes connecté

## 🐛 Dépannage

**"Email non trouvé"** → Vérifiez que vous êtes bien inscrit
**"Mot de passe incorrect"** → Vérifiez le mot de passe saisi
**"Cet email est déjà utilisé"** → Utilisez un autre email ou connectez-vous
**Redirection boucle** → Vérifiez les en-têtes HTTP du navigateur

