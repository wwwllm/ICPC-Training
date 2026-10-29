#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1,2,1,3
// 0,1,2,2
const int maxn = 2e5 + 50;
int arr[maxn];
map<int, int> b;
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    b.clear();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int y = (k - x % k) % k;
        if(y!=0){
            b[y]++;
            ans = max(ans, y + (b[y] - 1) * k);
        }  
    }
    cout << (ans == 0 ? 0 : ans + 1) << endl;
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