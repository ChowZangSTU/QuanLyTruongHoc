#pragma once
#include "SinhVien.h" 
struct Khoa //Danh Sach Sinh Vien
{
	int soluongsinhvien;
	sinhvien* svarr;
};
typedef struct Khoa khoa;

void NhapKhoa(khoa&);
void XuatKhoa(khoa);
void HoanViSinhVien(sinhvien&, sinhvien&);
void SapXepLopHoc(khoa&, char); // Char để phân loại tăng hoay giảm
void SoLuongKhaGioi(khoa);
void HocLai(khoa, int);
sinhvien* TimKiem(khoa , string );
void ThemSinhVien(khoa&, int);
void XoaSinhVien(khoa&, string);
void CapNhap(khoa& , string);



