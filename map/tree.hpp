/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:56:21 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/02/07 11:53:39 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include <iostream>


template <typename T>
class node
{
	public:
		T			data;
		node<T> 	*parent;
		node<T>		*left;
		node<T>		*right;
		int			height;
		int			balanceFactor;

	public:
		node(T data)
		{
			this->data = data;
			this->parent = NULL;
			this->left = NULL;
			this->right = NULL;
			this->height = 0; // maybe -1 because empty node has height -1
		}
};


template <typename T>
class tree
{
	public:
		node<T>		*root;

	public:
		tree(void)
		{
			this->root = NULL;
		}

		~tree(void)
		{
			this->root = NULL;
		}

		void		insert(T data)
		{
			node<T>		*new_node;

			new_node = new node<T>(data);
			if (this->root == NULL)
				this->root = new_node;
			else
			{
				node<T>		*parent;
				
				for (node<T> *current = this->root; current != NULL;)
				{
					parent = current;
					if (data < current->data)
						current = current->left;
					else
						current = current->right;
				}
				if (data < parent->data)
				{
					parent->left = new_node;
					new_node->parent = parent;
				}
				else
				{
					parent->right = new_node;
					new_node->parent = parent;
				}
			}
		}
		int max(int a , int b)
		{
			int res = (a > b) ? a : b;
			return res;
		}
		int height(node<T> *node) /* Returns amount of nodes, if you wanted amount of links return -1 instead of 0 */
		{
			if (node == NULL)
				return 0;
			return (1 + max(height(node->left), height(node->right)));
		}

	/* Start -> Pretty Print Binary Tree */
		void printBT(const std::string& prefix, const node<T>* node, bool isLeft)
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				
				std::cout << node->data << " (" << node->balanceFactor << ") " << std::endl;

				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}
		void printBT(const node<T>* node)
		{
			printBT("", node, false);    
		}
		void printBT()
		{
			// this->recalculate(this->root, 0);
			reloop(this->root);
			printBT("", this->root, false);    
		}
	/* End -> Pretty Print Binary Tree */
	

	/* https://stackoverflow.com/questions/2603692/what-is-the-difference-between-tree-depth-and-height */
	void recalculate(node<T> *leaf, int count = 0)
	{
		if (leaf == NULL)
			return ;
		leaf->height = count; // or height
		recalculate(leaf->left, count + 1);
		recalculate(leaf->right, count + 1);
	}
	void reloop(node<T> *leaf)
	{
		if (leaf == NULL)
			return ;
		
		// int temp;


		reloop(leaf->left);
		reloop(leaf->right);
		// get height of left and right
		int left = height(leaf->left);
		int right = height(leaf->right);

		if (leaf->left)
			leaf->left->height = left;
		if (leaf->right)
			leaf->right->height = right;
		leaf->balanceFactor = left - right;
	}
};

#endif // TREE_HPP