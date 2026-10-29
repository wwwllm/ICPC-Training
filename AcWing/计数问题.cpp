#include <bits/stdc++.h>
using namespace std;

int power10[10];
void init()
{
    power10[0] = 1;
    int i = 1;
    while (i < 10)
    {
        power10[i] = power10[i - 1] * 10;
        i++;
    }
}
int get(vector<int> a, int l, int r)
{
    int num = 0;
    for (int i = l; i >= r; i--)
        num = num * 10 + a[i];
    return num;
}
int count(int n, int x)
{
    if (!n)
        return 0;
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--)
    {
        if (i < n - 1)
        {
            res += get(num, n - 1, i + 1) * power10[i];
            if (!x)
                res -= power10[i];
        }
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += power10[i];
    }
    return res;
}
signed main()
{
    int a, b;
    init();
    while (cin >> a >> b, a || b)
    {
        if (a > b)
            swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}