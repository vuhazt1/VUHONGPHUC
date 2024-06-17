#include <iostream>
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
		char hotencha [30];
		char nghenghiepcha [50];
		int sdtcha;
		char hotenme [30];
		char nghenghiepme [50];
		int stdme;
};
	
struct Hocsinh {
	int id;
	char hoten [30];
	char gioitinh [5];
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
void hienThithongtinHS (HS &hs, int id);
void hienthiHS ( HS a[],int id, int n);
void xoaHS(HS a[], int id);

int main() {
	int key;
	char fileName[] = "hocsinh.txt"; //Biến này lưu tên tập tin mà dữ liệu sinh viên sẽ được đọc vào 
	HS arrayHS[MAX];//Khai báo một mảng các phần tử thuộc kiểu SV với kích thước MAX
	int soluongHS = 0;
	int idCount = 0;
	
	//Nhập danh sách học sinh từ file
	soluongHS = docFile(arrayHS, fileName);//đọc dữ liệu học sinh từ file lưu vào mảng 
	// arrayHS trả về số lượng học sinh đã đọc được
	idCount = idLonnhat(arrayHS, soluongHS);
	// Tìm ID lớn nhất trong danh sách học sinh để đảm bảo ID học sinh mới sẽ không bị trùng lặp
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
                nhapHS(arrayHS, newid,soluongHS);
                cout<<endl<<"Sua thong tin thanh cong!";
                pressAnyKey;
                break;}
            case 3:
                {
                cout<<"\nNhap ID hoc sinh can xoa:";
                int newid;
                cin>>newid;
                xoa(arrayHS,newid);
                cout << "Xoa thong tin thanh cong!";
                pressAnyKey;
                break;
                }
            case 4:
                int htID;
                cout<<"\nNhap ID hoc sinh can hien thi:";
                cin>>htID;
                HienthiHS(arrayHS,htID-1,soluongHS);
                pressAnyKey;
                break;
            case 6:
                cout<<endl<<"DANH SACH LOP:"<<endl<<endl;
                for(int i=0;i<soluongHS;i++)
                    {HienthiHS(arrayHS[i]);
                    cout<<endl;}
                break;
            case 7:
            	ghiFile(arrayHS, soluongHS,fileName);
            	cout << "Ghi danh sach hoc sinh vao file thanh cong!";
            	pressAnyKey();
            	break;
            case 8:
            	cout << "\nBan da thoat chuong trinh!";
            	return 0;
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
	cin.getline(hs.hoten,30);
	cout << "Nhap gioi tinh: "; 
	cin.getline(hs.gioitinh,5);
	cout << "Nhap tuoi: "; cin >> hs.tuoi;
	
	bool validDate = false;
	while (!validDate) {
	cout << "Sinh ngay: "; cin >> hs.ngaysinh.ng;
	cout << "     thang: "; cin >> hs.ngaysinh.th;
	cout << "     nam: "; cin >> hs.ngaysinh.na;
		if(kiemTrangaysinh(hs.ngaysinh.ng,hs.ngaysinh.th,hs.ngaysinh.na)) {
			validDate = true;
		}else {
			cout << "Ngay sinh khong hop le. Vui long nhao lai.\n";
		}
	}
	bool validDate2 = false;
	while (!validDate2) {
		cout << "Nhap hoc ngay: ";cin >> hs.ngaynhaphoc.ng;
		cout << "         thang: ";cin >> hs.ngaynhaphoc.th;
		cout << "         nam: "; cin >> hs.ngaynhaphoc.na;
		if(kiemTrangaynhaphoc(hs.ngaynhaphoc.ng,hs.ngaynhaphoc.th,hs.ngaynhaphoc.na)) {
			validDate2 = true;
		}else {
			cout << "Ngay nhap hoc khong hop le. Vui long nhap lai.\n"
		}
	}
	
