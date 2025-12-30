#include <bits/stdc++.h>
using namespace std;

struct ST
{
#define lg2(n) (63 - __builtin_clzll(n)) // 取位数
    int n;
    vector<vector<int>> st;
    ST(int n, vector<int> &a)
    {
        int bit = lg2(n) + 2;
        st.assign(n, vector<int>(bit));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        // st[i][j]=gcd(st[i][j-1],st[i+(1LL<<(j-1))][j-1])
        for (int j = 1; j < bit; j++)
            for (int i = 0; i + (1LL << (j - 1)) < n; i++)
                st[i][j] = gcd(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
    }
    int query(int l, int r)
    {
        int k = lg2(r - l + 1);
        return gcd(st[l][k], st[r - (1LL << k) + 1][k]);
    }
};
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ST st(n, a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << '\n';
    }
    return 0;
}
