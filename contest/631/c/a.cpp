
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

int n, m;
int a[maxn], r[maxn], t[maxn], b[maxn];
int st[maxn], h;
multiset <int> se;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", t + i, r + i);
	for (int i = 1; i <= m; i++)
	{
		while (h && r[st[h - 1]] <= r[i])
			h--;
		if (!h || (t[st[h - 1]] != t[i]))
			st[h++] = i;
	}
//	for (int i = 0; i < h; i++)
//		printf("j:%d r:%d t:%d\n", st[i], r[st[i]], t[st[i]]);
//	puts("");
	for (int i = 1; i <= r[st[0]]; i++)
		se.insert(a[i]);
	int k = 1;
	for (int i = 0; i < h; i++)
	{
		int j = st[i], cnt = r[j] - (i + 1 < h ? r[st[i + 1]] : 0);
//		printf("j:%d c:%d\n", j, cnt);
		while (cnt--)
		{
			auto it = se.end(); it--;
			if (t[j] == 2)
				it = se.begin();
			b[k++] = *it;
			se.erase(it);
		}
	}
	reverse(b + 1, b + k);
	for (; k <= n; k++)
		b[k] = a[k];
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
}

