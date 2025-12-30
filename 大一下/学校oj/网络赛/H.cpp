#include <bits/stdc++.h>
#define int long long
using namespace std;

// dp[n]=dp[n-1]+2sum(max(a[i],a[n]))
const int mod = 998244353, N = 3e5 + 10;
int lowbit(int x)
{
    return x & (-x);
}
struct BIT
{
    int tr[N];
    void add(int pos, int x)
    {
        for (int i = pos; i <= N; i += lowbit(i))
            tr[i] += x;
    }
    int query(int r)
    {
        int sum = 0;
        for (int i = r; i; i -= lowbit(i))
            sum += tr[i];
        return sum;
    }
} tcnt, tsum;
int ex_power(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int a[N],n;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dp = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = tcnt.query(a[i]);//小于等于a[i]的数的个数
        int res = tsum.query(a[i]);//的和
        dp = (dp + (2 * cnt + 1) * a[i] + sum - 2*res) % mod;
        sum += 2*a[i];
        tcnt.add(a[i], 1);
        tsum.add(a[i], a[i]);
        cout << dp * ex_power(i * i, mod - 2) % mod << endl;
    }
    return 0;
}