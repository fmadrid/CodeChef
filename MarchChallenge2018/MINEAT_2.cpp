#include <iostream>
#include <set>
#include <climits>
#include <cmath>
#include <utility>
#include <memory>
#include <algorithm>
#define DEBUG false

 
int main() {
 
	int T, N, H;
	
	std::cin >> T;
	
	for(int i = 1; i <= T; i++) {
		
		std::cin >> N >> H;
		double* A = new double[N];
		int maxElement = 0;
		for(int i = 0; i < N; i++) {
			std::cin >> A[i];
			maxElement = std::max(maxElement, (int) A[i]);
		}
		int lowerBound = 1;
		int upperBound = maxElement;
		int current = (upperBound - lowerBound) / 2 + lowerBound;
		while(true) {
			int requiredHours = 0;
			for(int i = 0; i < N; i++)
				requiredHours += std::ceil(A[i] / current);
			if(requiredHours > H) lowerBound = current + 1;
			else upperBound = current;
			current = (upperBound - lowerBound) / 2 + lowerBound;
			if(lowerBound == upperBound) break;
			
			
		}
		
		delete[] A;
		
		std::cout << current << "\n";
		
	}
	
	return 0;
	
}