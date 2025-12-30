#include <bits/stdc++.h>
using namespace std;

const vector<int> a = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};
bool cmp(vector<int> &b)
{
    for (auto it : b)
        if (it > 0)
            return 0;
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> temp = a;
    bool flag = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        temp[x]--;
        if (cmp(temp) && !flag)
        {
            ans = i;
            flag = 1;
        }
    }
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