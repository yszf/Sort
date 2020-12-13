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

	cout << "��������:" << endl;
	swap_sort(arr, len);
	show(arr, len);

	cout << "ð������:" << endl;
	reset_array(arr, brr, len);
	bubble_sort(arr, len);
	show(arr, len);

	cout << "ѡ������:" << endl;
	reset_array(arr, brr, len);
	select_sort(arr, len);
	show(arr, len);

	cout << "��������:" << endl;
	reset_array(arr, brr, len);
	insert_sort(arr, len);
	show(arr, len);

	cout << "ϣ������:" << endl;
	reset_array(arr, brr, len);
	shell_sort(arr, len);
	show(arr, len);

	cout << "������:" << endl;
	reset_array(arr, brr, len);
	heap_sort(arr, len);
	show(arr, len);

	cout << "�鲢�ݹ�:" << endl;
	reset_array(arr, brr, len);
	merge_sort(arr, len);
	show(arr, len);

	cout << "�鲢�ǵݹ�:" << endl;
	reset_array(arr, brr, len);
	merge_sort2(arr, len);
	show(arr, len);

	cout << "���ŵݹ�:" << endl;
	reset_array(arr, brr, len);
	quick_sort(arr, len);
	show(arr, len);

	cout << "���ŷǵݹ�:" << endl;
	reset_array(arr, brr, len);
	quick_sort2(arr, len);
	show(arr, len);
	
	return 0;
}