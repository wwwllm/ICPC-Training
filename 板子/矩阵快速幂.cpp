#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105, mod = 1e9 + 7;
int a[N][N], n, k;
int ans[N][N];
void init()
{
    for (int i = 1; i <= n; i++)
        ans[i][i] = 1;
}
void mulself()
{
    int c[N][N] = {{0}};
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % mod;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = c[i][j];
}
void mul()
{
    int c[N][N] = {{0}};
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = (c[i][j] + ans[i][k] * a[k][j]) % mod;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[i][j] = c[i][j];
}
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    init();
    while (k)
    {
        if (k & 1)
            mul();
        mulself();
        k >>= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}