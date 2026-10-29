#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct Range
{
    int l, r;
    bool operator<(const Range &M) const
    {
        return l < M.l;
    }
} range[N];
int n, st, ed;
signed main()
{
    cin >> st >> ed;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> range[i].l >> range[i].r;
    sort(range + 1, range + 1 + n);
    int ans = 0;
    bool flag = 0;
    for (int i = 1; i <= n;)
    {
        int j = i, r = -2e9;
        while (j <= n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j++;
        }
        ans++;
        if (r < st)
        {
            ans = -1;
            break;
        }
        if (r >= ed)
        {
            flag = 1;
            break;
        }
        st = r;
        i = j;
    }
    if(!flag)
        ans = -1;
    cout << ans << endl;
    return 0;
}