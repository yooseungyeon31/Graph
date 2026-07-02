#include <iostream>
#include <vector>

using namespace std;

struct BSTNode
{
	int Key; //BST의 숫자값
	BSTNode* Left;
	BSTNode* Right;

	BSTNode(int Value) : Key(Value), Left(nullptr), Right(nullptr)
	{

	}

	
};

class BinarySearchTree
{
private:
	BSTNode* Root = nullptr;

	BSTNode* InsertRec(BSTNode* Node, int Key)
	{
		if (Node == nullptr)
			return new BSTNode(Key);

		if (Key < Node->Key)
			Node->Left = InsertRec(Node->Left, Key);

		else if (Key < Node->Key)
			Node->Right = InsertRec(Node->Right, Key);

		return Node;


	}

	BSTNode* RemoveRec(BSTNode* Node, int Key)
	{
		if (Node == nullptr)
			return nullptr;

		if (Key < Node->Key)
			Node->Left = RemoveRec(Node->Left, Key);

		else if (Key < Node->Key)
			Node->Right = RemoveRec(Node->Right, Key);

		else
		{
			//삭제 대상이 Leap 노드인 경우 == 자식이 없는 경우
			if (Node->Left == nullptr && Node->Right == nullptr)
			{
				delete Node;
				return nullptr;

			}

			//삭제 대상의 자식이 하나인 경우 (Right는 자식이 있다)
			if (Node->Left == nullptr)
			{
				//오른쪽 자식을 오른쪽에 뺴두고
				BSTNode* RightChild = Node->Right;
				//삭제하고
				delete Node;
				//다른 오른쪽 자식으로 넣어준다..?
				return RightChild;
			}
			
			
			if (Node->Right == nullptr)
			{
				
				BSTNode* LeftChild = Node->Left;
				//삭제하고
				delete Node;
				return LeftChild;
			}

			//삭제 대상이 자식이 두개인 경우
			BSTNode* MinNode = FindMin(Node->Right);

			Node->Key = MinNode->Key;
			Node->Right = RemoveRec(Node->Right, MinNode->Key);

		}

		return Node;

	}

	BSTNode* FindMin(BSTNode* Node)
	{
		while (Node->Left)
			Node = Node->Left;

		return Node;
	}

public:

	~BinarySearchTree()
	{
		Clear(Root);
	}
	void Insert(int Key)
	{
		Root = InsertRec(Root, Key);

	}

	bool Contains(int Key) const
	{
		//클래스 함수안에서 변경할 수 없다.
		BSTNode* Current = Root;
		while (Current != nullptr)
		{
			if (Key == Current->Key)
				return true;

			Current = (Key < Current->Key) ? Current->Left : Current->Right;
		}

		return false;

	}

	 BSTNode* Find(int Key) const
	{
		//클래스 함수안에서 변경할 수 없다.
		BSTNode* Current = Root;
		while (Current != nullptr)
		{
			if (Key == Current->Key)
				return Current;

			Current = (Key < Current->Key) ? Current->Left : Current->Right;
		}

		return nullptr;

	}


	void Remove(int Key)
	{
		Root = RemoveRec(Root, Key);
		

	}
	void Clear(BSTNode* Node)
	{
		if (Node == nullptr)
			return;

		Clear(Node->Left);
		Clear(Node->Right);
		delete Node;
	 }

};



// 실습문제 구현하기 ----------------------------------------------------------
class BinarySearchTree2
{
private:
	BSTNode* Root = nullptr;

	void Clear(BSTNode* Node)
	{
		if (Node == nullptr)
			return;

		Clear(Node->Left);
		Clear(Node->Right);
		delete Node;
	}
public:
	~BinarySearchTree2()
	{
		Clear(Root);
	}

	void BuildFromSortedArray(const vector<int>& Values)
	{
		Clear(Root);
		Root = nullptr;

		if (Values.empty())
			return;

		int LastIndex = static_cast<int>(Values.size()) - 1;

		Root = BuildTree(Values, 0, LastIndex);
	}
	// [0][1][2][3][4][5][6][7][8][9]
// 11시 30분
// 재귀 함수 - 5~6줄

/*
	  4
   /    \
  1      7
 / \    / \
0   2  5   8
	 \  \   \
	  3  6   9
*/
// 현재 범위의 가운데 값으로 노드를 만든다.
// 가운데를 기준으로 왼쪽 범위의 가운데 값으로 자식 노드를 만든다.
// 왼쪽 범위가 모두 사라지면 가운데를 기준으로 가운데 값으로 자식 노드를 만든다.
	BSTNode* BuildTree(const vector<int>& Values, int Low, int High)
	{


		if (Low > High)
		{
			return nullptr;
		}

		
		//1. 중간 위치를 찾는다.
		int Mid = (Low + High) / 2;
		//2. 그 숫자로 중간 노드를 만든다.
		BSTNode* Node = new BSTNode(Values[Mid]);
		//3. 왼쪽 동네도 똑같은 방법으로 만들어서 내 왼쪽에 붙인다.(재귀)
		Node->Left = BuildTree(Values, Low, Mid-1);
		
		//4. 오른쪽 동네도 똑같은 방법으로 만들서 내 오른쪽에 붙인다. ( 재귀)
		Node->Right = BuildTree(Values, Mid+1, High);
		//5. 완성된 노드를 변환한다.

		return Node;

	
	}
};

int main()
{
	// 배열을 통짜로 BST 노드 형태로 만들기
	vector<int> Data =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	BinarySearchTree2 Bst;
	Bst.BuildFromSortedArray(Data);


	return 0;
}

//----------------------------------------------------------------


int main()
{
	int Data[] =
	{
		16,14,78,15,5,31,90,1,10,87
	};
	BinarySearchTree Bst;
	for (int Value : Data)
	{
		Bst.Insert(Value);
	}

	Bst.Remove(1);

	cout << boolalpha << Bst.Contains(1);
	

	return 0;
}















