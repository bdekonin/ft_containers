/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 14:56:21 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/01/25 17:20:30 by bdekonin      ########   odam.nl         */
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
		node<T>		*left;
		node<T>		*right;

	public:
		node(T data)
		{
			this->data = data;
			this->left = NULL;
			this->right = NULL;
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
					parent->left = new_node;
				else
					parent->right = new_node;
			}
		}
		int max(int a , int b)
		{
			int res = (a > b) ? a : b;
			return res;
		}
		int height()
		{
			return (this->height(this->root));
		}
		int height(node<T> *node)
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
				std::cout << node->data << std::endl;

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
			printBT("", this->root, false);    
		}
	/* End -> Pretty Print Binary Tree */

};

#endif // TREE_HPP