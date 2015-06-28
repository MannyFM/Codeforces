
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 2 * 500000 + 10
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "painter"
#define F first
#define S second

struct item
{
	char f;
	int sum, cnt;
	int pre, suf;
};

item t[4 * maxn];

void push(int v, int tl, int tr)
{
	if (t[v].f == 'B')
	{
		if (tl != tr)
		{
			t[v + v].f = 'B';
			t[v + v + 1].f = 'B';
		}
		t[v].sum = tr - tl + 1;
		t[v].cnt = 1;
		t[v].pre = tr - tl + 1;
		t[v].suf = tr - tl + 1;
	}
	if (t[v].f == 'W')
	{
		t[v].sum = 0;
		t[v].cnt = 0;
		t[v].pre = 0;
		t[v].suf = 0;
	}
	t[v].f = 0;
}

void merge(int v, int tl, int tr)
{
	if (tl > tr)
		return;
	int tm = (tl + tr) >> 1;
	t[v].sum = t[v + v].sum + t[v + v + 1].sum;
	t[v].cnt = t[v + v].cnt + t[v + v + 1].cnt;
	if (t[v + v].suf > 0 && t[v + v + 1].pre > 0)
		t[v].cnt--;
	t[v].pre = t[v + v].pre;
	if (t[v + v].pre == (tm - tl + 1))
		t[v].pre += t[v + v + 1].pre;
	t[v].suf = t[v + v + 1].suf;
	if (t[v + v + 1].suf == (tr - tm))
		t[v].suf += t[v + v].suf;
}

void update(int v, int tl, int tr, int l, int r, char x)
{
	if (l > r)
		return;
	push(v, tl, tr);
	if (tl == l && tr == r)
	{
		t[v].f = x;
		push(v, tl, tr);
		t[v].f = x;
		//printf("%d %d %c\nc%d s%d p%d s%d\n\n", l, r, x, t[v].cnt, t[v].sum, t[v].pre, t[v].suf);
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), x);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, x);
	merge(v, tl, tr);
}

int n, l, sz;
char c;
const int shift = 500000 + 2;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	while(n--)
	{
		scanf("\n%c%d%d", &c, &l, &sz);
		l += shift;
		update(1, 0, maxn - 1, l, l + sz - 1, c);
		push(1, 0, maxn - 1);
		printf("%d %d\n", t[1].cnt, t[1].sum);
	}
}
