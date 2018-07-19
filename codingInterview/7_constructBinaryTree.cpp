
#include <cstdio>

//二叉树节点定义
struct BiTreeNode {
    int val;
    BiTreeNode* left;
    BiTreeNode* right;
};


//核心逻辑函数声明
BiTreeNode* ConstructCore(int* startPre, int* endPre, int* startIn, int* endIn);

//重建二叉树
BiTreeNode* Construct(int* pre, int* in, int len) {
    //输入合法检测
    if(pre== NULL || in == NULL || len <= 0)
	return NULL;

    return ConstructCore(pre, pre + len - 1, in, in + len - 1);

}

BiTreeNode* ConstructCore(int* startPre, int* endPre, int* startIn, int* endIn) {
    //前序遍历序列的第一个数字是根节点的值
    int rootVal = startPre[0];
    BiTreeNode* root = new BiTreeNode();
    root -> val = rootVal;
    root -> left = root -> right = NULL;

    //二叉树只有一个节点
    if(startPre == endPre) {
	if(startIn == endIn && *startPre == *startIn)
	    return root;
	else {
	    printf("Invalid input: input sequence not match\n");
	    return NULL;
	}
    }

    //在中序遍历序列中找到根节点
    int* rootIn = startIn;
    while(rootIn < endIn && *rootIn != rootVal)
	rootIn ++;
    //错误处理
    if(rootIn == endIn && *rootIn != rootVal) {
	printf("Invalid input: input sequence not match\n");
	return NULL;
    }

    int leftLen = rootIn - startIn;
    int* leftPreEnd = startPre + leftLen;
    //构建左子树
    if(leftLen > 0) {
	root -> left = ConstructCore(startPre + 1, leftPreEnd, startIn, rootIn - 1);
    }
    //构建右子树 若左子树序列小于二叉树序列说明有右子树
    if(leftLen < endPre - startPre) {
	root -> right = ConstructCore(leftPreEnd + 1, endPre, rootIn + 1, endIn);
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








