#include <bits/stdc++.h>
using namespace std;

// 自动机：对信号序列进行判定的模型
// 在文章中找目标字符串出现次数
const int N = 2e5 + 10;
int tr[N][26], fi[N], ed[N], idx, cnt[N], ind[N], ans[N];
void insert(string str, int i)
{
    int p = 0;
    for (auto ele : str)
    {
        int u = ele - 'a';
        if (!tr[p][u])
            tr[p][u] = ++idx;
        p = tr[p][u];
    }
    ed[i] = p;
}
void setfile()
{
    queue<int> q;
    for (int i = 0; i <= 25; i++)
        if (tr[0][i])
            q.push(tr[0][i]), ind[0]++;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
            if (tr[u][i])
                fi[tr[u][i]] = tr[fi[u]][i], q.push(tr[u][i]), ind[fi[tr[u][i]]]++;
            else
                tr[u][i] = tr[fi[u]][i];
    }
}
void topu()
{
    queue<int> q;
    for (int i = 0; i <= idx; i++)
        if (!ind[i])
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        ans[u] += cnt[u];
        q.pop();
        int p = fi[u];
        ind[p]--;
        ans[p] += ans[u];
        if (!ind[p])
            q.push(p);
    }
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(s, i);
    }
    setfile();
    string str;
    cin >> str;
    int u = 0;
    for (auto it : str)
    {
        u = tr[u][it - 'a'];
        cnt[u]++;
    }
    topu();
    for (int i = 1; i <= n; i++)
        cout << ans[ed[i]] << endl;
    return 0;
}