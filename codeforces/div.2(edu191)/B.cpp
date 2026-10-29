    #include <bits/stdc++.h>
    #define int long long
    using namespace std;

    void solve()
    {
        int n;
        cin >> n;
        int p = 1;
        for (int i = 1; i <= n; i += 2)
        {
            if ((n % 2 == 1) && (i == n - 2))
            {
                cout << i << ' ' << i << ' ' << i + 1 << ' ' << i << ' ' << i + 1 << ' ' << i + 2 << ' ' << i << ' ' << i + 2 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 2 << ' ' << i + 2 << ' ';
                break;
            }
            else
                cout << i << ' ' << i + 1 << ' ' << i + 1 << ' ' << i << ' ' << i << ' ' << i + 1 << ' ' << i << ' ' << i + 1 << ' ';
        }
        cout << '\n';
    }
    signed main()
    {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t = 1;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }