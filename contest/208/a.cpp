#include <bits/stdc++.h>

using namespace std;

string s, a;
int ok[300], last = 1;

int main()
{
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; i++)
    {
        if (i + 2 < n && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
            ok[i] = ok[i + 1] = ok[i + 2] = 1;
    }
    for(int i = 0; i < n; i++)
        if (!ok[i])
            cout << s[i], last = 0;
        else
            if (last == 0)
                cout << " ", last = 1;

}
