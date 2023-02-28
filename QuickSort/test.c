
#include <stdio.h>

void rTST_Debug(unsigned int *piValues, unsigned int iSize) {
	unsigned int iCon;
	for (iCon = 0; iCon < iSize; iCon++) {
		printf("%d ", piValues[iCon]);
	}
	printf("\n");
}

void rTST_QuickSort(unsigned int *piValues, unsigned int iSize) {

	if (iSize <= 1) {
		return;
	}

	unsigned int iLeft;
	unsigned int iRight;
	iLeft = 1;
	iRight = iSize - 1;

	if (iLeft == iRight) {
		if (piValues[0] > piValues[1]) {
			unsigned int iTemp;
			iTemp = piValues[0];
			piValues[0] = piValues[1];
			piValues[1] = iTemp;
		}
		return;
	}

	while (iRight != iLeft) {
		while (piValues[0] <= piValues[iRight] && iLeft != iRight) {
			iRight--;
		}
		while (piValues[0] > piValues[iLeft] && iLeft != iRight) {
			iLeft++;
		}
		if (iLeft != iRight) {
			unsigned int iTemp;
			iTemp = piValues[iLeft];
			piValues[iLeft] = piValues[iRight];
			piValues[iRight] = iTemp;
		}
		else {
			unsigned int iTemp;
			iTemp = piValues[0];
			piValues[0] = piValues[iRight];
			piValues[iRight] = iTemp;
			break;
		}
	}
	rTST_QuickSort(&piValues[0], iRight + 1);
	rTST_QuickSort(&piValues[iRight + 1], iSize - iLeft - 1);
	return;
}
