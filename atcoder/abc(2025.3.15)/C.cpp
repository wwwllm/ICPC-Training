#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int a[N],st[N];
int t[N],ansl[N],t2[N],ansr[N];
void solve()
{
    int cnt = 0,n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        st[a[i]]++;
        if(st[a[i]]>1)
            cnt++;
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        t[a[i]]++;
        if(t[a[i]]>1)
            res++;
        ansl[i] = i - res;
    }
    res = 0;
    for (int i = n; i >= 1;i--){
        t2[a[i]]++;
        if(t2[a[i]]>1)
            res++;
        ansr[i] = n - i + 1 - res;
    }
    int ans = 0;
    for (int i = 1; i <= n-1;i++)
        ans = max(ansl[i] + ansr[i+1], ans);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}