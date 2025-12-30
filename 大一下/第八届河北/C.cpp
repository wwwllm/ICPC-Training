#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
vector<array<int, 3>> a;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r, i});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> path;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j < n && a[j][0] <= ans)
            pq.push({a[j][1], a[j][2]}),j++;
        while (pq.size() &&pq.top().first < ans)
            pq.pop();
        if (pq.size())
        {
            ans++;
            path.push_back(pq.top().second);
            pq.pop();
        }
        else
            break;
    }
    cout << ans << endl;
    for (auto it : path)
    {
        cout << it << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}