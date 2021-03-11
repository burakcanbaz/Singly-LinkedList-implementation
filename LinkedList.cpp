#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList():head{new Node<T>()}
{
	current = head;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while(head != nullptr){
		current = head->next;
		delete head;
		head = current;

	}
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& obj){

	Node<T> *copiedObject = obj.head;
	head = new Node<T>();
	head->next = nullptr;
	copiedObject = copiedObject->next;
	current = head;

	while(copiedObject!= nullptr){
		current->next = new Node<T>();
		current = current->next;
		current->data = copiedObject->data;
		current->next = nullptr;
		copiedObject = copiedObject->next;
	}
	sizeOfList = obj.sizeOfList;
	arr = obj.arr;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& obj){

	//std::cout << obj.sizeOfList << std::endl;
	LinkedList<T> copiedObject(obj);
	std::swap(copiedObject.head,head);
	std::swap(copiedObject.sizeOfList,sizeOfList);
	return *this;

}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& obj) noexcept:head{new Node<T>()},current{head}{

	std::swap(head,obj.head);
	std::swap(current,obj.current);
	arr = obj.arr;
	sizeOfList = obj.sizeOfList;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& obj){
	std::swap(head,obj.head);
	std::swap(current,obj.current);
	arr = obj.arr;
	sizeOfList = obj.sizeOfList;
}

template<typename T>
std::ostream& operator<<(std::ostream& out,LinkedList<T>& obj){

	obj.current= obj.head->next;

	while(obj.current != nullptr){
		out << obj.current->data << std::endl;
		obj.current = obj.current->next;
	}
	return out;

}


template<typename T>
inline int LinkedList<T>::getSizeOfList(){
	return sizeOfList;
}

template<typename T>
LinkedList<T>& LinkedList<T>::insert(const T& data){

	current = head;

	while(current->next != nullptr)
		current = current->next;

	current->next = new Node<T>(data);
	sizeOfList++;
	return *this;

}

template<typename T>
LinkedList<T>& LinkedList<T>::insert(const T& data, int index){

	if(index < 0 || index > sizeOfList)
		throw std::invalid_argument("Index must be greater than 0 and not greater than size"); // user may not know the size variable. fix it.

	current = head;

	while(index > 0){
		current = current->next;
		index--;
	}

	Node<T> *add = new Node<T>(data);
	if(current->next != nullptr){
		add->next = current->next;
		current->next = add;
	}
	else{
		current->next = add;
	}
	sizeOfList++;
	return *this;

}

template<typename T>
LinkedList<T>& LinkedList<T>::addFirst(const T& data){

	current = head;

	Node<T> *addFirst = new Node<T>(data);
	if(current->next != nullptr){
		addFirst->next = current->next;
		current->next = addFirst;
	}

	else{
		current->next = addFirst;
	}

	sizeOfList++;
	return *this;
}


template<typename T>
void LinkedList<T>::addLast(const T& data){
	insert(data);
}


template<typename T>
LinkedList<T>& LinkedList<T>::clear(){

	if(sizeOfList == 0){
		throw std::invalid_argument("There is no element you cannot delete anything.");
	}

	current = head;
	Node<T> *temp = current->next;

	while(temp->next != nullptr){
		current->next = temp->next;
		temp->next = nullptr;
		delete temp;
		temp = current->next;
		sizeOfList--;
	}
	//delete temp;
	delete current->next;
	current->next = nullptr;
	sizeOfList--;
	return *this;
}


template<typename T>
bool LinkedList<T>::contains(const T& data){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;

	while(current->next != nullptr){
		if(current->data == data)
			return true;
		else
			current = current->next;
	}
	if(current->data == data)
		return true;
	else
		return false;

}


template<typename T>
inline T LinkedList<T>::element(){
	return (sizeOfList == 0) ? throw std::invalid_argument("No element in list!") : head->next->data;
}


template<typename T>
T LinkedList<T>::get(int index){

	if(sizeOfList == 0 || index > sizeOfList)
		throw std::invalid_argument("no element in list or index must be smaller than size");

	current = head->next;

	while(index > 0){
		current = current->next;
		index--;
	}

	return current->data;
}

template<typename T>
inline T LinkedList<T>::getFirst(){
	return (sizeOfList == 0)? throw std::invalid_argument("no element in list."): head->next->data;
}

template<typename T>
T LinkedList<T>::getLast(){

	if(sizeOfList == 0)
		throw std::invalid_argument("no element in list.");

	current = head->next;

	while(current->next != nullptr)
		current = current->next;


	return current->data;
}

template<typename T>
int LinkedList<T>::indexOf(const T& data){

	int notFound = -1;
	int indexOfData = 0;
	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;

	while(current->next != nullptr){
		if(current->data == data)
			return indexOfData;

		current = current->next;
		indexOfData++;

	}
	if(current->data == data)
		notFound = indexOfData;

	return notFound;
}

