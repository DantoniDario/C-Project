#include <iostream>
#include <string>
using namespace std;

int main()
{
  int reponse;
  string champ;
  cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl;
  
  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
  cin >> reponse;
  if (reponse == 0) {
	  cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
	  cin >> reponse;
	  if (reponse == 0){
		  cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
		  cin >> reponse;
		  if (reponse == 0){
			  champ = "le cèpe de Bordeaux";
		  } else {
			 champ = "la girolle";
		  }
	  } else {
		  champ = "le coprin chevelu";
	  }
  } else {
	  cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
	  cin >> reponse;
	  if (reponse == 0){
		  champ = "le pied bleu";
	  } else {
		 cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		 cin >> reponse;
		 if (reponse == 0){
			 champ = "l'agaric jaunissant";
		 } else {
			 champ = "l'amanite tue-mouches";
		 } 
	  }
  }

  cout << "==> Le champignon auquel vous pensez est " << champ;

  
  return 0;
}
