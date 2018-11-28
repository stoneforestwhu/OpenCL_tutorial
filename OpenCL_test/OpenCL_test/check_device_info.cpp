#include<stdio.h>
#include<stdlib.h>
#include<CL/cl.h>

void checkErr(cl_int err, int num)
{
	if (CL_SUCCESS != err)
	{
		printf("OpenCL error(%d) at %d\n", err, num - 1);
	}
}

int main(int argc, char **argv)
{
	cl_device_id *device;
	cl_platform_id platform;
	cl_int err;
	cl_uint NumDevice;
	err = clGetPlatformIDs(1, &platform, NULL);
	checkErr(err, _LINE_);
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, NULL, &NumDevice);
	checkErr(err, _LINE_);
	device = (cl_device_id*)malloc(sizeof(cl_device_id)*NumDevice);
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, NumDevice, device, NULL);
	checkErr(err, _LINE_);
	for (int i = 0; i < NumDevice; i++)
	{
		char buffer[100];
		err = clGetDeviceInfo(device[i], CL_DEVICE_NAME, 100, buffer, NULL);
		checkErr(err, _LINE_);
		printf("Device Name:%s\n", buffer);
		cl_uint UnitNum;
		err = clGetDeviceInfo(device[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &UnitNum, NULL);
		checkErr(err, _LINE_);
		printf("Compute Units Number: %d\n", UnitNum);

		cl_uint frequency;
		err = clGetDeviceInfo(device[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_uint), &frequency, NULL);
		checkErr(err, _LINE_);
		printf("Device Frequency: %d(MHZ)\n", frequency);

		cl_ulong GlobalSize;
		err = clGetDeviceInfo(device[i], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &GlobalSize, NULL);
		checkErr(err, _LINE_);
		printf("Device Global Size: %0.0f(MB)\n", (float)GlobalSize/1024/1024);

		cl_uint GlobalCacheLine;
		err = clGetDeviceInfo(device[i],
			                  CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,
			                  sizeof(cl_uint),
			                  &GlobalCacheLine,
			                  NULL);
		checkErr(err, _LINE_);
		printf("Device Version:%s\n", DeviceVersion);

		char* DeviceExtensions;
		cl_uint ExtenNum;
		err = clGetDeviceInfo(device[i], )
		
	}
}