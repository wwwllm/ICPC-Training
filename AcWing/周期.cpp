#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char str[N];
int ne[N];
signed main()
{
    int n;
    int cnt = 1;
    while (cin >> n, n)
    {
        cout << "Test case #"<<cnt << endl;
        cin >> str+1;
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j && str[i] != str[j + 1])
                j = ne[j];
            if (str[i] == str[j + 1])
                j++;
            ne[i] = j;
        }
        for (int i = 2; i <= n; i++)
        {
            if (i % (i - ne[i]) == 0 && ne[i])
            {
                cout << i << ' ' << i / (i - ne[i]) << endl;
            }
        }
        cnt++;
        cout << endl;
    }
    return 0;
}