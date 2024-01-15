#include <bits/stdc++.h>
using namespace std;
void Pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "*";
        cout << endl;
    }
}
void Pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}
void Pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << "*";
        cout << endl;
    }
}
void Pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
            cout << " ";
        for (int k = 0; k < 2 * i + 1; k++)
            cout << "*";
        cout << endl;
    }
}
void Pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int k = 2 * (n - i) - 1; k > 0; k--)
            cout << "*";
        cout << endl;
    }
}
void Pattern6(int n)
{
    int t = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (t < n)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }
            t++;
        }
        else
        {
            for (int k = n - 1; k > i - n + 1; k--)
                cout << "*";
        }
        cout << endl;
    }
}
void Pattern7(int n)
{
    bool t = true;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            t = !t;
        for (int j = 0; j <= i; j++)
        {
            t = !t;
            cout << t;
        }
        cout << endl;
    }
}
void Pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= i + 1; k++)
            cout << k;
        for (int j = 0; j < 2 * (n - i - 1); j++)
            cout << " ";
        for (int l = i + 1; l >= 1; l--)
            cout << l;
        cout << endl;
    }
}
void Pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "*";
        for (int j = 1; j < n - 1; j++)
            if (i == 0 || i == n - 1)
                cout << "*";
            else
                cout << " ";
        cout << "*" << endl;
    }
}
void Pattern10(int n){
    for (int i = 0; i < 2*n-1;i++){
        for (int j = 0; j < 2 * n - 1;j++){
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min(min(top, down), min(left, right)));
        }
        cout << endl;
    }
}
int main()
{
    // Pattern1(5);
    // Pattern2(5);
    // Pattern3(5);
    // Pattern4(5);
    // Pattern5(5);
    // Pattern6(5);
    // Pattern7(5);
    // Pattern8(4);
    // Pattern9(4);
    Pattern10(4);
    return 0;
}