#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int a[N][N];
void out()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}
int gauss()
{
    int c, r;
    for (c = 1, r = 1; c <= n; c++)
    {
        int t = r;
        for (int i = r; i <= n; i++)
            if (a[i][c])
            {
                t = i;
                break;
            }
        if (!a[t][c])
            continue;
        for (int i = c; i <= n + 1; i++)
            swap(a[t][i], a[r][i]);
        for (int i = r + 1; i <= n; i++)
            if (a[i][c])
                for (int j = n + 1; j >= c; j--)
                    a[i][j] ^= a[r][j];
        r++;
    }
    if (r <= n)
    {
        for (int i = r; i <= n; i++)
            if (a[i][n + 1])
                return 2;
        return 1;
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            if (a[i][j])
                a[i][n + 1] ^= a[j][n + 1];
    return 0;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    int op = gauss();
    if (op == 0)
        for (int i = 1; i <= n; i++)
            cout << a[i][n + 1] << endl;
    else if (op == 1)
        cout << "Multiple sets of solutions" << endl;
    else
        cout << "No solution" << endl;
    return 0;
}