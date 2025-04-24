#include "fighters.h"
    

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
    fscanf(fichier, "%d\n", &c.vitesse);
    c.vitessecourante=0;          // vitesse
    fscanf(fichier, "%f\n", &c.esquive);          // esquive

    c.degaspe1 = 0;
    c.degaspe2 = 0;
    c.degaspe3 = 0;

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
        printf("Défense: %f\n", liste[i].defense);
        printf("Compétence spéciale: %s\n", liste[i].competspe.nomspe);
        printf("Description: %s %s", liste[i].competspe.description1,liste[i].competspe.description2);
        printf("Vitesse: %d\n", liste[i].vitesse);
        printf("Esquive: %f\n", liste[i].esquive);
        printf("----------------------------------------\n");
        printf("\n");
    }
}
    
Combattant* miseaJourCombattants(Combattant liste[],int choixcombattant){
    for(choixcombattant; choixcombattant< 11; choixcombattant++){
        liste[choixcombattant] = liste[choixcombattant+1];  
    }
return liste;
}

int longueur_int(int n) {
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

void allignement(int longueur){//fonction permettant d'alligner les colonnes
    for(int i = 0; i <50-longueur; i++){
        printf(" ");
    }
    printf("|");
}
   
void affichevitesse(int vitesse){
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
    int l = 0;// variable servant à l'allignementde des |
    int o=0;
    for(int t=0; t<(53*3+4); t++){
        printf("_");   
    }
    printf("\n");
    printf("|");
    printf("%s", nomequipe);// affichage du nom de l'équipe
    l=strlen(nomequipe);
    for(int y=0; y<161-l; y++){
        printf(" ");
    }
    printf("|");
    printf("\n");
    printf("|");
    for(int i = 0; i < 3; i++) {//affichage des noms des combattants
        printf("   %s:", equipe[i].nom);
        l=0;
        o=0;
         while (equipe[i].nom[o] != NULL) {
        l+= strlen(equipe[i].nom[o]);
        o++;
    }
        allignement(l+1);    
    }
    printf("\n");
    printf("|");
    for(int e=0; e<3; e++){
        affichevitesse(equipe[e].vitessecourante);//affichage de la barre de vitesse
        l=12;
        allignement(l);    
    }
    printf("\n");
    printf("|");
    for(int r=0; r<3; r++){
        l=-3;
        allignement(l);    
    }
    printf("\n");
    printf("|");
    for(int a=0; a<3; a++){// affichage des pv 
        printf("   pv:%d",equipe[a].pvcourants);
        l=longueur_int(equipe[a].pvcourants);
        allignement(l+3);    
    }
    printf("\n");
    printf("|");    
    for(int z=0; z<3; z++){// affichage des attaques
        
        printf("   %s:%d", equipe[z].nomatq, equipe[z].attaque);
        l=0;
        o=0;
        while (equipe[z].nomatq != NULL) {
        l+= strlen(equipe[z].nomatq[o]);
        o++;
        }
        
        l+=longueur_int(equipe[z].attaque);
        allignement(l+1);   
    }
    printf("\n");
    printf("|");
    for(int b=0; b<3; b++){// affichage des défenses
        printf("   défense:%d", equipe[b].defense);
        l=longueur_int(equipe[b].defense);
        allignement(l+8);    
    }
    printf("\n");
    printf("|");
    for(int c=0; c<3; c++){// affichage des compétences spéciales
        printf("   spé:%s", equipe[c].competspe.nomspe);
        
        l=0;
        o=0;
         while (equipe[c].competspe.nomspe[o] != NULL) {
        l+=strlen(equipe[c].competspe.nomspe[o]);
        o++;
    }
        allignement(l+4);     
    }
    printf("\n");   
    printf("|");
    for(int d=0; d<3; d++){// affichage des descriptions
        printf("   %s", equipe[d].competspe.description1);
        l=0;
        o=0;
         while (equipe[d].competspe.description1[o] != NULL) {
        l+= strlen(equipe[d].competspe.description1[o]);
        o++;
        }
        allignement(l);   
    }
    printf("\n");   
    printf("|");   
    for(int f=0; f<3; f++){
        printf("   %s", equipe[f].competspe.description2);
        l=0;
        o=0;
         while (equipe[d].competspe.description2[o] != NULL) {
        l+= strlen(equipe[d].competspe.description2[o]);
        o++;
        }
        allignement(l);   
    }
    printf("\n");
    printf("|");
    for(int g=0; g<3; g++){
        printf("   esquive:%d  ", equipe[g].esquive);
        l=longueur_int(equipe[g].esquive);
        allignement(l+8);   
    }
    printf("\n");
}    
    
    
void affichecombat(Combattant* equipe1,char* nomEquipe1, Combattant* equipe2,char* nomEquipe2){//affichage du combat
    affichejoueur(equipe1, nomEquipe1);
    affichejoueur(equipe2, nomEquipe2);
    for(int t=0; t<(53*3+4); t++){
        printf("_");   
    }
}

Combattant Convecompspé(FILE* fichier){
    fscanf(fichier, "%f\n", &c.competspe.valeur); // valeur
    fscanf(fichier, "%29[^\n]\n", c.competspe.nomspe); // nom de la compétence spéciale
    fscanf(fichier, "%59[^\n]\n", c.competspe.description1); // description 1
    fscanf(fichier, "%59[^\n]\n", c.competspe.description2); // description 2
    fscanf(fichier, "%d\n", &c.competspe.nombretouractif); // nombre de tours actif
    fscanf(fichier, "%d\n", &c.competspe.typecompétence); // type de compétence
    fscanf(fichier, "%d\n", &c.competspe.nombredepersonnetouchées); // nombre de personnes touchées
    return c.competspe;
}


int Utilisationcompétence(Combattant* attaquant, Combattant* défenseur, int choixcombattant, ){
    int choix=0;
    if(attaquant[choixcombattant].competspe.typecompétence==5){
        printf("Vous avez pris le contrôle de l'équipe ennemie\n");
        do{
            printf("Choisissez un combattant de l'équipe ennemie à contrôler\n");
            scanf("%d", &choix);
        }while(choix<1 || choix>3);

}

}
















