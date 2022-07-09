#pragma once

namespace IteratorPattern
{
	template<typename T>
	struct Node;

	template<typename T>
	struct BinaryTree;

	template<typename T> 
	struct Node
	{
		T value;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
		BinaryTree<T>* tree;

		explicit Node(const T& value);
		Node(const T& value, Node<T>* const left, Node<T>* const right);
		void set_tree(BinaryTree<T>* t);
	};

	template<typename T>
	struct BinaryTree
	{
		Node<T>* root = NULL;

		explicit BinaryTree(Node<T>* const root);

		template<typename U>
		struct PreOrderIterator
		{
			Node<U>* curent;

			explicit PreOrderIterator(Node<U>* curent);

			bool operator!=(const PreOrderIterator<U>& other);
			Node<U>& operator*();
			PreOrderIterator<U>& operator++();
		};

		typedef PreOrderIterator<T> iterator;

		iterator begin();
		iterator end();
	};

	class IteratorPattern
	{
	public:
		static void Run();
	};
}
