#include <bits/stdc++.h>
using namespace std;

// 字典树(trie树)：高效存储和查找字符串集合的数据结构
//可以用广搜统计总结点数
const int maxn = 1e5 + 10;
char str[maxn];
int son[maxn][26], cnt[maxn], idx; // 下标是0的点，既是根节点又是空节点
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op;
        cin >> op >> str;
        if (op == 'I')
            insert(str);
        else
            cout << query(str) << endl;
    }
    return 0;
}