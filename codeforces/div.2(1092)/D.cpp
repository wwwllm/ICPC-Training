#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
vector<int> D(N + 1);
void init()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            D[j]++;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int B = sqrt(n);
    int cnt = 0;
    vector<int> a;
    auto calc = [&](int b)
    {
        a.clear();
        int x = n;
        while (x)
        {
            a.push_back(x % b);
            x /= b;
        }
        int len = a.size();
        int p = 0;
        for (int i = 0, j = 0; i < len;)
        {
            while (j < len && a[i] == a[j])
                j++;
            p = gcd(p, j - i);
            i = j;
        }
        if (p >= 2)
        {
            cnt += D[p];
        }
    };
    for (int b = 2; b <= B; b++)
    {
        calc(b);
    }
    for (int x = 1; x <= B; x++)
    {
        int b = (n - x) / x;
        if (x * b + x == n && b >= 2 && b > x)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}