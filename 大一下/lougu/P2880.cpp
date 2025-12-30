#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5e4 + 50;
int h[maxn];
int ma[maxn][20], mi[maxn][20], log_2[maxn];
int n, q;
void init()
{
    for (int i = 1; i <= n; i++)
        ma[i][0] = mi[i][0] = h[i];
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i <= n-(1<<j)+1; i++)
        {
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
        }
    }
} 
int query_max(int l, int r)
{
    int x = log_2[r - l + 1];
    return max(ma[l][x], ma[r - (1 << x) + 1][x]);
}
int query_min(int l, int r)
{
    int x = log_2[r - l + 1];
    return min(mi[l][x], mi[r - (1 << x) + 1][x]);
}
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 2; i <= n; i++)
    {
        log_2[i] = log_2[i >> 1] + 1;
    }
    init();
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query_max(l, r) -query_min(l, r) << endl;
    }
    return 0;
}