#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    auto Sum=[&](int x){
        int ans=0;
        while(x>0){
            ans+=x%10;
            x/=10;
        }
        return ans;
    };
    auto f=[&](int x)->string{
        string res="";
        while(x>9){
            res+=to_string(x);
            x=Sum(x);
        }
        res+=to_string(x);
        return res;
    };
    if(s.size()==1){
        cout<<s<<'\n';
        return ;
    }
    int r=0;
    for(auto c:s){
        r+=c-'0';
    }
    r=max(r,200);
    int l=max(1,r-200);
    vector<int>cnt(10);
    for(auto c:s){
        cnt[c-'0']++;
    }
    for(int i=l;i<=r;i++){
        string res=f(i);
        bool ok=1;
        auto ncnt=cnt;
        for(auto c:res){
            ncnt[c-'0']--;
        }
        int tmp=0;
        for(int i=0;i<10;i++){
            if(ncnt[i]<0)
                ok=0;
            tmp+=i*ncnt[i];
        }
        if(tmp==i&&ok){
            string ans="";
            for(int i=9;i>=0;i--){
                while(ncnt[i]){
                    ans+=to_string(i);
                    ncnt[i]--;
                }
            }
            ans+=res;
            cout<<ans<<'\n';
            return ;
        }
    }
    cout<<-1<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}