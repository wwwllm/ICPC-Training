#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-4 + 1e-11;

bool isMatch(double user_v, long long target_v2)
{
    return abs(user_v - (target_v2 / 2.0)) <= EPS;
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    long long n = inf.readLong();
    long long m = inf.readLong();
    long long x0 = inf.readLong(), y0 = inf.readLong();
    long long x1 = inf.readLong(), y1 = inf.readLong();

    auto get_unique_features = [&](long long s, long long t, long long bound)
    {
        set<long long> s_vals;
        s_vals.insert(s + t);
        s_vals.insert(2 * bound - (s + t));
        s_vals.insert(abs(s - t));
        s_vals.insert(2 * bound - abs(s - t));
        vector<long long> v(s_vals.begin(), s_vals.end());
        return v;
    };

    vector<long long> setX2 = get_unique_features(x0, x1, n);
    vector<long long> setY2 = get_unique_features(y0, y1, m);
    long long expected_k = (long long)setX2.size() * setY2.size();

    // 如果起点终点重合，通常认为需要无限个或无法拦截
    if (x0 == x1 && y0 == y1)
    {
        expected_k = -1;
    }

    int user_k = ouf.readInt();

    // --- 修正后的判定顺序 ---

    // 1. 如果正确答案是 -1，或者选手认为无解
    if (user_k == -1)
    {
        if (expected_k == -1)
            quitf(_ok, "accepted");
        else
            quitf(_wa, "wrong answer");
    }

    // 2. 数量必须匹配
    if ((long long)user_k != expected_k)
    {
        quitf(_wa, "wrong answer");
    }

    // 3. 坐标匹配
    struct Point
    {
        double x, y;
    };
    vector<Point> user_pts;
    for (int i = 0; i < user_k; ++i)
    {
        double ux = ouf.readDouble();
        double uy = ouf.readDouble();
        if (ux < -EPS || ux > (double)n + EPS || uy < -EPS || uy > (double)m + EPS)
        {
            quitf(_wa, "wrong answer");
        }
        user_pts.push_back({ux, uy});
    }

    vector<bool> used(user_k, false);
    for (long long rx2 : setX2)
    {
        for (long long ry2 : setY2)
        {
            bool found = false;
            for (int i = 0; i < user_k; ++i)
            {
                if (!used[i] && isMatch(user_pts[i].x, rx2) && isMatch(user_pts[i].y, ry2))
                {
                    used[i] = true;
                    found = true;
                    break;
                }
            }
            if (!found)
                quitf(_wa, "wrong answer");
        }
    }

    quitf(_ok, "accepted");
    return 0;
}