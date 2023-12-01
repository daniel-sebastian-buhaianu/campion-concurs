#include <fstream>
#define MAX_JUDETE 50
#define MAX_ELEVI 500
using namespace std;
ofstream g("concurs.out");
int P,
    a[MAX_JUDETE+1][MAX_ELEVI+1],
    nr[MAX_JUDETE+1],
    inc[MAX_JUDETE+1];
void citire();
void sortare();
int nrJudete();
int main()
{
	citire();
	// rezolv cerinta 1
	g << nrJudete() << '\n';
	// rezolv cerinta 2
	for (int i = 1; i <= MAX_JUDETE; i++)
		if (a[i][0])
			g << a[i][0] << ' ';
	g << endl;
	// rezolv cerinta 3
	sortare();
	for (int i = 0; i < P;)
	{
		int max1=0, max2=0, lmax1=0, lmax2=0;
		for (int j = 1; j <= MAX_JUDETE; j++)
		{
			if (nr[j] > max1)
			{
				max2 = max1, lmax2 = lmax1;
				max1 = nr[j], lmax1 = j;
			}
			else if (nr[j] > max2)
			{
				max2 = nr[j];
				lmax2 = j;
			}
		}
		if (inc[lmax1] == 0) inc[lmax1]++;
		if (inc[lmax2] == 0) inc[lmax2]++;
		if (inc[lmax1] <= a[lmax1][0])
		{
			g << lmax1 << ' ';
			g << a[lmax1][inc[lmax1]] << '\n';
			nr[lmax1]--;
			inc[lmax1]++, i++;
		}
		if (inc[lmax2] <= a[lmax2][0] && i < P)
		{
			g << lmax2 << ' ';
			g << a[lmax2][inc[lmax2]] << '\n';
			nr[lmax2]--;
			inc[lmax2]++, i++;
		}
	}
	g.close();
	return 0;
}
void sortare()
{
	for (int i = 1; i <= MAX_JUDETE; i++)
		if (a[i][0])
			for (int j = 1; j < a[i][0]; j++)
				for (int k = j+1; k <= a[i][0]; k++)
					if (a[i][j] > a[i][k])
						swap(a[i][j], a[i][k]);
}
int nrJudete()
{
	int nrj = 0;
	for (int i = 1; i <= MAX_JUDETE; i++)
		if (a[i][0])
			nrj++;
	return nrj;
}
void citire()
{
	ifstream f("concurs.in");
	f >> P;
	for (int i = 0; i < P; i++)
	{
		int J, E;
		f >> J >> E;
		a[J][0]++;
		nr[J] = a[J][0];
		a[J][a[J][0]] = E;
	}
	f.close();
}
