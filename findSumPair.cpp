#include<iostream>
#include<unordered_map>
using namespace std;

void getInput(int *x, int &sum) {
	for (int i = 0; i < 10; i++) {
		cin >> x[i];
	}
	cout << "total = ";
	cin >> sum;
}

int main() {

	int x[10], sum;
	getInput(x,sum);
	unordered_map <int, int> lookUp;

	for (int i = 0; i < 10; i++) {
		if (lookUp.find(sum - x[i]) == lookUp.end()) {
			lookUp[x[i]] = i;
		}
		else {
			cout << lookUp[sum - x[i]] << " & " << i << endl;
		}
	}

}