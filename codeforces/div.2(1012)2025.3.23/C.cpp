#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> heap;
    int n;
    cin >> n;
    int x = 1, y = 1, d = 2;
    auto next = [&]()
    {
        if(y==1)
        {
            swap(x, y);
            y += 3;
        }
        else
            x += 3, y -= 3;
        d = x + y;
    };
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op && heap.size() && heap.top()[0] < d)
        {
            auto [dd, xx, yy] = heap.top();
            heap.pop();
            cout << xx << ' ' << yy << endl;
        }
        else
        {
            cout << x << ' ' << y << endl;
            heap.push({x + y + 1, x + 1, y});
            heap.push({x + y + 1, x, y + 1});
            heap.push({x + y + 4, x + 1, y + 1});
            next();
        }
    }
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