#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
	nombre = nombre * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
	int result(0);
	int chiffre_ref;
	int chiffre;
	int repetition(1);
	int init_nombre;
	
	do 
	{	
		chiffre_ref = separer_chiffre_gauche(nombre);
		init_nombre = nombre;
		chiffre = separer_chiffre_gauche(nombre);
		
		while (chiffre_ref == chiffre)
		{
			repetition += 1;
			init_nombre = nombre;
			chiffre = separer_chiffre_gauche(nombre);
		} 
		
		nombre = init_nombre;
		dire_chiffre(result, repetition, chiffre_ref);
		repetition = 1;
				
	} while (nombre != 0);
		
	return result;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
