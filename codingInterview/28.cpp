
bool isSymmetrical(pRoot1, pRoot2) {
    if(pRoot1 == NULL && pRoot2 == NULL)
	return true;
    if(pRoot1 == NULL || pRoot2 == NULL)
	return false;
    if(pRoot1 -> val != pRoot2 -> val)
	return false;

    return isSymmetrical(pRoot1 -> left, pRoot2 -> right) &&
	   isSymmetrical(pRoot1 -> right, pRoot2 -> left);


}


bool IsSymmetrical(Bitree* pRoot) {
    return isSymmetrical(pRoot, pRoot);
}
