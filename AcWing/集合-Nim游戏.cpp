#include <bits/stdc++.h>
using namespace std;

// sg函数：对于单个图sg(x)!=0,必胜
// 多个图:sg1(x)^sg2(x)……^sgn(x)!=0必胜
const int N = 10100,INF=0x3f3f3f3f;
unordered_set<int> S;
int f[N];
int sg_(int x)
{
    if (f[x] != -1)
        return f[x];
    unordered_set<int> s;
    for (auto ele : S)
    {
        if (x >= ele)
            s.insert(sg_(x - ele));
    }
    for (int i = 0; i<=INF; i++)
    {
        if (!s.count(i))
            return f[x]=i;
    }
    return INF;
}
signed main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x, S.insert(x);
    }
    memset(f, -1, sizeof(f));
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        int res = sg_(h);
        ans ^= res;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}