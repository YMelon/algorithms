
void Print(BitreeNode* pRoot) {
    if(pRoot == NULL)
	return;

    std::stack<BitreeNode*> levels[2];
    int cur = 0;
    int next = 1;

    levels[cur].push(pRoot);
    while(!levels[0].empty || !levels[1].empty()) {
	BitreeNode* pNode = levels[cur].top();
	levels[cur].pop();

	printf("%d ", pNode->val);

	if(cur == 0) {
	    if(pNode->left != NULL)
		levels[next].push(pNode->left);
	    if(pNode->right != NULL)
		levels[next].push(pNode->right);
	} else {
	    if(pNode->right != NULL)
		levels[next].push(pNode->right);
	    if(pNode->left != NULL)
		levels[next].push(pNode->left);
	}

	if(levels[cur].empty()) {
	    printf("\n");
	    cur = 1 - cur;
	    next = 1 - next;
	}
    }
}
