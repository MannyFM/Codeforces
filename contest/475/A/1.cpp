
#include <bits/stdc++.h>

using namespace std;

#define pp cout << "O."; else cout << "#.";

int main()
{
    int k;
    cin >> k;
    cout << "+------------------------+\n|";
    if (k) pp
    for(int i = 0; i < 10; i++)
    {
        if (i * 3 + 5 <= k) pp
    }
    cout << "|D|)\n|";
    if (k > 1) pp
    for(int i = 0; i < 10; i++)
    {
        if (i * 3 + 6 <= k) pp
    }
    cout << "|.|\n|";
    if (k > 2) pp
    cout << "......................|\n|";
    if (k > 3) pp
    for(int i = 0; i < 10; i++)
    {
        if (i * 3 + 7 <= k) pp
    }
    cout << "|.|)" << "\n+------------------------+";
}
