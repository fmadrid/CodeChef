#include <iostream>
#include <cmath>
#include <bitset>

void printArray(int* A, int SIZE) {
	for(int i = 0 ; i < SIZE; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";
}

struct Node {
	
	int digits[32];
	
	Node() {
		for(int i = 0; i < 32; i++)
			digits[i] = 0;
	}
	
	Node(Node& n) {
		for(int i = 0; i < 32; i++)
			digits[i] = n.digits[i];
	}
	
	Node(int x){
		for(int i = 0; i < 32; i++)
			digits[i] = 0;
		
		int i = 31;
		while(x > 0) {
			digits[i--] = x % 2;
			x /= 2;
		}
	}
	
	void add(Node& n) {
		for(int i = 0; i < 32; i++) {
			digits[i] += n.digits[i];
		}
	}
	
	void subtract(Node& n) {
		for(int i = 0; i < 32; i++) {
			digits[i] -= n.digits[i];
		}
	}
	
	int toInt() {
		std::cout << "in Int\n";
		int ret = 0;
		int power2 = 1;
		std::cout << digits[0] << "\n";
		for(int i = 31; i >= 0; i--) {
			
			ret += power2 * digits[i];
			power2 *= 2;
		}
		
		return ret;
	}
};

struct Heap {
	Node** nodes;
	int size;
	
	Heap(int x) : size(x){
		nodes = new Node*[x];
	}
};

Heap* createHeap(const int* A, int SIZE) {
	
	int sz = std::pow(2,std::floor(std::log2(SIZE))+2);
	Heap* heap = new Heap(sz);
	
	std::cout << "hSize: " << heap->size << "\n";
	
	for(int i = 0; i < SIZE; i++) {
		//std::cout << "Creating node at " << heap.size/2 + i << "\n";
		Node* newNode = new Node(A[i]);
		heap->nodes[heap->size/2 + i] = newNode;
	}
	
	for(int i = heap->size/2 + SIZE; i < heap->size; i++) {
		//std::cout << "Creating node at " << i << "\n";
		Node* newNode = new Node(0);
		heap->nodes[i] = newNode;
	}
	
	for(int i = heap->size - 1; i >= 2; i-= 2) {
		
		Node* newNode = new Node(0);
		newNode->add(*(heap->nodes[i]));
		newNode->add(*(heap->nodes[i-1]));
		heap->nodes[(i-1)/2] = newNode;
	}
	
	return heap;
	
}

Node* queryHeap(const Heap& heap, int L, int R) {
	L += heap.size/2;
	R += heap.size/2;
	std::cout << "L: " << L << " R: " << R << "\n";
	int tempL = L;
	int tempR = R;
	
	while((tempL-1)/2 != (tempR-1)/2) {
		tempL = (tempL-1)/2;
		tempR = (tempR-1)/2;
	}
	
	int parent = tempL;
	std::cout << "Parent: " << parent << "\n";
	Node nodeL(*(heap.nodes[L]));
	std::cout << "Left: " << nodeL.toInt() << "\n";
	while((L-1)/2 != parent) {
		if(L % 2 == 0) nodeL.subtract(*(heap.nodes[L-1]));
		L = (L-1)/2;
	}
	std::cout << "Left: " << nodeL.toInt() << "\n";
	Node nodeR(*(heap.nodes[R]));
	while((R-1)/2 != parent) {
		if(R % 2 == 1) nodeR.subtract(*(heap.nodes[R+1]));
		R = (R-1)/2;
	}
	std::cout << "Right: " << nodeR.toInt() << "\n";
	Node* ret = new Node();
	ret->add(nodeL);
	ret->add(nodeR);
	
	return ret;
}

int main() {

	int N, Q;
	
	std::cin >> N;
	std::cin >> Q;
	
	int* A =  new int[N];
	for(int i = 0; i < N; i++)
		std::cin >> A[i];
	
	Heap* heap = createHeap(A, N);
	
	
	std::cout << heap->size <<"\n";
	for(int i = 0; i < heap->size; i++)
		std::cout << heap->nodes[i]->toInt() << "\n";
	
	for(int i = 1; i <= Q; i++) {
		int L, R;
		std:: cin >> L >> R;
		queryHeap(*heap, L-1, R-1);
	}
	delete[] A;
	return 0;
}
		
		