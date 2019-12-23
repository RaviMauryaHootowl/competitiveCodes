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

int main() {
	                                      
	vector<int> petrolPumps = { 1,2,3,4,5 };
	vector<int> dist = { 3,4,5,1,2 };
  
	int tank = 0, def = 0, startIndex = 0;
  
	for (int i = 0; i < petrolPumps.size(); i++) {
		tank += petrolPumps[i] - dist[i];   // Keep storing Tank count
		
		// If tank becomes neg, then startIndex is not which is selected
		// And startIndex is also not any after that till (i)
		// StartIndex from i+1, but transfer negTank to defeceit
		if (tank < 0) {
			def = tank;
			tank = 0;
			startIndex = i + 1;
		}
	}

	if (tank - def < 0) { startIndex = -1; }
	cout << "Start Index should be " << startIndex << endl;
  return 0;
  
}
