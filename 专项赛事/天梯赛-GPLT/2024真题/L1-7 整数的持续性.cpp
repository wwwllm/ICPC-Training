#include <bits/stdc++.h>
using namespace std;

vector<int> ans[100];
int f(int x)
{
    int ans = 1;
    while (x)
    {
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}
signed main()
{
    int l, r;
    cin >> l >> r;
    int maxc = 0;
    for (int i = l; i <= r; i++)
    {
        int x = i;
        int cnt = 0;
        while (x >= 10)
        {
            x = f(x);
            cnt++;
        }
        maxc = max(cnt, maxc);
        ans[cnt].push_back(i);
    }
    cout << maxc << endl;
    int len = ans[maxc].size();
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
            cout << ans[maxc][i];
        else
            cout << ans[maxc][i] << ' ';
    }
}