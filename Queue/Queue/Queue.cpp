// Queue.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class QueueArray {
public:
	//void Zero(int x, string* queue);  //��l�ư}�C
	void Zero();
	int capacity; //�s�j�p�A�]���ݭn�ѥD�{���פJ�A�ҥH�u��bpublic�ŧi
	bool IsFull();//�T�{�O�_��
	//void Push(string x, string* queue); //�ΨӦs�J�}�C
	void Push(string x);
	//void Pop(string* queue); //�Ψӥ�줸��
	void Pop();
	bool IsEmpty(); //�T�{�O�_�ť�
	//string  getElement(int x, string* queue); //�]��queue[]�Oprivate�����ҥH������class���禡�Өϥ�private
	string getElement(int x);
	//void print(string* queue);  //��X�}�C
	void print();

private:
	int  front = 0, rear = 0; //���έק�
	string* queue;
							  //string queue[] ;
};

void QueueArray::Zero( ) {
	queue = new string[capacity];
	for (int i = 0; i < capacity; i++)
		queue[i] = "";
}
bool QueueArray::IsFull() {

	return (rear + 1 == capacity);
}
bool QueueArray::IsEmpty() {

	return (front == rear);
}
void QueueArray::Push(string x) {

	if (IsFull()) {
		cout << "Queue is Full!!!" << endl;
		return;
	}
	queue[++rear] = x;
}
void QueueArray::Pop( ) {

	if (IsEmpty()) {
		cout << "Queue is empty!!!" << endl;;
		return;
	}
	cout << "Deleted element is : " << queue[++front] << endl;
	queue[front] = "";
}
string QueueArray::getElement(int x ) {
	return queue[x];
}
void QueueArray::print( ) {
	for (int i = 0; i < capacity; i++) {
		if (queue[i] == "")
			cout << "[]" << " ";
		else
			cout << "[" << queue[i] << "]" << " ";
	}
	cout << endl;
	cout << "Front = " << front << "," << "Rear = " << rear << endl;
}
class QueueArray_1 {    //����array��circular queue ���j�����t���h�A�D�n�O�P�_�������P
public:
	void Zero();
	int capacity;
	bool IsFull();
	void Push(string x);
	void Pop();
	bool IsEmpty();
	string getElement(int x);
	void print();
private:
	int  front = 0, rear = 0;
	string* queue;

};