template<typename T>
int LinkedList<T>::lastIndexOf(const T& data){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	int indexCounter = 0;
	int lastOccur = -1;
	current = head->next;

	while(current->next != nullptr){

		if(current->data == data)
			lastOccur = indexCounter;

		indexCounter++;
		current = current->next;

	}
	if(current->data == data){
		lastOccur = indexCounter;
	}

	return lastOccur;
}

template<typename T>
T LinkedList<T>::poll(){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;

	head->next = head->next->next;
	current->next = nullptr;
	sizeOfList--;
	return current->data;
}

template<typename T>
T LinkedList<T>::pollFirst(){
	if(sizeOfList == 0)
		return {};

	current = head->next;

	head->next = head->next->next;
	current->next = nullptr;
	sizeOfList--;
	return current->data;
}

template<typename T>
T LinkedList<T>::pollLast(){
	if(sizeOfList == 0)
		return {};

	int counter = sizeOfList;
	current = head;

	while(counter != 1){
		current = current->next;
		counter--;
	}

	Node<T> *temp = current->next; // How can i delete temp ?
	current->next = nullptr;
	sizeOfList--;
	return temp->data;
}

template<typename T>
T LinkedList<T>::pop(){
	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;
	Node<T> *beforeLast = current;

	while(current->next != nullptr){
		beforeLast = current;
		current = current->next;
	}

	beforeLast->next = nullptr;
	T lastElementValue = current->data;
	delete current;
	current = nullptr;
	sizeOfList--;

	return lastElementValue;
}

template<typename T>
void LinkedList<T>::push(const T& data){
	addFirst(data);
}

template<typename T>
T LinkedList<T>::remove(){
	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;

	head->next = head->next->next;
	current->next = nullptr;
	sizeOfList--;
	return current->data;

}

template<typename T>
T LinkedList<T>::remove(int index){

	if(sizeOfList == 0 || index > sizeOfList)
		throw std::invalid_argument("No element in list.");

	current = head->next;
	Node<T> *nodeBeforeIndex = current;

	while(index > 0){
		nodeBeforeIndex = current;
		current = current->next;
		index--;
	}

	nodeBeforeIndex->next = current->next;
	sizeOfList--;
	T elementValueInRemovedIndex = current->data;
	delete current;
	current = nullptr;

	return elementValueInRemovedIndex;
}

template<typename T>
bool LinkedList<T>::removeFirstOccurrence(const T& data){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;
	Node<T> *elementBeforeFirstOccurrence = head;
	while(current->next != nullptr)
	{
		if(current->data == data)
		{
			elementBeforeFirstOccurrence->next = current->next;
			delete current;
			current = nullptr;
			sizeOfList--;
			return true;
		}
		else
		{
			elementBeforeFirstOccurrence = current;
			current = current->next;
		}
	}

	if(current->data == data)
	{
		elementBeforeFirstOccurrence->next = current->next;
		delete current;
		current = nullptr;
		sizeOfList--;
		return true;
	}
	else
		return false;
}

template<typename T>
T LinkedList<T>::removeLast(){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head->next;
	Node<T> *beforeLast = current;

	while(current->next != nullptr){
		beforeLast = current;
		current = current->next;
	}

	beforeLast->next = nullptr;
	T lastElementValue = current->data;
	delete current;
	current = nullptr;
	sizeOfList--;

	return lastElementValue;
}

template<typename T>
bool LinkedList<T>::removeLastOccurrence(const T& data){

	if(sizeOfList == 0)
		throw std::invalid_argument("No element in list.");

	current = head;
	Node<T> *prev1 = nullptr; //lastoccur
	Node<T> *prev2 = nullptr;

	while(current->next != nullptr)
	{
		prev2 = current;
		current = current->next;

		if(current->data == data)
		{
			prev1 = prev2;
		}

	}

	if(prev1 == nullptr)
		return false;

	current = prev1->next;
	prev1->next = current->next;
	delete current;
	current = nullptr;
	sizeOfList--;
	return true;
}

template<typename T>
T LinkedList<T>::set(int index,const T& data){
	if(sizeOfList == 0 || index > sizeOfList)
		throw std::invalid_argument("No element in list or given index greater than list size.");

	current = head->next;

	while(index > 0){
		current = current->next;
		index--;
	}

	T previousCurrentValue = current->data;
	current->data = data;

	return previousCurrentValue;

}

template<typename T>
std::vector<T>& LinkedList<T>::toVector(){

	current = head->next;
	for(int i = 0 ; i < size() ; i++){
		arr.push_back(current->data);
		current = current->next;
	}

	return arr;
}

template<typename T>
inline int LinkedList<T>::size(){
	return getSizeOfList();
}

