
#include <bits/stdc++.h>

using namespace std;


map <string, string> m;
string a, b;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        cin >> a >> b;
        auto it = m.find(a);
        if (it == m.end())
            m.insert(make_pair(b, a));
        else
        {
            string was = it -> second;
            m.erase(it);
            m.insert(make_pair(b, was));
        }
    }
    printf("%d\n", (int)(m.size()));
    for (auto i : m)
        cout << i.second << " " << i.first << '\n';
}
