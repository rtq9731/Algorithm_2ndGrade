//20402 권성빈
#include <iostream>

using namespace std;

typedef struct linked {
	int data;
	struct linked* next;
}node;

node* head = NULL;
node* tail = NULL;

void init();
void insert(node* ptr);
void printList(node* ptr);
void modify(node* ptr);
void insertData(node* ptr);
void Delete(node* ptr);

int main() 
{
	int menu = 0;
	
	init();

	while (true)
	{
		cout << "1. 입력 2. 출력 3. 수정 4. 삽입 5. 삭제 6. 종료" << endl;
		cout << "input menu : ";
		cin >> menu;

		switch (menu)
		{
		case 1: insert(tail); break;
		case 2: printList(head); break;
		case 3: modify(head); break;
		case 4: insertData(head); break;
		case 5: Delete(head);
		case 6: return (0);
		default: cout << "select menu error" << endl; break; return (0);
		}
	}

	return(0);
}

void init()
{
	head = new node;
	head->data = 0;
	head->data = NULL;
	tail = head;
	return;
}

void insert(node* ptr)
{
	node* newnode = new node;
	int num = 0;
	cout << "input number";
	cin >> num;

	newnode->data = num;
	newnode->next = NULL;

	ptr->next = newnode;
	tail = newnode;

	return;
}

void printList(node* ptr)
{
	node* view = ptr->next;

	while (view != NULL)
	{
		cout << view->data;
		view = view->next;
	}
	cout << endl;
	return;
}

void modify(node* ptr)
{
	int index = 0;
	int num = 0;
	int i;

	cout << "input modify index : ";
	cin >> index;

	cout << "input modify data : ";
	cin >> num;

	for (i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}
	
	ptr->data = num;
	return;
}

void insertData(node* ptr)
{
	node* newnode = new node;

	int index = 0, num = 0, i;
	cout << "input InsertData index : ";
	cin >> index;
	cout << "input data : ";
	cin >> num;

	for (i = 0; i < index; i++)
		ptr = ptr->next;

	newnode->data = num;
	newnode->data = NULL;

	if (ptr->next == NULL)
	{
		ptr->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = ptr->next;
		ptr->next = newnode;
	}
}

void Delete(node* ptr)
{
	node* temp = 0;
	int i, index;

	if (head == tail)
	{
		cout << "자료가 없습니다." << endl;
		return;
	}

	cout << "input delete index : ";
	cin >> index;
	for (i = 0; i < index - 1; i++)
		ptr = ptr->next;

	temp = ptr->next;
	if (temp->next == NULL)
	{
		ptr->next = NULL;
		tail = ptr;
	}
	else
	{
		ptr->next = temp->next;
	}

	Delete(temp);
	return;
}
