#include "Truong.h"

void NhapTruong(truong& t) {
	cout << "Nhap ten truong: "; cin >> t.tentruong;
	cout << "Nhap so luong khoa: "; cin >> t.soluongkhoa;

	t.karr = new Khoa[t.soluongkhoa];
	for (int i = 0; i < t.soluongkhoa; i++) {
		NhapKhoa(t.karr[i]);
	}
}

void XuatTruong(truong t) {
	cout << "Ten truong: " << t.tentruong;
	for (int i = 0; i < t.soluongkhoa; i++) {
		XuatKhoa(t.karr[i]);
	}
}
