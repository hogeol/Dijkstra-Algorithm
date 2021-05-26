//우선순위 Queue
#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#define MAX 999

typedef struct _priority_queue {
	int Pheap[MAX] = {};
	int Psize;

	_priority_queue() : Psize(0) {}
	void Swap(int& a, int& b);
	char Push(int value);
	short Pop();
	bool Isempty();

}_priority_queue;

#endif __PRIORITYQUEUE__