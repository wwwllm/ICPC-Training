#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
int a[maxn], ta, b[maxn], tb,c[maxn],tc;
void solve()
{
    int n, k;
    cin >> n >> k;
    ta = 0, tb = 0, tc = 0;
    for (int i = 1; i <= n; i++)
    {
        int tim, ai, bi;
        cin >> tim >> ai >> bi;
        if (ai == 0 && bi == 0)
            continue;
        else if(ai==0&&bi==1){
            b[++tb] = tim;
        }else if(ai==1&&bi==0){
            a[++ta] = tim;
        }else{
            c[++tc] = tim;
        }
           
    }
    int ans = 0;
    sort(a + 1, a + 1 + ta);
    sort(b + 1, b + 1 + tb);
    for (int i = 1; i <= min(ta, tb);i++){
        c[++tc] = a[i] + b[i];
    }
    if(tc<k){
        cout << -1 << endl;
    }else{
        sort(c + 1, c + 1 + tc);
        for (int i = 1; i <= k;i++){
            ans += c[i];
        }
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
        solve();
    return 0;
}