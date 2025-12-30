#include <bits/stdc++.h>
#define int long long
using namespace std;

// 求和加求积
struct sn
{
    int a[6];
};
const int mod = 1e5 + 3, N = 1e5 + 10;
int n;
sn s[N];
vector<int> has[N];
int to_hash(sn a)
{
    int mul = 1, sum = 0;
    for (int i = 0; i < 6; i++)
        sum = sum+a.a[i]%mod, mul = mul*a.a[i]%mod;
    return (sum + mul) % mod;
}
bool check(sn a, sn b)
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
        {
            bool flag = 1;
            for (int k = 0; k < 6; k++)
            {
                if (a.a[(i + k) % 6] != b.a[(j + k) % 6])
                    flag = 0;
            }
            if (flag)
                return 1;
            flag = 1;
            for (int k = 0; k < 6; k++)
            {
                if (a.a[(i + k) % 6] != b.a[(j - k + 6) % 6])
                    flag = 0;
            }
            if (flag)
                return 1;
        }
    return 0;
}
bool insert(sn a, int pos)
{
    int h = to_hash(a);
    for (auto ele : has[h])
    {
        if (check(s[ele], a))
            return 1;
    }
    has[h].push_back(pos);
    return 0;
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
            cin >> s[i].a[j];
    }
    for (int i = 1; i <= n; i++)
    {
        if (insert(s[i], i))
        {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
    }
    cout << "No two snowflakes are alike." << endl;
    return 0;
}