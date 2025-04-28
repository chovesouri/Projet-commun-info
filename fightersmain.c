#include "fighters.h"


Combattant ConveCombattant(FILE* fichier);
afficherCombattantsDisponibles(Combattant liste[], int taille);

int main(){
    srand(time(NULL));
    Combattant équipe1[3];
    Combattant équipe2[3];
    Combattant liste[12];
    int choix1=0;//choix du combattant allié qui attaque
    int choix2=0;//choix du combattant à attaquer
    int choixcap=0;//choix du type d'attaque
    int compteur1=1;
    int compteur2=1;
    int compteur3=0;
    char nomEquipe1[51];
    char nomEquipe2[51];
    int nombredetour=1;
    int valide=0;
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

    FILE *comp1=fopen("Competences speciales/Paquets d'Arthur", "r");
    if (comp1 == NULL) {
        exit(13);}
    FILE *comp2=fopen("Competences speciales/appel du cartel", "r");
    if (comp2 == NULL) {
        exit(14);}
    FILE *comp3=fopen("Competences speciales/devoir-de-meca", "r");
    if (comp3 == NULL) {
        exit(15);}    
    FILE *comp4=fopen("Competences speciales/ecrasement par doc martens", "r");
    if (comp4 == NULL) {
        exit(16);}
    FILE *comp5=fopen("Competences speciales/injection sql", "r");
    if (comp5 == NULL) {
        exit(17);}
    FILE *comp6=fopen("Competences speciales/justification parfaite", "r");   
    if (comp6 == NULL) {
        exit(18);}
    FILE *comp7=fopen("Competences speciales/long délai", "r");
    if (comp7 == NULL) {
        exit(19);}
    FILE *comp8=fopen("Competences speciales/remise des bulletins", "r");
    if (comp8 == NULL) {
        exit(20);}
    FILE *comp9=fopen("Competences speciales/renvoi", "r");
    if (comp9 == NULL) {
        exit(21);}
    FILE *comp10=fopen("Competences speciales/spam Teams", "r");
    if (comp10 == NULL) {
        exit(22);}
    FILE *comp11=fopen("Competences speciales/trust the process", "r");
    if (comp11 == NULL) {
        exit(23);}
    FILE *comp12=fopen("Competences speciales/vous etes des clowns", "r");
    if (comp12 == NULL) {
        exit(24);}

    liste[0] = ConveCombattant(f1);//affecter les combattants aux fichiers
    liste[0] = Convecompspé(comp4);
    liste[1] = ConveCombattant(f2);
    liste[1] = Convecompspé(comp10);
    liste[2] = ConveCombattant(f3);
    liste[2] = Convecompspé(comp7);
    liste[3] = ConveCombattant(f4);
    liste[3] = Convecompspé(comp8);
    liste[4] = ConveCombattant(f5);
    liste[4] = Convecompspé(comp9);
    liste[5] = ConveCombattant(f6);
    liste[5] = Convecompspé(comp12);
    liste[6] = ConveCombattant(f7);
    liste[6] = Convecompspé(comp1);
    liste[7] = ConveCombattant(f8);
    liste[7] = Convecompspé(comp11);
    liste[8] = ConveCombattant(f9);
    liste[8] = Convecompspé(comp3);
    liste[9] = ConveCombattant(f10);
    liste[9] = Convecompspé(comp5);
    liste[10] = ConveCombattant(f11);
    liste[10] = Convecompspé(comp2);
    liste[11] = ConveCombattant(f12);
    liste[11] = Convecompspé(comp6);

    printf("Joueur 1, choisissez un nom d'équipe :\n");
    scanf(" %50[^\n]", nomEquipe1);  // lit toute la ligne 

    printf("Joueur 2, choisissez un nom d'équipe :\n");
    scanf(" %50[^\n]", nomEquipe2); 
    
    for(int i=0; i<3;i++){
        do{
            afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
            printf("Joueur1 choisissez votre combattant numéro %d en saisissant sont numéro",compteur1);
            scanf("%d", &choix1);
           
        }while(choix1<1 || choix1>12-compteur3 );
        équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
        miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
        system("clear");//nettoyer l'écran
        compteur1++;
        compteur3++;
        do{
            afficherCombattantsDisponibles(liste, 12-compteur3);
            printf("Joueur2 choisissez votre combattant numéro %d en saisissant sont numéro",compteur2);
            scanf("%d", &choix1);
           
        }while(choix1<1 || choix1>12-compteur3 );
        équipe2[i] = liste[choix1-1];
        miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
        system("clear");
        compteur2++;
        compteur3++;

    }
    for(int t=0; t<3; t++){//génération de la vitesse courante
        équipe1[t].vitessecourante=rand()%50+1;
        équipe2[t].vitessecourante=rand()%50+1;
    }
    choix1=0;
    system("clear");
    
    
    do{//déroulement et affichage du combat
        printf("Tour %d\n", nombredetour);
        affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
        do{//choix du combattant qui va attaquer
            do{
                printf("Joeur 1, choisissez le combattant qui va attaquer\n");
                scanf("%d", &choix1);
            }while(choix1<1 || choix1>3);
            choix1=choix1-1;
            if(équipe1[choix1].pvcourants==0){
                printf("Ce combattant est KO, choisissez un autre combattant\n");
                valide=0;
            }else{
                valide=1;
            }
        }while(valide==0);
        valide=0;
        
        if(équipe1[choix1].vitessecourante!=100){
            do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                scanf("%d", &choix2);
            }while(choix2<1 || choix2>3);
            if(équipe2[choix2].pvcourants==0){
                printf("Ce combattant est KO, choisissez un autre combattant\n");
                valide=0;
            }else{
            valide=1;
                }
        }else{
            do{//choix du type d'attaque
                printf("Votre capacité spéciale est disponible, tapez 1 pour attaquer normalement ou 2 pour utiliser votre capacité spéciale\n");
                scanf("%d", &choixcap);
            }while(choixcap<1 || choixcap>2);
            if(choixcap==1){
                do{
                    do{//choix du combattant à attaquer si la capacité spéciale est disponible
                        printf("Choisissez un adversaire à attaquer\n");
                        scanf("%d", &choix2);
                    }while(choix2<1 || choix2>3);
                    if(équipe2[choix2].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                        valide=0;
                    }else{
                        valide=1;
                    }
                }while(valide==0);
                }
                choix2=choix2-1;
                équipe2[choix2].pvcourants-=équipe1[choix1].degats;
            else{
                utilisationcompétence(équipe1, équipe2, choix1, choix2);//utilisation de la capacité spéciale
            }    

        
        }






        











        nombredetour++;
    }while((équipe1[0].pvcourants>0 && équipe1[1].pvcourants>0 && équipe1[2].pvcourants) && (équipe2[1].pvcourants>0 && équipe2[2].pvcourants>0 && équipe2[2].pvcourants>0) );//condition de fin de combat















}
