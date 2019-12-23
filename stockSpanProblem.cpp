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

vector<int> stockSpanProblem(vector<int> prices) {
	stack<int> s;
	s.push(0);
	vector<int> stockSpans;
	for (int i = 1; i < prices.size(); i++) {
		while (!s.empty() && prices[s.top()] <= prices[i]) {
			s.pop();
		}
    
		if (!s.empty()) {
			stockSpans.push_back(i - s.top());
		}else {
			stockSpans.push_back(i + 1);
		}
		s.push(i);
	}
	return stockSpans;
}

void printVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	                                      
	vector<int> inputVec = { 100, 80, 60, 70, 60, 75, 85 };
	vector<int> stockSpanVec = stockSpanProblem(inputVec);
	printVector(stockSpanVec);

	return 0;
}
