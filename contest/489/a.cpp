
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 120)
#define pb push_back
#define mp make_pair
#define vi vector <int>
#define f first
#define s second

int n, a[maxn];
vector < pair <int, int> > ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		int j = min_element(a + i, a + n) - a;
		ans.pb(mp(i, j));
		swap(a[i], a[j]);
	}
	cout << (int)(ans.size()) << '\n';
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i].f << " " << ans[i].s << '\n';
}