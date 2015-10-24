
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
double const eps = 1e-12;
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
#define fn "advert"

int W, H, n;
int a[maxn], b[maxn];

bool eq(double a, double b)
{
	return abs(a - b) <= eps;
}

bool les (double a, double b)
{
	return a - b < eps;
}

bool F(double k)
{
	double curH = k * b[1], allH = curH, curW = k * a[1];
	if (les(H + .0, allH) || les(W + .0,curW))
		return 0;
	for (int i = 2; i <= n; i++)
	{
		if ((eq(curH, -1.0) || eq(curH, k * b[i])) && les(curW + k * a[i], W))
			curW += k * a[i];
		else
		{
			if (les(H + .0, allH + k * b[i]))
				return 0;
			allH += k * b[i];
			curW = k * a[i];
		}
		curH = k * b[i];
	}
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &W, &H);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i);
//	double k;
//	scanf("%lf", &k);
//	printf("%d\n", F(k));
	double l = eps, r = 1e9, k;
	for (int step = 0; step <= 200; step++)
	{
		 k = (l + r) / 2;
		 if (F(k))
		 	l = k;
		 else
		 	r = k;
	}
	printf("%.09f", k);
}
