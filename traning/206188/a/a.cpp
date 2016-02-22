
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 50000 + 4;
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
#define fn "F"

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

ll T[26][4 * maxn];
ll add[26][4 * maxn];

void push(int k, int v, int tl, int tr)
{
	if (!add[k][v] || tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	T[k][v + v] += add[k][v] * (tm - tl + 1);
	T[k][v + v + 1] += add[k][v] * (tr - tm);
	add[k][v + v] += add[k][v];
	add[k][v + v + 1] += add[k][v];
	add[k][v] = 0;
}

void upd(int k, int v, int tl, int tr, int l, int r, int x)
{
	if (l > r || tr < l || r < tl)
		return;
	push(k, v, tl, tr);
	if (l <= tl && tr <= r)
	{
		add[k][v] += x;
		T[k][v] += x * (tr - tl + 1ll);
		push(k, v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(k, v + v, tl, tm, l, r, x);
	upd(k, v + v + 1, tm + 1, tr, l, r, x);
	T[k][v] = T[k][v + v] + T[k][v + v + 1];
}

ll get(int k, int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return 0ll;
	push(k, v, tl, tr);
	if (l <= tl && tr <= r)
		return T[k][v];
	int tm = (tl + tr) >> 1;
	return get(k, v + v, tl, tm, l, r)
		+ get(k, v + v + 1, tm + 1, tr, l, r);
}

ll bp(ll a, ll b, ll c)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}
	return ans;
}

int id[110], cnt[110];
vector <int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n, m;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 0; i < (int)v.size(); i++)
		id[v[i]] = i;
//	printf("%d", (int)v.size());
	scanf("%d%d", &n, &m);
	int mxk = (int)v.size();
	for (int i = 1; i <= m; i++)
	{
		int t, l, r, x;
		scanf("%d%d%d%d", &t, &l, &r, &x);
		if (!t)
		{
			ll ans = 1ll;
			for (int i = 0; i < mxk; i++)
			{
				ll alpha = get(i, 1, 1, n, l, r);
				ans = (ans * bp(v[i], alpha, x)) % x;
			}
			printf(I64 "\n", ans);
		}
		else
		{
			memset(cnt, 0, sizeof(cnt));
			int y = x;
			for (int i = 2; i * i <= y; i++)
				while (y % i == 0)
					cnt[i]++, y /= i;
			if (y > 1)
				cnt[y]++;
			for (int i = 0; i < mxk; i++)
			{
				int C = (t == 1) ? 1 : -1;
				upd(i, 1, 1, n, l, r, cnt[v[i]] * C);
			}
		}
	}
}

