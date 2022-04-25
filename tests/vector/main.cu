// SPL.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#include <spl/vector3.hh>

//using namespace std;

//__global__ void cuda_hello();

__global__ void cuda_hello() {
	printf("Hello World from GPU!\n");
}

int main()
{

	SPLVector3<SPLieee32> vec, vec1, vec2;

	vec1 = SPLVector3<SPLieee32>(1, 1, 1);
	vec2 = SPLVector3<SPLieee32>(2, 2, 2);

	vec = vec1 + vec2;
	vec.print();

	cuda_hello<<<1, 1>>>();

	return 0;
}
