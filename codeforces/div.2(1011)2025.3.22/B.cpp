#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 5050;
int a[N], cnt[N];
void solve()
{
    int n;
    cin >> n;
    int pos = 0, pos1 = 0;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[i] = cnt[i - 1] + (a[i] == 0);
    }
    if (cnt[2]!=0)//前两个有0
    {
        if (cnt[n] - cnt[2] != 0)
            cout <<3<<endl<< 1 << ' ' << 2 << endl
                 << 2 << ' ' << n - 1 << endl
                 << 1 << ' ' << 2 << endl;
        else
            cout <<2<<endl<< 1 << ' ' << 2 << endl
                 << 1 << ' ' << n - 1 << endl;
    }
    else
    {
        if (cnt[n] - cnt[2] != 0)
            cout <<2<<endl<< 3 << ' ' << n << endl
                 << 1 << ' '<< 3 << endl;
        else
            cout <<1<<endl<< 1 << ' ' << n << endl;
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