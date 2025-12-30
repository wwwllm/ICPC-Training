#include <bits/stdc++.h>
using namespace std;

// 匈牙利算法：时间复杂度O(nm)
const int N = 505, M = 1e5 + 10;
int n1, n2, m;
vector<int> g[N];
int match[N];
bool st[N];
bool find(int x)
{
    for (auto ele : g[x])
    {
        if (!st[ele])
        {
            st[ele] = 1;
            if (!match[ele] || find(match[ele]))
            {
                match[ele] = x;
                return true;
            }
        }
    }
    return false;
}
signed main()
{
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, 0, sizeof(st));
        if (find(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}