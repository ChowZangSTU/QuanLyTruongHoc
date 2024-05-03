#include "Khoa.h"

void SINHVIEN(khoa& k, int i) {
	cout << "\n== Nhap Sinh Vien Thu " << i + 1 << endl;
	int check = 0;
	do {
		cout << "\n- Nhap ma so sinh vien: "; cin >> k.svarr[i].maso;
		for (int j = 0; j < i; j++) {
			if (k.svarr[i].maso == k.svarr[j].maso || stoi(k.svarr[i].maso) == stoi(k.svarr[j].maso)) {
				cout << "\Ma so sinh vien bi trung. Xin kiem tra lai!\n";
				check = 1;
				break;
			}
			else {
				check = 0;
			}
		}
	} while (check == 1);
	NhapSinhVien(k.svarr[i]);
}

void NhapKhoa(khoa& k) {  
	cout << "So luong sinh vien: "; cin >> k.soluongsinhvien;
	
	k.svarr = new sinhvien[k.soluongsinhvien];
	for (int i = 0; i < k.soluongsinhvien; i++) {
		SINHVIEN(k, i);
	}
}
void XuatKhoa(khoa k) {
	cout << "\n==== Danh Sach Sinh Vien ====";
	for (int i = 0; i < k.soluongsinhvien; i++) {
		cout << "\n\n  === Sinh vien thu " << i + 1 << " ===\n";
		XuatSinhVien(k.svarr[i]);
	}
}

void HoanViSinhVien(sinhvien& a, sinhvien& b) {
	sinhvien temp = a;
	a = b;
	b = temp;
}
void SapXepLopHoc(khoa& k, char phanloai) {
	for (int i = 0; i < k.soluongsinhvien-1; i++) {
		for (int j = i + 1; j < k.soluongsinhvien; j++) {
			if (phanloai == 't') {
				if (DiemTB(k.svarr[i]) > DiemTB(k.svarr[j])) {
					HoanViSinhVien(k.svarr[i], k.svarr[j]);
				}
			}
			else {
				if (DiemTB(k.svarr[i]) < DiemTB(k.svarr[j])) {
					HoanViSinhVien(k.svarr[i], k.svarr[j]);
				}
			}
		}
	}
}; // Char để phân loại tăng hoay giảm

void SoLuongKhaGioi(khoa k) {
	int gioi = 0, kha = 0;
	for (int i = 0; i < k.soluongsinhvien; i++) {
		if (XepLoai(k.svarr[i]) == "Gioi") {
			gioi++;
		}
		if (XepLoai(k.svarr[i]) == "Kha") {
			kha++;
		}
	}
	cout << "So luong hoc sinh gioi: " << gioi << endl;
	cout << "So luong hoc sinh kha: " << kha << endl;
}

void HocLai(khoa k, int tien) {
	int hoclai = 0;
	int sochi = 0;
	for (int i = 0; i < k.soluongsinhvien; i++) {
		//int check = 0; //Sv rot 1 mon thi dung
		//Duyệt vào từng môn học của sinh viên thứ i trong danh sách lớp
		for (int j = 0; j < k.svarr[i].soluongmon; j++) {

			if (k.svarr[i].mharr[j].diem < 5 /*check == 0*/) {
				hoclai++;
				sochi += k.svarr[i].mharr[j].sotinchi;
				//check = 1;
			}
		}
	}
	cout << "So mon can hoc lai: " << hoclai << endl;
	cout << "Tong so tien hoc lai: " << sochi * tien;
}

sinhvien* TimKiem(khoa k, string timmaso) {
	for (int i = 0; i < k.soluongsinhvien; i++) {
		if (k.svarr[i].maso == timmaso) {
			return &k.svarr[i];
		}
	}
	return NULL; //NULL là kiểu trả về của con trỏ 
}

void ThemSinhVien(khoa& k, int soluong) {
	int soluongcu = k.soluongsinhvien;
	k.soluongsinhvien += soluong;
	sinhvien* b = new sinhvien[k.soluongsinhvien];
	for (int i = 0; i < soluongcu; i++) {
		b[i] = k.svarr[i];
	}
	delete[]k.svarr;

	k.svarr = new sinhvien[k.soluongsinhvien];
	for (int i = 0; i < k.soluongsinhvien; i++) {
		if (i >= k.soluongsinhvien - soluong) {
			SINHVIEN(k, i);
		}
		else {
			k.svarr[i] = b[i];
		}
	}
	delete[]b;
}


void XoaSinhVien(khoa& k, string vitrixoa) 
{
	for (int i = 0; i < k.soluongsinhvien - 1; i++) {
		if (k.svarr[i].maso >= vitrixoa) {
			k.svarr[i] = k.svarr[i + 1];
		}
	}
	k.soluongsinhvien--;
}

void CapNhap(khoa& k, string maso) 
{
	for (int i = 0; i < k.soluongsinhvien; i++) {
		if (k.svarr[i].maso == maso) {
			NhapSinhVien(k.svarr[i]);
		}
	}
}

void HoanVi(sinhvien& a, sinhvien& b) {
	sinhvien temp = a;
	a = b;
	b = temp;
}

void SapXepTen(khoa& k, char phanloai) {
	for (int i = 0; i < k.soluongsinhvien - 1; i++) {
		for (int j = i + 1; j < k.soluongsinhvien; j++) {
			if (phanloai == 't') {
				char ten1[30], ten2[30];
				if (strcmp(ten1, ten2) == 1) {
					HoanVi(k.svarr[i], k.svarr[j]);
				}
			}
			else if (phanloai == 'g') {
				char ten1[30], ten2[30];
				if (strcmp(ten1, ten2) == 0) {
					HoanVi(k.svarr[i], k.svarr[j]);
				}
			}
		}
	}
}






