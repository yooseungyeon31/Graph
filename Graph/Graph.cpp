#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>


using namespace std;

const int VertexCount = 6;

int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{0,1,0,1,0,0},
	{1,0,1,1,0,0},
	{0,1,0,0,0,0},
	{1,1,0,0,1,0},
	{0,0,0,1,0,1},
	{0,0,0,0,1,0}

};

bool Visited[VertexCount] = {};

void DFS(int Current)
{
	cout << "방문 : " << Current << '\n';
	Visited[Current] = true; //방문 도장 찍기

	for (int Next = 0; Next < VertexCount; Next++)
	{
		if (AdjacencyMatrix[Current][Next] == 0) //연결여부 확인
			continue;

		if (Visited[Next] == true)//방문한 적 있는지?
			continue;


		DFS(Next); //현재값에다가 Next를 넣어준다. 재귀로 호출. 찾은 정점에서 같은 작업을 할거기 때문
		
	}

}

void AllSearch()
{

	for (int Current = 0; Current < VertexCount; Current++)
	{
		if (Visited[Current] == true)
			continue;

		DFS(Current);
	}
	//DFS가 총 2번 돌게 된다. -> 
}


void main()
{
	AllSearch();
	
}


//void AddUndirectedEdge(vector<vector<int>>& Graph, int first, int second)
//{
//    Graph[first].push_back(second);
//    Graph[first].push_back(first);
//}
//
//void main()
//{
//
//    int Graph[6][6] =
//    {
//
//    }
//
//    ////Graph 현재 정점과 연결된 정점을 저장
//    //vector<vector<int>>Graph(6);
//
//    ////정점과 정점을 잇는 코드
//    ////순서대로 [정점],  [이어질 정점]
//    //Graph[0].push_back(1);
//    //Graph[0].push_back(2);
//
//    //Graph[1].push_back(0);
//    //Graph[1].push_back(2);
//    //Graph[1].push_back(3);
//
//    //Graph[2].push_back(1);
//
//    //Graph[3].push_back(4);
//
//    //Graph[4].push_back(5);
//
//
//   
//}

