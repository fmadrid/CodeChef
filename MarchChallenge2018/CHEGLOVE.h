#include <iostream>
#include <string>

int main() {

	int T, N;
	
	int* L;
	int* G;
	std::cin >> T;
	
	for(int i = 1; i <= T; i++) {
		
		std::cin >> N;
		
			bool front = true, back = true;
			
			L = new int[N];
			for(int i = 0; i < N; i++) 
				std::cin >> L[i];
			
			G = new int[N];
			for(int i = 0; i < N; i++) {
				std::cin >> G[i];
				if(L[i] > G[i]) front = false;
				if(L[(N-1)-i] > G[i]) back = false;
			}
			
			std::string result;
			
			if(front && back) result = "both";
			else if(front) result = "front";
			else if(back) result = "back";
			else result = "none";
	
			std::cout << result << "\n";
			
			delete[] L;
			delete[] G;
		
	}
	
	return 0;
	
}