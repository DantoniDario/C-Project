#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;
  
  int price;
  int hours_1;
  int hours_2;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
   if ((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24)){
     cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
   } else {
	 if (fin == debut) {
     cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
     } else {
	   if (fin < debut) {
	     cout << "Bizarre, le début de la location est après la fin ..." << endl;   
       } else {
		 if ((fin <= 7) or (debut >= 17)){
		   price = (fin - debut); 
		   hours_1 = fin - debut;
		   hours_2 = 0;
		   cout << "Vous avez loué votre vélo pendant " << endl;
		   cout << hours_1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		   cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
	     }
		 else if ((debut <= 7) and ((fin >= 7) and (fin <= 17))) {
	       price = (7 - debut) + (fin - 7)*2;    
	       hours_1 = 7 - debut;
		   hours_2 = fin - 7;
		     if (hours_1 == 0){
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     } else {
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		       cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     }
	     }  
	     else if ((debut <= 7) and (fin >= 17)) {
	       price = (7 - debut) + (fin - 17) + 20;  
	       hours_1 = (7 - debut) + (fin - 17);
		   hours_2 = 10;  
		   if (hours_1 == 0){
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     } else {
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		       cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     }
	     }
	     else if ((debut >= 7) and (fin <= 17)) {
	       price = (fin - debut)*2; 
	       hours_1 = 0;
		   hours_2 = fin - debut; 
		   cout << "Vous avez loué votre vélo pendant " << endl;
		   cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		   cout << "Le montant total à payer est de " << price << " franc(s)." << endl;  
	     }  
	     else if (((debut >= 7) and (debut <= 17)) and (fin >= 17)) {
	       price = (17 - debut)*2 + (fin - 17);  
	       hours_1 = fin - 17;
		   hours_2 = (17 - debut);
		   if (hours_2 == 0){
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     } else {
			   cout << "Vous avez loué votre vélo pendant " << endl;
		       cout << hours_1 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
		       cout << hours_2 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
		       cout << "Le montant total à payer est de " << price << " franc(s)." << endl;
		     }
	     } 
	     }
       } 
     }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
