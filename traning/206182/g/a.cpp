
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(5e5 + 12);
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

int n, k, a[maxn];
int cur;
map <int, int> cnt;
int L, R, ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int j = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
		{
			cnt[a[i - 1]]--;
			if (!cnt[a[i - 1]])
				cur--;
		}
		while (j <= n)
		{
			cnt[a[j]]++;
			if (cnt[a[j]] == 1)
				cur++;
			if (cur > k)
			{
				cur--;
				cnt[a[j]]--;
				j--;
				break;
			}
			j++;
		}
//		printf("[%d %d %d] ", i, j, cur);
		if (umax(ans, min(j, n) - i + 1))
			L = i, R = min(j, n);
		j++;
	}
	printf("%d %d", L, R);
}

