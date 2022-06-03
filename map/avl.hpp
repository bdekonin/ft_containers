/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/23 14:23:32 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 20:59:33 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_AVL_HPP
# define MAP_AVL_HPP

#include <iostream>

template <typename value_type,
		class Compare = std::less<value_type>,
		class Alloc = std::allocator<value_type> >
class MAP_AVL
{
	public:
		class node
		{
			public:
				value_type key;
				int height;
				node *left;
				node *right;
				node *parent;
				node(value_type k)
				{
					height = 1;
					key = k;
					left = NULL;
					right = NULL;
				}
		};
	
	private:
	/* Private Member Variables */
		node *root;
		int n;
		Compare comp;
		Alloc _alloc;

	public:
		MAP_AVL()
		: root(NULL), n(0), comp(), _alloc()
		{
			this->comp = Compare();
			this->_alloc = Alloc();
		}

	/* Main functions */
		void insert(value_type key)
		{
			if (this->root == NULL)
			{
				this->root = new node(key);
				this->n++;
				return ;
			}
			else
			{
				node *new_node = new node(key);
				this->insertUtil(new_node, this->root);
				n++;
			}
		}
		node *search(value_type x)
		{
			return this->searchUtil(x, this->root);
		}
		void remove(value_type x)
		{
			if (n == 0)
			{
				std::cout << "Tree is empty" << std::endl;
				return ;
			}
			this->removeUtil(this->root, x);
			n--;
		}
		void inorder()
		{
			this->inorderUtil(this->root);
		}
	
	/* Getters */
		const int size() const
		{
			return this->n;
		}
		const node *getRoot() const
		{
			return this->root;
		}
		const Compare getComp() const
		{
			return this->comp;
		}
		
		node *begin() // Get most left node (smallest)
		{
			node *temp = this->root;

			while (temp->left != NULL)
				temp = temp->left;
			return temp;
		}
		const node*end() const // Get most right node (biggest)
		{
			node *temp = this->root;

			while (temp->right != NULL)
				temp = temp->right;
			return temp;
		}

