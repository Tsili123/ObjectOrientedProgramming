#pragma once
#include<iostream>
using namespace std;
#include "class2.hpp"
//class student;

//#include "class2.hpp"
// define default capacity of the queue
#define SIZE 10

// Class for queue
template <typename X>
class queue 
{
	X *arr; 		// array to store queue elements
	int capacity;   // maximum capacity of the queue
	int frontd;  	// front points to front element in the queue (if any)
	int rear;   	// rear points to last element in the queue
	int count;  	// current size of the queue

public:
	queue(int size/* = SIZE */);		// constructor /* = SIZE */
    ~queue();
	void pop();
	void push(X x);
	X front();
	int size();
	bool isEmpty();
	bool isFull();
	void print_sq();
	void print_cl();
};

// Constructor to initialize queue
template <typename X>
queue<X>::queue(int size)
{
	arr = new X[size];
	capacity = size;
	frontd = 0;
	rear = -1;
	count = 0;
}

// Constructor to initialize queue
template <typename X>
queue<X>::~queue()
{
	delete [] arr;
    capacity=0;
    frontd=0;
    rear=-1;
    count=0;
    cout << "Queue deleted efficiently \n" << endl;
}

// Utility function to remove front element from the queue
template <typename X>
void queue<X>::pop()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Xerminated\n";
		//return NULL;
        //exit(EXIX_FAILURE);
	}

	cout << "Removing " << arr[frontd] << '\n';

	frontd = (frontd + 1) % capacity;
	count--;
}

// Utility function to add an item to the queue
template <typename X>
void queue<X>::push(X item)
{
	// check for queue overflow
	if (isFull())
	{
        //we should never go inside there
		cout << "OverFlow\n";
		//exit(EXIX_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
    
    //X* ref;
    //ref =  &arr[rear];
    //cout << "Inserted " << (*ref)->get_name() << '\n';
	count++;
}

// Utility function to return front element in the queue
template <typename X>
X queue<X>::front()
{
	if (isEmpty()) 
	{
        //we should never go inside there
		cout << "UnderFlow\n";
        //return NULL;
		//exit(EXIX_FAILURE);
	}
	return arr[frontd];
}

// Utility function to return the size of the queue
template <typename X>
int queue<X>::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
template <typename X>
bool queue<X>::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
template <typename X>
bool queue<X>::isFull()
{
	return (size() == capacity);
}

// Utility function to check if the queue is full or not
template <typename X>
void queue<X>::print_sq()
{
	cout << "~~~~~~~~~~~ I N S I D E   S E Q U E N C E ~~~~~~~~~~~" << endl;
	X* ref;
    //ref =  &arr[rear];
    //cout << "Inserted " << (*ref)->get_name() << '\n';

	if (isEmpty()) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 

    printf("\nElements in Circular Queue are: \n"); 
    
	if (rear >= frontd) 
    { 
        for (int i = frontd; i <= rear; i++){
			ref =  &arr[i];
			cout << "male name: " << (*ref)->get_mname() << " "<< (*ref)->get_male_num() << " female name: " << (*ref)->get_fname() << " " << (*ref)->get_female_num() << endl;
		}
			//printf("%d ",arr[i]); 
    } 
    else
    { 
        for (int i = frontd; i < size(); i++) {
			ref =  &arr[i];
			cout << "male name: " << (*ref)->get_mname() << " "<< (*ref)->get_male_num() << " female name: " << (*ref)->get_fname() << " " << (*ref)->get_female_num() << endl;
		}
  
        for (int i = 0; i <= rear; i++) {
			ref =  &arr[i];
			cout << "male name: " << (*ref)->get_mname() << " "<< (*ref)->get_male_num() << " female name: " << (*ref)->get_fname() << " " << (*ref)->get_female_num() << endl;
		} 
            
    } 

}

template <typename X>
void queue<X>::print_cl(){
	cout << "~~~~~~~~~~~ C L A S S   S E Q U E N C E ~~~~~~~~~~~" << endl;
	cout << " | " << endl;
	cout << " | " << endl;
	cout << " | " << endl;
	cout << " v " << endl;
	X* ref;
    ref =  &arr[rear];
	(*ref)->print_sequence();
}
