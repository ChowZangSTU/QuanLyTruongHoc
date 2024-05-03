#include "Khoa.h"

int main() {
	string luachon;
	khoa k;
	NhapKhoa(k);
	XuatKhoa(k);

choosen:
	cout << "\n\n";
	cout << ">>                       LUA CHON <<\n";
	cout << "++----------------------------------------------- --------++\n";
	cout << "|  1. Sap xep danh sach theo thu tu (Tang hoac Giam)       |\n";
	cout << "|  2. Hien thi so luong hoc sinh kha/ gioi                 |\n";
	cout << "|  3. Tinh so tien hoc lai                                 |\n";
	cout << "|  4. Tim thong tin sinh vien                              |\n";
	cout << "|  5. Them sinh vien                                       |\n";
	cout << "|  6. Xoa sinh vien                                        |\n";
	cout << "|  7. Cap nhap thong tin sinh vien                         |\n";
	cout << "|  8. Ket thuc                                             |\n";
	cout << "++--------------------------------------------------------++\n";

	int tinhnang;
	cout << "Lua chon cua ban: "; cin >> tinhnang;
	switch (tinhnang)
	{
	case 1:
	{
		char sapxep;
		cout << "Tang (t) hay Giam (g) ? "; cin >> sapxep;
		SapXepLopHoc(k, sapxep);
		XuatKhoa(k);
	}
	goto choosen;

	case 2:
		SoLuongKhaGioi(k);
		goto choosen;

	case 3:
	{	int sotien;
	cout << "Nhap so tien cua 1 chi: "; cin >> sotien;
	HocLai(k, sotien);
	}
	goto choosen;

	case 4:
	{
		string masotim;
		cout << "== == Nhap ma so can tim: "; cin >> masotim;
		sinhvien* sv = TimKiem(k, masotim); //con tro chi tro toi dia chi da co roi
		if (sv == NULL) {
			cout << "Ko tim thay " << endl;
		}
		else {
			cout << "    Tim Thay Thong Tin Sinh Vien    \n";
			XuatSinhVien(*sv);
		}
	}
	goto choosen;

	case 5:
	{
		int them; cout << "Nhap so luong sinh vien can them: "; cin >> them;
		ThemSinhVien(k, them);
		XuatKhoa(k);
	}
	goto choosen;

	case 6:
	{
	xoathem:
		string vitrixoa;
		cout << "Nhap vi tri ban muon xoa: "; cin >> vitrixoa;

		XoaSinhVien(k, vitrixoa);
		cout << "\nXXXXXX Danh sach sinh vien sau khi xoa XXXXXX\n";
		XuatKhoa(k);
		cout << "\nSinh vien da xoa la sinh vien co ma so: " << stoi(vitrixoa) << endl;
		if (k.soluongsinhvien != 0) {
			cout << "\nCon lai " << k.soluongsinhvien << endl;
			cout << "\nBan co muong tiep tuc xoa? (y/n) "; cin >> luachon;
			if (luachon == "y") {
				goto xoathem;
			}

		}
		else {
			cout << "\nKHONG CON SINH VIEN DE XOA\n";
		}
	}
	goto choosen;

	case 7:
	{
	thaydoi:
		string maso;
		cout << "Nhap ma so cua sinh vien ban muon cap nhat: "; cin >> maso;
		CapNhap(k, maso);
		cout << "\nSinh vien sau khi duoc cap nhat la\n";
		XuatSinhVien(k.svarr[stoi(maso) - 1]);
		cout << "\nBan co muon tiep tup cap nhat thong tin ? (y/n) "; cin >> luachon;
		if (luachon == "y") {
			goto thaydoi;
		}
	}
	goto choosen;

	default:
		break;
	}

	delete[]k.svarr;
	system("pause");
	return 0;
}