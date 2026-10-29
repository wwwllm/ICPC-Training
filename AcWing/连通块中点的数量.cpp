#include <bits/stdc++.h>
using namespace std;

// 并查集模板
const int maxn = 1e5 + 10;
int n, bcj[maxn], m, cnt[maxn];
void init()
{
    for (int i = 1; i <= n; i++)
        bcj[i] = i, cnt[i] = 1;
}
int find(int x)
{
    if (bcj[x] != x)
    {
        return bcj[x] = find(bcj[x]);
    }
    return x;
}
void join(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra != rb)
        bcj[rb] = ra, cnt[ra] += cnt[rb];
}
signed main()
{
    cin >> n >> m;
    init();
    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C")
            cin >> a >> b, join(a, b);
        else if (op == "Q1")
            cin >> a >> b, cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        else
            cin >> a, cout << cnt[find(a)] << endl;
    }
    return 0;
}