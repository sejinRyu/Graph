// GraphExample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"
#include "Graph.h"


using vec_2D = std::pair<int, int>;

std::ostream& operator<<(std::ostream& os, vec_2D data)
{
	os << '(' << data.first << ", " << data.second << ')';
	return os;
}

int main()
{
	Graph::AdjacencyMatrix a;
	a.Init(10);



	std::cout << a << std::endl;
	
}

