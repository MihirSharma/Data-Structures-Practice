#include<iostream>
#include<string>

using namespace std;

void urlify(char* a, int size, int charSize) {
	size--;
	for (int i = charSize - 1; i >= 0; i--) {
		if (a[size] == ' ') {
			a[i] = '0';
			a[i - 1] = '2';
			a[i - 2] = '%';
			i -= 2;
			size --;
		}
		else {
			a[i] = a[size];
			size--;
		}
	}

}

int countSpaces(string s, int size) {
	int ctr = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') ctr++;
	}
	return ctr;
}

void convertString(string s, char* a, int size, int charSize) {
	for (int i = 0; i < size; i++) {
		a[i] = s[i];
	}
	for (int i = size; i < charSize; i++) {
		a[i] = NULL;
	}
}

int main() {
	string s;
	char* a = NULL;
	getline(cin, s);
	int size = s.size();
	int charSize = size + (countSpaces(s, size)) * 2;
	a = new char[size, charSize];
	convertString(s, a, size, charSize);
	urlify(a, size, charSize);
	for (int i = 0; i < charSize; i++) {
		cout << a[i];
	}
}