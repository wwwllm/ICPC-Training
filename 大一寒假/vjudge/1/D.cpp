#include <bits/stdc++.h>
using namespace std;

// 将所有字符串分解成长度为2或3的字串，存储在一个桶中
// 090,90,09
// 0--10
// 分解：dp[i]=dp[i-2]|dp[i-3]
const int maxn = 1e3 + 5;
string S;
string ans[maxn];
int top;
int dp[maxn];
void solve()
{
    top = 0;
    int n, m;
    cin >> n >> m;
    map<string, int> mpb, mpl, mpp;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (m == 1)
            continue;
        for (int j = 0; j < m - 1; j++)
        {
            string s1;
            s1 = s.substr(j, 2);
            mpb[s1] = 1;
            mpl[s1] = j + 1;
            mpp[s1] = i;
            if (j < m - 2)
            {
                string s2 = s.substr(j, 3);
                mpb[s2] = 1;
                mpl[s2] = j + 1;
                mpp[s2] = i;
            }
        }
    }
    cin >> S;
    if (m == 1)
    {
        cout << -1 << endl;
        return;
    }
    dp[0] = 1;
    for (int i = 2; i <= m; i++)
    {
        string s1 = S.substr(i - 2, 2);
        if (mpb[s1])
        {
            dp[i] |= dp[i - 2];
        }
        if (i > 2)
        {
            string s2 = S.substr(i - 3, 3);
            if (mpb[s2])
            {
                dp[i] |= dp[i - 3];
            }
        }
    }
    if (dp[m])
    {
        int j = m;
        while (j)
        {
            if (dp[j - 2])
            {
                string s1 = S.substr(j - 2, 2);
                top++;
                ans[top] = s1;
                j -= 2;
            }
            else
            {
                string s2 = S.substr(j - 3, 3);
                top++;
                ans[top] = s2;
                j -= 3;
            }
        }
        cout << top << endl;
        for (int i = top; i >= 1; i--)
        {
            cout << mpl[ans[i]] << ' ';
            if (ans[i].length() == 2)
            {
                cout << mpl[ans[i]] + 1 << ' ';
            }
            else
            {
                cout << mpl[ans[i]] + 2 << ' ';
            }
            cout << mpp[ans[i]] << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
