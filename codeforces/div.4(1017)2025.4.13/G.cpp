#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int tt;
    cin >> tt;
    deque<int> q;
    int ans = 0, sum = 0, flag = 0;
    while (tt--)
    {
        int op;
        cin >> op;
        if (op == 3)
        {
            int k;
            int cnt = q.size() + 1;
            cin >> k;
            ans += cnt * k;
            sum += k;
            if (flag)
                q.push_back(k);
            else
                q.push_front(k);
            cout << ans << endl;
        }
        else if (op == 1)
        {
            int an, cnt = q.size();
            if (flag)
            {
                an = q.back();
                q.pop_back();
                q.push_front(an);
            }
            else
            {
                an = q.front();
                q.pop_front();
                q.push_back(an);
            }
            ans = ans - cnt * an + sum;
            cout << ans << endl;
        }
        else
        {
            int cnt = q.size();
            flag = !flag;
            ans = sum * (cnt + 1) - ans;
            cout << ans << endl;
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