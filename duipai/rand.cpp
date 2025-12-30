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
	cout << 1 << '\n';

	int n = randINT(1, 20);
	cout << n << '\n';
	for (int i = 1; i <= n; i++)
	{
			int a = randINT(1, 20);
			cout << a << ' ';
	}
	cout << '\n';
	return 0;
}