#include <bits/stdc++.h>
using namespace std;

//树状数组实现单点修改和区间查询
int lowbit(int x)
{
    return x & (-x);
}
const int N = 5e5 + 10;
int tr[N], n, m;
void add(int pos, int x)
{
    for (int i = pos; i <= N; i += lowbit(i))
        tr[i] += x;
}
int puery(int l, int r)
{
    int sum = 0;
    for (int i = r; i; i -= lowbit(i))
        sum += tr[i];
    for (int i = l - 1; i; i -= lowbit(i))
        sum -= tr[i];
    return sum;
}
signed main()
{
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++)
        cin >> x, add(i, x);
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            add(a, b);
        else
            cout << puery(a, b) << endl;
    }
    return 0;
}