#include<unordered_map>
#include<iostream>
#include<string>

using namespace std;

bool permutation(string s1, string s2) {
	if (s1.size() != s2.size()) return false;
	unordered_map<char, int> map1, map2;
	for (int i = 0; i < s1.size(); i++) {
		if (map1.find(s1[i]) == map1.end())
			map1[s1[i]] = 1;
		else map1[s1[i]]++;

		if (map2.find(s2[i]) == map2.end())
			map2[s2[i]] = 1;
		else {
			map2[s2[i]]++;
		}
	}

	for (auto i : map1) {
		if (i.second != map2[i.first]) return false;
		cout << i.first << "	" << i.second<<endl;
	}
	return true;
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	cout << permutation(s1, s2);
}