
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e3 + 12)
#define pb push_back
#define inf (int)(1e9 + 7)

int n, m, d[maxn][maxn];
vector <int> g[maxn];

void bfs(int s)
{
    queue <int> q;
    vector <char> us(n + 1, 0);
    us[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < (int)g[v].size(); i++)
        {
            int to = g[v][i];
            if (!us[to])
            {
                d[s][to] = d[s][v] + 1;
                us[to] = 1;
                q.push(to);
            }
        }
    }
}

int main()
{
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int v = 1; v <= n; v++)
    {
        bfs(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += d[i][j];
    ans /= 2;
    printf("%d", ans);
    /*
    puts("");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ", d[i][j]);
        puts("");
    }*/
}
