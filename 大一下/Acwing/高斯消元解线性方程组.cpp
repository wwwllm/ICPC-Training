#include <bits/stdc++.h>
using namespace std;

// O(n^3)解n元线性方程组
// 1.无解  2.无穷多组解  3.唯一解
const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];
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
    int c = 1, r = 1;
    for (; c <= n; c++)
    {
        int t = r;
        for (int i = r; i <= n; i++)
            if (abs(a[i][c]) > abs(a[t][c]))
                t = i;
        if (abs(a[t][c]) < eps)
            continue;
        for (int i = c; i <= n + 1; i++)
            swap(a[r][i], a[t][i]);
        for (int i = n + 1; i >= c; i--)
            a[r][i] = a[r][i] / a[r][c];
        for (int i = r + 1; i <= n; i++)
            if (abs(a[i][c]) > eps)
                for (int j = n + 1; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r++;
    }
    if (r <= n)
    {
        for (int i = r; i <= n; i++)
            if (abs(a[i][n + 1]) > eps)
                return 2;
        return 1;
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
    return 0;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    int op = gauss();
    if (op == 1)
        cout << "Infinite group solutions" << endl;
    else if (op == 2)
        cout << "No solution" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << fixed << setprecision(2) << a[i][n + 1] << endl;
    }
    return 0;
}