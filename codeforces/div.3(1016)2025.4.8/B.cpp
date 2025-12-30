#include<bits/stdc++.h>
using namespace std;

string n;
void solve()
{
    cin >> n;
    int len = n.length();
    int ans = 0, pos = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (n[i] == '0')
            ans++;
        else
        {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < pos; i++)
        if (n[i] != '0')
            ans++;
    cout << ans << endl;
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