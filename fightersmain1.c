#include "fighters1.h"




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
    int choixtypecombat=0;                   
    int niveaubot=0;
    int f=0;
    int n=0;
    int choixcombattantbot=0;
    int minpv=0;
    Combattant équipe1témoin[3];
    Combattant équipe2témoin[3];
    int passetontour=0;
    int* passe=&passetontour;//variable permettant de savoir si le joueur a le droit de jouer ou pas
    float esquive;
    int validiter;// variable servant a vérifier la validiter des scanf
    FILE *f1 = fopen("combattants/mme_enserre_main", "r");//ouverture de tous les fichiers des combattans
    if (f1 == NULL) {
        printf("problème fichier combattant 1\n");
        exit(1);}
    FILE *f2 = fopen("combattants/mme_gros_t’es_qui", "r");
    if (f2 == NULL) {  
        printf("problème fichier combattant 2\n");  
        exit(2); } 
    FILE *f3 = fopen("combattants/mme_menu-bretin", "r");
    if (f3 == NULL) {
        printf("problème fichier combattant 3\n");    
        exit(3);}
    FILE *f4 = fopen("combattants/mme_picasso", "r");
    if (f4 == NULL) {  
        printf("problème fichier combattant 4\n"); 
        exit(4);}
    FILE *f5 = fopen("combattants/mr_j’accuse_iel", "r");
    if (f5 == NULL) {  
        printf("problème fichier combattant 5\n");
        exit(5); } 
    FILE *f6 = fopen("combattants/mr_abdelmoulaga", "r");
    if (f6 == NULL) { 
        printf("problème fichier combattant 6\n"); 
        exit(6);  } 
    FILE *f7 = fopen("combattants/mr_arancini", "r");
    if (f7 == NULL) {  
        printf("problème fichier combattant 7\n");  
        exit(7);}
    FILE *f8 = fopen("combattants/mr_bissap", "r");
    if (f8 == NULL) { 
        printf("problème fichier combattant 8\n");
        exit(8);}  
    FILE *f9 = fopen("combattants/mr_gay_prides", "r");
    if (f9 == NULL) { 
        printf("problème fichier combattant 9\n");
        exit(9);}
    FILE *f10 = fopen("combattants/mr_grognon", "r");
    if (f10 == NULL) {
        printf("problème fichier combattant 10\n");
        exit(10);}
    FILE *f11 = fopen("combattants/mr_par-dessus", "r");
    if (f11 == NULL) {
        printf("problème fichier combattant 11\n");
        exit(11); } 
    FILE *f12 = fopen("combattants/mr_pelleteuse", "r");
    if (f12 == NULL) {
        printf("problème fichier combattant 12\n");
        exit(12); } 
    

    FILE *comp1=fopen("Competences speciales/Paquets d'Arthur", "r");
    if (comp1 == NULL) {
        printf("problème fichier compétence 1\n");
        exit(13);}
    FILE *comp2=fopen("Competences speciales/appel du cartel", "r");
    if (comp2 == NULL) {
        printf("problème fichier compétence 2\n");
        exit(14);}
    FILE *comp3=fopen("Competences speciales/devoir-de-meca", "r");
    if (comp3 == NULL) {
        printf("problème fichier compétence 3\n");
        exit(15);}    
    FILE *comp4=fopen("Competences speciales/ecrasement par doc martens", "r");
    if (comp4 == NULL) {
        printf("problème fichier compétence 4\n");
        exit(16);}
    FILE *comp5=fopen("Competences speciales/injection sql", "r");
    if (comp5 == NULL) {
        printf("problème fichier compétence 5\n");
        exit(17);}
    FILE *comp6=fopen("Competences speciales/justification parfaite", "r");   
    if (comp6 == NULL) {
        printf("problème fichier compétence 6\n");
        exit(18);}
    FILE *comp7=fopen("Competences speciales/long délai", "r");
    if (comp7 == NULL) {
        printf("problème fichier compétence 7\n");
        exit(19);}
    FILE *comp8=fopen("Competences speciales/remise des bulletins", "r");
    if (comp8 == NULL) {
        printf("problème fichier compétence 8\n");
        exit(20);}
    FILE *comp9=fopen("Competences speciales/renvoi", "r");
    if (comp9 == NULL) {
        printf("problème fichier compétence 9\n");
        exit(21);}
    FILE *comp10=fopen("Competences speciales/spam Teams", "r");
    if (comp10 == NULL) {
        printf("problème fichier compétence 10\n");
        exit(22);}
    FILE *comp11=fopen("Competences speciales/trust the process", "r");
    if (comp11 == NULL) {
        printf("problème fichier compétence 11\n");
        exit(23);}
    FILE *comp12=fopen("Competences speciales/vous etes des clowns", "r");
    if (comp12 == NULL) {
        printf("problème fichier compétence 12\n");
        exit(24);}

    liste[0] = ConveCombattant(f1,comp4);//affecter les combattants aux fichiers
    liste[1] = ConveCombattant(f2,comp10);
    liste[2] = ConveCombattant(f3,comp7);
    liste[3] = ConveCombattant(f4,comp8);
    liste[4] = ConveCombattant(f5,comp9);
    liste[5] = ConveCombattant(f6,comp12);
    liste[6] = ConveCombattant(f7,comp1);
    liste[7] = ConveCombattant(f8,comp11);
    liste[8] = ConveCombattant(f9,comp3);
    liste[9] = ConveCombattant(f10,comp5);
    liste[10] = ConveCombattant(f11,comp2);
    liste[11] = ConveCombattant(f12,comp6);

    system("clear");
    
    printf("Bienvenue dans le jeu de combat cyfighters !\n\n");
    do{
        printf("Choisissez le type de combat :1 si vous souhaitez faire un combat contre une autre personne ou 2 si vous si souhaitez combattre contre un bot\n");
        validiter=scanf("%d", &choixtypecombat);
        vérifscanf(validiter);
    }while(choixtypecombat<1 || choixtypecombat>2 || validiter!=1);

    
    if(choixtypecombat==1){//choix du type de combat
        printf("Joueur 1, choisissez un nom d'équipe :\n");
        scanf(" %50[^\n]", nomEquipe1);  // lit toute la ligne jusqu'à 50 caractères ou jusqu'à un retour à la ligne
        printf("Joueur 2, choisissez un nom d'équipe :\n");
        scanf(" %50[^\n]", nomEquipe2); 
        system("clear");
        for(int i=0; i<3;i++){//choix des combattants
            do{
                afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
                printf("Joueur1 choisissez votre combattant numéro %d en saisissant sont numéro\n",compteur1);
                validiter=scanf("%d", &choix1);
                vérifscanf(validiter);    
            }while(choix1<1 || choix1>12-compteur3 || validiter!=1);
            équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
            miseàJourCombattants(liste, choix1-1);//mise à jour de la liste de combattants
            system("clear");
            compteur1++;
            compteur3++;
            do{
                afficherCombattantsDisponibles(liste, 12-compteur3);
                printf("Joueur2 choisissez votre combattant numéro %d en saisissant sont numéro\n",compteur2);
                validiter=scanf("%d", &choix1);
                vérifscanf(validiter);
            }while(choix1<1 || choix1>12-compteur3 || validiter!=1);
            équipe2[i] = liste[choix1-1];
            miseàJourCombattants(liste, choix1-1);//mise à jour de la liste de combattants
            system("clear");
            compteur2++;
            compteur3++;

        }
        for(int v=0; v<3; v++){
            équipe1témoin[v]=équipe1[v];
            équipe2témoin[v]=équipe2[v];
        }
        for(int t=0; t<3; t++){//initialisation de la vitesse courante
            équipe1[t].vitessecourante=rand()%40+1;
            équipe2[t].vitessecourante=rand()%40+1;
        }
        choix1=0;
        
        
        do{//déroulement et affichage du combat joeur/joueur
            //déroulement du tour du joueur 1
            if(passetontour==1){
                printf("L'équipe %s a utiliser une capacité spéciale pour vous empêcher de jouer \n",nomEquipe2);
                passetontour=0;
                sleep(5);
            }
            else{
                for(int q=0; q<3; q++){//mise à jour de la vitesse courante
                    if(équipe1[q].pvcourants>0){
                    équipe1[q].vitessecourante+=équipe1[q].vitesse;
                    }
                }
                for( n=0; n<3; n++){
                    if(équipe1[n].vitessecourante>100){
                        équipe1[n].vitessecourante=100;
                    }
                }
                printf("Tour %d\n", nombredetour);
                do{//choix du combattant qui va attaquer
                    do{
                        system("clear");
                        affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
                        printf("Equipe %s, choisissez le combattant qui va attaquer\n", nomEquipe1);
                        validiter=scanf("%d", &choix1);
                        vérifscanf(validiter);
                    }while(choix1<1 || choix1>3 || validiter!=1);
                    choix1=choix1-1;
                    if(équipe1[choix1].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(équipe1[choix1].pvcourants==0);
                if(équipe1[choix1].vitessecourante!=100){
                    do{
                        do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            validiter=scanf("%d", &choix2);
                            vérifscanf(validiter);
                        }while(choix2<1 || choix2>3 || validiter!=1);
                        choix2--;
                        if(équipe2[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                    }while(équipe2[choix2].pvcourants<=0);
                    esquive=(rand()%100+1)/100.00;
                    if(esquive<équipe2[choix2].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                    équipe2[choix2].pvcourants-=équipe1[choix1].attaque*équipe2[choix2].defense;
                    printf("L'attaque a été réussie\n");
                    }
                }
                else{
                    do{//choix du type d'attaque
                        printf("Votre capacité spéciale est disponible, tapez 1 pour attaquer normalement ou 2 pour utiliser votre capacité spéciale\n");
                        validiter=scanf("%d", &choixcap);
                        vérifscanf(validiter);
                    }while(choixcap<1 || choixcap>2 || validiter!=1);
                    if(choixcap==1){
                        do{
                            do{//choix du combattant à attaquer si la capacité spéciale est disponible
                                printf("Choisissez un adversaire à attaquer\n");
                                validiter=scanf("%d", &choix2);
                                vérifscanf(validiter);
                            }while(choix2<1 || choix2>3 || validiter!=1);
                            choix2=choix2-1;
                            if(équipe2[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(équipe2[choix2].pvcourants<=0);
                        esquive=(rand()%100+1)/100.00;
                        if(esquive<équipe2[choix2].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{
                        équipe2[choix2].pvcourants-=équipe1[choix1].attaque*équipe2[choix2].defense;
                        printf("L'attaque a été réussie\n");
                        }
              
                    }
                    else{
                        équipe1[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe1,nomEquipe1, équipe1témoin, équipe2,nomEquipe2, équipe2témoin, choix1, 0, passe);//utilisation de la capacité spéciale    
                    }
                }
                Miseàjourcompétence(équipe1, équipe1témoin);
                for(n=0; n<3; n++){
                    if(équipe2[n].pvcourants<0){
                        équipe2[n].pvcourants=0;
                    }
                }
                sleep(5);
            }
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");                       
            //déroulement du tour du joueur 2            
            if((équipe2[0].pvcourants<=0 && équipe2[1].pvcourants<=0 && équipe2[2].pvcourants<=0) || passetontour==1){
                if(passetontour==1){
                    printf("L'équipe %S a utiliser une capacité spéciale pour vous empêcher de jouer\n",nomEquipe1);
                    passetontour=0;

                }
            }
            else{
                for(int y=0; y<3; y++){//mise à jour de la vitesse courante
                    if(équipe2[y].pvcourants>0){
                    équipe2[y].vitessecourante+=équipe2[y].vitesse;
                    }
                }
                for( n=0; n<3; n++){
                    if(équipe2[n].vitessecourante>100){
                        équipe2[n].vitessecourante=100;
                    }
                }
                affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
                do{//choix du combattant qui va attaquer
                    do{
                        printf("Equipe %s, choisissez le combattant qui va attaquer\n",nomEquipe2);
                        validiter=scanf("%d", &choix1);
                        vérifscanf(validiter);
                    }while(choix1<1 || choix1>3 || validiter!=1);
                    choix1=choix1-1;
                    if(équipe2[choix1].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(équipe2[choix1].pvcourants<=0);
                if(équipe2[choix1].vitessecourante!=100){
                    do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                        do{
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            validiter=scanf("%d", &choix2);
                            vérifscanf(validiter);
                        }while(choix2<1 || choix2>3 || validiter!=1);
                        choix2--;
                        if(équipe1[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                        }   
                    }while(équipe1[choix2].pvcourants<=0);
                    esquive=(rand()%100+1)/100.00;
                    if(esquive<équipe1[choix2].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                    équipe1[choix2].pvcourants-=équipe2[choix1].attaque*équipe1[choix2].defense;
                    printf("L'attaque a été réussie\n");
                    } 
                }else{
                    do{//choix du type d'attaque
                        printf("Votre capacité spéciale est disponible, tapez 1 pour attaquer normalement ou 2 pour utiliser votre capacité spéciale\n");
                        validiter=scanf("%d", &choixcap);
                        vérifscanf(validiter);
                    }while(choixcap<1 || choixcap>2 || validiter!=1);
                    if(choixcap==1){
                        do{
                            do{//choix du combattant à attaquer si la capacité spéciale est disponible
                                printf("Choisissez un adversaire à attaquer\n");
                                validiter=scanf("%d", &choix2);
                                vérifscanf(validiter);
                            }while(choix2<1 || choix2>3 || validiter!=1);
                            choix2--;
                            if(équipe1[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(équipe1[choix2].pvcourants<=0);
                        esquive=(rand()%100+1)/100;
                        if(esquive<équipe1[choix2].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{
                        équipe1[choix2].pvcourants-=équipe2[choix1].attaque*équipe1[choix2].defense;
                        printf("L'attaque a été réussie\n");
                        }
                    }    
                    else{
                        équipe2[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe2,nomEquipe2, équipe2témoin, équipe1, nomEquipe1, équipe1témoin, choix1,0, passe);//utilisation de la capacité spéciale    
                        sleep(5);
                    }  
                }
                Miseàjourcompétence(équipe2, équipe2témoin);
                for(n=0; n<3; n++){
                    if(équipe2[n].pvcourants<0){
                        équipe2[n].pvcourants=0;
                    }
                }
                sleep(5);
            }
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");
            nombredetour++;
        }while((équipe1[0].pvcourants>0 && équipe1[1].pvcourants>0 && équipe1[2].pvcourants>0) && (équipe2[0].pvcourants>0 && équipe2[1].pvcourants>0 && équipe2[2].pvcourants>0) );//condition de fin de combat
        if(équipe1[0].pvcourants<=0 && équipe1[1].pvcourants<=0 && équipe1[2].pvcourants<=0){
            affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
            printf("L'équipe %s composé de %s, %s, %s a gagné !\n", nomEquipe2, équipe2[0].nom, équipe2[1].nom, équipe2[2].nom);
        }
        else{
            affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
            printf("L'équipe %s composé de %s, %s, %s a gagné !\n", nomEquipe1, équipe1[0].nom, équipe1[1].nom, équipe1[2].nom);
        }   
    }         
    else{ //combat joueur vs bot  
        do{
            printf("Choisissez la difficulté du bot : 1 pour noob, 2 pour facile, 3 pour moyen\n");
            validiter=scanf("%d", &niveaubot);
            vérifscanf(validiter);
        }while(niveaubot<1 || niveaubot>3 || validiter!=1);
        printf("Joueur 1, choisissez un nom d'équipe :\n");
        scanf(" %50[^\n]", nomEquipe1);  
        if(niveaubot==1){
            strcpy(nomEquipe2, "bot niveau 1");
        }
        if(niveaubot==2){
            strcpy(nomEquipe2, "bot niveau 2");
        }
        if(niveaubot==3){
            strcpy(nomEquipe2, "bot niveau 3");
        }
        system("clear");
        for(int i=0; i<3;i++){//choix des combattants
            do{
                afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
                printf("Equipe %s choisissez votre combattant numéro %d en saisissant sont numéro\n",nomEquipe1,compteur1);
                validiter=scanf("%d", &choix1);
                vérifscanf(validiter);
            }while(choix1<1 || choix1>12-compteur3 || validiter!=1);
            équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
            miseàJourCombattants(liste, choix1-1);//mise à jour de la liste de combattants
            system("clear");
            compteur1++;
            compteur3++;
            afficherCombattantsDisponibles(liste, 12-compteur3);
            choixcombattantbot=rand()%12-compteur3;
            printf("Le bot a choisi %s pour son champion n°%d\n",liste[choixcombattantbot].nom,compteur2);
            sleep(5);
            équipe2[i] = liste[choix1];
            miseàJourCombattants(liste, choix1);//mise à jour de la liste de combattants
            system("clear");
            compteur2++;
            compteur3++;

        }
        for(int v=0; v<3; v++){
            équipe1témoin[v]=équipe1[v];
            équipe2témoin[v]=équipe2[v];
        }
        for(int t=0; t<3; t++){
            équipe1[t].vitessecourante=rand()%50+1;
            équipe2[t].vitessecourante=rand()%50+1;
        }   
        do{
            if(passetontour==1){
                printf("Le bot a utiliser une capacité spéciale pour vous empêcher de jouer \n");
                passetontour=0;
                sleep(5);
            }
            else{
                //déroulement du tour du joueur 1
                for(int q=0; q<3; q++){//mise à jour de la vitesse courante
                    if(équipe1[q].pvcourants>0){
                    équipe1[q].vitessecourante+=équipe1[q].vitesse;
                    }
                }
                for( n=0; n<3; n++){
                    if(équipe1[n].vitessecourante>100){
                        équipe1[n].vitessecourante=100;
                    }
                }
                printf("Tour %d\n", nombredetour);
                affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
                do{
                    do{
                        printf("Equipe %s, choisissez le combattant qui va attaquer\n",nomEquipe1);
                        validiter=scanf("%d", &choix1);
                        vérifscanf(validiter);
                    }while(choix1<1 || choix1>3 || validiter!=1);
                    choix1=choix1-1;
                    if(équipe1[choix1].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(équipe1[choix1].pvcourants==0);
                if(équipe1[choix1].vitessecourante!=100){
                    do{
                        do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            validiter=scanf("%d", &choix2);
                            vérifscanf(validiter);
                        }while(choix2<1 || choix2>3 || validiter!=1);
                        choix2--;
                        if(équipe2[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                        }
                    }while(équipe2[choix2].pvcourants<=0);
                    esquive=(rand()%100+1)/100.00;
                    if(esquive<équipe2[choix2].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        équipe2[choix2].pvcourants-=équipe1[choix1].attaque*équipe2[choix2].defense;
                        printf("L'attaque a été réussie\n");
                    }                   
                }
                else{
                    do{//choix du type d'attaque
                        printf("Votre capacité spéciale est disponible, tapez 1 pour attaquer normalement ou 2 pour utiliser votre capacité spéciale\n");
                        validiter=scanf("%d", &choixcap);
                        vérifscanf(validiter);
                    }while(choixcap<1 || choixcap>2 || validiter!=1);
                    if(choixcap==1){
                        do{
                            do{//choix du combattant à attaquer si la capacité spéciale est disponible
                                printf("Choisissez un adversaire à attaquer\n");
                                validiter=scanf("%d", &choix2);
                                vérifscanf(validiter);
                            }while(choix2<1 || choix2>3 || validiter!=1);
                            choix2=choix2-1;
                            if(équipe2[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(équipe2[choix2].pvcourants<=0);
                        esquive=(rand()%100+1)/100.00;
                        if(esquive<équipe2[choix2].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{  
                        équipe2[choix2].pvcourants-=équipe1[choix1].attaque*équipe2[choix2].defense;
                        printf("L'attaque a été réussie\n");
                        }                        
                    }
                    else{
                        équipe1[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe1,nomEquipe1, équipe1témoin, équipe2,nomEquipe2, équipe2témoin, choix1,0, passe);//utilisation de la capacité spéciale    
                    }
                }
                sleep(5);
                for(n=0; n<3; n++){
                    if(équipe2[n].pvcourants<0){
                        équipe2[n].pvcourants=0;
                    }
                }
                Miseàjourcompétence(équipe1, équipe1témoin);//mise à jour des effets sur le combattant
            }
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");
            if((équipe2[0].pvcourants<=0 && équipe2[1].pvcourants<=0 && équipe2[2].pvcourants<=0) || passetontour==1){
                if(passetontour==1){
                    printf("Le bot ne peut pas jouer car vous avez utilisé une capacité spéciale pour l'en empêcher \n");
                    passetontour=0;
                }    
            }
            else{
                for( n=0; n<3; n++){//mise à jour de la vitesse courante
                    if(équipe2[n].pvcourants>0){
                    équipe2[n].vitessecourante+=équipe2[n].vitesse;
                    }
                }
                for( n=0; n<3; n++){
                    if(équipe2[n].vitessecourante>100){
                        équipe2[n].vitessecourante=100;
                    }
                }
                printf("Tour %d\n", nombredetour);
                affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
                //attaque du bot suivant son niveau de difficulté
                if(niveaubot==1){
                    do{
                        choix1=rand()%3;
                    }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0);
                    printf("Le bot a choisi %s pour attaquer\n", équipe2[choix1].nom);
                    do{
                        choix2=rand()%3;
                    }while(choix2<0 || choix2>2 || équipe1[choix2].pvcourants<=0);
                    printf("Le bot a choisi d'attaquer %s\n", équipe1[choix2].nom);
                    esquive=(rand()%100+1)/100.00;
                    if(esquive<équipe1[choix2].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        équipe1[choix2].pvcourants-=équipe2[choix1].attaque*équipe1[choix2].defense;
                        printf("L'attaque a été réussie\n");
                    }
                    
                }
                else if(niveaubot==2){
                    do{
                        choix1=rand()%3;
                    }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0);
                    printf("Le bot a choisi %s pour attaquer\n", équipe2[choix1].nom);
                    for( n=1; n<3; n++){
                        if(équipe1[minpv].pvcourants>équipe1[n].pvcourants){
                            minpv=n;
                        }
                    }
                    printf("Le bot a choisi d'attaquer %s car il est le combattant avec le moins de pv\n", équipe1[minpv].nom);
                    esquive=(rand()%100+1)/100.00;
                    if(esquive<équipe1[minpv].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        équipe1[minpv].pvcourants-=équipe2[choix1].attaque*équipe1[minpv].defense;
                        printf("L'attaque a été réussie\n");
                    }
                    
                }
                else{
                    if(équipe2[0].vitessecourante<100 && équipe2[1].vitessecourante<100 && équipe2[2].vitessecourante<100){
                        do{
                            choix1=rand()%3;
                        }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0);
                        printf("Le bot a choisi d'attaquer avec %s mais n'a pas sa capacité spéciale spéciale\n",équipe2[choix1].nom );
                        for( n=1; n<3; n++){
                            if(équipe1[minpv].pvcourants>équipe1[n].pvcourants){
                                minpv=n;
                            }
                        }
                        printf("Le bot a choisi d'attaquer %s car il est le combattant avec le moins de pv\n", équipe1[minpv].nom);
                        esquive=(rand()%100+1)/100.00;
                        if(esquive<équipe1[minpv].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{
                            équipe1[minpv].pvcourants-=équipe2[choix1].attaque*équipe1[minpv].defense;
                            printf("L'attaque a été réussie\n");
                        }    
                    }
                    else{
                        do{
                            choix1=rand()%3;
                        }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0 || équipe2[choix1].vitessecourante<100);
                        printf("Le bot a choisi d'utiliser la capacité de %s\n",équipe2[choix1].nom );
                        équipe2[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe2,nomEquipe2, équipe2témoin, équipe1,nomEquipe1, équipe1témoin, choix1,1, passe);
                    }
                }
                Miseàjourcompétence(équipe2, équipe2témoin);//mise à jour des effets sur le combattant
                sleep(10);   
                for(n=0; n<3; n++){
                    if(équipe1[n].pvcourants<0){
                        équipe1[n].pvcourants=0;
                    }
                }             
            }           
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");    
        }while((équipe1[0].pvcourants>0 && équipe1[1].pvcourants>0 && équipe1[2].pvcourants>0) && (équipe2[0].pvcourants>0 && équipe2[1].pvcourants>0 && équipe2[2].pvcourants>0) );//condition de fin de combat
        if(équipe1[0].pvcourants<=0 && équipe1[1].pvcourants<=0 && équipe1[2].pvcourants<=0){
            affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
            printf("L'équipe %s composé de %s, %s, %s a gagné !\n", nomEquipe2, équipe2[0].nom, équipe2[1].nom, équipe2[2].nom);
        }
        else{
            affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
            printf("L'équipe %s composé de %s, %s, %s a gagné !\n", nomEquipe1, équipe1[0].nom, équipe1[1].nom, équipe1[2].nom);
        }       
    }   
return 0;
}



