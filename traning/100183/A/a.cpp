
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define inf (int)(1e9 + 7)
#define pb push_back

int n, m, cyc, s, t;
int us[maxn], pr[maxn];
int path[maxn], sz;
vector <int> g[maxn];

void dfs(int v)
{
    us[v] = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!us[to])
        {
            pr[to] = v;
            dfs(to);
        }
        else
        {
            cyc = 1;
            pr[to] = v;
            s = v;
            t = to;
            return;
        }
    }
}

int main()
{
    freopen("cycle2.in", "r", stdin);
    //freopen("cycle2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
    }
    for(int i = 1; i <= n; i++)
        if (!us[i])
            dfs(i);
    if (cyc)
    {
        puts("YES");
        /*
        for(int i = 1; i <= n; i++)
            printf("%d ", pr[i]);
        puts("");
        */
        int y = t;
		for (int cur=y; ; cur = pr[cur]) {
			path[sz++] = (cur);
			if (cur == y && sz > 1)  break;
		}
		reverse(path + 1, path + sz);
        for(int i = 1; i < sz; i++)
            printf("%d ", path[i]);
    }
    else
        puts("NO");
}
