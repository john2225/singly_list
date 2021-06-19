#include "singly_linked_list.h"

int main()
{
    myList::singly_list<int> test1;
    test1.push_front(10);
    test1.push_front(11);

    myList::singly_list<int> test2(test1);

    test1.pop_front();
    test1.pop_front();
    test1.pop_front();
    int a = 12;
    test1.insert(a, 0);

    test1.insert(a, 0);
    test1.insert(7, 1);
    test1.insert(8, 2);
    test1.insert(54, 3);
    test1.insert(42, 4);
    test1.remove_at(1);
    myList::singly_list<int> test3{ 5, 7, 8, 4, 34 };

    test1.reverse();
    test3.traverse(print);

}