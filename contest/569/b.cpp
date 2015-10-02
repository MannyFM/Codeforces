
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

int n;
int a[maxn];
bool was[maxn], ch[maxn];
set <int> us;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		us.insert(i);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		us.erase(a[i]);
		ch[i] = a[i] < 1 || a[i] > n || was[a[i]];
		was[a[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		if (ch[i])
		{
			a[i] = * us.begin();
			us.erase(us.begin());
		}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}
