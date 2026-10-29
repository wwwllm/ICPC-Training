#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> PII;
void solve()
{
    priority_queue<PII, vector<PII>, greater<PII>> h1, h2;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c && d)
        {
            if (a < b)
                h1.push({a, i});
            else
                h2.push({b, i});
        }
        else if (c == 1)
            h1.push({a, i});
        else if (d == 1)
            h2.push({b, i});
    }
    cout << h1.size() << ' ';
    while (h1.size())
    {
        auto p = h1.top();
        cout << p.second << ' ';
        h1.pop();
    }
    cout << endl;
    cout << h2.size() << ' ';
    while (h2.size())
    {
        auto p = h2.top();
        cout << p.second << ' ';
        h2.pop();
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin>>t;
    while (t--)
        solve();
    return 0;
}