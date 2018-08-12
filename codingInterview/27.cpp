
struct BitreeNode {
    int val;
    BitreeNode* left;
    BitreeNode* right;
};


void MirrorRecur(BitreeNode* pNode) {
    if(pNode == NULL)
	return;
    if(pNode -> left == NULL && pNode -> right == NULL)
	return;

    BitreeNode* pTemp = pNode -> left;
    pNode -> left = pNode -> right;
    pNode -> right = pTemp;

    if(pNode -> left)
	MirrorRecur(pNode -> left);
    if(pNode -> right)
	MirrorRecur(pNode -> right);
}
