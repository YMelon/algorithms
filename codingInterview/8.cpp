#include <stdio.h>

struct BitreeNode {
    int val;
    BitreeNode* left;
    BitreeNode* right;
    BitreeNode* parent;
};


BitreeNode* getNext(BitreeNode* pNode) {
    if(pNode == NULL)
	return NULL;

    BitreeNode* pNext = NULL;
    
    //该节点有右子树
    if(pNode -> right != NULL) {
	BitreeNode* pRight = pNode -> right;
	while(pRight -> left != NULL)
	    pRight = pRight -> left;

	pNext = pRight;
    }else if(pNode -> parent != NULL) {
	BitreeNode* pCur = pNode;
	BitreeNode* pParent = pNode -> parent;
	while(pParent != NULL && pCur == pParent -> right) {
	    pCur = pParent;
	    pParent = pParent -> parent;
	}

	pNext = pParent;
    }

    return pNext;
}
