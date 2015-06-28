
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e6 + 12)
#define shift int(5e5 + 2)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "painter"
#define f first
#define s second
#define LOCAL

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}
// 0 - White
// 1 - Black
int t[4 * maxn];
int n;

void push(int v)
{
	if (t[v] == -1)
		return;
	t[v + v] = t[v];
	t[v + v + 1] = t[v];
	t[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int color)
{
	if (l > r)
		return;
	push(v);
	if (tl == l && tr == r)
	{
		t[v] = color;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(v + v, tl, tm, l, min(r, tm), color);
	update(v + v + 1, tm + 1, tr, max(l, tm + 1), r, color);
}

int get(int v, int tl, int tr, int pos)
{
	if (tl == tr)
		return t[v];
	push(v);
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return get(v + v, tl, tm, pos);
	else
		return get(v + v + 1, tm + 1, tr, pos);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	n = maxn;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		char c;
		int l, len;
		scanf("\n%c%d%d", &c, &l, &len);
		update(1, 0, n - 1, l + shift, l + len + shift, c == 'B');
	}
	int l = -1;
	ll len = 0ll, cnt = 0ll;
	for (int i = 0; i < n; i++)
	{
		int c = get(1, 0, n - 1, i);
		if (c)
		{
			if (l == -1)
				l = i;
		}
		else
		{
			if (l != -1)
			{
				printf("%d %d\n", l - shift, i - 1 - shift);
				cnt++;
				len += (i - l);
				l = -1;
			}
		}
	}
	printf("%I64d %I64d", cnt, len);
}