#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
string s = "CWP";
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, -1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'C')
            a[i] = 0;
        else if (c == 'W')
            a[i] = 1;
        else
            a[i] = 2;
    }
    vector<int> pre(n + 2);
    vector<array<int, 3>> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (a[i] == a[i + 1]);
        cnt[i] = cnt[i - 1];
        cnt[i][a[i]]++;
    }
    if (pre[n] == 0)
    {
        cout << "Beautiful\n";
        return;
    }
    int pos = -1, len = n + 1;
    auto check = [&](int l, int r) -> bool
    {
        int c = l <= 2 ? 0 : pre[l - 2];
        c += pre[n] - pre[r];
        if (c != 0)
            return 0;
        array<int, 3> num;
        for (int i = 0; i < 3; i++)
        {
            num[i] = cnt[r][i] - cnt[l - 1][i];
        }
        if (ranges::count(num, 0) == 2)
        {
            return 0;
        }
        else if (ranges::count(num, 0) == 1)
        {
            vector<int> ord{0, 1, 2};
            ranges::sort(ord, [&](int x, int y)
                         { return num[x] > num[y]; });
            int u = ord[0], v = ord[1];
            if (num[u] == num[v])
            {
                if (a[l - 1] == a[r + 1] && (a[l - 1] == u || a[l - 1] == v))
                {
                    return 0;
                }
                return 1;
            }
            else if (num[u] == num[v] + 1)
            {
                if (a[l - 1] == u || a[r + 1] == u)
                {
                    return 0;
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            vector<int> ord{0, 1, 2};
            ranges::sort(ord, [&](int x, int y)
                         { return num[x] > num[y]; });
            int x = ord[0], y = ord[1], z = ord[2];
            int L = r - l + 1;
            if (L & 1)
            {
                if (num[x] > (L + 1) / 2)
                {
                    return 0;
                }
                else if (num[x] == (L + 1) / 2)
                {
                    if (a[l - 1] == x || a[r + 1] == x)
                    {
                        return 0;
                    }
                    return 1;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                if (num[x] > L / 2)
                {
                    return 0;
                }
                else if (num[x] == L / 2)
                {
                    if (a[l - 1] == x && a[r + 1] == x)
                    {
                        return 0;
                    }
                    return 1;
                }
                else
                {
                    return 1;
                }
            }
        }
    };
    auto check_l = [&](int L) -> bool
    {
        for (int i = 1; i <= n; i++)
        {
            int j = i + L - 1;
            if (j > n)
                break;
            if (check(i, j))
            {
                if (L < len)
                {
                    len = L, pos = i;
                }
                return 1;
            }
        }
        return 0;
    };
    int lo = 0, hi = n + 1;
    while (lo + 1 != hi)
    {
        int mid = lo + hi >> 1;
        if (check_l(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (pos == -1)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << "Possible\n";
        cout << pos << ' ' << pos + len - 1 << '\n';
        int l = pos, r = pos + len - 1;
        {
            auto can = [&](array<int, 3> num, int l, int r) -> bool
            {
                if (ranges::count(num, 0) == 3)
                    return a[l - 1] != a[r + 1];
                if (ranges::count(num, 0) == 2)
                {
                    int c = 0;
                    while (num[c] == 0)
                        c++;
                    if (num[c] != 1)
                        return 0;

                    return a[l - 1] != c && a[r + 1] != c;
                }
                else if (ranges::count(num, 0) == 1)
                {
                    vector<int> ord{0, 1, 2};
                    ranges::sort(ord, [&](int x, int y)
                                 { return num[x] > num[y]; });
                    int u = ord[0], v = ord[1];
                    if (num[u] == num[v])
                    {
                        if (a[l - 1] == a[r + 1] && (a[l - 1] == u || a[l - 1] == v))
                        {
                            return 0;
                        }
                        return 1;
                    }
                    else if (num[u] == num[v] + 1)
                    {
                        if (a[l - 1] == u || a[r + 1] == u)
                        {
                            return 0;
                        }
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    vector<int> ord{0, 1, 2};
                    ranges::sort(ord, [&](int x, int y)
                                 { return num[x] > num[y]; });
                    int x = ord[0], y = ord[1], z = ord[2];
                    int L = r - l + 1;
                    if (L & 1)
                    {
                        if (num[x] > (L + 1) / 2)
                        {
                            return 0;
                        }
                        else if (num[x] == (L + 1) / 2)
                        {
                            if (a[l - 1] == x || a[r + 1] == x)
                            {
                                return 0;
                            }
                            return 1;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        if (num[x] > L / 2)
                        {
                            return 0;
                        }
                        else if (num[x] == L / 2)
                        {
                            if (a[l - 1] == x && a[r + 1] == x)
                            {
                                return 0;
                            }
                            return 1;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                }
            };
            array<int, 3> num;
            for (int c = 0; c < 3; c++)
                num[c] = cnt[r][c] - cnt[l - 1][c];

            for (int i = l; i <= r; i++)
            {
                for (int c = 0; c < 3; c++)
                {
                    if (num[c] == 0 || c == a[i - 1])
                        continue;

                    num[c]--;
                    a[i] = c;
                    if (can(num, i + 1, r))
                    {
                        break;
                    }

                    num[c]++;
                    a[i] = -1;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                cout << s[a[i]];
            }
            cout << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}