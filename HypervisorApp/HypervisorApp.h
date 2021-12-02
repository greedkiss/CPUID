#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>  
#include <vector>  
#include <bitset>  
#include <array>  
#include <string>  
#include <intrin.h> 


typedef struct _CPUID {
	int eax;
	int ebx;
	int ecx;
	int edx;
}CPUID;


#ifdef __cplusplus
extern "C" {
#endif

long long GetCpuID(int* addr, int eax);
long long VMX_Support_Detection();

#ifdef __cplusplus
}
#endif
