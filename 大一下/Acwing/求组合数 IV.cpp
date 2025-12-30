#include <bits/stdc++.h>
using namespace std;

// p是a!的k重质因子：k=a/(p^1)+a/(p^2)+a/(p^3)……
const int N = 5050;
bool vis[N];
int prime[N], cnt, sum[N];
void get_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            prime[++cnt] = i;
        for (int j = 1; i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int get(int a,int p)
{
    int ans = 0;
    while (a / p)
    {
        ans += a / p;
        a /= p;
    }
    return ans;
}
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (auto ele : a)
    {
        t += ele * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
signed main()
{
    int a, b;
    cin >> a >> b;
    get_prime(a);
    for (int i = 1; i <= cnt; i++)
    {
        sum[i] = get(a,prime[i]) - get(b,prime[i]) - get(a - b,prime[i]);
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i <= cnt; i++)
        while (sum[i])
            ans = mul(ans, prime[i]), sum[i]--;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}