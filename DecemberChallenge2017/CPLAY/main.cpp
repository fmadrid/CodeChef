#include <iostream>
#include  <string>

#define DEBUG false

using namespace std;

string runSolution(string str) {
	
	int sz = str.length();
	
	int scoreA = 0;
	int scoreB = 0;
	
	int maxA = 5;
	int maxB = 5;
	
	for(int i = 0; i < 10; i++) {
		
		if(str[i] == '1') {
			if(i % 2 == 0) scoreA++;
			else scoreB ++;
		}
		
		(i % 2 == 0) ? maxA-- : maxB--;
		
		if(scoreA + maxA < scoreB) return "TEAM-B " + to_string(i+1);
		
		if(scoreB + maxB < scoreA) return "TEAM-A " + to_string(i+1);
		
		if (DEBUG) printf("%d: %d (%d) - %d (%d)\n", i, scoreA, scoreA + maxA, scoreB, scoreB + maxB);
	}
	
	scoreA = 0; scoreB = 0;
	for(int i = 10; i < 19; i+=2) {
		if (DEBUG) printf("%d: %d-%d\n", i, str);
		if(str[i] == str[i+1]) continue;
		if(str[i] == '1') return "TEAM-A " + to_string(i + 2);
		if(str[i+ 1] == '1') return "TEAM-B " + to_string(i + 2);
	}
	
	return "TIE";
}

int main() {

	std::string line;
	getline(cin, line);
	cout << runSolution(line);
	while (std::getline(std::cin, line))
		cout << endl << runSolution(line);
	return 0;

}