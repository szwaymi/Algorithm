
#include <stdio.h>
#include "test.h"

#define M_TEST rTST_QuickSort

void rDebug(unsigned int *piValues, unsigned int iSize) {
	unsigned int iCon;
	for (iCon = 0; iCon < iSize; iCon++) {
		printf("%d ", piValues[iCon]);
	}
	printf("\n");
}
unsigned int rCheck(unsigned int *piA, unsigned int *piB, unsigned int iSize) {
	unsigned int iCon;
	for (iCon = 0; iCon < iSize; iCon++) {
		if (*piA != *piB) {
			return 0;
		}
	}
	return 1;
}
int main(void) {

	//[Test Data]
#define M_TEST_DATA_IN(N, ...) unsigned int iSeries_In_##N[] ={ __VA_ARGS__ }
#define M_TEST_DATA_OUT(N, ...) unsigned int iSeries_Out_##N[] ={ __VA_ARGS__ }
	//	[#1]
	M_TEST_DATA_IN(1, 6, 3, 78, 12, 45, 643, 56, 8, 5, 34234, 74, 3, 6, 8, 24565, 543, 785, 23, 729, 570, 62, 60, 56, 342, 9, 84, 574, 305, 3789, 54309);
	M_TEST_DATA_OUT(1, 3, 3, 5, 6, 6, 8, 8, 9, 12, 23, 45, 56, 56, 60, 62, 74, 78, 84, 305, 342, 543, 570, 574, 643, 729, 785, 3789, 24565, 34234, 54309);
	//	[#2]
	M_TEST_DATA_IN(2, 582, 167, 985, 179, 509, 198, 643, 455, 389, 647, 216, 151, 538, 466, 196, 418, 623, 20, 682, 906, 829, 450, 844, 595, 569, 450, 973, 792, 116, 411, 952, 262, 978, 651, 538);
	M_TEST_DATA_OUT(2, 20, 116, 151, 167, 179, 196, 198, 216, 262, 389, 411, 418, 450, 450, 455, 466, 509, 538, 538, 569, 582, 595, 623, 643, 647, 651, 682, 792, 829, 844, 906, 952, 973, 978, 985);
	//	[#3]
	M_TEST_DATA_IN(3, 788, 562, 588, 384, 816, 263, 731, 28, 362, 649, 706, 309, 428, 495, 842, 85, 518, 599, 540, 630, 236, 582, 703, 763, 167, 438, 122, 850, 702, 887, 237, 946, 717, 343, 632);
	M_TEST_DATA_OUT(3, 28, 85, 122, 167, 236, 237, 263, 309, 343, 362, 384, 428, 438, 495, 518, 540, 562, 582, 588, 599, 630, 632, 649, 702, 703, 706, 717, 731, 763, 788, 816, 842, 850, 887, 946);
	//	[#4]
	M_TEST_DATA_IN(4, 920, 575, 984, 695, 775, 444, 627, 250, 318, 138, 108, 876, 145, 996, 917, 45, 787, 520, 118, 896, 996, 805, 808, 249, 562, 823, 565, 319, 949, 622, 190, 547, 349, 299, 762, 996, 805, 138, 108, 876, 145);
	M_TEST_DATA_OUT(4, 45, 108, 108, 118, 138, 138, 145, 145, 190, 249, 250, 299, 318, 319, 349, 444, 520, 547, 562, 565, 575, 622, 627, 695, 762, 775, 787, 805, 805, 808, 823, 876, 876, 896, 917, 920, 949, 984, 996, 996, 996);
    M_TEST_DATA_IN(5, 3, 0, -2, -1, 1, 2);
    M_TEST_DATA_OUT(5, -2, -1, 0, 1, 2, 3);
    M_TEST_DATA_IN(6, -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4);
    M_TEST_DATA_OUT(6, -4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4);
	M_TEST_DATA_IN(7, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	M_TEST_DATA_OUT(7, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	M_TEST_DATA_IN(8, 9, 8, 7, 6, 5, 4, 3, 2, 1);
	M_TEST_DATA_OUT(8, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	//	[Combined]
	struct sTest {
		unsigned int iNO;
		unsigned int *piIn;
		unsigned int *piOut;
		unsigned int iSize;
	};
#define M_TEST_COMBINE(N) {N, iSeries_In_##N, iSeries_Out_##N, sizeof(iSeries_In_##N) / sizeof(unsigned int)}
	struct sTest mTest[] = {
		M_TEST_COMBINE(1),
		M_TEST_COMBINE(2),
		M_TEST_COMBINE(3),
		M_TEST_COMBINE(4),
        M_TEST_COMBINE(5),
        M_TEST_COMBINE(6),
		M_TEST_COMBINE(7),
		M_TEST_COMBINE(8),
	};
	
	unsigned int iLength = sizeof(mTest) / sizeof(struct sTest);
	unsigned int iCon;
	for (iCon = 0; iCon < iLength; iCon++) {
		printf("Test Case [%d], Result = ", mTest[iCon].iNO);
		unsigned int iResult;
		M_TEST(mTest[iCon].piIn, mTest[iCon].iSize);
        //rDebug(mTest[iCon].piIn, mTest[iCon].iSize);
		iResult = rCheck(mTest[iCon].piIn, mTest[iCon].piOut, mTest->iSize);
		if (iResult) { printf("[MATCHED]"); }
		else { printf("[FAIL]"); }
		printf("\n");
		if (!iResult) { break; }
	}
}
