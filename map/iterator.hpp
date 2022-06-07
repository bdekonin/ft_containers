/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:56:28 by bdekonin      #+#    #+#                 */
/*   Updated: 2021/12/01 22:33:53 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/*
** https://www.cplusplus.com/reference/iterator/
*/

# include <iostream>
# include "AVL.hpp"

namespace ft
{

	/* Iterator Tags */
		class input_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/InputIterator/ */
		class output_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/OutputIterator/ */
		class forward_iterator_tag : public input_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/ForwardIterator/ */
		class bidirectional_iterator_tag : public forward_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/BidirectionalIterator/ */
		class random_access_iterator_tag : public bidirectional_iterator_tag { }; /* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */

	template< class Category, class T, class Pointer = T*, class Reference = T&, class Distance = std::ptrdiff_t >
	class iterator
	{
		public:
			typedef T               value_type;
			typedef Distance        difference_type;
			typedef Pointer         pointer;
			typedef Reference       reference;
			typedef Category        iterator_category;
		public:
			/* Constructors */
			iterator() : _value(nullptr) { }
			iterator(pointer val) : _value(val) { }
			iterator(iterator const &src) { *this = src; }

			/* Destructor */
			virtual ~iterator() { }

			/* Operators */
			iterator	&operator=(iterator const &src)
			{
				this->_value = src._value;
				return (*this);
			}

		protected:
			pointer _value;
	};

	template < class T, class Category = ft::bidirectional_iterator_tag >
	class bidirectional_iterator : public iterator<Category, T>
	{
		public:
			typedef Category								iterator_category;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::ptrdiff_t							difference_type;

		/* Constructors */
		public:
			bidirectional_iterator() : iterator<Category, T>() { }
			bidirectional_iterator(pointer val) : iterator<Category, T>(val) { }

			/* Destructors */
			virtual ~bidirectional_iterator() { }
			
			/* Operators */
			bidirectional_iterator &operator = (bidirectional_iterator const &rhs)
			{
				if (this == &rhs)
					return *this;
				// pointer
				this->_value = rhs._value;
				return *this;
			}
		/* Operator Overloading */
		public:
			bool		operator == (bidirectional_iterator const &rhs) { return this->_value == rhs._value; } // a ==
			bool		operator != (bidirectional_iterator const &rhs) { return this->_value != rhs._value; } // a !=
			value_type	&operator * (void) { return *this->_value; } // a*
			value_type	*operator -> (void) { return this->_value; } // a->
			bidirectional_iterator	&operator++() 
			{
				this->_value++; return (*this);
			} // ++a
			bidirectional_iterator	operator++(int)
			{
				bidirectional_iterator old = *this;
				// this->_value++;
				this->nextNode();
				return (old);
			} // a++
			bidirectional_iterator	&operator--(void)
			{
				this->_value--; return (*this);
			} // --a
			bidirectional_iterator	operator--(int)
			{
				bidirectional_iterator old = *this;
				this->prevNode();
				return (old);
			} // a--
		public:

					void nextNode (void) // werkt niet waarschijnlijk door de std::less of std::greater
					{
						if (this->_value->right != this->_value->right->left)
						{
							this->_value = this->_value->right;
							while (this->_value->left != this->_value->left->left)
								this->_value = this->_value->left;
						}
						else
						{
							while (this->_value == this->_value->parent->right && this->_value != this->_value->parent)
								this->_value = this->_value->parent;
							this->_value = this->_value->parent;
						}
					}

					void prevNode (void)
					{
						if (this->_value == this->_value->parent)
						{
							while (this->_value->right != this->_value->right->left)
								this->_value = this->_value->right;
						}
						else if (this->_value->left != this->_value->left->left)
						{
							this->_value = this->_value->left;
							while (this->_value->right != this->_value->right->left)
								this->_value = this->_value->right;
						}
						else
						{
							while (this->_value == this->_value->parent->left && this->_value != this->_value->parent)
								this->_value = this->_value->parent;
							this->_value = this->_value->parent;
						}
					}
	};

} // namespace ft

#endif // ITERATOR_HPP
