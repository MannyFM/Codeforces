
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
#define fn "a"
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()

vector <int> shuf(int n)
{
	vector <int> v;
	for (int i = 1; i <= n; i++)
		v.pb(i);
	for (int i = n - 1; i > 0; i--)
		swap(v[i], v[rand() % n]);
	return v;
}

int main()
{
	
	#ifdef fn
		//freopen(fn".in", "r", stdin);
		//freopen(fn".out", "w", stdout);
	#endif
	srand(time(0));
	ofstream out;
	ifstream normf, ansf;
	for (int step = 0; step < 1; step++)
	{
		out.open(fn".in");
		int N = 4000, M = 1000000;
		out << N << "\n";
		for (int i = 0; i < N; i++)
			out << M << " " << M << " 1\n";

		out.close();
		
	}
}
