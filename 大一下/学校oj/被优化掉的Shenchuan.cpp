#include <bits/stdc++.h>
#define int long long
using namespace std;

// a2=a1+a3+(a5-a4)+(a7-a6)……
const char p[11] = " shenchuan";
const int N = 1e6 + 10;
char s[N];
int ans[N], top, ne[N];
void solve()
{
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 2, j = 0; i <= 9; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == 9)
        {
            ans[++top] = i - 9;
            j = ne[j];
        }
    }
    cout << top << endl;
    for (int i = 1; i <= top; i++)
    {
        cout << ans[i] << ' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}
