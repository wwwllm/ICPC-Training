#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 55;
char arr[maxn], s[maxn];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == '(')
        {
            s[++top] = '(';
        }
        else
        {
            if (top == 0)
            {
                ans++;
            }
            else
            {
                top--;
            }
        }
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