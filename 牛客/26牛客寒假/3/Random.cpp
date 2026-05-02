#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randINT(int l, int r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    shuffle(a.begin(), a.end(), rng);
    for (int i = 0; i < min(n, 200LL); i++)
    {
        for (int j = i + 1; j < min(n, 200LL); j++)
        {
            if (__gcd(a[i], a[j]) > 1)
            {
                cout << a[i] << ' ' << a[j] << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}