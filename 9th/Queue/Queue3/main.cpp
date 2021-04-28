//20402 권성빈 
#include <iostream>

using namespace std;

#define NEXT(index,QSIZE) ((index + 1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
}Queue;

void InitQueue(Queue* queue, int qsize);
int IsFull(Queue* queue);
int isEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);

void main()
{
	int i, size;
	int select = -1;

	Queue queue;

	cout << "큐의 크기를 입력하세요.";
	cin >> size;

	InitQueue(&queue, size);

	while(true)
	{
		cout << endl << "1. Enqueue	2. Dequeue 3. Quit" << endl;
		cout << ">> ";
		cin >> select;
		
		switch (select)
		{
		case 1:
			int value;
			cout << "input data: ";
			cin >> value;
			Enqueue(&queue, value);
			break;
		case 2:
			Dequeue(&queue);
			break;
		case 3:
			exit(0);
		default:
			cout << endl << " ERROR! Not Defined Input! " << endl;
			exit(0);
			break;
		}
	}

}

void InitQueue(Queue* queue, int qsize)
{
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = 0;
	queue->count = 0;
}

int IsFull(Queue* queue) { return queue->count == queue->qsize; }
int isEmpty(Queue* queue) { return queue->count == 0; }

void Enqueue(Queue* queue, int data)
{
	if (IsFull(queue)) {
		cout << "Queue Is Full";
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->front, queue->qsize);
	queue->count++;
}

int Dequeue(Queue* queue)
{
	int re = 0;
	if (isEmpty(queue))
	{
		cout << "Queue Is Empty";
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	cout << "Dequeue : " << re;
	queue->count--;
	return re;
}