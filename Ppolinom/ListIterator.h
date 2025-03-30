#pragma once
#include <iterator>
#include "TList.h"
template <typename T> class TList;
template <typename T> struct Node;

template <typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T> {
	friend class TList<T>;
private:
	Node<T>* pCurr;
	ListIterator(Node<T>* nod) :pCurr(nod) {};
public:
	ListIterator(const ListIterator& li) : pCurr(li.pCurr) {};
	bool operator ==(const ListIterator& li) { return pCurr == li.pCurr; };
	bool operator !=(const ListIterator& li) { return pCurr != li.pCurr; };
	typename ListIterator<T>::reference operator*() const;
	ListIterator<T>& operator++();
	size_t operator-(ListIterator<T> const& other) const;
};

template<class T>
typename ListIterator<T>::reference ListIterator<T>::operator*() const
{
	return (pCurr->value);
}

template<class T>
ListIterator<T>& ListIterator<T>::operator++()
{
	pCurr = pCurr->pNext;
	return *this;
}

template<typename T>
inline size_t ListIterator<T>::operator-(ListIterator<T> const& other) const
{
	return (*this - other.pCurr);
}

