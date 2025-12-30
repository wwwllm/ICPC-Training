#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int n1=0, n2=0;
    for (int i = 0; i < n - 1;i++){
        if(s[i]=='>')
            n1++;
        else
            n2++;
    }
    cout << n - n1 << ' ';
    for (int i = 0; i < n - 1;i++){
        if(s[i]=='>'){
            n1--;
            cout <<n- n1 << ' ';
        }else{
            cout << n2 << ' ';
            n2--;
        }
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