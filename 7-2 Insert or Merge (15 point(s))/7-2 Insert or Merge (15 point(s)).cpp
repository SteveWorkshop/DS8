// 7-2 Insert or Merge (15 point(s)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;

int once[N], twice[N], sorted[N];

bool isMergedSomeTimes(int* twice, int n, int len)
{
    for (int i = 0; i < n; i += len)
    {
        int begin = i, end = i + len - 1;
        if (end > n - 1) { end = n - 1; }
        for (int k = begin; k < end; k++)
        {
            if (twice[k] > twice[k + 1]) { return false; }
        }
    }
    return true;
}

int howLongMerged(int* a, int n)
{
    for (int len = 2; len <= n; len *= 2)
    {
        if (!isMergedSomeTimes(a, n, len)) { return len / 2; }
    }
    return n;
}

void nthMergePass(int* a, int n, int sublen)
{
    if (sublen >= n) { return; }
    for (int begin = 0; begin < n; begin += 2 * sublen)
    {
        
        int mid = begin + sublen - 1;
        int end = begin + 2 * sublen - 1;
        if (end > n - 1) { end = n - 1; }
        if (begin >= end) { continue; }
        int* tmp = new int[2 * sublen];
        int i = begin, j = mid + 1, k = 0;
        while (i <= mid && j <= end)
        {
            if (a[i] < a[j]) { tmp[k++] = a[i++]; }
            else { tmp[k++] = a[j++]; }
        }
        while (i <= mid) { tmp[k++] = a[i++]; }
        while (j <= end) { tmp[k++] = a[j++]; }
        for (int i = begin, k = 0; i <= end; i++, k++)
        {
            a[i] = tmp[k];
        }
        delete[] tmp;
    }
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
    
    int len = howLongMerged(twice, n);
    if (len != 1)
    {
        std::cout << "Merge Sort\n";
        nthMergePass(twice, n, len);
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
