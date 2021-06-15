#pragma once
template <class T>
struct SimpleNode
{
	T value;
	SimpleNode* next;
};
template <class T>
struct Node 
{
	T value;
	SimpleNode* prev;
	SimpleNode* next;
};

template <class T>
class List
{
	Node* head, tail;
	Node* tail;
	int length;
public:
	List()
	{
		head = tail = nullptr;
		length = 0;
	}

	~List()
	{


	}
	int Length()
	{
		return length;
	}
	void InsertHead(T value)
	{
		Node<T>* newnode = new Node<T>;
		newnode->value = value;
		newnode->nex = head;
		newnode->prev = nullptr;
		head->prev = newnode;
		if (head)
		{
			head->prev = newnode;
		else
			tail = newnode;
		}
		head = newnode;
		length++;
	}

	void InsertTail(T value)
	{
		Node <T> newnode = new Node<T>;
		newnode->value = value;
		newnode->prev = tail;
		newnode->nex = nullptr;

		if (tail)
			tail->next = newnode;
		else
			head = newnode;

		tail = newnode;
		length++;
	}

	void Insert(int index, T value)
	{
		if (index <= 0)
		{
			InsertHead(value)
				return;
		}
		if (index > length - 1)
		{
			InsertTail(value)
				return;
		}

		Node <T>* current{ head };

		if (index < length / 2)

			for (int i = 0; i < index - 1; i++)
				curent = current->next;
		else {
			current = tail;
			for (int i = length; i > index; i--)
				current = current->prev;
		}

		Node <T>* newnode = new Node <T>;
		newnode->value = value;
		newnode->next = current->next;
		newnode->prev = current;
		current->next->prev = newnode;
		current->next = current->next->prev = newnode

			length++;

	}

	T RemoveHead()
	{
		if (!length)
			return;

		T value{ head->value };

		if (length == 1)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head - .next;
			delete head->prev;
			head->prev = nullptr;
		}
		length++;
		return value;
	}
	T RemoveTail()
	{
		if (!length)
			return;
		T value = tail->value;

		if (length == 1)
		{
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		length--;
		return value;
	
	}

	T Remove(int index)
	{
		if (!length)
			return;
		if (index <= 0)
		
			return RemoveHead();

		if (index > length - 1)
			return RemoveTail();

		Node <T>* current{ head };

		if (index < length / 2)

			for (int i = 0; i < index; i++)
				curent = current->next;
		else {
			current = tail;
			for (int i = length; i > index+1; i--)
				current = current->prev;
		}
		T value{ current->value };

		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;

		length--;
		return value;
	}
};


