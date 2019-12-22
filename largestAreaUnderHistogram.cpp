#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestAreaRectangle(vector<int> hist) {
	stack<int> s;
	hist.push_back(0);
	int area = 0;

	for (int i = 0; i < hist.size(); i++) {
		if (s.empty() || hist[i] >= hist[s.top()]) {
			s.push(i);
		}
		else {
			int curTop;
			while (!s.empty() && hist[i] < hist[s.top()]) {
				curTop = s.top();
				s.pop();
				if (s.empty()) {
					area = max(area, (i)*hist[curTop]);
				}
				else {
					area = max(area, (i - s.top() - 1)*hist[curTop]);
				}
			}
			s.push(i);
		}
	}
	return area;
}


int main(){
    // Driver Code
    largestAreaRectangle({2,3,6,5,7,2});
    
    return 0;
}
