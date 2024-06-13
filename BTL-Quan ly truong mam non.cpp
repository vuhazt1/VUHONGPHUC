#include <bits/stdc++.h>
#include <string.h>
#define MAX 100

using namespace std;
struct Ngaysinh {
		int ng;
		int th;
		int na;
};

struct Ngaynhaphoc {
		int ng;
		int th;
		int na;
};

struct Thongtinphuhuynh {
		string hotencha ;
		string nghenghiepcha;
		int sdtcha;
		string hotenme ;
		string nghenghiepme ;
		int stdme;
};

struct Hocsinh {
	int id;
	string hoten;
	string gioitinh;
	int tuoi;
	Ngaysinh ngaysinh;
	Ngaynhaphoc ngaynhaphoc;
	Thongtinphuhuynh phuhuynh;
};

typedef Hocsinh HS;

void printLine(int n);
void nhapThongtinHS(HS &hs, int id);
void nhapHS(HS a[], int id,int n);
void capNhapthongtinHS(HS &hs);
void capNhapHS( HS a[],int id, int n);
int xoaTheoid(HS a[], int id, int n);
void timKiemtheoten (HS a[],char ten[], int n);
int idLonnhat(HS a[],int n);
int docFile (HS a[], char fileName[]);
void ghiFile(HS a[], int n, char fileName[]);
void pressAnyKey();
bool kiemTrangaysinh(int ngay, int thang, int nam);
void hienthiHS(HS &hs, int id);
void htHS(HS a[], int id, int n);
void delele(HS a[], int id);
int idCount = 0;
int main() {
	int key;
	char fileName[] = "hocsinh.txt"; //Biến này lưu tên tập tin mà dữ liệu sinh viên sẽ được đọc vào
	HS arrayHS[MAX];//Khai báo một mảng các phần tử thuộc kiểu SV với kích thước MAX
	int soluongHS = 0;


	//Nhập danh sách học sinh từ file
	//soluongHS = docFile(arrayHS, fileName);
	//idCount = idLonnhat(arrayHS, soluongHS);
	while (true) {
		cout << "             QUAN LY TRUONG MAM NON             \n";
		cout << "***********************MENU*********************\n";
		cout << "**  1. Them hoc sinh.                         **\n";
		cout << "**  2. Cap nhat thong tin hoc sinh boi ID.    **\n";
		cout << "**  3. Xoa hoc sinh boi ID.                   **\n";
		cout << "**  4. Tim kiem hoc sinh theo ten.            **\n";
		cout << "**  5. Sap xep hoc sinh theo ten.             **\n";
		cout << "**  6. Hien thi danh sach hoc sinh.           **\n";
		cout << "**  7. Ghi danh sach hoc sinh vao file.       **\n";
		cout << "**  8. Thoat.                                 **\n";
		cout << "************************************************\n";
		cout << "Nhap tuy chon: ";
		cin >> key;
		switch (key) {
			case 1:
				cout << "\n1. Them hoc sinh.";
				idCount ++;
				nhapHS(arrayHS, idCount,soluongHS);
				cout << "\nThem hoc sinh thanh cong!";
				soluongHS ++;
				pressAnyKey();
				break;
            case 2:
                {cout<<"\nNhap ID hoc sinh can chinh sua:";
                int newid=0;
                cin>>newid;
                nhapHS(arrayHS, newid,newid-1);
                cout<<endl<<"Sua thong tin thanh cong!";
                pressAnyKey;
                break;}
            case 3:
                {
                cout<<"\nNhap ID hoc sinh can xoa:";
                int newid;
                cin>>newid;
                delele(arrayHS,newid);
                pressAnyKey;
                break;
                }
            case 4:
                int htID;
                cout<<"\nNhap ID hoc sinh can hien thi:";
                cin>>htID;
                htHS(arrayHS,htID-1,htID-1);
                pressAnyKey;
                break;
            case 6:
                cout<<endl<<"DANH SACH LOP:"<<endl<<endl;
                for(int i=0;i<idCount;i++)
                    {htHS(arrayHS,i,i);
                    cout<<endl;}
                break;

			case 0:
				cout << "\nBan da thoat chuong trinh!";
				cin.get();
				return 0;
			default:
				cout << "\nKhong co chuc nang nay!";
				cout << "\nHay chon chuc nang trong menu.";
				pressAnyKey();
				break;
		}
	}
}
void nhapThongtinHS(HS &hs, int id) {
	hs.id = id;
	cout << "\nNhap ho va ten: ";
	cin.ignore(); //loại bỏ kí tự xuống dòng còn lại trong bộ nhớ đệm
	getline(cin,hs.hoten);
	cout << "Nhap gioi tinh: ";
	getline(cin,hs.gioitinh);
	cout << "Nhap tuoi: "; cin >> hs.tuoi;
	cout << "Sinh ngay: "; cin >> hs.ngaysinh.ng;
	cout << "     thang: "; cin >> hs.ngaysinh.th;
	cout << "     nam: "; cin >> hs.ngaysinh.na;
	//	if(kiemTrangaysinh(hs.ngaysinh.ng,hs.ngaysinh.th,hs.ngaysinh.na)) {
	//		break;
	//	}else {
	//		cout << "Ngay sinh khong hop le. Vui long nhao lai.\n";
	//	}
	cout << "Nhap thong tin phu huynh\n";
	cout << "Nhap ho ten cha: ";
	cin.ignore();
	getline(cin,hs.phuhuynh.hotencha);
	cout << "Nhap nghe nghiep cha: ";
	getline(cin,hs.phuhuynh.nghenghiepcha);
	cout << "Nhap so dien thoai cua cha: ";
	cin >> hs.phuhuynh.sdtcha;
	cout << "Nhap ho ten me: ";
	cin.ignore();
	getline(cin,hs.phuhuynh.hotenme);
	cout << "Nhap nghe nghiep me: ";
	getline(cin,hs.phuhuynh.nghenghiepme);
	cout << "Nhap so dien thoai cua me: ";
	cin >> hs.phuhuynh.stdme;
}

