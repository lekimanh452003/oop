#include<iostream.h>
#include<iomanip.h>
class AnPham
{
	private:
		char ten[30];
		int gia;
	public:
		AnPham(char * ten=" ", int gia=0)
		{
			strcpy(this->ten,ten);
			this->gia=gia;
		}
		void input()
		{
			cin.ignore();
			cout<<"\nNhap ten: ";
			cin.getline(ten, 30);
			cout<<"\nNhap gia thanh: ";
			cin>>gia;
		}
		void display()
		{
			cout<<left<<setw(20)<<this->ten
					  <<setw(20)<<this->gia;
		}
};
class Sach :public virtual AnPham
{
	private:
		int page;
	public:
		Sach(char * ten=" ", int gia=0, int page=0):AnPham(ten,gia)
		{
			this->page=page;
		}
		void input()
		{
			AnPham::input();
			cout<<"\nNhap so trang: ";
			cin>>page;
		}
		void display()
		{
			AnPham::display();
			cout<<left<<setw(20)<<this->page<<endl;
		}
		bool tim()
		{
			if(page > 500)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class CD :public virtual AnPham
{
	private:
		int phut;
	public:
		CD(char * ten=" ", int gia=0, int phut):AnPham(ten, gia)
		{
			this->phut=phut;
		}
		void input()
		{
			AnPham::input();
			cout<<"\nNhap so phut: ";
			cin>>phut;
		}
		void display()
		{
			AnPham::display();
			cout<<left<<setw(20)<<this->phut<<endl;
		}
};
int main()
{
	int n;
	cout<<"\nNhap n =";
	cin>>n;
	Sach s[n];
	for(int i=0; i< n; i++)
	{
		cout<<"\nNhap quyen sach thu "<<i+1<<endl;
		s[i].input();
	}
	
	cout<<"\nDanh sach cac quyen sach: "<<endl;
	for(int i=0; i< n; i++)
	{
		s[i].display();
	}
	cout<<"\nDanh sach cac quyen sach co trang> 500: "<<endl;
	for(int i=0; i< n; i++)
	if(s[i].tim()==true)
	
		{
			s[i].display();
		}
	return 0;
}