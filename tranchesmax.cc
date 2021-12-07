#include <iostream>
#include <array>
#include <vector>


using namespace std;

int somme_consecutifs_max(vector<int> tab)
{
	int resultmax(0);
	int result(0);
	
	for (auto element : tab)
	{
		if (element != 0)
		{
			result += element;
			
		} else {
			if (result > resultmax)
			{
				resultmax = result;
				result = 0;
			} else {
				result = 0;
			}
		}
	}
	if (result > resultmax)
	{
		resultmax = result;
		result = 0;
	}
	
	return resultmax;
}

vector<size_t> lignes_max(vector<vector<int>> tab)
{
	vector<size_t> result;
	int resultmax(0);
	
	if (tab.empty())
	{
		return result;
	} else {
		for (int i(0); i < tab.size(); ++i)
		{
			if(somme_consecutifs_max(tab[i]) > resultmax)
			{
				result.clear();
				result.push_back(i);
				resultmax = somme_consecutifs_max(tab[i]);
			}
			else if(somme_consecutifs_max(tab[i]) == resultmax)
			{
				result.push_back(i);
			}
		}
		
		
	}
	
	return result; 
	
}

vector<vector<int>> tranches_max(vector<vector<int>> tab)
{
	vector<vector<int>> result;
	vector<size_t> ligneMax(lignes_max(tab));
	
	for (auto element : ligneMax)
	{
		result.push_back(tab[element]);
	}

	return result; 
}

int main()
{

 
  return 0;
}
