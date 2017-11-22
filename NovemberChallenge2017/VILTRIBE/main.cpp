/*	Author:	Frank Madrid
	Title:	Villages and Tribes
	Description:	Solution to https://www.codechef.com/NOV17/problems/VILTRIBE
*/
#include <iostream>
 
using namespace std;
 
void solution();
 
int main() {
 
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		
		solution();
		if(i != n-1) cout << endl;
	}
		
	return 0;
	
}
 
void solution() {
	
	string line;
	
	cin >> line;
	
	int aTribe = 0, bTribe = 0;
	
	int state = 0;
	int count = 0;
	
	for(char c : line) {
	
		if(c == 'A') {
			
			if(state == 1)  aTribe += count;
			if(state == 2) bTribe++;
			
			count = 0;
			state = 1;
			
		}
		
		if(c == 'B') {
			
			if(state == 1) aTribe++;
			if(state == 2) bTribe += count;
			
			count = 0;
			state = 2;
			
		}
	
		count++;
	
	}
	
	if(state == 1) aTribe++;
	if(state == 2) bTribe++;
 
	
	cout << aTribe << " " << bTribe;
	
}