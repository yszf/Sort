#include "sort.h"

void reset_array(int arr[], int brr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = brr[i];
	}
}

void show(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	int arr[] = { 34, 12, 45, 67, 1, 56, 101, 23, 89, 90};
	int brr[] = { 34, 12, 45, 67, 1, 56, 101, 23, 89, 90 };
	int len = sizeof(arr) / sizeof(arr[0]); 
	show(arr, len);

	cout << "½»»»ÅÅÐò:" << endl;
	swap_sort(arr, len);
	show(arr, len);

	cout << "Ã°ÅÝÅÅÐò:" << endl;
	reset_array(arr, brr, len);
	bubble_sort(arr, len);
	show(arr, len);

	cout << "Ñ¡ÔñÅÅÐò:" << endl;
	reset_array(arr, brr, len);
	select_sort(arr, len);
	show(arr, len);

	cout << "²åÈëÅÅÐò:" << endl;
	reset_array(arr, brr, len);
	insert_sort(arr, len);
	show(arr, len);

	cout << "Ï£¶ûÅÅÐò:" << endl;
	reset_array(arr, brr, len);
	shell_sort(arr, len);
	show(arr, len);

	cout << "¶ÑÅÅÐò:" << endl;
	reset_array(arr, brr, len);
	heap_sort(arr, len);
	show(arr, len);

	cout << "¹é²¢µÝ¹é:" << endl;
	reset_array(arr, brr, len);
	merge_sort(arr, len);
	show(arr, len);

	cout << "¹é²¢·ÇµÝ¹é:" << endl;
	reset_array(arr, brr, len);
	merge_sort2(arr, len);
	show(arr, len);

	cout << "¿ìÅÅµÝ¹é:" << endl;
	reset_array(arr, brr, len);
	quick_sort(arr, len);
	show(arr, len);

	cout << "¿ìÅÅ·ÇµÝ¹é:" << endl;
	reset_array(arr, brr, len);
	quick_sort2(arr, len);
	show(arr, len);
	
	return 0;
}