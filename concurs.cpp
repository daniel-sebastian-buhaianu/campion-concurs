#include <fstream>
#define JMAX 52
#define EMAX 502
using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
int p[JMAX], nj;
int main()
{
    int P, i;
    int jud[JMAX], e[JMAX][EMAX];
	f >> P;
	for (i = 0; i < P; i++)
	{
		int J, E;
		f >> J >> E;
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
            for (int k = p[J]; k > dr; k--)
            {
                e[J][k] = e[J][k-1];
            }
            e[J][dr] = E;
        }
        p[J]++;
	}
	f.close();
	g << nj << '\n';
	for (i = 1; i < JMAX; i++)
    {
        if (p[i])
        {
            g << p[i] << ' ';
        }
    }
    g << '\n';
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
            g << jud[k1] << ' ' << e[jud[k1]][i] << '\n';
            g << jud[k2] << ' ' << e[jud[k2]][j] << '\n';
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
        g << jud[k1] << ' ' << e[jud[k1]][i];
    }
	g.close();
	return 0;
}
