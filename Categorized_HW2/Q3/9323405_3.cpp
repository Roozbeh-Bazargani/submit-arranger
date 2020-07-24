#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 
struct Queue
{
   
    int read, write;
    int size;
    int *arr;
 
    Queue(int s)
    {
       write = read = -1;
       size = s;
       arr = new int[s];
    }
 
    void enQueue(int value);
    int deQueue();
    void displayQueue();};
 
 
void Queue::enQueue(int value)
{
    if ((write == 0 && read == size-1) ||
            (read == write -1))
    {
      cout << "\Queue is full";
        return;
    }
 
    else if (write == -1)
    {
        write = read = 0;
        arr[read] = value;
    }
 
    else if (read == size-1 && write != 0)
    {
        read = 0;
        arr[read] = value;
    }
 
    else
    {
        read++;
        arr[read] = value;
    }
}

int Queue::deQueue()
{
    if (write == -1)
    {
      cout << "\Queue is empty";
        return INT_MIN;
    }
 
    int data = arr[write];
    arr[write] = -1;
    if (write == read)
    {
        write = -1;
        read = -1;
    }
    else if (write == size-1)
        write = 0;
    else
        write++;
 
    return data;
}
 


void Queue::displayQueue()
{
    if (write == -1)
    {
      cout << "\empty";
        return;
	   }
    cout << "\elements  are: ";
    if (read >= write)
    {
        for (int i = write; i <= read; i++)
          cout << arr[i];
    }
    else
    {
        for (int i = write; i < size; i++)
	cout <<  arr[i];
 
        for (int i = 0; i <= read; i++)
	cout << arr[i];
    }
}

