#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
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
            for (int k = 0; k < n; k++)
            {
                if (M[i][k] == 0)
                    continue;
                for (int j = 0; j < n; j++)
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
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 3 * exp(2, m - 1) % mod << '\n';
        return;
    }
    vector<int> p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 3;
    }
    auto check = [&](int x)
    {
        vector<int> X;
        for (int i = 0; i < n; i++)
        {
            int tmp = x / p[i] % 3;
            X.push_back(tmp);
        }
        for (int i = 0; i < X.size() - 1; i++)
        {
            if (X[i] == X[i + 1])
                return 0;
        }
        if (X[0] == 0 && X[1] == 1)
            return 1;
        else
            return 0;
    };
    vector<int> st;
    for (int i = 0; i <= p[n]; i++)
    {
        if (check(i))
            st.push_back(i);
    }
    int r = st.size();
    Mat M(r);
    vector<array<int, 3>> b = {{0, 1, 2}, {1, 0, 2}, {0, 2, 1}, {2, 0, 1}, {1, 2, 0}, {2, 1, 0}};
    auto change = [&](vector<int> &x, array<int, 3> &f) -> vector<int>
    {
        vector<int> nx(x.size());
        for (int i = 0; i < x.size(); i++)
        {
            nx[i] = f[x[i]];
        }
        return nx;
    };
    auto calc = [&](int x, int y) -> int
    {
        x = st[x], y = st[y];
        vector<int> X, Y;
        for (int i = 0; i < n; i++)
        {
            X.push_back(x / p[i] % 3);
            Y.push_back(y / p[i] % 3);
        }
        int val = 0;
        for (int sy = 0; sy < 6; sy++)
        {
            auto ny = change(Y, b[sy]);
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                if (X[i] == ny[i])
                    ok = 0;
            }
            val += ok;
        }

        return val;
    };
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            M.M[i][j] = calc(i, j);
        }
    }
    M = exp(M, m - 1);
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            (res += M.M[i][j]) %= mod;
        }
    }
    cout << res * 6 % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}