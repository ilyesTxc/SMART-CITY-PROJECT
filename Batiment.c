#include "batiment.h"
#include "equipement.h"
#include "utils.h"

Batiment batiments[MAX_BATIMENTS];
int nbBatiments = 0;



// ajout d'un bâtiment

void ajouterBatiment() {
    if (nbBatiments >= MAX_BATIMENTS) {
        printf("Nombre maximum de bâtiments atteint.\n");
        return;
    }

    Batiment b;
    b.id_batiment = (nbBatiments == 0) ? 1 : batiments[nbBatiments - 1].id_batiment + 1;
    printf("Entrez le nom du bâtiment: ");
    scanf(" %[^\n]s", b.nom_batiment);
    printf("Entrez l'adresse du bâtiment: ");
    scanf(" %[^\n]s", b.adresse);
    b.nb_equipements = 0;

    batiments[nbBatiments++] = b;
    printf("Bâtiment ajouté avec succès ! ID: %d\n", b.id_batiment);

}


// modification d'un bâtiment

void modifierBatiment() {
    int id;
    printf("Entrez l'ID du bâtiment à modifier: ");
    scanf("%d", &id);
    for (int i = 0; i < nbBatiments; i++) {
        if (batiments[i].id_batiment == id) {
            printf("Nom actuel: %s\n", batiments[i].nom_batiment);
            printf("Nouveau nom: ");
            scanf(" %[^\n]s", batiments[i].nom_batiment);
            printf("Adresse actuelle: %s\n", batiments[i].adresse);
            printf("Nouvelle adresse: ");
            scanf(" %[^\n]s", batiments[i].adresse);
            printf("Bâtiment modifié avec succès.\n");

            return;
        }
    }
    printf("Bâtiment introuvable.\n");
}


// suppression d'un bâtiment

void supprimerBatiment() {
    int id;
    printf("Entrez l'ID du bâtiment à supprimer: ");
    scanf("%d", &id);
    for (int i = 0; i < nbBatiments; i++) {
        if (batiments[i].id_batiment == id) {
            for (int j = i; j < nbBatiments - 1; j++) {
                batiments[j] = batiments[j + 1];
            }
            nbBatiments--;
            printf("Bâtiment supprimé avec succès.\n");
            return;
        }
    }
    printf("Bâtiment introuvable.\n");
}

// affichage des bâtiments

void afficherBatiments() {
    printf("\n=== Liste des bâtiments ===\n");
    for (int i = 0; i < nbBatiments; i++) {
        printf("ID: %d | Nom: %s | Adresse: %s | Nb équipements: %d\n",
               batiments[i].id_batiment, batiments[i].nom_batiment, batiments[i].adresse, batiments[i].nb_equipements);
    }
}

// gestion des équipements d'un bâtiment

void gererEquipementsBatiment() {
    printf("Gestion des équipements d'un bâtiment (fonction à compléter)...\n");
}

// Recherche d'un bâtiment par son ID : retourne l'indice dans le tableau ou -1 si non trouvé
int rechercheBatimentParId(int id) {
    for (int i = 0; i < nbBatiments; i++) {
        if (batiments[i].id_batiment == id) {
            return i;
        }
    }
    return -1;
}

