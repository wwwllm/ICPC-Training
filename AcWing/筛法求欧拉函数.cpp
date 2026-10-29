#include <bits/stdc++.h>
#define int long long
using namespace std;

//欧拉定理：若a,n互质则，a^phi[n]=1(mod n)
const int N = 1e6 + 10;
int phi[N], n;
int prime[N], cnt;
bool st[N];
void get_prime(int x)
{
    phi[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
        {
            phi[i] = i - 1;
            prime[++cnt] = i;
        }
        for (int j = 1; prime[j] * i <= x; j++)
        {
            st[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
signed main()
{
    cin >> n;
    get_prime(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += phi[i];
    cout << ans << endl;
    return 0;
}