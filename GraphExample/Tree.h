#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

namespace Tree
{
	static class Tree
	{
	public:
		template<typename T>
		static void PrintPreOrder(Node<T>& root_node)
		{
			std::cout <<root_node.GetDepth()<<" : "<< root_node << std::endl;
			for (size_t i = 0; i < root_node.Size(); i++)
			{
				PrintPreOrder(root_node[i]);
			}
		}

		template<typename T>
		static void PrintLevelOrder(Node<T>& root_node)
		{
			std::queue<Node<T>* > q;
			q.push(&root_node);
			
			int depth = root_node.GetDepth();

			while (!q.empty())
			{
				Node<T>& node = *q.front();
				q.pop();

				if (depth != node.GetDepth())
				{
					depth = node.GetDepth();
					std::cout << std::endl;
				}
				std::cout << node << ' ';

				for (size_t i = 0; i < node.Size(); i++)
				{
					q.push(&node[i]);
				}
			}

			
		}

		//template<typename T, typename Func>
	};

}	

