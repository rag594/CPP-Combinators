#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

#include "combinators.hpp"

using namespace std;


int main() {
	std::vector<int> v{6, 2, 3, 4, 5, 6};
	set<int> s = {1,2,3,4};
	std::vector<float> d(v.size());
	

	std::cout << "**************Ex1******************" << std::endl;

	//1. map over the vector and return a vector<float> with twice the value
	auto f = _map(v,d, [](int x) { return  x*2.0;});

	for(int i = 0;i < d.size();i++) {
		std::cout << std::fixed << d[i]  << std::endl;
	}

	std::cout << "**************Ex2******************" << std::endl;

	
	//2. (Set)return vector of pair with each element zipped with it's index
	auto p = _zipWithIndex(s);
	for(int i = 0;i < p.size();i++) {
                std::cout << p[i].first  << " " << p[i].second << std::endl;
        }

	std::cout << "**************Ex3******************" << std::endl;

	//3. (Vector)return vector of pair with each element zipped with it's index
	auto q = _zipWithIndex(v);
        for(int i = 0;i < q.size();i++) {
                std::cout << q[i].first  << " " << q[i].second << std::endl;
        }

	std::cout << "**************Ex4******************" << std::endl;

	//4. filter the elements based on a predicate
	auto g = _filter(v, [](int x) { return x%2 == 0;});
	 for(int i = 0;i < g.size();i++) {
                std::cout << g[i]  << std::endl;
        }

	std::cout << "**************Ex5******************" << std::endl;

        //4. not filter the elements based on a predicate
        auto h = _filterNot(v, [](int x) { return x%2 == 0;});
         for(int i = 0;i < h.size();i++) {
                std::cout << h[i]  << std::endl;
        }


	return 0;

}
