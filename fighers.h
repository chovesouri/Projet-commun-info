#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

typedef enum { 
    // Enumération des types de combatants
    guerrier, 
    mage, 
    voleur, 
    archer, 
    paladin, 
    druide, 
    assassin, 
    nain, 
    elfe, 
    orc, 
    troll, 
    demon, 
    ange, 
} typeCombatant;





typedef struct {
    int pvmax;
    int pvcourants;
    int attaque;
    int defense;
    int vitesse;     
    int esquive;

} combatant;
