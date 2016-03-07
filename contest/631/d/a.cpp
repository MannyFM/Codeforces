
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxlen = int(2e6 + 12);
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
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

struct pt
{
	ll cnt;
	char x;
	pt() {}
	pt(int a, char b) : cnt(a), x(b) {};
	bool operator == (const pt & p)
	{
		return p.cnt == cnt && p.x == x;
	}
	bool operator <= (const pt & p)
	{
		return p.cnt >= cnt && p.x == x;
	}
};

int n, m;
vector <pt> s, t, w;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		char c;
		scanf("%d-%c", &x, &c);
		if (s.empty() || s.back().x != c)
			s.pb({x, c});
		else
			s.back().cnt += x;
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		char c;
		scanf("%d-%c", &x, &c);
		if (t.empty() || t.back().x != c)
			t.pb({x, c});
		else
			t.back().cnt += x;
	}
	n = (int)s.size();
	m = (int)t.size();
	if (m == 1)
	{
		ll ans = 0ll;
		for (int i = 0; i < n; i++)
			if (t[0] <= s[i])
				ans += s[i].cnt - t[0].cnt + 1;
		printf(I64, ans);
		rt("");
	}
	if (m == 2)
	{
		ll ans = 0ll;
		for (int i = 0; i + 1 < n; i++)
			if (t[0] <= s[i] && t[1] <= s[i + 1])
				ans++;
		printf(I64, ans);
		rt("");
	}
	for (int i = 1; i + 1 < (int)t.size(); i++)
		w.pb(t[i]);
	w.pb({0, '#'});
	for (int i = 0; i < (int)s.size(); i++)
		w.pb(s[i]);
	vector <int> p(w.size(), 0);
	int N = (int)p.size();
	for (int i = 1; i < N; i++)
	{
		int j = p[i - 1];
		while (j > 0 && !(w[i] == w[j]))
			j = p[j - 1];
		j += w[i] == w[j];
		p[i] = j;
	}
//	for (auto x : w)
//		printf("(%d-%c) ", x.cnt, x.x);
//	puts("");
//	for (int i = 0; i < N; i++)
//		printf("%d ", p[i]);
//	puts("");
	ll ans = 0ll;
	for (int i = m; i + 1 < N; i++)
	{
		int j = p[i];
//		if (j == m - 2)
//			printf("%d ", i);
		if (j == m - 2 && t[0] <= w[i - j] && t.back() <= w[i + 1])
			ans++;
	}
	printf(I64, ans);
}

