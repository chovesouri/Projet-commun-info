typedef struct {
    char nom[50];
    int pvmax;
    int pvcourants;
    char nomAtq[50];
    int attaque;
    int defense;
    char competSpe[50];
    int vitesse;     
    int esquive;
    int degatsSpe[3];  // Tableaux pour 3 attaques spéciales
} Combattant;


Combattant ConveCombattant(FILE *fichier) {
    Combattant c;
    
    // Lecture des informations de base du combattant
    fscanf(fichier, "Nom: %49[^\n]\n", c.nom);
    fscanf(fichier, "PV Max: %d\n", &c.pvmax);
    c.pvcourants = c.pvmax;  // Initialisation avec les PV max
    fscanf(fichier, "Attaque: %d\n", &c.attaque);
    fscanf(fichier, "Defense: %d\n", &c.defense);
    fscanf(fichier, "Vitesse: %d\n", &c.vitesse);
    fscanf(fichier, "Esquive: %d\n", &c.esquive);

    // Lecture des compétences spéciales
    for (int i = 0; i < 3; i++) {
        fscanf(fichier, "Competence Spéciale %d: %49[^\n]\n", &i, c.competSpe[i]);
        fscanf(fichier, "Degats Competence %d: %d\n", &i, &c.degatsSpe[i]);
    }

    return c;
}
void miseaJourCombattants(Combattant liste[], int index) {
    for (int i = index; i < NB_TOTAL_COMBATTANTS - 1; i++) {
        liste[i] = liste[i + 1];  // Décaler les combattants
    }
    // Réinitialiser le dernier combattant à vide
    liste[NB_TOTAL_COMBATTANTS - 1].pvcourants = -1;  // Marquer comme "inactif"
}
void attaquer(Combattant* attaquant, Combattant* cible) {
    int degats = attaquant->attaque - (int)(attaquant->attaque * (cible->defense / 100.0));
    if (degats < 0) degats = 0;

    // Chance d'esquive
    float chance = (float)(rand() % 100);
    if (chance < cible->esquive) {
        printf("%s esquive l'attaque !\n", cible->nom);
    } else {
        cible->pvcourants -= degats;
        if (cible->pvcourants < 0) cible->pvcourants = 0;
        printf("%s inflige %d dégâts à %s. PV restants : %d\n", attaquant->nom, degats, cible->nom, cible->pvcourants);
    }
}
