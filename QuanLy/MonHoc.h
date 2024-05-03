#pragma once
#include <iostream>
#include <string>
using namespace std;

struct MonHoc
{
	int diem, sotinchi;
	char tenmon[30];
};
typedef struct MonHoc monhoc;

void NhapMon(monhoc&);
void XuatMon(monhoc);


