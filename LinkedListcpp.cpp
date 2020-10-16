#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()//Constructor
{
	head = nullptr;
	size = 0;
}

LinkedList::~LinkedList()//Destructor
{

	head = nullptr;
	size = 0;
}

void LinkedList::push_back(int newEl)//Adding to the end of the list
{
	Node* temp;
	if (size == 0)
	{
		head = new Node(newEl);
		tail = head;
	}
	else
	{
		temp = tail;
		tail->next = new Node(newEl);
		tail = tail->next;
		tail->prev = temp;
	}
	size++;
}

void LinkedList::push_front(int newEl)//Adding to the beginning of the list
{
	Node* temp;
	if (size == 0)
	{
		head = new Node(newEl);
		tail = head;
	}
	else
	{
		temp = head;
		head = new Node(newEl, head);
		temp->prev = head;
	}
	size++;
}

void LinkedList::pop_back()//Remove the last element
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* cur = head;
		while (cur->next != tail)
			cur = cur->next;
		cur->next = nullptr;
		delete tail;
		tail = cur;
		prev = tail->prev;
	}
	size--;
}

void LinkedList::pop_front()//Remove the first element
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* cur = head;
		cur = cur->next;
		cur->prev = nullptr;
		delete head;
		head = cur;
	}
}

void LinkedList::insert(int newEl, size_t index)//Adding element by index
{
	Node* p = nullptr , * cur;
	Node* temp = new Node(newEl);
	cur = head;
	int i = 0;
	while (cur!=NULL && i<index)
	{
		cur = cur->next;
		i++;
	}
	if (cur == NULL)
	{
		if (head == NULL)
		{
			cout << "List is empty\n";
			return;
		}
		cout << "Index is greater than list size\n";
		return;
	}
	if (cur != head)
	{
		p = cur->prev;
		cur->prev = temp;
		temp->next = cur;
		temp->prev = p;
	}
	else
		push_front(newEl);
	if (p != NULL)
		p->next = temp;
	size++;
}

int LinkedList::at(size_t index) const//Getting an item by index
{
	if (size == 0)
		cout << "List is empty\n";
	if ((index >= size)&&(size!=0))
		cout<<"Index is greater than list size";
	if((index<size)&&(size!=0))
	{
		size_t counter = 0;
		Node* cur = head;
		while (counter != index)
		{
			cur = cur->next;
			counter++;
		}
		return cur->data;
	}
}

void LinkedList::remove(size_t index)//Deleting an element by index
{
	size_t counter = 0;
	Node* cur = head;
	while (counter != index)
	{
		cur = cur->next;
		counter++;
	}
	if (cur == head)
	{
		pop_front();
		return;
	}
	if (cur == tail)
	{
		pop_back();
		return;
	}
	Node* prev, * next;
	prev = cur->prev;
	next = cur->next;
	if (prev != NULL)
		prev->next = cur->next;
	if (next != NULL)
		next->prev = cur->prev;
	delete cur;
}

size_t LinkedList::get_size()//Getting list size
{
	size_t counter = 0;
	Node* cur = head;
	while (cur != nullptr)
	{
		counter++;
		cur = cur->next;
	}
	return counter;
}

void LinkedList::print_to_console()//Printing list elements to console
{
	Node* cur = head;
	cout << "List elements:\t";
	while (cur != nullptr)
	{
		cout << cur->data << ' ';
		cur=cur->next;
	}
	cout << '\n';
}

void LinkedList::clear()//Removing all list elements
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	size = 0;
}

void LinkedList::set(size_t index, int newData)//Replacing the element by index with the passed element
{
	Node* cur = head;
	size_t counter = 1;
	while (counter <= index)
	{
		counter++;
		cur = cur->next;
	}
	cout << "Element " << cur->data;
	cur->data = newData;
	cout << " replaced by " << cur->data<<'\n';
}

bool LinkedList::isEmpty()//Checking if the list is empty
{
	if (head == nullptr && tail == nullptr)
		return true;
	else
		return false;
}

size_t LinkedList::find_first(LinkedList x, LinkedList y)//Finding the first occurrence of another list in the list
{
	if (x.isEmpty() || y.isEmpty())
		return 0;
	int counter=0;
	Node* curx, * cury;
	curx = x.head;
	cury = y.head;
	if (x.get_size() > y.get_size())
	{
		while (cury->data != curx->data && curx->next!=NULL)
		{
			curx = curx->next;
			counter++;
		}
		while (cury->data == curx->data && cury->next != NULL && curx->next!=NULL)
		{
			cury = cury->next;
			curx = curx -> next;
		}
		if (cury->next == NULL)
		{
			return counter;
		}
		else
			return 0;
	}
	else
	{
		if (x.get_size() == y.get_size())
			if (curx->data == cury->data)
				goto analysis;
			else
				return 0;
		while (curx->data != cury->data && cury->next != NULL)
		{
			cury = cury->next;
			counter++;
		}
	analysis:
		while (curx->data == cury->data && curx->next!=NULL && cury->next!=NULL)
		{
			curx = curx->next;
			cury = cury -> next;
		}
		if (curx->next == NULL)
		{
			return counter;
		}
		else
			return 0;
	}
}

bool LinkedList::isPrinted()//Is the list printed
{
	Node* cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << ' ';
		cur = cur->next;
	}
	cout << '\n';
	if (cur == nullptr)
		return true;
	else
		return false;
}