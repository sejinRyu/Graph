// GraphExample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"
#include "Graph.h"
#include <random>
#include <stack>

using vec_2D = std::pair<int, int>;
std::ostream& operator<<(std::ostream& os, const vec_2D data)
{
	os << '(' << data.first << ", " << data.second << ')';
	return os;
}


int main()
{
	graph::adjacency_matrix a;
	a.init(9);

	tree::node<vec_2D> tree(vec_2D(0, 0));
	std::stack<vec_2D> stack;
	


	std::cout << a << std::endl;
	
}

