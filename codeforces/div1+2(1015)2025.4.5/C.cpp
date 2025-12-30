#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), p(n+1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    int x=0;
    vector<array<int, 2>> ans;
    for (int i = 1; i <= n;i++){
        if(a[i]==b[i]){
            if(n&1&&!x){
                x = i;
            }else {
                cout << -1 << endl;
                return;
            }
        }else if(b[p[b[i]]]!=a[i]){
            cout << -1 << endl;
            return;
        }
    }
    auto _swap = [&](int i, int j)
    {
        if (i == j)
            return;
        swap(a[i], a[j]);
        swap(p[a[i]], p[a[j]]);
        swap(b[i], b[j]);
        ans.push_back({i, j});
    };
    if (n & 1)
    {
        _swap((n + 1) / 2, x);
    }
    for (int i = 1; i <= n/2;i++){
        _swap(p[b[i]], n - i + 1);
    }
    cout << ans.size() << endl;
    for(auto [i,j]:ans){
        cout << i << ' ' << j << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}