	cout << "Nhap thong tin phu huynh\n";
	cout << "Nhap ho ten cha: ";
	cin.ignore();
	cin.getline(hs.phuhuynh.hotencha,30);
	cout << "Nhap nghe nghiep cha: ";
	cin.getline(hs.phuhuynh.nghenghiepcha,50);
	cout << "Nhap so dien thoai cua cha: ";
	cin >> hs.phuhuynh.sdtcha;
	cout << "Nhap ho ten me: ";
	cin.ignore();
	cin.getline(hs.phuhuynh.hotenme,30);
	cout << "Nhap nghe nghiep me: ";
	cin.getline(hs.phuhuynh.nghenghiepme,50);
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

bool kiemTrangaynhaphoc (int ngay, int thang, int nam) {
	if(nam < 1950 || nam >2050) return false;
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
	cin.getline(hs.hoten,30);
	cout << "Nhap gioi tinh: "; 
	cin.getline(hs.gioitinh,5);
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
	cin.getline(hs.phuhuynh.hotencha,30);
	cout << "Nhap nghe nghiep cha: ";
	cin.getline(hs.phuhuynh.nghenghiepcha,50);
	cout << "Nhap so dien thoai cua cha: ";
	cin >> hs.phuhuynh.sdtcha;
	cout << "Nhap ho ten me: ";
	cin.ignore();
	cin.getline(hs.phuhuynh.hotenme,30);
	cout << "Nhap nghe nghiep me: ";
	cin.getline(hs.phuhuynh.nghenghiepme,50);
	cout << "Nhap so dien thoai cua me: ";
	cin >> hs.phuhuynh.stdme;
}

void capNhatHS(HS a[],int id, int n) {
	int found = 0;
	for(int i = 0;i<n;i++) {
		if(a[i].id==id) {
			found =1;
			printLine(40);
			cout <<  "\nCap nhat thong tin hoc sinh co ID = " << id;
			capNhatthongtinHS (a[i]);
			printLine(40);
			break;
		}
	}
	if(found == 0) {
		cout << "\nHoc sinh co ID " << id <<" khong ton tai.";
	}
}

int idLonnhat (HS a[], int n) {
	int idMax=0;
	if (n>0) {
		idMax = a[0].id;
		for(int i = 0; i < n;i++) {
			if(a[i].id > idMax) {
				idMax = a[i].id;
			}
		}
	}return idMax;
}
//?
int docFile(HS a[],char fileName[]) {
	FILE * fp;
	int i = 0;
	fp = fopen (fileName,"r");
	cout << "Chuan bi doc file: "; puts(fileName);
	//doc thong tin sinh vien 
	while (fscanf(fp,"%5d%30s%5s%5d\n",
			&a[i].id,&a[i].hoten,&a[i].gioitinh,&a[i].tuoi)!=EOF) {
		i++;
		cout << "Doc ban ghi thu: "<< i << endl;
	}
	cout << "So luong hoc sinh co san trong file la: "<< i << endl;
	cout << endl;
	fclose (fp);
	//trả về số lượng sinh viên đọc từ file 
	return i;
}
//?
void ghiFile (HS a[], int n, char fileName[]) {
	FILE * fp;
	fp = fopen(fileName,"w");
	for (int i = 0;i<n;i++) {
		fprintf(fp,"%5d%30s%5s%5d\n",&a[i].id,&a[i].hoten,&a[i].gioitinh,&a[i].tuoi);
	}
	fclose (fp);
}

void hienThiHS(HS &hs, int id){
    hs.id=id;
    cout << "Ho va ten: ";cout<<hs.hoten<<endl;
	cout << "Gioi tinh: ";cout<<hs.gioitinh<<endl;
	cout << "Tuoi: "; cout << hs.tuoi<<endl;
	cout << "Sinh ngay: "; cout<<hs.ngaysinh.ng<<endl;
	cout << "     thang: "; cout<< hs.ngaysinh.th<<endl;
	cout << "     nam: ";cout<< hs.ngaysinh.na<<endl;
	cout << "Thong tin phu huynh\n";
	cout << "Ho ten cha: "; cout<<hs.phuhuynh.hotencha<<endl;
	cout << "Nghe nghiep cha: ";cout<<hs.phuhuynh.nghenghiepcha<<endl;
	cout << "So dien thoai cua cha: ";
	cout << hs.phuhuynh.sdtcha<<endl;
	cout << "Ho ten me: ";
	cout<<hs.phuhuynh.hotenme<<endl;
	cout << "Nghe nghiep me: ";
	cout<<hs.phuhuynh.nghenghiepme<<endl;
	cout << "So dien thoai cua me: ";
	cout<< hs.phuhuynh.stdme<<endl;
}

void hienThithongtinHS( HS a[], int id, int n) {
	printLine(40);
	cout << "\nHien thi thong tin hoc sinh thu: " << n+1;
	hienThithongtinHS(a[n],id);
	printLine(40);
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
	cout << "\n\n\n\n\n";
}