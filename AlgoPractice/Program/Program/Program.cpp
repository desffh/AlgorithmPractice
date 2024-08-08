#include <iostream>
#include <vector>
#include <algorithm> // sort사용하려면 

using namespace std;
#define SIZE 8

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


	};

	vector <Edge> graph; // Edge를 담을 vector형 배열

public:
	Graph()
	{
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


	return 0;
}