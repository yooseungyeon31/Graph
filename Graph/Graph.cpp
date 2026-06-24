////강사님 해설
//#include <iostream>
//
//using namespace std;
//
//int M, N, K;
//int field[50][50] = {};
//bool visited[50][50] = {};
//
//int dy[] = { -1,1,0,0 };
//int dx[] = { 0,0,-1,1 };
//
//void dfs(int y, int x)
//{
//	//방문표시
//	visited[y][x] = true;
//
//
//	//연결되고 아직 방문 안한놈 찾기
//	for (int i = 0; i < 4; i++) //4방위확인
//	{
//		int ny = y + dy[i];
//
//		int nx = x + dx[i];
//
//		//범위초과 검증 
//		if (ny >= 0 && ny < N && nx >= 0 && nx < M)
//		{
//			if (field[ny][nx] == 1 && !visited[ny][nx])
//				dfs(ny, nx); //반복
//
//		}
//	}
//}
//
//int main()
//{
//	cin >> M >> N >> K;
//
//	//맵 만들기
//	for (int i = 0; i < K; i++)
//	{
//		int X, Y;
//		cin >> X >> Y;
//		field[Y][X] = 1;
//
//	}
//	int worm_count = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			if (field[i][j] == 1 && !visited[i][j])
//			{
//				dfs(i, j);
//				worm_count++;
//			}
//		}
//
//	}
//	cout << worm_count << '\n';
//
//
//	
//}






////유기농 배추 DFS 문제 내가 풀던거..
//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <iostream>
//#include <vector>
//#include <cstring>
//
//
//using namespace std;
//
//const int MAX_VERTEX = 2501;
//int M, N, K; //가로길이, 세로길이, 배추 위치의 개수
//int VertexCount;
//int board[51][51]; //보드 배열
//
//int AdjacencyMatrix[MAX_VERTEX][MAX_VERTEX];
//bool Visited[MAX_VERTEX];
//bool HasCabbage[MAX_VERTEX];
//
//
//
//void DFS(int Current)
//{
//	cout << "방문 : " << Current << '\n';
//	Visited[Current] = true; //방문 도장 찍기
//
//	for (int Next = 0; Next < VertexCount; Next++)
//	{
//		if (AdjacencyMatrix[Current][Next] == 0) //연결여부 확인
//			continue;
//
//		if (Visited[Next] == true)//방문한 적 있는지?
//			continue;
//
//
//		DFS(Next); //현재값에다가 Next를 넣어준다. 재귀로 호출. 찾은 정점에서 같은 작업을 할거기 때문
//
//	}
//}
//
//void Search() {
//	cin >> M >> N >> K;
//
//	VertexCount = N * M;
//
//
//	//배추 위치 받기
//	for (int i = 0; i < K; i++)
//	{
//		int y, x;
//		cin >> y>>x;
//
//
//		int VertexNum = x * N + y;
//		HasCabbage[VertexNum] = true;
//	}
//
//	//상하좌우 확인
//	for (int x = 0; x < N; x++)
//	{
//		for (int y = 0; y < M; y++)
//		{
//			int CurrentNum = x * M + y;
//
//			//배추가 현재 개수가 true 가 아니면 계속해라
//			if (!HasCabbage[CurrentNum] == true)
//				continue;
//
//			if (y + 1 < M)
//			{
//				int rightCurrent = x * M + (y + 1);
//				if (HasCabbage[rightCurrent])
//				{
//					AdjacencyMatrix[rightCurrent][CurrentNum] = 1;
//					AdjacencyMatrix[CurrentNum][rightCurrent] = 1;
//				}
//			}
//
//			if (x + 1 < N)
//			{
//				int downCurrent = (x + 1) * M + y;
//				if (HasCabbage[downCurrent])
//				{
//					AdjacencyMatrix[downCurrent][CurrentNum] = 1;
//					AdjacencyMatrix[CurrentNum][downCurrent] = 1;
//				}
//			}
//
//
//
//
//		}
//	}
//
//	int BugCount = 0;
//	for (int Current = 0; Current < VertexCount; Current++)
//	{
//		if (Visited[Current] == true)
//			continue;
//
//		DFS(Current);
//		BugCount++;
//	}
//	cout << BugCount << '\n';
//
//}
//
//
//int main()
//{
//	Search();
//
//}



//--------------------------------------------------
//DFS 설명

//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//
//const int VertexCount = 6;
//
//int AdjacencyMatrix[VertexCount][VertexCount] =
//{
//	{0,1,0,1,0,0},
//	{1,0,1,1,0,0},
//	{0,1,0,0,0,0},
//	{1,1,0,0,1,0},
//	{0,0,0,1,0,1},
//	{0,0,0,0,1,0}
//
//};
//
//bool Visited[VertexCount] = {};
//
//void DFS(int Current)
//{
//	cout << "방문 : " << Current << '\n';
//	Visited[Current] = true; //방문 도장 찍기
//
//	for (int Next = 0; Next < VertexCount; Next++)
//	{
//		if (AdjacencyMatrix[Current][Next] == 0) //연결여부 확인
//			continue;
//
//		if (Visited[Next] == true)//방문한 적 있는지?
//			continue;
//
//
//		DFS(Next); //현재값에다가 Next를 넣어준다. 재귀로 호출. 찾은 정점에서 같은 작업을 할거기 때문
//		
//	}
//
//}
//
//void AllSearch()
//{
//
//	for (int Current = 0; Current < VertexCount; Current++)
//	{
//		if (Visited[Current] == true)
//			continue;
//
//		DFS(Current);
//	}
//	//DFS가 총 2번 돌게 된다. -> 
//}
//
//
//void main()
//{
//	AllSearch();
//	
//}


//-------------------------------------------------------


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

