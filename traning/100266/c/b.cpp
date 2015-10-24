
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
#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn "cipher"

int next[12][3265925], sz, end[3265925];
int a[12], b[12], n;
int C[12];

bool add()
{
	for (int i = 1; i <= n; i++)
		C[i] = 0;
	for (int i = 0; i < n; i++)
		C[b[i]]++;
	for (int i = 1; i <= n; i++)
		if (!C[i])
			return 0;
	int v = 0;
	for (int i = 0; i < n; i++)
	{
		if (!next[b[i]][v])
			next[b[i]][v] = ++sz;
		v = next[b[i]][v];
	}
	if (end[v])
		return 0;
	else
	{
		end[v] = 1;
		return 1;
	}
}

bool find()
{
	int v = 0;
	for (int i = 0; i < n; ++i)
	{
		 if (!next[a[i]][v])
		 	return 0;
		 v = next[a[i]][v];
	}
	return end[v];
}

int us[10], pos = 1;

void Next()
{
	memset(us, 0, sizeof(us));
	for (int i = 0; i + pos < n; i++)
	{
		a[i] = a[i + pos];
		us[a[i]]++;
	}
	for (int i = n - pos; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (!us[j])
			{
				us[j] = 1;
				a[i] = j;
				break;
			}
	}
	
}

vector <int> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cnt *= i + 1;
	}
	Next();
	while (cnt)
	{
		Next();
		while (pos < n && find())
		{
			pos++;
			Next();
		}
		if (pos == n)
		{
			pos = 1;
			while (find())
				next_permutation(a, a + n);
		}
		if (add())
			cnt--;
		if (int(v.size()) <= n)
			continue;
		for (int j = int(v.size()) - n; j < int(v.size()); j++)
		{
			
		}
			
	}
	
}
