#include "HypervisorApp.h"

using namespace std;

string GetCpuVendor(CPUID* cpu_info)
{
	char systype[13];
	string cpuid;


	for (int i = 0; i < 4; i++) {
		systype[i] = (char)*(((char*)(&cpu_info->ebx)) + i);
	}

	for (int i = 0; i < 4; i++) {
		systype[4 + i] = (char)*(((char*)(&cpu_info->edx)) + i);
	}

	for (int i = 0; i < 4; i++) {
		systype[8 + i] = (char)*(((char*)(&cpu_info->ecx)) + i);
	}

	systype[12] = (char)"\0";
	cpuid.assign(systype, 12);
	
	return cpuid;
}

int main()
{
	CPUID cpu_info = { 0 };
	string systype;

	GetCpuID((int*)&cpu_info, 0);
	systype = GetCpuVendor(&cpu_info);

	cout << "CPU vendor is " << systype << endl;

	if (VMX_Support_Detection()) {
		cout << "CPU SUPPORT VMX" << endl;
	}
	else {
		cout << "CPU DON NOT SUPPORT VMX" << endl;
	}
	
	return 0;
}