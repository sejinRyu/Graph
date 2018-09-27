#pragma once
#include <vector>
#include <iostream>

namespace Graph
{
	template <typename T>
	using Matrix = std::vector<std::vector<T> >;

	class AdjacencyMatrix : public Matrix<int>
	{
	private:

	public:
		using Vertex = unsigned int;
		enum Weight : int
		{
			inf = INT32_MAX
		};

		void Init(size_t size)
		{
			this->Matrix<int>::assign(size, std::vector<int>(size, Weight::inf));
			for (size_t i = 0; i < size; i++)
				(*this)[i][i] = 0;
		}

		AdjacencyMatrix() :Matrix<int>()
		{

		}

		AdjacencyMatrix(size_t size)
		{
			this->Init(size);
		}

		void InsertEdge(const Vertex src, const Vertex dst, int weight = 1, bool direction = true)
		{
			(*this)[src][dst] = weight;

			//무방향일때 - 대각선축으로 대칭
			if (!direction)
				(*this)[dst][src] = weight;
		}

		void DeleteEdge(const Vertex src, const Vertex dst, bool direction = true)
		{
			this->InsertEdge(src, dst, Weight::inf, direction);
		}

		//return weight
		const int GetWeight(const Vertex src, const Vertex dst)
		{
			return (*this)[src][dst];
		}

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, Matrix<T>& mat)
	{
		for (const auto& vec : mat)
		{
			for (const auto& var : vec)
			{
				os << var << ' ';
			}
			os << std::endl;
		}
		return os;
	}

}