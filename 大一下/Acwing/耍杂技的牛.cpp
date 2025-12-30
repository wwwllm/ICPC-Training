#include<bits/stdc++.h>
using namespace std;

typedef pair<int ,int> PII;
const int N=1e5+10;
int n;
PII a[N];
int w[N];
bool cmp(PII a,PII b){
    return a.first + a.second < b.first + b.second;
}
signed main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int w,s;
        cin>>w>>s;
        a[i] = {w, s};
    }
    sort(a+1,a+1+n,cmp);
    int ans = -2e9;
    for(int i=1;i<=n;i++)
        w[i] = w[i - 1] + a[i].first,ans=max(w[i-1]-a[i].second,ans);
    cout << ans << endl;
    return 0;
}