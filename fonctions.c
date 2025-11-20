#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <time.h>
int max_batiment=100;
int max_equipement=100 ;





// les fonctions du gestion des batiment
Batiment saisie_batiment ()
{
    Batiment ba ;
    printf("\n donner id_batiment :");
    scanf("%d",&ba.id_bat);
    printf("\n donner le nom du batiment :");
    scanf("%s",ba.nom_bat);
    printf("\n donner l adresse :");
    scanf("%s\n %s\n %d\n ",ba.adresses.ville ,ba.adresses.rue , &ba.adresses.code_postal);
    printf("\n donner le nombre d equipement :");
    scanf("%d",&ba.nbEquip);
    return(ba);
}

void saisie_tab_batiment(Batiment tab[],int n)
{
    int i;
    do {
        printf("donner le nombre des batiment a ajouter");
        scanf("%d",&n);
    }
    while(n>max_batiment);
    for(i=0;i<=n;i++) tab[i]=saisie_batiment();


}
void affiche_batiment(Batiment ba)
{
    printf("\n L'id du batiment %d ",ba.id_bat);
    printf("\n le nom du batiment %s",ba.nom_bat);
    printf("\n l'adresse :\n *le nom du ville %s \n *le nom du rue %s \n *le code postal %d",ba.adresses.ville ,ba.adresses.rue , ba.adresses.code_postal);
    printf("\n le nombre d'equipement %d",ba.nbEquip);

}
void affiche_tab_batiment(Batiment tab[], int n)
{
    int i;
    if (n<= max_batiment){
            for(i=0;i<=n;i++) affiche_batiment( tab[i]) ;
    }

}
void modifier_batiment (Batiment *ba)
{
    int choix ;
    printf("\n 1.modifier l' id du batiment");
    printf("\n 2.modifier le nom du batiment ");
    printf("\n 3.modifier l'adresse du batiment");
    printf("\n 4.modifier le nombre des equipement");
    printf("\n 0.retour au menu principal");
    printf("\n donner votre choix");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1 :
        {
            printf("donner la nouvelle valeur de l'id");
            scanf("%d",&ba->id_bat);
            break ;
        }
    case 2 :
        {
            printf("donner le nouveau nom ");
            scanf("%s",ba->nom_bat);
            break ;
        }
    case 3 :
        {
            printf("donner la nouvelle adresse ");
            printf("\n le nouveau nom du ville");
            scanf("%s",ba->adresses.ville);
            printf("\n le nouveau nom du rue ");
            scanf("%s",ba->adresses.rue);
            printf("\n le nouveau code postal");
            scanf("%d",&ba->adresses.code_postal);
            break ;


        }
    case 4 :
        {
            printf("donner le nouveau nombre des equipement ");
            scanf("%d",&ba->nbEquip);
            break ;

        }
    case 0:
        {
            break ;
        }
    default : printf("votre choix est invalide");

    }

}
void modifier_tab_batiment (Batiment tab[],int n)
{
    int i ;
    if(n<= max_batiment){
        for (i=0;i<= n ;i++) {
                modifier_batiment(&tab[i]);
    }
    }
}

void supprimer_batiment(Batiment tab[] ,int pos ,int *n)
{
    int i ;
    if (*n<=max_batiment){
        for(i=pos;i<*n;i++){
            tab[i]=tab[i+1];
            (*n)-- ;
        }
    }
}
int recherche_id_batiment(Batiment tab[],int n)
{
    int id ;
    int i;
    printf("donner l'id ");
    scanf("%d",&id);
    if (n<=max_batiment){
        for (i=0;i<=n;i++){
            if (id==tab[i].id_bat) return (i);


        }



    }
    return -1 ;


}

