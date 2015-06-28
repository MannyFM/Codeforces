
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fn "chess"

int n, a[maxn];
bool v[maxn], h[maxn];
vector < pair <int, int> > ans;

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < a[i]; j++)
    	{
    		if (!v[i] && !h[j])
    		{
    			ans.pb(mp(i + 1, j + 1));
    			v[i] = h[j] = 1;
    		}
    	}
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
    	printf("%d %d\n", ans[i].f, ans[i].s);
}
