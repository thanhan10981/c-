#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100
#define ESC 27

class hocSinh {
private:
    int MSV;
    int namSinh;
    string hoTen;
    string queQuan;

public:
// hàm Nhập danh sách học sinh vào mảng.
    void nhapDanhSachhs() {
        cout << "Nhap ma SV: ";
        cin >> MSV;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore();
        cout << "Nhap que quan: ";
        getline(cin, queQuan);
    }
    void nhap_n_SV(hocSinh ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		ds[i].nhapDanhSachhs();
	}
}
// hàm Lưu danh sách học sinh từ mảng vào tập tin có tên là DATA.INP.
    void ghiDanhSachhs(ofstream &file) {
        file <<"MA SINH VIEN:"<< MSV << "; HO VA TEN: " << hoTen << "; NAM SINH:" << namSinh << "; QUE QUAN:" << queQuan << endl;
    }
// hàm Đọc danh sách học sinh từ tập tin DATA.INP ra mảng.
    void docDanhSachhs(ifstream &file) {
        file >> MSV;
        file.ignore();
        getline(file, hoTen);
        file >> namSinh;
        file.ignore();
        getline(file, queQuan);
    }
// hàm Hiển thị tất cả thông tin của các học sinh từ mảng lên màn hình.
    void hienThiThongTin(){
        cout << "Ma SV: " << MSV << endl;
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Nam Sinh: " << namSinh << endl;
        cout << "Que Quan: " << queQuan << endl;
    }

    int getMSV() {
        return MSV;
    }
};
// hàm Sắp xếp các danh sách học sinh giảm dần dựa theo mã học sinh.
void sapXepTheoMa(hocSinh ds[], int soLuongHS) {
    for (int i = 0; i < soLuongHS - 1; i++) {
        for (int j = 0; j < soLuongHS - i - 1; j++){
            if (ds[j].getMSV() < ds[j + 1].getMSV()) {
                hocSinh temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}
//hàm Xóa một học sinh có mã học cho trước ra khỏi danh sách.
void xoaHocSinhTheoMa(int maXoa, hocSinh ds[], int &soLuongHS) {
    int index = -1;
    for (int i = 0; i < soLuongHS; i++) {
        if (ds[i].getMSV() == maXoa) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < soLuongHS - 1; i++) {
            ds[i] = ds[i + 1];
        }
        soLuongHS--;
        cout << "Da xoa sinh vien co ma " << maXoa << " ra khoi danh sach." << endl;
    } else {
        cout << "Khong tim thay sinh vien co ma " << maXoa << " de xoa." << endl;
    }
}
//hàm Tìm một học sinh có mã học sinh cho trước.
void timHocSinhTheoMa(int maTimKiem, hocSinh ds[], int soLuongHS) {
    bool found = false;
    for (int i = 0; i < soLuongHS; i++) {
        if (ds[i].getMSV() == maTimKiem) {
            ds[i].hienThiThongTin();
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ma " << maTimKiem << endl;
    }
}
 void doc_n_SV(hocSinh ds[], int &n);

int main() {
    int luaChon,n;
    hocSinh danhSachHocSinh[MAX_SIZE];
    int soLuongHocSinh = 0;
    while (true) {
        system("cls");
        cout << "-------------------------------MENU--------------------------------" << endl;
        cout << "1.Nhap danh sach sinh vien vao mang" << endl;
        cout << "2.Luu danh sach sinh vien tu mang vao tap tin co ten la DATA.INP." << endl;
        cout << "3.Hien thi sinh vien tren mang" << endl;
        cout << "4.Doc danh sach sinh vien tu tap tin DATA.INP ra mang." << endl;
        cout << "5.Tim 1 sinh vien co ma sinh vien cho truoc." << endl;
        cout << "6.Chen 1 sinh vien vao danh sach." << endl;
        cout << "7.Xoa 1 sinh vien co ma sinh vien choi truoc ra ra khoi danh sach." << endl;
        cout << "8.Sap xem cac danh sach sinh vien giam dan dua theo tren ma sinh vien." << endl;
        cout<< "ESC de thoat" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Nhap lua chon cua ban:" << endl;
        luaChon = _getch();
        switch (luaChon) {
            case '1':
                if (soLuongHocSinh < MAX_SIZE) {
                    hocSinh hs;
                    cout<<"nhap so sinh vien can nhap."<< endl;
                    cin>>n;
                    hs.nhap_n_SV(danhSachHocSinh,  n);
                    danhSachHocSinh[soLuongHocSinh++] = hs;
                    cout << "Da them sinh vien vao danh sach." << endl;
                } else {
                    cout << "Danh sach da day. Khong the them sinh vien moi." << endl;
                }
                _getch();
                break;
            case '2':
                if (soLuongHocSinh > 0) {
                    ofstream outFile("DATA.INP");
                    for (int i = 0; i < soLuongHocSinh; i++) {
                        danhSachHocSinh[i].ghiDanhSachhs(outFile);
                    }
                    outFile.close();
                    cout << "Da luu danh sach sinh vien vao file DATA.INP." << endl;
                } else {
                    cout << "Danh sach rong. Khong the luu." << endl;
                }
                _getch();
                break;
            case '3':
               doc_n_SV(danhSachHocSinh, n);
                _getch();
                break;
            case '4':
                {
                    ifstream inFile("DATA.INP");
                    if (!inFile) {
                        cout << "Khong the doc file DATA.INP." << endl;
                        _getch();
                        break;
                    }

                    soLuongHocSinh = 0; 
                    while (!inFile.eof() && soLuongHocSinh < MAX_SIZE) {
                        danhSachHocSinh[soLuongHocSinh].docDanhSachhs(inFile);
                        soLuongHocSinh++;
                    }
                    inFile.close();
                    cout << "Da doc danh sach sinh vien tu file DATA.INP." << endl;
                }
                _getch();
                break;
            case '5':
                int maTimKiem;
                cout << "Nhap ma sinh vien can tim: ";
                cin >> maTimKiem;
                timHocSinhTheoMa(maTimKiem, danhSachHocSinh, soLuongHocSinh);              
                _getch();
                break;
            case '6':
                if (soLuongHocSinh < MAX_SIZE) {
                    hocSinh newStudent;
                    newStudent.nhapDanhSachhs();
                    danhSachHocSinh[soLuongHocSinh++] = newStudent;
                    cout << "Da them sinh vien vao danh sach." << endl;
                } else {
                    cout << "Danh sach da day. Khong the them sinh vien moi." << endl;
                }
                _getch();
                break;
            case '7':
                if (soLuongHocSinh > 0) {
                    int maXoa;
                    cout << "Nhap ma sinh vien can xoa: ";
                    cin >> maXoa;
                    xoaHocSinhTheoMa( maXoa,danhSachHocSinh, soLuongHocSinh);
                } else {
                    cout << "Danh sach rong. Khong the xoa." << endl;
                }
                _getch();
                break;
            case '8':
                if (soLuongHocSinh > 0) {
                    sapXepTheoMa(danhSachHocSinh, soLuongHocSinh);
                    cout << "Da sap xep danh sach sinh vien theo ma giam dan." << endl;
                } else {
                    cout << "Danh sach rong. Khong the sap xep." << endl;
                }
                _getch();
                break;
            case ESC:
                cout << "Ban da thoat chuong trinh" << endl;
                _getch();
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon trong menu" << endl;
                _getch();
                break;
        }
    }
}
void hocSinh::doc_n_SV(hocSinh danhSachHocSinh[] ,int &n)
{

	n = 0;
	ifstream in("DATA.INP");
	if (!in)
	{
		cout << "Khong mo duoc file.";
		return;
	}
	while (true)
	{
		in >> danhSachHocSinh[n].maSV;
		in.ignore();
		getline(in,danhSachHocSinh[n].hoTen);
		in >> danhSachHocSinh[n].namSinh;
		in.ignore();
		if (!getline(in, danhSachHocSinh[n].queQuan))
			break;
		n++;
	}
}