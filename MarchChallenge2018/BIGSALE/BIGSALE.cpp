#include <cstdio>
#include<iostream>
#include <string>
#include <iomanip>

int main() {

	int T, N;
	
	std::cin >> T;
	
	for(int i = 1; i <= T; i++) {
		
		std::cin >> N;
		double valueLost = 0;
		for(int i = 1; i<=N;i++) {
			
			double* data = new double[3];
			for(int i = 0; i < 3; i++)
				std::cin>>data[i];
			
			valueLost += data[1] * data[0] *( data[2]/100) * (data[2]/100);
			delete[] data;
		}
		
		printf("%0.7f\n", valueLost);
			
	}
	
	return 0;
	
}