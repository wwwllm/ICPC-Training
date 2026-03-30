#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>cnt(n);
    int p=0;
    while(n--){
        cnt[p]++;
        if(s[p]=='L'){
            p--;
        }
        else{
            p++;
        }
    }
    int res=0;
    for(auto c:cnt)
        if(c)res++;
    cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}