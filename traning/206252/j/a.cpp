
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

map <string, int> ton;
vector <string> v = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int dist(int a, int b)
{
	if (a < b)
		return (a - b + 12) % 12;
	return a - b;
}

bool check(int * x)
{
//	printf("%d %d %d\n", x[0], x[1], x[2]);
//	printf("%d %d %d\n\n", dist(x[1], x[0]), dist(x[2], x[1]), dist(x[2], x[0]));
	if (dist(x[1], x[0]) == 4 && dist(x[2], x[1]) == 3 && dist(x[2], x[0]) == 7)
	{
		puts("major");
		exit(0);
	}
	if (dist(x[1], x[0]) == 3 && dist(x[2], x[1]) == 4 && dist(x[2], x[0]) == 7)
	{
		puts("minor");
		exit(0);
	}
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (auto s : v)
		ton[s] = ton.size();
	string a, b, c;
	cin >> a >> b >> c;
	int x[] = {ton[a], ton[b], ton[c]};
	sort(x, x + 3);
	do
		check(x);
	while (next_permutation(x, x + 3));
	puts("strange");
}

