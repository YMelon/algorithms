
BitreeNode* Convert(BitreeNode* pRoot) {
    BitreeNode* pLastNodeInList = NULL;
    ConvertNode(pRoot, &pLastNodeInList);

    BitreeNode* pHeadOfList = pLastNodeInlist;
    while(pHeadOfList != NULL && pHeadOfList->left != NULL)
	pHeadOfList = pHeadOfList -> left;

    return pHeadOfList;
}

void ConvertNode(BitreeNode* pNode, BitreeNode** pLastInList) {
    if(pNode == NULL)
	return;

    BitreeNode* pCurrent = pNode;

    if(pCurrent -> left != NULL)
	ConvertNode(pCurrent->left, pLastInList);

    pCurrent -> left = *pLastInList;
    if(*pLastInlist != NULL)
	(*pLastInList) -> right = pCurrent;

    *pLastInList = pCurrent;

    if(pCurrent -> right != NULL)
	ConvertNode(pCurrent->right, pLastInlist);
}
