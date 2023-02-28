
#include <stdio.h>

int rSearch(int *piSeries, unsigned int iSize, int iTarget){

    unsigned int iLeft = 0;
    unsigned int iRight = iSize - 1;
    
    while(iRight >= iLeft){
        printf("[(%d %d) =",iLeft , iRight);
        unsigned int iMiddle = (iRight + iLeft) / 2;
        printf(" %d] = %d\n", iMiddle, piSeries[iMiddle]);
        if(piSeries[iMiddle] == iTarget){
            return iMiddle;
        }else if(piSeries[iMiddle] < iTarget){
            iLeft = iMiddle + 1;
        }else{
            iRight = iMiddle - 1;
        }
    }
    return -1;
}

int main(void){
    int iSeries[] = {1,3,6,8,12,15,17,19,20,22,23,25,32,43,76,78,80,91,93,100};
    
    printf("%d\n", rSearch(iSeries, sizeof(iSeries) / sizeof(int), 78));
}
