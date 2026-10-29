#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
void solve()
{
    int n;
    cin >> n;
    int c = min(8 * n, 13000);
    int m2 = c / 5;
    int m1 = sqrt(m2);
    int m = sqrt(m1);
    cout << "! " << m1;
    cout.flush();
    int maxn = 0, x = c - m2;
    while (x >= m)
    {
        cout << "? " << 1;
        cout.flush();
        int num;
        cin >> num;
        maxn = max(maxn, num);
        x -= m;
    }
    cout << "! " << maxn << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin>>t;
    while (t--)
        solve();
    return 0;
}