
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
#define f first
#define s second

int n, R[maxn], L[maxn];
int RevR[maxb], RevL[maxn];
int id[maxb];
int cnt[2][maxb];
set <int> all;
vector <int> ans;

void rec(int id, int v)
{
	//printf("%d %d\n", id, v);
	ans.push_back(id);
	if (!R[v])
		return;
	rec(R[v], RevL[id]);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", L + i, R + i);
		RevR[R[i]] = i;
		RevL[L[i]] = i;
		cnt[0][L[i]]++;
		cnt[1][R[i]]++;
		all.insert(L[i]);
		all.insert(R[i]);
	}
	all.erase(0);
	for (auto i = begin(all); i != end(all); i++)
	{
		int v = *i;
		if (cnt[0][v] + cnt[1][v] == 1)
		{
			if (cnt[0][v])
			{
				id[RevL[0]] = v;
			}
			else
			{
				id[RevR[0]] = v;
			}
		}
	}
	rec(id[RevL[0]], RevL[0]);
	for (int i = 0; i < int(ans.size()); i++)
		printf("%d ", ans[i]);
}