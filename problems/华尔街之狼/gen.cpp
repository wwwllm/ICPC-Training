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
    int n = randINT(6, 7);
    int m = randINT(50, 100);
    int k = randINT(1e8, 1e9);
    int max_val = 1e5;

    cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << randINT(1, max_val) << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << randINT(1, max_val) << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        // 创建编号池并打乱，保证同一策略中买/卖不冲突
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        static std::mt19937_64 g(std::random_device{}());
        shuffle(p.begin(), p.end(), g);

        // 随机分配买入数量 x 和卖出数量 y
        // 总数不超过 n 即可
        int total_affected = randINT(0, n);
        int x = randINT(0, total_affected);
        int y = total_affected - x;

        // 第一行：建仓指令 x_j id1 id2...
        cout << x;
        for (int j = 0; j < x; j++)
        {
            cout << " " << p[j];
        }
        cout << endl;

        // 第二行：清仓指令 y_j id1 id2...
        cout << y;
        for (int j = 0; j < y; j++)
        {
            cout << " " << p[x + j];
        }
        cout << endl;
    }
    return 0;
}