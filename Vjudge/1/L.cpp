#include <bits/stdc++.h>
#define int long long
using namespace std;

// 将能一起引爆的放在一起（并查集），二分时间
// 每个块引爆时间为块中最小的时间
// 按时间顺序排序
//(x1,y1),(x2,y2):(x1==x2&&abs(y1-y2)<=k)||(y1==y2&&abs(x1-x2)<=k)
const int maxn = 2e5 + 50;
int bcj[maxn][2];
int n, k;
struct dian
{
	int x, y, time, pos;
};
dian d[maxn];
int ans[maxn], top;
bool f(int x1, int y1, int x2, int y2)
{
	return (x1 == x2 && abs(y1 - y2) <= k) || (y1 == y2 && abs(x1 - x2) <= k);
}
int find(int x)
{
	if (x == bcj[x][0])
		return x;
	return bcj[x][0] = find(bcj[x][0]);
}
void join(int a, int atime, int b, int btime)
{
	int roota = find(a), rootb = find(b);
	if (roota != rootb)
	{
		bcj[rootb][0] = roota;
		bcj[roota][1] = min(bcj[roota][1], min(min(atime, btime), bcj[rootb][1]));
	}
}
bool cmp(int t)
{
	int l = 0, r = top + 1, mid;
	while (l + 1 != r)
	{
		mid = (l + r) >> 1;
		if (ans[mid] > t)
			r = mid;
		else
			l = mid;
	}
	return t >= top - r;
}
bool cmp1(dian a, dian b)
{
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp2(dian a, dian b)
{
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
void solve()
{
	cin >> n >> k;
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i].x >> d[i].y >> d[i].time;
		bcj[i][0] = i;
		bcj[i][1] = d[i].time;
		d[i].pos = i;
	}
	sort(d + 1, d + 1 + n, cmp1);
	for (int i = 1; i <= n;)
	{
		int j = i + 1;
		while (j <= n && d[i].x == d[j].x)
		{
			if (f(d[i].x, d[i].y, d[j].x, d[j].y))
			{
				join(d[i].pos, d[i].time, d[j].pos, d[j].time);
			}
			i = j++;
		}
		i = j;
	}
	sort(d + 1, d + 1 + n, cmp2);
	for (int i = 1; i <= n;)
	{
		int j = i + 1;
		while (j <= n && d[i].y == d[j].y)
		{
			if (f(d[i].x, d[i].y, d[j].x, d[j].y))
			{
				join(d[i].pos, d[i].time, d[j].pos, d[j].time);
			}
			i = j++;
		}
		i = j;
	}
	for (int i = 1; i <= n; i++)
	{ // n
		if (bcj[i][0] == i)
		{
			ans[++top] = bcj[i][1];
		}
	}
	sort(ans + 1, ans + top + 1); // nlogn
	int l = -1, r = min(ans[top], top), mid;
	while (l + 1 != r)
	{ // logn
		mid = (l + r) >> 1;
		if (cmp(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
