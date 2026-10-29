#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7, N = 100;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r) : n(r), M(r, vector<int>(r)) {};
    Mat unit()
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 1;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] += M[i][k] * b.M[k][j] % mod;
                    res.M[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " \n"[j == n - 1];
            }
        }
    }
};
Mat exp(Mat a, int b)
{
    Mat ans(a.n);
    ans = ans.unit();
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;

    k--;
    vector<int> t(k);

    for (int i = 0; i < k; i++)
    {
        cin >> t[i];
    }
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < k; j++)
        {
            int pos = i - t[j];
            if (pos >= 0)
            {
                (dp[i] += 1) %= mod;
                for (int x = pos; x < i; x++)
                    (dp[i] += dp[x]) %= mod;
            }
        }
    }
    if (n <= N)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            (ans += dp[i]) %= mod;
        }
        cout << ans << '\n';
        return;
    }
    vector<int> pre(N + 1);
    for (int i = 0; i < k; i++)
    {
        for (int m = 1; m <= N; m++)
        {
            if (t[i] >= m)
                pre[m]++;
        }
    }
    Mat M(N + 2);
    for (int i = 1; i <= N; i++)
    {
        M.M[0][i] = pre[i];
        M.M[1][i] = pre[i];
    }
    M.M[0][0] = 1, M.M[0][N + 1] = M.M[1][N + 1] = k + 1;
    for (int i = 2; i <= N; i++)
    {
        M.M[i][i - 1] = 1;
    }
    M.M[N + 1][N + 1] = 1;
    M = exp(M, n - N);
    int ans = 0;
    vector<int> st(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        st[i] = dp[N - i];
        (st[0] += st[i]) %= mod;
    }
    st[N + 1] = 1;
    for (int i = 0; i <= N + 1; i++)
    {
        (ans += st[i] * M.M[0][i] % mod) %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}