
#include <stdio.h>

void rTST_Debug(int *piValues, unsigned int iSize) {
	unsigned int iCon;
	for (iCon = 0; iCon < iSize; iCon++) {
		printf("%d ", piValues[iCon]);
	}
	printf("\n");
}

void rTST_QuickSort(int *piValues, unsigned int iSize) {

	unsigned int iLeft;
	unsigned int iRight;
	iLeft = 0;
	iRight = iSize;

	do {
		do {
			iRight--;
		} while (piValues[0] <= piValues[iRight] && iLeft < iRight);
		do {
			iLeft++;
		} while (piValues[0] > piValues[iLeft] && iLeft < iRight);
		if (iLeft < iRight) {
			unsigned int iTemp;
			iTemp = piValues[iLeft];
			piValues[iLeft] = piValues[iRight];
			piValues[iRight] = iTemp;
		}
	} while (iLeft < iRight);

	unsigned int iTemp;
	iTemp = piValues[0];
	piValues[0] = piValues[iRight];
	piValues[iRight] = iTemp;

	if (iRight > 1) {
		rTST_QuickSort(&piValues[0], iRight);
	}
	if (iSize - iRight - 1 > 1) {
		rTST_QuickSort(&piValues[iRight + 1], iSize - iRight - 1);
	}
	return;
}
