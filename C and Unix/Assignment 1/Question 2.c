#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("characters are %d bytes. The maximum value is %c, and the minimum value is %c\n\n", sizeof(char), CHAR_MAX, CHAR_MIN);
	printf("shorts are %d bytes. The maximum value is %hi, and the minimum value is %hi\n\n", sizeof(short), SHRT_MAX, SHRT_MIN);
	printf("integers are %d bytes. The maximum value is %d, and the minimum value is %d\n\n", sizeof(int), INT_MAX, INT_MIN);
	printf("unsigned integers are %d bytes. The maximum value is %u, and the minimum value is 0\n\n", sizeof(unsigned int), UINT_MAX);
	printf("floats are %d bytes. The maximum value is %f, and the minimum value is %f\n\n", sizeof(float), FLT_MAX, FLT_MIN);
	
	return 0;
}
