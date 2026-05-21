#include <iostream>
#include <iomanip>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int days = 365;
    double p = 1.0;
    int n = 0;

    while (p > 0.5)
    {
        n++;
        p *= (double)(days - n + 1) / days;

        std::cout << n << " " << std::fixed << std::setprecision(9) << (1 - p) << '\n';
    }

    std::cout << n << "\n";

    return 0;
}
//答案是23
//说明了在hash表中出现哈希冲突的概率高