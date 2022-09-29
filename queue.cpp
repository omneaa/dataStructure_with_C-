#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next = NULL;
	Node()
	{
		next = NULL;

	}
};
/*queue operations
Dequeue:delete front element in the queue
enqueue:add element
peak:return the top element
search,count,isempty
clear
*/
class queue {
public:
	Node* front;
	Node* rear;
	queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool IsEmpty()
	{
		return(front == NULL);
	}

	void Enqueue(int item)
	{
		if (IsEmpty())
		{
			Node* newNode = new Node;
			newNode->data = item;
			front = rear = newNode;
		}
		else
		{
			Node* newNode = new Node;
			newNode->data = item;
			rear->next = newNode;
			rear = newNode;
		}
	}
	void Display()
	{
		if (IsEmpty())
			cout << "It's empty\n";
		else
		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << endl;;
				temp = temp->next;
			}
		}
	}
	void Dequeuq()
	{
		if (IsEmpty())
			cout << "it's empty\n";
		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* ptr = front;
			front = front->next;
			delete ptr;
		}
	}
	
	int Count()
	{
		int counter = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	int GetFront()
	{
		return front->data;
	}
	int GetRear()
	{
		return rear->data;
	}
	bool Found(int item)
	{
		bool f = false;
		Node* temp = front;
		while (temp != NULL)
		{
			if (temp->data == item)
				f = true;
			temp = temp->next;
		}
		return f;
	}
	void Clear()
	{
		//clear mean delete all elements
		while (!IsEmpty())
		{
			Dequeuq();
		}
	}
};

int main()
{
	queue s;
	s.Enqueue(6);
	s.Enqueue(7);
	s.Enqueue(5);
	s.Dequeuq();
	s.Display();
	cout << s.Found(7)<<endl;
	cout<<s.Count()<<endl;
	s.Clear();
	cout << s.Count();
}
