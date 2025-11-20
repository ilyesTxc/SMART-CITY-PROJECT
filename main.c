#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"






/* Menu de gestion des bâtiments */
void gestionBatiments() {
    int choix;
    do {
        printf("\n=== GESTION DES BÂTIMENTS ===\n");
        printf("1. Ajouter un bâtiment\n");
        printf("2. Modifier un bâtiment\n");
        printf("3. Supprimer un bâtiment\n");
        printf("4. Afficher la liste des bâtiments\n");
        printf("5. Recherche d'un batiment selon l'id\n");
        printf("6.Recherche d'un batiment selon le nom");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: saisie_tab_batiment(); break;
            case 2: modifier_tab_batiment(); break;
            case 3: supprimer_batiment(); break;
            case 4: affiche_tab_batiment(); break;
            case 5: recherche_id_batiment(); break;
            case 6: recherche_nom_batiment();break;
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
        printf("5. Recherche des equipements selon l'id \n");
        printf("6. Recherche des equipements selon le nom\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: saisie_tab_equipement(); break;
            case 2: modifier_tab_equipement(); break;
            case 3: supprimer_equipement(); break;
            case 4: affiche_tab_equipement(); break;
            case 5: recherche_id_equipement(); break;
            case 6: recherche_nom_equipemnt(); break;
            case 0: break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
}
int utilisationEquipements(){
   Consommation consoList[MAX_CONSO];
    int nbConso = 0;

    int choix;
    int idEquipement;
    time_t debut;
    float tauxConsommation;

    do {
        printf("\n=== GESTION DES CONSOMMATIONS ===\n");
        printf("1. Allumer un équipement\n");
        printf("2. Eteindre un équipement\n");
        printf("3. Afficher les consommations\n");
        printf("4. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("ID de l'equipement: ");
                scanf("%d", &idEquipement);
                printf("Taux de consommation (kWh/h): ");
                scanf("%f", &tauxConsommation);
                allumerEquipement(idEquipement, &debut);
                break;

            case 2:
                printf("ID de l'equipement: ");
                scanf("%d", &idEquipement);
                eteindreEquipement(idEquipement, debut, consoList, &nbConso, tauxConsommation);
                break;

            case 3:
                afficherConsommations(consoList, nbConso);
                break;

            case 4:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide!\n");
        }
    } while (choix != 4);

    return 0;
}
int main() {
    int choix;
    do {
        printf("\n===== MENU PRINCIPAL - CITE INTELLIGENTE =====\n");
        printf("1. Gestion des batiments\n");
        printf("2. Gestion des equipements electriques\n");
        printf("3. Utilisation des equipements electriques\n");
        printf("4. Statistiques\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: gestionBatiments(); break;
            case 2: gestionEquipements(); break;
            case 3: utilisationEquipements(); break;
            case 4: printf("les statistiques sera disponible bintot"); break;
            case 0: printf("Sortie de l'application...\n"); break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
    return 0;
}
