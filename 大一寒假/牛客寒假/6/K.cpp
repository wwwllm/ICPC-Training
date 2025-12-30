#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if(y%2==0){
        cout << "NO" << endl;
        return;
    }
    int b = y / 2;
    if(b%2==x%2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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
