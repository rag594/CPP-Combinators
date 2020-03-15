#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include "combinators.hpp"

using namespace std;


int main() {
	std::vector<int> v{6, 2, 3, 4, 5, 6};
	std::vector<float> d(v.size());
	std::vector<pair<int,int> > vp(v.size());
	auto f = mapOver(v,d, [](int x) { return  x*2.0;});

	for(int i = 0;i < d.size();i++) {
		std::cout << std::fixed << d[i]  << std::endl;
	}

	auto p = zipWithIndex(v,vp);
	for(int i = 0;i < vp.size();i++) {
                std::cout << vp[i].first  << " " << vp[i].second << std::endl;
        }

	return 0;

}
