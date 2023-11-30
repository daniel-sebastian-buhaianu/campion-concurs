#include <fstream>
#define MAX_J 50
#define MAX_E 1000
using namespace std;
ifstream citeste("concurs.in");
ofstream scrie("concurs.out");
bool a[MAX_J+1][MAX_E+1];
int nrp[MAX_J];
int main()
{
	int P;
	citeste >> P;
	while (P > 0)
	{
		int J, E;
		citeste >> J >> E;
		a[J][E] = 1;
		nrp[J]++;
		P--;
	}
	int nrj=0, jud[MAX_J], i;
	for (i = 1; i <= MAX_J; i++)
	{
		if (nrp[i])
		{
			jud[nrj++] = i;
		}
	}
	scrie << nrj << endl;
	for (i = 0; i < nrj; i++)
	{
		scrie << nrp[jud[i]] << ' ';
	}
	scrie << endl;
	int j;
	for (i = 0; i < nrj-1; i++)
	{
		for (j = i+1; j < nrj; j++)
		{
			if (nrp[jud[i]] < nrp[jud[j]])
			{
				swap(jud[i], jud[j]);
			}
		}
	}
	citeste.close();
	scrie.close();
	return 0;
}
