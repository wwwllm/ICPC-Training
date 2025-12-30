#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    vector<int> t(20);
    cin >> s;
    for(auto it:s){
        int u = it - '0';
        t[u]++;
    }
    for (int i = 9; i >=0;i--){
        int k = i;
        while(!t[k])
            k++;
        cout << k;
        t[k]--;
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}