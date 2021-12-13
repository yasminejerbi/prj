#include "etudiant.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum
{
     NOM,
     PRENOM,
     ID,
     MDP,
     NIVEAU,
     SEXE,
     ETAT,
	JOUR,
	MOIS,
	ANNEE,
     /*DATE_INSCRIPTION,*/
     COLUMNS
};

void afficher(GtkWidget *liste,char *file)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	Etudiant f;
	store=NULL;
	
	FILE *z;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ETAT",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",NIVEAU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",ANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("MDP",renderer,"text",MDP,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		 
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	z=fopen(file,"r");
	if(z==NULL){return;}
	else
	{
		 while(fscanf(z,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,&f.niveau,&f.date_inscription.jour,&f.date_inscription.mois,&f.date_inscription.annee,f.sexe,f.mdp)!=EOF)
		 {
			gtk_list_store_append(store,&iter);
		  	gtk_list_store_set(store,&iter,ID,f.itd,ETAT,f.etat,NOM,f.nom,PRENOM,f.prenom,NIVEAU,f.niveau,JOUR,f.date_inscription.jour,MOIS,f.date_inscription.mois,ANNEE,f.date_inscription.annee,SEXE,f.sexe,MDP,f.mdp,-1);
		 }
	 fclose(z);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}
}

/*void afficher(GtkTreeView *liste)
{
Etudiant p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[50], prenom[20], itd[20], mdp[20], sexe[5], etat[20];
char jour[50], mois[50], annee[50];
char niveau[50];
Date date_inscription;
store=NULL;
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("itd", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mdp", renderer,"text",MDP, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau", renderer,"text",NIVEAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe", renderer,"text",SEXE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etat", renderer,"text",ETAT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("etudiant.txt","a+");
if(f==NULL)
{
return;
}
else
{ f = fopen("etudiant.txt","a+");
		/*while(fscanf(f,"%s %s %d %s %s %s %s %d %d %d\n",p.itd,p.prenom,&p.niveau,p.nom,p.mdp,p.etat,p.sexe,&(p.date_inscription.jour),&(p.date_inscription.mois),&(p.date_inscription.annee))!=EOF)

while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",itd,prenom,niveau,nom,mdp,etat,sexe,jour,mois,annee)!=EOF)
	{

sprintf(nom,"%s",p.nom);
sprintf(prenom,"%s",p.prenom);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,itd,NOM,nom,PRENOM,prenom,NIVEAU,niveau,SEXE,sexe,ETAT,etat,MDP,mdp,JOUR,p.date_inscription.jour,MOIS,mois,ANNEE,annee,-1);
	}
/*gtk_list_store_set(store,&iter,ID,p.itd,NOM,p.nom,PRENOM,p.prenom,NIVEAU,p.niveau,SEXE,p.sexe,ETAT,p.etat,MDP,p.mdp,JOUR,p.date_inscription.jour,MOIS,p.date_inscription.mois,ANNEE,p.date_inscription.annee,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}*/

void ajouter(Etudiant etd)
{

FILE *fe=fopen("etudiant.txt","a+");

    if(fe!=NULL)
     {
fprintf(fe,"%s %s %s %s %d %s %s %d %d %d \n",etd.nom,etd.prenom,etd.itd,etd.mdp,etd.niveau,etd.sexe,etd.etat,etd.date_inscription.jour,etd.date_inscription.mois,etd.date_inscription.annee);
fclose(fe);
}  
}

void modifier(Etudiant e)
{
Etudiant p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
fflush(stdin);
f=fopen("etudiant.txt","r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %s %s %s %d %s %s %d %d %d \n",p.nom,p.prenom,p.itd,p.mdp,&(p.niveau),p.sexe,p.etat,&p.date_inscription.jour,&p.date_inscription.mois,&p.date_inscription.annee)!=EOF)
	{
		if(p.itd!=e.itd)
			{
			fprintf(g,"%s %s %s %s %d %s %s %d %d %d\n",p.nom,p.prenom,p.itd,p.mdp,p.niveau,p.sexe,p.etat,p.date_inscription.jour,p.date_inscription.mois,p.date_inscription.annee);
}
		else
			{
			fprintf(g,"%s %s %s %s %d %s %s %d %d %d\n",p.itd,e.prenom,e.itd,e.mdp,e.niveau,e.sexe,e.etat,e.date_inscription.jour,e.date_inscription.mois,e.date_inscription.annee);
}
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Etudiant modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove("etudiant.txt");
rename("dump.txt","etudiant.txt");
}
}

void supprimer(char id[20]){
	Etudiant f;
	FILE *z,*g;
	z=fopen("etudiant.txt","r");
	g=fopen("tm.txt","a+");
	if(z!=NULL && g!=NULL)
	{
		while(fscanf(z,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,&f.niveau,&f.date_inscription.jour,&f.date_inscription.mois,&f.date_inscription.annee,f.sexe,f.mdp)!=EOF)
		{
			if(strcmp(id,f.itd)!=0)
				fprintf(g,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,f.niveau,f.date_inscription.jour,f.date_inscription.mois,f.date_inscription.annee,f.sexe,f.mdp);
		}

	
	}
	fclose(z);
	fclose(g);
	remove("etudiant.txt");
	rename("tm.txt","etudiant.txt");
}

void recherche(char cin[20]){
	Etudiant f;
	FILE *z,*g;
	z=fopen("etudiant.txt","r");
	g=fopen("recherche.txt","a+");
	if(z!=NULL && g!=NULL){
		while(fscanf(z,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,&f.niveau,&f.date_inscription.jour,&f.date_inscription.mois,&f.date_inscription.annee,f.sexe,f.mdp)!=EOF)
		{
			if(strcmp(cin,f.itd)==0)
				fprintf(g,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,f.niveau,f.date_inscription.jour,f.date_inscription.mois,f.date_inscription.annee,f.sexe,f.mdp);
				
				
		}
	}
	fclose(z);
	fclose(g);

}

int nbEtudiant(int niv, char *fichierEtud)
{
int som=0;
Etudiant f;
FILE *F;
F=fopen("nombre.txt","a+");
while(fscanf(F,"%s %s %s %s %d  %d %d %d %s %s\n",f.itd,f.etat,f.nom,f.prenom,&f.niveau,&f.date_inscription.jour,&f.date_inscription.mois,&f.date_inscription.annee,f.sexe,f.mdp)!=EOF)
		{
if(f.niveau==niv)
 som++;
return som;
}
}




