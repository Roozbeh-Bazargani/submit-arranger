#include <iostream>
#include <fstream>



class Queue {

    private:
        int size, front, rear;
        int* items{new long double[size]};

    public:
        Queue(std::string filename){
            std::ifstream file_obj;
            file_obj.open(filename);
            for(int i{}; i < size; i++) {
                file_obj >> items[i];
            }

            file_obj.close();
            front = -1;
            rear = -1;
        }
        std::string filename{};

    bool isFull(){
        if(front == 0 && rear == size - 1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front == -1) return true;
        else return false;
    }

    void enQueue(long double element){
        if(isFull()){
            std::cout << "Queue is full" << std::endl;
        } else {
            if(front == -1) front = 0;
            rear++;
            items[rear] = element;
            std::cout << std::endl << "Inserted " << element << std::endl;
        }
    }

    int deQueue(){
        int element;
        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
            return(-1);
        } else {
            element = items[front];
            if(front >= rear){
                front = -1;
                rear = -1;
            } // Q has only one element, so we reset the queue after deleting it.
            else {
                front++;
            }
            return(element);
        }
    }

    void displayQueue()
    {
        // Function to display elements of Queue
        int i;
        if(isEmpty()) {
            std::cout << std::endl << "Empty Queue" << std::endl;
        }
        else
        {
            for(i=front; i<=rear; i++)
                std::cout << items[i] << "\t";
        }
//        std::cout << std::endl;
    }

};


int main()
{
    Queue q{"Queue.txt"};

    // Display elements present in Circular Queue
    q.displayQueue();

    // Inserting elements in Circular Queue
    q.enQueue(15.5);
    q.enQueue(-6);

    q.displayQueue();

    // Deleting elements from Circular Queue
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;

    q.displayQueue();


    return 0;
}
