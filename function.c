#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "function.h"

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
// affichage de tous les équipements
void afficherEquipements() {
    printf("\n=== Tous les équipements ===\n");
    for (int i = 0; i < nbEquipements; i++) {
        printf("ID: %d | Nom: %s | Type ID: %d | Batiment ID: %d | Etat: %s\n",
               equipements[i].id, equipements[i].nom, equipements[i].idType,
               equipements[i].idBatiment, equipements[i].etat ? "Allumé" : "Éteint");
    }
}

TypeEquipement types[MAX_TYPES];
int nbTypes = 0;

// ajout d'un type d'équipement

void ajouterTypeEquipement() {
    if (nbTypes >= MAX_TYPES) {
        printf("Nombre maximum de types atteint.\n");
        return;
    }
    TypeEquipement t;
    t.id = (nbTypes == 0) ? 1 : types[nbTypes-1].id + 1;
    printf("Nom du type: ");
    scanf(" %[^\n]s", t.nom);
    printf("Description: ");
    scanf(" %[^\n]s", t.description);

    types[nbTypes++] = t;
    printf("Type ajouté avec succès ! ID: %d\n", t.id);

}

// modification d'un type d'équipement

void modifierTypeEquipement() {
    int id;
    printf("ID du type à modifier: ");
    scanf("%d", &id);
    for(int i=0; i<nbTypes; i++){
        if(types[i].id==id){
            printf("Nom actuel: %s\nNouveau nom: ", types[i].nom);
            scanf(" %[^\n]s", types[i].nom);
            printf("Description actuelle: %s\nNouvelle description: ", types[i].description);
            scanf(" %[^\n]s", types[i].description);
            printf("Type modifié avec succès.\n");

            return;
        }
    }
    printf("Type introuvable.\n");
}

// suppresion d'un type d'équipement

void supprimerTypeEquipement() {
    int id;
    printf("ID du type à supprimer: ");
    scanf("%d", &id);
    for(int i=0; i<nbTypes; i++){
        if(types[i].id==id){
            for(int j=i;j<nbTypes-1;j++)
                types[j]=types[j+1];
            nbTypes--;
            printf("Type supprimé avec succès.\n");

            return;
        }
    }
    printf("Type introuvable.\n");
}

// affichage des types d'équipement

void afficherTypeEquipements() {
    printf("\n===Liste des types d'équipement===\n");
    for(int i=0; i<nbTypes; i++){
        printf("ID: %d | Nom: %s | Description: %s\n", types[i].id, types[i].nom, types[i].description);
    }
}

Consommation consommations[MAX_CONSOMMATIONS];
int nbConsommations = 0;

// ajouter consommation

void ajouterConsommation(int idEquip, time_t debut, time_t fin, float conso) {
    if (nbConsommations >= MAX_CONSOMMATIONS) {
        printf("Nombre maximum de consommations atteint.\n");
        return;
    }
    Consommation c;
    c.id = (nbConsommations == 0) ? 1 : consommations[nbConsommations-1].id + 1;
    c.idEquipement = idEquip;
    c.debut = debut;
    c.fin = fin;
    c.consommation = conso;
    consommations[nbConsommations++] = c;
    printf("Consommation ajoutée pour l'équipement %d: %.2f\n", idEquip, conso);
}

// afficher consommations

void afficherConsommations() {
    printf("\n=== Consommations enregistrées ===\n");
    for (int i = 0; i < nbConsommations; i++) {
        struct tm *debut_tm = localtime(&consommations[i].debut);
        struct tm *fin_tm = localtime(&consommations[i].fin);
        printf("ID: %d | Equipement ID: %d | Début: %02d/%02d/%04d %02d:%02d:%02d | Fin: %02d/%02d/%04d %02d:%02d:%02d | Consommation: %.2f\n",
               consommations[i].id, consommations[i].idEquipement,
               debut_tm->tm_mday, debut_tm->tm_mon+1, debut_tm->tm_year+1900,
               debut_tm->tm_hour, debut_tm->tm_min, debut_tm->tm_sec,
               fin_tm->tm_mday, fin_tm->tm_mon+1, fin_tm->tm_year+1900,
               fin_tm->tm_hour, fin_tm->tm_min, fin_tm->tm_sec,
               consommations[i].consommation);
    }
}

// Trier consommations croissant (Tri par sélection)

void trierConsommationsCroissant() {
    for(int i=0;i<nbConsommations-1;i++){
        for(int j=i+1;j<nbConsommations;j++){
            if(consommations[i].consommation > consommations[j].consommation){
                Consommation temp = consommations[i];
                consommations[i] = consommations[j];
                consommations[j] = temp;
            }
        }
    }
    printf("Consommations triées par ordre croissant.\n");
}

// Trier consommations décroissant (Tri par sélection)

void trierConsommationsDecroissant() {
    for(int i=0;i<nbConsommations-1;i++){
        for(int j=i+1;j<nbConsommations;j++){
            if(consommations[i].consommation < consommations[j].consommation){
                Consommation temp = consommations[i];
                consommations[i] = consommations[j];
                consommations[j] = temp;
            }
        }
    }
    printf("Consommations triées par ordre décroissant.\n");
}


// UTILISATION_DES_EQUIPEMENTS

void allumerEquipement() {
    int id;
    printf("ID de l'équipement à allumer: ");
    scanf("%d", &id);
    for(int i=0;i<nbEquipements;i++){
        if(equipements[i].id == id){
            if(equipements[i].etat == 1){
                printf("L'équipement est déjà allumé.\n");
                return;
            }
            equipements[i].etat = 1;
            equipements[i].debut_utilisation = time(NULL);
            printf("Équipement %s allumé.\n", equipements[i].nom);
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

void eteindreEquipement() {
    int id;
    printf("ID de l'équipement à éteindre: ");
    scanf("%d", &id);
    for(int i=0;i<nbEquipements;i++){
        if(equipements[i].id == id){
            if(equipements[i].etat == 0){
                printf("L'équipement est déjà éteint.\n");
                return;
            }
            time_t fin = time(NULL);
            double duree_min = difftime(fin, equipements[i].debut_utilisation)/60.0;
            float conso = duree_min * equipements[i].conso_min;
            ajouterConsommation(equipements[i].id, equipements[i].debut_utilisation, fin, conso);
            equipements[i].etat = 0;
            printf("Équipement %s éteint. Consommation: %.2f\n", equipements[i].nom, conso);
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

void afficherEtatEquipements() {
    printf("\n=== État des équipements ===\n");
    for(int i=0;i<nbEquipements;i++){
        printf("ID: %d | Nom: %s | Etat: %s\n", equipements[i].id, equipements[i].nom,
               equipements[i].etat ? "Allumé" : "Éteint");
    }
}

// Menu de statistiques (stub: placeholder so main2 links)
void statistiquesMenu() {
    printf("Menu statistiques non implémenté.\n");
}
