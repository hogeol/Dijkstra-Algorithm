#include<iostream>
#ifndef __IMPLEMENT__
#define __IMPLEMENT__
#include "PriorityQueue.hpp"
#include "AdjacencyList.hpp"

short graph[256][256]; //���� ���
short pi[256]; //��� ����
short distance[256]; //���� ������ ��� ��������
bool find[256]; //��带 ã���� ã�Ҵٰ� ����
node adj_list[64]; //adjacencylist ���

int Choose(int num); //����ġ ����
void Relax(int u, int v, short weight[][256]);
void Adjacency_list(int num_vertex); //���, LIST ��ȯ
void Dijkstra(int start, int num_vertex, short weight[][50]);

int Choose(int num)
{
	short min_distance = MAX;
	short min_vertex_index = -1;

	for (short i = 0; i < num; i++)
	{
		if (::find[i] != true)
		{
			if (::distance[i] < min_distance) //����ġ�� �ּ��� ������ �̵�
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
	//���� distance���� ������
	if (::distance[v] > ::distance[u] + weight[u][v])
	{
		//���� distance�� ����
		::distance[v] = ::distance[u] + weight[u][v];
		pi[v] = u;
	}
}

void Adjacency_list(int num_vertex)
{
	node shift = (node)malloc(sizeof(_transform)); //�̵�
	node compare = (node)malloc(sizeof(_transform)); //��
	node tmp = (node)malloc(sizeof(_transform));

	for (int i = 0; i < num_vertex; i++)
	{
		compare = adj_list[i];
		for (int j = 0; j < num_vertex; j++)
		{
			if (graph[i][j] != 0)
			{
				tmp->Tvertex = j;
				tmp->Tweight = graph[i][j]; //weight ����
				if (adj_list[i] == compare) //�ٸ� ��ΰ� ���� ��
				{
					shift = tmp;
					adj_list[i] = tmp;
				}
				else //�ٸ� ��ΰ� ���� �� ��θ� ����
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
	//�׷��� �ʱ�ȭ
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
	//vertext �ʱ�ȭ
	::distance[start] = 0;
	::find[start] = 1;

	for (int i = 0; i < num_vertex; i++)
	{
		int u = Choose(num_vertex);
		::find[u] = 1;

		//�ִ� ��� �Ÿ� ���
		for (int j = 0; j < num_vertex; j++)
		{
			if (::find[j] != 1)
				Relax(u, j, graph);
		}

		//��ο� ����ġ ���
		if (i > 0)
		{
			int k = i;
			while (k != 0)
			{
				print[pi_num] = pi[k] + 1; //��� ����
				k = pi[k];
				pi_num++;
			}
			//��� ���
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
