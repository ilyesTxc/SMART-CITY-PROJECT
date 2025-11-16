#include "type_equipement.h"

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

