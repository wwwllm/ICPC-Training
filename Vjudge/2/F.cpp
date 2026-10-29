#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll t1=0, t2=0;
    while(n%3==0){
        n /= 3;
        t1++;
    }
    while(n%2==0){
        n /= 2;
        t2++;
    }
    if(n==1){
        if(t2>t1){
            cout << -1 << endl;
        }else{
            cout << t1 * 2 - t2 << endl;
        }
    }
    else{
        cout << -1 << endl;
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