#include<iostream>
#include <string>
#include <set>
#include <queue>
#include<algorithm>
#include<climits>
 
using namespace std;
 
struct CompareByFirst {
    constexpr bool operator()(pair<int, string> const & a,
                              pair<int, string> const & b) const noexcept
    { return a.first > b.first; }
};
 
int LCSubstring(std::string S) {
	
	int** L = new int*[S.size()];
	for(int i = 0; i < S.size(); i++)
		L[i] = new int[S.size()];
	
	int z = 0;
	int length = 0;
	set<std::string> ret;
	for(int i = 0; i < S.size(); i++) {
		for(int j = 0; j < S.size(); j++) {
			
			if(S[i] == S[S.size() - j - 1]) {
				
				L[i][j] = (i == 0 || j == 0) ? 1 : L[i-1][j-1] + 1;
				
				if(L[i][j] > z)       length = z = L[i][j];
				else if(L[i][j] == z) length = (z < length) ? z : length;
				
			} else L[i][j] = 0;
			
		}
	}
	
	for(int i = 0; i < S.size(); ++i)
    delete [] L[i];
	 
	delete [] L;
 
	return length;
 
}
 
pair<int, string> solution(int length, int letterCount) {
 
		pair<int, string> ret;
		
		if(letterCount == 1) {
			string temp(length, 'a');
			ret = make_pair(length, temp);
			
			return ret;
		}
		else if(letterCount == 2 && length >= 9) {
			string temp(length, 'a');
			for(int i = 1; i < length; i = i + 6)
				temp[i] = 'b';
			for(int i = 4; i < length; i = i + 6)
				temp[i] = 'b';
			for(int i = 5; i < length; i = i + 6)
				temp[i] = 'b';
			
			ret = make_pair(4, temp);
			
			return ret;
		}
		else if(letterCount >= 3) {
			
			string temp(length, 'a');
			for(int i = 1; i < length; i = i + 3)
				temp[i] = 'b';
			for(int i = 2; i < length; i = i + 3)
				temp[i] = 'c';
			ret = make_pair(1, temp);
			
			return ret;
			
		}
		
		priority_queue< pair<int, string>,std::vector< pair<int, string> >, CompareByFirst > pQueue;
		
		string main = "";
		
		pQueue.emplace(make_pair(1, "a"));
		ret = make_pair(INT_MAX, "");
		
		while(!pQueue.empty()) {
		
			pair<int, string> top = pQueue.top();
			pQueue.pop();
			
			//cout << "Current: " << top.first << " " << top.second << endl;
			
			if(top.second.size() == length) {
				if(top.first == 1) return top;
				if(top.first < ret.first) ret = top;
				continue;
			}
				
			for(int i = 'a'; i < 'a' + letterCount; i++) {
				//cout << "Letter : " << (char) i << endl;
				string temp = top.second + (char) i;
				int length = LCSubstring(temp);
				//cout << "Adding: " << length << " " << temp << endl;
				pQueue.emplace( make_pair(length, temp));
			}
		}
		
		return ret;
}
 
 
int main() {
	
	int T;
	cin >> T;
	
	for(int i = 1; i <= T; i++) {
		int N, A;
		cin >> N >> A;
		pair<int, string> val = solution(N,A);
		cout << val.first << " " << val.second;
		if(i != T) cout << endl;
	}
	
	return 0;
	
}