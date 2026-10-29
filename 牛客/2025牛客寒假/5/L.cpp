#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int mod = n % 6;
        if (mod <= 2)
        {
            cout << (n / 6) * 2 << endl;
            for (int i = 1; i <= n / 6; i++)
            {
                cout << (i - 1) * 6 + 1 << ' ' << (i - 1) * 6 + 2 << ' ' << (i - 1) * 6 + 4 << endl
                     << (i - 1) * 6 + 3 << ' ' << (i - 1) * 6 + 5 << ' ' << (i - 1) * 6 + 6 << endl;
            }
        }
        else
        {   
            if(n<6){
                cout << 1 << endl;
                cout << 1 << ' ' << 2 << ' ' << 4 << endl;
                return;
            }
            cout << (n / 6) * 2 + 1 << endl;
            cout << 1 << ' ' << 2 << ' ' << 4 << endl
                 << 3 << ' ' << 9 << ' ' << 5 << endl
                 << 6 << ' ' << 8 << ' ' << 7 << endl;
            for (int i = 1; i <= n / 6 - 1; i++)
            {
                cout << (i - 1) * 6 + 10 << ' ' << (i - 1) * 6 + 14 << ' '<<(i - 1) * 6 + 11 << endl
                     << (i - 1) * 6 + 13 << ' ' << (i - 1) * 6 + 12 << ' ' << (i - 1) * 6 + 15 << endl;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}