	/* Utils functions */
		void insertUtil(node *elem, node *tree)
		{
			// if (elem->key < tree->key) // Comp()
			if (this->comp(elem->key, tree->key) == true)
			{
				if (tree->left == NULL)
				{
					tree->left = elem;
					elem->parent = tree;
					
					if (tree->height < tree->left->height + 1)
						tree->height = tree->left->height + 1;
				}
				else
				{
					this->insertUtil(elem, tree->left);
					if (tree->height < tree->left->height + 1)
						tree->height = tree->left->height + 1;
					if ((tree->right != NULL && tree->left->height > tree->right->height + 1) ||
						(tree->right == NULL && tree->left->height > 1))
					{
						if (this->comp(elem->key, tree->left->key) == true)
							this->singleRotateRight(tree);
						else
							this->doubleRotateRight(tree);
					}
				}
			}
			else // Comp()
			{
				if (tree->right == NULL)
				{
					tree->right = elem;
					elem->parent = tree;

					if (tree->height < tree->right->height + 1)
						tree->height = tree->right->height + 1;
				}
				else 
				{
					this->insertUtil(elem, tree->right);
					if (tree->height < tree->right->height + 1)
						tree->height = tree->right->height + 1;
					if ((tree->left != NULL && tree->right->height > tree->left->height + 1) ||
						(tree->left == NULL && tree->right->height > 1))
					{
						if (elem->key >= tree->right->key)
							this->singleRotateLeft(tree);
						else
							this->doubleRotateLeft(tree);
					}
				}
			}
		}
		node *searchUtil(value_type x, node *tree)
		{
			if (tree == NULL)
				return NULL;
			if (x == tree->key)
				return tree;
			if (this->comp(x, tree->key) == true)
				return this->searchUtil(x, tree->left);
			else
				return this->searchUtil(x, tree->right);
		}
		void removeUtil(node *tree, value_type key)
		{
			bool leftchild = false;
			if (tree != NULL)
			{
				if (tree->parent != NULL)
					leftchild = tree->parent->left == tree;

				if (key == tree->key)
				{
					if (tree->left == NULL && tree->right == NULL)
					{
						if (leftchild && tree->parent != NULL)
							tree->parent->left = NULL;
						else if (tree->parent != NULL)
							tree->parent->right = NULL;
						else
							this->root = NULL;
					}
					else if (tree->left == NULL)
					{
						if (tree->parent != NULL)
						{
							if (leftchild)
								tree->parent->left = tree->right;
							else
								tree->parent->right = tree->right;
							tree->right->parent = tree->parent;
						}
						else
						{
							this->root = tree->right;
							this->root->parent = NULL;
						}
					}
					else if (tree->right == NULL)
					{
						if (tree->parent != NULL)
						{
							if (leftchild)
								tree->parent->left = tree->left;
							else
								tree->parent->right = tree->left;
							tree->left->parent = tree->parent;
						}
						else
						{
							this->root = tree->left;
							this->root->parent = NULL;
						}
					}
					else // tree.left != null && tree.right != null
					{
						node *tmp = tree;
						tmp = tree->left;
						while (tmp->right != NULL)
							tmp = tmp->right;

						tree->key = tmp->key; // COPY
						
						if (tmp->left == NULL)
						{
							if (tmp->parent != tree)
								tmp->parent->right = NULL;
							else
								tree->left = NULL;
						}
						else
						{
							if (tmp->parent != tree)
							{
								tmp->parent->right = tmp->left;
								tmp->left->parent = tmp->parent;
							}
							else
							{
								tree->left = tmp->left;
								tmp->left->parent = tree;
							}
						}
						
						node *oldnode = tmp;
						
						tmp = tmp->parent;
						
						if (height(tmp) != std::max(height(tmp->left), height(tmp->right)) + 1)
							tmp->height = std::max(height(tmp->left), height(tmp->right)) + 1;	
						while (tmp != tree)
						{
							node *tmpPar = tmp->parent;
							// TODO:  Add extra animation here?
							if (height(tmp->left)- height(tmp->right) > 1)
							{
								if (height(tmp->left->right) > height(tmp->left->left))
									this->doubleRotateRight(tmp);
								else
									this->singleRotateRight(tmp);
							}
							if (tmpPar->right != NULL)
							{
								if (height(tmpPar) != std::max(height(tmpPar->left), height(tmpPar->right)) + 1)
									tmpPar->height = std::max(height(tmpPar->left), height(tmpPar->right)) + 1;
							}
							tmp = tmpPar;
						}
						if (height(tree->right)- height(tree->left) > 1)
						{
							if (height(tree->right->left) > height(tree->right->right))
								this->doubleRotateLeft(tree);
							else
								this->singleRotateLeft(tree);
						}
						
						delete oldnode;
					}
				}
				else if (this->comp(key, tree->key) == true)
				{
					this->removeUtil(tree->left, key);
					if (height(tree->right)- height(tree->left) > 1)
					{
						if (height(tree->right->left) > height(tree->right->right))
							this->doubleRotateLeft(tree);
						else
							this->singleRotateLeft(tree);
					}
					if (height(tree) != std::max(height(tree->left), height(tree->right)) + 1)
						tree->height = std::max(height(tree->left), height(tree->right)) + 1;
				}
				else // Comp()
				{
					this->removeUtil(tree->right, key);
					if (height(tree->left)- height(tree->right) > 1)
					{
						if (height(tree->left->right) > height(tree->left->left))
							this->doubleRotateRight(tree);
						else
							this->singleRotateRight(tree);
					}
					if (height(tree) != std::max(height(tree->left), height(tree->right)) + 1)
						tree->height = std::max(height(tree->left), height(tree->right)) + 1;
				}
			}	
		}
		void inorderUtil(node * head)
		{
			if(head == NULL)
				return ;
			this->inorderUtil(head->left);
			std::cout << head->key << " ";
			this->inorderUtil(head->right);
		}

