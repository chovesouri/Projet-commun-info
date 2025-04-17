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
        printf("     Attaque     : %s: (%d)\n", liste[i].nomatq, liste[i].attaque);
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

int longueur_int(int n) {// Compter les chiffres d'un entier
    int longueur = 0;
    while (n > 0) {
        n /= 10;
        longueur++;
    }

    return longueur;
}
void allignement(int longueur){//fonction permettant d'lligner les colonnes
    for(int i = 0; i <35-longueur; i++){
        printf(" ");
    }

}
   
void affichecombats(Combattant* equipe) {// Affiche les combats entre les deux équipes
    printf("|");
    int l = 0;// variable servant à l'allignementde des |
    
    for(int i = 0; i < 3; i++) {//affichage des noms des combattants
        printf("   %s: ", equipe[i].nom);
        l=strlen(equipe[i].nom);
        aliignement(l);
        printf("|");
    }
    printf("\n");
    for(int a=0; a<3; a++){
        printf("   pv:%d",equipe[a].pvcourants);
        l=longueur_int(equipe[a].pvcourants);
        allignement(l);
        printf("|");
    }    
    for(int z=0; z<3; z++){
        printf("   %s:%d ", equipe[z].nomatq, equipe[z].attaque);
        l=strlen(equipe[z].nomatq)+longueur_int(equipe[z].attaque);
        allignement(l);
        printf("|");
    }
    for(int b=0; b<3; b++){
        printf("   %s ", equipe[b].defense);
        l=strlen(equipe[b].defense);
        allignement(l);
        printf("|");
    }









}   