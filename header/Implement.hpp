#include<iostream>
#ifndef __IMPLEMENT__
#define __IMPLEMENT__
#include "PriorityQueue.hpp"
#include "AdjacencyList.hpp"

short graph[256][256]; //인접 행렬
short pi[256]; //경로 저장
short distance[256]; //다음 노드까지 경로 길이저장
bool find[256]; //노드를 찾으면 찾았다고 저장
node adj_list[64]; //adjacencylist 노드

int Choose(int num); //가중치 선택
void Relax(int u, int v, short weight[][256]);
void Adjacency_list(int num_vertex); //행렬, LIST 변환
void Dijkstra(int start, int num_vertex, short weight[][50]);

int Choose(int num)
{
	short min_distance = MAX;
	short min_vertex_index = -1;

	for (short i = 0; i < num; i++)
	{
		if (::find[i] != true)
		{
			if (::distance[i] < min_distance) //가중치가 최소인 것으로 이동
			{
				min_distance = ::distance[i];
				min_vertex_index = i;
			}
		}
	}
	return min_vertex_index;
}

void Relax(int u, int v, short weight[][256])
{
	//현재 distance보다 작으면
	if (::distance[v] > ::distance[u] + weight[u][v])
	{
		//현재 distance를 더함
		::distance[v] = ::distance[u] + weight[u][v];
		pi[v] = u;
	}
}

void Adjacency_list(int num_vertex)
{
	node shift = (node)malloc(sizeof(_transform)); //이동
	node compare = (node)malloc(sizeof(_transform)); //비교
	node tmp = (node)malloc(sizeof(_transform));

	for (int i = 0; i < num_vertex; i++)
	{
		compare = adj_list[i];
		for (int j = 0; j < num_vertex; j++)
		{
			if (graph[i][j] != 0)
			{
				tmp->Tvertex = j;
				tmp->Tweight = graph[i][j]; //weight 대입
				if (adj_list[i] == compare) //다른 경로가 없을 때
				{
					shift = tmp;
					adj_list[i] = tmp;
				}
				else //다른 경로가 있을 때 경로를 연결
				{
					shift->Tlink = tmp;
					shift = tmp;
				}
			}
		}
		tmp->Tlink = NULL;
	}
}

void Dijkstra(int start, int num_vertex, short weight[][256])
{
	int print[128] = {}, pi_num = 1;
	//그래프 초기화
	for (int i = 0; i < num_vertex; i++)
	{
		for (int j = 0; j < num_vertex; j++)
		{
			if (graph[i][j] == 0)
				if (i != j)
					graph[i][j] = MAX;
		}
	}
	for (int i = 0; i < num_vertex; i++)
	{
		::distance[i] = weight[start][i];
		::find[i] = 0;
		if ((::distance[i] >= 0) && ::distance[i] < MAX)
			pi[i] = start;
		else
			pi[i] = -1;
	}
	//vertext 초기화
	::distance[start] = 0;
	::find[start] = 1;

	for (int i = 0; i < num_vertex; i++)
	{
		int u = Choose(num_vertex);
		::find[u] = 1;

		//최단 경로 거리 계산
		for (int j = 0; j < num_vertex; j++)
		{
			if (::find[j] != 1)
				Relax(u, j, graph);
		}

		//경로와 가중치 출력
		if (i > 0)
		{
			int k = i;
			while (k != 0)
			{
				print[pi_num] = pi[k] + 1; //경로 저장
				k = pi[k];
				pi_num++;
			}
			//경로 출력
			std::cout << "PATH TO " << i + 1 << " >> ";
			for (int j = pi_num - 1; j >= 1; j--) 
				std::cout << print[j] << " -> ";

			std::cout << i + 1 << " : " << ::distance[i] << std::endl;
			pi_num = 1;
			print[100] = {};
		}
	}
}

#endif __IMPLEMENT__
