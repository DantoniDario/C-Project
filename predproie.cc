#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  
  double taux_attaque_debut(0.0);
  double taux_attaque_final(0.0);
  double attack_rate(0.0);
  
  do {
	  cout << "Combien de renards au départ (>= 2) ? ";
	  cin >> renards_i;
  } while(renards_i < 2);
  
  do {
	  cout << "Combien de lapins au départ  (>= 5) ? ";
	  cin >> lapins_i;
  } while(lapins_i < 5);


  // ===== PARTIE 2 =====
  // Première simulation
  double old_renards(renards_i);
  double old_lapins(lapins_i);
  double  new_renards(0.0);
  double  new_lapins(0.0);
  
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  
  for (int i(1); i <= duree; ++i){
	  new_lapins = old_lapins * (1.0 + taux_croissance_lapins - taux_attaque * old_renards);
	  new_renards = old_renards * (1.0 + taux_attaque * old_lapins * taux_croissance_renards - taux_mortalite);
	  
	  if (new_lapins < 0){
		  new_lapins = 0;
	  }
	  if (new_renards < 0){
		  new_renards = 0;
	  }
	  
	  old_lapins = new_lapins;
	  old_renards = new_renards;
	  
	  cout << "Après "  << i << " mois, il y a " << new_lapins << " lapins et " << new_renards << " renards" << endl;
	  
  }
  

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;
  
  old_renards = renards_i;
  old_lapins = lapins_i;
  new_renards = 0.0;
  new_lapins = 0.0;
  bool danger_lapin(false);
  bool danger_renard(false);
  bool ouf_lapin(false);
  bool ouf_renard(false);
  bool mort_lapin(false);
  bool mort_renard(false);
  int duree_2(0);
  
  do {
	  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
	  cin >> taux_attaque_debut;
  } while((taux_attaque_debut > 6) or (taux_attaque_debut < 0.5));
  
  do {
	  cout << "taux d'attaque à la fin en % (entre " << taux_attaque_debut << " et 6) ? ";
	  cin >> taux_attaque_final;
  } while((taux_attaque_final > 6) or (taux_attaque_final < taux_attaque_debut));
  
  for (double j(taux_attaque_debut); j < taux_attaque_final; ++j){
	  
	attack_rate = j/100;
	
	old_renards = renards_i;
    old_lapins = lapins_i;
    new_renards = 0.0;
    new_lapins = 0.0;
    danger_lapin = false;
    danger_renard = false;
    ouf_lapin = false;
    ouf_renard = false;
    mort_lapin = false;
    mort_renard = false;
	
  
  for (int i(1); i <= duree; ++i){
	new_lapins = old_lapins * (1.0 + taux_croissance_lapins - attack_rate * old_renards);
	new_renards = old_renards * (1.0 + attack_rate * old_lapins * taux_croissance_renards - taux_mortalite);
	
	if (new_lapins < 2){
		new_lapins = 0;
		mort_lapin = true;
	}
	if (new_renards < 2){
		new_renards = 0;
		mort_renard = true;
	}
	if (new_lapins < 5){
		danger_lapin = true;
	}
	if (new_renards < 5){
		danger_renard = true;
	}
	if ((old_lapins < 5) and (new_lapins > 5)){
		ouf_lapin = true;
	}
	if ((old_renards < 5) and (new_renards > 5)){
		ouf_renard = true;
	}
	if ((new_renards == 0) and (new_lapins == 0)){
		duree_2 = i;
		i = duree;
	} else {
		duree_2 = duree;
	}
	  
	old_lapins = new_lapins;
	old_renards = new_renards;	  
  }
  
  cout <<  endl << "***** Le taux d'attaque vaut "<< attack_rate * 100 << "%" <<  endl;

  cout << "Après "  << duree_2 << " mois, il y a " << new_lapins << " lapins et " << new_renards << " renards" << endl;
  
  if (danger_renard){
		cout << "Les renards ont été en voie d'extinction" << endl;
	}
  if (ouf_renard){
		cout << "mais la population est remontée ! Ouf !" << endl;
	}
  if (mort_renard){
		cout << "et les renards ont disparu :-(" << endl;
	}
  if (danger_lapin){
		cout << "Les lapins ont été en voie d'extinction" << endl;
	}
  if (ouf_lapin){
		cout << "mais la population est remontée ! Ouf !" << endl;
	}
  if (mort_lapin){
		cout << "et les lapins ont disparu :-(" << endl;
	}
  if (not(danger_renard) and not(danger_lapin)){
		cout << "Les lapins et les renards ont des populations stables." << endl;
	}
}

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
