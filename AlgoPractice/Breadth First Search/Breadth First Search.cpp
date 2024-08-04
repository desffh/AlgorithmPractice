#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define SIZE 6 

// 너비 우선 탐색(BFS Breadth First Search)

class Graph
{
private:
	bool visited[SIZE]; // 방문배열

	queue <int> queue; // queue 배열

	vector <int> graph[SIZE]; // 그래프 인접 리스트

public:
	Graph()
	{	// 방문배열 초기화
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}
	// 그래프 연결
	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		graph[edge].push_back(vertex);
	}
	// start부터 탐색
	void Search(int start)
	{
		// 1. queue에 시작노드 삽입 후 방문처리
		queue.push(start);
		visited[start] = true;

		// 2. queue가 빌때까지 탐색
		while (queue.empty() == false)
		{
			// 큐 제일 앞에 값 저장 후 출력
			int x = queue.front();

			cout << x << " ";

			queue.pop();

			// 큐의 제일 앞의 값에 인접한 노드들부터 탐색
			for (int i = 0; i < graph[x].size(); i++)
			{
				int next = graph[x][i]; // x와 인접한 노드들

				// 방문하지 않았다면
				if (visited[next] == false)
				{
					queue.push(next); // 인접 노드들 큐에 넣고
					visited[next] = true; // 방문 처리
				}

			}
		}
	}

};



int main()
{
	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 3);

	graph.Insert(2, 4);
	graph.Insert(3, 4);
	graph.Insert(3, 5);
	graph.Insert(5, 4);


	graph.Search(1); // 1 2 3 4 5

	return 0;
}