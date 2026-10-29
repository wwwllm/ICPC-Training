#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r, x,a,b;
    cin >> l >> r >> x;
    cin >> a >> b;
    if(a>b){
        swap(a, b);
    }
    if(b==a){
        cout << 0 << endl;
        return;
    }
    if((a-l<x&&r-a<x)||(b-l<x&&r-b<x)){
        cout << -1 << endl;
        return;
    }
    if(b-a>=x){
        cout << 1 << endl;
        return;
    }else{
        if(a-l>=x){
            cout << 2 << endl;
        }else{
            if(r-b>=x){
                cout << 2 << endl;
            }else{
                cout << 3 << endl;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
