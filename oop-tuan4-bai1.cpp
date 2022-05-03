#include <iostream.h>
#include <iomanip.h>
#include <string.h>
class NGUOI
{
	private:
		char ht[30]; // Ho ten
		char scm[10]; //So chung minh
		char gt[3]; //
	public:
		NGUOI() // ham khoi tao co tham so
		{
			strcpy(this->ht, "Le Kim Anh");
			strcpy(this->scm,"073615032");
			strcpy(this->gt,"nu");
		}	
		NGUOI(char *ht, char *scm, char *gt) //Ham khoi tao khong tham so
		{
			strcpy(this->ht,ht);
			strcpy(this->scm,scm);
			strcpy(this->gt,gt);	
		}
		~NGUOI(){}; // ham huy
		void nhap()
		{
			cin.ignore();
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);
			cout<<"\tNhap so chung minh: ";cin.getline(this->scm,10);
			cout<<"\tNhap gioi tinh: ";cin.getline(this->gt,3);
		}
		void xuat()
		{
			cout<<left<<setw(20)<<this->ht;
			cout<<left<<setw(20)<<this->scm;
			cout<<left<<setw(20)<<this->gt;
		}
};
class HS : public virtual NGUOI
{
	private:
		char cn[20]; //Chuyen nganh
		float dtk; // Diem tong ket
	public:
		HS() // ham khoi tao co tham so
		{
			strcpy(this->cn, "CNTT");
			dtk=3.8;
		}	
		HS(char *ht, char *scm, char *gt, char *cn,float dkt):NGUOI(ht,scm,gt)
		{
			strcpy(cn, cn);
			dtk=dkt;
		}
		~HS(){};
		void nhap()
		{
			NGUOI::nhap();
			cin.ignore();
			cout<<"\tNhap chuyen nganh: ";cin.getline(this->cn,20);
			cout<<"\tNhap diem tong ket: ";cin>>this->dtk;

		}
		void xuat()
		{
			NGUOI::xuat();
			cout<<left<<setw(20)<<this->cn;
			cout<<left<<setw(20)<<this->dtk<<endl;
		}
		bool operator >(const HS &hs)
		{
			return(this->dtk > hs.dtk);
		}
		void sapxep()
		{
			if(dtk>=0 && dtk <=4.9)
			{
				cout<<"\nYeu";
			}else if(dtk>=5 && dtk <=7.9)
			{
				cout<<"\nKha";
			}else
			{
				cout<<"\nGioi";
			}
		}
};
void tieude1()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"So chung minh";
	cout<<setw(20)<<left<<"Gioi tinh"<<endl;
}
void tieude2()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"So chung minh";
	cout<<setw(20)<<left<<"Gioi tinh";
	cout<<setw(20)<<left<<"Chuyen nghanh";
	cout<<setw(20)<<left<<"Diem tong ket"<<endl;
}
int main()
{
	int n;
	cout<<"\nNhap so luong nguoi = ";
	cin>>n;
	NGUOI a[n];
	for(int i=0; i<n; i++)
	{
		cout<<"\nThong tin nguoi thu "<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\nDanh sach nguoi: "<<endl;
	tieude1();
	for(int i=0; i<n; i++)
	{
		a[i].xuat();
	}
	int m;
	cout<<"\nNhap so luong hs: ";
	cin>>m;
	HS b[m];
	for(int i = 0; i < m; i++)
	{
		cout<<"\nThong tin hs thu "<<i+1<<endl;
		b[i].nhap();
	}
	cout<<"\nXuat giao vien: "<<endl;
	tieude2();
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiao vien thu "<<i + 1<<": \n";
		b[i].xuat();
	}
}