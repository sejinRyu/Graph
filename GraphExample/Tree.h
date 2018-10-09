#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

namespace tree
{
	class tree
	{
	public:
		template<typename T>
		static void print_pre_order(node<T>& root_node)
		{
			std::cout <<root_node.get_depth()<<" : "<< root_node << std::endl;
			for (size_t i = 0; i < root_node.size(); i++)
			{
				print_pre_order(root_node[i]);
			}
		}

		template<typename T>
		static void print_level_order(node<T>& root_node)
		{
			std::queue<node<T>* > q;
			q.push(&root_node);
			
			int depth = root_node.get_depth();

			while (!q.empty())
			{
				node<T>& node = *q.front();
				q.pop();

				if (depth != node.get_depth())
				{
					depth = node.get_depth();
					std::cout << std::endl;
				}
				std::cout << node << ' ';

				for (size_t i = 0; i < node.size(); i++)
				{
					q.push(&node[i]);
				}
			}

			
		}

		//template<typename T, typename Func>
	};

}	

