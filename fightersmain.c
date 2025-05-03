#include "fighters.h"




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
        exit(8);}  
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
    liste[0].competspe =Convecompspé(comp4);
    liste[1] = ConveCombattant(f2);
    liste[1].competspe = Convecompspé(comp10);
    liste[2] = ConveCombattant(f3);
    liste[2].competspe = Convecompspé(comp7);
    liste[3] = ConveCombattant(f4);
    liste[3].competspe = Convecompspé(comp8);
    liste[4] = ConveCombattant(f5);
    liste[4].competspe = Convecompspé(comp9);
    liste[5] = ConveCombattant(f6);
    liste[5].competspe = Convecompspé(comp12);
    liste[6] = ConveCombattant(f7);
    liste[6].competspe = Convecompspé(comp1);
    liste[7] = ConveCombattant(f8);
    liste[7].competspe = Convecompspé(comp11);
    liste[8] = ConveCombattant(f9);
    liste[8].competspe = Convecompspé(comp3);
    liste[9] = ConveCombattant(f10);
    liste[9].competspe = Convecompspé(comp5);
    liste[10] = ConveCombattant(f11);
    liste[10].competspe = Convecompspé(comp2);
    liste[11] = ConveCombattant(f12);
    liste[11].competspe = Convecompspé(comp6);

    
    
    printf("Bienvenue dans le jeu de combat cyfighters !\n\n");
    do{
        printf("Choisissez le type de combat :1 si vous souhaitez faire un combat contre une autre personne ou 2 si vous si souhaitez combattre contre un bot\n");
        scanf("%d", &choixtypecombat);
    }while(choixtypecombat<1 || choixtypecombat>2);

    
    if(choixtypecombat==1){//choix du type de combat
        printf("Joueur 1, choisissez un nom d'équipe :\n");
        scanf(" %50[^\n]", nomEquipe1);  // lit toute la ligne jusqu'à 50 caractères ou jusqu'à un retour à la ligne
        printf("Joueur 2, choisissez un nom d'équipe :\n");
        scanf(" %50[^\n]", nomEquipe2); 
        
        for(int i=0; i<3;i++){//choix des combattants
            do{
                afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
                printf("Joueur1 choisissez votre combattant numéro %d en saisissant sont numéro",compteur1);
                scanf("%d", &choix1);
            
            }while(choix1<1 || choix1>12-compteur3 );
            équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
            miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
            system("clear");
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
        for(int v=0; v<3; v++){
            strcpy(équipe1témoin[v], équipe1[v]);
            strcpy(équipe2témoin[v], équipe2[v]);
        }
        for(int t=0; t<3; t++){//initialisation de la vitesse courante
            équipe1[t].vitessecourante=rand()%50+1;
            équipe2[t].vitessecourante=rand()%50+1;
        }
        choix1=0;
        system("clear");
        
        do{//déroulement et affichage du combat
            //déroulement du tour du joueur 1
            if(passetontour==1){
                printf("L'adversaire a utiliser une capacité spéciale pour vous empêcher de jouer \n");

            }else{
                for(int q=0; q<3; q++){//mise à jour de la vitesse courante
                    équipe1[q].vitessecourante+=équipe1[q].vitesse;
                }
                for( n=0; n<3; n++){
                    if(équipe1[n].vitessecourante>100){
                        équipe1[n].vitessecourante=100;
                    }
                }
                printf("Tour %d\n", nombredetour);
                affichecombat(équipe1, nomEquipe1, équipe2, nomEquipe2);
                do{//choix du combattant qui va attaquer
                    do{
                        printf("Joueur 1, choisissez le combattant qui va attaquer\n");
                        scanf("%d", &choix1);
                    }while(choix1<1 || choix1>3);
                    choix1=choix1-1;
                    if(équipe1[choix1].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(équipe1[choix1].pvcourants==0);
                if(équipe1[choix1].vitessecourante!=100){
                    do{
                        do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            scanf("%d", &choix2);
                        }while(choix2<1 || choix2>3);
                        choix2--;
                        if(équipe2[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                    };
                    }while(équipe2[choix2].pvcourants<=0);
                    équipe2[choix2].pvcourants-=équipe1[choix1].attaque;
                }
                else{
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
                            choix2=choix2-1;
                            if(équipe2[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(équipe2[choix2].pvcourants<=0);
                    équipe2[choix2].pvcourants-=équipe1[choix1].attaque;
                    }
                    else{
                        équipe1[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe1,nomEquipe1, équipe2,nomEquipe2, choix1, 0, passe);//utilisation de la capacité spéciale    
                    }
                sleep(5);
                }
            }
            for(n=0; n<3; n++){
                if(équipe2[n].pvcourants<0){
                    équipe2[n].pvcourants=0;
                }
            }
            for(f=0; f<3; f++){
                if(équipe1[f].nombredetouractif1>0){
                    équipe1[f].nombredetouractif1--;
                    if(équipe1[f].nombredetouractif1==0){
                        Miseàjourcompétence(équipe1, f, 1);//mise à jour des effets sur le combattant
                    }
                }
                if(équipe1[f].nombredetouractif2>0){
                    équipe1[f].nombredetouractif2--;
                    if(équipe1[f].nombredetouractif2==0){
                        Miseàjourcompétence(équipe1, f, 2);//mise à jour des effets sur le combattant    
                    }
                }
                if(équipe1[f].nombredetouractif3>0){
                    équipe1[f].nombredetouractif3--;
                    if(équipe1[f].nombredetouractif3==0){
                        Miseàjourcompétence(équipe1, f, 3);//mise à jour des effets sur le combattant    
                    }
                }
            }
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");
           
            
            //déroulement du tour du joueur 2
            
            if((équipe2[0].pvcourants<=0 && équipe2[1].pvcourants<=0 && équipe2[2].pvcourants<=0) || passetontour==1){
                if(passetontour==1){
                    printf("L'avdersaire a utiliser une capacitéspéciale pour vous empêcher de jouer\n");
                }
            }
            else{
                for(int y=0; y<3; y++){//mise à jour de la vitesse courante
                    équipe2[y].vitessecourante+=équipe2[y].vitesse;
                }
                for( n=0; n<3; n++){
                    if(équipe2[n].vitessecourante>100){
                        équipe2[n].vitessecourante=100;
                    }
                }
                affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
                do{//choix du combattant qui va attaquer
                    do{
                        printf("Joeur 1, choisissez le combattant qui va attaquer\n");
                        scanf("%d", &choix1);
                    }while(choix1<1 || choix1>3);
                    choix1=choix1-1;
                    if(équipe2[choix1].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(équipe2[choix1].pvcourants<=0);
                if(équipe2[choix1].vitessecourante!=100){
                    do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                        do{
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            scanf("%d", &choix2);
                        }while(choix2<1 || choix2>3);
                        choix2--;
                        if(équipe1[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                        }   
                    }while(équipe1[choix2].pvcourants<=0);
                équipe1[choix2].pvcourants-=équipe2[choix1].attaque; 
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
                            choix2--;
                            if(équipe1[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(équipe1[choix2].pvcourants<=0);
                        équipe1[choix2].pvcourants-=équipe2[choix1].attaque;
                    }    
                    else{
                        équipe2[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe2,nomEquipe2, équipe1, nomEquipe1, choix1,0, passe);//utilisation de la capacité spéciale    
                    } 
                sleep(5);   
                }
                for( f=0; f<3; f++){
                    if(équipe2[f].nombredetouractif1>0){
                        équipe2[f].nombredetouractif1--;
                        if(équipe2[f].nombredetouractif1==0){
                            Miseàjourcompétence(équipe2, f, 1);//mise à jour des effets sur le combattant
                        }
                    }
                    if(équipe2[f].nombredetouractif2>0){
                        équipe2[f].nombredetouractif2--;
                        if(équipe2[f].nombredetouractif2==0){
                            Miseàjourcompétence(équipe2, f, 2);//mise à jour des effets sur le combattant    
                        }
                    }
                    if(équipe1[f].nombredetouractif3>0){
                        équipe1[f].nombredetouractif3--;
                        if(équipe1[f].nombredetouractif3==0){
                            Miseàjourcompétence(équipe2, f, 3);//mise à jour des effets sur le combattant    
                        }
                    }
                }
            
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");
            nombredetour++;
        }while((équipe1[0].pvcourants>0 && équipe1[1].pvcourants>0 && équipe1[2].pvcourants) && (équipe2[1].pvcourants>0 && équipe2[2].pvcourants>0 && équipe2[2].pvcourants>0) );//condition de fin de combat
        if(équipe1[0].pvcourants<=0 && équipe1[1].pvcourants<=0 && équipe1[2].pvcourants<=0){
            printf("L'équipe %s composé de %s %s %s a gagné !\n", nomEquipe2, équipe2[0].nom, équipe2[1].nom, équipe2[2].nom);
        }
        else{
            printf("L'équipe %s composé de %s %s %s a gagné !\n", nomEquipe1, équipe1[0].nom, équipe1[1].nom, équipe1[2].nom);
        }
   
   
   
   
   
    }
   
   
   
    else{
        
        do{
            printf("Choisissez la difficulté du bot : 1 pour noob, 2 pour facile, 3 pour moyen\n");
            scanf("%d", &niveaubot);
        }while(niveaubot<1 || niveaubot>3);
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
        for(int i=0; i<3;i++){//choix des combattants
            do{
                afficherCombattantsDisponibles(liste, 12-compteur3);//afficher les combattants disponibles
                printf("Joueur1 choisissez votre combattant numéro %d en saisissant sont numéro",compteur1);
                scanf("%d", &choix1);
            }while(choix1<1 || choix1>12-compteur3 );
            équipe1[i] = liste[choix1-1];//affecter le combattant choisi à l'équipe 1
            miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
            system("clear");
            compteur1++;
            compteur3++;
            afficherCombattantsDisponibles(liste, 12-compteur3);
            choixcombattantbot=rand()%12-compteur3+1;
            printf("Le bot a choisi %s pour son champion n°%d",liste[choixcombattantbot].nom,compteur2);
            sleep(5);
            équipe2[i] = liste[choix1];
            miseaJourCombattants(liste, choix1);//mise à jour de la liste de combattants
            system("clear");
            compteur2++;
            compteur3++;

        }
        for(int v=0; v<3; v++){
            strcpy(équipe1témoin[v], équipe1[v]);
            strcpy(équipe2témoin[v], équipe2[v]);
        }
        do{
            //déroulement du tour du joueur 1
            for(int q=0; q<3; q++){//mise à jour de la vitesse courante
                équipe1[q].vitessecourante+=équipe1[q].vitesse;
            }
            for( n=0; n<3; n++){
                if(équipe1[n].vitessecourante>100){
                    équipe1[n].vitessecourante=100;
                }
            }
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
                }
            }while(équipe1[choix1].pvcourants==0);
            if(équipe1[choix1].vitessecourante!=100){
                do{
                    do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                        printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                        scanf("%d", &choix2);
                    }while(choix2<1 || choix2>3);
                    choix2--;
                    if(équipe2[choix2].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                   };
                }while(équipe2[choix2].pvcourants<=0);
                équipe2[choix2].pvcourants-=équipe1[choix1].attaque;
            }
            else{
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
                        choix2=choix2-1;
                        if(équipe2[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                        }
                    }while(équipe2[choix2].pvcourants<=0);
                équipe2[choix2].pvcourants-=équipe1[choix1].attaque;
                }
                else{
                    équipe1[choix1].vitessecourante=0;
                    Utilisationcompétence(équipe1,nomEquipe1, équipe2,nomEquipe2, choix1,0, passe);//utilisation de la capacité spéciale    
                }
            sleep(5);
            }
            for(n=0; n<3; n++){
                if(équipe2[n].pvcourants<0){
                    équipe2[n].pvcourants=0;
                }
            }
            for(f=0; f<3; f++){
                if(équipe1[f].nombredetouractif1>0){
                    équipe1[f].nombredetouractif1--;
                    if(équipe1[f].nombredetouractif1==0){
                        Miseàjourcompétence(équipe2, f, 1);//mise à jour des effets sur le combattant
                    }
                }
                if(équipe1[f].nombredetouractif2>0){
                    équipe1[f].nombredetouractif2--;
                    if(équipe1[f].nombredetouractif2==0){
                        Miseàjourcompétence(équipe2, f, 2);//mise à jour des effets sur le combattant    
                    }
                }
                if(équipe1[f].nombredetouractif3>0){
                    équipe1[f].nombredetouractif3--;
                    if(équipe1[f].nombredetouractif3==0){
                        Miseàjourcompétence(équipe2, f, 3);//mise à jour des effets sur le combattant    
                    }
                }
            }
            choix1=0;
            choix2=0;
            choixcap=0;
            system("clear");
            affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);


            if(équipe2[0].pvcourants<=0 && équipe2[1].pvcourants<=0 && équipe2[2].pvcourants<=0){
                
            }
            else{
                for( n=0; n<3; n++){//mise à jour de la vitesse courante
                    équipe2[n].vitessecourante+=équipe2[n].vitesse;
                }
                for( n=0; n<3; n++){
                    if(équipe2[n].vitessecourante>100){
                        équipe2[n].vitessecourante=100;
                    }
                }
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
                    équipe1[choix2].pvcourants-=équipe2[choix1].attaque;
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
                    équipe1[minpv].pvcourants-=équipe2[choix1].attaque;
                }

                else(niveaubot==3){
                    if(équipe2[0].vitessecourante<100 && équipe2[1].vitessecourante<100 && équipe2[2].vitessecourante<100){
                        do{
                            choix1=rand()%3;
                        }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0);
                        printf("Le bot a choisi d'attaquer avec %s mais n'a pas sa capacité spéciale spéciale",équipe2[choix1].nom )
                        for( n=1; n<3; n++){
                            if(équipe1[minpv].pvcourants>équipe1[n].pvcourants){
                                minpv=n;
                            }
                        }
                        printf("Le bot a choisi d'attaquer %s car il est le combattant avec le moins de pv\n", équipe1[minpv].nom);
                        équipe1[minpv].pvcourants-=équipe2[choix1].attaque;
                    }
                    else{
                        do{
                            choix1=rand()%3
                        }while(choix1<0 || choix1>2|| équipe2[choix1].pvcourants<=0 || équipe2[choix1].vitessecourante<100);
                        printf("Le bot a choisi d'utiliser la capacité de %s",équipe[choix1].nom );
                        équipe2[choix1].vitessecourante=0;
                        Utilisationcompétence(équipe2,nomEquipe2, équipe1,nomEquipe1, choix1,1, passe);


                    }
                }
                sleep(5);
                for(n=0; n<3; n++){
                    if(équipe2[n].pvcourants<0){
                        équipe2[n].pvcourants=0;
                    }
                }
                for(f=0; f<3; f++){
                    if(équipe1[f].nombredetouractif1>0){
                        équipe1[f].nombredetouractif1--;
                        if(équipe1[f].nombredetouractif1==0){
                            Miseàjourcompétence(équipe1, f, 1);//mise à jour des effets sur le combattant
                        }
                    }
                    if(équipe1[f].nombredetouractif2>0){
                        équipe1[f].nombredetouractif2--;
                        if(équipe1[f].nombredetouractif2==0){
                            Miseàjourcompétence(équipe1, f, 2);//mise à jour des effets sur le combattant    
                        }
                    }
                    if(équipe1[f].nombredetouractif3>0){
                        équipe1[f].nombredetouractif3--;
                        if(équipe1[f].nombredetouractif3==0){
                            Miseàjourcompétence(équipe1, f, 3);//mise à jour des effets sur le combattant    
                        }
                    }
                }
                choix1=0;
                choix2=0;
                choixcap=0;
                system("clear");
                affichecombat(équipe2, nomEquipe2, équipe1, nomEquipe1);
 
        }while((équipe1[0].pvcourants>0 && équipe1[1].pvcourants>0 && équipe1[2].pvcourants) && (équipe2[1].pvcourants>0 && équipe2[2].pvcourants>0 && équipe2[2].pvcourants>0) );//condition de fin de combat
        if(équipe1[0].pvcourants<=0 && équipe1[1].pvcourants<=0 && équipe1[2].pvcourants<=0){
            printf("L'équipe %s composé de %s %s %s a gagné !\n", nomEquipe2, équipe2[0].nom, équipe2[1].nom, équipe2[2].nom);
        }
        else{
            printf("L'équipe %s composé de %s %s %s a gagné !\n", nomEquipe1, équipe1[0].nom, équipe1[1].nom, équipe1[2].nom);
        }       
    }
    
return 0;
}


