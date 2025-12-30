#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int maxn = 3e5 + 10;
int a[maxn], n, m;
vector<int> all;
vector<PII> add, q;
int find(int x)
{
    int l = -1, r = all.size(), mid;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (all[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        q.push_back({l, r});

        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end()); // 去重
    for (auto it : add)
    {
        int x = find(it.first);
        a[x] += it.second;
    }
    for (int i = 1; i <= all.size(); i++)
        a[i] += a[i - 1];
    for (auto it : q)
    {
        int l = find(it.first), r = find(it.second);
        cout << a[r] - a[l - 1] << endl;
    }
    return 0;
}