Batiment recherche_nom_batiment(Batiment tab[], int n)
{
    int i;
    char nom[50];

    printf("Donner le nom du batiment : ");
    scanf("%49s", nom);

    for (i = 0; i < n; i++)
    {
        if (strcmp(tab[i].nom_bat, nom) == 0)
        {
            return tab[i];
        }
    }

    printf("Erreur : nom invalide, aucun bâtiment ne porte ce nom.\n");

    Batiment vide = {0};
    return vide;
}

// les fonctions de gestion des equipements

Equipement saisie_equipement ()
{
    Equipement eq ;
    printf("\n donner id_equipement :");
    scanf("%d",&eq.id_equip);
    printf("\n donner nom de l equipement :");
    scanf("%s",eq.nom_equip);
    printf("\n donner la consomation minimale de l energie  :");
    scanf("%f",&eq.energie_consom_min);
    printf("\n donner id du batiment ");
    scanf("%d",&eq.id_bat);
    printf("\n donner id du type d equipement:");
    scanf("%d",&eq.id_type);
    eq.etat=0;
    eq.debut_utilisation=0;
    return (eq);

}

void saisie_tab_equipement (Equipement tab[],int n)
{
    int i;
    do {
        printf("donner le nombre d'equipements a ajouter");
        scanf("%d",&n);
    }
    while(n>max_equipement);
    for(i=0;i<=n;i++) tab[i]=saisie_equipement();




}

void affiche_equipement(Equipement eq)
{
    printf("\n L'id de l' equipement %d ",eq.id_equip);
    printf("\n le nom de l'equipemnt %s",eq.nom_equip);
    printf("\n l'energie de consommation min %f",eq.energie_consom_min);
    printf("\n l'id du batiment  %d",eq.id_bat);
    printf("\n l'id du type d'equipement  %d",eq.id_type);
    printf("\n l'etat %d",eq.etat);



}


void affiche_tab_equipement(Equipement tab[], int n)
{
    int i;
    if (n<= max_equipement){
            for(i=0;i<=n;i++) affiche_equipement( tab[i]) ;
    }

}
void modifier_equipement(Equipement *eq)
{
    int choix ;
    printf("\n 1.modifier l' id de l'equipement");
    printf("\n 2.modifier le nom de l'equipement ");
    printf("\n 3.modifier l'energie de consommation min ");
    printf("\n 4.modifier l' id du batiment");
    printf("\n 5.modifier l'id du type d'equipement ");
    printf("\n 6.modifier l'etat");
    printf("\n 0.retour au menu principal");
    printf("\n donner votre choix");
    scanf("%d",&choix);
    switch (choix)
    {
            case 1 :
        {
            printf("donner la nouvelle valeur de l'id");
            scanf("%d",&eq->id_equip);
            break ;
        }
    case 2 :
        {
            printf("donner le nouveau nom ");
            scanf("%s",eq->nom_equip);
            break ;
        }
    case 3 :
        {
            printf("donner la nouvelle valeur de l'energie de consommation min ");
            scanf("%f",&eq->energie_consom_min);
            break ;


        }
    case 4 :
        {
            printf("donner la nouvelle valeur de l'id");
            scanf("%d",&eq->id_bat);
            break ;
        }
    case 5 :
        {
            printf("donner la nouvelle valeur de l'id");
            scanf("%d",&eq->id_type);
            break ;
        }
    case 6 :
        {
            printf("donner la nouvelle valeur de l'etat ");
            scanf("%d",&eq->etat);
            break ;

        }
    case 0:
        {
            break ;
        }
    default : printf("votre choix est invalide");

    }
}
void modifier_tab_equipement (Equipement tab[],int n)
{
    int i ;
    if(n<= max_equipement){
        for (i=0;i<= n ;i++) {
                modifier_equipement(&tab[i]);
    }
    }
}
void supprimer_equipement(Equipement tab[] ,int pos ,int *n)
{
    int i ;
    if (*n<=max_equipement){
        for(i=pos;i<*n;i++){
            tab[i]=tab[i+1];
            (*n)-- ;
        }
    }
}
int recherche_id_equipement(Equipement tab[],int n)
{
    int id ;
    int i;
    printf("donner l'id ");
    scanf("%d",&id);
    if (n<=max_equipement){
        for (i=0;i<=n;i++){
            if (id==tab[i].id_equip) return (i);


        }


    }
    return -1 ;


}
Equipement recherche_nom_equipemnt(Equipement tab[],int n)
{
    int i ;
    char nom[50] ;
    printf("donner le nom de consommation ");
    scanf("%49s",nom);
    if (n<=max_equipement){
        for (i=0;i<=n;i++){
            if (strcmp(tab[i].nom_equip , nom) == 0) return (tab[i]);


        }


    }
    printf("Erreur : nom invalide, veuillez verifier le nom.\n");
    Equipement vide = {0};
    return vide;
}
// Fonction pour ajouter une consommation après opération Allumer/Eteindre
int ajouterConsommation(Consommation consoList[], int *nbConso,
                       int idEquipement, time_t debut, time_t fin, float consommation) {

    // Vérifier si le tableau est plein
    if (*nbConso >= MAX_CONSO) {
        printf("Erreur: Le tableau des consommations est plein!\n");
        return 0; // Échec
    }

    // Ajouter la nouvelle consommation
    Consommation nouvelleConso;
    nouvelleConso.id = *nbConso + 1;
    nouvelleConso.idEquipement = idEquipement;
    nouvelleConso.debut = debut;
    nouvelleConso.fin = fin;
    nouvelleConso.consommation = consommation;

    consoList[*nbConso] = nouvelleConso;
    (*nbConso)++;

    printf("Consommation ajoutée avec succès! (ID: %d)\n", nouvelleConso.id);
    return 1; // Succès
}

