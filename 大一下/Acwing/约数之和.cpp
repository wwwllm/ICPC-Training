#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main()
{
    int t;
    cin >> t;
    map<int, int> mp;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n / i; i++)
        {
            while (n % i == 0)
            {
                n /= i;
                mp[i]++;
            }
        }
        if (n > 1)
            mp[n]++;
    }
    int ans = 1;
    for(auto [a,b]:mp){
        int sum = 1+a,k=b-1;
        while(k--){
            sum = (sum * a + 1) % mod;
        }
        ans = (ans * sum) % mod;
    }
    cout << ans << endl;
    return 0;
}