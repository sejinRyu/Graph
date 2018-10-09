#pragma once
#include <vector>
#include <iostream>

namespace graph
{
	template <typename T>
	using matrix = std::vector<std::vector<T> >;

	class adjacency_matrix : public matrix<int>
	{
	private:

	public:
		using vertex = unsigned int;
		enum weight : int
		{
			inf = INT32_MAX
		};

		void init(const size_t size);

		adjacency_matrix() = default;

		adjacency_matrix(const size_t size);

		void insert_edge(const vertex src, const vertex dst, const int weight = 1, const bool direction = true);

		void delete_edge(const vertex src, const vertex dst, const bool direction = true);

		//return weight
		int get_weight(const vertex src, const vertex dst);
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, matrix<T>& mat)
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

};