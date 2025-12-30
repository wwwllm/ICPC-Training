#include <bits/stdc++.h>
using namespace std;

// 堆模板:优先队列
// up(k)将第k个元素向上比较，移到合法位置
// down(k)将第k个元素向下比较，移到合法位置

// 1.插入一个数:heap[++size],up(size)
// 2.求集合中最小值：heap[1]
// 3.删除第一个数：heap[1]=heap[size],down(1)
// 4.删除第k个数：heap[k]=heap[size],down(k),up(k):选择一个
// 5.修改第k个数：heap[k]=x,down(k),up(k):选择一个

//小根堆
const int maxn = 1e5 + 10;
int n, m;
int h[maxn], sz = 0;
void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}
void init()
{
    for (int i = n / 2; i; i--)
        down(i);
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    sz = n;
    init();
    while (m--)
    {
        cout << h[1] << ' ';
        h[1] = h[sz--];
        down(1);
    }
    cout << endl;
    return 0;
}