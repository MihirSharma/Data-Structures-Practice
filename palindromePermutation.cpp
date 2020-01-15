#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool palidrome(string s) {
	int oddCtr = 0;
	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= (int)'a' && s[i] <= (int)'z') {
			if (map.find(s[i]) == map.end()) map[s[i]] = 1;
			else map[s[i]]++;
		}
	}
	for (auto i : map) {
		if (i.second % 2 != 0 && oddCtr < 2) oddCtr++;
		if (oddCtr > 1) return false;
	}
	return true;
}

int main() {
	string s;
	cin >> s;
	cout << palidrome(s);
}