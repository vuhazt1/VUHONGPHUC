#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

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
				string toString() const {
					return to_string(day) + '/' + to_string(month) + to_string(year);
				}
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
				string tieusubenhtat;//Tiêu sử bệnh tật
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
			//them vecto vào
			//vector<HocSinh> danhSachHocSinh;
		};
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
				};/*   private:
        map<string, vector<Chitietsuckhoe>> suckhoe;
        map<string, Chedoan> chedoan;
        map<string, vector<Baocaosuckhoe>> baocaosuckhoe;*/
		};
		
};



class Truongmamnon {
	private:
		admin hieutruong;
	public:
		string getAdminUsername() const {
			return hieutruong.getUsername();
		}
		string getAdminPassword() const {
			return hieutruong.getPassword();
		}
};

int main () {
	Truongmamnon hust;
	int dangnhap = 0;
	string username, password;
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