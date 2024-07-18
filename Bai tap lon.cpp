#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

const int MAX_HOCSINH = 1000;

class admin  {
	private:
		string const username = "1";
		string const password = "1";
	public:
		admin () {
		}
		string getUsername() const {
			return username;
		}
		string getPassword() const {
			return password;
		}
};


class Quanlyhocsinh {
	public:
		class Thongtinhocsinh {
			public:
				struct Ngaysinh  { 
					int day;
					int month;
					int year;
					//Phương thức 'toString()' kết hợp các giá trị ngày tháng năm thành một chuỗi định dạng (DD/MM/YYYY)
					string toString() const {
						return to_string(day) + '/' + to_string(month) + to_string(year);
					}//to_string(day): chuyển đổi giá trị của 'day' từ int sang string
				};
				struct Ngaynhaphoc { 
					int day;
					int month;
					int year;
					string toString() const {
						return to_string(day) + '/' + to_string(month) + to_string(year);
					}
				};
				struct Phuhuynh {
					string hoten ;
					string nghenghiep ;
					int sdt;
					string email ;
				};
				struct Hosoyte {
					int cannang;
					int chieucao;
					string tieusubenhtat;//Tiểu sử bệnh tật
					string diung;//Dị ứng 
					string hosotiemchung;//Hồ sơ tiêm chủng 
				};
				struct Hocsinh {
					int id;
					string hoten ;
					string gioitinh ;
					int tuoi;
					Ngaysinh ngaysinh;
					Ngaynhaphoc ngaynhaphoc;
					string diachi ;
					string quequan ;
					Phuhuynh bo;
					Phuhuynh me;
					Hosoyte yte;
				};	
				vector<Hocsinh> danhsachHocsinh;
				//Một vector chứa các đối tượng 'Hocsinh', lưu trữ danh sách tất cả các học sinh
			};
			Thongtinhocsinh thongtinhocsinh;
				bool kiemTrangaysinh(int day, int month, int year) {
					if(year <1950||year >2150) return false;
					if(month<1||month>12) return false;
					if(day<1||day>31) return false;
					bool namNhuan = (year%4==0&&year%100!=0) ||(year%400==0);
					if(month==2) {
						if(namNhuan) {
							return day<=29;
						}else {
							return day <=28;
						}
					}
					if(month ==4||month==6||month==9||month==11) {
						return day <=30;
					}
					return true;
				}
				bool kiemTrangaynhaphoc(int day, int month, int year) {
					return kiemTrangaysinh(day,month,year);
				}
				
				void nhapThongtinHS(Thongtinhocsinh::Hocsinh &hs, int id) {
					hs.id=id;
					cout << "\nNhap ho va ten: ";
					cin.ignore();//Loại bỏ kí tự xuống dòng còn lại trong bộ nhớ đệm
					getline(cin,hs.hoten);
					cout << "Nhap gioi tinh: ";
					getline(cin,hs.gioitinh);
					cout << "Nhap tuoi: ";
					cin >> hs.tuoi;
					
					bool validDate = false;
					while (!validDate) {
						cout << "Sinh ngay: ";cin >> hs.ngaysinh.day;
						cout << "     thang:c";cin>> hs.ngaysinh.month;
						cout << "     nam: ";cin>>hs.ngaysinh.year;
						if(kiemTrangaysinh(hs.ngaysinh.day,hs.ngaysinh.month,hs.ngaysinh.year)) {
							validDate =true;
						}else {
							cout << "Ngay sinh khong hop le. Vui long nhap lai.\n";
						}
					}
			
			bool validDate2 = false;
			while (!validDate2) {
				cout << "Nhap hoc ngay: ";cin >> hs.ngaynhaphoc.day;
				cout << "         thang: ";cin >> hs.ngaynhaphoc.month;
				cout << "         nam: ";cin >>hs.ngaynhaphoc.year;
				if(kiemTrangaynhaphoc(hs.ngaynhaphoc.day,hs.ngaynhaphoc.month,hs.ngaynhaphoc.year)) {
					validDate=true;
				}else {
					cout << "Ngay nhap hoc khong hop le. Vui long nhap lai.\n";
				}
			}
			cout << "Nhap dia chi: ";
			getline(cin,hs.diachi);
			cout << "Nhap que quan: ";
			getline(cin,hs.quequan);
			cout << "Nhap thong tin phu huynh\n";
			cout << "Nhap ho ten cha: ";
			cin.ignore();
			getline(cin,hs.bo.hoten);
			cout <<"Nhap nghe nghiep cha: ";
			getline(cin,hs.bo.nghenghiep);
			cout << "Nhap so dien thoai cua cha: ";
			cin>>hs.bo.sdt;
			cout << "Nhap email cua cha: ";
			cin>>hs.bo.email;
			cout <<"Nhap ho ten me: ";
			cin.ignore();
			getline(cin,hs.me.hoten);
			cout << "Nhap nghe nghiep me: ";
			cin >> hs.me.nghenghiep;
			cout << "Nhap so dien thoai cua me: ";
			cin>> hs.me.sdt;
			cout << "Nhap email cua me: ";
			cin >> hs.me.email;
			cin.ignore();
		}
		
