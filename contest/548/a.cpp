
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
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

string s;
int k;

bool IsPal(string s)
{
	int n = int(s.size());
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - i - 1])
			return 0;
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	cin >> s;
	scanf("%d", &k);
	int n = int(s.size());
	if (n % k)
	{
		puts("NO");
		return 0;
	}
	int len = n / k;
	for (int i = 0; i < k; i++)
		if (!IsPal(s.substr(i * len, len)))
		{
			puts("NO");
			return 0;
		}
	puts("YES");
}

