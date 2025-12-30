#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7, M[3][3] = {{3, 2, 6}, {1, 0, 0}, {0, 1, 0}};
int ans[3][3], a[3][3], f[3][3];
void mul1()
{ // ans*a
    int c[3][3];
    memset(c, 0, sizeof(c));
    for (int k = 0; k <= 2; k++)
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                c[i][j] = (c[i][j] + ans[i][k] * a[k][j]) % mod;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            ans[i][j] = c[i][j];
}
void mul2()
{
    int c[3][3];
    memset(c, 0, sizeof(c));
    for (int k = 0; k <= 2; k++)
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % mod;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            a[i][j] = c[i][j];
}
void mul()
{
    int c[3][3];
    memset(c, 0, sizeof(c));
    for (int k = 0; k <= 2; k++)
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                c[i][j] = (c[i][j] + ans[i][k] * f[k][j]) % mod;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            f[i][j] = c[i][j];
}
void init()
{
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            a[i][j] = M[i][j], ans[i][j] = 0;
    for (int i = 0; i <= 2; i++)
        ans[i][i] = 1, f[i][0] = 1;
}
void solve()
{
    int n;
    cin >> n;
    init();
    if (n <= 3)
    {
        cout << 1 << endl;
    }
    n -= 3;
    while (n)
    {
        if (n & 1)
            mul1();
        n >>= 1;
        mul2();
    }
    mul();
    cout << f[0][0] << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}