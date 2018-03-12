#include <iostream>
#include <vector>
#include<bitset>
#include <cmath>
std::vector<int>& bitSetToVector(const std::bitset<31>& bs, std::vector<int>& v) {
	for(int i = 0; i < 31; i++)
		v[i] = (int) bs[i];
	return v;
}

std::vector<int>& add(const std::vector<int> a, std::vector<int>& b) {
	for(int i = 0; i < 31; i++)
		b[i] += a[i];
	return b;
}

std::vector<int> subtract(std::vector<int> source, const std::vector<int>& target) {
	for(int i = 0; i < source.size(); i++)
		source[i] -= target[i];
	return source;
}

int main() {

	int N, Q;
	std::cin >> N >> Q;
	
	std::vector<std::vector<int>> bitArrays;
	
	std::vector<int> cumulativeSum(31, 0);
	for(int i = 1; i <= N; i++) {
		int x;
		std::cin >> x;
		std::vector<int> tempV(31,0);
		bitArrays.push_back(add(bitSetToVector(std::bitset<31>(x), tempV), cumulativeSum));
	}
	
	
	for(int i = 1; i <= Q; i++) {
		int L,R;
		std::cin >> L >> R;
		L--; R--;
		std::vector<int> numOnes = (L == 0) ? bitArrays[R] : subtract(bitArrays[R], bitArrays[L-1]);
		
		std::bitset<31> newNumber;
		for(int i = 0; i < 31; i++){
			int numZeroes = (R-L+1) - numOnes[i];
			newNumber[i] = (numOnes[i] > numZeroes) ? 0 : 1;
		}
		
		
		std::cout << newNumber.to_ulong();
		if( i != Q ) std::cout << "\n";
	}
	
	return 0;
	
}