#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
struct M
{
    int T[2][2];
};
void mul(M *a, M b)
{
    M c;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            c.T[i][j] = 0;
    for (int k = 0; k <= 1; k++)
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                c.T[i][j] = (c.T[i][j] + (*a).T[i][k] * b.T[k][j]) % mod;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            (*a).T[i][j] = c.T[i][j];
}
void mulans(M a, M *b)
{
    M c;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            c.T[i][j] = 0;
    for (int k = 0; k <= 1; k++)
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
                c.T[i][j] = (c.T[i][j] + a.T[i][k] * (*b).T[k][j]) % mod;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            (*b).T[i][j] = c.T[i][j];
}
signed main()
{
    int n;
    cin >> n;
    n--;
    M a = {{{1, 1}, {1, 0}}};
    M f = {{{1, 0}, {1, 0}}};
    M ans = {{{1, 0}, {0, 1}}};
    while (n)
    {
        if (n & 1)
            mul(&ans, a);
        mul(&a, a);
        n >>= 1;
    }
    mulans(ans, &f);
    cout << f.T[1][0] << endl;
    return 0;
}