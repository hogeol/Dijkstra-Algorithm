//인접행렬 리스트
#ifndef __ADJACENCYLIST__
#define __ADJACENCYLIST__

typedef struct _transform* node;
typedef struct _transform
{
	node Tlink;
	int Tvertex;
	int Tweight;

}_transform;

#endif __ADJACENCYLIST__