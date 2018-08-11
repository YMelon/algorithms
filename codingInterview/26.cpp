
struct BitreeNode {
    double val;
    BitreeNode* left;
    BitreeNode* right;
};

bool Equal(double num1, double num2) {
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	return true;
    else 
	return false;
}
bool DoesTree1HaveTree2(BitreeNode* pRoot1, BitreeNode* pRoot2) {
    if(pRoot2 == NULL)
	return true;
    if(pRoot1 == NULL)
	return false;

    if(!Equal(pRoot1 -> val, pRoot2 -> val))
	return false;

    return DoesTree1HaveTree2(pRoot1 -> left, pRoot2 -> left) && 
	   DoesTree1HaveTree2(pRoot1 -> right, pRoot2 -> right);
}


bool HasSubtree(BitreeNode* pRoot1, BitreeNode* pRoot2) {
    bool result = false;

    if(pRoot1 != NULL && pRoot2 != NULL) {
        if(Equal(pRoot1 -> val, pRoot2 -> val))
	    result = DoesTree1HaveTree2(pRoot1, pRoot2);
	if(!result)
	    result = HasSubtree(pRoot1 -> left, pRoot2);
	if(!result)
	    result = HasSubtree(pRoot1 -> right, pRoot2);
    }

    return result;
}
