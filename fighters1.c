#include "fighters1.h"
    

Combattant ConveCombattant(FILE* fichier,FILE* fichier2){//fonction permettant le transfert des stats des combattants
    Combattant c;
    // Lecture directe avec fscanf
    fscanf(fichier, "%19[^\n]\n", c.nom);         // nom
    fscanf(fichier, "%d\n", &c.pvmax);            // pvmax
    c.pvcourants = c.pvmax;                       // init à pvmax
    fscanf(fichier, "%39[^\n]\n", c.nomatq);      // nomatq
    fscanf(fichier, "%d\n", &c.attaque);          // attaque
    fscanf(fichier, "%f\n", &c.defense);          // defense
    fscanf(fichier, "%d\n", &c.vitesse);
    c.vitessecourante=0;          // vitesse
    fscanf(fichier, "%f\n", &c.esquive);          // esquive
    fscanf(fichier2, "%f\n", &c.competspe.valeur); 
    fscanf(fichier2, "%29[^\n]\n", c.competspe.nomspe); 
    fscanf(fichier2, "%59[^\n]\n", c.competspe.description1); 
    fscanf(fichier2, "%59[^\n]\n", c.competspe.description2); 
    fscanf(fichier2, "%d\n", &c.competspe.nombretouractif); 
    fscanf(fichier2, "%d\n", &c.competspe.typecompétence);

    c.typespe1 = 0;
    c.nombredetouractif1 = 0;
    c.typespe2 = 0;
    c.nombredetouractif2 = 0;
    c.typespe3 = 0;
    c.nombredetouractif3 = 0;

    ;
    return c;
}


void afficherCombattantsDisponibles(Combattant liste[], int taille) {// Affiche les combattants disponibles avec toutes leurs caractéristiques
    printf("==== COMBATTANTS DISPONIBLES ====\n");
    printf("\n\n");
    for (int i = 0; i < taille; i++) {
        printf("(%d) Nom : %s\n", i+1, liste[i].nom);
        printf("PV max: %d\n", liste[i].pvmax);
        printf("Attaque: %s: (%d)\n", liste[i].nomatq, liste[i].attaque);
        printf("Défense: réducions de %.0f%\n", (1-liste[i].defense)*100);
        printf("Compétence spéciale: %s\n", liste[i].competspe.nomspe);
        printf("Description: %s %s\n", liste[i].competspe.description1,liste[i].competspe.description2);
        printf("Vitesse: %d\n", liste[i].vitesse);
        printf("Esquive: %.2f \n", liste[i].esquive);
        printf("----------------------------------------\n");
        printf("\n");
    }
}
    
Combattant* miseàJourCombattants(Combattant liste[],int choixcombattant){ //fonction mettant à jour la liste des combattants disponibles
    for(choixcombattant; choixcombattant< 11; choixcombattant++){
        liste[choixcombattant] = liste[choixcombattant+1];  
    }
return liste;
}

int longueur_int(int n){//fonction permettant de compter le nombre de chiffre de l'entier rentrer en paramètre
    if (n == 0) return 1; // cas particulier
    int longueur = 0;
    if (n < 0){
    n = -n;// valeur absolue
    }
    while (n > 0) {
        n /= 10;
        longueur++;
    }
    return longueur;
}

void alignement(int longueur){//fonction permettant d'aligner les colonnes lors de l'affichage

    for(int i = 0; i <60-longueur; i++){
        printf(" ");
    }
    printf("|");
}
   
void affichevitesse(int vitesse){ // affiche la vitesse de façon styliser
    int a=vitesse/10;
    printf("   (");
    for(int i=0; i<a; i++){
        printf(">");
    }
    for(int b = 0; b <10-a; b++){
        printf(" ");
    }    
    printf(")");
}







