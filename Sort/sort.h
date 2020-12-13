#ifndef __SORT_H_2020_12_13__
#define __SORT_H_2020_12_13__

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <stack>

#ifdef _WIN32
#include "vld.h"
#endif

using namespace std;

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swap_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (arr[i] > arr[j]) {
				swap(arr, i, j);
			}
		}
	}
}

void bubble_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		bool flag = false;
		for (int j = len - 1; j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr, j, j - 1);
				flag = true;
			}
		}

		if (!flag) {
			break;
		}
	}
}

void select_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}

		if (min != i) {
			swap(arr, min, i);
		}
	}
}

void insert_sort(int arr[], int len) {
	for (int i = 1; i < len; ++i) {
		int temp = arr[i];
		if (temp < arr[i - 1]) {
			int j = i - 1;
			for (; 0 <= j && arr[j] > temp; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

void shell_sort(int arr[], int len) {
	int incre = len;
	do {
		incre = incre / 3 + 1;
		for (int i = incre; i < len; ++i) {
			int temp = arr[i];
			if (temp < arr[i - incre]) {
				int j = i - incre;
				for (; 0 <= j && arr[j] > temp; j -= incre) {
					arr[j + incre] = arr[j];
				}
				arr[j + incre] = temp;
			}
		}
	} while (1 < incre);
}

void heap_adjust(int arr[], int k, int len) {
	int temp = arr[k];
	int i = 2 * k + 1;
	while (i < len) {
		if (i + 1 < len && arr[i + 1] > arr[i]) {
			++i;
		}
		if (temp > arr[i]) break;
		arr[k] = arr[i];
		k = i;
		i = 2 * k + 1;
	}
	arr[k] = temp;
}

void heap_sort(int arr[], int len) {
	for (int i = len / 2 - 1; 0 <= i; --i) {
		heap_adjust(arr, i, len);
	}

	for (int i = len - 1; 0 <= i; --i) {
		swap(arr, 0, i);
		heap_adjust(arr, 0, i);
	}
}

void merge(int arr[], int start, int mid, int end) {
	int len = end - start + 1;
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(nullptr != brr);
	memset(brr, 0, sizeof(int) * len);
	int low1 = start;
	int high1 = mid;
	int low2 = mid + 1;
	int high2 = end;
	int i = 0;
	while (low1 <= high1 && low2 <= high2) {
		if (arr[low1] < arr[low2]) {
			brr[i++] = arr[low1++];
		}
		else {
			brr[i++] = arr[low2++];
		}
	}

	while (low1 <= high1) {
		brr[i++] = arr[low1++];
	}

	while (low2 <= high2) {
		brr[i++] = arr[low2++];
	}

	for (int j = 0; j < i; ++j) {
		arr[start + j] = brr[j];
	}

	free(brr);
}

void msort(int arr[], int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		msort(arr, start, mid);
		msort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void merge_sort(int arr[], int len) {
	msort(arr, 0, len - 1);
}


void merge_pass(int arr[], int n, int s) {
	int i = 0;
	while (i < n - 2 * s + 1) {
		merge(arr, i, i + s - 1, i + s);
		i += 2 * s;
	}

	if (i < n - s) {
		merge(arr, i, i + s - 1, n - 1);
	}
}

void merge_sort2(int arr[], int len) {
	int k = 1;
	while (k < len) {
		merge_pass(arr, len, k);
		k *= 2;
	}
}

int pivot(int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	if (arr[low] > arr[high]) {
		swap(arr, low, high);
	}

	if (arr[mid] > arr[high]) {
		swap(arr, mid, high);
	}

	if (arr[low] < arr[mid]) {
		swap(arr, low, mid);
	}

	return low;
}

int partition(int arr[], int low, int high) {
	int p = pivot(arr, low, high);
	int temp = arr[p];
	while (low < high) {
		while (low < high && temp <= arr[high]) {
			--high;
		}
		arr[low] = arr[high];
		
		while (low < high && temp >= arr[low]) {
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = temp;
	
	return low;
}

// Œ»∂®≈≈–Ú
int partition2(int arr[], int low, int high) {
	int len = high - low + 1;
	int temp = arr[low];
	int pos = low + 1;
	int* brr = (int*)malloc(sizeof(int) * len);
	assert(nullptr != brr);
	memset(brr, 0, sizeof(int) * len);
	int mid = low;
	int x = 0;
	while (pos <= high) {
		if (arr[pos] <= temp) {
			brr[x++] = arr[pos];
		}
		pos++;
	}
	brr[x] = temp;
	mid = low + x;

	pos = high;
	int y = len - 1;
	while (pos >= low) {
		if (arr[pos] >= temp) {
			brr[y--] = arr[pos];
		}
		pos--;
	}

	for (int i = 0; i < len; ++i) {
		arr[low + i] = brr[i];
	}

	free(brr);

	return mid;
}

void qsort(int arr[], int start, int end) {
	int mid;
	while (start < end) {
		mid = partition2(arr, start, end);
		qsort(arr, start, mid - 1);
		start = mid + 1;
	}
}

void quick_sort(int arr[], int len) {
	qsort(arr, 0, len - 1);
}

void qsort2(int arr[], int low, int high) {
	if (low < high) {
		stack<int> sta;
		sta.push(high);
		sta.push(low);

		while (!sta.empty()) {
			int l = sta.top();
			sta.pop();
			int h = sta.top();
			sta.pop();

			int mid = partition2(arr, l, h);
			if (mid + 1 < h) {
				sta.push(h);
				sta.push(mid + 1);
			}

			if (l < mid - 1) {
				sta.push(mid - 1);
				sta.push(l);
			}
		}
	}

}

void quick_sort2(int arr[], int len) {
	qsort2(arr, 0, len - 1);
}

#endif