// Fonction pour afficher toutes les consommations
void afficherConsommations(Consommation consoList[], int nbConso) {
    if (nbConso == 0) {
        printf("Aucune consommation enregistrée.\n");
        return;
    }

    printf("\n=== LISTE DES CONSOMMATIONS ===\n");
    printf("ID\tEquipement\tDébut\t\tFin\t\t\tConsommation (kWh)\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < nbConso; i++) {
        char debutStr[20], finStr[20];

        // Convertir les timestamps en chaînes lisibles
        strftime(debutStr, sizeof(debutStr), "%H:%M:%S", localtime(&consoList[i].debut));
        strftime(finStr, sizeof(finStr), "%H:%M:%S", localtime(&consoList[i].fin));

        printf("%d\t%d\t\t%s\t%s\t\t%.2f\n",
               consoList[i].id,
               consoList[i].idEquipement,
               debutStr,
               finStr,
               consoList[i].consommation);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Total: %d consommation(s) enregistrée(s)\n", nbConso);
    printf("Espace restant: %d/%d\n", MAX_CONSO - nbConso, MAX_CONSO);
}

// Fonction pour allumer un équipement
void allumerEquipement(int idEquipement, time_t *debut) {
    *debut = time(NULL);
    printf("Équipement %d allumé à %s", idEquipement, ctime(debut));
}

// Fonction pour éteindre un équipement et enregistrer la consommation
void eteindreEquipement(int idEquipement, time_t debut, Consommation consoList[],
                       int *nbConso, float tauxConsommation) {

    time_t fin = time(NULL);

    // Calculer la durée en heures
    double dureeHeures = difftime(fin, debut) / 3600.0;

    // Calculer la consommation
    float consommation = dureeHeures * tauxConsommation;

    printf("Équipement %d éteint à %s", idEquipement, ctime(&fin));
    printf("Durée d'utilisation: %.2f heures\n", dureeHeures);
    printf("Consommation: %.2f kWh\n", consommation);

    // Ajouter à la liste des consommations
    if (!ajouterConsommation(consoList, nbConso, idEquipement, debut, fin, consommation)) {
        printf("Impossible d'ajouter la consommation - tableau plein!\n");
    }
}


