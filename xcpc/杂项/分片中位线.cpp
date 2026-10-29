#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128;
void solve(int pid)
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> sum;
    auto calc = [&](int x) -> int
    {
        int pos = ranges::upper_bound(a, x) - a.begin();
        return pos;
    };
    if (pid != 0)
    {
        char op;
        int x;
        while (cin >> op)
        {
            cin >> x;
            if (op == '?')
            {
                cout << calc(x) << endl;
            }
            else if (op == '!')
            {
                cout << x << endl;
                break;
            }
        }
    }
    else
    {
        auto query = [&](int x)
        {
            cout << "? " << x << endl;
            char op;
            int y;
            cin >> op >> y;
            cout << calc(y) << endl;
            int cnt;
            cin >> cnt;
            return cnt;
        };
        i128 l = (i128)LLONG_MIN - 1, r = (i128)LLONG_MAX + 1;
        while (l + 1 != r)
        {
            int mid = (int)(l + r >> 1);
            if (query(mid) >= (sum + 1) / 2)
                r = mid;
            else
                l = mid;
        }
        cout << "! " << (int)r << endl;
        char op;
        int x;
        cin >> op >> x;
        cout << x << endl;
    }
}
signed main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int pid = atoi(argv[1]);
    solve(pid);
}