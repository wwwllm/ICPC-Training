#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n;
bool a[maxn + 1];
int prime[maxn + 1], ans;
void Euler_sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0)
            prime[++ans] = i;
        for (int j = 1; prime[j] <= n / i; j++)
        {
            a[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break; // 保证prime[j]为最小质因数
        }
    }
}
signed main()
{
    cin >> n;
    Euler_sieve(n);
    cout << ans << endl;
    return 0;
}