#ifndef SOLVER_GRID_H
#define SOLVER_GRID_H

#include <vector>
#include <algorithm>
#include <iostream>

namespace solver {
	struct domain {
		void remove(std::vector<int> row) {
			for(int value : row) {
				if(value != 0) {
					auto itt = std::find(std::begin(m_values), std::end(m_values), value);
					if(itt != std::end(m_values)) {
						m_values.erase(itt);
					}
				}
			}
		}
		void print() {
			for(int value : m_values) {
				std::cout << value << " ";
			}
		}
	private:
		std::vector<int> m_values {1, 2, 3, 4, 5, 6, 7, 8, 9};
	};


	struct grid	{
		static const int n = 9;

		grid(std::vector<std::vector<int>> grid)
		:m_grid(grid) {
		}
		
		void print() {
			for(auto row : m_grid) {
				for(auto col_value : row) {
					std::cout << col_value << " ";
				}
				std::cout << std::endl;
			}
		}

		void build_domain() {
			for(int row = 0; row < n; ++row) {
				for(int col = 0; col < n; ++col) {
					domain d;
					d.remove(get_row(row));
					d.remove(get_column(col));
					d.remove(get_unit(row, col));
					m_domain.push_back(d);
				}
			}
		}
		/*

		domain cur_domain;
		cur_domain.remove(row);
		cur_domain.remove(get_column());
		m_domain.push_back(cur_domain);
		*/

		void print_domain() {
			for(auto row : m_domain) {
				row.print();
				std::cout << std::endl;
			}
		}

	//private:
		vector<int> get_unit(int r, int c) {
			vector<int> unit;
			auto row_start = r / 3 * 3;
			auto col_start = c / 3 * 3;
			for(int row = 0; row < 3; ++row) {
				for(int col = 0; col < 3; ++col) {
					auto row_index = row_start + row;
					auto col_index = col_start + col;
					auto v = m_grid[row_index][col_index];
					unit.push_back(v);
				}
			}
			return unit;
		}

		vector<int> get_unit(int index) {
			vector<int> unit;
			for(int row = 0; row < 3; ++row) {
				for(int col = 0; col < 3; ++col) {
					auto row_index = index / 3 * 3 + row;
					auto col_index = index % 3 * 3 + col;
					auto v = m_grid[row_index][col_index];
					std::cout << "[" << row_index << "][" <<col_index << "]:" << v;
					unit.push_back(v);
				}
				std::cout << std::endl;
			}
			return unit;
		}

		vector<int> get_column(int index) {
			vector<int> col;
			for(int count = 0; count < n; ++count) {
				col.push_back(m_grid[count][index]);
			}
			return col;
		}

		vector<int> get_row(int index) {
			return m_grid[index];
		}

		std::vector<std::vector<int>> m_grid;
		std::vector<domain> m_domain;
	};
}

#endif
