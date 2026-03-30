#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cur=a[1];
    int ans=1;
    for(int i=2;i<=n;i++){
        if(cur<=a[i]){
            ans++;
            cur=a[i];
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}