#include <bits/stdc++.h>
using namespace std;

// 解决最长回文字符字串长度
const int N = 11e6 + 50;
int p[N << 1];
char s[N], ss[N << 1];
int changestr()
{
    int len = strlen(s);
    for (int i = 0, j = 0; i < len; i++)
    {
        ss[j++] = '*';
        ss[j++] = s[i];
    }
    ss[2 * len] = '*';
    return 2 * len + 1;
}
int manacher()
{
    int n = changestr();
    int ans = 0;
    for (int i = 0, c = 0, r = 0, len; i < n; i++)
    {
        len = r > i ? min(r - i, p[2 * c - i]) : 1;
        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
            len++;
        if (i + len > r)
            r = i + len, c = i;
        ans = max(ans, len);
        p[i] = len;
    }
    return ans - 1;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    cout << manacher() << endl;
    return 0;
}