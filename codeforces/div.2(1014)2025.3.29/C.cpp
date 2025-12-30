#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
void solve(){
    int n;
    cin >> n;
    int maxx = -1;
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        sum += x;
        if(x&1)
            cnt++;
        maxx = max(x, maxx);
    }
    if(cnt==n||cnt==0)
        cout << maxx << endl;
    else
        cout << sum - cnt + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}