#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x)
{
    return x & (-x);
}

const int N = 6e5 + 10;
int tr[N], n, q, a[N];
vector<array<int, 3>> arr;//询问数组
vector<int> b;//离散化数组
int st[N];

void add(int pos, int x)
{
    for (int i = pos; i <= N; i += lowbit(i))
        tr[i] += x;
}
int query(int l, int r)
{
    int sum = 0;
    for (int i = r; i; i -= lowbit(i))
        sum += tr[i];
    for (int i = l - 1; i; i -= lowbit(i))
        sum -= tr[i];
    return sum;
}
int find(int x)
{
    int l = -1, r = b.size() + 1, mid;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (b[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r + 1;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        b.push_back(x);
    }
    cin >> q;
    while (q--)
    {
        int op, a, c;
        cin >> op;
        if (op == 1 || op == 2)
        {
            cin >> a;
            arr.push_back({op, a, 0});
            b.push_back(a);
        }
        else
        {
            cin >> a >> c;
            arr.push_back({op, a, c});
            b.push_back(a), b.push_back(c);
        }
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++)
    {
        int pos = find(a[i]);//找到a[i]
        add(pos, a[i]);
        st[pos]++;
    }
    for (auto [op, a, b] : arr)
    {
        if (op == 1)
        {
            int pos = find(a);
            add(pos, a);
            st[pos]++;
        }
        else if (op == 2)
        {
            int pos = find(a);
            if(!st[pos])
                continue;
            add(pos, -a);
        }
        else
        {
            int posl = find(a), posr = find(b);
            int sum = query(posl, posr);
            cout << sum << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin>>t;
    while (t--)
        solve();
    return 0;
}