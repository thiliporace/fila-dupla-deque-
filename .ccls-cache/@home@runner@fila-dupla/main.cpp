#include <iostream>
#include <sstream>
#include "Deque.h"

void PrintDequeInfo(const Deque& deque)
{
    if (IsEmpty(deque))
        std::cout << "Front(): Empty deque. - Back(): Empty deque.";
    else
        std::cout << "Front(): " << Front(deque) << " - Back(): " << Back(deque);

    std::cout << " (" << Count(deque) << '/' << Size(deque) << ")\n";
    std::cout << deque << '\n';
}

int main()
{
    Deque deque;
    Setup(deque);
    std::cout << ">>> Setup()\n";
    PrintDequeInfo(deque);

    std::cout << "--------------------\n";
    std::string str = "Deque_Hello_World!";
    for (int i = 0; i < str.length(); i += 2)
    {
        std::cout << "\n>>> InsertFront(): " << str[i] << '\n';
        if (!InsertFront(deque, str[i]))
            std::cout << "Deque is full! Cannot insert " << str[i] << '\n';
        PrintDequeInfo(deque);

        std::cout << "\n>>> InsertBack():  " << str[i + 1] << '\n';
        if (!InsertBack(deque, str[i + 1]))
            std::cout << "Deque is full! Cannot insert " << str[i + 1] << '\n';
        PrintDequeInfo(deque);
    }

    std::cout << "\n--------------------\n";
    char value;
    while (!IsEmpty(deque))
    {
        value = RemoveFront(deque);
        std::cout << "\n>>> RemoveFront(): " << value << '\n';
        PrintDequeInfo(deque);

        value = RemoveBack(deque);
        std::cout << "\n>>> RemoveBack():  " << value << '\n';
        PrintDequeInfo(deque);
    }

    std::cout << "--------------------\n";
    Clear(deque);
    std::cout << "\n>>> Clear()\n";
    PrintDequeInfo(deque);
}