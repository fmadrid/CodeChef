#include <iostream>

using namespace std;

int main() {

    int T;
    std::cin >> T;

    for(int k = 1; k <= T; k++) {

        int N;
        std::cin >> N;

        int* votes = new int[N];
        for(int i = 0; i < N; i++)
            votes[i] = 2;

        votes[0]--;
        votes[N-1]--;
        int* influence = new int[N];

        long long* cumulativeSum = new long long[N];

        for(int i = 0; i < N; i++)
            std::cin >> influence[i];

        cumulativeSum[0] = influence[0];
        for(int i = 1; i < N; i++) {
            cumulativeSum[i] = cumulativeSum[i-1] + influence[i];
        }

        // Right Votes
        for(int i = 0; i < N; i++) {
            for(int j = i+2; j < N; j++) {
                if(influence[i] >= cumulativeSum[j-1] - cumulativeSum[i]) votes[j]++;
					 else break;
            }
        }

        // Left Votes
        for(int i = N-1; i >= 0; i--) {
            for(int j = i-2; j >=0; j--) {
                if(influence[i] >= cumulativeSum[i-1] - cumulativeSum[j]) votes[j]++;
					 else break;
            }
        }
        
        for(int i = 0; i < N; i++)
            std::cout << votes[i] << " ";
        std::cout << "\n";

        delete[] votes;
        delete[] cumulativeSum;

    }

    return 0;

}