void affichejoueur(Combattant* equipe,char* nomequipe) {// Affiche l'équipe d'un joueur
    int l=0;// variable servant à l'alignementde des |
    for(int t=0; t<(63*3+4); t++){
        printf("_");   
    }
    printf("\n");
    printf("|");
    printf("%s", nomequipe);// affichage du nom de l'équipe
    l=strlen(nomequipe);
    for(int y=0; y<191-l; y++){
        printf(" ");
    }
    printf("|");
    printf("\n");
    printf("|");
    for(int i = 0; i < 3; i++) {//affichage des noms des combattants
        printf("   %d)%s:",i+1,equipe[i].nom);       	
        l= strlen(equipe[i].nom);
        alignement(l+3);   
    }
    printf("\n");
    printf("|");
    for(int e=0; e<3; e++){
        affichevitesse(equipe[e].vitessecourante);//affichage de la barre de vitesse
        l=12;
        alignement(l);    
    }
    printf("\n");
    printf("|");
    for(int r=0; r<3; r++){
        l=-3;
        alignement(l);    
    }
    printf("\n");
    printf("|");
    for(int a=0; a<3; a++){// affichage des pv 
        printf("   pv:%d",equipe[a].pvcourants);
        l=longueur_int(equipe[a].pvcourants);
        alignement(l+3);    
    }
    printf("\n");
    printf("|");    
    for(int z=0; z<3; z++){// affichage des attaques
        
        printf("   %s:%d", equipe[z].nomatq, equipe[z].attaque);
        l= strlen(equipe[z].nomatq);
        l+=longueur_int(equipe[z].attaque);
        alignement(l+1);   
    }
    printf("\n");
    printf("|");
    for(int b=0; b<3; b++){// affichage des défenses
        printf("   défense:%.2f", equipe[b].defense);    
        alignement(12);    
    }
    printf("\n");
    printf("|");
    for(int c=0; c<3; c++){// affichage des compétences spéciales
        printf("   spé:%s", equipe[c].competspe.nomspe);
        l=strlen(equipe[c].competspe.nomspe);
        alignement(l+4);     
    }
    printf("\n");   
    printf("|");
    for(int d=0; d<3; d++){// affichage des descriptions
        printf("   %s", equipe[d].competspe.description1);
        
        l= strlen(equipe[d].competspe.description1);
        alignement(l);   
    }
    printf("\n");   
    printf("|");   
    for(int f=0; f<3; f++){
        printf("   %s", equipe[f].competspe.description2);
        l=strlen(equipe[f].competspe.description2);
        alignement(l);   
    }
    printf("\n");
    printf("|");
    for(int g=0; g<3; g++){
        printf("   esquive:%.2f", equipe[g].esquive);
        alignement(12);   
    }
    printf("\n");
}    
    
    
void affichecombat(Combattant* equipe1,char* nomEquipe1, Combattant* equipe2,char* nomEquipe2){//affichage du combat
    affichejoueur(equipe1, nomEquipe1);
    affichejoueur(equipe2, nomEquipe2);
    for(int t=0; t<(63*3+4); t++){
        printf("_");       
    }
    printf("\n\n");
}

