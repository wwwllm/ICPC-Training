#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,vector<array<int,2>>>mp;
    for(int i=0;i<n;i++){
        int id=i+1,x,y;
        cin>>x>>y;
        mp[x].push_back({y,id});
    }
    for(auto &[x,aa]:mp)ranges::sort(aa,greater<array<int,2>>());
    vector<int>ans;
    auto check=[&](int cnt)->bool{
        ans.clear();
        for(auto [x,aa]:mp){
            int tmp=aa.size();
            while(aa.size()&&tmp+aa.back()[0]<cnt){
                aa.pop_back();
                tmp--;
            }
            if(cnt<=tmp){
                for(int i=0;i<cnt;i++){
                    ans.push_back(aa[i][1]);
                }
                return 1;
            }
            cnt-=tmp;
            for(auto [y,id]:aa){
                ans.push_back(id);
            }
        }
        return cnt<=0;
    };
    int l=0,r=n+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    check(l);
    cout<<l<<'\n';
    for(auto x:ans)cout<<x<<' ';
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}