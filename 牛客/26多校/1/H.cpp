#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int N = 1e3;
vector<array<int, 3>> st = {{3, 0, 0},
                            {2, 1, 0},
                            {2, 0, 1},
                            {1, 2, 0},
                            {1, 1, 1},
                            {1, 0, 2},
                            {0, 3, 0},
                            {0, 2, 1},
                            {0, 1, 2},
                            {0, 0, 3}};
map<array<int, 3>, int> pos;
vector dp(N + 1, vector(10, vector<double>(10)));
double k = 0;
void init()
{
    for (int i = 0; i < 10; i++)
    {
        pos[st[i]] = i;
    }
    auto score = [&](int &x, int &y)
    {
        if (x == y)
            return 1;
        if ((x + 1) % 3 == y)
            return 3;
        return 0;
    };
    auto calc = [&](int t, array<int, 3> a, array<int, 3> b) -> double
    {
        double res = 0;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                a[x]++, b[y]++;
                res += dp[t][pos[a]][pos[b]];
                a[x]--, b[y]--;
            }
        }
        res /= 9;
        return res;
    };
    for (int i = 1; i <= N; i++)
    {
        for (int a = 0; a < 10; a++)
        {
            for (int b = 0; b < 10; b++)
            {
                auto sta = st[a], stb = st[b];
                double res2 = 0;
                for (int x = 0; x < 3; x++)
                {
                    if (sta[x] == 0)
                        continue;
                    double res1 = 1e18;
                    for (int y = 0; y < 3; y++)
                    {
                        if (stb[y] == 0)
                            continue;
                        int sc = score(x, y);
                        sta[x]--, stb[y]--;
                        auto tmp = calc(i - 1, sta, stb);
                        sta[x]++, stb[y]++;
                        res1 = min(res1, tmp + sc);
                    }
                    res2 = max(res2, res1);
                }
                dp[i][a][b] = res2;
            }
        }
    }
    int d = 100;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            k += dp[N][i][j] - dp[N - d][i][j];
        }
    }
    k /= 100 * d;
}
void solve()
{
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;
    cout << fixed << setprecision(12);
    auto get_st = [&](string &s)
    {
        array<int, 3> res{};
        for (auto c : s)
        {
            if (c == 'R')
                res[0]++;
            if (c == 'S')
                res[1]++;
            if (c == 'P')
                res[2]++;
        }
        return res;
    };
    auto a = get_st(A), b = get_st(B);
    if (n <= N)
    {
        cout << dp[n][pos[a]][pos[b]] << '\n';
    }
    else
    {
        cout << dp[N][pos[a]][pos[b]] + (n - N) * k << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}