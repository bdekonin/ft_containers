/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/23 14:23:32 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/25 14:07:33 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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
		node<T>	*getnext()
		{
			node<T> *it(this);

			if (it->right)
			{
				it = it->right;
				while (it->left)
					it = it->left;
			}
			else
			{
				node<T> *tmp = it;
				it = it->parent;
				while (it->left != tmp)
				{
					tmp = it;
					it = it->parent;
				}
			}
			return (it);
		}
		node<T>*	getprevious()
		{
			if (this == this->first_node || this == this->last_node)
				return this->parent;
			node* it(this);

			if (it->left)
			{
				it = it->left;
				while (it->right)
					it = it->right;
			}
			else
				while (it->data >= this->data)
					it = it->parent;
			return (it);
		}
};

template <typename T, class Compare = std::less<int> >
class avltree
{
	public:
		node<T> *root;

		avltree(void)
		{
			this->root = NULL;
		}

		~avltree(void)
		{
			this->root = NULL;
		}

		/* helper */
		int getBalanceFactor(node<T> *node)
		{
			if (!node)
				return 0;
			return height(node->left) - height(node->right);
		}
		int max(int a, int b)
		{
			return (a > b ? a : b);
		}
		int height(node<T> *node) /* Returns amount of nodes, if you wanted amount of links return -1 instead of 0 */
		{
			if (node == NULL)
				return 0;
			return (1 + max(height(node->left), height(node->right)));
		}

	/* https://www.geeksforgeeks.org/avl-tree-set-1-insertion/ */
		node<T> *rightRotate(node<T> *y)
		{
			node<T> *x = y->left;
			if (!x)
				return (x);
			node<T> *T2 = x->right;
		
			// Perform rotation
			x->right = y;
			y->left = T2;
		
			// Update heights
			y->height = max(height(y->left),
							height(y->right)) + 1;
			x->height = max(height(x->left),
							height(x->right)) + 1;
		
			// Return new root
			return x;
		}
		node<T> *leftRotate(node<T> *x)
		{
			node<T> *y = x->right;
			if (!y)
				return (x);
			node<T> *T2 = y->left;
		
			// Perform rotation
			y->left = x;
			x->right = T2;
		
			// Update heights
			x->height = max(height(x->left),   
							height(x->right)) + 1;
			y->height = max(height(y->left),
							height(y->right)) + 1;
		
			// Return new root
			return y;
		}

	/* Inserting Data */
		node<T>		*insert(T data)
		{
			this->root = this->insert(this->root, data);
			return root;
		}
		node<T>		*insert(node<T> *node, T data)
		{
			if (node == NULL)
				return (new ::node<T>(data));

			Compare comp = Compare();

			if (comp(data, node->data) == true)
			{
				node->left = this->insert(node->left, data);
				node->left->parent = node;
			}
			else if (comp(data, node->data) == false) // maybe true
			{
				node->right = this->insert(node->right, data);
				node->right->parent = node;
			}
			else
				return node;

			node->height = 1 + max(this->height(node->left), this->height(node->right));

			int balance = getBalanceFactor(node);

			// If this node becomes unbalanced, then
			// there are 4 cases
		
			// Left Left Case
			if (balance > 1 && data < node->left->data)
				return rightRotate(node);
		
			// Right Right Case
			if (balance < -1 && data > node->right->data)
				return leftRotate(node);
		
			// Left Right Case
			if (balance > 1 && data > node->left->data)
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		
			// Right Left Case
			if (balance < -1 && data < node->right->data)
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		
			/* return the (unchanged) node pointer */
			return node;
			
		}

	/* Deleting Data */
		/* Given a non-empty binary search tree,
		return the node with minimum key value
		found in that tree. Note that the entire
		tree does not need to be searched. */
		node<T> *minValueNode(node<T> *node)
		{
			::node<T> *curr = node;
		
			/* loop down to find the leftmost leaf */
			while (curr->left != NULL)
				curr = curr->left;
		
			return curr;
		}
		node<T> *deleteNode(T key)
		{
			this->root = this->deleteNode(this->root, key);
			return root;
		}
		node<T> *deleteNode(node<T> *root, T key) // change to T
		{
			// if key > current key -> right
			// else if key < current key -> left

			// if key == current key -> delete
			// {
				// if node has 2 children find largest noge in left subtree

				// copy largest value of left subtree into node to delete
				// remove we just copied
			// }

			if (root == NULL)
				return root;
			
			Compare comp = Compare();

			if (key < root->data)
			{
				deleteNode(root->left, key);
			}
			else if (key > root->data)
			{
				deleteNode(root->right, key);
			}
			else // data == key
			{
				// if node has 2 children find largest noge in left subtree
				if (root->left && root->right)
				{
					node<T> *temp = minValueNode(root->right); // change to smallest
					root->data = temp->data;

					
					delete (temp);
				}
				else
				{
					node<T> *temp = root;
					if (root->left == NULL)
						root = root->right;
					else if (root->right == NULL)
						root = root->left;
					delete temp;
				}
			}
			return this->root;
		}

		node<T> *rebalance()
		{
			node<T> *root = this->root;
			root->height = 1 + max(this->height(root->left), this->height(root->right));

			int balance = getBalanceFactor(root);
		
			// If this node becomes unbalanced,
			// then there are 4 cases
		
			// Left Left Case
			if (balance > 1 &&
				getBalanceFactor(root->left) >= 0)
				return rightRotate(root);
		
			// Left Right Case
			if (balance > 1 &&
				getBalanceFactor(root->left) < 0)
			{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		
			// Right Right Case
			if (balance < -1 &&
				getBalanceFactor(root->right) <= 0)
				return leftRotate(root);
		
			// Right Left Case
			if (balance < -1 &&
				getBalanceFactor(root->right) > 0)
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}

			return root;
		}




	/* Start -> Pretty Print Binary Tree */
		void printBT(const std::string& prefix, const node<T>* node, bool isLeft)
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				
				if (node->parent)
					std::cout << node->data << " (" << node->parent->data << ") " << std::endl;
				else
					std::cout << node->data << " (" << node->parent << ") " << std::endl;

				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}
		void printBT(const node<T>* node)
		{
			printBT("", node, true);    
		}
		void printBT()
		{
			// this->recalculate(this->root, 0);
			reloop(this->root);
			printBT("", this->root, true);    
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
		
	/* End -> Pretty Print Binary Tree */
};


#endif // UTILS_HPP