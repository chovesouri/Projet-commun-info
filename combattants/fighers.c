#include "Untitled-1.h"

Combattant ConveCombattant(FILE* fichier){
    Combattant c;
    // Lecture directe avec fscanf
    fscanf(fichier, "%19[^\n]\n", c.nom);         // nom
    fscanf(fichier, "%d\n", &c.pvmax);            // pvmax
    c.pvcourants = c.pvmax;                       // init à pvmax
    fscanf(fichier, "%29[^\n]\n", c.nomatq);      // nomatq
    fscanf(fichier, "%d\n", &c.attaque);          // attaque
    fscanf(fichier, "%f\n", &c.defense);          // defense
    fscanf(fichier, "%29[^\n]\n", c.competspe);   // competspe
    fscanf(fichier, "%d\n", &c.vitesse);          // vitesse
    fscanf(fichier, "%f\n", &c.esquive);          // esquive

    // Valeurs par défaut pour les dégâts spéciaux
    c.degaspe1 = 0;
    c.degaspe2 = 0;
    c.degaspe3 = 0;

    fclose(fichier);
    return c;
}


void afficherCombattantsDisponibles(Combattant liste[], int taille) {// Affiche les combattants disponibles avec toutes leurs caractéristiques
    printf("==== COMBATTANTS DISPONIBLES ====\n");
    printf("\n\n");
    for (int i = 0; i < taille; i++) {
        printf("(%d) Nom : %s\n", i+1, liste[i].nom);
        printf("     PV max      : %d\n", liste[i].pvmax);
        printf("     PV actuels  : %d\n", liste[i].pvcourants);
        printf("     Attaque     : %s (%d)\n", liste[i].nomatq, liste[i].attaque);
        printf("     Défense     : %d\n", liste[i].defense);
        printf("     Spécial     : %s\n", liste[i].competspe);
        printf("     Vitesse     : %d\n", liste[i].vitesse);
        printf("     Esquive     : %d\n", liste[i].esquive);
        printf("----------------------------------------\n");
        printf("\n");
    }
}
    
Combattant* miseaJourCombattants(liste[],int choixcombattant){
    for(choixcombattant; choixcombattant< 11; i++){
        liste[choixcombattant] = liste[choixcombattant+1];  
    }
return liste;
} 
   
