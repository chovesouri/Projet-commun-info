#include "fighers.h"



int main(){
    Combattant équipe1[3];
    Combattant équipe2[3];
    Combattant liste[12];
    int choix1;
    int compteur1=1;
    int compteur2=1;
    int compteur3=0;
    char nomEquipe1[51];
    char nomEquipe2[51];
    int nombredetour=1;
    FILE *f1 = fopen("combattants/mme enserre-main", "r");//ouverture de tous les fichiers des combattans
    if (f1 == NULL) {
        exit(1);}
    FILE *f2 = fopen("combattants/mme gros_t'es_qui ?", "r");
    if (f2 == NULL) {    
        exit(2); } 
    FILE *f3 = fopen("combattants/mme menu-bretin", "r");
    if (f3 == NULL) {    
        exit(3);}
    FILE *f4 = fopen("combattants/mme picasso", "r");
    if (f4 == NULL) {   
        exit(4);}
    FILE *f5 = fopen("combattants/mr j’accuse_iel", "r");
    if (f5 == NULL) {  
        exit(5); } 
    FILE *f6 = fopen("combattants/mr abdelmoulaga", "r");
    if (f6 == NULL) {  
        exit(6);  } 
    FILE *f7 = fopen("combattants/mr arancini", "r");
    if (f7 == NULL) {    
        exit(7);}
    FILE *f8 = fopen("combattants/mr bissap", "r");
    if (f8 == NULL) { 
        exit(8);  
    FILE *f9 = fopen("combattants/mr gay_prides", "r");
    if (f9 == NULL) { 
        exit(9);}
    FILE *f10 = fopen("combattants/mr grognon", "r");
    if (f10 == NULL) {
        exit(10);}
    FILE *f11 = fopen("combattants/mr par-dessus", "r");
    if (f11 == NULL) {
        exit(11); } 
    FILE *f12 = fopen("combattants/mr pelleteuse", "r");
    if (f12 == NULL) {
        exit(12); } 
    }

    liste[0] = ConveCombattant(f1);//affecter les combattants aux fichiers
    liste[1] = ConveCombattant(f2);
    liste[2] = ConveCombattant(f3);
    liste[3] = ConveCombattant(f4);
    liste[4] = ConveCombattant(f5);
    liste[5] = ConveCombattant(f6);
    liste[6] = ConveCombattant(f7);
    liste[7] = ConveCombattant(f8);
    liste[8] = ConveCombattant(f9);
    liste[9] = ConveCombattant(f10);
    liste[10] = ConveCombattant(f11);
    liste[11] = ConveCombattant(f12);
    

    printf("Joueur 1, choisissez un nom d'équipe :\n");
    scanf(" %50[^\n]", nomEquipe1);  // lit toute la ligne 

    printf("Joueur 2, choisissez un nom d'équipe :\n");
    scanf(" %50[^\n]", nomEquipe2); 
    
    for(int i=0; i<3;i++){
        do{
            afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
            printf("Joueur1 choisissez votre combattant numéro %d en saisissant sont numéro",compteur1);
            scanf("%d", &choix1);
           
        }while(choix1<1 || choix1>12-compteur3 || );
        équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
        miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
        systeme("clear");//nettoyer l'écran
        compteur1++;
        compteur3++;
        do{
            afficherCombattantsDisponibles(liste, 12-compteur3);
            printf("Joueur2 choisissez votre combattant numéro %d en saisissant sont numéro",compteur2);
            scanf("%d", &choix1);
           
        }while(choix1<1 || choix1>12-compteur || );
        équipe2[i] = liste[choix1-1];
        miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
        systeme("clear");
        compteur2++;
        compteur3++;

    }
    do{//déroulement et affichage du combat
    printf("Tour numéro %d\n",nombredetour);


        nombredetour++;
    }while((equipe1[0].pvcourants>0 && equipe[1].pvcourants>0 && equipe1[2].pvcourants) && (equipe2[1].pvcourants>0 && equip2[2].pvcourants>0 && equipe2[2].pvcourants>0) );//condition de fin de combat
    printf("\n=============================================\n");
    printf("               COMBAT TERMINÉ\n");
    printf("=============================================\n");





}
    













}
