class Solution {
public:
    
    struct Node {
        char value;
        vector<Node*> children;
        Node(char c) : value(c) {}
    };
    
    vector<Node*> initializeNodeString(string S) {

        vector<Node*> nodes;
        for(auto it = S.rbegin(); it != S.rend(); it++) {
            Node* tempNode = new Node(*it);
            for(Node* n : nodes) n->children.insert(n->children.begin(), tempNode);
            nodes.insert(nodes.begin(),tempNode);
        }

        return nodes;
    }
	 
	Node* doesContainCharacter(Node* Node, char c) {
        for( auto it = Node->children.rbegin(); it != Node->children.rend(); it++)
            if( it->value == c)
                return it;
        return nullptr;
		
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        
        int count = 0;
        
		  vector<Node*> nodes = initializeNodeString(S);
		  
        for(string word : words) {
            
            int nodeIndex = 0
				// Find first index
            Node* currentNode = nodes[nodeIndex];
				while(currentNode->value != word[0])
					currentNode = nodes[++nodeIndex];
					
				int wordIndex = 1;
            while(wordIndex < word.length()) {
					Node* nextNode = doesContainCharacter(currentNode, word[wordIndex]);
					if(nextNode == nullptr) break;
					currentNode = nextNode;
					wordIndex++;
					if(wordIndex >= word.length()) break;
            }
				
            if(wordIndex >= word.length()) count ++;
            
            return count;
        }
    }
};