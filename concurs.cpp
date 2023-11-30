#include <fstream>
#define MAX_JUDETE 50
#define MAX_ELEVI 500
using namespace std;
ofstream g("concurs.out");
int a[MAX_JUDETE+1][MAX_ELEVI+1], P;
void citire();
int nrJudete();
void sortare();
void afisare();
int main()
{
    citire();
    g << nrJudete() << '\n';
    int i, nr[MAX_JUDETE+1];
    for (i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            g << a[i][0] << ' ';
            nr[i] = a[i][0];
        }
    }
    sortare();
    max1 = max2 = 0;
    inc[max1] = inc[max2] = 0;
    for (i = 0; i < P;)
    {
        for (int j = 1; j <= MAX_JUDETE; j++)
        {
            if (nr[j] > max1)
            {
                max2 = max1;
                max1 = j;
            }
            else if (nr[j] > max2)
            {
                max2 = j;
            }
        }
        // TO BE CONTINUED
        if (inc[max1] <= a[max1][0])
        {
            g << max1 << ' ' << a[max1][inc[max1]] << '\n';
            inc[max1]++;
            i++;
        }
        if (inc[max2] <= a[max2][0])
        {
            g << max2 << ' ' << a[max2][inc[max2]] << '\n';
            inc[max2]++;
            i++;
        }
    }
    g.close();
    return 0;
}
void afisare()
{
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            for (int j = 0; j <= a[i][0]; j++)
            {
                g << a[i][j] << ' ';
            }
            g << endl;
        }
    }
}
void sortare()
{
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            for (int j = 1; j < a[i][0]; j++)
            {
                for (int k = j+1; k <= a[i][0]; k++)
                {
                    if (a[i][j] > a[i][k])
                    {
                        swap(a[i][j], a[i][k]);
                    }
                }
            }
        }
    }
}
int nrJudete()
{
    int nrj = 0;
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            nrj++;
        }
    }
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
        a[J][a[J][0]] = E;
    }
    f.close();
}
#include <fstream>
#define MAX_JUDETE 50
#define MAX_ELEVI 500
using namespace std;
ofstream g("concurs.out");
int a[MAX_JUDETE+1][MAX_ELEVI+1], P;
void citire();
int nrJudete();
void sortare();
void afisare();
int main()
{
    citire();
    g << nrJudete() << '\n';
    int i, nr[MAX_JUDETE+1];
    for (i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            g << a[i][0] << ' ';
            nr[i] = a[i][0];
        }
    }
    sortare();
    max1 = max2 = 0;
    inc[max1] = inc[max2] = 0;
    for (i = 0; i < P;)
    {
        for (int j = 1; j <= MAX_JUDETE; j++)
        {
            if (nr[j] > max1)
            {
                max2 = max1;
                max1 = j;
            }
            else if (nr[j] > max2)
            {
                max2 = j;
            }
        }
        // TO BE CONTINUED
        if (inc[max1] <= a[max1][0])
        {
            g << max1 << ' ' << a[max1][inc[max1]] << '\n';
            inc[max1]++;
            i++;
        }
        if (inc[max2] <= a[max2][0])
        {
            g << max2 << ' ' << a[max2][inc[max2]] << '\n';
            inc[max2]++;
            i++;
        }
    }
    g.close();
    return 0;
}
void afisare()
{
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            for (int j = 0; j <= a[i][0]; j++)
            {
                g << a[i][j] << ' ';
            }
            g << endl;
        }
    }
}
void sortare()
{
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            for (int j = 1; j < a[i][0]; j++)
            {
                for (int k = j+1; k <= a[i][0]; k++)
                {
                    if (a[i][j] > a[i][k])
                    {
                        swap(a[i][j], a[i][k]);
                    }
                }
            }
        }
    }
}
int nrJudete()
{
    int nrj = 0;
    for (int i = 1; i <= MAX_JUDETE; i++)
    {
        if (a[i][0])
        {
            nrj++;
        }
    }
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
        a[J][a[J][0]] = E;
    }
    f.close();
}
