#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//a������  n�Ƿ�Χ
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void HeapSort(int* a, int n);
void AdjustDown(int* a, int n, int root);
void SelectSort(int* a, int n);
void SortTest();
void MergeSort(int* a, int n);
void CountSort(int* a, int n);