
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

int a[] = {'-', 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
map <char, int> order;
char _s[maxn];

string solve() {
	for (int i = 1; i <= 11; i++)
		order[a[i]] = i;
	ll k;
	scanf(I64 "%s", &k, _s);
	string buf = "";
	while (k > 0) {
		int x = k % 11, y = k / 11;
		if (x == 0)
				y--, x = 11;
		buf += a[x];
		k = y;
	}
//	cout << (_s) << "+" << buf << '\n';
	int n = strlen(_s), m = buf.length();
	reverse(_s, _s + n);
	string ans = "";
	int ok = 0;
	for (int i = 0; i < max(n, m); i++) {
		int b = (i < n ? order[_s[i]] : 0) + (i < m ? order[buf[i]] : 0) + ok;
		int x = b % 11;
		ok = b / 11;
		if (x == 0) {
			x = 11;
			ok--;
		}
		ans += a[x];
	}
	if (ok)
		ans += 'A';
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		puts(solve().c_str());
	}
}

