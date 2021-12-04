// 6-2 Iterative Mergesort (15 point(s)).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass(ElementType list[], ElementType sorted[], int N, int length);

void output(ElementType list[], int N)
{
    int i;
    for (i = 0; i < N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort(ElementType list[], int N)
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while (length < N) {
        merge_pass(list, extra, N, length); /* merge list into extra */
        output(extra, N);//好家伙，薛定谔的数组。。。
        length *= 2;
        merge_pass(extra, list, N, length); /* merge extra back to list */
        output(list, N);
        length *= 2;
    }
}

int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */
void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
    for (int begin = 0; begin < N; begin += 2 * length)
    {
        int mid = begin + length - 1;
        int end = begin + 2 * length - 1;
        if (end > N - 1) { end = N - 1; }
        if (begin > end) 
        { 
            continue; 
        }
        if (begin == end)
        {
            sorted[begin] = list[begin];
            continue;
        }
        //begin~mid, mid+1~end, 合并
        int i = begin, j = mid + 1;
        int k = begin;
        while (i <= mid && j <= end)
        {
            if (list[i] < list[j]) { sorted[k++] = list[i++]; }
            else { sorted[k++] = list[j++]; }
        }
        while (i <= mid)
        {
            sorted[k++] = list[i++];
        }
        while (j <= end)
        {
            sorted[k++] = list[j++];
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
