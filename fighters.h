#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

Combattant ConveCombattant(FILE* fichier);



typedef struct{
    char* nomspe[30];
    char* description1[35];
    char* description2[35];
}competencespeciales;


typedef struct{
    char* nom[20];
    int pvmax;
    int pvcourants;
    char* nomatq[50];
    int attaque;
    int defense;
    competencespeciales competspe;
    int vitesse;     
    int esquive;
    int degaspe1;
    int degaspe2;
    int degaspe3;
    int vitessecourante;
    }Combattant;
