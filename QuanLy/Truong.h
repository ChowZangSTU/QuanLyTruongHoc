#pragma once
#include "Khoa.h"
struct Truong
{
	char tentruong[30];
	int soluongkhoa;
	Khoa* karr;
};
typedef struct Truong truong;

void NhapTruong(truong&);
void XuatTruong(truong);


