#pragma once

class LinkedList
{
private:


	class Node
	{
	public:
		Node(int data, Node * prev = nullptr, Node * next = nullptr) 
		{
			this->data = data;
			this->prev = prev; 
			this->next = next;
		};
		~Node() {};

		int data;
		Node* prev;
		Node * next;
	};


	Node * head; //
	Node * tail; //
	size_t size; //

public:

	LinkedList();
	~LinkedList();

	void reset_list();
	void add_first(int newElem); //adding the first elem
	size_t get_size(); //getting list size 
	void push_back(int newElem);  //add in the end
	void push_front(int newElem); //add in the beginning
	void pop_back(); //delete last elem
	void pop_front();//delete first elem
	void insert(int, size_t); //insert elem by index
	int at(size_t index); //getting data element by index
	void remove(size_t); // deleting element by index
	void print_to_console(); //print list
	void clear(); //clears list
	void set(size_t, int); //replacement elem data by index
	bool isEmpty(); //check if the list is empty
	bool contains(LinkedList*); //checking for the contents of another list in the list
	
};
