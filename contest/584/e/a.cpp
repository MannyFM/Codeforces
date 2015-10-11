
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
//#define fn ""

int n, a[maxn], b[maxn], pos[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i), pos[b[i]] = i;
	for (int i = 1; i <= n; i++)
		a[i] = pos[a[i]];
	for (int i = 1; i <= n; i++)
		pos[a[i]] = i;
	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", pos[i]);
	puts("");
	*/
	vector <pii> path;
	int ans = 0;
	for (int i = n; i > 0; i--)
	{
		int j = pos[i];
		while (j < i)
		{
			j = pos[i] + 1;
			for (; a[j] > pos[i]; j++);
			int x = pos[i], y = j;
			path.pb(mp(x, y));
			swap(a[x], a[y]);
			//printf("pos[%d]=%d : %d %d (%d %d)\n", i, pos[i], x, y, a[x], a[y]);
			ans += abs(x - y);
			pos[a[x]] = x;
			pos[i] = y;
			/*
			printf("a:");
			for (int k = 1; k <= n; k++)
				printf("%d ", a[k]);
			puts("");
			printf("p:");
			for (int k = 1; k <= n; k++)
				printf("%d ", pos[k]);
			puts("\n");
			*/
		}
	}
	printf("%d\n%d\n", ans, path.size());
	for (pii x : path)
		printf("%d %d\n", x.F, x.S);
		
}
