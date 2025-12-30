#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len - 1; i++)
        if (s[i] == s[i + 1])
            ans++;
    len += ans;
    if(s[0]=='i'){
        if(len&1)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }else{
        if(len&1)
            cout << ans + 1 << endl;
        else
            cout << ans + 2 << endl;
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