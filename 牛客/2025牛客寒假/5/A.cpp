#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    char c;
    int m;
    cin >> m >> c;
    if(c==43){
        cout << 1 << ' ' << m-1 << endl;
    }else if(c==42){
        cout << 1 << ' ' << m << endl;
    }else{
        cout << m + 1 << ' ' << 1 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
 //   cin >> t;
    while (t--)
        solve();
    return 0;
}