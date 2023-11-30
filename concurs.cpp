#include <fstream>
#define MAX_J 50
#define MAX_E 250
using namespace std;
ifstream citeste("concurs.in");
ofstream scrie("concurs.out");
int p[MAX_J+1];
int main()
{
	int P, i, nj=0;
	int e[MAX_J+1][MAX_E], jud[MAX_J];
	citeste >> P;
	for (i = 0; i < P; i++)
	{
		int J, E;
		citeste >> J >> E;
		if (p[J] == 0)
        {
            jud[nj++] = J;
            e[J][0] = E;
        }
        else
        {
            int st = -1, dr = p[J];
            while (dr-st > 1)
            {
                int mij = st + (dr-st)/2;
                if (e[J][mij] < E)
                {
                    st = mij;
                }
                else
                {
                    dr = mij;
                }
            }
            for (int k = p[J]+1; k > dr; k--)
            {
                e[J][k] = e[J][k-1];
            }
            e[J][dr] = E;
        }
        p[J]++;
	}
	citeste.close();
	scrie << nj << endl;
	for (i = 0; i < nj; i++)
    {
        scrie << p[jud[i]] << ' ';
    }
    scrie << endl;
    for (i = 0; i < nj-1; i++)
    {
        for (int j = i+1; j < nj; j++)
        {
            if (p[jud[i]] < p[jud[j]])
            {
                swap(jud[i], jud[j]);
            }
        }
    }
    int k1=0, k2=1, j;
    i = j = 0;
    do
    {
        while (i < p[jud[k1]] && j < p[jud[k2]])
        {
            scrie << jud[k1] << ' ' << e[jud[k1]][i] << endl;
            scrie << jud[k2] << ' ' << e[jud[k2]][j] << endl;
            i++, j++;
        }
        if (j >= p[jud[k2]])
        {
            k2++;
            j = 0;
        }
        if (i >= p[jud[k1]])
        {
            i = j;
            k1 = k2;
            j = 0;
            k2++;
        }
    } while (k1 < nj && k2 < nj);
    if (k1 < nj && i < p[jud[k1]])
    {
        scrie << jud[k1] << ' ' << e[jud[k1]][i] << endl;
    }
	scrie.close();
	return 0;
}
