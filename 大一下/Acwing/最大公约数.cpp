#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{   
    return !b ? a : gcd(b, a % b);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}