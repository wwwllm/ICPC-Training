#include <bits/stdc++.h>
using namespace std;

// a=p*b(p为质数)
const int N = 1e7 + 10;
bool a[N + 1];
int prime[N + 1], ans;
void Euler_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (a[i] == 0)
            prime[++ans] = i;
        for (int j = 1; prime[j] <= N / i; j++)
        {
            a[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int find(int x)
{
    int l = 0, r = ans + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (prime[mid] > x)
            r = mid;
        else
            l = mid;
    }
    return l;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = n / i;
        ans += find(j);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    Euler_sieve();
    while (t--)
        solve();
    return 0;
}