#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2048/C
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    cout << 1 << ' ' << n << ' ';
    int i;
    for (i = 0; i < n; i++)
        if (s[i] == '0')
            break;
    int len = n - i;
    if (len == 0)
    {
        cout << "1 1\n";
        return;
    }
    int p = i;
    for (; p < n; p++)
    {
        if (s[p] == '1')
            break;
    }
    if (p - i > i)
        cout << 1 << ' ' << len << endl;
    else
        cout << 2 * i - p + 1 << ' ' << 2 * i - p + len << endl;
    // 暴力：
    //  map<string, vector<int>> mp;
    //  string ans = "";
    //  auto f = [&](string a, string b)
    //  {
    //      if (a == "")
    //          return b;
    //      if (b == "")
    //          return a;
    //      int n = a.size();
    //      for (int i = 0; i < n; i++)
    //      {
    //          if (a[i] != b[i])
    //          {
    //              if (a[i] > b[i])
    //                  return a;
    //              else
    //                  return b;
    //          }
    //      }
    //      return a;
    //  };
    //  for (int j = 0; j < i; j++)
    //  {
    //      string temp = s.substr(j, len);
    //      string res;
    //      for (int k = 0; k < len; k++)
    //      {
    //          int x = s[i + k] - '0';
    //          int y = temp[k] - '0';
    //          res += '0' + x ^ y;
    //      }
    //      mp[res].push_back(j + 1);
    //      ans = f(res, ans);
    //  }
    //  int l = mp[ans][0];
    // cout << l << ' ' << l + len - 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}