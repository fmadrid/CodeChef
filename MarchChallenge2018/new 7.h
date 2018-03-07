class EncodedWordDetector { 

private:
	string baseWord;	// Store the word we will compare to
public: 
  EncodedWordDetector(const string& secret) { baseWord = secret; }
  bool isPotentiallyEncodedWord(const string& test) const {
	  
	  if(baseWord.length() != test.length()) return false;
	  
	  char mapping[256];
	  for(char& c : mapping) c = -1;
	  
	  string newWord(baseWord);
	  
	  // Create and perform mapping
	  for(int i = 0; i < newWord.length(); i++) {
		  
		  if(mapping[i] == -1) mapping[i] = test[i];
		  else if(mapping[c] != test[i]) return false;
		  
		  newWord[i] = 
	  }
	  
	  //Check for uniqueness
	  map<int, char> checkUniqueness;
	  for(int i = 0; i < 256; i++) {
		 if(mapping[i] != -1) {
			if(checkUniqueness.find(mapping[i]) != checkUniqueness.end()) return false;
			else checkUniqueness.insert(make_pair(mapping[i], mapping[i]));
		 }
	  }
	  
		  
		  
}; 

"cololo" is a possible encoding of "banana", 