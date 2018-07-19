
#include "utils/BiTree.cpp"
#include <cstdio>


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


int main() {
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    BiTreeNode* root = Construct(preorder, inorder, length);
    PrintTree(root);
    
    return 0;
}








