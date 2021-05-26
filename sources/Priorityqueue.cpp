#include "PriorityQueue.hpp"

void _priority_queue::Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

char _priority_queue::Push(int value)
{
	if (Psize + 1 > MAX)
		return 0;
	Pheap[Psize] = value;

	int current = Psize;
	int parent = (Psize - 1) / 2;

	while (current > 0 && Pheap[current] > Pheap[parent]) {
		Swap(Pheap[current], Pheap[parent]);
		current = parent;
		parent = (parent - 1) / 2;
	}

	Psize++;

	return 1;
}

short _priority_queue::Pop() {
	if (Psize <= 0)
		return -1;

	int head = Pheap[0];
	int current = 0;
	int left_child = current * 2 + 1;
	int right_child = current * 2 + 2;
	int max_node = current;

	while (left_child < Psize) {
		if (Pheap[max_node] < Pheap[left_child])
			max_node = left_child;
		if (Pheap[max_node] < Pheap[right_child] && right_child < Psize)
			max_node = right_child;
		if (max_node == current)
			break;
		else {
			Swap(Pheap[current], Pheap[max_node]);
			current = max_node;
			left_child = current * 2 + 1;
			right_child = current * 2 + 2;
		}
	}
	return head;
}

bool _priority_queue::Isempty() {
	if (Psize == 0)
		return 1;
	else
		return 0;
}
