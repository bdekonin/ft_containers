/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/23 14:23:32 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 18:58:08 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
# define AVL_HPP

#include <iostream>
template <typename T, class Compare = std::less<T> >
class AVL
{
	public:
		class node
		{
			public:
				T key;
				int height;
				node *left;
				node *right;
				node *parent;
				node(T k)
				{
					height = 1;
					key = k;
					left = NULL;
					right = NULL;
				}
		};
	
	AVL()
	: root(NULL), n(0)
	{
		
	}
	node *root;
	int n;



	void insert(T key)
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
	node *search(T x)
	{
		return this->searchUtil(x, this->root);
	}
	void remove(T x)
	{
		this->removeUtil(this->root, x);
		n--;
	}
	void inorder()
	{
		this->inorderUtil(this->root);
	}

	private:
	void insertUtil(node *elem, node *tree)
	{
		if (elem->key < tree->key)
		{
			if (tree->left == NULL)
			{
				tree->left = elem;
				elem->parent = tree;
				
				if (tree->height < tree->left->height + 1)
				{
					tree->height = tree->left->height + 1;
				}
			}
			else
			{
				if (tree->height < tree->left->height + 1)
				{
					tree->height = tree->left->height + 1;
				}
				if ((tree->right != NULL && tree->left->height > tree->right->height + 1) ||
					(tree->right == NULL && tree->left->height > 1))
				{
					if (elem->key < tree->left->key)
					{
						this->singleRotateRight(tree);
					}
					else
					{
						this->doubleRotateRight(tree);
					}
				}
			}
		}
		else
		{
			if (tree->right == NULL)
			{
				tree->right = elem;
				elem->parent = tree;
				
				// this->resizeTree();

				if (tree->height < tree->right->height + 1)
				{
					tree->height = tree->right->height + 1;
				}
				
			}
			else
			{
				this->insertUtil(elem, tree->right);
				if (tree->height < tree->right->height + 1)
				{
					tree->height = tree->right->height + 1;
				}
				if ((tree->left != NULL && tree->right->height > tree->left->height + 1) ||
					(tree->left == NULL && tree->right->height > 1))
				{
					if (elem->key >= tree->right->key)
					{
						this->singleRotateLeft(tree);
					}
					else
					{
						this->doubleRotateLeft(tree);
					}
				}
			}
		}
	}
	node *searchUtil(T x, node *tree)
	{
		if (tree == NULL)
			return NULL;
		if (x == tree->key)
			return tree;
		if (x < tree->key)
			return this->searchUtil(x, tree->left);
		else
			return this->searchUtil(x, tree->right);
	}
	void removeUtil(node *tree, T key)
	{
		bool leftchild = false;
		if (tree != NULL)
		{
			if (tree->parent != NULL)
			{
				leftchild = tree->parent->left == tree;
			}

			if (key == tree->key)
			{
				if (tree->left == NULL && tree->right == NULL)
				{
					if (leftchild && tree->parent != NULL)
					{
						tree->parent->left = NULL;
					}
					else if (tree->parent != NULL)
					{
						tree->parent->right = NULL;
					}
					else
					{
						this->root = NULL;
					}
					// this->resizeTree();
					
				}
				else if (tree->left == NULL)
				{
					if (tree->parent != NULL)
					{
						if (leftchild)
						{
							tree->parent->left = tree->right;
						}
						else
						{
							tree->parent->right = tree->right;
						}
						tree->right->parent = tree->parent;
					}
					else
					{
						this->root = tree->right;
						this->root->parent = NULL;
					}
					// this.resizeTree();
				}
				else if (tree->right == NULL)
				{
					if (tree->parent != NULL)
					{
						if (leftchild)
						{
							tree->parent->left = tree->left;
						}
						else
						{
							tree->parent->right = tree->left;
						}
						tree->left->parent = tree->parent;
					}
					else
					{
						this->root = tree->left;
						this->root->parent = NULL;
					}
					// this.resizeTree();
				}
				else // tree.left != null && tree.right != null
				{
					node *tmp = tree;
					tmp = tree->left;
					while (tmp->right != NULL)
					{
						tmp = tmp->right;
					}
					
//					delete tree->key; ????
					
					tree->key = tmp->key; // COPY
					
					if (tmp->left == NULL)
					{
						if (tmp->parent != tree)
						{
							tmp->parent->right = NULL;
						}
						else
						{
							tree->left = NULL;
						}
						// this.resizeTree();
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
						// this.resizeTree();
					}
					
					node *oldnode = tmp;
					
					tmp = tmp->parent;
					
					if (height(tmp) != std::max(height(tmp->left), height(tmp->right)) + 1)
					{
						tmp->height = std::max(height(tmp->left), height(tmp->right)) + 1;	
					}
					// std::max(height(tree->left), height(tree->right)) + 1;

					while (tmp != tree)
					{
						node *tmpPar = tmp->parent;
						// TODO:  Add extra animation here?
						if (height(tmp->left)- height(tmp->right) > 1)
						{
							if (height(tmp->left->right) > height(tmp->left->left))
							{
								this->doubleRotateRight(tmp);
							}
							else
							{
								this->singleRotateRight(tmp);
							}
						}
						if (tmpPar->right != NULL)
						{
							if (height(tmpPar) != std::max(height(tmpPar->left), height(tmpPar->right)) + 1)
							{
								tmpPar->height = std::max(height(tmpPar->left), height(tmpPar->right)) + 1;
							}
						}
						tmp = tmpPar;
					}
					if (height(tree->right)- height(tree->left) > 1)
					{
						if (height(tree->right->left) > height(tree->right->right))
						{
							this->doubleRotateLeft(tree);
						}
						else
						{
							this->singleRotateLeft(tree);
						}
					}
					
					delete oldnode;
				}
			}
			else if (key < tree->key)
			{
				this->removeUtil(tree->left, key);
				if (height(tree->right)- height(tree->left) > 1)
				{
					if (height(tree->right->left) > height(tree->right->right))
					{
						this->doubleRotateLeft(tree);
					}
					else
					{
						this->singleRotateLeft(tree);
					}					
				}
				if (height(tree) != std::max(height(tree->left), height(tree->right)) + 1)
				{
					tree->height = std::max(height(tree->left), height(tree->right)) + 1;
				}
			}
			else
			{
				this->removeUtil(tree->right, key);
				if (height(tree->left)- height(tree->right) > 1)
				{
					if (height(tree->left->right) > height(tree->left->left))
					{
						this->doubleRotateRight(tree);
					}
					else
					{
						this->singleRotateRight(tree);
					}					
				}
				if (height(tree) != std::max(height(tree->left), height(tree->right)) + 1)
				{
					tree->height = std::max(height(tree->left), height(tree->right)) + 1;
				}
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
		{
			t2->parent = A;
		}
		B->parent = A->parent;
		if (this->root == A)
		{
			this->root = B;
		}
		else
		{
			if (this->isLeftChild(A))
			{
				A->parent->left = B;
			}
			else
			{
				A->parent->right = B;
			}
		}
		B->left = A;
		A->parent = B;
		A->right = t2;
		this->resetHeight(A);
		this->resetHeight(B);

		// this->resizeTree();
	}
	void singleRotateRight(node *tree)
	{
		node *B = tree;
		node *t3 = B->right;
		node *A = tree->left;
		node *t1 = A->left;
		node *t2 = A->right;
		
		if (t2 != NULL)
		{
			t2->parent = B;
		}
		A->parent = B->parent;
		if (this->root == B)
		{
			this->root = A;
		}
		else
		{
			if (this->isLeftChild(B))
			{
				B->parent->left = A;
			}
			else
			{
				B->parent->right = A;
			}
		}
		A->right = B;
		B->parent = A;
		B->left = t2;
		this->resetHeight(B);
		this->resetHeight(A);
		// this.resizeTree();			
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
			{
				C->parent->left = B;
			}
			else
			{
				C->parent->right = B;
			}
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
		
		// this->resizeTree();
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
			{
				A->parent->left = B;
			}
			else
			{
				A->parent->right = B;
			}
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
		
		// this.resizeTree();
	}

	/* Utilities */
	bool isLeftChild(node *node)
	{
		if (node->parent == NULL)
		{
			return true;
		}
		return node->parent->left == node;	
	}
	void resetHeight(node *tree)
	{
		if (tree != NULL)
		{
			int newHeight = std::max(height(tree->left), height(tree->right)) + 1;
			
			if (tree->height != newHeight)
			{
				tree->height = newHeight;
			}
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
		void printBT(const node* node)
		{
			printBT("", node, true);    
		}
		void printBT()
		{
			// this->recalculate(this->root, 0);
			// reloop(this->root);
			printBT("", this->root, true);    
		}
};

#endif // UTILS_HPP