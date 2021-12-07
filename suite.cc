#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
   
  for (int i(debut); i <= fin; ++i) {
	  int j(i);
	  int step(0);
	  while (j > 0){
	     if (j%3 == 0) {
		     j += 4;
	     } else {
		     if (j%4 == 0){
			     j *= 0.5;
		     } else {
			     j -= 1;
		     }
	     }
	     step += 1;
     }
     cout << i << " -> " << step << endl;
  }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
