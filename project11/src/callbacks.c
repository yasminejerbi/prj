#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "etudiant.h"

int n, m;
void
on_button15_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *entry3,*treeview1;
	char cin1[20];
	entry3=lookup_widget(objet_graphique,"entry3");
	treeview1=lookup_widget(objet_graphique,"treeview1");
	strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(entry3)));
	if(strcmp(cin1,"")!=0)
	{
		recherche(cin1);
		afficher(treeview1,"etudiant.txt");
		remove("recherche.txt");
	}
	else
		afficher(treeview1,"etudiant.txt");
}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1, *gestion_etudiants1;

gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
treeview1=lookup_widget(gestion_etudiants1,"treeview1");
afficher(treeview1,"etudiant.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_etudiants1, *gestion_etudiants2;
gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
gestion_etudiants2=lookup_widget(objet_graphique,"gestion_etudiants2");
gtk_widget_destroy(gestion_etudiants1);
gestion_etudiants2=create_gestion_etudiants2();
gtk_widget_show(gestion_etudiants2);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_etudiants1, *gestion_etudiants2;
gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
gestion_etudiants2=lookup_widget(objet_graphique,"gestion_etudiants2");
gtk_widget_destroy(gestion_etudiants1);
gestion_etudiants2=create_gestion_etudiants2();
gtk_widget_show(gestion_etudiants2);
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_etudiants1;
	GtkTreeModel  *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	
	
        gchar* id;
	
	gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
        treeview=lookup_widget(gestion_etudiants1,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&id,-1);
		supprimer(id);
		afficher(treeview,"etudiant.txt");
		
	}
}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_etudiants1, *gestion_etudiants2;
gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
gestion_etudiants2=lookup_widget(objet_graphique,"gestion_etudiants2");
gtk_widget_destroy(gestion_etudiants2);
gestion_etudiants1=create_gestion_etudiants1();
gtk_widget_show(gestion_etudiants1);

	/*GtkWidget *gestion_etudiants1,*gestion_etudiants2,*treeview1;
	gestion_etudiants1=lookup_widget(objet_graphique,"gestion_etudiants1");
	gestion_etudiants2=lookup_widget(objet_graphique,"gestion_etudiants2");
	gtk_widget_destroy(gestion_etudiants2);
	gestion_etudiants1=create_gestion_etudiants1();
	gtk_widget_show(gestion_etudiants1);
	treeview1=lookup_widget(gestion_etudiants1,"treeview1");
	afficher(treeview1,"etudiant.txt");*/
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry4,*entry5,*entry6,*entry7;
GtkWidget *output;
GtkWidget *combobox2;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
char msg[20];
FILE *f;

Etudiant e;

entry4=lookup_widget(objet_graphique ,"entry4");
entry5=lookup_widget(objet_graphique , "entry5");
entry6=lookup_widget(objet_graphique , "entry6");
entry7=lookup_widget(objet_graphique , "entry7");

combobox2=lookup_widget(objet_graphique , "combobox2");

Jour=lookup_widget(objet_graphique , "jour");
Mois=lookup_widget(objet_graphique , "mois");
Annee=lookup_widget(objet_graphique , "annee");

e.date_inscription.jour=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Jour));
e.date_inscription.mois=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Mois));
e.date_inscription.annee=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Annee));

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(entry5)));
strcpy(e.itd,gtk_entry_get_text(GTK_ENTRY(entry6)));
strcpy(e.mdp,gtk_entry_get_text(GTK_ENTRY(entry7)));

if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=1;
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=2;
if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=3;
if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=4;	

if(n==1)
strcpy(e.sexe,"femme");
if(n==0)
strcpy(e.sexe,"homme");

if(m=1)
strcpy(e.etat,"handicape");

ajouter(e);

output=lookup_widget(objet_graphique , "sortie");
strcpy(msg,"ajout reussit");
gtk_label_set_text(GTK_LABEL(output),msg);
}


void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry4,*entry5,*entry6,*entry7;
GtkWidget *combobox2;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
Etudiant e;

entry4=lookup_widget(objet_graphique ,"entry4");
entry5=lookup_widget(objet_graphique , "entry5");
entry6=lookup_widget(objet_graphique , "entry6");
entry7=lookup_widget(objet_graphique , "entry7");

combobox2=lookup_widget(objet_graphique , "combobox2");

Jour=lookup_widget(objet_graphique , "jour");
Mois=lookup_widget(objet_graphique , "mois");
Annee=lookup_widget(objet_graphique , "annee");

e.date_inscription.jour=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Jour));
e.date_inscription.mois=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Mois));
e.date_inscription.annee=gtk_spin_button_get_value_as_int ( GTK_SPIN_BUTTON(Annee));

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(entry5)));
strcpy(e.itd,gtk_entry_get_text(GTK_ENTRY(entry6)));
strcpy(e.mdp,gtk_entry_get_text(GTK_ENTRY(entry7)));

if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=1;
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=2;
if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=3;
if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
	e.niveau=4;

modifier(e);


}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
n=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
n=0;
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
m=1;
}

