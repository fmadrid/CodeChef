#include <iostream>
#include <climits>
#include <string>
 
using namespace std;
 
string solution(int, int);
 
int main() {
 
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		
		int n, p;
		cin >> n >> p;
		cout <<  solution(n, p);
		
		if(i != t) cout << endl;
		
	}
		
	return 0;
 
}
 
string solution(int n, int p) {
	
	//cout << "n: " << n << " p: " << p << endl;
	if(p < 3) return "impossible";
	
	string sub(p, 'b');
	sub[0] = 'a';
	sub[p - 1] = 'a';
	
	string ret;
	int k = n / p;
	for(int i = 1; i <= k; i++)
		ret.append(sub);
	
	return ret;
} 