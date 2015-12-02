
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
#define fn "square"

string r[4], c[4];
int n[4], m[4];

string a[4][4];
string R[4], C[4];

int f()
{
	a[3][1] = a[3][2] = a[3][3] = "";
	C[1] = C[2] = C[3] = "";
	R[1] = R[2] = R[3] = "";
	for (int k = 1; k <= 3; k++)
	{
		int pos = 0;
		for (int j = 1; j < 3; j++)
			for (int i = 0; i < int(a[j][k].length()) && pos < m[k] && a[j][k][i] == c[k][pos]; i++)
				pos++;
		while (pos < m[k])
			a[3][k].pb(c[k][pos++]);
	}
	/*
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			printf("%s+", a[i][j].c_str());
		puts("");
	}
	puts("");
	*/
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			R[i] += a[i][j];
			C[j] += a[i][j];
		}
	/*
	for (int i = 1; i <= 3; i++)
		printf("%s ", R[i].c_str());
	puts("");
	for (int i = 1; i <= 3; i++)
		printf("%s ", C[i].c_str());
	puts("");
	*/
	for (int i = 1; i <= 3; i++)
		if (R[i] != r[i])
		{
			//printf("!%d\n%s\n%s\n", i, R[i].c_str(), r[i].c_str());
			return 0;
		}
	for (int i = 1; i <= 3; i++)
		if (C[i] != c[i])
		{
			//printf("@%d\n%s\n%s\n", i, C[i].c_str(), c[i].c_str());
			return 0;
		}
	return 1;
}

void cut(int x, int x1, int y, int y1)
{
	a[1][1] = r[1].substr(0, x);
	a[1][2] = r[1].substr(x, x1 - x);
	a[1][3] = r[1].substr(x1, n[1] - x1);
	a[2][1] = r[2].substr(0, y);
	a[2][2] = r[2].substr(y, y1 - y);
	a[2][3] = r[2].substr(y1, n[2] - y1);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 1; i <= 3; i++)
	{
		getline(cin, r[i]);
		n[i] = int(r[i].length());
	}
	for (int i = 1; i <= 3; i++)
	{
		getline(cin, c[i]);
		m[i] = int(c[i].length());
	}
	
	int ans = 0;
	//cut(1, 2, 1, 2);
	//ans += f();
	
	for (int x = 0; x <= n[1]; x++)
		for (int x1 = x; x1 <= n[1]; x1++)
			for (int y = 0; y <= n[2]; y++)
				for (int y1 = y; y1 <= n[2]; y1++)
				{
					cut(x, x1, y, y1);
					ans += f();
				}
	
	printf("%d", ans);
}
