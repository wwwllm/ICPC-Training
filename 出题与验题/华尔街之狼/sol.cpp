#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r, int val = 0) : n(r), M(r, vector<int>(r, val)) {};
    Mat unit()
    {
        Mat res(n,-inf);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 0;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n, -inf);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] = max(res.M[i][j], M[i][k] + b.M[k][j]);
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
    Mat ans = Mat(a.n).unit();
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    Mat M(1LL << n, -inf);
    for (int i = 1; i <= m; i++)
    {
        int buy = 0, sell = 0;
        int s;
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int b;
            cin >> b;
            buy |= (1LL << (b - 1));
        }
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int b;
            cin >> b;
            sell |= (1LL << (b - 1));
        }
        for (int u = 0; u < (1LL << n); u++)
        {
            int v = (u | buy) & (~sell);
            int w = 0;
            for (int bit = 0; bit < n; bit++)
            {
                int ub = (u >> bit) & 1, vb = (v >> bit) & 1;
                if (!ub && vb)
                    w += a[bit];
                else if (ub && !vb)
                    w -= d[bit];
            }
            M.M[u][v] = max(M.M[u][v], w);
        }
    }
    auto res = exp(M, k);
    int ans = -inf;
    for (int b = 0; b < (1LL << n); b++)
    {
        ans = max(ans, res.M[0][b]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}