#include <bits/stdc++.h>
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
    for (int i = 0; i <= n; i++)
    {
        if (cnt[i])
            mex++;
        else
            break;
    }
    if (mex == 0 && k > 1)
    {
        cout << 0 << '\n';
        return;
    }
    if (k == 0)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        cout << sum << '\n';
        return;
    }
    while (k--)
    {
        int tmp = mex;
        vector<int> b(n + 2);
        int t = 0;
        for (int i = 0; i <= n + 1; i++)
        {
            if (cnt[i] == 1)
            {
                int res = min(i, mex);
                int c = cnt[i];
                cnt[i] = 0;

                b[res] += c;
            }
            else if (cnt[i] > 1)
            {
                int res = mex;
                int c = cnt[i];
                cnt[i] = 0;
                b[res] += c;
            }
        }
        cnt = b;
        int p = -1;
        for (int i = 0; i <= n + 1; i++)
        {
            if (cnt[i] != 1)
            {
                p = i;
                break;
            }
        }
        if (p = -1)
            break;
        if((cnt[p]==0&&cnt[p+1]!=0)||(cnt[p]!=0&&cnt[p+1]==0))
    }

    if (k & 1)
    {
        int sum = 0;
        for (int i = 0; i <= n + 1; i++)
        {
            if (cnt[i] == 1)
                sum += cnt[i] * i;
            else if (cnt[i] > 0)
            {
                if (cnt[i - 1] == 0)
                    sum += (i - 1) * cnt[i];
                else
                    sum += (i + 1) * cnt[i];
            }
        }
        cout << sum << '\n';
    }
    else
    {
        int sum = 0;
        for (int i = 0; i <= n + 1; i++)
            sum += cnt[i] * i;
        cout << sum << '\n';
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