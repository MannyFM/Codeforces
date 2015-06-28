
#include <bits/stdc++.h>

using namespace std;

int n, m;
char v[30], g[30];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> g[i];
    for(int j = 0; j < m; j++)
        cin >> v[j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            bool in = 0, out = 0;
            if (i + 1 < n)
            {
                if (v[j] == '^')
                    in = 1;
                else
                    out = 1;
            }
            if (i >= 1)
            {
                if (v[j] == '^')
                    out = 1;
                else
                    in = 1;
            }
            if (j + 1 < m)
            {
                if (g[i] == '>')
                    out = 1;
                else
                    in = 1;
            }
            if (j >= 1)
            {
                if (g[i] == '>')
                    in = 1;
                else
                    out = 1;
            }
            if (!in || !out)
            {
                puts("NO");
                return 0;
            }
        }
    puts("YES");
}
