
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

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

int n, x;
map <int, int> cnt;
priority_queue <pii> q;
vector <vector <int>> ans;
pii r[4];
int a[4];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		cnt[x]++;
	}
	for (pii x : cnt)
		q.push({x.S, x.F});
	while (q.size() > 2)
	{
		r[0] = q.top(); q.pop();
		r[1] = q.top(); q.pop();
		r[2] = q.top(); q.pop();
		a[0] = r[0].S;
		a[1] = r[1].S;
		a[2] = r[2].S;
		sort(a, a + 3);
		r[0].F--;
		r[1].F--;
		r[2].F--;
		if (r[0].F > 0)
			q.push(r[0]);
		if (r[1].F > 0)
			q.push(r[1]);
		if (r[2].F > 0)
			q.push(r[2]);
		ans.pb({a[2], a[1], a[0]});
	}

	printf("%d\n", (int)ans.size());
	for (auto x : ans)
	{
		for (int y : x)
			printf("%d ", y);
		puts("");
	}
}

