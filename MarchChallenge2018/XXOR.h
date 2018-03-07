#include <iostream>

int main() {

	int T, Q;
	
	std::cin >> T;
	
	for(int i =1; i <= T; i++) {
		
		std::cin >> Q;
		
		int** arr = new int*[Q];
		for(int i = 0; i < Q; i++)
			arr[i] = new int[10];
		
	
	for(int i = 0; i<= 31; i++) {
	
		int sum = 0;
		for(int n : arr)
			sum += i ^ n;
		std::cout << "i: " << i << " Sum: " << sum << "\n";
		
	}
	
	return 0;
}