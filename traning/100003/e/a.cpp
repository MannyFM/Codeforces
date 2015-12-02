
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
#define fn "gems"
#define NO {puts("-1"); exit(0);}

int const sz = 26;
char s[maxn];
int a[maxn];
int n, k;
ll cnt[sz], to[sz][sz];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - 'a';
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < sz; j++)
			to[a[i]][j] += cnt[j];
		cnt[a[i]]++;
		/*
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				if (to[i][j])
					printf("to[%c][%c]=%d\n", i + 'a', j + 'a', to[i][j]);
		puts("");
		*/
	}
	//puts("");
	ll ans = 0;
	for (int i = 1; i <= k; i++)
	{
		char x, y;
		scanf(" %c%c", &x, &y);
		ans += to[x - 'a'][y - 'a'];
	}
	printf(I64, ans);
}
