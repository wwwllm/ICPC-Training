#include <bits/stdc++.h>
using namespace std;

int getor(int l, int r) //[l,r]区间位运算
{
    return l | ((1 << (__lg(l ^ r)) + 1) - 1);
}
int getand(int l, int r)
{
    return l & ((1 << (__lg(l ^ r)) + 1) - 1);
}
int getxor(int l, int r)
{
    if (x < 0)
        return 0;
    else if (x % 4 == 0)
        return x;
    else if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else
        return 0;
}
signed main()
{
    int l, r;
    cin >> l, r;
    cout << getor(l, r) << ' ' << getand(l, r) << ' ' << getxor(l, r) << '\n';
    return 0;
}