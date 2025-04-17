#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fighters.h"

#define NB_TOTAL_COMBATTANTS 12
#define NB_PAR_EQUIPE 3

void nettoyerBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void attaquer(Combattant* attaquant, Combattant* cible) {
    int degats = attaquant->attaque - (int)(attaquant->attaque * cible->defense);
    if (degats < 0) degats = 0;

    // chance d'esquive
    float chance = (float)(rand() % 100);
    if (chance < cible->esquive) {
        printf("%s esquive l'attaque !\n", cible->nom);
    } else {
        cible->pvcourants -= degats;
        if (cible->pvcourants < 0) cible->pvcourants = 0;
        printf("%s inflige %d dégâts à %s. PV restants : %d\n", attaquant->nom, degats, cible->nom, cible->pvcourants);
    }
}

int equipeEstMorte(Combattant equipe[]) {
    for (int i = 0; i < NB_PAR_EQUIPE; i++) {
        if (equipe[i].pvcourants > 0) return 0;
    }
    return 1;
}

int choisirCombattant(Combattant equipe[]) {
    int choix;
    do {
        printf("Choisissez un de vos combattants vivants :\n");
        for (int i = 0; i < NB_PAR_EQUIPE; i++) {
            if (equipe[i].pvcourants > 0) {
                printf("(%d) %s (%d PV)\n", i+1, equipe[i].nom, equipe[i].pvcourants);
            }
        }
        printf("Votre choix : ");
        scanf("%d", &choix);
        nettoyerBuffer();
    } while (choix < 1 || choix > NB_PAR_EQUIPE || equipe[choix-1].pvcourants <= 0);
    return choix - 1;
}

int choisirCible(Combattant adversaires[]) {
    int choix;
    do {
        printf("Choisissez une cible parmi les adversaires encore en vie :\n");
        for (int i = 0; i < NB_PAR_EQUIPE; i++) {
            if (adversaires[i].pvcourants > 0) {
                printf("(%d) %s (%d PV)\n", i+1, adversaires[i].nom, adversaires[i].pvcourants);
            }
        }
        printf("Votre choix : ");
        scanf("%d", &choix);
        nettoyerBuffer();
    } while (choix < 1 || choix > NB_PAR_EQUIPE || adversaires[choix-1].pvcourants <= 0);
    return choix - 1;
}

int main() {
    srand(time(NULL));

    Combattant equipe1[NB_PAR_EQUIPE];
    Combattant equipe2[NB_PAR_EQUIPE];
    Combattant liste[NB_TOTAL_COMBATTANTS];
    char* fichiers[] = {
        "combattants/mme enserre-main", "combattants/mme gros_t'es_qui ?", "combattants/mme menu-bretin", "combattants/mme picasso",
        "combattants/mr j’accuse_iel", "combattants/mr abdelmoulaga", "combattants/mr arancini", "combattants/mr bissap",
        "combattants/mr gay_prides", "combattants/mr grognon", "combattants/mr par-dessus", "combattants/mr pelleteuse"
    };

    for (int i = 0; i < NB_TOTAL_COMBATTANTS; i++) {
        FILE* f = fopen(fichiers[i], "r");
        if (f == NULL) {
            printf("Erreur ouverture fichier %s\n", fichiers[i]);
            exit(1);
        }
        liste[i] = ConveCombattant(f);
    }

    char nomEquipe1[51], nomEquipe2[51];
    printf("Joueur 1, nom d'équipe : ");
    scanf(" %50[^\n]", nomEquipe1); nettoyerBuffer();
    printf("Joueur 2, nom d'équipe : ");
    scanf(" %50[^\n]", nomEquipe2); nettoyerBuffer();

    int nbDispo = NB_TOTAL_COMBATTANTS;
    for (int i = 0; i < NB_PAR_EQUIPE; i++) {
        int choix;
        afficherCombattantsDisponibles(liste, nbDispo);
        printf("Joueur 1, choisissez un combattant : ");
        scanf("%d", &choix); nettoyerBuffer();
        equipe1[i] = liste[choix - 1];
        miseaJourCombattants(liste, choix - 1);
        nbDispo--;

        afficherCombattantsDisponibles(liste, nbDispo);
        printf("Joueur 2, choisissez un combattant : ");
        scanf("%d", &choix); nettoyerBuffer();
        equipe2[i] = liste[choix - 1];
        miseaJourCombattants(liste, choix - 1);
        nbDispo--;
    }

    int tour = 1;
    while (!equipeEstMorte(equipe1) && !equipeEstMorte(equipe2)) {
        printf("\n--- Tour %d ---\n", tour);

        printf("\n== Joueur 1 ==\n");
        int a1 = choisirCombattant(equipe1);
        int c1 = choisirCible(equipe2);
        attaquer(&equipe1[a1], &equipe2[c1]);

        if (equipeEstMorte(equipe2)) break;

        printf("\n== Joueur 2 ==\n");
        int a2 = choisirCombattant(equipe2);
        int c2 = choisirCible(equipe1);
        attaquer(&equipe2[a2], &equipe1[c2]);

        tour++;
    }

    if (equipeEstMorte(equipe2)) {
        printf("\nVictoire de l'équipe %s !\n", nomEquipe1);
    } else {
        printf("\nVictoire de l'équipe %s !\n", nomEquipe2);
    }

    return 0;
}
