#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        b[i] = c - '0';
    }
    if (a[0] != b[0] || a[n - 1] != b[n - 1])
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> A, B;
    for (int i = 0; i < n - 1; i++)
    {
        int aa, bb;
        aa = (a[i] ^ a[i + 1]) ^ (i % 2);
        bb = (b[i] ^ b[i + 1]) ^ (i % 2);
        if (aa)
            A.push_back(i);
        if (bb)
            B.push_back(i);
    }
    if (A.size() == B.size())
    {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            ans += abs(A[i] - B[i]);
        }
        cout << ans << '\n';
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