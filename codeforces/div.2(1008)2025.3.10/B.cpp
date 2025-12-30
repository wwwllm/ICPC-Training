#include <bits/stdc++.h>
#define ll long long
using namespace std;

//k=1:n,n,n,n……,n-1
//k=2:n-1,n-1,n-1,n-1……n,n-1
//
const int maxn = 2e5 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    if(k&1){
        for (int i = 1; i <= n - 2;i++)
            cout << n << ' ';
        cout << n << ' ' << n - 1 << endl;
    }else {
        for (int i = 1; i <= n - 2; i++)
            cout << n-1 << ' ';
        cout << n << ' ' << n - 1 << endl;
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