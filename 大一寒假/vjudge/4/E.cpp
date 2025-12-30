#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's')
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            if (i != len - 1)
            {
                if ((s[i] == 'Y' && s[i + 1] != 'e') || (s[i] == 'e' && s[i + 1] != 's') || (s[i] == 's' && s[i + 1] != 'Y'))
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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
