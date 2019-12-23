#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <cmath>
#include <ios>
#include <iomanip>
#include <limits>
using namespace std;

stack<int> sortStack(stack<int> givenS) {
	stack<int> extraS;

	while (!givenS.empty()) {
		int curEle = givenS.top();
		givenS.pop();

		// Checks if the curElement is greater than extraS's top, 
		//then pops extraS to put CurEle in order
		while (!extraS.empty() && curEle > extraS.top()) {
			givenS.push(extraS.top());
			extraS.pop();
		}
		extraS.push(curEle);
	}
	return extraS;
}

void printStack(stack<int> givenS) {
	while (!givenS.empty()) {
		cout << givenS.top() << " ";
		givenS.pop();
	}
	cout << endl;
}

int main() {
	                                      
	deque<int> inputData = { 10, 8, 6, 7, 9, 4 };  // Last ele of Deque will be top of the stack.
	stack<int> givenS(inputData);  // Puts deque into the stack.
	
	cout << "Unsorted Stack is ";
	printStack(givenS);
	stack<int> sortedStack = sortStack(givenS);
	cout << "Sorted Stack is ";
	printStack(sortedStack);

	return 0;
}
