/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize){
    int *frac;
    frac = (int*)malloc(2*sizeof(int));
    frac[0] = 1;
    frac[1] = cont[contSize-1];
    *returnSize = 2;
    for(int i=contSize-2;i>=0;i--){
        frac[0] = frac[0] + cont[i]*frac[1];
        int temp = frac[0];
        frac[0] = frac[1];
        frac[1] = temp;
    }
    int temp = frac[0];
    frac[0] = frac[1];
    frac[1] = temp;
    return frac;
}