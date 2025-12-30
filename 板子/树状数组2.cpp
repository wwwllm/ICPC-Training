#include <bits/stdc++.h>
#define int long long
using namespace std;

// 树状数组实现区间修改和单点查询
//思想：差分
int lowbit(int x)
{
    return x & (-x);
}
const int N = 5e5 + 10;
int tr[N], n, m,a[N];
void add(int pos, int x)
{
    for (int i = pos; i <= n; i += lowbit(i))
        tr[i] += x;
}
int puery(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}
signed main()
{
    cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int op;
        cin >> op ;
        if (op == 1){
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k), add(y + 1, -k);
        }
        else{
            int x;
            cin >> x;
            cout << a[x] + puery(x) << endl;
        }   
    }
    return 0;
}