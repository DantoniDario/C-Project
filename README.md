#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
 
 typedef vector<vector<int>> Carte;
 
 struct Position
 {
	 int i;
	 int j;
 };
 
 bool binaire(Carte const& carte)
 {
	 bool result(true);
	 for (auto ligne : carte)
	 {
		 for (auto element : ligne)
		 {
			 if ((element != 0) and (element != 1))
			 {
				 result = false;
			 }
		 }
	 }
	 return result;
	 
 }
 
 void affiche(Carte const& carte)
 {
	 for (auto ligne : carte)
	 {
		 for (auto element : ligne)
		 {
			 cout << element;
		 }
		 cout << endl;
	 }
	 cout << "----";
	 cout << endl;
 }
 
 void marque_composantes(Carte& carte)
 {
 }
 
 void ajoute_unique(vector<int>& ensemble, int valeur)
 {
 }

 bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
 {
   return true;
 }

 bool convexite_lignes(Carte& carte)
 {
   return true;
 }
 
 bool verifie_et_modifie(Carte& carte)
 {
	 bool result(true);
	 
	 for (auto ligne : carte)
	 {
		 for (auto element : ligne)
		 {
			 if ((element != 0) and (element != 1))
			 {
				 result = false;
			 }
		 }
	 }
	 if (not result)
	 {
		 cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
		 return result;
		 
	 } else {
		 for (int i(0); i < carte.size(); ++i)
		 {
		     for (int j(0); j < carte[i].size(); ++j)
			 {
					 if ((j > 0) and (carte[i][j] == 0) and (carte[i][j-1] == 1))
					 {
						int k(j);
						do
						{ k += 1;
						} while ((carte[i][k] == 0) and (k < carte[i].size()));
						
						if (k < carte[i].size())
						{
							for (int t(j);t < k; ++t)
							{
								carte[i][t] = 1;
							}
						}			
						k = 0;
				      }
			   }
		 }
		 return result;
	 } 
 }
 

double longueur_cloture(Carte const& carte, double echelle = 2.5) 
{
	int result(0);

	for (int i = 0; i < carte.size(); ++i) 
	{
		for (int j = 0; j < carte[i].size(); ++j) 
		{			
			if (carte[i][j] == 1)
			{
				if (i == 0)
				{
					result += 1;				
				}
				if (i == (carte.size()-1))
				{
					result += 1;				
				}
				if (j == 0) 
				{
					result += 1;
				}
				if (j == (carte[i].size()-1))
				{
					result += 1;
				}
				if((i > 0) and (carte[i-1][j] != 1))
				{
					result += 1;
				}
				if((j > 0) and (carte[i][j-1] != 1))
				{
					result += 1;
				}
				if((i < carte.size()-1) and (carte[i+1][j] != 1))
				{
					result += 1;
				}
				if((j < carte[i].size()-1) and (carte[i][j+1] != 1))
				{
					result += 1;
				}
			}
			
		}
	}

	return result * echelle;
}

		//  cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
        //  cout << "bord extérieur entrant trouvé en position [";
        //  cout << "][";
        //  cout << "]" << endl;


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
