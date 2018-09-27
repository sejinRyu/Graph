#pragma once
#include <memory>
#include <vector>

namespace Tree
{
	template<typename T>
	class Node
	{
	private:
		T data;
		std::vector<std::unique_ptr<Node<T> > > sub_tree;
		const size_t depth_level;

		Node(const T& data, const size_t depth) : data(data), depth_level(depth)
		{

		}

		Node(T&& data, const size_t depth) : data(data), depth_level(depth)
		{

		}

	public:
		using ValueType = T;

		void InsertNode(const T& data)
		{
			this->sub_tree.push_back(std::unique_ptr<Node<T> >(new Node<T>(data, this->depth_level + 1)));
			return;
		}
		
		void InsertNode(T&& data)
		{
			this->sub_tree.push_back(std::unique_ptr<Node<T> >(new Node<T>(std::move(data), this->depth_level + 1)));
			return;
		}

		void DeleteNode(const size_t index)
		{
			if (this->sub_tree.size() <= index)
				throw std::out_of_range("out_of_range");

			(*this)[index].DeleteAllNode();


			this->sub_tree[index].reset();
			this->sub_tree.erase(this->sub_tree.begin() + index);
		}

		void DeleteAllNode()
		{
			for (auto& var : this->sub_tree)
			{
				var->DeleteAllNode();
				var.reset();
			}
			this->sub_tree.erase(this->sub_tree.begin(), this->sub_tree.end());
		}

		Node<T>& operator[](const size_t index)
		{
			if (this->sub_tree.size() <= index)
				throw std::out_of_range("out_of_range");
			return *this->sub_tree[index].get();
		}

		const size_t Size() const
		{
			return this->sub_tree.size();
		}

		Node<T>& operator=(const T& data)
		{
			this->data = data;
			return *this;
		}

		operator T&()
		{
			return this->data;
		}

		Node(const T& data) :data(data), depth_level(0)
		{

		}

		Node(T&& data) :data(data), depth_level(0)
		{

		}

		const size_t GetDepth() const
		{
			return this->depth_level;
		}

	};

}
