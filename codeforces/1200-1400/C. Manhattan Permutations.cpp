#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1978/C
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++)
        p[i] = i;
    for (int i = 1, j = n; i < j; i++)
    {
        if(k>=2*(j-i)){
            swap(p[i], p[j]);
            k -= 2 * (j - i);
            j--;
        }
        if(k==0)
            break;
    }
    if (k == 0)
    {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++)
            cout << p[i] << " \n"[i == n];
    }
    else
        cout << "No\n";
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