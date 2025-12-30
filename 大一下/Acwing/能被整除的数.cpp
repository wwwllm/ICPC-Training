#include <bits/stdc++.h>
#define int long long
using namespace std;

// 容斥原理
const int maxn = 20;
int p[maxn];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    int ans = 0;
    for (int i = 1; i < (1 << m); i++)
    {
        int x = 1;
        int op = -1;
        for (int k = 0; k <= m - 1; k++)
        {
            if ((i >> k) & 1)
            {
                op *= -1;
                if (x * p[k + 1] > n)
                {
                    x = -1;
                    break;
                }
                x *= p[k + 1];
            }
        }
        if (x != -1)
            ans += op * (n / x);
    }
    cout << ans << endl;
    return 0;
}