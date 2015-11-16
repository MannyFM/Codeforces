
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

vector <int> v;

void ADD()
{
	/*
	if (v.empty())
	{
		for (int i = 0; i < n; i++)
			v.pb(a[i]);
		return;
	}
	int pos = v.size() - n;
	for (; pos < int(v.size()); pos++)
	{
		//printf("%d: ", pos);
		bool ok = 1;
		for (int j = 0; pos + j < int(v.size()); j++)
		{
			//printf("%d ", v[pos + j]);
			if (v[pos + j] != a[j])
			{
				ok = 0;
				break;
			}
		}
		//puts("");
		if (ok)
		{
			//puts("+");
			//printf("%d %d\n", pos, (v.size() - pos));
			for (int j = (v.size() - pos); j < n; j++)
				v.pb(a[j]);
			return;
		}
	}
	*/
	for (int i = 0; i < n; i++)
		v.pb(a[i]);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	srand(time(0));
	scanf("%d", &n);
	ll cnt = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cnt *= (i + 1);
	}
	do
	{
		if (find())
			continue;
		ADD();
		
		cerr << "cnt:" << cnt << "  ";
		for (int i = 0; i < n; i++)
			cerr << a[i] << " ";
		cerr << '\n';
		
		printf("v:");
		for (int x : v)
			printf("%d ", x);
		puts("");
		
		if (int(v.size()) <= n)
			continue;
		for (int i = int(v.size()) - n; i <= int(v.size()) - n; i++)
		{
			printf("b:");
			for (int j = 0; j < n; j++)
			{
				b[j] = v[i + j];
				printf("%d ", b[j]);
			}
			if (add())
			{
				printf("-");
				cnt--;
			}
			puts("");
		}
	} while(next_permutation(a, a + n));
	printf("%d\n", v.size());
	cnt = 0;
	for (int x : v)
	{
		printf("%d ", x);
		/*
		cnt++;
		if (cnt == n)
			puts(""), cnt -= n;
		*/
	}
	
}
