
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

int n, len;
string ans = "1";
char _s[maxn];

bool perfect(const string & s)
{
	bool ok = 0;
	for (char x : s)
	{
		if (x == '1')
		{
			if (ok)
				return 0;
			ok = 1;
			continue;
		}
		if (x > '0')
			return 0;
	}
	return 1;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", _s + 1);
		if (_s[1] == '0')
		{
			puts("0");
			return 0;
		}
		if (!perfect(string(_s + 1)))
			ans = string(_s + 1);
		else
			len += strlen(_s + 1) - 1;
	}
	printf("%s", ans.c_str());
	for (int i = 0; i < len; i++)
		printf("0");
}

