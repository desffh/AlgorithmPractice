#include <iostream>
#include <vector>
#include <algorithm> // sort사용하려면 

using namespace std;
#define SIZE 8

// 최소신장트리

// 그래프
class Graph
{
private:
	int parent[SIZE]; // 부모배열

	int cost;

	// 간선
	class Edge
	{
		// 연결할 노드 x와 y, 그 사이 가중치
	private:
		int x;
		int y;
		int distance;

	public:
		// 초기화
		// main함수에서 받은 인수값을 매개변수로 받아
		// 멤버변수 각각에 할당
		Edge(int x, int y, int distance)
		{
			this->x = x;
			this->y = y;
			this->distance = distance;
		}
		int& X()
		{
			return x;
		}
		int& Y()
		{
			return y;
		}
		int& Distance()
		{
			return distance;
		}

		// 연산자 < 정의 
		// 정렬 기준을 distance로
		bool operator < (const Edge& edge)
		{
			return this->distance < edge.distance;
		}

	};

	vector <Edge> graph; // Edge를 담을 vector형 배열

public:
	Graph()
	{
		cost = 0;

		// 부모배열 초기화
		for (int i = 1; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}
	// vector배열에 정점과 간선 삽입
	void Insert(int x, int y, int distance)
	{
		// graph배열에 Edge넣어주기
		graph.push_back(Edge(x, y, distance));
	}

	// 부모 노드 찾기
	int Find(int x)
	{
		if (parent[x] == x)
		{
			return x;
		}
		else
		{
			parent[x] = Find(parent[x]);
			return parent[x];
		}
	}

	// 유니온 합치기
	void Union(int x, int y)
	{
		x = Find(x); // 집합의 root노드
		y = Find(y);
		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}
	// 같은지 아닌지 확인
	bool Same(int x, int y)
	{
		return Find(x) == Find(y);

	}
	// 가중치 비교 후 저장
	void Kruskal()
	{
		// graph배열을 가중치 오름차순으로 정렬
		// -> Edge의 가중치를 비교하여
		// this->distance < edge.distance = true라면 그대로
		// false라면 순서를 바꿔 이 과정을 반복하여 오름차순 정렬
		sort(graph.begin(), graph.end());

		for (int i = 0; i < graph.size(); i++)
		{
			// 정점 x,y가 다르다면 -> 노드가 서로 다른 집합
			if (Same(graph[i].X(), graph[i].Y()) == false)
			{
				// 집합이 달라root노드가 다르고 사이클이 없음
				cost += graph[i].Distance();

				// 가중치 합산하고 root노드 맞춰주기
				Union(graph[i].X(), graph[i].Y());

				cout << '(' << graph[i].X() << ',' << graph[i].Y() << ")->" << graph[i].Distance() << endl;
			}
		}
		cout << "Graph의 최소비용: " << cost << endl;
	}

};




int main()
{
	Graph graph;

	graph.Insert(1, 7, 10);
	graph.Insert(1, 4, 28);
	graph.Insert(1, 2, 66);
	graph.Insert(1, 5, 19);

	graph.Insert(2, 4, 25);
	graph.Insert(2, 5, 60);

	graph.Insert(3, 5, 21);
	graph.Insert(3, 6, 35);

	graph.Insert(4, 7, 15);
	graph.Insert(5, 6, 40);

	graph.Kruskal();

	return 0;
}