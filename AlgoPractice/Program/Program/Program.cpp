#include <iostream>
using namespace std;
#define SIZE 7

// 유니온 파인드
// 여러 노드가 있을때 어떤 노드가 어떤 노드와 연결되어 있는지
// 확인하는 알고리즘

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
			// 재귀를 돌려 부모배열 찾아서 return
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

		// 노드의 값을 합쳐준다
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
		// 같으면 true, 틀리면 false값을 반환
	}
};


int main()
{
	Graph graph;

	graph.Union(2, 3);
	graph.Union(1, 3);


	return 0;
}