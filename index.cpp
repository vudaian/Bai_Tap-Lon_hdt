#include "iostream"
#include "fstream"
#include "cstring"
#include "math.h"
#include "conio.h"
#include "string.h"
#include "cstdlib"
#include "iomanip"
#include "vector"
using namespace std;
#define MAX 100
int countSach = 0;
int countNhanVien = 0;
int countUser = 0;
int countMuonTra = 0;
int x = 1;
int w = 15; 
class Sach;
class NhanVien;

void check(string &s) {
	if(s[0]>=97) {
		s[0]=s[0]-32;
	}
	else {
		s[0]=s[0];
	}
}
string viet_hoa(string &s) {
	vector<string> v;
	stringstream ss(s);
	string temp;
	while(ss>>temp) {
		check(temp);
		v.push_back(temp);
	}
	string a;
	for(int i=0;i<v.size();i++) {
		a=a+v[i]+" ";
	}
	return a;
}

//Khai báo lớp Sach
class Sach {
	public:
		string maSach;
		string tenSach;
		string chuDe;
		string tacGia;
		string nhaXuatBan;
		string ngayXuatBan;
	public:
		friend istream & operator>>(istream & is, Sach &s) {
            cout<<">> Nhap ma sach: ";
            fflush(stdin);
            getline(cin,s.maSach);
            
            cout<<">> Nhap ten sach: ";
            fflush(stdin);
            getline(cin,s.tenSach);
            
            cout<<">> Nhap chu de: ";
            fflush(stdin);
            getline(cin,s.chuDe);
            
            cout<<">> Nhap tac gia: ";
            fflush(stdin);
            getline(cin,s.tacGia);
            
            cout<<">> Nhap nha xuat ban: ";
            fflush(stdin);
            getline(cin,s.nhaXuatBan);
            
            cout<<">> Nhap ngay xuat ban: ";
            fflush(stdin);
            getline(cin,s.ngayXuatBan);
            return is;
        }
		friend ostream & operator<<(ostream & os, Sach &s) {
            cout<<char(186)<<setw(w)<< s.maSach <<setw(w)<<char(186)<<setw(w)<< s.tenSach <<setw(w)<<char(186)<<setw(w)<<s.chuDe<<setw(w)<<char(186)<<setw(w)<<viet_hoa(s.tacGia)<<setw(w)<<char(186)<<setw(w)<< s.nhaXuatBan <<setw(w)<<char(186)<<setw(w)<<s.ngayXuatBan<<setw(w)<<char(186)<< endl;
	        return os;
        }
		Sach() {
			maSach = "";
			tenSach = "";
			chuDe = "";
			tacGia = "";
			nhaXuatBan = "";
			ngayXuatBan = "";
		}
		~Sach(){}
    public:
        //Thêm, hiển thị, tìm kiếm, xóa, sửa
        void themSach();
        void hienThiSach();
        void suaSach();
        void xoaSachTheoMaSach();
        void timKiemSach();
        int luuFileSach();
        int docFileSach();
};
Sach s[MAX];

