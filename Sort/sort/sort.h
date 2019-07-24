#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//a是数组  n是有效数据个数
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);

void Swap(int*p1, int* p2);
void SelectSort(int* a, int n);
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);
int PartSort(int* a, int begin, int end);
void QuickSort(int* a, int left, int right);

void MergeSort(int* a, int n);
void CountSort(int* a, int n);

void PrintArray(int* a, int n);
