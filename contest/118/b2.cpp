
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 1; j <= (n - i * 2 + 1) / 2; j++)
            cout << "*";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "D";
        for (int j = 1; j <= (n - i * 2 + 1) / 2; j++)
            cout << "*";
        puts("");
    }
    for (int i = 1; i <= n; i++)
    	cout << "D";
    puts("");
    for (int i = n / 2; i > 0; i--)
    {
        for (int j = 1; j <= (n - i * 2 + 1) / 2; j++)
            cout << "*";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "D";
        for (int j = 1; j <= (n - i * 2 + 1) / 2; j++)
            cout << "*";
        puts("");
    }
}