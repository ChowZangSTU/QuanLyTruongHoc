#include "SinhVien.h"

void NhapSinhVien(sinhvien& sv) {
	cout << "- Nhap ten sinh vien: "; cin >> sv.tensv;
	cout << "@@@ Nhap so luong mon: "; cin >> sv.soluongmon;
	sv.mharr = new MonHoc[sv.soluongmon]; // con tro sv.mharr trỏ đến kieu du lieu monhoc

	for (int i = 0; i < sv.soluongmon; i++) {
		cout << "\n- Nhap mon thu " << i + 1 << endl;
		NhapMon(sv.mharr[i]);
	}
}

float DiemTB(sinhvien sv) {
	float tongtin = 0, tongdiem = 0;
	for (int i = 0; i < sv.soluongmon; i++) {
		tongtin += sv.mharr[i].diem * sv.mharr[i].sotinchi;
	}

	for (int i = 0; i < sv.soluongmon; i++) {
		tongdiem += sv.mharr[i].sotinchi;
	}
	return tongtin / tongdiem;
}

string XepLoai(sinhvien sv) {
	float avg = DiemTB(sv);
	if (avg < 2) {
		return "Kem";
	}
	else if (avg < 5) {
		return "Yeu";
	}
	else if (avg < 7) {
		return "Trung Binh";
	}
	else if (avg < 8) {
		return "Kha";
	}
	else if (avg < 9) {
		return "Gioi";
	}
	else {
		return "Xuat Sac";
	}
}

void XuatSinhVien(sinhvien sv) {
	cout << "- Ma so sinh vien: " << sv.maso << endl;
	cout << "- Ten sinh vien: " << sv.tensv << endl;

	for (int i = 0; i < sv.soluongmon; i++) {
		cout << "\n- Mon thu " << i + 1 << endl;
		XuatMon(sv.mharr[i]);
	}
	string n = XepLoai(sv);

	if (DiemTB(sv) == NULL) {
		sv.avg = 0;
	}
	else { sv.avg = DiemTB(sv); }
	cout << "\n- Diem trung binh: " << sv.avg << endl;
	cout << "Xep Loai: " << n << endl;
}

int TongChi(sinhvien sv, int sotien) {
	int sum = 0;
	for (int i = 0; i < sv.soluongmon; i++) {
		sum += sv.mharr[i].sotinchi * sotien;
	}
	return sum;
}