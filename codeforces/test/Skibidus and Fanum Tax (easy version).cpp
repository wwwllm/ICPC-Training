#include <bits/stdc++.h>
#define int long long
using namespace std;

// c=b-a
// d=a;
const int N = 2e5 + 10;
int a[N],b;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    cin >> b;
    a[n + 1] = 0x3f3f3f3f;
    for (int i = n; i >= 1;i--){
        if(a[i]<=a[i+1]){
            if(b-a[i]>a[i]&&b-a[i]<=a[i+1])
                a[i] = b - a[i];
        }else{
            if(b-a[i]>a[i+1]){
                cout << "NO" << endl;
                return;
            }else
                a[i] = b - a[i];
        }
    }
    cout << "YES" << endl;
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
