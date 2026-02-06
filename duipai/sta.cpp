#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
typedef pair<int,int> PII;
const int N=5e5+5;
int n,k,a[N];
bool check(int T){
    if(T==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]>0)cnt++;
        }
        return cnt<=k;
    }
    int cnt=0,pre=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0)continue;
        cnt++;
        int res=T-1;
        int ind=max(pre,i+a[i]);
        int j=i,ne=ind;
        while(1){
            while(j+1<=ind){
                j++;
                if(j>n){
                    return cnt<=k;
                }
                ne=max(ne,j+a[j]);
            }
            if(ne==ind)break;
            if(res==0)break;
            res--;
            ind=ne;
        }
        pre=ne;
        i=j;
    }
    return cnt<=k;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    int ans=l;
    if(ans>n)ans=-1;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }
}