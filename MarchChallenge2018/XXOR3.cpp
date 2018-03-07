
#include<iostream>

void printArray(int* A, int SIZE) {
	for(int i = 0 ; i < SIZE; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";
}

struct Node {
	int digits[32] = {};
	
	Node() {}
	
	Node(const Node& n) {
		for(int i = 0; i < 32; i++)
			digits[i] = n.digits[i];
	}
	
	Node(int x){
		int i = 31;
		while(x > 0) {
			digits[i--] = x % 2;
			x /= 2;
		}
	}
	
	void add(Node& n) {
		for(int i = 0; i < 32; i++)
			digits[i] += n.digits[i];
	}
	
	void subtract(Node& n) {
		for(int i = 0; i < 32; i++)
			digits[i] -= n.digits[i];
	}
	
	int toInt() {
		int ret = 0;
		int power2 = 1;
		for(int i = 31; i >= 0; i--) {
			ret += power2 * digits[i];
			power2 *= 2;
		}
		
		return ret;
	}
};

struct Heap {
	int sz;
	Node** nodes;
	Heap(int* A, int size) {
		
		sz = std::pow(2, (int) std:ceil(std::log2(size)) + 1) - 1;
		nodes = new Node*[x];
	}
	
	~Heap() { delete[] nodes; }
};

int main() {
	
	Heap heap(10);
	heap.nodes[0] = new Node();
	printArray(heap.nodes[0]->digits, 32);
	
	return 0;
	
}