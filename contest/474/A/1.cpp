
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map <char, pair <int, int> > d;
    string a[3] = {"qwertyuiop","asdfghjkl;","zxcvbnm,./"}, in;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 10; j++)
            d[a[i][j]] = make_pair(i, j);
    char fl;
    cin >> fl >> in;
    for(int i = 0; i < (int)(in.length()); i++)
    {
        pair <int, int> pos = d[in[i]];
        int x = pos.first, y = pos.second;
        if (fl == 'R')
            cout << a[x][y - 1];
        else
            cout << a[x][y + 1];
    }
}
