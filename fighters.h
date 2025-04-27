#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

Combattant ConveCombattant(FILE* fichier);



typedef struct{
    float valeur;
    char nomspe[30];
    char description1[60];
    char description2[60];
    int nombretouractif;
    int typecompétence;
    
}competencespeciales;


typedef struct{
    char nom[20];
    int pvmax;
    int pvcourants;
    char nomatq[50];
    int attaque;
    int defense;
    competencespeciales competspe;
    int vitesse;     
    int esquive;
    int degaspe1;
    int numcapacite1;//compteur de tour de capacité
    int degaspe2;
    int numcapacite2;
    int degaspe3;
    int numcapacite3;
    int vitessecourante;
    }Combattant;