void QueueArray_1::Zero() {
	queue = new string[capacity];
	for (int i = 0; i < capacity; i++)
		queue[i] = "";
}
bool QueueArray_1::IsFull() {

	return ((rear + 1) % capacity == front);
}
bool QueueArray_1::IsEmpty() {

	return (front == rear);
}
void QueueArray_1::Push(string x ) {

	if (IsFull()) {
		cout << "Queue is Full!!!" << endl;
		return;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
}
void QueueArray_1::Pop( ) {

	if (IsEmpty()) {
		cout << "Queue is empty!!!" << endl;;
		return;
	}

	front = (front + 1) % capacity;
	cout << "Deleted element is : " << queue[front] << endl;
	queue[front] = "";
}
string QueueArray_1::getElement(int x ) {
	return queue[x];
}
void QueueArray_1::print( ) {
	for (int i = 0; i < capacity; i++) {
		cout << "[" << queue[i] << "]" << " ";
	}
	cout << endl;
	cout << "Front = " << front << "," << "Rear = " << rear << endl;
}
struct Node {      //��node
	int data;
	Node *next;
};
class QueueList {  //���Xlinklist

public:
	QueueList() {
		front = rear = NULL;    //�@�}�l�S����ơA�����]��NULL//��s
		size = 0;
	};
	void generate();
	void print();
	int capacity = 0;
	void push(int x);
	void pop();
	int size;
private:
	int fr = 0;
	int re = 0;
	Node *front;
	Node *rear;
	Node *dot;
	Node *head;

};
void QueueList::generate() {   //���ͫ��w�n�D���j�p
	front = new Node;
	front->data = -1;
	rear = front;
	head = front;
	dot = front;
	for (int i = 0; i < (capacity - 1); i++) {
		Node *newNode = new Node;
		newNode->data = -1;
		newNode->next = front;
		dot->next = newNode;
		dot = newNode;
	}

}
void QueueList::print() {
	Node *current = head;             // ��pointer *current�blist������
									  /*int i = 0;*/
									  //while (i<capacity) {                 // Traversal
									  //	cout << "�a�}" << current << "->";
									  //		cout<<current->data<<"  ";
									  //	current = current->next;
									  //	i++;
									  //}
	for (int i = 0; i < capacity; i++) {
		if (current->data == -1)
			cout << "[]" << " ";
		else
			cout << "[" << current->data << "]" << " ";
		current = current->next;
	}
	cout << endl;
	cout << "Front = " << fr << "," << "Rear = " << re << endl;
}
void QueueList::push(int x) {     //data�ȿ�J
	rear = rear->next;
	//cout << rear << "  "<<endl;
	rear->data = x;
	size++;
	re = (re + 1) % capacity;
	//cout << "rear��" << rear << endl;
	//cout << "front��" << front << endl;
}
void QueueList::pop() {
	front = front->next;
	cout << "Deleted element is : " << front->data << endl;
	front->data = -1;
	size--;
	fr = (fr + 1) % capacity;
	//cout << "rear��" << rear << endl;
	//cout << "front��" << front << endl;
}




int main()
{
	cout << "SELECT YOUR CHOICE" << endl; //�D�禡�ΨӶi���J��X
	cout << endl;
	cout << "1.LINEAR QUEUE" << endl;   //�T�ӿ�ܨѧP�O
	cout << "2.CIRCULAR QUEUE" << endl;
	cout << "3.LINKED LIST" << endl;
	int haha = 0;
	cin >> haha;
	cout << endl;
	switch (haha) {
	case 1:                       //�`�N���a��Oswitch�᭱�n���@�y���z�� ���M�]���X��
	{
		cout << "LINEAR QUEUE" << endl;
		QueueArray q;
		cout << "Enter the size of the Queue : ";
		cin >> q.capacity;
		q.Zero();                     //��l�ư}�C

		do
		{
			int choice = 0;
			cout << "1.INSERTION" << endl << "2.DELETION" << endl << "3.EXIT" << endl;
			cout << "Enter your choice : "; cin >> choice;
			switch (choice) {
			case 1:
			{
				cout << "Enter an element : "; //���char�i�H�ΨӶפJ�r���򳡤����
				string sample;
				cin >> sample;
				q.Push(sample);
				q.print();
				break;
			}
			case 2:
			{
				q.Pop();
				q.print();
				break; }
			case 3:
				exit(1);
			}
			cout << endl;
		} while (1);
	}
	case 2:
	{
		cout << "CIRCULAR QUEUE" << endl;
		QueueArray_1 q;
		cout << "Enter the size of the Queue : ";
		cin >> q.capacity;
		q.Zero( );
		do
		{
			int choice = 0;
			cout << "1.INSERTION" << endl << "2.DELETION" << endl << "3.EXIT" << endl;
			cout << "Enter your choice : "; cin >> choice;
			switch (choice) {
			case 1:
			{
				cout << "Enter an element : ";
				string sample;
				cin >> sample;
				q.Push(sample );
				q.print( );
				break;
			}
			case 2:
			{
				q.Pop( );
				q.print( );
				break; }
			case 3:
				exit(0);
			}
			cout << endl;
		} while (1);
	}
	case 3:
	{
		QueueList q;
		cout << " Enter the Size : ";
		cin >> q.capacity;
		q.generate();
		//q.print();
		while (1) {
			int choice = 0;
			cout << "1.INSERTION" << endl << "2.DELETION" << endl << "3.EXIT" << endl;
			cout << "Enter your choice : "; cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Enter an element : ";
				int sample = 0;
				cin >> sample;
				if (q.size == q.capacity - 1) {
					cout << "Queue is Full!" << endl;
					q.print();
					continue;
				}
				q.push(sample);
				q.print();
				break;
			}
			case 2:
			{
				if (q.size == 0) {
					cout << "Queue is Empty!" << endl;
					q.print();
					continue;
				}
				q.pop();
				q.print();
				break;
			}
			case 3:
				exit(1);
			}

		}
	}

	}
	return 0;
}


