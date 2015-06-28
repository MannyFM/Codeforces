
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

int n;
int F, f[20];
vector <int> v;

void rec(int F)
{
	if (F == 1)
	{
		printf("%d! = ", n);
		for (auto i : v)
			printf("%d! * ", i);
		puts("");
		return;
	}
	for (int i = 2; i < 10; i++)
		if (F % f[i] == 0)
		{
			v.pb(i);
			rec(F / f[i]);
			v.pop_back();
		}

}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	f[0] = f[1] = 1;
	for (int i = 2; i < 12; i++)
		f[i] = f[i - 1] * i;
	for (n = 1; n < 10; n++)
	{
		rec(f[n]);
		puts("");
	}
}