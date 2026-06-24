#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

const int VertexCount = 6;

int AdjacencyMatrix[VertexCount][VertexCount] =
{
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}

};

bool Visited[VertexCount] = {};
int Distance[VertexCount] = {}; //시작 지점으로 부터 떨어진  거리 재기 위한거
int Parent[VertexCount] = {}; //해당 정점의 부모를 기록 

void PrintShortestPath(int Start, int Dest)
{
	// 출력값 0->3->4->5 이게 찍혀 나오게 해보기
	if (Visited[Dest] == false)
	{
		cout << "목적지까지 이동할 수 없습니다.";
		return;
	}

	//벡터
	vector<int>path;
	int Current = Dest;

	//목적지에서 시작점으로 돌아가기
	while (Current != Start)
	{
		path.push_back(Current);
		Current = Parent[Current];
	} path.push_back(Start);

	//거꾸로 뒤집기
	reverse(path.begin(), path.end());

	//출력하기
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i];
		if (i != path.size() - 1)
		{
			cout << "->";
		}
	}
	cout << '\n';


	
	//출력값
	// 0->3->4->5

}


void BFS(int Start)
{
	//5->4->3->0


	queue<int> VertexQueue; //예약 목록
	VertexQueue.push(Start); //시작 지점 예약
	Visited[Start] = true; //방문 도장 찍기
	Parent[Start] = Start;
	Distance[Start] = 0;


	while (!VertexQueue.empty()) //큐가 비어있지 않다면 반복
	{
		int Current = VertexQueue.front();//큐에 가장 오래 예약된 놈 엿보기
		VertexQueue.pop();

		cout << "방문 : " << Current << '\n';
		cout << "부모 : " << Parent[Current] << '\n';
		cout << "거리 : " << Distance[Current] << '\n' << '\n';

		for (int Next = 0; Next < VertexCount; ++Next) //현재 정점에서 연결되어 있고 방문 안한놈 찾기
		{
			if (AdjacencyMatrix[Current][Next] == 0) //연결 되어 있는지 않은지
				continue;
			 
			if (Visited[Next] == true) //이미 방문 했는지
				continue;

			VertexQueue.push(Next); //예약 걸기
			Visited[Next] = true;
			Parent[Next] = Current;// 부모는 지금 현재 연결된 정점을 뒤지고 있는 정점
			Distance[Next] = Distance[Current] + 1; //부모의 거리에서 1을 더한 값이 나의값


		}

	}




	
}

void main()
{
	BFS(0);
	PrintShortestPath(0, 5);
	return;
}


//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//// BFS (Breath First Search)
//// 너비 우선 탐색
//
//// 예약이 없으면 종료
//const int VertexCount = 6;
//
//int AdjacencyMatrix[VertexCount][VertexCount] =
//{
//    {0, 1, 0, 1, 0, 0},
//    {1, 0, 1, 1, 0, 0},
//    {0, 1, 0, 0, 0, 0},
//    {1, 1, 0, 0, 1, 0},
//    {0, 0, 0, 1, 0, 1},
//    {0, 0, 0, 0, 1, 0}
//};
//
//bool Visited[VertexCount] = {};
//int Distance[VertexCount] = {}; // 시작 지점으로부터 떨어진 거리 기록
//int Parent[VertexCount] = {}; // 해당 점점의 부모를 기록 (예약을 건 주체가 부모)
//
//void PrintShortestPath(int Start, int Dest)
//{
//    // 5 4 3 0
//    // 0 3 4 5 -> 출력값으로 이게 나오게끔 
//
//    if (Visited[Dest] == false)
//    {
//        cout << "목적지까지 이동할 수 없습니다." << '\n';
//        return;
//    }
//}
//
//void BFS(int Start)
//{
//    queue<int> VertexQueue; // 예약 목록
//    VertexQueue.push(Start); // 시작 지점 예약
//    Visited[Start] = true; // 방문 도장 찍기
//    Parent[Start] = Start; // 시작 지점은 동일
//    Distance[Start] = 0;
//
//
//    while (!VertexQueue.empty()) // Queue가 비어있지 않다면 반복
//    {
//        int Current = VertexQueue.front(); // Queue에 가장 오래 예약한 점 확인하기
//        VertexQueue.pop();
//
//        cout << "방문 : " << Current << '\n';
//        cout << "부모 : " << Parent[Current] << '\n';
//        cout << "거리 : " << Distance[Current] << '\n' << endl;
//
//        for (int Next = 0; Next < VertexCount; ++Next) // 현재 정점에서 연결 되어있고, 방문 안 한 지점
//        {
//            if (AdjacencyMatrix[Current][Next] == 0) // 연결되어있지 않은지
//                continue;
//            if (Visited[Next] == true) // 이미 방문 했는지
//                continue;
//
//            VertexQueue.push(Next); // 예약 걸기
//            Visited[Next] = true;
//            Parent[Next] = Current; // 부모는 지금 현재 연결된 정점을 뒤지고 있는 정점
//            Distance[Next] = Distance[Current] + 1; // 부모의 거리에서 1을 더한 값이 나의 값
//        }
//    }
//
//}
//
//void main()
//{
//    BFS(0);
//
//    return;
//}