#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include <time.h>
#include <unistd.h>





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
    float defense;
    competencespeciales competspe;
    int vitesse;     
    float esquive;
    int typespe1;
    int nombredetouractif1;//compteur de tour de capacité
    int typespe2;
    int nombredetouractif2;
    int typespe3;
    int nombredetouractif3;
    int vitessecourante;
    }Combattant;
  
  
Combattant ConveCombattant(FILE* fichier,FILE* fichier2);  
void afficherCombattantsDisponibles(Combattant liste[], int taille);
void affichecombat(Combattant* equipe1,char* nomEquipe1, Combattant* equipe2,char* nomEquipe2);
void affichejoueur(Combattant* equipe,char* nomequipe);
void affichevitesse(int vitesse);
void alignement(int longueur);
int longueur_int(int n);
void Utilisationcompétence(Combattant* attaquant,char* noméquipeat,Combattant* attaquanttémoin, Combattant* défenseur,char* noméquipedéf, Combattant* défenseurtémoin, int choixcombattant,int vérificationbot, int* passe);
void Miseàjourcompétence(Combattant* équipe, Combattant* équipetémoin);
Combattant* miseàJourCombattants(Combattant liste[],int choixcombattant);
void vérifscanf(int valider);
