
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define fn "painter"

struct item
{
	int fill, cnt, suf, pre, sum;
	item()
	{
		fill = -1;
		cnt = suf = pre = sum = 0;
	}
} T[4 * maxn];

void push(int v, int tl, int tr)
{
	if (T[v].fill == -1 || tl == tr)
		return;
	T[v + v].fill = T[v].fill;
	T[v + v].pre = T[v + v].suf = T[v].fill;
	T[v + v].cnt = 1;
	T[v + v + 1].fill = T[v].fill;
	T[v + v + 1].pre = T[v + v + 1].suf = T[v].fill;
	T[v + v + 1].cnt = 1;
	T[v].sum = T[v].fill * (tr - tl + 1);
	T[v].cnt = T[v].fill;
	T[v].fill = -1;
}

item cmb(item a, item b)
{
	item c = item();
	c.cnt = a.cnt + b.cnt;
	if (a.suf && b.pre)
		c.cnt--;
	c.pre = a.pre;
	c.suf = b.suf;
	c.sum = a.sum + b.sum;
	return c;
}

void upd(int v, int tl, int tr, int l, int r, int c)
{
	if (l > r || tr < l || r < tl)
		return;
	push(v, tl, tr);
	if (l <= tl && tr <= r)
	{
		T[v].fill = c;
		T[v].cnt = c;
		T[v].sum = (tr - tl + 1) * c;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v + v, tl, tm, l, r, c);
	upd(v + v + 1, tm + 1, tr, l, r, c);
	T[v] = cmb(T[v + v], T[v + v + 1]);
}

item get(int v, int tl, int tr, int l, int r)
{
	if (l > r || tr < l || r < tl)
		return T[0];
	push(v, tl, tr);
	if (l <= tl && tr <= r)
		return T[v];
	int tm = (tl + tr) >> 1;
	return cmb(get(v + v, tl, tm, l, r),
		get(v + v + 1, tm + 1, tr, l, r));
}

int l, len;
char c;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf(" %c%d%d", &c, &l, &len);
		upd(1, 1, N, l, l + len - 1, c == 'B');
		item t = get(1, 1, N, 1, N);
		printf("%d %d\n", t.cnt, t.sum);
	}
}
