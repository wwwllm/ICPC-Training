#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
int a[maxn];
set<int> S;
void solve()
{
    int n;
    S.clear();
    cin >> n;
    for (int i = 1; i <= n;i++)
        S.insert(i);
    bool flag = 0;
    for (int i = 2; i <= n;i+=2){
        cin >> a[i];
        if (!S.count(a[i]))
        {
            flag = 1;
        }
        S.erase(a[i]);
    }
    for (int i = n - 1; i >= 1;i-=2){
        int p = a[i + 1];
        auto it = S.upper_bound(p);
        if(it==S.begin()){
            flag = 1;
        }
        it--;
        a[i] = *it;
        S.erase(*it);
    }
    if(flag){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
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
