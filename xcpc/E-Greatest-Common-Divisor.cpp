    #include<bits/stdc++.h>
    #define int long long
    using namespace std;

    //https://codeforces.com/gym/105930/problem/E
    const int N=1e6;
    void solve(){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>pre(N+1);
        int sum=0;
        for(auto &x:a)cin>>x,sum+=x,pre[x]++;
        int ma=*ranges::max_element(a);
        for(int i=1;i<=N;i++){
            pre[i]+=pre[i-1];
        }
        int ans=0;
        auto check=[&](int x)->bool{
            int cnt=0;
            if(x>ma){
                cnt=x*n-sum;
            }
            else{
                int j=1;
                while(1){
                    int l=(j-1)*x,r=min(j*x,ma);
                    cnt+=(pre[r]-pre[l])*j*x;
                    if(r==ma)break;
                    j++;
                }
                cnt-=sum;
            }
            return cnt<=k&&(k-cnt)%x==0;
        };
        int m=sum+k;
        for(int i=1;i<=m/i;i++){
            if(m%i==0){
                int u=i,v=m/i;
                if(check(u))ans=max(u,ans);
                if(check(v))ans=max(ans,v);
            }
        }
        cout<<ans<<'\n';
    }
    signed main(){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int t;
        cin>>t;
        while(t--)solve();
        return 0;
    }