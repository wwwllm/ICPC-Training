#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n + 1, "");
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        a[i] = op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
    }
    vector<int> cnt(n + 2, 0);
    for (int i = n; i >= 1; i--)
    {
        cnt[i] = a[i] == "Pop" ? cnt[i + 1] + 1 : cnt[i + 1];
    }
    deque<int> dq;
    ll sum = 0;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        string op = a[i];
        if (op == "Push")
        {
            int x;
            x = q.front();
            q.pop();
            dq.push_back(x);
            sum = (sum + (ll)x) % mod;
        }
        else if (op == "Pop")
        {
            int u = dq.back();
            dq.pop_back();
            sum = (sum - (ll)u + mod) % mod;
        }
        else
        {
            deque<int> temp = dq;
            while (!ok && dq.size() < cnt[i + 1] && temp.size())
            {
                int u = temp.back();
                dq.push_front(u);
                temp.pop_back();
            }
            if (dq.size() >= cnt[i + 1])
                ok = 1;
            sum = (sum * 2LL) % mod;
        }
        cout << sum << '\n';
    }
    return 0;
}