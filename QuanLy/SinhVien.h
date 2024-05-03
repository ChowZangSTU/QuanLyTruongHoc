#pragma once
#include "MonHoc.h"
struct SinhVien
{
	string maso, tensv;
	int soluongmon;
	float avg;
	MonHoc *mharr; //con trỏ mharr trỏ đến kiểu dữ liệu MonHoc
};
typedef struct SinhVien sinhvien;

void NhapSinhVien(sinhvien&);
void XuatSinhVien(sinhvien);
float DiemTB(sinhvien);
string XepLoai(sinhvien);
int TongChi(sinhvien, int);

