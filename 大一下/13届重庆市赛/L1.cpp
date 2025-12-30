#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
const int N = 4e5 + 10;
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
    vector<int> s(N);
    int idx = 0;
    ll sum = 0;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        string op = a[i];
        if (op == "Push")
        {
            int x = q.front();
            q.pop();
            s[++idx] = x;
            sum = (sum + x) % mod;
        }
        else if (op == "Pop")
        {
            sum = (sum - s[idx--] + mod) % mod;
        }
        else
        {
            int num = idx;
            for (int i = 1; !ok && i <= num; i++)
            {
                s[++idx] = s[i];
            }
            if (idx >= cnt[i + 1])
                ok = 1;
            sum = (sum * 2) % mod;
        }
        cout << sum << '\n';
    }
    return 0;
}