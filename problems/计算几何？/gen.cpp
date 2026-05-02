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
    int n = randINT(1e4, 1e9);
    int m = randINT(1e4, 1e9);

    cout << n << " " << m << "\n";

    int x1 = randINT(0, n), y1 = randINT(0, m), x2 = randINT(0, n), y2 = randINT(0, m);
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    return 0;
}