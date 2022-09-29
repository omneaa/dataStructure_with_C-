#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

};

class LinedList {
public:
	Node* head;
	LinedList()
	{
		head = NULL;
	}
	bool IsEmpty()
	{
		/*if (head == NULL)
		return true;
		else
		return false;*/
	return (head == NULL);
	}
	void InsertFirst(int item)
	{
		Node* newNode=new Node();
		newNode->data = item;
		//IsEmpty() mean if IsEmpty==true
		if (IsEmpty())
		{
			
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;

		}
	}
	void display()
	{
		if (IsEmpty())
			cout << "it's empty\n";
		else
		{
			//print element called traverse
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data<<endl;
				temp = temp->next;

			}
		}
	}
	int counter()
	{
		int counter = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
			counter++;

		}
		return counter;
	}
	bool IsFound(int item)
	{
		bool found = false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == item)
			{
				found= true;
			
			}
			temp = temp->next;

		}
		return found;

	}
	void InsertBefore(int before, int item)
	{
		
		if (IsFound(before))
		{
			Node* newNode = new Node();
			newNode->data = item;
			Node* temp = head;
			while (temp != NULL && temp->next->data != before)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;

		}
		else
			cout << "the number isn't found\n";
	}
	void AppendItem(int item)
	{
		//Append mean add item at the end of the list
		if (IsEmpty())
		{
			InsertFirst(item);
		}
		else
		{
			Node* newNode = new Node();
			newNode->data = item;
			newNode->next = NULL;
			Node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			
			temp->next = newNode;
			//			newNode->next = NULL;

		}
	}
	void DeleteItem(int item)
	{
		
		if (IsEmpty())
		{
			cout << "it's empty\n";
		}
		else
		{
			if (head->data == item)
			{
				Node* delPtr = head;
				head = head->next;
				delete delPtr;
			}
			else
			{
				Node* prev = NULL;
				Node* delPtr = head;
				while (delPtr->data != item)
				{
					prev = delPtr;
					delPtr = delPtr->next;
				}
				prev->next = delPtr->next;
				delete delPtr;

			}
		}
}
};

	int main()
	{
		LinedList lis;
		lis.InsertFirst(3);
		lis.InsertFirst(4);
		cout<<lis.IsFound(5)<<endl;
		lis.InsertBefore(3, 9);
		lis.AppendItem(8);
		lis.DeleteItem(9);
		lis.display();
	}
	