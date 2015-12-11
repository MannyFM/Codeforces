
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

int h, w, n, q;
map <pii, int> u, d, r, l;
set <pii> all;
map <int, set <int> > H, W;
int cnt;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &y, &x);
		W[x].insert(y);
		H[y].insert(x);
		all.insert({x, y});
	}
	/*
	puts("W");
	for (auto u : W)
	{
		printf("%d: ", u.F);
		for (int x : u.S)
			printf("%d ", x);
		puts("");
	}
	puts("H");
	for (auto u : H)
	{
		printf("%d: ", u.F);
		for (int x : u.S)
			printf("%d ", x);
		puts("");
	}
	*/
	for (pii v : all)
	{
		int x = v.F, y = v.S;
		auto it = H[y].upper_bound(x);
		if (it != H[y].end())
			r[v] = *it;
		else
			r[v] = inf;
		it = H[y].lower_bound(x);
		if (it != H[y].begin())
		{
			it--;
			l[v] = *it;
		}
		else
			l[v] = -inf;
		it = W[x].upper_bound(y);
		if (it != W[x].end())
			u[v] = *it;
		else
			u[v] = inf;
		it = W[x].lower_bound(y);
		if (it != W[x].begin())
		{
			it--;
			d[v] = *it;
		}
		else
			d[v] = -inf;
		if (u[v] != inf && u[v] != y + 1)
		{
			cnt++; //printf("u");
		}
		if (d[v] != -inf && d[v] != y - 1)
		{
			cnt++; //printf("d");
		}
		if (r[v] != inf && r[v] != x + 1)
		{
			cnt++; //printf("r");
		}
		if (l[v] != -inf && l[v] != x - 1)
		{
			cnt++; //printf("l");
		}
		//printf("%d   %d %d  l:%d r:%d u:%d d:%d\n", cnt, v.F, v.S, l[v], r[v], u[v], d[v]);
	}
	//printf("%d\n", cnt);
	puts(!cnt ? "YES" : "NO");
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &y, &x);
		pii v = {x, y};
		if (all.count(v))
		{
			puts(!cnt ? "YES" : "NO");
			continue;
		}
		all.insert({x, y});
		H[y].insert(x);
		W[x].insert(y);
		auto it = H[y].lower_bound(x);
		int lx = -inf, rx = inf;
		if (it != H[y].begin())
		{
			it--;
			lx = *it;
			if (r[{lx, y}] != lx + 1 && r[{lx, y}] != inf)
			{
				cnt--;
				//printf("-l");
			}
		}
		it = H[y].upper_bound(x);
		if (it != H[y].end())
		{
			rx = *it;
			if (l[{rx, y}] != rx - 1 && l[{rx, y}] != -inf)
			{
				cnt--;
				//printf("-r");
			}
		}
		if (lx != -inf)
		{
			if (x != lx + 1)
			{
				cnt += 2;
				//printf("+l");
			}
			r[{lx, y}] = x;
		}
		if (rx != inf)
		{
			if (x != rx - 1)
			{
				cnt += 2;
				//printf("+r");
			}
			l[{rx, y}] = x;
		}
		int ly = -inf, ry = inf;
		it = W[x].lower_bound(y);
		if (it != W[x].begin())
		{
			it--;
			ly = *it;
			if (u[{x, ly}] != ly + 1 && u[{x, ly}] != inf)
			{
				cnt--;
				//printf("-d");
			}
		}
		it = W[x].upper_bound(y);
		if (it != W[x].end())
		{
			ry = *it;
			if (d[{x, ry}] != ry - 1 && d[{x, ry}] != -inf)
			{
				cnt--;
				//printf("-u");
			}
		}
		if (ly != -inf)
		{
			if (y != ly + 1)
			{
				cnt += 2;
				//printf("+d");
			}
			u[{x, ly}] = y;
		}
		if (ry != inf)
		{
			if (y != ry - 1)
			{
				cnt += 2;
				//printf("+u");
			}
			d[{x, ry}] = y;
		}
		l[v] = lx;
		r[v] = rx;
		u[v] = ry;
		d[v] = ly;
		//printf("%d   %d %d  l:%d r:%d u:%d d:%d\n", cnt, v.F, v.S, l[v], r[v], u[v], d[v]);
		puts(!cnt ? "YES" : "NO");
	}
}
