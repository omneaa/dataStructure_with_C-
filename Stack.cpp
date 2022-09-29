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
/*stack operations
pop:delete top element in the stack
push:add element
peak:return the top element
search,count,isempty
*/
class Stack {
public:
	Node* top;
	Stack()
	{
		top = NULL;
	}
	bool IsEmpty()
	{
		return(top == NULL);
	}

	void Push(int item)
	{
		if (IsEmpty())
		{
			Node* newNode = new Node;
			newNode->data = item;
			newNode->next = NULL;
			top = newNode;
		}
		else
		{
			Node* newNode = new Node;
			newNode->data = item;
			newNode->next = top;
			top = newNode;
		}
	}
	void pop()
	{
		
		Node* ptr=top;
		top = top->next;
		delete ptr;
	}
	void Display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << endl;;
			temp = temp->next;
		}
	}
	int Count()
	{
		int counter = 0;
		Node* temp = top;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	int Peak()
	{
		return top->data;
	}
	bool Found(int item)
	{
		bool f = false;
		Node *temp = top;
		while (temp != NULL)
		{
			if (temp->data == item)
				f= true;
			temp = temp->next;
		}
		return f;
		

	}
};

	int main()
	{
		Stack s;
		s.Push(6);
		s.Push(7);
		s.Push(5);
		s.Display();
		cout << s.Found(7);
	}
	