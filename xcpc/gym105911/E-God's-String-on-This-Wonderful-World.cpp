#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105911/problem/E
const int inf =1e9;
int len=600;
struct Q
{
    int l,r,idx;
    bool operator <(const Q &a)const{
		int i=l/len,j=a.l/len;
		return i!=j?i<j:i&1?a.r<r:r<a.r;
	}
};
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    string s;
    cin>>s;
    s=' '+s;
    vector<int>a(26,0);
    map<vector<int>,int>mp;
    vector<int>pos(n+1);
    int m=0;
    mp[a]=m++;
    pos[0]=mp[a];
    for(int i=1;i<=n;i++){
        a[s[i]-'a']++;
        a[s[i]-'a']%=k;
        if(mp.count(a)){
            pos[i]=mp[a];
            continue;
        }
        mp[a]=m++;
        pos[i]=mp[a];
    }
    vector<int>cnt(m,0);
    
    int res=0;
    auto add=[&](int x){
        res+=cnt[pos[x]];
        cnt[pos[x]]++;
    };
    auto del=[&](int x){
        cnt[pos[x]]--;
        res-=cnt[pos[x]];
    };
    int p=0;
    vector<Q>qu(q);
    for(auto &[l,r,idx]:qu){
        cin>>l>>r;
        l--;
        idx=p++;
    }
    sort(qu.begin(),qu.end());
    vector<int>ans(q);
    int l=1,r=0;
    for(auto [L,R,idx]:qu){
        while(l>L)add(--l);
        while(l<L)del(l++);
        while(r>R)del(r--);
        while(r<R)add(++r);
        ans[idx]=res;
    }
    for(auto x:ans)cout<<x<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}