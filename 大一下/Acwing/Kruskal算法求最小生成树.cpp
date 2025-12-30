#include <bits/stdc++.h>
using namespace std;

// Kruskal算法：时间复杂度O(mlogm),时候稀疏图
// 算法流程：1.先将所有边从小到大排序。2.枚举每条边a,b,c。如果a,b还不联通则把b加到集合里面
const int maxn = 1e5 + 10;
struct Edge
{
    int a, b, v;
    bool operator< (const Edge &W)const{
        return v < W.v;
    }
} e[2*maxn];
int n, m, ans, cnt=1;
int bcj[maxn];
void init()
{
    for (int i = 1; i <= n; i++)
        bcj[i] = i;
}
int find(int x)
{
    if (bcj[x] == x)
        return x;
    return bcj[x] = find(bcj[x]);
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> e[i].a >> e[i].b >> e[i].v;
    init();
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        int ra = find(e[i].a), rb = find(e[i].b);
        if (ra != rb)
        {
            bcj[ra] = rb;
            ans += e[i].v;
            cnt++;
        }
    }
    if (cnt == n)
        cout << ans << endl;
    else
        cout << "impossible" << endl;
    return 0;
}