
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(n==0&&m==0){
        cout << "Yes" << endl;
        return;
    }else{
        if(n==0||m==0){
            cout << "No" << endl;
            return;
        }else{
            cout << "Yes" << endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}