
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e3 + 12)
#define maxs (int)(1e6 + 123)
#define inf (int)(1e9 + 7)

int n, x[maxn];
string s[maxn];
map <string, int> m;
map <int, string> in;
set <string> v;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i] >> x[i];
        m[s[i]] += x[i];
    }
    int ans = -inf;
    for (int i = 0; i < n; i++)
    	ans = max(ans, m[s[i]]);
    for (int i = 0; i < n; i++)
    {
    	if (ans == m[s[i]])
    		v.insert(s[i]);
    }
    map <string, int> pts;
	for (int i = 0; i < n; i++)
	{
		pts[s[i]] += x[i];
		if (v.find(s[i]) != v.end())
		{
			if (pts[s[i]] >= ans)
			{
				cout << s[i];
				return 0;
			}
		}
	}
}
