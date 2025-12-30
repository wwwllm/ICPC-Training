#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(a[i]);
    for (int i = 2; i <= n; i++)
    {
        while (dq.front() != b[i])
        {
            cout << 1;
            int t = dq.front();
            dq.pop_front();
            dq.push_back(t);
        }
        while (dq.back() != b[i - 1])
        {
            cout << 2;
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            dq.push_back(b);
            dq.push_front(a);
        }
        cout << 1;
        int t = dq.front();
        dq.pop_front();
        dq.push_back(t);
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}