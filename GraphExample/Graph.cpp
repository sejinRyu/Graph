#include "stdafx.h"
#include "Graph.h"

namespace graph
{
	void adjacency_matrix::init(const size_t size)
	{
		this->matrix<int>::assign(size, std::vector<int>(size, weight::inf));
		for (size_t i = 0; i < size; i++)
			(*this)[i][i] = 0;
	}

	adjacency_matrix::adjacency_matrix(const size_t size)
	{
		this->init(size);
	}

	void adjacency_matrix::insert_edge(const vertex src, const vertex dst, const int weight,
		const bool direction)
	{
		(*this)[src][dst] = weight;

		//무방향일때 - 대각선축으로 대칭
		if (!direction)
			(*this)[dst][src] = weight;
	}

	void adjacency_matrix::delete_edge(const vertex src, const vertex dst, const bool direction)
	{
		this->insert_edge(src, dst, weight::inf, direction);
	}

	int adjacency_matrix::get_weight(const vertex src, const vertex dst)
	{
		return (*this)[src][dst];
	}



};