#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int sum = 0, year = 2025;
    auto cmp = [&](int y)
    {
        if ((y % 4 == 0) || (y % 100 == 0 && y % 400 == 0))
            return 1;
        return 0;
    };
    if (cmp(year))
        sum = (sum + 366) % 7;
    else
        sum = (sum + 365) % 7;
    year++;
    while (sum)
    {
        if (cmp(year))
            sum = (sum + 366) % 7;
        else
            sum = (sum + 365) % 7;
        if (sum)
            year++;
    }
    cout << year << '\n';
    return 0;
}