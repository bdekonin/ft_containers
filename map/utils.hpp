/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/23 14:23:32 by bdekonin      #+#    #+#                 */
/*   Updated: 2022/05/30 14:34:52 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
using namespace std;

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
			// if (y->data == 7)
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
					node<T> *temp = minValueNode(root->left); // change to smallest
					root->data = temp->data;
					temp->data = 99;
					
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
		void insert(T x)
		{
			this->root= this->insertUtil(this->root, x);
			this->rebuildParents(this->root, nullptr);
		}
		void remove(T x)
		{
			this->root= this->removeUtil(this->root, x);
		}
		node * search(T x)
		{
			return this->searchUtil(this->root,x);
		}
		void inorder()
		{
			this->inorderUtil(this->root);
			std::cout << std::endl;
		}

		/* temp */
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

		
	private:
		int height(node * head){
			if(head==NULL)
				return 0;
			return head->height;
		}
		node * rightRotation(node * head)
		{
			// node * newhead = head->left;
			// head->left = newhead->right;
			// newhead->right = head;
			// head->height = 1+max(height(head->left), height(head->right));
			// newhead->height = 1+max(height(newhead->left), height(newhead->right));
			// return newhead;

			node *A = head->left;
			node *B = head;
			node *t1 = A->left;
			node *t2 = A->right;
			node *t3 = B->right;
			
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
			B->height = 1+max(height(B->left), height(B->right));
			A->height = 1+max(height(A->left), height(A->right));
			// this.resizeTree();	
			return (A);
		}
		node * leftRotation(node * head)
		{
			// node * newhead = head->right;
			// head->right = newhead->left;
			// newhead->left = head;
			// head->height = 1+max(height(head->left), height(head->right));
			// newhead->height = 1+max(height(newhead->left), height(newhead->right));
			// return newhead;

			node *A = head;
			node *B = head->right;
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
			A->height = 1+max(height(A->left), height(A->right));
			B->height = 1+max(height(B->left), height(B->right));
			
			//this.resizeTree();
			return B;
		}

		void rebuildParents(node *head, node *parent)
		{
			if (head == NULL)
				return ;
			head->parent = parent;
			rebuildParents(head->left, head);
			rebuildParents(head->right, head);
		}

		void inorderUtil(node * head)
		{
			if(head == NULL)
				return ;
			inorderUtil(head->left);
			cout<<head->key<<" ";
			inorderUtil(head->right);
		}

		node * insertUtil(node * head, T x){
			if(head==NULL)
			{
				n += 1;
				node * temp = new node(x);
				return temp;
			}
			if(x < head->key)
				head->left = insertUtil(head->left, x);
			else if(x > head->key)
				head->right = insertUtil(head->right, x);
			head->height = 1 + max(height(head->left), height(head->right));
			int bal = height(head->left) - height(head->right);
			if(bal > 1)
			{
				if(x < head->left->key)
				{
					return rightRotation(head);
				}
				else
				{
					head->left = leftRotation(head->left);
					return rightRotation(head);
				}
			}
			else if(bal < -1)
			{
				if(x > head->right->key)
				{
					return leftRotation(head);
				}
				else
				{
					head->right = rightRotation(head->right);
					return leftRotation(head);
				}
			}
			return head;
		}
		node * removeUtil(node * head, T x){
			if(head==NULL)
				return NULL;
			if(x < head->key)
			{
				head->left = removeUtil(head->left, x);
			}
			else if(x > head->key)
			{
				head->right = removeUtil(head->right, x);
			}
			else
			{
				node * r = head->right;
				if(head->right==NULL)
				{
					node * l = head->left;
					delete(head);
					head = l;
				}
				else if(head->left==NULL)
				{
					delete(head);
					head = r;
				}
				else
				{
					while(r->left!=NULL) r = r->left;
					head->key = r->key;
					head->right = removeUtil(head->right, r->key);
				}
			}
			if(head == NULL)
				return head;
			head->height = 1 + max(height(head->left), height(head->right));
			int bal = height(head->left) - height(head->right);
			if(bal > 1)
			{
				if(height(head->left) >= height(head->right))
				{
					return rightRotation(head);
				}
				else
				{
					head->left = leftRotation(head->left);
					return rightRotation(head);
				}
			}
			else if(bal < -1)
			{
				if(height(head->right) >= height(head->left))
				{
					return leftRotation(head);
				}
				else
				{
					head->right = rightRotation(head->right);
					return leftRotation(head);
				}
			}
			return head;
		}
		node * searchUtil(node * head, T x){
			if(head == NULL)
				return NULL;
			T k = head->key;
			if(k == x)
				return head;
			if(k > x)
				return searchUtil(head->left, x);
			if(k < x)
				return searchUtil(head->right, x);
		}
		bool isLeftChild(node *curr)
		{
			if (curr->parent == NULL)
			{
				return true;
			}
			return curr->parent->left == curr;
		}
};

#endif // UTILS_HPP