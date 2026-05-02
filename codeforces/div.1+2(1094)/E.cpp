#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    int ma = (1LL << n) - 1;
    auto query = [&](int x) -> int
    {
        cout << "Q " << x << endl;
        int res;
        cin >> res;
        return res;
    };
    auto insert = [&](int x) -> int
    {
        cout << "I " << x << endl;
        int cnt;
        cin >> cnt;
        return cnt;
    };
    auto answer = [&](int k, int c)
    {
        cout << "A " << k << ' ' << c << endl;
        return;
    };
    cout << 0 << endl;
    int cnt = insert(0);
    int op;
    if (cnt == 1)
        op = 1;
    else
    {
        cnt = insert(ma);
        if (cnt == 2)
        {
            cnt = insert(1);
            if (cnt == 2)
                answer(2, ma);
            else
                answer(3, ma);
            return;
        }
        cnt = query(ma);
        if (cnt == 1)
            op = 2;
        else
            op = 3;
    }
    auto find = [&](int l, int r, int cnt) -> int
    {
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (query(mid) < cnt)
                r = mid;
            else
                l = mid;
        }
        return l;
    };
    int ans;
    if (op == 1)
    {
        cnt = insert(ma);
        ans = find(0, ma + 1, 1);
    }
    else if (op == 2)
    {
        ans = find(0, ma, 2);
    }
    else
    {
        int u = find(ma >> 1, ma, 1);
        int v = ma - u;
        cnt = insert(u);
        if (cnt == 4)
            ans = v;
        else
            ans = u;
    }
    answer(op, ans);
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