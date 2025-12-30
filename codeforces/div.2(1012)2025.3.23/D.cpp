#include <bits/stdc++.h>
using namespace std;

//(贝特朗公设)： 对于每个正整数 x，在区间[x, 2x] 内有一个素数 p。
//在[n/3,2*n/3]中找一个素数p使得前i项平均数都为p
bool is_prime(int x)
{
    if(x==0||x==1)
        return 0;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    int l = n / 3;
    int r = (n*2+2)/3;
    int p;
    for (int i = l; i <= r; i++)
        if (is_prime(i))
        {
            p = i;
            break;
        }
    vector<int> ans;
    ans.push_back(p);
    int k = 1;
    while (k < p)
    {
        ans.push_back(p - k);
        if(p+k<=n)ans.push_back(p + k);
        k++;
    }
    for (int i = p + k; i <= n; i++)
        ans.push_back(i);
    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
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