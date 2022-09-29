#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <ostream>

const int DEQUE_CAPACITY = 16;

struct Deque
{
	int front;
	int rear;
	int count;
	char values[DEQUE_CAPACITY];
};

void Setup(Deque& deque); // Observação: no lugar de Deque Create();
bool InsertFront(Deque& deque, char value);
bool InsertBack(Deque& deque, char value);
char RemoveFront(Deque& deque);
char RemoveBack(Deque& deque);
char Front(const Deque& deque);
char Back(const Deque& deque);
int Size(const Deque& deque);
int Count(const Deque& deque);
bool IsEmpty(const Deque& deque);
bool IsFull(const Deque& deque);
void Clear(Deque& deque);
std::ostream& operator<<(std::ostream& os, const Deque& deque);

#endif