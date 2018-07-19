#include <cstdio>

//二叉树节点定义
struct BiTreeNode {
    int val;
    BiTreeNode* left;
    BiTreeNode* right;
};


void PrintTreeNode(const BiTreeNode* pNode) {
    if(pNode != NULL) {
	printf("value of this node is: %d\n", pNode -> val);
        //打印左孩子节点
	if(pNode -> left != NULL)
	    printf("value of its left child is: %d\n", pNode -> left -> val);
	else
	    printf("left child is NULL.\n");
        //打印右孩子节点
	if(pNode -> right != NULL)
	    printf("value of its right child is: %d\n", pNode -> right -> val);
	else
	    printf("right child is NULL.\n");
    } else {
	printf("this node is NULL.\n");
    }

    printf("\n");
}

void PrintTree(const BiTreeNode* pRoot) {
    PrintTreeNode(pRoot);

    if(pRoot != NULL) {
        //打印左子树
	if(pRoot -> left != NULL)
	    PrintTree(pRoot -> left);
	//打印右子树
	if(pRoot -> right != NULL)
	    PrintTree(pRoot -> left);
    }
}

















