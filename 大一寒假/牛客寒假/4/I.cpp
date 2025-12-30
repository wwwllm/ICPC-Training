#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50;
const string str = "uwawauwa";
char a[maxn];
int t1[maxn], t2[maxn];
bool check(int p)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (a[i + p] != str[i])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    memset(t1, 0, sizeof(t1));
    memset(t2, 0, sizeof(t2));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 'u')
        {
            t1[i] += t1[i - 1] + 1;
        }
        else
        {
            t1[i] = t1[i - 1];
        }
        if (check(i))
        {
            t2[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t2[i] == 1 && i > 2)
            ans += t1[i - 2];
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}