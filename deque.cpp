#include "Deque.h"

void Setup(Deque& deque)
{
	deque.front = deque.rear = deque.count = 0;
	for (int i = 0; i < DEQUE_CAPACITY; ++i)
		deque.values[i] = '\0';
}

bool InsertFront(Deque& deque, char value)
{
	if (IsFull(deque))
		return false;

	// deque.front contém o índice do primeiro elemento da fila (frente da fila).
	// Como estamos inserindo um novo elemento *antes* do atual primeiro elemento da fila,
	// devemos usar o índice indicado por deque.front e subtrair 1 ("um antes do primeiro").
	deque.front = (deque.front - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;

	// A linha acima equivale às três linhas de código abaixo (lembre-se: vetor circular).
	//--deque.front;
	//if (deque.front < 0)
	//	deque.front = DEQUE_CAPACITY - 1;

	deque.values[deque.front] = value;
	++deque.count;

	return true;
}

// A inserção no final da fila deque é semelhante à função Enqueue() de uma queue.
bool InsertBack(Deque& deque, char value)
{
	if (IsFull(deque))
		return false;

	deque.values[deque.rear] = value;
	deque.rear = (deque.rear + 1) % DEQUE_CAPACITY;
	++deque.count;

	return true;
}

// A remoção do primeiro da fila deque é semelhante à função Dequeue() de uma queue.
char RemoveFront(Deque& deque)
{
	if (IsEmpty(deque))
		return '\0';

	char front = deque.values[deque.front];
	deque.values[deque.front] = '\0';
	deque.front = (deque.front + 1) % DEQUE_CAPACITY;
	--deque.count;

	return front;
}

char RemoveBack(Deque& deque)
{
	if (IsEmpty(deque))
		return '\0';

	// deque.rear contém o índice que deve ser usado para inserir um novo
	// elemento no final da fila. Portanto, devemos obter o índice anterior,
	// que é o último elemento armazenado na fila.
	deque.rear = (deque.rear - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;

	// Observe que acessamos o índice correto do último elemento da fila
	// e não precisamos recalcular esse índice, já que o último elemento
	// está sendo removido (e o índice correto para um novo elemento a
	// ser inserido no fim da fila é o mesmo).
	char rear = deque.values[deque.rear];
	deque.values[deque.rear] = '\0';
	--deque.count;

	return rear;
}

char Front(const Deque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[deque.front];
}

char Back(const Deque& deque)
{
	if (IsEmpty(deque))
		return '\0';

	// deque.rear contém o índice que deve ser usado para inserir um novo
	// elemento no final da fila. Portanto, devemos obter o índice anterior,
	// que é o último elemento armazenado na fila.
	int last = (deque.rear - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;

	return deque.values[last];
}

int Size(const Deque& deque)
{
	//return sizeof(deque.values) / sizeof(deque.values[0]);
	return DEQUE_CAPACITY;
}

int Count(const Deque& deque)
{
	return deque.count;
}

bool IsEmpty(const Deque& deque)
{
	return deque.count == 0;
}

bool IsFull(const Deque& deque)
{
	return deque.count == DEQUE_CAPACITY;
}

void Clear(Deque& deque)
{
	while (!IsEmpty(deque))
	{
		RemoveFront(deque);
	}
}

std::ostream& operator<<(std::ostream& os, const Deque& deque)
{
	if (!IsEmpty(deque))
	{
		int first = deque.front;
		int last = first + deque.count;

		bool isRearBeforeFront = deque.rear <= deque.front;
		if (isRearBeforeFront)
			last = DEQUE_CAPACITY;

		for (int i = first; i < last; ++i)
			os << deque.values[i] << ' ';

		if (isRearBeforeFront)
		{
			last = deque.rear;
			for (int i = 0; i < last; ++i)
				os << deque.values[i] << ' ';
		}
	}

	return os;
}