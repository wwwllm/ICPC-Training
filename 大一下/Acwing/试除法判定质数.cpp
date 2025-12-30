#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        bool flag = 1;
        if(x==1)
            flag = 0;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}