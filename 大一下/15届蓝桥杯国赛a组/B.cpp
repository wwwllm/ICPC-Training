#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10120300500;
signed main()
{
    int ans = 0;
    for (int i = 2; i <= 2 * N / i; i++)
    {
        if (2 * N % i == 0)
        {
            int j = 2 * N / i;
            if ((i & 1) == (j & 1))
            {
                int b = (j - i) / 2;
                ans += b * b + N;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}