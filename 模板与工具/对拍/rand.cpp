#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int randINT(int l, int r)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(l, r);
	return distrib(gen);
}

signed main()
{
	// 优化随机输出的速度
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cout << t << '\n';

	while (t--)
	{

		int n = randINT(10, 50);
		for (int i = 0; i < n; i++)
		{
			cout << randINT(0, 100) << " \n"[i == n - 1];
		}
	}

	return 0;
}