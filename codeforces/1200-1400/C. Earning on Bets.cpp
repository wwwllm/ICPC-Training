#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1979/C
int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> k(n), ans(n);
    for(auto &ele:k)
        cin >> ele;
    int mul = 1;
    for (auto ele : k)
        mul = lcm(mul, ele);
    int sum = 0;
    for (auto ele : k)
        sum += mul / ele;
    if (sum < mul)
    {
        for (int i = 0; i < n; i++)
            cout << mul / k[i] << " \n"[i == n - 1];
    }
    else
        cout << -1 << '\n';
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