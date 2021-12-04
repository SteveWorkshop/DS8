// 7-3 Insertion or Heap Sort (15 point(s)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <functional>

const int N = 1e5 + 10;

int once[N], twice[N];

/*
* 本方法参考自：https://www.cnblogs.com/woxiaosade/p/10628388.html
* 和：https://blog.csdn.net/LaoJiu_/article/details/51822898
*/

int* firstNotaHeap(int* a, int n)
{
    return std::is_heap_until(a, a + n, std::less<int>());
}

void nthHeapSort(int* a, int* position)
{
    std::pop_heap(a, position, std::less<int>());
}

int findFirstNotInOrder(int* origin, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (origin[i - 1] > origin[i]) { return i; }
    }
    return -1;
}

void nthInsertionPass(int* a, int n, int firstindex)
{
    int tmp = a[firstindex];
    int j;
    for (j = firstindex - 1; j >= 0 && a[j] > tmp; j--)
    {
        a[j + 1] = a[j];
    }
    a[j + 1] = tmp;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> once[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> twice[i];
    }
    int* pos = firstNotaHeap(twice, n);
    if (pos == twice + 1)//一个也是堆，所以说这里用twice+1判断
    {
        std::cout << "Insertion Sort\n";
        int i = findFirstNotInOrder(twice, n);
        nthInsertionPass(twice, n, i);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (flag) { std::cout << " "; }
            else { flag = true; }
            std::cout << twice[i];
        }
    }
    else
    {
        std::cout << "Heap Sort\n";
        nthHeapSort(twice, pos);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (flag) { std::cout << " "; }
            else { flag = true; }
            std::cout << twice[i];
        }
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
