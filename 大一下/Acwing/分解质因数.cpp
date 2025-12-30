#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n/i; i++)
        {
            if (n % i == 0)
            {
                int s = 0;
                while (n % i == 0)
                {
                    s++;
                    n /= i;
                }
                cout << i << ' ' << s << endl;
            }
        }
        if(n!=1)
            cout << n << ' ' << 1 << endl;
        cout << endl;
    }
    return 0;
}