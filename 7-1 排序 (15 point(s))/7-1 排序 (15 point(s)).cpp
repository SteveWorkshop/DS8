// 7-1 排序 (15 point(s)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;

int a[N];

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    //没别的意思，就是想试试这两个函数
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::make_heap(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        std::pop_heap(a, a + n - i, cmp);
    }
    int flag = false;
    for (int i = 0; i < n; i++)
    {
        if (flag) { std::cout << " "; }
        else { flag = true; }
        std::cout << a[i];
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
