#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"

/* Prototypes des fonctions de menu */
void gestionBatiments();
void gestionEquipements();
void utilisationEquipements();
void statistiquesMenu();
void Consommations();
void MenuDeTrie();
void statistiquesIntervalleTemps();

int main() {
    int choix;
    do {
        printf("\n===== MENU PRINCIPAL - CITÉ INTELLIGENTE =====\n");
        printf("1. Gestion des bâtiments\n");
        printf("2. Gestion des équipements électriques\n");
        printf("3. Utilisation des équipements électriques\n");
        printf("4. Statistiques sur intervalle de temps\n");
        printf("5. Statistiques des consommations Triée : decroissante ou croissante\n");
        printf("6. Consommations\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix:");
        scanf("%d", &choix);
        switch (choix) {
            case 1: gestionBatiments(); break;
            case 2: gestionEquipements(); break;
            case 3: utilisationEquipements(); break;
            case 4: statistiquesIntervalleTemps(); break;
            case 5: MenuDeTrie(); break;
            case 6: Consommations(); break;
            case 0: printf("Sortie de l'application...\n"); break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
    return 0;
}

/* Menu de gestion des bâtiments */
void gestionBatiments() {
    int choix;
    do {
        printf("\n=== GESTION DES BÂTIMENTS ===\n");
        printf("1. Ajouter un bâtiment\n");
        printf("2. Modifier un bâtiment\n");
        printf("3. Supprimer un bâtiment\n");
        printf("4. Afficher la liste des bâtiments\n");
        printf("5. Gérer les équipements d'un bâtiment\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterBatiment(); break;
            case 2: modifierBatiment(); break;
            case 3: supprimerBatiment(); break;
            case 4: afficherBatiments(); break;
            case 5: gererEquipementsBatiment(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
}

/* Menu de gestion des équipements */
void gestionEquipements() {
    int choix;
    do {
        printf("\n=== GESTION DES ÉQUIPEMENTS ÉLECTRIQUES ===\n");
        printf("1. Ajouter un équipement\n");
        printf("2. Modifier un équipement\n");
        printf("3. Supprimer un équipement\n");
        printf("4. Afficher tous les équipements\n");
        printf("5. Afficher les équipements par bâtiment\n");
        printf("6. Afficher les équipements par type\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterEquipement(); break;
            case 2: modifierEquipement(); break;
            case 3: supprimerEquipement(); break;
            case 4: afficherEquipements(); break;
            case 5: afficherEquipementsParBatiment(); break;
            case 6: afficherEquipementsParType(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
}

/* Menu d'utilisation des équipements */
void utilisationEquipements() {
    int choix;
    do {
        printf("\n=== UTILISATION DES ÉQUIPEMENTS ÉLECTRIQUES ===\n");
        printf("1. Allumer un équipement\n");
        printf("2. Éteindre un équipement\n");
        printf("3. Afficher L'etat des equipements\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: allumerEquipement(); break;
            case 2: eteindreEquipement(); break;
            case 3: afficherEtatEquipements(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
}

void Consommations(){
    int choix;
    do{
        printf("\n=== CONSOMMATIONS ===\n");
        printf("1. Ajouter une consommation\n");
        printf("2. Afficher une consommation\n");
        printf("3. Retour au menu principal\n");
        scanf("%d",&choix);
        switch(choix){
            case 1: ajouterConsommation(); break;
            case 2: afficherConsommations(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while(choix != 0);
}





