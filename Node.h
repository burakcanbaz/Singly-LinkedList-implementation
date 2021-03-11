#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template<typename T>
struct Node{

	T data;
	//T data = T{};
	Node<T> *next = nullptr;
	Node() = default;

	Node(const T& data)
	{
		this->data = data;
	}

};

#endif /* NODE_H_ */
