#include <iostream>
#include <string>

using namespace std;

class stack {
public:
	int top;
	char y[200];
	stack(string &x); 
	void push(char a);
	char pop();
};

stack::stack(string &x) {
	top = 0;
}

void stack::push(char a){
	y[top] = a;
	top++;
	
}

char stack::pop() {
	char ret = y[top-1];
	top--;
	return ret;
}

int main()
{
	char z;
	bool check= true;
	string x = "()()(";
	unsigned int size = x.size();
	stack s(x);
	
	for (int i = 0; i < x.size(); i++) {
		if (s.top < 200) {
			if (x[i] == '{' || x[i] == '[' || x[i] == '(') {
				s.push(x[i]);
			}
			else if (x[i] == '}' || x[i] == ']' || x[i] == ')') {
				z = s.pop();
				if ((x[i] == '}' && z == '{') || (x[i] == ']' && z == '[') || (x[i] == ')' && z == '(')) {
					continue;
				}
				else {
					check = false;
					break;
				}
			}
			else {
				cout << "Unknown symbol detected" << endl;
				break;
			}
		}
		else {
			cout << "Program unable to compute" << endl;
			break;
		}
	}
	if (s.top == 0 && check) {
		cout << "balanced" << endl;
	}
	else {
		cout << "unbalanced" << endl;
	}
	return 0;
}