void Sach :: themSach() {
    char C;
    do {
        cout << "\nNhap thong tin sach thu " << countSach + 1 << endl;
        cin >> s[countSach];    
        countSach++;
        cout << "Ban co muon them sach nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch(); 
    } while (C != 'k');
    luuFileSach();
}
//Hiển thị
void Sach :: hienThiSach() {
    cout<<char(186)<<setw(w)<< "Ma sach" <<setw(w)<<char(186)<<setw(w)<< "Ten sach" <<setw(w)<<char(186)<<setw(w)<< "Chu de" <<setw(w)<<char(186)<<setw(w)<< "Tac gia" <<setw(w)<<char(186)<<setw(w)<< "Nha xuat ban" <<setw(w)<<char(186)<<setw(w)<<"Ngay xuat ban"<<setw(w)<<char(186)<< endl;
    for (int i = 0; i < countSach; i++) {
        cout << s[i];
    }
}
//Sửa
void Sach :: suaSach() {
    string newMa;
    char C;
    int dem = 0;
    if (countSach == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma sach can sua: ";
        fflush(stdin);
        getline(cin,newMa);
        for (int i = 0; i < countSach; i++) {
            if (s[i].maSach == newMa) {
                cout<<">> Sua ten sach: ";
                fflush(stdin);
                getline(cin,s[i].tenSach);
                
                cout << ">> Sua chu de: ";
                fflush(stdin);
                getline(cin,s[i].chuDe);
                
                cout << ">> Sua tac gia: ";
                fflush(stdin);
                getline(cin,s[i].tacGia);
                
                cout << ">> Sua nha xuat ban: ";
                fflush(stdin);
                getline(cin,s[i].nhaXuatBan);
                
                cout << ">> Sua ngay xuat ban: ";
                fflush(stdin);
                getline(cin,s[i].ngayXuatBan);
                dem++;
            }
        }
        if(dem == 0) {
            cout << "Khong tim thay sach nao co ma sach la " << newMa << endl;
        }
        cout << "Ban co muon sua sach nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileSach();
}
//Xóa
void Sach :: xoaSachTheoMaSach() {
    string delMa;
    char C;
    int d = 0;
    if (countSach == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma sach can xoa: ";
        fflush(stdin);
        getline(cin,delMa);
        for (int i = 0; i < countSach; i++) {
            if (s[i].maSach == delMa) {
                s[i] = s[i + 1];
                countSach--;
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay sach nao co ma sach la " << delMa << endl;
        }
        cout << "Ban co muon xoa sach nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileSach();
}
//Tìm kiếm
void Sach :: timKiemSach() {
    string str;
    char C;
    int d = 0;
    if (countSach == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma sach can tim: ";
        fflush(stdin);
        getline(cin,str);
        for (int i = 0; i < countSach; i++) {
            if (s[i].maSach == str) {
                cout << "\tSach co ma sach la " << str << endl;
                cout<<char(186)<<setw(w)<< "Ma sach" <<setw(w)<<char(186)<<setw(w)<< "Ten sach" <<setw(w)<<char(186)<<setw(w)<< "Chu de" <<setw(w)<<char(186)<<setw(w)<< "Tac gia" <<setw(w)<<char(186)<<setw(w)<< "Nha xuat ban" <<setw(w)<<char(186)<<setw(w)<<"Ngay xuat ban"<<setw(w)<<char(186)<< endl;
                cout << s[i];
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay sach nao co ma sach la " << str << endl;
        }
        cout << "Ban co muon tim kiem sach nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
} 
//Lưu file
int Sach :: luuFileSach() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseSach";
    ofstream file;
    file.open(fileName, ios::out);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    };
    file << countSach << endl;
    for (int i = 0; i < countSach; i++) {
        file << s[i].maSach << "," << s[i].tenSach << "," << s[i].chuDe << "," << s[i].tacGia << "," << s[i].nhaXuatBan << "," << s[i].ngayXuatBan << endl;
    }
    file.close();
    return 1;
}
//Đọc file
int Sach :: docFileSach() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseSach";
    ifstream file;
    file.open(fileName, ios::in);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    }
    file >> countSach;
    int i = 0;
    while(i < countSach) {
        if (i == 0) {
            file.ignore();
        }
        getline(file, s[i].maSach, ',');
        getline(file, s[i].tenSach, ',');
        getline(file, s[i].chuDe, ',');
        getline(file, s[i].tacGia, ',');
        getline(file, s[i].nhaXuatBan, ',');
        getline(file, s[i].ngayXuatBan);
        i++;
    }
    file.close();
    return 1;
}

//////////////////////////////////////Lớp Nguoi

class Nguoi {
    public:
        string id;
        string ten;
    Nguoi() {
        id = "";
        ten = "";
    }
    ~Nguoi() {}
};

//////////////////////////////////////Lớp NhanVien

class NhanVien : public Nguoi {
    public:
        string sdt;
        string diaChi;
    public:
        friend istream & operator>>(istream & is, NhanVien &n) {
            cout<<">> Nhap ma nhan vien: ";
            fflush(stdin);
            getline(cin,n.id);
            
            cout<<">> Nhap ten nhan vien: ";
            fflush(stdin);
            getline(cin,n.ten);
            
            cout<<">> Nhap so dien thoai: ";
            fflush(stdin);
            getline(cin,n.sdt);

            cout<<">> Nhap dia chi: ";
            fflush(stdin);
            getline(cin,n.diaChi);
            return is;
        }
		friend ostream & operator<<(ostream & os, NhanVien &n) {
            cout<<char(186)<<setw(w)<< n.id <<setw(w)<<char(186)<<setw(w)<< n.ten <<setw(w)<<char(186)<<setw(w)<<n.sdt<<setw(w)<<char(186)<<setw(w)<<n.diaChi<<setw(w)<<char(186)<< endl;
	        return os;
        }
        NhanVien() {
            sdt = "";
            diaChi = "";
        }
        ~NhanVien() {}
    public:
    //Thêm, hiển thị, tìm kiếm, xóa, sửa
        void themNhanVien();
        void hienThiNhanVien();
        void suaNhanVien();
        void xoaNhanVienTheoMaNhanVien();
        void timKiemNhanVien();
        int luuFileNhanVien();
        int docFileNhanVien();
};  
NhanVien n[MAX];

void NhanVien :: themNhanVien() {
    char C;
    do {
        cout << "\nNhap thong tin nhan vien thu " << countNhanVien + 1 << endl;
        cin >> n[countNhanVien];    
        countNhanVien++;
        cout << "Ban co muon them nhan vien nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch(); 
    } while (C != 'k');
    luuFileNhanVien();
}
//Hiển thị
void NhanVien :: hienThiNhanVien() {
    cout<<char(186)<<setw(w)<< "Ma nhan vien" <<setw(w)<<char(186)<<setw(w)<< "Ten nhan vien" <<setw(w)<<char(186)<<setw(w)<< "SDT" <<setw(w)<<char(186) << setw(w)<< "Dia chi" <<setw(w)<<char(186)<< endl;
    for (int i = 0; i < countNhanVien; i++) {
        cout << n[i];
    }
}
//Sửa
void NhanVien :: suaNhanVien() {
    string newID;
    char C;
    int dem = 0;
    if (countNhanVien == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nhan vien can sua: ";
        fflush(stdin);
        getline(cin,newID);
        for (int i = 0; i < countNhanVien; i++) {
            if (n[i].id == newID) {
                cout<<">> Sua ten nhan vien: ";
                fflush(stdin);
                getline(cin,n[i].ten);
                
                cout << ">> Sua so dieb thoai nhan vien: ";
                fflush(stdin);
                getline(cin,n[i].sdt);
                
                cout << ">> Sua dia chi nhan vien: ";
                fflush(stdin);
                getline(cin,n[i].diaChi);
                dem++;
            }
        }
        if(dem == 0) {
            cout << "Khong tim thay nhan vien nao co ma nhan vien la " << newID << endl;
        }
        cout << "Ban co muon sua nhan vien nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileNhanVien();
}
//Xóa
void NhanVien :: xoaNhanVienTheoMaNhanVien() {
    string delID;
    char C;
    int d = 0;
    if (countNhanVien == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nhan vien can xoa: ";
        fflush(stdin);
        getline(cin,delID);
        for (int i = 0; i < countNhanVien; i++) {
            if (n[i].id == delID) {
                n[i] = n[i + 1];
                countNhanVien--;
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay nhan vien nao co ma sach la " << delID << endl;
        }
        cout << "Ban co muon xoa nhan vien nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileNhanVien();
}
//Tìm kiếm
void NhanVien :: timKiemNhanVien() {
    string str;
    char C;
    int d = 0;
    if (countNhanVien == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nhan vien can tim: ";
        fflush(stdin);
        getline(cin,str);
        for (int i = 0; i < countNhanVien; i++) {
            if (n[i].id == str) {
                cout << "\tNhan vien co ma nhan vien la " << str << endl;
                cout<<char(186)<<setw(w)<< "Ma nhan vien" <<setw(w)<<char(186)<<setw(w)<< "Ten nhan vien" <<setw(w)<<char(186)<<setw(w)<< "SDT" <<setw(w)<<char(186) << setw(w)<< "Dia chi" <<setw(w)<<char(186)<< endl;
                cout << n[i];
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay nhan vien nao co ma sach la " << str << endl;
        }
        cout << "Ban co muon tim kiem nhan vien nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
}
//Lưu file
int NhanVien :: luuFileNhanVien() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseNhanVien";
    ofstream file;
    file.open(fileName, ios::out);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    };
    file << countNhanVien << endl;
    for (int i = 0; i < countNhanVien; i++) {
        file << n[i].id << "," << n[i].ten << "," << n[i].sdt << "," << n[i].diaChi << endl;
    }
    file.close();
    return 1;
}
//Đọc file
int NhanVien :: docFileNhanVien() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseNhanVien";
    ifstream file;
    file.open(fileName, ios::in);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    }
    file >> countNhanVien;
    int i = 0;
    while(i < countNhanVien) {
        if (i == 0) {
            file.ignore();
        }
        getline(file, n[i].id, ',');
        getline(file, n[i].ten, ',');
        getline(file, n[i].sdt, ',');
        getline(file, n[i].diaChi);
        i++;
    }
    file.close();
    return 1;
}

//////////////////////////////////////Lớp User

class User : public Nguoi {
    public:
        string username;
        string password;
    public:
        friend istream & operator>>(istream & is, User &u) {
            cout<<">> Nhap ma nguoi dung: ";
            fflush(stdin);
            getline(cin,u.id);

            cout<<">> Nhap ten nguoi dung: ";
            fflush(stdin);
            getline(cin,u.ten);
            
            cout<<">> Nhap tai khoan: ";
            fflush(stdin);
            getline(cin,u.username);
            
            cout<<">> Nhap mat khau: ";
            fflush(stdin);
            getline(cin,u.password);

            return is;
        }
		friend ostream & operator<<(ostream & os, User &u) {
            cout<<char(186)<<setw(w)<< u.id <<setw(w)<<char(186)<<setw(w)<< u.ten <<setw(w)<<char(186)<<setw(w)<<u.username<<setw(w)<<char(186)<<setw(w)<<u.password<<setw(w)<<char(186)<< endl;
	        return os;
        }
        User() {
            username = "";
            password = "";
        }
        ~User() {}
        void themUser();
        void hienThiUser();
        void suaUser();
        void xoaUserTheoMaUser();
        void timKiemUser();
        int luuFileUser();
        int docFileUser();
        void loginU();
};
User u[MAX];

void menuDocGia() {
	Sach arrBook;
    arrBook.docFileSach();
	int select;
	do
	{
		cout <<"\n";
		cout << "           * UNG DUNG QUAN LY THU VIEN *           " << endl;
        cout << "+------------------------MENU-------------------------+" << endl;
        cout << "|     1. Hien thi danh sach sach co trong thu vien    |" << endl;
        cout << "|     2. Tim kiem thong tin sach bang ma sach         |" << endl;
        cout << "|     0. Thoat chuong trinh                           |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>select;
        switch(select) {
        	case 1:
                cout << "\tDanh sach sach co trong thu vien" << endl;
                arrBook.hienThiSach();
        		break;
			case 2:
				cout << "\tTim kiem sach trong thu vien" << endl;
				arrBook.timKiemSach();
        		break;
            case 0: break;
			default: cout << "Khong co chuc nang nay! Hay nhap lai!" << endl;
		}
	} while(select != 0);
}

void User :: loginU() {
    docFileUser();
    int cnt= 0;
    string taiKhoan;
    string matKhau;
    fflush(stdin);
    cout << "\nNhap tai khoan nguoi dung: ";
    getline(cin, taiKhoan);
    cout << "Nhap mat khau nguoi dung: ";
    getline(cin, matKhau);
    for(int i=0; i < countUser; i++) {
        if (u[i].username == taiKhoan && u[i].password == matKhau) {
            menuDocGia();   
            cnt++;
        }
    }
    if(cnt == 0) cout << "Tai khoan hoac mat khau sai!" << endl;
}

void User :: themUser() {
    char C;
    do {
        cout << "\nNhap thong tin nguoi dung thu " << countUser + 1 << endl;
        cin >> u[countUser];    
        countUser++;
        cout << "Ban co muon them nguoi dung nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch(); 
    } while (C != 'k');
    luuFileUser();
}
//Hiển thị
void User :: hienThiUser() {
    cout<<char(186)<<setw(w)<< "Ma nguoi dung" <<setw(w)<<char(186)<<setw(w)<< "Ten nguoi dung" <<setw(w)<<char(186)<<setw(w)<< "Tai khoan" <<setw(w)<<char(186)<<setw(w)<< "Mat khau" <<setw(w)<<char(186)<< endl;
    for (int i = 0; i < countUser; i++) {
        cout << u[i];
    }
}
//Sửa
void User :: suaUser() {
    string newID;
    char C;
    int dem = 0;
    if (countUser == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nguoi dung can sua: ";
        fflush(stdin);
        getline(cin,newID);
        for (int i = 0; i < countUser; i++) {
            if (u[i].id == newID) {
                cout<<">> Sua ten nguoi dung: ";
                fflush(stdin);
                getline(cin,u[i].ten);
                
                cout << ">> Sua tai khoan: ";
                fflush(stdin);
                getline(cin,u[i].username);
                
                cout << ">> Sua mat khau: ";
                fflush(stdin);
                getline(cin,u[i].password);
                dem++;
            }
        }
        if(dem == 0) {
            cout << "Khong tim thay nhan vien nao co ma nhan vien la " << newID << endl;
        }
        cout << "Ban co muon sua nhan vien nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileUser();
}
//Xóa
void User :: xoaUserTheoMaUser() {
    string delID;
    char C;
    int d = 0;
    if (countUser == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nguoi dung can xoa: ";
        fflush(stdin);
        getline(cin,delID);
        for (int i = 0; i < countUser; i++) {
            if (u[i].id == delID) {
                u[i] = u[i + 1];
                countUser--;
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay nguoi dung nao co ma sach la " << delID << endl;
        }
        cout << "Ban co muon xoa nguoi dung nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileUser();
}
//Tìm kiếm
void User :: timKiemUser() {
    string str;
    char C;
    int d = 0;
    if (countUser == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma nguoi dung can tim: ";
        fflush(stdin);
        getline(cin,str);
        for (int i = 0; i < countUser; i++) {
            if (u[i].id == str) {
                cout << "\tNguoi dung co ma nguoi dung la " << str << endl;
                cout<<char(186)<<setw(w)<< "Ma nguoi dung" <<setw(w)<<char(186)<<setw(w)<< "Ten nguoi dung" <<setw(w)<<char(186)<<setw(w)<< "Tai khoan" <<setw(w)<<char(186)<<setw(w)<< "Mat khau" <<setw(w)<<char(186)<< endl;
                cout << u[i];
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay nguoi dung nao co ma sach la " << str << endl;
        }
        cout << "Ban co muon tim kiem nguoi dung nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
}
//Lưu file
int User :: luuFileUser() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseUser";
    ofstream file;
    file.open(fileName, ios::out);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    };
    file << countUser << endl;
    for (int i = 0; i < countUser; i++) {
        file << u[i].id << "," << u[i].ten << "," << u[i].username << "," << u[i].password << endl;
    }
    file.close();
    return 1;
}
//Đọc file
int User :: docFileUser() {
    string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseUser";
    ifstream file;
    file.open(fileName, ios::in);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    }
    file >> countUser;
    int i = 0;
    while(i < countUser) {
        if (i == 0) {
            file.ignore();
        }
        getline(file, u[i].id, ',');
        getline(file, u[i].ten, ',');
        getline(file, u[i].username, ',');
        getline(file, u[i].password);
        i++;
    }
    file.close();
    return 1;
}


////////////////////////////////////////Lớp MuonTra

class MuonTra{
	public:
		string maMuonTra;
		string dateMuon;
		string dateTra;
		string tenNguoi;
	public:
		MuonTra()
		{
			maMuonTra ="";
			dateMuon = "";
			dateTra ="";
			tenNguoi="";
		}
		friend istream & operator>>(istream & is, MuonTra &mt)
		{
            cout<<">> Nhap ma muon tra: ";
            fflush(stdin);
            getline(cin,mt.maMuonTra);
            
            cout<<">> Nhap ten muon: ";
            fflush(stdin);
            getline(cin,mt.tenNguoi);
            
            cout<<">> Nhap ngay muon: ";
            fflush(stdin);
            getline(cin,mt.dateMuon);

            cout<<">> Nhap ngay tra: ";
            fflush(stdin);
            getline(cin,mt.dateTra);

			return is;
		}
		friend ostream & operator<<(ostream & os, MuonTra &mt)
		{
			cout<<char(186)<<setw(w)<< mt.maMuonTra <<setw(w)<<char(186)<<setw(w)<< mt.tenNguoi <<setw(w)<<char(186)<<setw(w)<<mt.dateMuon<<setw(w)<<char(186)<<setw(w)<<mt.dateTra<<setw(w)<<char(186)<< endl;
			return os;
		}
		void themMuonTra();
		void hienthiMuonTra();
		void suaMuonTra();
		void timkiemMuonTra();
		void xoaMuonTra();
		void luuFileMuonTra();
		void docFileMuonTra();
		~MuonTra(){}
};
MuonTra mt[MAX];
void MuonTra::themMuonTra()
{
	char C;
    do {
        cout << "\nNhap thong tin muon tra thu " << countMuonTra + 1 << endl;
        cin >> mt[countMuonTra];    
        countMuonTra++;
        cout << "Ban co muon them muon tra nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch(); 
    } while (C != 'k');
    luuFileMuonTra();
}
void MuonTra::hienthiMuonTra() {
    cout<<char(186)<<setw(w)<< "Ma muon tra" <<setw(w)<<char(186)<<setw(w)<< "Ten nguoi muon" <<setw(w)<<char(186)<<setw(w)<< "Ngay muon" <<setw(w)<<char(186)<<setw(w)<< "Ngay tra" <<setw(w)<<char(186)<<endl;
    for(int i=0;i<countMuonTra;i++)
    {
        cout << mt[i];
    }
}
void MuonTra::suaMuonTra() {
	string newID;
    char C;
    int dem = 0;
    if (countMuonTra == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma muon tra can sua: ";
        fflush(stdin);
        getline(cin,newID);
        for (int i = 0; i < countMuonTra; i++) {
            if (mt[i].maMuonTra == newID) {
                cout<<">> Sua ten nguoi: ";
                fflush(stdin);
                getline(cin,mt[i].tenNguoi);
                
                cout << ">> Sua ngay muon: ";
                fflush(stdin);
                getline(cin,mt[i].dateMuon);
                
                cout << ">> Sua ngay tra: ";
                fflush(stdin);
                getline(cin,mt[i].dateTra);
                dem++;
            }
        }
        if(dem == 0) {
            cout << "Khong tim thay nhan vien nao co ma muon tra la " << newID << endl;
        }
        cout << "Ban co muon sua muon tra nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileMuonTra();
}
void MuonTra::timkiemMuonTra()
{
	string str;
    char C;
    int d = 0;
    if (countMuonTra == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma muon tra can tim: ";
        fflush(stdin);
        getline(cin,str);
        for (int i = 0; i < countMuonTra; i++) {
            if (mt[i].maMuonTra == str) {
                cout << "\tNguoi thue la " << str << endl;
                cout<<char(186)<<setw(w)<< "Ma sach" <<setw(w)<<char(186)<<setw(w)<< "Ten nguoi" <<setw(w)<<char(186)<<setw(w)<< "Ngay muon" <<setw(w)<<char(186)<<setw(w)<<"Ngay tra"<<setw(w)<<char(186)<< endl;
                cout << mt[i];
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay sach nao co ma sach la " << str << endl;
        }
        cout << "Ban co muon tim kiem sach nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
}
void MuonTra::xoaMuonTra() {
	string delID;
    char C;
    int d = 0;
    if (countMuonTra == 0) {
        cout << "Danh sach rong!!!";
    }
    else {
        do {
        cout << "Nhap ma muon tra can xoa: ";
        fflush(stdin);
        getline(cin,delID);
        for (int i = 0; i < countMuonTra; i++) {
            if (mt[i].maMuonTra == delID) {
                mt[i] = mt[i + 1];
                countMuonTra--;
                d++;
            }
        }
        if(d == 0) {
            cout << "Khong tim thay muon tra nao co ma muon tra la " << delID << endl;
        }
        cout << "Ban co muon xoa muon tra nua khong? Nen muon ban co the bam phim bat ky, neu khong ban bam phim (k)" << endl;
        C = getch();
        } while (C != 'k');
    }
    luuFileMuonTra();
}
void MuonTra::luuFileMuonTra()
{
	string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseMuonTra";
    ofstream file;
    file.open(fileName, ios::out);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    };
    file << countMuonTra << endl;
    for (int i = 0; i < countMuonTra; i++) {
        file << mt[i].maMuonTra << "," << mt[i].tenNguoi << "," << mt[i].dateMuon << "," << mt[i].dateTra << endl;
    }
    file.close();
}
void MuonTra::docFileMuonTra()
{
	string fileName = "D://Workspace//C C++//Bai_Tap-Lon_hdt/databaseMuonTra";
    ifstream file;
    file.open(fileName, ios::in);
    if(!file.is_open()) {
        cout << "Error opening!";
        exit(1);
    }
    file >> countMuonTra;
    int i = 0;
    while(i < countMuonTra) {
        if (i == 0) {
            file.ignore();
        }
        getline(file, mt[i].maMuonTra, ',');
        getline(file, mt[i].tenNguoi, ',');
        getline(file, mt[i].dateMuon, ',');
        getline(file, mt[i].dateTra);
        i++;
    }
    file.close();
}


void menuSach()
{
	Sach arrBook;
    arrBook.docFileSach();
	int selectSach;
	do
	{
		cout <<"\n";
		cout << "           * UNG DUNG QUAN LY THU VIEN *           " << endl;
        cout << "+------------------------MENU-------------------------+" << endl;
        cout << "|     1. Them sach                                    |" << endl;
        cout << "|     2. Hien thi danh sach sach co trong thu vien    |" << endl;
        cout << "|     3. Sua thong tin sach bang ma sach              |" << endl;
        cout << "|     4. Tim kiem thong tin sach bang ma sach         |" << endl;
        cout << "|     5. Xoa thong tin sach bang ma sach              |" << endl;
        cout << "|     0. Thoat chuong trinh                           |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>selectSach;
        switch(selectSach) {
        	case 1:
                system("cls");
				cout << "\tNhap du lieu cho sach moi:\n";
				arrBook.themSach();
	            cout << "\nNhap sach moi thanh cong" << endl;
                system("cls");
        		break;
        	case 2:
                cout << "\tDanh sach sach co trong thu vien" << endl;
                arrBook.hienThiSach();
        		break;
        	case 3:
                system("cls");
                cout << "\tSua sach trong thu vien" << endl;
                arrBook.suaSach();
                system("cls");
        		break;
			case 4:
                system("cls");
				cout << "\tTim kiem sach trong thu vien" << endl;
				arrBook.timKiemSach();
                system("cls");
        		break;
			case 5:
                system("cls");
				cout << "\tXoa sach trong thu vien" << endl;
				arrBook.xoaSachTheoMaSach();
                system("cls");
        		break;
            case 0: break;
			default: cout << "Chua co chuc nang nay! Hay nhap lai!" << endl;
		}
	}while(selectSach != 0);
}

void menuUser() {
	User arrUser;
    arrUser.docFileUser();
	int selectUser;
	do 
	{
		cout <<"\n";
		cout << "           * UNG DUNG QUAN LY THU VIEN *           " << endl;
        cout << "+------------------------MENU-------------------------+" << endl;
        cout << "|     1. Them nguoi dung                              |" << endl;
        cout << "|     2. Hien thi danh sach nguoi dung                |" << endl;
        cout << "|     3. Sua thong tin sach bang ma nguoi dung        |" << endl;
        cout << "|     4. Tim kiem thong tin sach bang ma nguoi dung   |" << endl;
        cout << "|     5. Xoa thong tin sach bang ma nguoi dung        |" << endl;
        cout << "|     0. Thoat chuong trinh                           |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>selectUser;
        switch(selectUser) {
        	case 1:
                system("cls");
				cout << "\tNhap du lieu cho nguoi dung moi:\n";
				arrUser.themUser();
	            cout << "\nNhap nguoi dung moi thanh cong" << endl;
                system("cls");
        		break;
        	case 2:
                cout << "\tDanh sach nguoi dung co trong thu vien" << endl;
                arrUser.hienThiUser();
        		break;
        	case 3:
                system("cls");
                cout << "\tSua nguoi dung trong thu vien" << endl;
                arrUser.suaUser();
                system("cls");
        		break;
			case 4:
                system("cls");
				cout << "\tTim kiem nguoi dung trong thu vien" << endl;
				arrUser.timKiemUser();
                system("cls");
        		break;
			case 5:
                system("cls");
				cout << "\tXoa nguoi dung trong thu vien" << endl;
				arrUser.xoaUserTheoMaUser();
                system("cls");
        		break;
            case 0: break;
			default: cout << "Chua co chuc nang nay! Hay nhap lai!" << endl;
		}
	}while(selectUser != 0);
}

void menuNhanVien() {
	NhanVien arrNhanVien;
    arrNhanVien.docFileNhanVien();
	int selectNhanVien;
	do
	{
		cout <<"\n";
		cout << "                    * QUAN LY NHAN VIEN *                  " << endl;
        cout << "+---------------------------MENU---------------------------+" << endl;
        cout << "|     1. Them nhan vien                                    |" << endl;
        cout << "|     2. Hien thi danh sach nhan vien co trong thu vien    |" << endl;
        cout << "|     3. Sua thong tin nhan vien bang ma nhan vien         |" << endl;
        cout << "|     4. Tim kiem thong tin nhan vien bang ma nhan vien    |" << endl;
        cout << "|     5. Xoa thong tin nhan vien bang ma nhan vien         |" << endl;
        cout << "|     0. Thoat chuong trinh                                |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>selectNhanVien;
        switch(selectNhanVien) {
        	case 1:
                system("cls");
				cout << "\tNhap du lieu cho nhan vien moi:\n";
				arrNhanVien.themNhanVien();
	            cout << "\nNhap nhan vien moi thanh cong" << endl;
                system("cls");
        		break;
        	case 2:
                cout << "\tDanh nhan vien nhan vien co trong thu vien" << endl;
                arrNhanVien.hienThiNhanVien();
        		break;
        	case 3:
                system("cls");
                cout << "\tSua nhan vien trong thu vien" << endl;
                arrNhanVien.suaNhanVien();
                system("cls");
        		break;
			case 4:
                system("cls");
				cout << "\tTim kiem nhan vien trong thu vien" << endl;
				arrNhanVien.timKiemNhanVien();
                system("cls");
        		break;
			case 5:
                system("cls");
				cout << "\tXoa nhan vien trong thu vien" << endl;
				arrNhanVien.xoaNhanVienTheoMaNhanVien();
                system("cls");
        		break;
            case 0: break;
			default: cout << "Chua co chuc nang nay! Hay nhap lai!" << endl;
		}
	} while(selectNhanVien != 0);
}

void menuMuonTra()
{
	MuonTra arrMuonTra;
    arrMuonTra.docFileMuonTra();
	int selectMuonTra;
	do
	{
		cout <<"\n";
		cout << "                     * UNG DUNG QUAN LY THU VIEN *           " << endl;
        cout << "+---------------------------------MENU------------------------------+" << endl;
        cout << "|     1. Them nguoi thue sach                                       |" << endl;
        cout << "|     2. Hien thi danh sach nguoi thue sach co trong thu vien       |" << endl;
        cout << "|     3. Sua thong tin nguoi thue sach bang ma nguoi thue sach      |" << endl;
        cout << "|     4. Tim kiem thong tin nguoi thue sach bang ma nguoi thue sach |" << endl;
        cout << "|     5. Xoa thong tin nguoi thue sach bang ma nguoi thue sach      |" << endl;
        cout << "|     0. Thoat chuong trinh                                         |" << endl;
        cout << "+-------------------------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>selectMuonTra;
        switch(selectMuonTra) {
        	case 1:
                system("cls");
				cout << "\tNhap du lieu cho nguoi thue sach moi:\n";
				arrMuonTra.themMuonTra();
	            cout << "\nNhap nguoi thue sach moi thanh cong" << endl;
                system("cls");
        		break;
        	case 2:
                cout << "\tDanh nguoi thue sach nguoi thue sach co trong thu vien" << endl;
                arrMuonTra.hienthiMuonTra();
        		break;
        	case 3:
                cout << "\tSua nguoi thue sach trong thu vien" << endl;
                arrMuonTra.suaMuonTra();
        		break;
			case 4:
				cout << "\tTim kiem nguoi thue sach trong thu vien" << endl;
				arrMuonTra.timkiemMuonTra();
        		break;
			case 5:
				cout << "\tXoa nguoi thue sach trong thu vien" << endl;
				arrMuonTra.xoaMuonTra();
        		break;
            case 0: break;
			default: cout << "Chua co chuc nang nay! Hay nhap lai!" << endl;
		}
	}while(selectMuonTra != 0);
}

void menuAdmin() {
    int selectAdmin;
    do {
        system("cls");
        cout << "\n";
        cout << "                * CHUC NANG CUA ADMIN *               " << endl; 
        cout << "+------------------------MENU-------------------------+" << endl;
        cout << "|     1. Quan ly sach                                 |" << endl;
        cout << "|     2. Quan ly nhan vien                            |" << endl;
        cout << "|     3. Quan ly nguoi dung                           |" << endl;
        cout << "|     4. Quan ly muon tra                             |" << endl;
        cout << "|     0. Thoat chuong trinh                           |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "\n>> Chon chuc nang: ";
        cin>>selectAdmin;
        switch(selectAdmin) {
            case 1: 
                system("cls");
                menuSach();
                break;
            case 2:
                system("cls");
                menuNhanVien();
                break;
            case 3: 
                system("cls");
                menuUser();
                break;
            case 4: 
                system("cls");
                menuMuonTra();
                break;
            case 0: exit(1);
            default: cout << "Khong co chuc nang nay! Hay nhap lai!" << endl;
        }   

    } while (selectAdmin != 0);
}

void loginUser() {
    User a;
    a.loginU();
}   

void loginAdmin() {
    string taiKhoan;
    string matKhau;
    fflush(stdin);
    cout << "\nNhap tai khoan nguoi quan ly: ";
    getline(cin, taiKhoan);
    cout << "Nhap mat khau nguoi quan ly: ";
    getline(cin, matKhau);
    if (taiKhoan == "admin" && matKhau == "admin") {
        menuAdmin();
    }
    else cout << "Error: Tai khoan hoac mat khau khong chinh xac\n";
}

void menuLogin() {
    int select;
    do {
        cout << "\n";
        cout << "Dang nhap" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "\n >> Chon cap dang nhap: "; cin >> select;
        switch (select) {
            case 1: 
                loginAdmin();
                break;
            case 2: 
                loginUser();
                break;
        } 
    } while (select != 0);
}

int main() {
    menuLogin();
    return 0;
}