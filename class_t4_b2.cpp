#include<iostream.h>
#include<iomanip.h>
class SP
{
	private:
		char ma[5];
		char ten[20];
		int nam;
	public:
		SP(char *ma =" ", char *ten=" ", int nam=0)
		{
			strcpy(this->ma, ma);
			strcpy(this->ten, ten);
			this->nam=nam;
		}
		void nhap()
		{
			cin.ignore();
			cout<<"\nNhap ma san pham: ";
			cin.getline(ma, 5);
			cout<<"\nNhap ten san pham: ";
			cin.getline(ten, 20);
			cout<<"\nNhap nam san pham: ";
			cin>>nam;
		}
		void xuat()
		{
			cout<<left<<setw(20)<<this->ma
					  <<setw(20)<<this->ten
					  <<setw(20)<<this->nam;
		}
};
class TV :public virtual SP
{
	private:
		int dai, rong;
	public:
		TV(char *ma =" ", char *ten=" ", int nam=0, int dai=0, int rong=0)
		:SP(ma, ten, nam)
		{
			this->dai=dai;
			this->rong=rong;
		}
		void nhap()
		{
			SP::nhap();
			cout<<"\nNhap chieu dai: ";
			cin>>dai;
			cout<<"\nNhap chieu rong: ";
			cin>>rong;
		}
		void xuat()
		{
			SP::xuat();
			cout<<left<<setw(20)<<this->dai
					  <<setw(20)<<this->rong<<endl;	
		}
		float dientich()
		{
			return dai*rong;
		}
};
void tieude()
{
	cout<<setw(20)<<left<<"Ma";
	cout<<setw(20)<<left<<"Ten";
	cout<<setw(20)<<left<<"Nam";
	cout<<setw(20)<<left<<"Chieu dai";
	cout<<setw(20)<<left<<"Chieu rong"<<endl;
}
int main()
{
	int n;
	cout<<"\nNhap n= ";
	cin>>n;
	TV tv[n];
	for(int i=0; i<n; i++ )
	{
		cout<<"\nNhap ti vi thu "<<i+1<<endl;
		tv[i].nhap();
	}
	cout<<"\nDanh sach: "<<endl;
	tieude();
	for(int i = 0; i < n; i++)
	{
		tv[i].xuat();
	}
	
	cout<<"\nSap xep theo dien tich man hinh tang dan: "<<endl;
	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++)
	{
		if(tv[i].dientich()>tv[j].dientich())
		{
			TV temp=tv[i];
			tv[i]=tv[j];
			tv[j]=temp;
		}
	}
	tieude();
	for(int i = 0; i < n; i++)
	{
		tv[i].xuat();
	}
	return 0;
}