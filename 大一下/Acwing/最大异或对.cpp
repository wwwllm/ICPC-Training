#include <bits/stdc++.h>
using namespace std;

// 字典树(trie树)：高效存储和查找字符串集合的数据结构

const int maxn = 1e5 + 10;
int son[maxn * 32][2], idx, a[maxn]; // 下标是0的点，既是根节点又是空节点
void insert(int x)
{
    int p = 0;
    for (int i = 31; i >= 0; i--)
    {
        int u = (x >> i) & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int u = (x >> i) & 1;
        if (son[p][!u])
        { // 如果可以走到不同的异或后这一位为一
            res = res * 2 + !u;
            p = son[p][!u];
        }
        else
        {
            res = res * 2 + u;
            p = son[p][u];
        }
    }
    return res ^ x;
}
signed main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}