#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <vector>
#include "Node.h"

template<typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<(std::ostream& ,LinkedList<T>& );


template<typename T>
class LinkedList {
	std::vector<T> arr;
	int sizeOfList = 0;
	Node<T> *head;
	Node<T> *current;

public:

	LinkedList();
	~LinkedList();

	LinkedList(const LinkedList<T>&);	  //copy constructor
	LinkedList<T>& operator=(const LinkedList<T>&);  	//copy assignment

	LinkedList(LinkedList<T>&&) noexcept;	  //move constructor
	LinkedList<T>& operator=(LinkedList<T>&&);  	//move assignment

	friend std::ostream& operator<< <>(std::ostream&,LinkedList<T>&);	  //<< operator overload

	int getSizeOfList(); 	//getter for sizeOfList variable.
	LinkedList<T>& insert(const T&); 	//take data as argument and insert data at the end of the list
	LinkedList<T>& insert(const T&, int); 	//take data and index as argument , insert data at the specified index of the list.

	LinkedList<T>& addFirst(const T&);  	//take data as argument and add it as a first element.
	void addLast(const T& data); 	//take data as argument and add it at the end of list.

	LinkedList<T>& clear(); 	//clear all linkedlist element

	bool contains(const T&);  	//take data as argument and if data exists return true if not return false.

	inline T element();  	// returns the first element of this list if no element throw exception.
	T get(int);  	//Returns the element at the specified position in this list.

	inline T getFirst();  	//returns the first element of list.
	T getLast();  	//returns the last element of list

	int indexOf(const T&);  	//return the first occurence of element in list.
	int lastIndexOf(const T&);  	//returns last occurrence of existing object if there is no element return -1.

	T poll();  	//Retrieves and removes the head (first element) of this list.
	T pollFirst();  	//Retrieves and removes the first element of this list, or returns null if this list is empty.
	T pollLast();  	//Retrieves and removes the last element of this list, or returns null if this list is empty.

	T pop();  	//return and remove last element of list if no element in list throw error.
	void push(const T&);  	//push data as a first element of list.

	T remove();  	//Retrieves and removes the head (first element) of this list.
	T remove(int);  	//Retrieves and removes data at the specified position of list.

	bool removeFirstOccurrence(const T&);	  //remove first occurrence of data in the list.
	T removeLast();  	//removes and returns last element of list.
	bool removeLastOccurrence(const T&);  	//remove last occurrence of data in the list.

	T set(int, const T&);	  //change value of data at the specified position in the list.

	std::vector<T>& toVector();  	//convert data to vector and return it.

	inline int size();  	//return size of list.


};


#endif /* LINKEDLIST_H_ */
