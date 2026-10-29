#include <bits/stdc++.h>
#define int long long
using namespace std;

int ta[26], tb[26];
void solve()
{
    int na, nb;
    memset(ta, 0, sizeof(ta));
    memset(tb, 0, sizeof(tb));
    string sa, sb;
    cin >> na >> nb;
    cin >> sa >> sb;
    if (nb > na)
    {
        swap(na, nb);
        swap(sa, sb);
    }
    int suma = 0, sumb = 0;
    int m = 0;
    for (int i = 0; i < na; i++)
        ta[sa[i] - 'a']++;
    for (int i = 0; i < nb; i++)
        tb[sb[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        int t = min(ta[i], tb[i]);
        ta[i] -= t, tb[i] -= t;
        suma += ta[i], sumb += tb[i];
        m += ta[i] / 2;
    }
    int k = suma - sumb;
    k = min(k, m * 2);
    cout << (suma + sumb - k) / 2 << endl;
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
