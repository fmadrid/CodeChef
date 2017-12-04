#include <iostream>

#define DEBUG false

using namespace std;

const int R_TO_G = 5;
const int G_TO_R = 3;

int runSolution(int n, int m) {

	int totA = 0;
	int totB = 0;

	char c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			cin >> c;
			
			if(DEBUG) printf("(%d, %d) : %c\n", i, j, c);
			
			if((i + j) % 2 == 0) {
				if(c == 'R') totB += R_TO_G;
				if(c == 'G') totA += G_TO_R;
			}
			else {
				if(c == 'R') totA += R_TO_G;
				if(c == 'G') totB += G_TO_R;
			}
		
		}
	}
	
	return (totA < totB) ? totA : totB;
}

int main() {

	int T;
	cin >> T;
	
	while(T--) {
	
		int N, M;
		cin >> N >> M;
		
		cout << runSolution(N,M);
		
		if(T != 0) cout << endl;
	
	}

}