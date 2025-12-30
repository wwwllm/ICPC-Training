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

const int maxn = 1e5 + 10;
int n,m=0;
int h[maxn], sz = 0, ph[maxn], hp[maxn]; // ph第k个元素存在h下标，hp和ph相反
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int u)
{
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}
void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
        heap_swap(u / 2, u), u /= 2;
}
void insert(int x)
{
    h[++sz] = x;
    ph[++m] = sz;
    hp[sz] = m;
    up(sz);
}
void erase_min()
{
    heap_swap(1, sz);
    sz--;
    down(1);
}
void erase(int k)
{
    heap_swap(k, sz);
    sz--;
    down(k), up(k);
}
void alter(int k, int x)
{
    h[k] = x;
    down(k), up(k);
}
signed main()
{
    cin >> n;
    string op;
    int k, x;
    while (n--)
    {
        cin >> op;
        if (op == "I")
            cin >> x, insert(x);
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
            erase_min();
        else if (op == "D")
            cin >> k, erase(ph[k]);
        else
            cin >> k >> x, alter(ph[k], x);
    }
    return 0;
}