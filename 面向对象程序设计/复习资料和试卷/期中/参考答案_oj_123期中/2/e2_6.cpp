#include<iostream>
#include<algorithm>

using namespace std;
const int N = 35;
int f[N][N];
int n, m;

void work()
{
    for (int i = 1; i <= m; i++)
    {
        f[0][i] = f[1][i];
        f[n + 1][i] = f[n][i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = f[i][1];
        f[i][m + 1] = f[i][m];
    }
    f[0][0] = f[1][1];
    f[0][m + 1] = f[1][m];
    f[n + 1][0] = f[n][1];
    f[n + 1][m + 1] = f[n][m];
}

int main()
{

    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> f[i][j];

        work();
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
                if (j != m + 1)
                    cout << f[i][j] << " ";
                else
                    cout << f[i][j];
            cout << endl;
        }
    }
    return 0;
}