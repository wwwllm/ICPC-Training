#include <bits/stdc++.h>
#define int long long
using namespace std;

int ex_power(int a, int b, int mod)
{
    int ans = 1;
    a%=mod
    while(b){
        if(b&1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, k, p;
        cin >> a >> k >> p;
        cout << ex_power(a, k, p) << endl;
    }
    return 0;
}