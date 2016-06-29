// IntersectingArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector
#include <iterator>
#include <unordered_set>
using namespace std;

int main() {
	vector<int> nums1 = { 1,2,2 };
	vector<int> nums2 = { 2,2 };

		std::vector<int> v;                      // 0  0  0  0  0  0  0  0  0  0
		vector<int>::iterator it;
		std::sort(nums1.begin(), nums1.end());     //  5 10 15 20 25
		std::sort(nums2.begin(), nums2.end());   // 10 20 30 40 50

		std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v));
		it= unique(v.begin(), v.end());
		// 10 20 0  0  0  0  0  0  0  0
		v.erase(it, v.end());                    // 10 20

	std::cout << "The intersection has " << (v.size()) << " elements:\n";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}	
