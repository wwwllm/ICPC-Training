#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50;
int f[maxn][6];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int x;
            cin >> x;
            f[i][x] = 1;
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        int maxt = 0, cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (f[j][i])
                cnt++;
            else
                cnt = 0;
            maxt = max(maxt, cnt);
        }
        cout << maxt << ' ';
    }
    cout << endl;
    return 0;
}