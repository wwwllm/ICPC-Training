#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mex = 0;
    for (int i = 0; i <= n + 1; i++)
    {
        if (cnt[i] == 0)
        {
            mex = i;
            break;
        }
    }
    if (k == 0)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        cout << sum << '\n';
        return;
    }
    if (k <= 100)
    {
        while (k--)
        {
            vector<int> tmp(n + 2);
            for (int i = 0; i <= n + 1; i++)
            {
                if (cnt[i] == 1)
                {
                    int res = min(mex, i);
                    tmp[res] += cnt[i];
                }
                else if (cnt[i] > 1)
                {
                    int res = mex;
                    tmp[res] += cnt[i];
                }
            }
            cnt = tmp;
            for (int i = 0; i <= n + 1; i++)
            {
                if (!cnt[i])
                {
                    mex = i;
                    break;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n + 1; i++)
            sum += cnt[i] * i;
        cout << sum << endl;
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            vector<int> tmp(n + 2);
            for (int i = 0; i <= n + 1; i++)
            {
                if (cnt[i] == 1)
                {
                    int res = min(mex, i);
                    tmp[res] += cnt[i];
                }
                else if (cnt[i] > 1)
                {
                    int res = mex;
                    tmp[res] += cnt[i];
                }
            }
            cnt = tmp;
            for (int i = 0; i <= n + 1; i++)
            {
                if (!cnt[i])
                {
                    mex = i;
                    break;
                }
            }
        }
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i <= n + 1; i++)
            sum1 += cnt[i] * i;

        vector<int> tmp(n + 2);
        for (int i = 0; i <= n + 1; i++)
        {
            if (cnt[i] == 1)
            {
                int res = min(mex, i);
                tmp[res] += cnt[i];
            }
            else if (cnt[i] > 1)
            {
                int res = mex;
                tmp[res] += cnt[i];
            }
        }
        cnt = tmp;
        for (int i = 0; i <= n + 1; i++)
            sum2 += cnt[i] * i;

        if ((k - 1000) % 2 == 1)
            cout << sum2 << endl;
        else
            cout << sum1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}