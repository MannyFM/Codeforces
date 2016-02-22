
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
	T[k][v + v] += (tm - tl + 1) * add[k][v];
	T[k][v + v + 1] += (tr - tm) * add[k][v];
	add[k][v + v] += add[k][v];
	add[k][v + v + 1] += add[k][v];
	add[k][v] = 0ll;
}

void upd(int k, int v, int tl, int tr, int l, int r, ll x)
{
	push(k, v, tl, tr);
	if (l > r || tr < l || r < tl)
		return;
	if (l <= tl && tr <= r)
	{
		T[k][v] += (tr - tl + 1) * x;
		add[k][v] += x;
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
	push(k, v, tl, tr);
	if (l > r || tr < l || r < tl)
		return 0ll;
	if (l <= tl && tr <= r)
		return T[k][v];
	int tm = (tl + tr) >> 1;
	return get(k, v + v, tl, tm, l, r)
		+ get(k, v + v + 1, tm + 1, tr, l, r);
}

bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int id[110], pr[110], mx;
int cnt[110];

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

void parse(ll x)
{
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < mx && x > 1; i++)
	{
		while (x % pr[i] == 0)
			cnt[i]++, x /= pr[i];
	}
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
//		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 2; i <= 100; i++)
		if (isPrime(i))
			pr[mx++] = i, id[i] = mx - 1;
	printf("%d: ", mx);
	for (int i = 0; i < mx; i++)
		printf("%d ", pr[i]);
	puts("");
	int n, m, l, r, x, t;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &t, &l, &r, &x);
		printf("/");
		if (!t)
		{
			ll ans = 1ll;
			printf("|");
			for (int i = 0; i < mx; i++)
			{
				printf("+");
				ll cnt = get(i, 1, 1, n, l, r);
				printf("-");
				if (cnt)
					printf("cnt[%d]=" I64 " ", pr[i], cnt);
				printf("$");
				ans = (ans * bp(pr[i], cnt, x));
				printf("!");
			}
			puts("");
			printf(I64 "\n", ans);
		}
		else
		{
			parse(x);
			int c = t == 2 ? 1 : -1;
			for (int i = 0; i < mx; i++)
				if (cnt[i])
				{
					upd(i, 1, 1, n, l, r, cnt[i] * c);
					printf("cnt[%d]=%d ", pr[i], cnt[i]);
				}
			puts("");
		}
		puts("\\");
	}
}

