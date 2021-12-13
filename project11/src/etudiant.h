#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct Date
{
int jour;
int mois;
int annee;
}Date;

typedef struct Etudiant
{
    char nom[20];
    char prenom[20];
    char itd[20];
    char mdp[20];
    int niveau;
    char sexe[20];
    char etat[20];
    Date date_inscription;

    }Etudiant;


void ajouter(Etudiant etd);
void afficher(GtkWidget *liste,char *file);
void modifier(Etudiant e);
void supprimer(char id[20]);
void recherche(char cin[20]);
int nbEtudiant(int niv, char *fichierEtud);
