#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P3803
const double pi = acos(-1.0);
using Complex = complex<double>;
namespace FFT
{
    vector<int> mul(vector<int> &a, vector<int> &b)
    {
        int n = 1;
        int tot = a.size() + b.size() - 1;
        while (n < tot)
        {
            n <<= 1;
        }
        vector<Complex> fa(n), fb(n);
        for (int i = 0; i < a.size(); i++)
        {
            fa[i] = a[i];
        }
        for (int i = 0; i < b.size(); i++)
        {
            fb[i] = b[i];
        }
        dft(fa);
        dft(fb);
        for (int i = 0; i < n; i++)
        {
            fa[i] *= fb[i];
        }
        idft(fa);
        vector<int> c(tot);
        for (int i = 0; i < c.size(); i++)
        {
            c[i] = round(fa[i].real());
        }
        return c;
    }
    void dft(vector<Complex> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            Complex wn(cos(pi / k), sin(pi / k));
            for (int i = 0; i < n; i += 2 * k)
            {
                Complex w(1, 0);
                for (int j = 0; j < k; j++)
                {
                    Complex u = a[i + j], v = a[i + j + k] * w;
                    a[i + j] = u + v;
                    a[i + j + k] = u - v;
                    w *= wn;
                }
            }
        }
    }
    void idft(vector<Complex> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        for (int i = 0; i < n; i++)
        {
            a[i] /= n;
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= m; i++)
    {
        cin >> b[i];
    }
    auto c = FFT::mul(a, b);
    for (int i = 0; i <= n + m; i++)
    {
        cout << c[i] << " ";
    }
    cout << '\n';
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