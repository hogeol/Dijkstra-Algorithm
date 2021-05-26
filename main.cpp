#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Implement.hpp"

using namespace std;
#define GRAPH1 "graph1.txt"
#define GRAPH2 "graph2.txt"

int main(int argc, char** argv)
{
	int num_vertex = 0;
	FILE* file;
	file = fopen(GRAPH1, "rt");
	if (file == NULL)
	{
		cerr << "ERROR!! there are no " << GRAPH1 << " file\n";
		return -1;
	}
	//vertex 갯수 가져오기
	fscanf(file, "%d", &num_vertex);
	//인접행렬 가져오기
	for (int i = 0; i < num_vertex; i++)
		for (int j = 0; j < num_vertex; j++)
			fscanf(file, "%d", &graph[i][j]);

	//행렬 -> Adjacency List 변환
	Adjacency_list(num_vertex);

	//Dijkstra 알고리즘으로 최단거리 탐색
	Dijkstra(0, num_vertex, graph);
	return 0;
}
