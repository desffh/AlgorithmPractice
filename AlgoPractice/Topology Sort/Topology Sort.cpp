#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 8

// 위상정렬: 사이클이 발생하지 않는 단방향 그래프에서 사용
//			 진입차수가 0이 되면 queue에 넣어둠

class Graph
{
private:
	int degree[SIZE]; // 진입차수 배열

	queue <int> queue; // queue배열

	vector <int> graph[SIZE]; // 인접리스트 그래프

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			degree[i] = 0; // 진입차수 0으로 초기화
		}
	}
	// 인접리스트 그래프 추가
	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		degree[edge]++; // 연결된 edge에 진입차수(간선) 추가
	}

	// 탐색
	void Sort()
	{
		// 1 ~ 7 까지 반복
		for (int i = 1; i < SIZE; i++)
		{
			// 진입차수가 0 이면 queue에 push
			if (degree[i] == 0)
			{
				queue.push(i);
			}
		}
		// 큐가 빌때까지 탐색
		while (queue.empty() == false)
		{
			// x에 queue 제일 앞에 값 넣고 pop
			int x = queue.front();
			cout << x << " ";
			queue.pop();

			// graph x에 인접한 정점의 수 만큼 반복
			for (int i = 0; i < graph[x].size(); i++)
			{
				// 인접한 정점들의 진입차수--
				int start = graph[x][i];
				degree[start]--;

				// 진입차수가 0 이라면 queue에 push
				if (degree[start] == 0)
				{
					queue.push(start);
				}
			}
		}

	}

};



int main()
{
	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 5);

	graph.Insert(2, 3);
	graph.Insert(3, 4);

	graph.Insert(4, 7);

	graph.Insert(5, 6);
	graph.Insert(6, 4);

	graph.Sort(); // 1 2 5 3 6 4 7


	return 0;
}