#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
map<int, int> d;
int n;
vector<int> g[N];
bool b[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
        d[a]++, d[b]++;
    }
    cout << 0 << endl;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 1)
            q.push(i), b[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto ele : g[u])
        {
            if (!b[ele])
            {
                d[ele]--;
                cout << ele << ' ' << u << endl;
                if (d[ele] == 1)
                {
                    q.push(ele);
                    b[ele] = 1;
                }
            }
        }
    }
    int cnt = 0, in = -1;
    for (auto [pos, num] : d)
    {
        if (!b[pos])
        {
            d[pos]--;
            in = pos;
            b[pos] = 1;
            q.push(pos);
            break;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto ele : g[u])
        {
            if (!b[ele] || (cnt > 1 && ele == in))
            {
                cout << ele << ' ' << u << endl;
                d[ele]--;
                q.push(ele);
                b[ele] = 1;
                cnt++;
                break;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}