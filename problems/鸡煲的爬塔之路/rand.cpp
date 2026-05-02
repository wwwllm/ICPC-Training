#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int randINT(int l, int r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}

signed main()
{
    int n = 1000;
    int m = 10000;
    int h = randINT(1, 1000);
    int s = randINT(1, n);

    cout << n << " " << m << " " << h << " " << s << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << randINT(1, 1000000000) << (i == n ? "" : " ");
    }
    cout << "\n";

    for (int i = 1; i <= m; i++)
    {
        int u = randINT(1, n);
        int v = randINT(1, n);
        // 为了让路径更有意义，边权 w 建议不要太大，否则走两步就没了
        // 这里设定 w 在 1 到 h/10 之间，或者干脆 1 到 100
        int w = randINT(1, max(1LL, h / 5));
        cout << u << " " << v << " " << w << "\n";
    }
    return 0;
}