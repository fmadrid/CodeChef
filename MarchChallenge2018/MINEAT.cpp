#include <iostream>
#include <set>
#include <climits>
#include <cmath>
#include <utility>
#include <memory>
 
#define DEBUG false
struct cmp
{
    bool operator()(std::pair<int,double> a, std::pair<int,double> b)
    {
		 if(std::ceil(a.second/a.first) == std::ceil(b.second/b.first)) return a.first > b.first;
		 else return std::ceil(a.second/a.first) < std::ceil(b.second/b.first);
    }
};
 
 
 
int main() {
 
	int T, N, H, x;
	
	std::cin >> T;
	
	for(int i = 1; i <= T; i++) {
		
		std::cin >> N >> H;
		
		int hoursPerPile = H / N;
		int remainingHours = H - hoursPerPile * N;
		
		std::multiset<std::pair<int,double>, cmp> pileValues;
		
		for(int i = 1; i<=N;i++) {			
			std::cin >> x;
			pileValues.insert(std::make_pair(1, (double) x));
		}
		
		H -= N;
		while(H>0) {
			if(DEBUG) {
			   for(auto it = pileValues.begin(); it != pileValues.end(); it++)
				   std::cout << "(" << it->first << ", " << it->second << "), ";
			   std::cout << "\n";
			}
			auto it = std::prev(pileValues.end());
			auto it2 = std::prev(it);
			 int ratio = std::max(1,(int)std::floor((it->second/it->first)/(it2->second/it2->first)));
			 int delta = std::min(ratio,H);
			 H-=delta;
			int spentHours = it->first + delta;
			double pileValue = it->second ;
			pileValues.erase(std::prev(pileValues.end()));
			pileValues.insert(std::make_pair(spentHours,pileValue));
		}
		if(DEBUG) {
		   for(auto it = pileValues.begin(); it != pileValues.end(); it++)
				   std::cout << "(" << it->first << ", " << it->second << "), ";
			  std::cout << "\n";
		}
		auto it = std::prev(pileValues.end());
		int ret = (int) std::ceil(it->second / it->first);
		std::cout << ret << "\n";
		
	}
	
	return 0;
	
}