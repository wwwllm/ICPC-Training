#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
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
signed main()
{
    int n, k;
    cin >> n >> k;
    Mat M(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M.M[i][j];
        }
    }
    auto ans = exp(M, k);
    ans.print();
    return 0;
}