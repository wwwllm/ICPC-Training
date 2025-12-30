#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto it:s){
        if(it=='1')
            cnt++;
    }
    int ans = cnt * (n - 1) + n - cnt;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}