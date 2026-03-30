#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;

// 4 8 12 16 24 28 32 36 40 44 48 52 56 64 68 72 76 80 84 88 92 96 104 108 112 116 120 124 128 132 136 144 148 152 156 160 164 168 172 176 184 188 192 196 204 208 212 216 224 228 232 236 240 244 248 252 256 264 268 272 276 280 284 288 292 296 304 308 312 316 320 324 328 332 336 344 348 352 356 360 364 368 372 376 384 388 392 396 400
vector<int> a = {
    1, 2, 3, 5, 6, 7, 9, 10, 11, 13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 25, 26, 27, 29, 30, 31, 33, 34, 35, 37, 38, 39, 41, 42, 43, 45, 46, 47, 49, 50, 51, 53, 54, 55, 57, 58, 59, 60, 61, 62, 63, 65, 66, 67, 69, 70, 71, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89, 90, 91, 93, 94, 95, 97, 98, 99};
// 1575
inline LL calc(LL k)
{
    LL x = 4, y = 100, ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (y > k)
            break;
        ans += k / x;
        ans -= k / y;
        x *= 100;
        y *= 100;
    }
    ans += k / x;
    if (x <= k)
    {
        x *= 100;
        ans += k / x;
    }
    return ans;
}
void solve()
{
    // auto check = [&](int x)
    // {
    //     int a = 4, b = 10;
    //     int cnt = 0;
    //     while (a <= x)
    //     {
    //         if (x % a == 0 && x % b != 0)
    //             cnt++;
    //         a = a * 10, b = b * 10;
    //     }
    //     return cnt == 1;
    // };
    // int cnt = 0;
    // for (int i = 1; i <= 2024; i++)
    // {
    //     if (!check(i))
    //     {
    //         cnt++;
    //     }
    // }
    // cerr << cnt << '\n';
    int k;
    cin >> k;
    // k += 1575;
    int l = 0, r = 1e18;

    cout << calc(k) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}