bool kiemTrangaysinh(int ngay, int thang, int nam) {
	if(nam < 1950 || nam > 2150) return false;
	if(thang < 1|| thang > 12) return false;
	if(ngay< 1|| ngay > 31) return false;
	bool namNhuan = (nam % 4 ==0 && nam %100!=0) || (nam % 400 == 0);
	if(thang == 2) {
		if(namNhuan) {
			return ngay <=29;
		}else {
			return ngay <= 28;
		}
	}
	if (thang ==4 || thang==6|| thang == 9|| thang ==11) {
		return ngay <=30;
	}return true;
}

void nhapHS(HS a[], int id, int n) {
	printLine(40);
    cout << "\nNhap hoc sinh thu "<<n+1;
	nhapThongtinHS(a[n],id);
	printLine(40);
}

void capNhatthongtinHS(HS &hs) {
	cout << "\nNhap ho va ten: ";
	cin.ignore(); //loại bỏ kí tự xuống dòng còn lại trong bộ nhớ đệm
	getline(cin,hs.hoten);
	cout << "Nhap gioi tinh: ";
	getline(cin,hs.gioitinh);
	cout << "Nhap tuoi: "; cin >> hs.tuoi;
	cout << "Sinh ngay: "; cin >> hs.ngaysinh.ng;
	cout << "     thang: "; cin >> hs.ngaysinh.th;
	cout << "     nam: "; cin >> hs.ngaysinh.na;
	//	if(kiemTrangaysinh(hs.ngaysinh.ng,hs.ngaysinh.th,hs.ngaysinh.na)) {
	//		break;
	//	}else {
	//		cout << "Ngay sinh khong hop le. Vui long nhao lai.\n";
	//	}
	cout << "Nhap thong tin phu huynh\n";
	cout << "Nhap ho ten cha: ";
	cin.ignore();
	getline(cin,hs.phuhuynh.hotencha);
	cout << "Nhap nghe nghiep cha: ";
	getline(cin,hs.phuhuynh.nghenghiepcha);
	cout << "Nhap so dien thoai cua cha: ";
	cin >> hs.phuhuynh.sdtcha;
	cout << "Nhap ho ten me: ";
	cin.ignore();
	getline(cin,hs.phuhuynh.hotenme);
	cout << "Nhap nghe nghiep me: ";
	getline(cin,hs.phuhuynh.nghenghiepme);
	cout << "Nhap so dien thoai cua me: ";
	cin >> hs.phuhuynh.stdme;
}




void printLine(int n) {
	cout << endl;
	for( int i = 0; i<n;i++) {
		cout << "_";
	}cout << endl;
}

void pressAnyKey() {
	cout << "\n\nBam pim bat ki de tiep tuc...";
	cin.get();
	system("cls");
}
void hienthiHS(HS &hs, int id){

    hs.id=id;
    cout << "Ho va ten: ";cout<<hs.hoten<<endl;

	cout << " Gioi tinh: ";cout<<hs.gioitinh<<endl;

	cout << "Tuoi: "; cout << hs.tuoi<<endl;
	cout << "Sinh ngay: "; cout<<hs.ngaysinh.ng<<endl;
	cout << "     thang: "; cout<< hs.ngaysinh.th<<endl;
	cout << "     nam: ";cout<< hs.ngaysinh.na<<endl;
	cout << " Thong tin phu huynh\n";
	cout << " Ho ten cha: "; cout<<hs.phuhuynh.hotencha<<endl;


	cout << " Nghe nghiep cha: ";cout<<hs.phuhuynh.nghenghiepcha<<endl;

	cout << " So dien thoai cua cha: ";
	cout << hs.phuhuynh.sdtcha<<endl;
	cout << " Ho ten me: ";

	cout<<hs.phuhuynh.hotenme<<endl;
	cout << "Nghe nghiep me: ";
	cout<<hs.phuhuynh.nghenghiepme<<endl;
	cout << " So dien thoai cua me: ";
	cout<< hs.phuhuynh.stdme<<endl;

}
void htHS(HS a[], int id, int n) {
	hienthiHS(a[n],id);
}

void delele(HS a[], int n)
{
    for(int i=n-1;i<idCount;i++)
            {a[i].hoten=a[i+1].hoten;
            a[i].gioitinh=a[i+1].gioitinh;
            a[i].tuoi=a[i+1].tuoi;
            a[i].ngaysinh.ng=a[i+1].ngaysinh.ng;
            a[i].ngaysinh.th=a[i+1].ngaysinh.th;
            a[i].ngaysinh.na=a[i+1].ngaysinh.na;
            a[i].phuhuynh.hotencha=a[i+1].phuhuynh.hotencha;
            a[i].phuhuynh.nghenghiepcha=a[i+1].phuhuynh.nghenghiepcha;
            a[i].phuhuynh.sdtcha=a[i+1].phuhuynh.sdtcha;
            a[i].phuhuynh.hotenme=a[i+1].phuhuynh.hotenme;
            a[i].phuhuynh.nghenghiepme=a[i+1].phuhuynh.nghenghiepme;
            a[i].phuhuynh.stdme=a[i+1].phuhuynh.stdme;}
}
