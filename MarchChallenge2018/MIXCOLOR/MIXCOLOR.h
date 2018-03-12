#include <set>
#include <iostream>

int main() {

	int T, N, x;
	
	std::cin >> T;
	
	for(int i = 1; i <= T; i++) {
		
		std::cin >> N;
		
		int duplicates = 0;
		std::set<int> uniqueValues;
		for(int i = 1; i<=N;i++) {			
			
			std::cin >> x;
			if(uniqueValues.find(x) != uniqueValues.end()) duplicates++;
			else uniqueValues.insert(x);
		}
		std::cout << duplicates << "\n";
		
	}
	
	return 0;
	
}
