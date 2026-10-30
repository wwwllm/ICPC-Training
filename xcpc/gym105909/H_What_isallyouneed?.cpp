#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string suf = s.substr(n - 12);
    if (suf == "isallyouneed")
    {
        cout << "Yes\n";
        for (int i = 0; i <= n - 13; i++)
            cout << s[i];
        cout << '\n';
    }
    else
        cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}