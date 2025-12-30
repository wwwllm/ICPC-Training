#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6e6 + 10;
int prime[N + 1], ans = 0;
bool cmp[N + 1];
void Euler_sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (cmp[i] == 0)
            prime[++ans] = i;
        for (int j = 1; prime[j] <= n / i; j++)
        {
            cmp[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= ans; i++)
        prime[i] += prime[i - 1];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), [&](int a, int b)
         { return a > b; });
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    int i;
    for (i = n; i >= 1; i--)
    {
        if (a[i - 1] >= prime[i])
            break;
    }
    cout << n - i << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    Euler_sieve(N);
    while (t--)
        solve();
    return 0;
}