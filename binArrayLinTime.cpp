#include<iostream>

using namespace std;

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	int begin = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 0) {
			arr[begin] = 0;
			begin++;
		}
	}
	for (int i = begin; i < 10; i++) {
		arr[i] = 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
	}
}