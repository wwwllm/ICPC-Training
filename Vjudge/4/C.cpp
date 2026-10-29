#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50, maxm = 3.5e4;
int is_prime[maxm+10] = {0}, prime[maxm+10], top = 0, t[maxm+10];
map<int,int> mp;
int a[maxn];
void Euler_sieve()
{
    for (int i = 2; i <= maxm; i++)
    {
        if (is_prime[i] == 0)
            prime[++top] = i;
        for (int j = 1; j <= top && prime[j] * i <= maxm; j++)
        {
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= top; i++)
        t[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= top && a[i] >= prime[j]; j++)
        {
            if (!(a[i] % prime[j]))
            {
                t[j]++;
                while (!(a[i] % prime[j]))
                    a[i] /= prime[i];
            }
        }
        if (a[i] != 1)
        {
            if (mp[a[i]])
            {
                cout << "YES" << endl;
                return;
            }
            mp[a[i]] = 1;
        }
    }
    for (int i = 1; i <= top; i++)
    {
        if (t[i] > 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    Euler_sieve();
    while (t--)
        solve();
    return 0;
}
