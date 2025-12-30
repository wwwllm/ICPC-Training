#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 50;
string as, bs, cs;
int s[4] = {0},a[maxn],b[maxn],c[maxn];
void solve()
{
    int n, x, y;
    memset(s, 0, sizeof(s));
    int ans = 0;
    cin >> n >> x >> y;
    cin >> as >> bs >> cs;
    for (int i = 1; i <= n; i++)
    {
        a[i] = as[i - 1] - '0';
        b[i] = bs[i - 1] - '0';
        c[i] = cs[i - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        if ((a[i] ^ b[i]) != c[i])
        {
            s[a[i] * 2 + b[i]]++;
        }
    }
    int sum = s[0] + s[1] + s[2] + s[3],sumx=0,sumy=0;
    sort(s, s + 4);
    if (s[3] * 2 > sum)
    {
        sumx = s[3] * 2 - sum;
        sumy = (sum - sumx) / 2;
    }
    else
    {
        sumy = sum / 2;
        sumx = sum % 2;
    }
    if (x * 2 <= y)
    {
        cout << sum * x << endl;
    }
    else
    {
        cout << sumx * x + sumy * y << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
        solve();
    return 0;
}