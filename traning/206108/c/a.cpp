
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

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

char s[20];

bool check(int a, int b)
{
//	puts("");
	for (int j = 1; j <= b; j++)
	{
		int cur = j;
		bool ok = 1;
		for (int i = 1; i <= a; i++)
		{
			if (s[cur] == 'O')
				ok = 0;
//			printf("%c", s[cur]);
			cur += b;
		}
//		puts("");
		if (ok)
			return 1;
	}
	return 0;
}

void solve()
{
	vi ans;
	scanf("%s", s + 1);
	for (int a = 1; a <= 12; a++)
		if (12 % a == 0 && check(a, 12 / a))
			ans.pb(a);
	printf("%d ", (int)ans.size());
	for (int x : ans)
		printf("%dx%d ", x, 12 / x);
	puts("");
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}

