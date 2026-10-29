#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
PII p[N];
vector<array<int, 3>> qu;
int ans[N];
vector<int> a;
int tr[2 * N];
int lowbit(int x)
{
    return x & -x;
}
void add(int pos, int x)
{
    for (int i = pos; i <= N*2; i += lowbit(i))
        tr[i] += x;
}
int query(int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
int find(int x)
{
    int l = -1, r = a.size();
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r + 1;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {y, x};
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= q; i++)
    {
        int h, k;
        cin >> h >> k;
        qu.push_back({h, k, i});
    }
    sort(qu.begin(), qu.end(), [](const array<int, 3> &a, const array<int, 3> &b)
         { return a[0] < b[0]; });
    int i = 1;
    for (auto [h, k, pos] : qu)
    {
        while (p[i].first <= h && i <= n)
        {
            int posx = find(p[i].second);
            add(posx, 1);
            i++;
        }
        if (query(N) < k)
        {
            ans[pos] = -1;
        }
            else
            {
                int l = 0, r = a.size() + 1;
                while (l + 1 != r)
                {
                    int mid = l + r >> 1;
                    if (query(mid) >= k)
                        r = mid;
                    else
                        l = mid;
                }
                ans[pos] = a[r - 1];
            }
    }
    for (int i = 1; i <= q; i++)
    {
        if (ans[i] == -1)
            cout << "CKW_QAQ" << endl;
        else
            cout << ans[i] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}