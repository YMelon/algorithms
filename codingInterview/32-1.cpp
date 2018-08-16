
void PrintFromToBottom(BitreeNode* pRoot) {
    if(!pRoot)
	return;

    std::deque<BitreeNode*> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    while(dequeTreeNode.size()) {
	BitreeNode* pNode = dequeTreeNode.front();
	dequeTreeNode.pop_front();
	printf("%d ", pNode->val);

	if(pNode->left)
	    dequeTreeNode.push_back(pNode->left);
	if(pNode->right)
	    dequeTreeNode.push_back(pNode->right);
    }
}