		void nhapHosoyte(Quanlyhocsinh::Thongtinhocsinh::Hocsinh &hs) {
			cout << "Nhap thong tin ho so y te: \n";
			cout << "Nhap can nang: "; cin>>hs.yte.cannang;
			cout << "Nhap chieu cao: ";cin >> hs.yte.chieucao;
			cin.ignore();
			cout << "Nhap tieu su benh tat: ";
			getline(cin,hs.yte.tieusubenhtat);
			cout << "Nhap di ung: ";
			getline(cin,hs.yte.diung);
			cout << "Nhap ho so tiem chung: ";
			getline(cin,hs.yte.hosotiemchung);
		}
		
		void themHocsinh(Quanlyhocsinh::Thongtinhocsinh &qlhs,int id) {
			Quanlyhocsinh::Thongtinhocsinh::Hocsinh hs;
			nhapThongtinHS(hs,id);
			
			char choice;
			cout << "Ban co muon nhap thong tin cho ho so y te (y/n)? ";
			cin >> choice;
			if(choice == 'y'||choice == 'Y') {
				nhapHosoyte(hs);
			}
			qlhs.danhsachHocsinh.push_back(hs);
			cout << "Da them hoc sinh thanh cong!";
		}
		
		class Suckhoe {
			public:
				struct Ngaytheodoi {
					int day;
					int month;
					int year;
					string toString() const {
						return to_string(day) + '/' + to_string(month) + to_string(year);
					}
				};	
				struct Chitietsuckhoe {
					Ngaytheodoi ngaytheodoi;
					string tinhtrang;
					string ghichu;
				};
				struct Chedoan {
					string buoisang;
					string buoitrua;
					string buoichieu;
				};
				struct Ngaybaocao {
					int day;
					int month;
					int year;
					string toString() const {
						return to_string(day) + '/' + to_string(month) + to_string(year);
					}
				};
				struct Baocaosuckhoe {
					Ngaybaocao ngaybaocao;
					string noidung;
				};
        map<string, vector<Chitietsuckhoe>> suckhoe;
        //Một map lưu trữ thông tin chi tiết sức khỏe của học sinh, key là tên học học sinh, value là một vector các đối tượng 'Chitietsuckhoe'
        map<string, Chedoan> chedoan;
        map<string, vector<Baocaosuckhoe>> baocaosuckhoe;
		};
		
};


class date {
	private:
		int day,month,year;
	public:
		date(int d=0,int m=0,int y =0) {
			day =d;
			month = m;
			year=y;
		}
		void setDay(int d) {
			day =d;
		}
		void setMonth (int m) {
			month = m;
		}
		void setYear(int y) {
			year =y;
		}
		int getDay() const {
			return day;
		}
		int getMonth() const {
			return month;
		}
		int getYear() const {
			return year;
		}
};

class Truongmamnon {
	private:
		admin hieutruong;
		date ngay;
	public:
		string getAdminUsername() const {
			return hieutruong.getUsername();
		}
		string getAdminPassword() const {
			return hieutruong.getPassword();
		}
		void setDate() {
			int day, month, year;
			cout << "\nNhap ngay: ";
			cin >> day;
			ngay.setDay(day);
			cout << "\nNhap thang: ";
			cin >> month;
			ngay.setMonth(month);
			cout << "\nNhap nam: ";
			cin >> year;
			ngay.setYear(year);
		}
};

