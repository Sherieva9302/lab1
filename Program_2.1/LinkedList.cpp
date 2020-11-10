#include <stdexcept>
#include "List.h"
#include <iostream>

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 0;
}


void LinkedList::add_first(int newElem)
{
	head = new Node(newElem);
	tail = head;
}


size_t LinkedList::get_size() 
{
	return size;
}

void LinkedList::push_back(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Node(newElem, tail);
		tail = tail->next;
	}
	size++;
}


void LinkedList::push_front(int newElem) 
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head->prev = new Node(newElem, nullptr, head);
		head = head->prev;

	}
	size++;

}

void LinkedList::pop_back() //delete last elem
{
	if (size == 0) throw std::out_of_range("Last elem not found");

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	size--;
}

void LinkedList::pop_front() // delete first elem
{
	if (size == 0) {
		throw out_of_range("First elem not found");
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		head = head->next;
		delete head->prev;
		size--;
	}
}

int LinkedList::at(size_t index) 
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		size_t counter = 0;
		Node* current = head;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

void LinkedList::insert(int newElem, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index == 0) { 
		push_front(newElem);
	}
	else {										
		Node* new_elem = new Node(newElem);
		Node* cur = head;
		for (int i = 0; i < int(index) - 1; i++) //setting cursor on correct spot
		{
			cur = cur->next;
		} 
		new_elem->prev = cur;
		new_elem->next = cur->next;		//insert
		cur->next = new_elem;
		(new_elem->next)->prev = new_elem;
		size++;
	}
}

void LinkedList::remove(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}

	if (index == 0) pop_front();
	else
		if (index == size) pop_back();
		else
		{
			Node* cur = head;
			for (int i = 0; i < int(index); i++) //setting cursor on correct spot
			{
				cur = cur->next;
			}
			(cur->prev)->next = cur->next; 
			(cur->next)->prev = cur->prev;
			delete cur;
			size--;
		}

}

void LinkedList::print_to_console() 
{
	if (isEmpty()) cout << "The list is empty";
	Node* cur = head;
	while (cur != nullptr)	
	{ 
		cout << cur->data << " "; 
		cur = cur->next; 
	} 
	delete cur;
}

void LinkedList::clear()
{
	while (size > 0)
	{
		pop_back();
	}
}

void LinkedList::set(size_t index, int newData) //replacement
{
	if (index >= size)
	{
		throw out_of_range("Index is greater than list size");
	}
	else
	{
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		cur->data = newData;
	}
}

bool LinkedList::isEmpty()
{
	if (size == 0) return 1;
	else return 0;
}

bool LinkedList::contains(LinkedList *lst2)
{

	int counter = 0, counter2 = 0, stop = 0;
	if ((size==0)||(lst2->size==0))
	{
		throw out_of_range("The list is empty");
	}
	if (size < lst2->get_size())
	{
		throw out_of_range("Second list is greater then first list");
	}

	for (counter = 0; counter <= int(size - lst2->get_size()); counter++)
	{

		while (at(counter) == lst2->at(counter2)) //while elements are equal
		{
			stop = counter; //point of returned
			counter++; //go to next
			counter2++;
			if (counter >= int(size)) break;
		}

		if (counter2 == lst2->get_size()) return 1;
		counter2 = 0;
		if (stop!=0) counter = stop; //return
		stop = 0;
	}

	return 0;

}

LinkedList::~LinkedList() 
{
	clear(); 
}