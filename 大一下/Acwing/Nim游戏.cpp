#include <bits/stdc++.h>
using namespace std;

// a[i]=1:为必败点
const int N = 105, INF = 0x3f3f3f3f;
int f[N];
int sg(int x)
{
    unordered_set<int> s;
    if (f[x] != -1)
        return f[x];
    for (int i = 0; i < x; i++)
        for (int j = 0; j <= i; j++)
            s.insert(sg(i) ^ sg(j));
    for (int i = 0;i<=INF ; i++)
        if (!s.count(i))
            return f[x] = i;
    return INF;
}
signed main()
{
    int n;
    cin >> n;
    int ans = 0;
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans ^= sg(x);
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}