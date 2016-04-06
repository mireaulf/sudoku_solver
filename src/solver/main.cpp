
#include <array>
using std::array;
#include <vector>
using std::vector;

#include "..\..\inc\grid.h"

int main(int argc, char** argv) {
	
	//std::array<std::array<int, 9>, 9> 
	std::vector<std::vector<int>>
		grid 
	{ 
		{0, 6, 0, 
			0, 0, 8, 
				2, 0, 0},
		{1, 0, 4, 
			3, 0, 5, 
				0, 0, 0},
		{0, 5, 0, 
			6, 0, 0, 
				0, 0, 1},
		{8, 0, 0, 
			0, 0, 6, 
				7, 0, 0},
		{4, 0, 7, 
			0, 0, 0, 
				9, 0, 1},
		{0, 0, 6, 
			3, 0, 0, 
				0, 0, 4},
		{5, 0, 0, 
			0, 0, 7, 
				0, 4, 0},
		{0, 0, 0, 
			2, 0, 6, 
				5, 0, 8},
		{0, 0, 2, 
			9, 0, 0, 
				0, 7, 0}
	};

	solver::grid solver(grid);
	solver.print();
	std::cout << std::endl;
	solver.build_domain();
	solver.print_domain();
	/*
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			std::cout << "[" << i << "][" << j << "]" << std::endl;
			for(auto i : solver.get_unit(i, j)) {
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}*/
	return 0;
}
