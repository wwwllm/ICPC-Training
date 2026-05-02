#include<bits/stdc++.h>
#define int long long
using namespace std;

int Lcm(int a,int b,int lim){
    if(a==0||b==0)return 0;
    int g=gcd(a,b);
    int res=a/g;
    if (__builtin_mul_overflow(res, b, &res) || res > lim) {
        return lim + 7;
    }
    return res;
}
void solve(){
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    int ab=Lcm(a,b,m);
    int ac=Lcm(a,c,m);
    int bc=Lcm(b,c,m);
    int abc=Lcm(ac,bc,m);
    int ansa=6*(m/a)-3*(m/ab)-3*(m/ac)+2*(m/abc);
    int ansb=6*(m/b)-3*(m/ab)-3*(m/bc)+2*(m/abc);
    int ansc=6*(m/c)-3*(m/ac)-3*(m/bc)+2*(m/abc);

    cout<<ansa<<' '<<ansb<< ' '<<ansc<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}