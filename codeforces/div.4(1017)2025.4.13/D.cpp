#include<bits/stdc++.h>
using namespace std;

void solve(){
    string p;
    string s;
    cin >> p >> s;
    int n = p.length(),m=s.length();
    if(n*2<m||n>m||p[0]!=s[0]){
        cout << "NO" << endl;
        return;
    }
    int i, j;
    for (i = 0, j = 0;i<n&&j<m;){
        int ii = i,jj=j;
        while(p[ii]==p[i]&&ii<n)
            ii++;
        while(s[jj]==s[j]&&jj<m)
            jj++;
        int leni = ii - i, lenj = jj - j;
        if(leni*2<lenj||leni>lenj){
            cout << "NO" << endl;
            return;
        }
        i = ii, j = jj;
    }
    if(i==n&&j==m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}