#include <bits/stdc++.h>
#define int long long
using namespace std;

//a,b,x
//x=a+b-1
const int maxn = 2e5 + 10;
int a[maxn];
void solve()
{
    int n;
    cin >> n;
    if(n==1){
        int x;
        cin >> x;
        cout << x << endl;
        return;
    }
    int sum=0;
    for (int i = 1; i <= n;i++)
        cin >> a[i],sum+=a[i];
    sum -= n-1;
    cout << sum << endl;
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
