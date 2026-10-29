#include <bits/stdc++.h>
#define int long long

using namespace std;

int lowbit(int x) { return x & -x; }
const int N = 1e5 + 10;
int a[N], d[N];
int tr[3 * N], ans = 0;
vector<int> b;
void add(int pos, int x)
{
    for (int i = pos; i < 3 * N; i += lowbit(i))
        tr[i] += x;
}
int query(int x)
{ // 求小于等于x
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tr[i];
    return ans;
}
int find(int x)
{
    int l = -1, r = b.size();
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (b[mid] >= x)
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
        cin >> a[i], b.push_back(a[i]);
    int top = 0;
    while (q--)
    {
        int x;
        cin >> x;
        d[++top] = x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        ans += i - 1 - query(pos);
        add(pos, 1);
    }
    cout << ans << endl;
    for (int i = 1; i <= top; i++)
    {
        int pos = lower_bound(b.begin(), b.end(), d[i]) - b.begin() + 1;
        ans += n - query(pos);
        add(pos, 1);
        n++;
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    //	cin>>t;
    while (t--)
        solve();
    return 0;
}