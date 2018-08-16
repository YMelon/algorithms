
void PrintInLine(BitreeNode* pRoot) {
    if(!pRoot)
	return;

    std::queue<BitreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while(!nodes.empty()) {
	BitreeNode* pNode = nodes.front();
	printf("%d ", pNode->val);
	
	if(pNode->left) {
	    nodes.push(pNode->left);
	    ++ nextLevel;
	}
	if(pNode->right) {
	    nodes.push(pNode->right);
	    ++ nextLevel;
	}

	nodes.pop();
	-- toBePrinted;
	if(toBePrinted == 0) {
	    printf("\n");
	    toBePrinted = nextLevel;
	    nextLevel = 0;
	}
    }
}
