#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int e[maxn], l[maxn], r[maxn], head, idx;
void init()
{
    l[1] = 0, r[0] = 1;
    idx = 2;
}
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(void)
{
    int m;
    cin >> m;
    init();
    while (m--)
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << ' ';

    return 0;
}
