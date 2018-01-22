
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

int a[] = {'A', 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
map <char, int> order;
char _s[maxn];

string solve() {
	for (int i = 1; i <= 11; i++)
		order[a[i]] = i;
	ll k;
	scanf(I64 "%s", &k, _s + 1);
	int n = strlen(_s + 1);
	string s = string(_s + 1), ans = "";
//	puts(s.c_str());
	if (s.length() > 10) {
		ans = s.substr(0, n - 10);
		s = s.substr(n - 11, 10);
		n = s.length();
	}
	ll x = 0, pw = 1;
	for (int i = n - 1; i >= 0; i--) {
		x += pw * order[s[i]];
		pw *= 11ll;
	}
//	printf(I64 "+" I64 "\n", k, x);
	k += x;
	string buf = "";
	while (k > 0) {
		buf += a[k % 11];
		k /= 11;
	}
	reverse(buf.begin(), buf.end());
	if (buf.length() > n && ans.length() > 0) {
		buf.pop_back();
		bool ok = 1;
		reverse(ans.begin(), ans.end());
		string nans = "";
		for (int i = 0; i < (int)ans.size(); i++) {
			if (ans[i] == 'Y')
				nans += 'A';
			else {
				nans += ans[i] + 1;
				nans += ans.substr(i + 1, ans.size() - i - 1);
				ok = 0;
				break;
			}
		}
		if (ok)
			nans.pb('A');
		reverse(nans.begin(), nans.end());
		ans = nans;
//		cout << nans << '\n';
	}
	return ans + buf;
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

