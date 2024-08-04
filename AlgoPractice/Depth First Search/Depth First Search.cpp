#include <iostream>
#include <vector>
using namespace std;
#define SIZE 8 

// 깊이 우선 탐색 (Depth First Search)
// 시작점부터 다음 노드로 넘어가기 전에 해당 노드와 
// 연결된 곳 완벽하게 탐색하고 넘어가는 방법

class Graph
{
private:
	bool visited[SIZE]; // 방문배열

	vector <int> graph[SIZE]; // 그래프 인접리스트

public:
	Graph()
	{	// 방문배열 초기화
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	// 간선추가(그래프 연결)
	void Insert(int vertex, int edge)
	{
		// vector 구조는 뒷쪽 삽입,삭제만 가능 (push_back, pop_back)
		graph[vertex].push_back(edge);
		graph[edge].push_back(vertex);
	}

	// 함수가 호출될때마다 스택 프레임 생성, 함수 종료시 스택에서 제거

	// 탐색 (원하는 시작점부터 start)
	void Search(int start)
	{
		// 현재 노드 시작지점 방문체크
		visited[start] = true;

		// 현재 노드 출력
		cout << start << endl;

		// 현재 노드와 연결된 다음 노드를 재귀적으로 방문체크
		// graph[start].size() <- 인접한 정점들을 저장해두는 벡터인 graph
		// graph[start]에 연결되어 있는 정점들의 수
		for (int i = 0; i < graph[start].size(); i++)
		{
			// graph[start]에 연결되어 있는 정점들이 다음 노드
			int next = graph[start][i];

			// 다음 노드가 방문하지 않은 노드라면 재귀
			if (visited[next] == false)
			{
				Search(next);
			}
			// 방문한 노드라면 함수 종료 (스택에서 제거)
		}

	}
};


int main()
{
	Graph graph;

	// 피라미드 삼각형 모양
	graph.Insert(1, 2);
	graph.Insert(1, 3);

	graph.Insert(2, 3);
	graph.Insert(2, 4);
	graph.Insert(2, 5);

	graph.Insert(3, 6);
	graph.Insert(3, 7);

	graph.Insert(4, 5);
	graph.Insert(6, 7);

	graph.Search(1); // 1 2 3 6 7 4 5

	return 0;
}