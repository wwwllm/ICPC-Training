#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SA
{
    int n;
    vector<int> sa, rk, lc;
    SA(string &s) : n(s.size()), sa(s.size()), rk(s.size()), lc(s.size() - 1)
    {
        ranges::iota(sa, 0);
        ranges::sort(sa, [&](int a, int b)
                     { return s[a] < s[b]; });
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i - 1]] != s[sa[i]]);
        }
        int k = 1;
        vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1)
        {
            tmp.clear();
            for (int i = 0; i < k; i++)
            {
                tmp.push_back(n - k + i);
            }
            for (auto i : sa)
            {
                if (i >= k)
                    tmp.push_back(i - k);
            }
            ranges::fill(cnt, 0);
            for (int i = 0; i < n; i++)
                cnt[rk[i]]++;
            for (int i = 1; i < n; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
            {
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }
            swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            }
            k <<= 1;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            if (rk[i] == 0)
                j = 0;
            else
            {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j];)
                {
                    j++;
                }
                lc[rk[i] - 1] = j;
            }
        }
    }
};
void solve()
{
    string s;
    cin >> s;
    SA sa(s);
    int &n = sa.n;
    for (int i = 0; i < n; i++)
    {
        cout << sa.sa[i] << " \n"[i == n - 1];
    }
    cout << 0 << ' ';
    for (int i = 0; i < n - 1; i++)
    {
        cout << sa.lc[i] << "  \n"[i == n - 2];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
