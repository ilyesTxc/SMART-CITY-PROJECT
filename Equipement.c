#include "equipement.h"
#include "utils.h"

Equipement equipements[MAX_EQUIPEMENTS];
int nbEquipements = 0;

// ajout d'un équipement

void ajouterEquipement() {
    if (nbEquipements >= MAX_EQUIPEMENTS) {
        printf("Nombre maximum d'équipements atteint.\n");
        return;
    }
    Equipement e;
    e.id = (nbEquipements == 0) ? 1 : equipements[nbEquipements - 1].id + 1;
    printf("Nom de l'équipement: ");
    scanf(" %[^\n]s", e.nom);
    printf("Consommation par minute: ");
    scanf("%f", &e.conso_min);
    printf("ID du bâtiment associé: ");
    scanf("%d", &e.idBatiment);
    printf("ID du type d'équipement: ");
    scanf("%d", &e.idType);
    e.etat = 0;
    e.debut_utilisation = 0;

    equipements[nbEquipements++] = e;
    printf("Équipement ajouté avec succès ! ID: %d\n", e.id);

}

// modification d'un équipement

void modifierEquipement() {
    int id;
    printf("ID de l'équipement à modifier: ");
    scanf("%d", &id);
    for (int i = 0; i < nbEquipements; i++) {
        if (equipements[i].id == id) {
            printf("Nom actuel: %s\nNouveau nom: ", equipements[i].nom);
            scanf(" %[^\n]s", equipements[i].nom);
            printf("Consommation actuelle: %.2f\nNouvelle consommation: ", equipements[i].conso_min);
            scanf("%f", &equipements[i].conso_min);
            printf("Bâtiment actuel ID: %d\nNouveau bâtiment ID: ", equipements[i].idBatiment);
            scanf("%d", &equipements[i].idBatiment);
            printf("Type actuel ID: %d\nNouveau type ID: ", equipements[i].idType);
            scanf("%d", &equipements[i].idType);
            printf("Équipement modifié avec succès.\n");
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

// suppression d'un équipement

void supprimerEquipement() {
    int id;
    printf("ID de l'équipement à supprimer: ");
    scanf("%d", &id);
    for (int i = 0; i < nbEquipements; i++) {
        if (equipements[i].id == id) {
            for (int j = i; j < nbEquipements - 1; j++)
                equipements[j] = equipements[j + 1];
            nbEquipements--;
            printf("Équipement supprimé avec succès.\n");
            sauvegarderEquipementsDansFichier();
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

// affichage de tous les équipements

void afficherEquipementsParBatiment() {
    int idB;
    printf("ID du bâtiment: ");
    scanf("%d", &idB);
    printf("\n=== Équipements du bâtiment %d ===\n", idB);
    for (int i = 0; i < nbEquipements; i++) {
        if (equipements[i].idBatiment == idB)
            printf("ID: %d | Nom: %s | Etat: %s\n", equipements[i].id, equipements[i].nom,
                   equipements[i].etat ? "Allumé" : "Éteint");
    }
}

// affichage des équipements par type

void afficherEquipementsParType() {
    int idT;
    printf("ID du type: ");
    scanf("%d", &idT);
    printf("\n=== Équipements du type %d ===\n", idT);
    for (int i = 0; i < nbEquipements; i++) {
        if (equipements[i].idType == idT)
            printf("ID: %d | Nom: %s | Etat: %s\n", equipements[i].id, equipements[i].nom,
                   equipements[i].etat ? "Allumé" : "Éteint");
    }
}

// affichage des équipements par batiment

void afficherEquipementsParBatiment() {
    int idB;
    printf("ID du bâtiment: ");
    scanf("%d", &idB);
    printf("\n=== Équipements du bâtiment %d ===\n", idB);
    for (int i = 0; i < nbEquipements; i++) {
        if (equipements[i].idBatiment == idB)
            printf("ID: %d | Nom: %s | Etat: %s\n", equipements[i].id, equipements[i].nom,
                   equipements[i].etat ? "Allumé" : "Éteint");
    }
}