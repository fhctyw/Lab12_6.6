#include <iostream>
using namespace std;

struct Elem
{
	Elem* link;
	int info;
};

void enqueue(Elem*& first, Elem*& last, int info)
{
	Elem* tmp = new Elem;
	tmp->info = info;
	tmp->link = nullptr;
	if (last != nullptr)
		last->link = tmp;
	last = tmp;
	if (first == nullptr)
		first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	int info = first->info;
	delete first;
	first = tmp;
	if (first == nullptr)
		last = nullptr;
	return info;
}

int count(const Elem* L)
{
	if (L != nullptr)
		return 1 + count(L->link);
	else
		return 0;
}

void print(const Elem* first)
{
	if (first == nullptr)
		cout << endl;
	else
	{
		cout << first->info << " ";
		print(first->link);
	}
}

bool isEmpty(const Elem* first)
{
	return count(first);
}

void clear(Elem*& first, Elem*& last)
{
	int k = count(first);
	for (size_t i = 0; i < k; i++)
		dequeue(first, last);
}

int getElem(Elem* first, int index)
{
	int i = 0;
	while (first != nullptr)
	{
		if (i == index) return first->info;
		i++;
		first = first->link;
	}
	return -1;
}

int search(Elem* first, int info)
{
	int i = 0;
	while (first != nullptr)
	{
		if (first->info == info) return i;
		i++;
		first = first->link;
	}
	return -1;
}

int main()
{
	Elem* first = nullptr, * last = nullptr;

	enqueue(first, last, 10);
	enqueue(first, last, -11);
	enqueue(first, last, 2);
	enqueue(first, last, 4);

	print(first);
	
	cout << getElem(first, 2) << endl;
	cout << search(first, 2) << endl;
	return 0;
}