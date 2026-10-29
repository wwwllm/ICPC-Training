#include <bits/stdc++.h>
using namespace std;

bool b[10];
int g[10][10];
bool solve()
{
    bool flag = 1;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            cin >> g[i][j];
            if (g[i][j] > 9 || g[i][j] < 1)
                flag=0;
        }
    if(!flag)
        return 0;
    for (int i = 1; i <= 9; i++)
    {
        memset(b, 0, sizeof(b));
        for (int j = 1; j <= 9; j++)
            if (b[g[i][j]])
                return 0;
            else
                b[g[i][j]] = 1;
    }
    for (int i = 1; i <= 9; i++)
    {
        memset(b, 0, sizeof(b));
        for (int j = 1; j <= 9; j++)
            if (b[g[j][i]])
                return 0;
            else
                b[g[j][i]] = 1;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            memset(b, 0, sizeof(b));
            int x = (i - 1) * 3, y = (j - 1) * 3;
            for (int n = 1; n <= 3; n++)
                for (int m = 1; m <= 3; m++)
                    if (b[g[x + n][y + m]])
                        return 0;
                    else
                        b[g[x + n][m + y]] = 1;
        }
    }
    return 1;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        if (solve())
            cout << 1 << endl;
        else
            cout << 0 << endl;
    return 0;
}