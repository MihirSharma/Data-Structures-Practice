#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void checkStringChars(string s1, string s2, int &moveCtr) {
	int size, j= 0;
	bool s1larger;
	if (s1.size() > s2.size()) {
		size = s2.size();
		s1larger = true;
	}
	else {
		size = s2.size();
		s1larger = false;
	}
	for (int i = 0; i < size; i++) {
		if (s1larger) {
			if (s1[j] == s2[i]) j++;
			else if (s1[j + 1] == s2[i] && j < size) {
				moveCtr++;
				j += 2;
			}
			else { 
				moveCtr++; 
				j++;
			}
		}
		else {
			if (s1[i] == s2[j]) j++;
			else if (s1[i] == s2[j+1]) {
				moveCtr++;
				j += 2;
			}
			else {
				moveCtr++;
				j++;
			}
		}
	}
}


int main(){
	int moveCtr = 0;
	bool check = true;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int s1Size = s1.size(), s2Size = s2.size();
	if (abs(s1Size - s2Size) <= 1) {
		checkStringChars(s1, s2, moveCtr);
		if (moveCtr > 1) {
			check =  false;
		}
	}
	else {
		check =  false;
	}
	if (check) cout << "true";
	else cout << "false";
}
