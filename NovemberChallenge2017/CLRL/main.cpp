#include <iostream>
#include <climits>
#include <string>
 
using namespace std;
 
string solution(int, int);
 
int main() {
 
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int m, k;
		
		cin >> m >> k;
		cout <<  solution(m, k);
		
		if(i != n-1) cout << endl;
		
	}
		
	return 0;
 
}
 
string solution(int m, int target) {
	
	//cout << "m: " << m << " target: " << target << endl;
	int lowerBound = 0;
	int upperBound = 1000000000+1;;
	
	int x = target;
	
	int current;
	
	string ret = "";
	int i;
	for(i = 1; i <= m; i++) {
		
		
		
		//cout << "LB: " << lowerBound << " UB: " << upperBound << endl;
		
		cin >> current;
		if(!ret.empty()) continue;
		//cout << "Current: " << current << endl;
		if(current >= upperBound || current <= lowerBound) ret = "NO";
		
		if(current < target) lowerBound = current;
		else if(current > target) upperBound = current;
		else ret = "YES";
		
		x = current;
		
		
		
	}
	
	return ret;
	
} 