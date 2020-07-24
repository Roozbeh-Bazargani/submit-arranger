# include <iostream>
# include "Queue.h"
# include <cstdio>
# include <cstdlib>
# include <fstream>
# include <queue>
# include <string>


int main()
{
    std::queue<std::string> qlist;
    int choice{};
    double element{};
    bool creation{};

    Queue q;

    std::cout<<std::endl<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"-----------9523053----------"<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl;

    /*
    queue will be created by entering 1.
    */
    std::cout<<"if you want create queue please write 1 :"<<std::endl;
    std::cin>>creation;
    if (creation==1)
      q.create_node(qlist);
    else
      return 0;

    while (1)
    {
        std::cout<<std::endl<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<"-----------9523053----------"<<std::endl;
        std::cout<<"----------------------------"<<std::endl;
        std::cout<<std::endl<<std::endl;

        /*
        this is the menu of options
        */
        std::cout<<"1.Add number"<<std::endl;
        std::cout<<"2.Delete"<<std::endl;
        std::cout<<"3.Search"<<std::endl;
        std::cout<<"4.Display"<<std::endl;
        std::cout<<"5.Update"<<std::endl;
        std::cout<<"6.Sort"<<std::endl;
        std::cout<<"7.Quit"<<std::endl;
        std::cout<<"Enter your choice : ";

        std::cin>>choice;

        switch(choice)
        {

        case 1:

            std::cout<<std::endl<<std::endl;
            /*
            if the line is empty , using CASE 1 is impossible
            */
            if (&Queue::last == NULL)
            {
              std::cout<<"Your moment size=0"<<std::endl\
              <<"Your Max size="<<q.get_maxsize(qlist)<<std::endl\
              <<"Enter the element: ";
              std::cin>>element;
              q.enQueue(element);
              break;
            }
            if(q.get_momentsize() < q.get_maxsize(qlist))
            {
              std::cout<<"Your moment size="<<q.get_momentsize()<<std::endl\
              <<"Your Max size="<<q.get_maxsize(qlist)<<std::endl\
              <<"Enter the element: ";
              std::cin>>element;
              q.enQueue(element);
              std::cout<<std::endl;
            }
            else
            {
              std::cout<<"No space"<<std::endl;
            }
            break;

        case 2:

            std::cout<<std::endl<<std::endl;

            /*
            if the line is empty , using CASE 2 is impossible
            */
            if (&Queue::last == NULL)
            {
                std::cout<<"List is empty, nothing to delete"<<std::endl;
                break;
            }

            std::cout<<"Deleted value="<<q.deQueue()<<std::endl;
            break;

        case 3:

            std::cout<<std::endl<<std::endl;
            if (&Queue::last == NULL)
            {
                std::cout<<"List Empty!! Can't search"<<std::endl;
                break;
            }

            std::cout<<"Enter the element to be searched: ";
            std::cin>>element;
            q.search_element(element);
            std::cout<<std::endl;
            break;

        case 4:

            std::cout<<std::endl<<std::endl;
            q.displayQueue();
            break;

        case 5:

            std::cout<<std::endl<<std::endl;
            q.update();
            break;

        case 6:

            std::cout<<std::endl<<std::endl;
            q.sort();
            break;

        case 7:

            return 0;
            break;

        default:

            std::cout<<"Wrong choice"<<std::endl;

        }

    }
    return 0;
}