	/* Rotations */
		void singleRotateLeft(node *tree)
		{
			node *A = tree;
			node *B = tree->right;
			node *t1 = A->left;
			node *t2 = B->left;
			node *t3 = B->right;
			
			if (t2 != NULL)
				t2->parent = A;

			B->parent = A->parent;

			if (this->root == A)
				this->root = B;
			else
			{
				if (this->isLeftChild(A))
					A->parent->left = B;
				else
					A->parent->right = B;
			}

			B->left = A;
			A->parent = B;
			A->right = t2;

			this->resetHeight(A);
			this->resetHeight(B);

		}
		void singleRotateRight(node *tree)
		{
			node *B = tree;
			node *t3 = B->right;
			node *A = tree->left;
			node *t1 = A->left;
			node *t2 = A->right;
			
			if (t2 != NULL)
				t2->parent = B;

			A->parent = B->parent;

			if (this->root == B)
				this->root = A;
			else
			{
				if (this->isLeftChild(B))
					B->parent->left = A;
				else
					B->parent->right = A;
			}

			A->right = B;
			B->parent = A;
			B->left = t2;

			this->resetHeight(B);
			this->resetHeight(A);
		}
		void doubleRotateRight(node *tree)
		{
			node *A = tree->left;
			node *B = tree->left->right;
			node *C = tree;
			node *t1 = A->left;
			node *t2 = B->left;
			node *t3 = B->right;
			node *t4 = C->right;
			
			if (t2 != NULL)
			{
				t2->parent = A;
				A->right = t2;
			}
			if (t3 != NULL)
			{
				t3->parent = C;
				C->left = t2;
			}
			if (C->parent == NULL)
			{
				B->parent = NULL;
				this->root = B;
			}
			else
			{
				if (this->isLeftChild(C))
					C->parent->left = B;
				else
					C->parent->right = B;

				B->parent = C->parent;
				C->parent = B;
			}

			B->left = A;
			A->parent = B;
			B->right=C;
			C->parent=B;
			A->right=t2;
			C->left = t3;

			this->resetHeight(A);
			this->resetHeight(C);
			this->resetHeight(B);
		}
		void doubleRotateLeft(node *tree)
		{
			node*A = tree;
			node*B = tree->right->left;
			node*C = tree->right;
			node*t1 = A->left;
			node*t2 = B->left;
			node*t3 = B->right;
			node*t4 = C->right;
			
			if (t2 != NULL)
			{
				t2->parent = A;
				A->right = t2;
			}
			if (t3 != NULL)
			{
				t3->parent = C;
				C->left = t2;
			}
				
			
			if (A->parent == NULL)
			{
				B->parent = NULL;
				this->root = B;
			}
			else
			{
				if (this->isLeftChild(A))
					A->parent->left = B;
				else
					A->parent->right = B;

				B->parent = A->parent;
				A->parent = B;
			}

			B->left = A;
			A->parent = B;
			B->right=C;
			C->parent=B;
			A->right=t2;
			C->left = t3;

			this->resetHeight(A);
			this->resetHeight(C);
			this->resetHeight(B);
		}

	/* Utilities */
		bool isLeftChild(node *node)
		{
			if (node->parent == NULL)
				return true;

			return node->parent->left == node;	
		}
		void resetHeight(node *tree)
		{
			if (tree != NULL)
			{
				int newHeight = std::max(height(tree->left), height(tree->right)) + 1;
				
				if (tree->height != newHeight)
					tree->height = newHeight;
			}
		}
		int height(node * head)
		{
			if (head == NULL)
				return 0;
			return head->height;
		}

	/* Debugging */
		void printBT(const std::string& prefix, const node* node, bool isLeft)
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				
				// std::cout << node->key << " (" << node->parent << ") " << std::endl;
				if (node->parent)
					std::cout << node->key << " (" << node->parent->key << ") " << std::endl;
				else
					std::cout << node->key << " (" << "0" << ") " << std::endl;


				// enter the next tree level - left and right branch
				printBT( prefix + (isLeft ? "│   " : "    "), node->right, true);
				printBT( prefix + (isLeft ? "│   " : "    "), node->left, false);
			}
		}
		
	public:
		void printBT()
		{
			// this->recalculate(this->root, 0);
			// reloop(this->root);
			printBT("", this->root, true);    
		}
};

#endif // UTILS_HPP