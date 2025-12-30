#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
char str[N];
int f(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
void solve()
{
    cin >> str + 1;
    int ans = 0;
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++)
        ans += str[i] - '0';
    while (ans >= 10)
    {
        ans = f(ans);
    }
    if (ans == 7)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}