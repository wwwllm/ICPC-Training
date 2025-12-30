#include <bits/stdc++.h>
using namespace std;

// https : // codeforces.com/problemset/problem/2050/D
// 另一种思路：类似冒泡排序：当差值超过二交换
void solve()
{
    string S;
    cin >> S;
    int n = S.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = S[i] - '0';
    }
    for (int i = 0; i < n; i++)
    {
        int res = a[i], p = i;
        for (int j = 0; j < 10 && i + j < n; j++)
        {
            if (res < a[j + i] - j)
            {
                res = a[j + i] - j;
                p = i + j;
            }
        }
        for (int j = p; j > i; j--)
            swap(a[j], a[j - 1]);
        a[i] = res;
    }
    for (auto it : a)
        cout << it;
    cout << '\n';
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