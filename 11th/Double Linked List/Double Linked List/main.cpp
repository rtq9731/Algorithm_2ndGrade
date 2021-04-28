#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
};

struct Node* CreateNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->nextNode = NULL;
	temp->prevNode = NULL;
	return temp;
}

void AppendNode(Node** head, Node* newNode)
{
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tail = *head;
		while (tail->nextNode != NULL)
		{
			tail = tail->nextNode;
		}
		tail->nextNode = newNode;
		newNode->prevNode = tail;
		newNode->nextNode = NULL;
	}
}

int CountNode(Node** head)
{
	int count = 0;
	struct Node* current = *head;
	while (current != NULL)
	{
		current = current->nextNode;
		count++;
	}
	return count;
}

struct Node* SearchNode(Node** head, int index)
{
	struct Node* current = *head;
	while (current->nextNode != NULL && (--index) >= 0)
		current = current->nextNode;
	return current;
}

void RemoveNode(Node** head, Node* remove)
{
	if (*head == NULL)
	{
		cout << "\nThere is no list data\n" << endl;
		*head = remove->nextNode;
		remove->prevNode = NULL;
		remove->nextNode = NULL;
		delete(remove);
	}
	else
	{
		Node* temp = *head; 
		while (temp->nextNode != remove)
			temp = temp->nextNode;

		temp->nextNode = remove->nextNode;
		remove->nextNode->prevNode = temp;
		remove->nextNode = NULL;
		remove->prevNode = NULL;
		delete(remove);
	}
}

void InsertNodeAfter(Node* current, Node* newNode)
{
	newNode->prevNode = current;
	newNode->nextNode = current->nextNode;
	current->nextNode->prevNode = newNode;
	current->nextNode = newNode;
}

void InsertNodeBefore(Node* current, Node* newNode)
{
	newNode->nextNode = current;
	newNode->prevNode = current->prevNode;
	current->prevNode->nextNode = newNode;
}

int main()
{
	Node* node = NULL;
	Node* head = NULL;
	Node* myNode = NULL;
	int i = 0;
	int count = 0;

	for (i = 0; i < 10; i++)
	{
		node = CreateNode(i);
		AppendNode(&head, node);
	}

	cout << "\nCounting Node..." << endl;
	cout << count << endl;
	cout << "\nChecking Node...\n" << endl;

	for (i = 0; i < count; i++)
	{
		myNode = SearchNode(&head, i);
		cout << "[" << i << "]" << myNode->data << endl;
	}

	cout << "\nRemoving Node...\n" << endl;
	myNode = SearchNode(&head, 3);
	RemoveNode(&head, myNode);
	count = CountNode(&head);

	for ( i = 0; i < count; i++)
	{
		myNode = SearchNode(&head, i);
		cout << "[" << i << "]" << myNode->data << endl;
	}

	cout << "\nInserting After Node..." << endl;
	node = CreateNode(3000);
	myNode = SearchNode(&head, 6);
	InsertNodeAfter(myNode, node);
	count = CountNode(&head);
	for (i = 0; i < count; i++)
	{
		myNode = SearchNode(&head, i);
		printf("[%d] %d\n", i, myNode->data);
	}

	cout << "\nInserting Before Node..." << endl;
	node = CreateNode(1000);
	myNode = SearchNode(&head, 2);
	InsertNodeBefore(myNode, node);
	count = CountNode(&head);
	for (i = 0; i < count; i++)
	{
		myNode = SearchNode(&head, i);
		cout << "[" << i << "]" << myNode->data << endl;
	}
	

	return(0);
}