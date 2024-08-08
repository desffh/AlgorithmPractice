#include <iostream>
using namespace std;
#define SIZE 7

// 유니온 파인드
// 여러 노드가 있을때 어떤 노드가 어떤 노드와 연결되어 있는지
// 확인하는 알고리즘

// Union: x집합과 y집합끼리 트리구조로 합치기 
// Find: x가 속한 집합의 대표값 반환(부모노드)

class Graph
{
private:
	int parent[SIZE]; // 부모배열


public:
	Graph()
	{
		// 부모배열 = 부모배열 값으로 초기화
		for (int i = 1; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}
	// 부모찾는 함수
	int Find(int x)
	{
		// 부모배열 == 부모배열의 값
		if (parent[x] == x)
		{
			return x; // root노드를 반환
		}
		else
		{
			// parent[x]의 값을 Find()에 넣어 재귀를 돌리고
			// 반환된 x값을 넣어주기
			// ex) parent[x] = 반환된 x값
			// return parent[x]해주기

			parent[x] = Find(parent[x]);
			return parent[x];
		}
	}

	// 합치기
	void Union(int x, int y)
	{
		// 루트노드 x, y 찾기
		x = Find(x);
		y = Find(y);

		// 노드의 값을 root노드로 바꿔주기
		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}

	// 부모노드가 서로 같은지 확인
	bool Same(int x, int y)
	{
		return Find(x) == Find(y);
		// 같으면 true 0, 틀리면 false 1값을 반환
	}
};


int main()
{
	Graph graph;

	graph.Union(2, 3);
	graph.Union(1, 3);

	cout << graph.Same(1, 3); // 1
	cout << graph.Same(2, 3); // 1
	cout << graph.Same(3, 4); // 0

	return 0;
}