#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int num;
    int a[3] = {1, 2, 3};
    cout << "? 1 2 3" << endl;
    cout.flush();
    cin >> num;
    if(num==0){
        cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        return;
    }
    while (num)
    {
        int pos = rand() % 3;
        a[pos] = num;
        cout << "? " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
        cout.flush();
        cin >> num;
    }
    cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
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
