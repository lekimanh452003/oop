#include <iostream.h>
#include <iomanip.h>
#include <math.h>
class GV
{
	private:
		 char ht[30]; // ho ten
		 char cn[20]; // chuyen nganh
		 float bl; // bac luong
	public:
		//ham khoi tao
		GV(char *ht=" ",char *cn=" ", float bl = 0)
		{
			strcpy(this->ht,ht);
			strcpy(this->cn, cn);
			this->bl=bl;
		}
		~GV(){};
		void nhap()
		{
			cin.ignore();
			cout<<"\tNhap ho ten: ";cin.getline(this->ht,30);
			cout<<"\tNhap chuyen nganh: ";cin.getline(this->cn, 20);
			cout<<"\tNhap bac luong: ";cin>>this->bl;
		}
		void xuat()
		{
			cout<<left<<setw(20)<<this->ht
					  <<setw(20)<<this->cn
					  <<setw(20)<<this->bl;
		}
		friend class GVTH;	 			
};
class GVTH : public virtual GV
{
	private:
		char lop[5];
		float lpc; //luong phu cap
	public:
		GVTH(char *ht=" ",char *cn=" ", float bl = 0, char *lop= " ",float lpc=0)
		:GV(ht, cn, bl)
		{
			strcpy(this->lop,lop);
			this->lpc=lpc;	
		}
		~GVTH(){};
		void nhap()
		{
			GV::nhap();
			cin.ignore();
			cout<<"\tNhap lop: ";cin.getline(this->lop,5);
			cout<<"\tNhap luong phu cap: ";cin>>this->lpc;
		}
		void xuat()
		{
			GV::xuat();
			cout<<left<<setw(20)<<this->lop
					  <<setw(20)<<this->lpc<<endl;
		}
		float luongpc()
		{
			lpc=0.5*1150*bl;
			return lpc;
		}
		float tienluong()
		{
			return 1150*bl+lpc;
		}
		
};
void tieude1()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"Chuyen nganh";
	cout<<setw(20)<<left<<"Bac luong";
	cout<<setw(20)<<left<<"Lop";
	cout<<setw(20)<<left<<"Luong phu cap"<<endl;
}
void sapxep(GVTH gvt[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n;j++)
		{
			if(gvt[i].tienluong()>gvt[j].tienluong())
			{
				GVTH temp=gvt[i];
				gvt[i]=gvt[j];
				gvt[j]=temp;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"\nNhap so luong giao vien: ";
	cin>>n;
	GV *gv = new GV[n];
	cout<<"\nNhap thong tin giao vien: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nGiao vien thu " <<i+1<<endl;
		gv[i].nhap();
	}
	cout<<"\nXuat danh sach giao vien: "<<endl;
	for(int i=0; i<n; i++)
	{
		gv[i].xuat();
	}
	int m;
	GVTH *gvt =new GVTH[n];
	cout<<"\nNhap thong tin giao vien tieu hoc: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"\nGiao vien thu "<<i+1<<endl;
		gvt[i].nhap();
	}
	cout<<"\nDanh sach giao vien theo thu tu tang dan cua tien luong:"<<endl;
	tieude1();
	sapxep(gvt, n);
	for(int i=0; i<n; i++)
	{
		gvt[i].xuat();
	}
}