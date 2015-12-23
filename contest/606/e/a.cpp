
	#include <bits/stdc++.h>

	using namespace std;

	typedef long double ld;
	typedef long long  ll;
	typedef unsigned long long ull;
	typedef map <int, int> mii;
	typedef pair <int, int> pii;
	typedef pair <ll, ll> pll;

	int const maxn = int(1e5 + 12);
	int const maxb = int(2e6 + 12);
	int const inf = int(1e9 + 7);
	ll const linf = ll(1e18 + 12);
	ld const eps = 1e-17;
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

	struct pt
	{
		int x, y;
		pt() : x(0), y(0) {};
		pt(int x, int y) : x(x), y(y) {};
		pt operator + (const pt & b) const
		{
			return pt(x + b.x, y + b.y);
		}
		pt operator - (const pt & b) const
		{
			return pt(x - b.x, y - b.y);
		}
		int operator * (const pt & b) const
		{
			return x * b.y - y * b.x;
		}
		int operator % (const pt & b) const
		{
			return x * b.x + y * b.y;
		}
		ll len2() const
		{
			return x * 1ll * x + y * 1ll * y;
		}
	};

	int tri(const pt & a, const pt & b, const pt & c)
	{
		return (b - a) * (c - b);
	}

	bool clock(const pt & a, const pt & b, const pt & c)
	{
		return tri(a, b, c) > 0;
	}

	bool nclock(const pt & a, const pt & b, const pt & c)
	{
		return tri(a, b, c) <= 0;
	}

	bool cmp(const pt & a, const pt & b)
	{
		int t = a * b;
		return t ? t > 0 : a.len2() < b.len2();
	}

	void convex(vector <pt> & v)
	{
		int n = int(v.size());
		if (n < 3)
			return;
		vector <pt> ans;
		pt start = v[0];
		for (int i = 0; i < n; i++)
			if (v[i].x < start.x || (v[i].x == start.x && v[i].y < start.y))
				start = v[i];
		for (int i = 0; i < n; i++)
			v[i] = v[i] - start;
		sort(v.begin(), v.end(), cmp);
		ans.pb(v[0]);
		/*
		for (pt p : v)
			printf("(%d %d)", p.x, p.y);
		puts("");
		for (pt p : ans)
			printf("[%d %d] ", p.x, p.y);
		puts("");
		*/
		for (int i = 1; i < n; i++)
		{
			while (ans.size() > 1 && nclock(ans[ans.size() - 2], ans.back(), v[i]))
				ans.pop_back();
			ans.pb(v[i]);
			/*
			for (pt p : ans)
				printf("[%d %d] ", p.x, p.y);
			puts("");
			*/
		}
		for (int i = 0; i < int(ans.size()); i++)
			ans[i] = ans[i] + start;
		v = ans;
	}

	template <typename T>
	T max(const T & a, const T & b, const T & c)
	{
		return max(max(a, b), c);
	}

	template <typename T>
	T min(const T & a, const T & b, const T & c)
	{
		return min(min(a, b), c);
	}

	int n, p, v;
	vector <pt> e;
	int a[maxn], b[maxn], ma, mb;
	ld ans = 1e18;

	inline ld f(ld t, int i)
	{
		ld pe = t * e[i].x,
			ve = t * e[i].y;
		ld extra = max((p - pe) / e[i - 1].x, (v - ve) / e[i - 1].y);
		return t + max(extra, ld(0));
	}

	int main()
	{
		#ifdef fn
			freopen(fn ".in", "r", stdin);
			freopen(fn ".out", "w", stdout);
		#endif
		scanf("%d%d%d", &n, &p, &v);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", a + i, b + i);
			ma = max(ma, a[i]);
			mb = max(mb, b[i]);
			e.pb(pt(a[i], b[i]));
			ans = min(ans, max((ld)p / a[i], (ld)v / b[i]));
		}
		e.pb(pt(ma, 0));
		e.pb(pt(0, mb));
		convex(e);
		n = int(e.size());
		/*
		for (int i = 0; i < n; i++)
			printf("%d %d\n", e[i].x, e[i].y);
		*/
		for (int i = 1; i < n; i++)
		{
			ld l = 0, r = 2e6;
			for (int step = 200; step > 0; step--)
			{
				ld m1 = l + (r - l) / 3,
					m2 = r - (r - l) / 3;
				if (eps < f(m2, i) - f(m1, i))
					r = m2;
				else
					l = m1;
			}
			ans = min(ans, f(l, i), f(r, i));
			//printf("%d %f\n", i, (double)f(l, i));
		}
		printf("%.10f\n", double(ans) - eps);
	}

