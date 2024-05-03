#include "MonHoc.h"


void NhapMon(monhoc& mh) {
	cin.ignore();
	cout << "+ Nhap ten mon hoc: "; cin >> mh.tenmon;

	do {
		cout << "+ Nhap so diem: "; cin >> mh.diem;
		if (mh.diem < 0 || mh.diem > 10) {
			cout << "\n! - ! Bi loi. Xin hay kiem tra lai ! - !\n";
		}
	} while (mh.diem < 0 || mh.diem > 10);

	do {
		cout << "+ Nhap so tin chi: "; cin >> mh.sotinchi;
		if (mh.sotinchi < 0) {
			cout << "\n! - ! Bi loi. Xin hay kiem tra lai ! - !\n";
		}
	} while (mh.sotinchi < 0);
}

void XuatMon(monhoc mh) {
	cout << "+ Ten Mon: " << mh.tenmon << endl;
	cout << "+ Diem: " << mh.diem << endl;
	cout << "+ So tin: " << mh.sotinchi << endl;
}