
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

string s;
bool us[maxn], f1, f2;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	cin >> s;
	for (int i = 0; i < int(s.size()) - 1; i++)
		if (s[i] == 'A' && s[i + 1] == 'B')
		{
			us[i] = us[i + 1] = 1;
			f1 = 1;
			break;
		}
	for (int i = 0; i < int(s.size()) - 1; i++)
		if (s[i] == 'B' && s[i + 1] == 'A' && !us[i] && !us[i + 1])
		{
			f2 = 1;
			break;
		}
	if (f1 && f2)
	{
		puts("YES");
		return 0;
	}
	f1 = f2 = 0;
	memset(us, 0, sizeof us);
	for (int i = 0; i < int(s.size()) - 1; i++)
		if (s[i] == 'B' && s[i + 1] == 'A')
		{
			us[i] = us[i + 1] = 1;
			f2 = 1;
			break;
		}
	for (int i = 0; i < int(s.size()) - 1; i++)
		if (s[i] == 'A' && s[i + 1] == 'B' && !us[i] && !us[i + 1])
		{
			//us[i] = us[i + 1]++;
			f1 = 1;
			break;
		}
	if (f1 && f2)
		puts("YES");
	else
		puts("NO");

}

