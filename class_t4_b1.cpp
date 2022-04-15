#include<iostream.h>
#include<iomanip.h>
class Nguoi
{
	private:
		char ht[30];
		int t;
	public:
		Nguoi()
		{
			strcpy(this->ht,"Nguyen Van A");
			t=30;
		}
		Nguoi(char *ht,int a)
		{
			strcpy(this->ht,ht);
			this->t=a;
		}
		void nhap()
		{
			cin.ignore();
			cout<<"\nNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\nNhap tuoi: ";
			cin>>t;
		}
		void xuat()
		{
			cout<<left<<setw(20)<<ht;
			cout<<left<<setw(20)<<t;
		}
	
};
class ThiSinh :public virtual Nguoi
{
	private:
		char sbd[8];
		float toan, ly, hoa;
	public:
		ThiSinh()
		{
			strcpy(this->sbd,"001");
			toan=5;
			ly=6;
			hoa=7;			
		}
		ThiSinh(char *ht,int a, char *sbd, float t, float l, float h):Nguoi(ht, t)
		{
			strcpy(this->sbd,sbd);
			this->toan=t;
			this->ly=l;
			this->hoa=h;
		}
		void nhap()
		{
			Nguoi::nhap();
			cin.ignore();
			cout<<"\nNhap so bao danh: ";
			cin.getline(sbd, 8);
			cout<<"\nNhap diem Toan: ";
			cin>>toan;
			cout<<"\nNhap diem Ly: ";
			cin>>ly;
			cout<<"\nNhap diem Hoa: ";
			cin>>hoa;	
		}
		void xuat()
		{
			Nguoi::xuat();
			cout<<left<<setw(20)<<sbd
				<<left<<setw(20)<<toan
		  		<<left<<setw(20)<<ly
 		 		<<left<<setw(20)<<hoa<<endl;
		}
		float tongdiem()
		{
			return toan+ly+hoa;
		}
		
		bool datyc()
		{
			if(toan>=5 && ly>=5 && hoa>=5)
			{
				return true;
			}else
			{
				return false;	
			}
			
		}
};

void tieude()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(20)<<left<<"Tuoi";
	cout<<setw(20)<<left<<"SBD";
	cout<<setw(20)<<left<<"Toan";
	cout<<setw(20)<<left<<"Ly";
	cout<<setw(20)<<left<<"Hoa"<<endl;
}
		
int main()
{
	int n;
	cout<<"\nNhap n= ";
	cin>>n;
	ThiSinh a[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"\nThi sinh thu "<<i+1<<": \n";
		a[i].nhap();
	}
	cout<<"\nDanh sach thi sinh: "<<endl;
	tieude();
	for(int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
	cout<<"\nDanh sach thi sinh co tong diem 3 mon tang dan: "<<endl;
	tieude();
	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++)
		if(a[i].tongdiem()>a[j].tongdiem())
		{
			ThiSinh temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}	
	for(int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
	cout<<"\nDanh sach thi sinh dat yeu cau: "<<endl;
	tieude();
	if(a[n].datyc()==true)
	{
		for(int i = 0; i < n; i++)
		{
			a[i].xuat();
		}
	}

	return 0;
}