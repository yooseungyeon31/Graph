////std::map std::set -> 내부적으로 트리 비스무리한걸 쓰긴함.
////
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//template <typename T>
//class TreeNode
//{
//public:
//    TreeNode(const T& Value) : Data(Value)
//    {
//
//    }
//
//    ~TreeNode()
//    {
//        for (TreeNode<T>* Child : Children)
//            delete Child;
//    }
//
//    T Data;
//    vector<TreeNode<T>*> Children;
//};
//
//
//// 원시적인 트리 -> 탐색에 대한 특정 알고리즘이 없는 순전히 트리 형식으로 데이터를 관리하기위한 형태
//
//TreeNode<string>* MakeTree()
//{
//    TreeNode<string>* Root = new TreeNode<string>("A");
//    {
//        TreeNode<string>* NodeB = new TreeNode<string>("B");
//        {
//            TreeNode<string>* NodeD = new TreeNode<string>("D");
//            TreeNode<string>* NodeE = new TreeNode<string>("E");
//            {
//                TreeNode<string>* NodeI = new TreeNode<string>("I");
//                NodeE->Children.push_back(NodeI);
//            }
//            TreeNode<string>* NodeF = new TreeNode<string>("F");
//
//            NodeB->Children.push_back(NodeD);
//            NodeB->Children.push_back(NodeE);
//            NodeB->Children.push_back(NodeF);
//        }
//
//        TreeNode<string>* NodeC = new TreeNode<string>("C");
//        {
//            NodeC->Children.push_back(new TreeNode<string>("G"));
//            NodeC->Children.push_back(new TreeNode<string>("H"));
//        }
//
//        Root->Children.push_back(NodeB);
//        Root->Children.push_back(NodeC);
//    }
//
//    return Root;
//}
//void PrintTree(TreeNode<string>* Root)
//{
//	// 이 그래프가 전체 출력되게 만들어주세요
//	//면접 문제 유형: 트리 전체 순화, 트리 높이 구하기
//
//	
//    cout << Root->Data << endl;
//
//	for (TreeNode<string>* Child : Root->Children)
//		PrintTree(Child);
//
//    //전위순회 : 현재 노드 먼저 처리하고 자식 서브트리 처리
//	
//}
//
////트리 높이 출력
//int GetHeight(TreeNode<string>* Root)
//{
//    
//    int height = 0; 
//
//    for (TreeNode<string>* Child : Root->Children)
//    {
//        int maxChildHeight = GetHeight(Child)+1;
//
//        if (height < maxChildHeight)
//        {
//            height = maxChildHeight;
//        }
//      
//    }
//    //최종적으로 넘겨받은 트리의 높이가 출력되도록 만들어 주세요
//    return height;
//}
//
//int main()
//{
//	TreeNode<string>* Root = MakeTree();
//	PrintTree(Root);
//    cout << "트리 높이: " << GetHeight(Root) << endl;
//   
//	delete Root;
//	return 0;
//}
//
//
