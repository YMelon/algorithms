
#include "Utilities/BinaryTree.h"
#include <cstdio>


//核心逻辑函数声明
BinaryTreeNode* ConstructCore(int* startPreorder, 
	                      int* endPreorder, 
			      int* startInorder, 
			      int* endInorder);

//重建二叉树
BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    //输入合法检测
    if(preorder == NULL || inorder == NULL || length <= 0)
	return NULL;

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);

}

BinaryTreeNode* ConstructCore(int* startPreorder, 
	                      int* endPreorder, 
			      int* startInorder, 
			      int* endInorder) {
    //前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root -> m_nValue = rootValue;
    root -> m_pLeft = root -> m_pRight = NULL;

    if(startPreorder == endPreorder) {
	//只有一个节点
	if(startInorder == endInorder && *startPreorder == *startInorder)
	    return root;
	else {
	    printf("Invalid input");
	    return NULL;
	}
    }

    //在中序遍历序列中找到根节点的值
    int* rootInorder = startInorder;
    while(rootInorder < endInorder && *rootInorder != rootValue)
	rootInorder ++;
    //错误处理
    if(rootInorder == endInorder && *rootInorder != rootValue) {
	printf("Invalid input\n");
	return NULL;
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0) {
	//构建左子树
	root -> m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, 
		                        startInorder, rootInorder);
    }
    //构建右子树
    if(leftLength < endPreorder - startPreorder) {
	root -> m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, 
		                         rootInorder + 1, endInorder);
    }

    return root;
}





void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");


/*
    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
*/

        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

}

// ÆÕÍ¨¶þ²æÊ÷
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// ËùÓÐ½áµã¶¼Ã»ÓÐÓÒ×Ó½áµã
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// ËùÓÐ½áµã¶¼Ã»ÓÐ×ó×Ó½áµã
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// Ê÷ÖÐÖ»ÓÐÒ»¸ö½áµã
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// ÍêÈ«¶þ²æÊ÷
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// ÊäÈë¿ÕÖ¸Õë
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// ÊäÈëµÄÁ½¸öÐòÁÐ²»Æ¥Åä
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}








