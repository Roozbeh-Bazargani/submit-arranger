# include "Queue.h"

struct node
{
    double info;
    struct node *next;
}*last;

/*
this part creates our list (circular line) by reading
numbers from Queue.txt.
*/
void Queue::create_node(std::queue <std::string> qlist)
{
    struct node *temp, *s;
    temp = new(struct node);
    int value{};
    double val{};
    char c;
    std::ifstream input;
    input.open("Queue.txt");
    input>>value;
    input>>val;
    input>>c;
    temp->info = val;

    /*
    this IF is for the first number of Queue.txt
    */
    if (last == NULL)
    {
          last = temp;
          temp->next = last;
     }
     else
     {
          temp->next = last->next;
          last->next = temp;
          last = temp;
     }

     /*
     this FOR is for the other values of Queue.txt
     */
     for (int i{1} ; i<value ; i++)
     {
          if( input.eof() )
          {
            break;
          }
           input>>val;
           input>>c;
           s = last->next;
           for (int j{1} ; j < i ; j++)
           {
              s = s->next;
           }
           temp = new(struct node);
           temp->next = s->next;
           temp->info = val;
           s->next = temp;
           last = temp;
     }

     /*
     this IF is for preventing from creating queue larger than the max size.
     */
     if (!input.eof())
     {
          std::cout<<std::endl<<"No more space. please check your file"<<std::endl;
     }
     input.close();
}

/*
this part adds numbers (by user) at the end of line.
*/
void Queue::enQueue(double value)
{
    struct node *temp ;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

}


/*
this part deletes first number in circle and then shows the
value of deleted number.
*/
double Queue::deQueue(void)
{

    struct node *temp, *s;
    s = last->next;
    double deletion{s->info};

    /*
    if List has only one element
    */
    if (last->next == last )
    {
        temp = last;
        last = NULL;
        free(temp);
        return deletion;
     }

      temp = s;
      last->next = s->next;
      free(temp);
      return deletion;
}


/*
this part searches a value among line.
*/
void Queue::search_element(double value)
{

    struct node *s;
    int counter{};
    s = last->next;

    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            std::cout<<"Element "<<value<<" found at position "\
            <<counter<<std::endl;

            return;
        }
        s = s->next;
    }

    if (s->info == value)
    {
        counter++;
        std::cout<<"Element "<<value<<" found at position "<<counter<<std::endl;
        return;
    }

    std::cout<<"Element "<<value<<" not found in the list"<<std::endl;
}


/*
this part prints all numbers .
*/
void Queue::displayQueue()
{
    struct node *s;
    if (last == NULL)
    {
        std::cout<<"List is empty, nothing to display"<<std::endl;
        return;
    }

    s = last->next;
    std::cout<<"Queue: "<<std::endl;
    while (s != last)
    {
        std::cout<<s->info<<" -> ";
        s = s->next;
    }

    std::cout<<s->info<<std::endl;
}


/*
this part updates an element among line;
*/
void Queue::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        std::cout<<"List is empty, nothing to update"<<std::endl;
        return;
    }

    std::cout<<"Enter the node position to be updated: ";
    std::cin>>pos;
    std::cout<<"Enter the new value: ";
    std::cin>>value;
    struct node *s;
    s = last->next;

    for (i = 0 ; i < pos - 1 ; i++)
    {
        if (s == last)
        {
            std::cout<<"There are less than "<<pos<<" elements."<<std::endl;
            return;
        }
        s = s->next;
    }

    s->info = value;
    std::cout<<"Node Updated"<<std::endl;
}


/*
this part sorts our line from smaller to larger.
and it is optional.
*/
void Queue::sort()
{

    struct node *s, *ptr;
    double temp;
    if (last == NULL)
    {
        std::cout<<"List is empty, nothing to sort"<<std::endl;
        return;
    }
    s = last->next;

    while (s != last)
    {
        ptr = s->next;
        while (ptr != last->next)
        {
            if (ptr != last->next)
            {
                if (s->info > ptr->info)
                {
                    temp = s->info;
                    s->info = ptr->info;
                    ptr->info = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;
        }
        s = s->next;
    }
}

/*
this parts set max size of Queue which is the first
number in Queue.txt.
*/
int Queue::get_maxsize(std::queue <std::string> qlist)
{
    std::ifstream file;
    file.open("Queue.txt");
    int value{};
    file>>value;
    file.close();
    return value;
}

/*
this part shows moment size of line.
*/
int Queue::get_momentsize(void)
{
    struct node *s;
    s = last->next;
    int size{};
    while (s != last)
    {
        s = s->next;
        size++ ;
    }
    return ++size;
}
