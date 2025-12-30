#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans[1005], t[1005], s[1005];
void chen1()
{
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            s[i + j - 1] += ans[i] * t[j];
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        s[i + 1] += s[i] / 10;
        s[i] %= 10;
    }
    for (int i = 1; i <= 500; i++)
        ans[i] = s[i];
}
void chen2()
{
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            s[i + j - 1] += t[i] * t[j];
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        s[i + 1] += s[i] / 10;
        s[i] %= 10;
    }
    for (int i = 1; i <= 500; i++)
        t[i] = s[i];
}
signed main()
{
    int p;
    cin >> p;
    cout << (int)(log10(2) * p + 1) << endl;
    ans[1] = 1;
    t[1] = 2;
    while (p != 0) // 快速幂模板
    {
        if (p % 2 == 1)
            chen1();
        p /= 2;
        chen2();
    }
    ans[1] -= 1;
    for (int i = 500; i >= 1; i -= 1) // 注意输出格式，50个换一行，第一个不用
        if (i != 500 && i % 50 == 0)
            cout << endl
                 << ans[i];
        else
            cout << ans[i];
    return 0;
}