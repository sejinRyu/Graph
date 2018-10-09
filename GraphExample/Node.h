#pragma once
#include <memory>
#include <vector>

namespace tree
{
	template<typename T>
	class node
	{
	private:
		T data_;
		std::vector<std::unique_ptr<node<T> > > sub_tree_;
		const size_t depth_level_;

		node(const T& data, const size_t depth);

		node(T&& data, const size_t depth);

	public:
		using value_type = T;

		void insert_node(const T& data);

		void insert_node(T&& data);

		void delete_node(const size_t index);

		void delete_all_node();

		node<T>& operator[](const size_t index);

		const size_t size() const;

		node<T>& operator=(const T& data);

		operator T&();

		node(const T& data);

		node(T&& data);

		size_t get_depth() const;
	};

	template <typename T>
	node<T>::node(const T& data, const size_t depth): data_(data), depth_level_(depth)
	{
	}

	template <typename T>
	node<T>::node(T&& data, const size_t depth): data_(data), depth_level_(depth)
	{
	}

	template <typename T>
	void node<T>::insert_node(const T& data)
	{
		this->sub_tree_.push_back(std::unique_ptr<node<T>>(new node<T>(data, this->depth_level_ + 1)));
		return;
	}

	template <typename T>
	void node<T>::insert_node(T&& data)
	{
		this->sub_tree_.push_back(std::unique_ptr<node<T>>(new node<T>(std::move(data), this->depth_level_ + 1)));
		return;
	}

	template <typename T>
	void node<T>::delete_node(const size_t index)
	{
		if (this->sub_tree_.size() <= index)
			throw std::out_of_range("out_of_range");

		(*this)[index].DeleteAllNode();


		this->sub_tree_[index].reset();
		this->sub_tree_.erase(this->sub_tree_.begin() + index);
	}

	template <typename T>
	void node<T>::delete_all_node()
	{
		for (auto& var : this->sub_tree_)
		{
			var->DeleteAllNode();
			var.reset();
		}
		this->sub_tree_.erase(this->sub_tree_.begin(), this->sub_tree_.end());
	}

	template <typename T>
	node<T>& node<T>::operator[](const size_t index)
	{
		if (this->sub_tree_.size() <= index)
			throw std::out_of_range("out_of_range");
		return *this->sub_tree_[index].get();
	}

	template <typename T>
	const size_t node<T>::size() const
	{
		return this->sub_tree_.size();
	}

	template <typename T>
	node<T>& node<T>::operator=(const T& data)
	{
		this->data_ = data;
		return *this;
	}

	template <typename T>
	node<T>::operator T&()
	{
		return this->data_;
	}

	template <typename T>
	node<T>::node(const T& data): data_(data), depth_level_(0)
	{
	}

	template <typename T>
	node<T>::node(T&& data): data_(data), depth_level_(0)
	{
	}

	template <typename T>
	size_t node<T>::get_depth() const
	{
		return this->depth_level_;
	}
}
