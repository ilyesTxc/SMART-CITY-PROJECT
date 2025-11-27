#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"



int main() {
    int choix;
    do {
        printf("\n===== MENU PRINCIPAL - CITE INTELLIGENTE =====\n");
        printf("1. Gestion des batiments\n");
        printf("2. Gestion des equipements electriques\n");
        printf("3. Utilisation des equipements electriques\n");
        printf("4. Statistiques\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix:");
        scanf("%d", &choix);
        switch (choix) {
            case 1: gestionBatiments(); break;
            case 2: gestionEquipements(); break;
            case 3: utilisationEquipements(); break;
            case 4:statistiquesMenu(); break;
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
        printf("1. Ajouter un batiment\n");
        printf("2. Modifier un batiment\n");
        printf("3. Supprimer un batiment\n");
        printf("4. Afficher la liste des batiments\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouterBatiment(); break;
            case 2: modifierBatiment(); break;
            case 3: supprimerBatiment(); break;
            case 4: afficherBatiments(); break;
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
        printf("1. Ajouter un equipement\n");
        printf("2. Modifier un equipement\n");
        printf("3. Supprimer un equipement\n");
        printf("4. Afficher tous les equipements\n");
        printf("5. Afficher les equipements par batiment\n");
        printf("6. Afficher les equipements par type\n");
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
            default: printf("Choix invalide. Veuillez reessayer.\n"); break;
        }
    } while (choix != 0);
}

/* Menu d'utilisation des équipements */
void utilisationEquipements() {
    int choix;
    do {
        printf("\n=== UTILISATION DES EQUIPEMENTS ELECTRIQUES ===\n");
        printf("1. Allumer un equipement\n");
        printf("2. Eteindre un équipement\n");
        printf("3. Afficher L'etat des equipements\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: allumerEquipement(); break;
            case 2: eteindreEquipement(); break;
            case 3: afficherEtatEquipements(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez reessayer.\n"); break;
        }
    } while (choix != 0);
}
void statistiquesMenu() {
    int choix;
    do {
        printf("\n=== STATISTIQUES ===\n");
        printf("1. Statistiques par equipement\n");
        printf("2. Statistiques par batiment\n");
        printf("3. Statistiques par type d'equipement\n");
        printf("4. Statistiques sur intervalle de temps\n");
        printf("5. Trier les consommations\n");
        printf("6. Recherche par nom (equipement, batiment ou type)\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: statistiquesParEquipement(); break;
            case 2: statistiquesParBatiment(); break;
            case 3: statistiquesParType(); break;
            case 4: statistiquesIntervalleTemps(); break;
            case 5: trierConsommations(); break;
            case 6: rechercheParNom(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez reessayer.\n"); break;
        }
    } while (choix != 0);





}
