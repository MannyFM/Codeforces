
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
#define fn "billboard"

int k, n, m;
char s[110][110][110];
int a[110][110];
vector <vector <pii>> v, buf;
vector <pii> x, y, z;

void check()
{
	for (auto b : v)
	{
		x.clear();
		y.clear();
		z.clear();
		for (int i = 0; i < int(b.size()); i++)
		{
			if (a[b[i].F][b[i].S] == -1)
				x.pb(b[i]);
			if (a[b[i].F][b[i].S] == 0)
				y.pb(b[i]);
			if (a[b[i].F][b[i].S] == 1)
				z.pb(b[i]);
		}
		/*
		printf("b: ");
		for (pii i : b)
			printf("(%d %d)", i.F, i.S);
		puts("");
		printf("x: ");
		for (pii i : x)
			printf("(%d %d)", i.F, i.S);
		puts("");
		printf("y: ");
		for (pii i : y)
			printf("(%d %d)", i.F, i.S);
		puts("");
		printf("z: ");
		for (pii i : z)
			printf("(%d %d)", i.F, i.S);
		puts("");
		*/
		if (!x.empty())
			buf.pb(x);
		if (!y.empty())
			buf.pb(y);
		if (!z.empty())
			buf.pb(z);
	}
	v = buf;
	buf.clear();
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int t = 1; t <= m; t++)
			{
				char C;
				scanf(" %c", &C);
				s[i][j][t] = (C == '*');
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = s[1][i][j];
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	*/
	vector <pii> X;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			X.pb(mp(i, j));
	v.pb(X);
	check();
	//puts("");
	for (int t = 2; t <= k; t++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = s[t][i][j] - s[t - 1][i][j];
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", a[i][j]);
			puts("");
		}
		*/
		check();
		//puts("");
	}
	printf("%d", v.size());
}
