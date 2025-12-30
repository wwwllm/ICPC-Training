#include <bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}
struct BIT
{
    vector<int> tr;
    int cnt = 0, N = 0;
    void add(int pos, int n)
    {
        for (int i = pos; i <= N; i += lowbit(i))
            tr[i] += n;
    }
    int query(int l)
    {
        int ans = 0;
        for (int i = l; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    }
    BIT(int n, vector<int> a)
    {
        tr.assign(n + 1, 0);
        N = n;
        int p = 0;
        for (auto it : a)
        {
            int num = query(it);
            cnt += p - num;
            p++;
            add(it, 1);
        }
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), a1, a2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i & 1)
        {
            a2.push_back(a[i]);
        }
        else
            a1.push_back(a[i]);
    }
    BIT tr1(n, a1);
    BIT tr2(n, a2);
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    vector<int> ans(n);
    for (int i = 0; i < a1.size(); i++)
    {
        ans[2 * i] = a1[i];
    }
    for (int i = 0; i < a2.size(); i++)
    {
        ans[2 * i + 1] = a2[i];
    }
    if (!((tr1.cnt & 1) == (tr2.cnt & 1)))
        swap(ans[n - 1], ans[n - 3]);
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
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