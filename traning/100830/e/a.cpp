
#include <bits/stdc++.h>

using namespace std;

string buff = "";
string s[14], a;
int cur, n, k, m;

void cpy()
{
    if (s[cur].length() < k)
        buff = s[cur];
    else
        buff = s[cur].substr(s[cur].length() - k, k);
}

int main()
{
    freopen("notepad.in", "r", stdin);
    freopen("notepad.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        //puts(s[cur].empty() ? "-1" : s[cur].c_str());
        cin >> a;
        if (a == "Next")
        {
            cur = (cur + 1) % n;
            continue;
        }
        if (a == "Copy")
        {
            cpy();
            continue;
        }
        if (a == "Backspace")
        {
            s[cur].pop_back();
            continue;
	}
	if (a == "Paste")
	{
            for (char x : buff)
                s[cur].push_back(x);
            continue;
	}
	for (char x : a)
            s[cur].push_back(x);
    }
    if (s[cur].length() >= k)
        s[cur] = s[cur].substr(s[cur].length() - k, k);
    puts(s[cur].empty() ? "Empty" : s[cur].c_str());
}
