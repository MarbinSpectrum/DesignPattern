#include "IteratorPattern.h"
#include <string>
#include <iostream>

namespace IteratorPattern
{
	template<typename T>
	Node<T>::Node(const T& value)
	: value(value)
	, left(nullptr)
	, right(nullptr)
	, tree(nullptr)
	{
	}

	template<typename T>
	Node<T>::Node(const T& value, Node<T>* const left, Node<T>* const right)
	: value(value)
	, left(left)
	, right(right)
	, tree(nullptr)
	{
		this->left->tree = tree;
		this->right->tree = tree;
		this->left->parent = this;
		this->right->parent = this;
	}

	template<typename T>
	void Node<T>::set_tree(BinaryTree<T>* t)
	{
		tree = t;
		if (left != nullptr)
		{
			left->set_tree(t);
		}
		if (right != nullptr)
		{
			right->set_tree(t);
		}
	}

	template<typename T>
	BinaryTree<T>::BinaryTree(Node<T>* const root)
	: root(root)
	{
		root->set_tree(this);
	}

	template<typename T>
	template<typename U>
	BinaryTree<T>::PreOrderIterator<U>::PreOrderIterator(Node<U>* curent)
		: curent(curent)
	{
	}

	template<typename T>
	template<typename U>
	bool BinaryTree<T>::PreOrderIterator<U>::operator!=(const PreOrderIterator<U>& other)
	{
		return curent != other.curent;
	}

	template<typename T>
	template<typename U>
	Node<U>& BinaryTree<T>::PreOrderIterator<U>::operator*()
	{
		return *curent;
	}

	template<typename T>
	template<typename U>
	BinaryTree<T>::PreOrderIterator<U>& BinaryTree<T>::PreOrderIterator<U>::operator++()
	{
		if (curent->right)
		{
			curent = curent->right;
			while (curent->left)
			{
				curent = curent->left;
			}
		}
		else
		{
			Node<T>* p = curent->parent;
			while (p && curent == p->right)
			{
				curent = p;
				p = p->parent;
			}
			curent = p;
		}
		return *this;
	}

	template<typename T>
	BinaryTree<T>::iterator BinaryTree<T>::begin()
	{
		Node<T>* n = root;

		if (n)
		{
			while (n->left)
			{
				n = n->left;
			}
		}
		return BinaryTree<T>::iterator(n);
	}

	template<typename T>
	BinaryTree<T>::iterator BinaryTree<T>::end()
	{
		return BinaryTree<T>::iterator(nullptr);
	}

	void IteratorPattern::Run()
	{
		BinaryTree<std::string> family
		{
			new Node<std::string>
			{
				"me",
				new Node<std::string>
				{
					"mother",
					new Node<std::string>{"mother's mother"},
					new Node<std::string>{"mother's father"}
				},
				new Node<std::string>{"father"}
			}
		};

		for (auto it = family.begin(); it != family.end(); ++it)
		{
			std::cout << (*it).value << std::endl;
		}
	}
};