void Utilisationcompétence(Combattant* attaquant,char* noméquipeat,Combattant* attaquanttémoin, Combattant* défenseur,char* noméquipedéf, Combattant* défenseurtémoin, int choixcombattant,int vérificationbot, int* passe){ //utilisation des compétences
    int choix = 0;
    int choix2=0;
    int choixcap=0;
    float esquive=0;
    int minpv=0;
    int validiter;
    switch (attaquant[choixcombattant].competspe.typecompétence){// switch case permettant de savoir quelle compétence spéciale doit être utilisé
        case 1:
            if(vérificationbot==0){   
                do{
                    printf("Choisissez le combattant qui doit lire la thèse de Mr Arancini\n");
                    validiter=scanf("%d", &choix);
                    vérifscanf(validiter);
                    choix--;
                }while(choix < 0 || choix > 2 || défenseur[choix].pvcourants<=0 || validiter!=1);
                défenseur[choix].vitessecourante = 0;
                printf("Le combattant %s voit son compteur de compétence remis à 0\n", défenseur[choix].nom);
            }
            else{
                for(int n=0; n<2; n++){
                    if(défenseur[choix].pvcourants && défenseur[n+1].pvcourants && défenseur[choix].vitessecourante<défenseur[n+1].vitessecourante){
                            choix=n;                    
                    }
                }
                printf("Le bot bien programmé réinitialise le conteur de %s qui était l'ennemie le plus proche d'utiliser sa compétence\n", défenseur[choix].nom);
                défenseur[choix].vitessecourante = 0;
            }       
        break;                   
        case 2:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for (int i = 0; i < 3; i++) {
                if(attaquant[i].pvcourants > 0){
                    attaquant[i].defense*=attaquant[choixcombattant].competspe.valeur;
                    if(attaquant[i].typespe1==0){
                        attaquant[i].nombredetouractif1=2;
                        attaquant[i].typespe1=2;
                    }else if(attaquant[i].typespe2==0){
                        attaquant[i].nombredetouractif2=2;
                        attaquant[i].typespe2=2;
                    }else{
                        attaquant[i].nombredetouractif3=2;
                        attaquant[i].typespe3=2;
                    }    
                }
            }
            break;           
        case 3:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for (int a = 0; a < 3; a++) {
                if (défenseur[a].pvcourants > 0) {
                    défenseur[a].vitesse-=attaquant[choixcombattant].competspe.valeur;
                    if(attaquant[a].typespe1==0){
                        attaquant[a].nombredetouractif1=2;
                        attaquant[a].typespe1=3;
                    }else if(attaquant[a].typespe2==0){
                        attaquant[a].nombredetouractif2=2;
                        attaquant[a].typespe2=3;
                    }else{
                        attaquant[a].nombredetouractif3=2;
                        attaquant[a].typespe3=3;
                    }
                }
            }
            break;
        case 4:
            if(vérificationbot==0){
                do{
                    printf("Choisissez le combattant adverse dont vous souhaitez écraser le pied et faire des dégats bruts\n");
                    validiter=scanf("%d", &choix);
                    vérifscanf(validiter);
                    choix--;
                }while (choix < 0 || choix > 2 || défenseur[choix].pvcourants<=0 || validiter!=1);
                défenseur[choix].pvcourants-=attaquant[choixcombattant].competspe.valeur;
                printf("Le pied de %s a bien été écrasé\n", défenseur[choix].nom);
            }else{
                for(int n=1; n<3; n++){
                    if(défenseur[choix].pvcourants>défenseur[n].pvcourants){
                        choix=n;
                    }
                }
                printf("Le bot a choisi d'écraser le pied de %s car il est le combattant avec le moins de pv\n", défenseur[choix].nom);
                défenseur[choix].pvcourants-=attaquant[choixcombattant].competspe.valeur;
            }
            break;

        case 5:
            if(vérificationbot==0){
                do{
                    printf("Bien joué, vous avez réussi à vous introduire dans l'equipe adversaire à cause d'une faille de sécurité\n");
                    printf("Choisissez le combattant adverse dont vous souhaitez prendre le contrôle\n");
                    validiter=scanf("%d", &choix);
                    vérifscanf(validiter);
                    choix--;
                }while (choix < 0 || choix > 2 || défenseur[choix].pvcourants<=0 || validiter!=1);               
                if(défenseur[choix].vitessecourante!=100){
                    do{
                        do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                            printf("La capacité du joueur adverse n'est pas disponible choisissez un combattant à attaquer avec une attaque normale\n");
                            validiter=scanf("%d", &choix2);
                            vérifscanf(validiter);
                        }while(choix2<1 || choix2>3 || validiter!=1);
                        choix2--;
                        if(défenseur[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                       };
                    }while(défenseur[choix2].pvcourants<=0);
                    esquive=(rand()%100+1)/100;
                    if(esquive<défenseur[choix2].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        printf("L'attaque a été réussie\n");
                        défenseur[choix2].pvcourants-=défenseur[choix].attaque*défenseur[choix2].defense;
                    }
                }
                else{
                    do{//choix du type d'attaque
                        printf("Votre capacité spéciale est disponible, tapez 1 pour attaquer normalement ou 2 pour utiliser la capacité spéciale\n");
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
                            if(défenseur[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(défenseur[choix2].pvcourants<=0);
                        esquive=(rand()%100+1)/100;
                        if(esquive<défenseur[choix2].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{
                            défenseur[choix2].pvcourants-=défenseur[choix].attaque*défenseur[choix2].defense;
                            printf("L'attaque a été réussie\n");
                        }
                    }
                    else{
                        Utilisationcompétence(défenseur,noméquipedéf,défenseurtémoin, défenseur,noméquipedéf, défenseurtémoin, choix,0, passe);//utilisation de la capacité spéciale    
                    }
                }
            }else{
                if(défenseur[0].vitessecourante<100 && défenseur[1].vitessecourante<100 && défenseur[2].vitessecourante<100){
                    do{
                        choix=rand()%3;
                    }while(choix<0 || choix>2|| défenseur[choix].pvcourants<=0);
                    printf("Le bot a choisi d'attaquer avec %s mais n'a pas sa capacité spéciale spéciale",défenseur[choix].nom );
                    for(int n=1; n<3; n++){
                        if(défenseur[minpv].pvcourants>défenseur[n].pvcourants){
                            minpv=n;
                        }
                    }
                    printf("Le bot a choisi d'attaquer %s car il est le combattant avec le moins de pv\n", défenseur[minpv].nom);
                    esquive=(rand()%100+1)/100;
                    if(esquive<défenseur[minpv].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        printf("L'attaque a été réussie\n");
                        défenseur[minpv].pvcourants-=défenseur[choix].attaque*défenseur[minpv].defense;
                    }
                }
                else{
                    do{
                        choix=rand()%3;
                    }while(choix<0 || choix>2|| défenseur[choix].pvcourants<=0 || défenseur[choix].vitessecourante<=100);
                    printf("Le bot a choisi d'utiliser la capacité de %s",défenseur[choix].nom );
                    défenseur[choix].vitessecourante=0;
                    Utilisationcompétence(défenseur,noméquipedéf, défenseurtémoin, défenseur,noméquipedéf, défenseurtémoin, choix,1, passe);
                }
            }
            break;

        case 6:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for (int i = 0; i < 3; i++) {
                if(défenseur[i].pvcourants<=0){
                    défenseur[i].pvcourants-=attaquant[choixcombattant].competspe.valeur;
                }
            }
            break;
        case 7:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            *passe=1;
            printf("Le maître du jeux trouve cette attaque trop claqué et décide donc de vous laisser choisir un adversaire a qui vous mettrez 150 dégats bruts\n")
            do{    
                do{
                    printf("Choisissez un adversaire à attaquer\n");
                    validiter=scanf("%d", &choix2);
                    vérifscanf(validiter);
                }while(choix2<1 || choix2>3 || validiter!=1);
                choix2=choix2-1;
                if(défenseur[choix2].pvcourants==0){
                printf("Ce combattant est KO, choisissez un autre combattant\n");
                }
            }while(défenseur[choix2].pvcourants<=0);
            défenseur[choix2].pvcourants-=150;            
            break;
        case 8:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for(int i = 0; i < 3; i++) {
                if (attaquant[i].pvcourants > 0) {
                    attaquant[i].pvcourants+=attaquant[choixcombattant].competspe.valeur;                    
                }
            }
            break;
        case 9:
            if(vérificationbot==0){
                do{
                    printf("Choisissez le combattant adverse dont vous souhaitez le renvoi\n");
                    validiter=scanf("%d", &choix);
                    vérifscanf(validiter);
                    choix--;
                }while (choix < 0 || choix > 2 || défenseur[choix].pvcourants<=0 || validiter!=1);
                défenseur[choix].pvcourants*=attaquant[choixcombattant].competspe.valeur;
            }
            else{
                for(int n=1; n<3; n++){
                    if(défenseur[choix].pvcourants<défenseur[n].pvcourants){
                        choix=n;
                    }
                }
                printf("Le bot a choisi de renvoyer %s car il est le combattant avec le plus de pv\n", défenseur[choix].nom);
                défenseur[choix].pvcourants*=attaquant[choixcombattant].competspe.valeur;
            }
            break;
        case 10:
        for(int i = 0; i < 2; i++) {
            if(vérificationbot==0){
                    for(int q=0; q<3; q++){//mise à jour de la vitesse courante
                    attaquant[q].vitessecourante+=attaquant[q].vitesse;
                }
                for(int n=0; n<3; n++){
                    if(attaquant[n].vitessecourante>100){
                        attaquant[n].vitessecourante=100;
                    }
                }
                affichecombat(attaquant, noméquipeat, défenseur, noméquipedéf);
                do{//choix du combattant qui va attaquer
                    do{
                        printf("Equipe %s, choisissez le combattant qui va attaquer\n",noméquipeat);
                        validiter=scanf("%d", &choix);
                        vérifscanf(validiter);
                    }while(choix<1 || choix>3 || validiter!=1);
                    choix=choix-1;
                    if(attaquant[choix].pvcourants==0){
                        printf("Ce combattant est KO, choisissez un autre combattant\n");
                    }
                }while(attaquant[choix].pvcourants==0);
                if(attaquant[choix].vitessecourante!=100){
                    do{
                        do{//choix du combattant à attaquer si la capacité spéciale n'est pas disponible
                            printf("Votre capacité spéciale n'est pas disponible choisissez un adversaire à attaquer\n");
                            validiter=scanf("%d", &choix2);
                            vérifscanf(validiter);
                        }while(choix2<1 || choix2>3 || validiter!=1);
                        choix2--;
                        if(défenseur[choix2].pvcourants==0){
                            printf("Ce combattant est KO, choisissez un autre combattant\n");
                        }
                    }while(défenseur[choix2].pvcourants<=0);                    
                    esquive=(rand()%100+1)/100;
                    if(esquive<défenseur[choix2].esquive){
                        printf("L'attaque a été esquivée\n");   
                    }else{
                        printf("L'attaque a été réussie\n");
                        défenseur[choix2].pvcourants-=attaquant[choix].attaque*attaquant[choix2].defense;
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
                            if(défenseur[choix2].pvcourants==0){
                                printf("Ce combattant est KO, choisissez un autre combattant\n");
                            }
                        }while(défenseur[choix2].pvcourants<=0);
                        esquive=(rand()%100+1)/100;
                        if(esquive<défenseur[choix2].esquive){
                            printf("L'attaque a été esquivée\n");
                        }else{
                            printf("L'attaque a été réussie\n");
                            défenseur[choix2].pvcourants-=attaquant[choix].attaque*attaquant[choix2].defense;
                        }
                    }
                    else{
                        attaquant[choix].vitessecourante=0;
                        Utilisationcompétence(attaquant,noméquipeat, attaquanttémoin, défenseur,noméquipedéf, défenseurtémoin, choix, 0, passe);//utilisation de la capacité spéciale    
                    }
                sleep(5);
                }
            
                for(int n=0; n<3; n++){
                    if(défenseur[n].pvcourants<0){
                        défenseur[n].pvcourants=0;
                    }
                }
            }
            else{
                for(int n=0; n<3; n++){//mise à jour de la vitesse courante
                    attaquant[n].vitessecourante+=attaquant[n].vitesse;
                }
                for(int n=0; n<3; n++){
                    if(attaquant[n].vitessecourante>100){
                        attaquant[n].vitessecourante=100;
                    }
                }
                if(attaquant[0].vitessecourante<100 && attaquant[1].vitessecourante<100 && attaquant[2].vitessecourante<100){
                    do{
                        choix=rand()%3;
                    }while(choix<0 || choix>2|| attaquant[choix].pvcourants<=0);
                    printf("Le bot a choisi d'attaquer avec %s mais n'a pas sa capacité spéciale spéciale",attaquant[choix].nom );
                    for(int n=1; n<3; n++){
                        if(défenseur[minpv].pvcourants>défenseur[n].pvcourants){
                            minpv=n;
                        }
                    }
                    printf("Le bot a choisi d'attaquer %s car il est le combattant avec le moins de pv\n", défenseur[minpv].nom);
                    esquive=(rand()%100+1)/100;
                    if(esquive<défenseur[minpv].esquive){
                        printf("L'attaque a été esquivée\n");
                    }else{
                        défenseur[minpv].pvcourants-=attaquant[choix].attaque*défenseur[minpv].defense;
                        printf("L'attaque a été réussie\n");
                    }    
                }
                else{
                    do{
                        choix=rand()%3;
                    }while(choix<0 || choix>2|| attaquant[choix].pvcourants<=0 || attaquant[choix].vitessecourante<100);
                    printf("Le bot a choisi d'utiliser la capacité de %s",attaquant[choix].nom );
                    attaquant[choix].vitessecourante=0;
                    Utilisationcompétence(attaquant,noméquipeat, attaquanttémoin, défenseur, noméquipedéf, défenseurtémoin, choix,1, passe);


                }
            }            
        }
        sleep(10);
            break;
        case 11:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for(int i = 0; i < 3; i++) {
                if (attaquant[i].pvcourants > 0) {
                    attaquant[i].attaque*=attaquant[choixcombattant].competspe.valeur;
                    if(attaquant[i].typespe1==0){
                        attaquant[i].nombredetouractif1=2;
                        attaquant[i].typespe1=11;
                    }else if(attaquant[i].typespe2==0){
                        attaquant[i].nombredetouractif2=2;
                        attaquant[i].typespe2=11;
                    }else{
                        attaquant[i].nombredetouractif3=2;
                        attaquant[i].typespe3=11;
                    }    
                    
                }
            }
        break;
        case 12:
            printf("%s %s\n", attaquant[choixcombattant].competspe.description1,attaquant[choixcombattant].competspe.description2);
            for (int i = 0; i < 3; i++) {
                if(défenseur[i].pvcourants > 0){
                    défenseur[i].attaque*=attaquant[choixcombattant].competspe.valeur;
                    if(défenseur[i].typespe1==0){
                        défenseur[i].nombredetouractif1=2;
                        défenseur[i].typespe1=12;
                    }else if(défenseur[i].typespe2==0){
                        défenseur[i].nombredetouractif2=2;
                        défenseur[i].typespe2=12;
                    }else{
                        défenseur[i].nombredetouractif3=2;
                        défenseur[i].typespe3=12;
                    }    
                }
            }
            break;  
            default:
            printf("Erreur de compétence\n");
            exit(25);
       }
}


void Miseàjourcompétence(Combattant* équipe, Combattant* équipetémoin){ //mise à jour de la compétence
    for(int i=0; i<3; i++){
        équipe[i].nombredetouractif1-=1;
        équipe[i].nombredetouractif2-=1;
        équipe[i].nombredetouractif3-=1;
        if(équipe[i].nombredetouractif1==0){
            switch (équipe[i].typespe1) {
                case 2:
                    équipe[i].defense=équipetémoin[i].defense;
                    équipe[i].typespe1=0;
                    break;
                case 3:
                    équipe[i].vitesse=équipetémoin[i].vitesse;
                    équipe[i].typespe1=0;
                    break;
                case 11:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;
                case 12:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;    
            }
        }
        if(équipe[i].nombredetouractif2==0){
            switch (équipe[i].typespe1) {
                case 2:
                    équipe[i].defense=équipetémoin[i].defense;
                    équipe[i].typespe1=0;
                    break;
                case 3:
                    équipe[i].vitesse=équipetémoin[i].vitesse;
                    équipe[i].typespe1=0;
                    break;
                case 11:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;
                case 12:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;    
            }
        }
        if(équipe[i].nombredetouractif3==0){
            switch (équipe[i].typespe1) {
                case 2:
                    équipe[i].defense=équipetémoin[i].defense;
                    équipe[i].typespe1=0;
                    break;
                case 3:
                    équipe[i].vitesse=équipetémoin[i].vitesse;
                    équipe[i].typespe1=0;
                    break;
                case 11:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;
                case 12:
                    équipe[i].attaque=équipetémoin[i].attaque;
                    équipe[i].typespe1=0;
                    break;    
            }
        }
        if(équipe[i].nombredetouractif1<0){
            équipe[i].nombredetouractif1=0;
        }
        if(équipe[i].nombredetouractif2<0){
            équipe[i].nombredetouractif2=0;
        }
        if(équipe[i].nombredetouractif3<0){
            équipe[i].nombredetouractif3=0;
        }
    }
}


void vérifscanf(int a){ // fonction serant à  vider le buffer en cas de mauvaise saisie
    if (a !=1 ) {
        while (getchar() != '\n'); 
    }
}













