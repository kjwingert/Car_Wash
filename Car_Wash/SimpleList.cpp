#include "SimpleList.h"
#include "Node.h"
#define WASH_TIME 3

/// <summary>
/// Destructor
/// </summary>
SimpleList::~SimpleList()
{
	Node* temp;
	while (_head != NULL)
	{
		temp = _head;
		_head = temp->next;
		delete temp;
	}
}


/// <summary>
/// Queues a new item at the end of the queue
/// </summary>
/// <param name="newValue">The integer value of the new item</param>
void SimpleList::QueueItem(int newValue)
{
	Node* temp = new Node;
	temp->value = newValue;
	temp->next = NULL;

	if (_head == NULL)	// Empty List
	{
		_head = _tail = temp;
	}
	else
	{
		_tail->next = temp;
		_tail = temp;
	}
	cout << "Queued Item" << endl;
}

/// <summary>
/// Dequeues the next item in the queue
/// </summary>
/// <returns>The value of the next node</returns>
int SimpleList::DequeueItem()
{
	// Is empty?
	if (_head == NULL)
		return -1;

	Node* temp = _head;
	_head = temp->next;

	// Set the new head to maintain the list
	// even if the next it is NULL (empty)
	if (_head == NULL)
		_tail = NULL;

	int nReturn = temp->value;
	delete temp;

	cout << "Dequeued Node" << endl;
	return nReturn;
}

/// <summary>
/// Display the entire list as it exists currently
/// </summary>
void SimpleList::DisplayList()
{
	cout << "SimpleList Values" << endl;
	// If empty, just return nothing
	if (_head == NULL)
		return;

	Node* temp = _head;
	
	// Loop through until all item have been printed
	while (1)
	{
		cout << temp->value << endl;

		// If at end, exit
		if (temp == _tail)
			return;

		temp = temp->next;
	}
}