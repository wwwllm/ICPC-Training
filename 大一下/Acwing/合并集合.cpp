#include <bits/stdc++.h>
using namespace std;

// 并查集模板
const int maxn = 1e5 + 10;
int n, bcj[maxn], m;
void init()
{
    for (int i = 1; i <= n; i++)
        bcj[i] = i;
}
int find(int x)
{
    if (bcj[x] != x)
        return bcj[x] = find(bcj[x]);
    return x;
}
void join(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra != rb)
        bcj[rb] = ra;
}
signed main()
{
    cin >> n >> m;
    init();
    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M')
            join(a, b);
        else
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }
    return 0;
}