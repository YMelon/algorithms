
bool VerifySquenceOfBST(int sequence[], int len) {
   if(sequence == NULL || len <= 0)
       return false;

   int root = sequence[len-1];

   int i = 0;
   for(; i < len-1; i++) {
       if(sequence[i] > root)
	   break;
   }

   int j = i;
   for(; j < len-1; j++) {
       if(sequence[j] < root)
	   return false;
   }

   bool left = true;
   if(i > 0)
       left = VerifySquenceOfBST(sequence, i);

   bool right = true;
   if(i < len-1)
       right = VerifySquenceOfBST(sequence+i, len-i-1);

   return (left && right);
}
