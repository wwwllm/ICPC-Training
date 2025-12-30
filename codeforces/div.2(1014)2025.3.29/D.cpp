#include <bits/stdc++.h>
using namespace std;

const int N = 200, tot = 'L' ^ 'I' ^ 'T';
int cnt[N], a[N];
void solve()
{
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vector<int> ans;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = x;
        cnt[x]++;
        if (i > 1 && a[i] != a[i - 1])
            ok = 1;
    }
    if (!ok)
        cout << -1 << endl;
    else
    {
        if (cnt['L'] == cnt['I'] && cnt['I'] == cnt['T'])
        {
            cout << 0 << endl;
            return;
        }
        for (int i = 1; i <= n - 1; i++)
        {
            if (a[i] == a[i + 1])
                continue;
            int x = a[i], y = a[i + 1], z = tot ^ a[i] ^ a[i + 1];
            int pos = i;
            cnt[z]++;
            ans.push_back(pos);
            while (cnt[x] != cnt[y] || cnt[x] != cnt[z] || cnt[y] != cnt[z])
            {
                if (cnt[x] > cnt[y])
                    ans.push_back(pos), cnt[y]++, swap(y, z);
                else
                    ans.push_back(++pos), cnt[x]++, swap(x, z);
            }
            break;
        }
        cout << ans.size() << endl;
        for (auto v : ans)
            cout << v << endl;
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