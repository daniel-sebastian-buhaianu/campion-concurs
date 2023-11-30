#include <fstream>
#define JMAX 52
#define EMAX 502
using namespace std;
ifstream f("concurs.in");
ofstream g("concurs.out");
int a[JMAX][EMAX];
int main()
{
    int P, i;
    f >> P;
    for (i = 0; i < P; i++)
    {
        int J, E;
        f >> J >> E;
        int st = 0, dr = a[J][0]+1;
        while (dr-st > 1)
        {
            int mij = st + (dr-st)/2;
            if (a[J][mij] < E)
            {
                st = mij;
            }
            else
            {
                dr = mij;
            }
        }
        for (int k = a[J][0]+1; k > dr; k--)
        {
            a[J][k] = a[J][k-1];
        }
        a[J][dr] = E;
        a[J][0]++;
    }
    f.close();
    int jud[JMAX], nj=0;
    for (i = 1; i <= 50; i++)
    {
        if (a[i][0])
        {
            jud[nj++] = i;
        }
    }
    g << nj << '\n';
    for (i = 0; i < nj; i++)
    {
        g << a[jud[i]][0] << ' ';
    }
    g << '\n';
    g.close();
    return 0;
}
