#include <iostream>
#include <cmath>

void printArray(int* A, int SIZE) {
	for(int i = 0 ; i < SIZE; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";
}

struct Node {
	
	int index = 0;
	int digits[32] = {};
	Node* leftChild   = nullptr;
	Node* rightChild  = nullptr;
	Node* parent      = nullptr;
	
	Node() {}
	Node(int idx, int x) : index(idx) {
		std::cout << "Creating Node: " << x << "\n";
		int i = 31;
		while(x != 0) {
			digits[i--] = x % 2;
			x /= 2;
		}
	}
	
	void add(Node* n) {
		if(!n) return;
		for(int i = 0; i < 32; i++) {
			digits[i] += n->digits[i];
		}
	}
	
	void subtract(Node* n) {
		if(!n) return;
		for(int i = 0; i < 32; i++) {
			digits[i] -= n->digits[i];
		}
	}
	
};

Node* arrayToBinaryTree(const int* A, int& index, int SIZE, int level) {
	
	if(index >= SIZE) return nullptr;
	else if(level == 0) return new Node(index, A[index++]);
	
	Node* branch = new Node();
	branch->leftChild  = arrayToBinaryTree(A, index, SIZE, level-1);
	branch->rightChild = arrayToBinaryTree(A, index, SIZE, level-1);
	
	branch->add(branch->leftChild);
	branch->add(branch->rightChild);
	
	return branch;
}
		
Node* constructBitSetTree(const int* A, int SIZE) {
	int index = 0;
	return arrayToBinaryTree(A, index, SIZE, (int) std::ceil(std::log2(SIZE)));
}

int main() {

	int N, Q;
	
	std::cin >> N;
	std::cin >> Q;
	
	int* A =  new int[N];
	for(int i = 0; i < N; i++)
		std::cin >> A[i];
	Node* binaryTree = constructBitSetTree(A, N);
	delete[] A;
	
	printArray(binaryTree->digits, 32);
	
	
	return 0;
}
		
		