int main () {
	Truongmamnon hust;
	Quanlyhocsinh huster;
	int dangnhap = 0;
	string username, password;
	cout << "Nhap ngay hom nay\n";
	hust.setDate();
	system("cls");
	cout << "*************************************************\n";
	cout << "**                                             **\n";
	cout << "**                                             **\n";
	cout << "**              HE THONG QUAN LY               **\n";
	cout << "**               TRUONG MAM NON                **\n";
	cout << "**                                             **\n";
	cout << "**                                             **\n";
	cout << "*************************************************\n";
	cout << "An phim bat ky de tiep tuc...\n";
	_getwch();
	system("cls");
	cout << "*************************************************\n";
	cout << "**                                             **\n";
	cout << "**                                             **\n";
	cout << "**           BAN TRUY CAP VOI TU CACH LA       **\n";
	cout << "**           1) Quan tri vien                  **\n";
	cout << "**           2) Giao vien                      **\n";
	cout << "**           3) Phu huynh                      **\n";
	cout << "**                                             **\n";
	cout << "**                                             **\n";
	cout << "*************************************************\n";
	cin >> dangnhap;
	system("cls");
	switch (dangnhap) {
		case 1:
			cout << " ______________________________________ \n";
			cout << "                                        \n";
			cout << "                                        \n";
			cout << "              - Dang nhap -             \n";
			cout << "            Username:";cin >> username;
			cout << "            Password:";cin >> password;
			cout << "                                        \n";
			cout << " ______________________________________ \n";
			if ((hust.getAdminUsername()== username) && (hust.getAdminPassword()== password)) {
				system("cls");
				int adminOption = 0;
				cout << "******************************************************\n";
				cout << "**                                                  **\n";
				cout << "**             Lua chon muc muon truy cap           **\n";
				cout << "**   1) Quan ly hoc sinh                            **\n";
				cout << "**   2) Quan ly lop hoc                             **\n";
				cout << "**   3) Quan ly giao vien va nhan vien              **\n";
				cout << "**   4) Quan ly tai lieu va chuong trinh hoc        **\n";
				cout << "**   5) Giao tiep voi phu huynh                     **\n";
				cout << "**   6) Quan ly tai chinh                           **\n";
				cout << "**   7) Quan ly co so vat chat                      **\n";
				cout << "**   8) Bao cao phan tich                           **\n";
				cout << "**                                                  **\n";
				cout << "******************************************************\n";
				cin >> adminOption;
				system("cls");
				switch (adminOption) {
					case 1:
						int key1;
						while (true) {
							cout << "              QUAN LY HOC SINH              \n";
							cout << "*********************MENU*********************\n";
							cout << "**  1. Them hoc sinh.                       **\n";
							cout << "**  2. Cap nhat thong tin hoc sinh boi ID.  **\n";
							cout << "**  3. Xoa hoc sinh boi ID.                 **\n";
							cout << "**  4. Tim kiem hoc sinh theo ten.          **\n";
							cout << "**  5. Sap xep hoc sinh theo ten.           **\n";
							cout << "**  6. Hien thi danh sach hoc sinh.         **\n";
							cout << "**  7. Ghi danh sach hoc sinh vào file .    **\n";
							cout << "**  8. Thoat.                               **\n";
							cout << "**********************************************\n";
							cout << "Nhap tuy chon: ";
							cin >> key1;
							switch(key1) {
								case 1:
									cout << "\n1. Them hoc sinh.";
									int id;
									cout << "Nhap ID hoc sinh moi: ";
									cin >>id;
									huster.themHocsinh(huster.thongtinhocsinh,id);
									break;
								case 2:
									cout << "\n2. Cap nhat thong tin hoc sinh.";
									break;
								case 3: 
									break;
								case 4:
									break;
								case 5:
									break;
								case 6:
									break;
								default:
									cout << "Khong co chuc nang nay. Vui long nhap lai!";
										
							}
						}
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						cout << "\nKhong co chuc nang nay, vui long chon lai!"<< endl;
						break;
				}
			}
			else {
				cout << "Thong tin dang nhap khong hop le, an phim bat ki de thu lai!";
				_getwch();
				system("cls");
				//adminlogin
			}break;
		case 2:
			//cout <<
			break;
		case 3:
			break;
		default:
			cout << "Lua chon khong hop le, vui long chon lai!\n";	
			//them 
			break;
	}
	return 0;
}