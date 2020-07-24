# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <fstream>
# include <queue>
# include <string>


/*
this is Queue class ,which has 9 parts.
*/

class Queue

{

    public:
       std::queue<std::string> qlist;
       std::ifstream input;

       struct node
       {
           double info;
           struct node *next;
       }*last;
       /*
       construtor and deconstrurutor
       */
       Queue () {};
       Queue (std::string fn);
       ~Queue() {};

        /*
        this part creates our list (circular line) by reading
        numbers from Queue.txt.
        */
        void create_node(std::queue<std::string> qlist);

        /*
        this part adds numbers (by user) at the end of line.
        */
        void enQueue(double value);

        /*
        this part deletes first number in circle and then shows the
        value of deleted number.
        */
        double deQueue();

        /*
        this part searches a value among line.
        */
        void search_element(double value);

        /*
        this part prints all numbers .
        */
        void displayQueue();

        /*
        this part updates an element among line;
        */
        void update();

        /*
        this part sorts our line from smaller to larger.
        and it is optional.
        */
        void sort();

        /*
        this parts set max size of Queue which is the first
        number in Queue.txt.
        */
        int get_maxsize(std::queue<std::string> qlist);

        /*
        this part shows moment size of line.
        */
        int get_momentsize();

};
