#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> a;
        int n;
        cin >> n;
        for (int i = 1; i <= n / i; i++)
        {
            if (n % i == 0)
            {
                a.insert(i);
                if (i * i != n)
                {
                    a.insert(n / i);
                }
            }
        }
        for (auto ele : a)
            cout << ele << ' ';
        cout << endl;
    }
}