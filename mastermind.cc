#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	bool valide(false);
	if ((c == '.') or (c == 'R') or (c == 'G') or (c == 'B') or (c == 'C') or (c == 'Y') or (c == 'M')){
		return valide = true;
	}
	return valide;
}

// ======================================================================
bool verifier(char c1, char& r1, int& score)
{
	bool verif(false);
	
	if (c1 == r1)
	{
		score += 1;
		r1 = 'x';
		verif = true;
	}
	
	return verif;
}

// ======================================================================
void apparier(char c1, char& r1, char& r2, char& r3, int& score)
{
	if (verifier(c1, r1, score)) {verifier(c1, r1, score);}
	else if (verifier(c1, r2, score)) {verifier(c1, r2, score);}
	else {verifier(c1, r3, score);}
	
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	int score1(0);
	int score2(0);
	
	bool b1(verifier(c1, r1, score1));
	bool b2(verifier(c2, r2, score1));
	bool b3(verifier(c3, r3, score1));
	bool b4(verifier(c4, r4, score1));
	
	afficher(score1, '#');
	
	if(not b1) {apparier(c1, r2, r3, r4, score2);}
	if(not b2) {apparier(c2, r1, r3, r4, score2);}
	if(not b3) {apparier(c3, r1, r2, r4, score2);}
	if(not b4) {apparier(c4, r1, r2, r3, score2);}
	
	afficher(score2, '+');
	
	afficher(4 - score1 - score2, '-');
	
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	bool victoire(false);
	if ((c1 == r1) and (c2 == r2) and (c3 == r3) and (c4 == r4))
	{
		victoire = true;
		return victoire;
	}
	return victoire;
}

// ======================================================================
void jouer(int coup_max = 8)
{
	char c1(tirer_couleur());
	char c2(tirer_couleur());
	char c3(tirer_couleur());
	char c4(tirer_couleur());
	char r1;
	char r2;
	char r3;
	char r4;
	
	int coup(1);
	
	do
	{
		r1 = lire_couleur();
		r2 = lire_couleur();
		r3 = lire_couleur();
		r4 = lire_couleur();
		
		afficher_coup(r1, r2, r3, r4, c1, c2, c3, c4);
		
		coup +=1;
		
	} while(not(gagne(c1, c2, c3, c4, r1, r2, r3, r4)) and (coup <= coup_max));
	 
	if(gagne(c1, c2, c3, c4, r1, r2, r3, r4))
	{
		message_gagne(coup-1);
	} else {
		message_perdu(c1, c2, c3, c4);
	}	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
