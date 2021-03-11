#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "LinkedList.cpp"

int main(){

	using std::cout;
	using std::endl;

	LinkedList<int> n1;
	n1.insert(5);
	n1.insert(6,0);
	n1.addFirst(7);
	n1.addLast(8);
	n1.insert(5);
	n1.insert(9);
	n1.insert(10);
	n1.insert(11);
	n1.insert(7);
	n1.insert(7);
	n1.insert(7);
	n1.addLast(7);
	cout << "if 5 exists in the return true(1) else return false(0) -> "  << n1.contains(5) <<endl;
	cout << "First element value of the list =  "  << n1.element() << endl;
	cout << "Element value at the 2.index in the list =  " <<  n1.get(2) << endl;
	cout << "index of first occurrence of 5 = " << n1.indexOf(5) << endl;
	cout << "index of last occurrence of 5 = " << n1.lastIndexOf(5) << endl;
	cout << "Retrieves and removes the first element of the list = " << n1.poll() << endl;
	cout << "Retrieves and removes the last element of this list = " << n1.pollLast() << endl;
	cout << "Return and remove last element of list = " << n1.pop() << endl;
	n1.push(7); //push element to list.
	cout << "Retrieves and removes the first element of this list =  " << n1.remove() << endl;
	cout << "Retrieves and removes data at the specified position of list = " << n1.remove(3) << endl;
	cout << "Remove first occurrence of data in the list: " << n1.removeFirstOccurrence(6) << endl;
	cout << "Remove last occurence of data in the list: " << n1.removeLastOccurrence(7)  <<endl;
	n1.set(0,21); //change 0.index element with 21
	n1.toVector();  //LinkedList to STL vector

	cout << n1 << endl;

}

