#include <bits/stdc++.h>
// #include<time.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=  1e9+ 7;
#define endl "\n"
#define eps 1e-7
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define vpi vector<pi>
#define vi vector<ll>
#define pi pair<ll,ll>
#define mk make_pair
#define pb push_back
#define ppb pocatalback
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<ll>>
#define minheap priority_queue<ll,vi,greater<ll>>
#define maxheap priority_queue<ll>
#define minheapi priority_queue<pi,vpi,greater<pi>>
#define maxheapi priority_queue<pi>
#define IOS iosupplierbase::syncustomerwith_stdio(0); cin.tie(0);
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i,a,b) for(i=a;i<b;i++)
#define deb1(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deblp(i, a, n) fo(i, n){cout << a[i] << " ";}
#define clr(x,a) memset(x, a, sizeof(x))
#define fills(a,val) fill_n(a, sizeof(a)/sizeof(a[0]), val)
#define sq(x) ((x)*(x))

ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x*(y/gcd(x,y)); }
ll modd(ll a){return (a%mod + mod)%mod;}
double findMod(double a, double b)
{
    double mods;
    if (a < 0)
        mods = -a;
    else
        mods =  a;
    if (b < 0)
        b = -b;
    while (mods >= b)
        mods = mods - b;
    if (a < 0)
        return -mods;
    return mods;
}
ll add(ll a,ll b){return modd(modd(a)+modd(b));}
ll mul(ll a,ll b){return modd(modd(a)*modd(b));}
int smask(int i,int pos){ return (i|(1<<pos)); }
int clmask(int i,int pos){return (i&(~(1<<pos))) ; }
bool chmask(int i,int pos){return (i&(1<<pos))!=0 ;}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(sq(a.first-b.first)+sq(a.second-b.second));}

long long binpow(long long a, long long b) {
    if (b <= 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return mul(mul(res, res), a);
    else
        return mul(res,res);
}
// to find (a/b)mod m{m is a prime}
//(a/b)mod m == a*(a^-1)mod m == a*binpow(b,m-2)

// long long ncr(long long a,long long b)
// {
//     // precalc factorial
//     return mul(fact[a],binpow(mul(fact[b],fact[a-b]),mod-2) );
// }

//ll prime[60];
//int posx[10];
//int posy[10];
//int price[30];
//char board[26][26];
// int dx[]={-1,1,0,0};//N,S,w,E
// int dy[]={0,0,-1,1};
using namespace std;

class customer
{
	int customerid;
	char customername[30];
	int customerage;
	char customergender[7];
	char customercity[30];
	long int customermobillno;
	public: void getdata();
		void putdata();
		void customeradd();
		void customershow_full();
		void customerdelete();
		void customersearch();
		void customerupdate();
};

void customer :: getdata()
{
	cout<<endl<<"Enter Customer's id: ";
	cin>>customerid;
	cout<<"Enter Customer's name: ";
	cin>>customername;
	cout<<"Enter Customer's age: ";
	cin>>customerage;
	cout<<"Enter Customer's gender: ";
	cin>>customergender;
	cout<<"Enter Customer's city: ";
	cin>>customercity;
	cout<<"Enter Customer's contact no.: ";
	cin>>customermobillno;
}

void customer :: putdata()
{
	cout<<endl<<"Customer's id is "<<customerid;
	cout<<endl<<"Customer's name is "<<customername;
	cout<<endl<<"Customer's age is "<<customerage;
	cout<<endl<<"Customer's gender is "<<customergender;
	cout<<endl<<"Customer's city is "<<customercity;
	cout<<endl<<"Customer's contact no is "<<customermobillno;
}

class supplier
{
        int supplierid;
        char suppliername[30];
        int supplierage;
        char suppliergender[7];
        char suppliercity[30];
        long int suppliermobillno;
        public: void getdata();
                void putdata();
                void supplieradd();
		void suppliershow_full();
		void supplierdelete();
		void suppliersearch();
		void supplierupdate();
};

void supplier :: getdata()
{
        cout<<endl<<"Enter Supplier's id: ";
        cin>>supplierid;
        cout<<"Enter Supplier's name: ";
        cin>>suppliername;
        cout<<"Enter Supplier's age: ";
        cin>>supplierage;
        cout<<"Enter Supplier's gender: ";
        cin>>suppliergender;
        cout<<"Enter Supplier's city: ";
        cin>>suppliercity;
        cout<<"Enter Supplier's contact no.: ";
	cin>>suppliermobillno;
}

void supplier :: putdata()
{
        cout<<endl<<"Supplier's id is "<<supplierid;
        cout<<endl<<"Supplier's name is "<<suppliername;
        cout<<endl<<"Supplier's age is "<<supplierage;
        cout<<endl<<"Supplier's gender is "<<suppliergender;
        cout<<endl<<"Supplier's city is "<<suppliercity;
        cout<<endl<<"Supplier's contact no is "<<suppliermobillno;
}

class bill
{
        int billid;
        char billname[30];
        char billcity[30];
        long int billmobillno;
        char billdate[10];
	long int billtotal_amt;
	public: void getdata();
                void putdata();
                void billadd();
		void billshow_full();
		void billdelete();
		void billsearch();
		void billupdate();
};

void bill :: getdata()
{
        cout<<endl<<"Enter Bill's id: ";
        cin>>billid;
        cout<<"Enter Bill's name: ";
        cin>>billname;
        cout<<"Enter Bill owner's city: ";
        cin>>billcity;
        cout<<"Enter Bill owner's contact no.: ";
        cin>>billmobillno;
	cout<<"Enter date of Bill creation: ";
	cin>>billdate;
	cout<<"Enter total amount: ";
	cin>>billtotal_amt;
}

void bill :: putdata()
{
        cout<<endl<<"Bill's id is "<<billid;
        cout<<endl<<"Bill's name is "<<billname;
        cout<<endl<<"Bill owner's city is "<<billcity;
        cout<<endl<<"Bill owner's contact no. is "<<billmobillno;
        cout<<endl<<"Bill's Date of creation is "<<billdate;
	cout<<endl<<"Bill's Total amount is "<<billtotal_amt;
}

class catalogue
{
        int catalid;
        char catalname[30];
        long int catalprice;
        public: void getdata();
                void putdata();
                void cataladd();
		void catalshow_full();
		void cataldelete();
		void catalsearch();
		void catalupdate();
};

void catalogue :: getdata()
{
        cout<<endl<<"Enter Product's id: ";
        cin>>catalid;
        cout<<"Enter Product's name: ";
	cin>>catalname;
        cout<<"Enter Product's price: ";
        cin>>catalprice;
}

void catalogue :: putdata()
{
        cout<<endl<<"Product's id is "<<catalid;
        cout<<endl<<"Product's name is "<<catalname;
        cout<<endl<<"Product's price is "<<catalprice;
}

class shopping_cart
{
        public: //void getdata();
                //void putdata();
                void customerscustomeradd();
                void customerscustomershow_full();
                void customerscustomerdelete();
                //void customerscustomersearch();
};

/*void shopping_cart :: getdata()
{
        cout<<endl<<"Enter Product's id: ";
        cin>>scustomerid;
        cout<<"Enter Product's name: ";
        cin>>scustomername;
        cout<<"Enter Product's price: ";
        cin>>scustomerprice;
}

void shopping_cart :: putdata()
{
        cout<<endl<<"Product's id is "<<scustomerid;
        cout<<endl<<"Product's name is "<<scustomername;
        cout<<endl<<"Product's price is "<<scustomerprice;
}*/




void start_screen();
void owner_menu();
void customer_menu();
void default_msg_for_switch();
void customermenu();
void suppliermenu();
void billmenu();
void ownercatalogue();


int owner_authen()
{
	char ownerusername[20],ownerpassword[20];
	char owneruser[20]="username",ownerpass[20]="password";
	cout<<endl<<endl;
	cout.width(25);
	cout<<"Enter Owner's";
	cout<<endl<<setw(34)<<"username: ";
	cin>>ownerusername;
	cout<<setw(34)<<"password: ";
	cin>>ownerpassword;
	if(strcmp(ownerusername, owneruser)==0 && strcmp(ownerpassword, ownerpass)==0)
		return 1;
	else
		return 0;
}

void default_msg_for_switch()
{
	cout<<"Invalid Choice!!";
}

void customer :: customersearch()
{
	const int N=200;
        char line[N];
	cout<<endl<<endl<<"Welcome Sir to the world's fastest Search Section...	!!";
	cout<<endl<<"Enter customer id, of which you want to get details: ";
	int id_se,x;
	cin>>id_se;
	ifstream fin1("customer");
	while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j==id_se)
                {
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<setw(55)<<"Search SUCCESSFULL";
			cout<<endl<<endl<<endl<<setw(60)<<"********CANTEEN MANAGEMENT SYSTEM********";
		        cout<<endl<<setw(54)<<"CUSTOMER DATABASE";
		        cout<<endl<<endl<<setw(5)<<"ID"<<setw(16)<<"NAME"<<setw(15)<<"AGE"<<setw(16)<<"GENDER"<<setw(20)<<"CITY"<<setw(18)<<"CONTACT";
			cout<<endl<<endl<<line<<endl;
                        x=1;
                }
        }
	fin1.close();
	if(x!=1)
		cout<<endl<<endl<<"Sorry Sir... But Unfortunately, you had entered customer id that is not listed!!!";
}

void supplier :: suppliersearch()
{
        const int N=200;
        char line[N];
        cout<<endl<<endl<<"Welcome Sir to the world's fastest Search Section... !!";
        cout<<endl<<"Enter supplier's id, of which you want to get details: ";
        int id_se,x;
        cin>>id_se;
        ifstream fin1("supplier");
        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j==id_se)
                {
                        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<setw(55)<<"Search SUCCESSFULL";
                        cout<<endl<<endl<<endl<<setw(60)<<"********COMPUTER SHOP********";
                        cout<<endl<<setw(54)<<"SUPPLIER DATABASE";
                        cout<<endl<<endl<<setw(5)<<"ID"<<setw(16)<<"NAME"<<setw(15)<<"AGE"<<setw(16)<<"GENDER"<<setw(20)<<"CITY"<<setw(18)<<"CONTACT";
                        cout<<endl<<endl<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        if(x!=1)
                cout<<endl<<endl<<"Sorry Sir... But Unfortunately, you had entered supplier id that is not listed!!!";
}

void bill :: billsearch()
{
        const int N=200;
        char line[N];
        cout<<endl<<endl<<"Welcome Sir to the world's fastest Search Section... !!";
        cout<<endl<<"Enter bill's id, of which you want to get details: ";
        int id_se,x;
        cin>>id_se;
        ifstream fin1("bill");
        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j==id_se)
                {
                        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<setw(55)<<"Search SUCCESSFULL";
                        cout<<endl<<endl<<endl<<setw(60)<<"********COMPUTER SHOP********";
                        cout<<endl<<setw(50)<<"BILL DATABASE";
                        cout<<endl<<endl<<setw(5)<<"ID"<<setw(16)<<"NAME"<<setw(18)<<"CITY"<<setw(16)<<"CONTACT NO."<<setw(13)<<"DATE"<<setw(28)<<"TOTAL AMOUNT";
                        cout<<endl<<endl<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        if(x!=1)
                cout<<endl<<endl<<"Sorry Sir... But Unfortunately, you had entered bill id that is not listed!!!";
}

void catalogue :: catalsearch()
{
        const int N=200;
        char line[N];
        cout<<endl<<endl<<"Welcome Sir to the world's fastest Search Section... !!";
        cout<<endl<<"Enter product's id, of which you want to get details: ";
        int id_se,x;
        cin>>id_se;
        ifstream fin1("catalogue");
        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j==id_se)
                {
                        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<setw(55)<<"Search SUCCESSFULL";
                        cout<<endl<<endl<<endl<<setw(60)<<"********COMPUTER SHOP********";
                        cout<<endl<<setw(50)<<"CATALOGUE";
                        cout<<endl<<endl<<setw(5)<<"ID"<<setw(50)<<"NAME"<<setw(30)<<"PRICE";
                        cout<<endl<<endl<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        if(x!=1)
                cout<<endl<<endl<<"Sorry Sir... But Unfortunately, you had entered product id that is not listed!!!";
}





void customer :: customeradd()
{
	int pos;
	getdata();
	ofstream fout;
	//int i;
	fout.open("customer",ios::app);
	/*if(i!=10)
	{
	fout<<endl<<setw(50)<<"********COMPUTER SHOP********";
	fout<<endl<<setw(44)<<"CUSTOMER DATABASE";
	fout<<endl<<endl<<setw(5)<<"ID"<<setw(16)<<"NAME"<<setw(15)<<"AGE"<<setw(16)<<"GENDER"<<setw(20)<<"CITY"<<setw(18)<<"CONTACT";
	i=10;
	}*/
	fout<<endl<<endl<<setw(5)<<customerid<<setw(16)<<customername<<setw(15)<<customerage<<setw(16)<<customergender<<setw(20)<<customercity<<setw(18)<<customermobillno<<setw(5)<<"";
	fout.close();
}

void supplier :: supplieradd()
{
        getdata();
        ofstream fout;
        fout.open("supplier",ios::app);
	fout<<endl<<endl<<setw(5)<<supplierid<<setw(16)<<suppliername<<setw(15)<<supplierage<<setw(16)<<suppliergender<<setw(20)<<suppliercity<<setw(18)<<suppliermobillno<<setw(5)<<"";
        fout.close();
}

void bill :: billadd()
{
        getdata();
        ofstream fout;
        fout.open("bill",ios::app);
	fout<<endl<<endl<<setw(5)<<billid<<setw(16)<<billname<<setw(18)<<billcity<<setw(16)<<billmobillno<<setw(15)<<billdate<<setw(20)<<"Rs."<<billtotal_amt<<"/-"<<setw(5)<<"";
        fout.close();
}

void catalogue :: cataladd()
{
        getdata();
        ofstream fout;
        fout.open("catalogue",ios::app);
        fout<<endl<<endl<<setw(5)<<catalid<<setw(50)<<catalname<<setw(25)<<"Rs."<<catalprice<<"/-"<<setw(5)<<"";
        fout.close();
}

void shopping_cart :: customerscustomeradd()
{
	const int N=200;
        char line[N];
        cout<<endl<<"Enter product's id, that you want to add into shopping cart: ";
        int id_se,x;
        cin>>id_se;
        ifstream fin1("catalogue");
	ofstream fout("shopping_cart",ios::app);
        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j==id_se)
                {
                        fout<<endl<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        if(x!=1)
                cout<<endl<<endl<<"Sorry Sir... But Unfortunately, you had entered product id that is not listed!!!";
	else
	{
		cout<<endl<<endl<<endl<<"Your Shopping cart is as under";
		ifstream fin;
	        fin.open("shopping_cart");
        	const int N=200;
	        char line[N];
	        while(fin)
	        {
	                fin.getline(line,N);
	                cout<<line<<endl;
	        }
	        fin.close();
		cout<<endl<<endl<<"Press 1. To Shop more";
		cout<<endl<<setw(30)<<"2. to remove any product";
		cout<<endl<<setw(16)<<"9. to Exit";
		int ch;
		cout<<endl<<"Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: customer_menu();
				break;
			case 2: customerscustomerdelete();
				break;
			case 9: cout<<endl<<endl<<endl<<setw(55)<<"Thank you for visiting... :)";
	                        cout<<endl<<endl<<endl<<endl;
				exit(0);
				break;
			default: default_msg_for_switch();
				break;
		}


	}

}


void customer :: customershow_full()
{
	ifstream fin;
	fin.open("customer");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
	fin.close();
}

void supplier :: suppliershow_full()
{
        ifstream fin;
        fin.open("supplier");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
	fin.close();
}

void bill :: billshow_full()
{
        ifstream fin;
        fin.open("bill");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
	fin.close();
}

void catalogue :: catalshow_full()
{
        ifstream fin;
        fin.open("catalogue");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
	fin.close();
}

void shopping_cart :: customerscustomershow_full()
{
        ifstream fin;
        fin.open("shopping_cart");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
}

void customer :: customerupdate()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("customer");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to update??";
        cout<<endl<<"Enter id of the record you want to update: ";
        int id_up,x;
        cin>>id_up;
        ifstream fin1("customer");
        ofstream fout("temp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_up)
                {

                      	fout<<line<<endl;


		}
		else
		{
			x=1;
			getdata();
			fout<<setw(5)<<customerid<<setw(16)<<customername<<setw(15)<<customerage<<setw(16)<<customergender<<setw(20)<<customercity<<setw(18)<<customermobillno<<setw(5)<<""<<endl;
        	}
        }
        fin1.close();
        fout.close();
        remove("customer");
        rename("temp","customer");
	if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing updatation is as under";
                ifstream fin2("customer");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";

}

void supplier :: supplierupdate()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("supplier");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to update??";
        cout<<endl<<"Enter id of the record you want to update: ";
        int id_up,x;
        cin>>id_up;
        ifstream fin1("supplier");
        ofstream fout("stemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_up)
                {

                        fout<<line<<endl;

                }

		else
                {
                        x=1;
                        getdata();
                        fout<<setw(5)<<supplierid<<setw(16)<<suppliername<<setw(15)<<supplierage<<setw(16)<<suppliergender<<setw(20)<<suppliercity<<setw(18)<<suppliermobillno<<setw(5)<<""<<endl;

                }
        }
        fin1.close();
        fout.close();
        remove("supplier");
        rename("stemp","supplier");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing updatation is as under";
                ifstream fin2("supplier");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";
}

void bill :: billupdate()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("bill");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to update??";
        cout<<endl<<"Enter id of the record you want to update: ";
        int id_up,x;
        cin>>id_up;
        ifstream fin1("bill");
        ofstream fout("btemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_up)
                {

                        fout<<line<<endl;
               //         x=1;

                }

		else
                {
                        x=1;
                        getdata();
                        fout<<setw(5)<<billid<<setw(16)<<billname<<setw(18)<<billcity<<setw(16)<<billmobillno<<setw(15)<<billdate<<setw(20)<<"Rs."<<billtotal_amt<<"/-"<<setw(5)<<""<<endl;

                }
        }
        fin1.close();
        fout.close();
        remove("bill");
        rename("btemp","bill");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing updatation is as under";
                ifstream fin2("bill");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";

}


void catalogue :: catalupdate()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("catalogue");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to update??";
        cout<<endl<<"Enter id of the record you want to update: ";
        int id_up,x;
        cin>>id_up;
        ifstream fin1("catalogue");
        ofstream fout("catemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_up)
                {

                        fout<<line<<endl;
               //         x=1;

                }
		else
                {
                        x=1;
                        getdata();
        		fout<<setw(5)<<catalid<<setw(50)<<catalname<<setw(25)<<"Rs."<<catalprice<<"/-"<<setw(5)<<""<<endl;

                }
        }
        fin1.close();
        fout.close();
        remove("catalogue");
        rename("catemp","catalogue");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing updatation is as under";
                ifstream fin2("catalogue");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";

}




void customer :: customerdelete()
{
	cout<<endl<<"Here is your full database...";
	ifstream fin;
        fin.open("customer");
        const int N=200;
        char line[N];
	while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
	fin.close();
	cout<<endl<<endl<<"Which record would you like to delete??";
	cout<<endl<<"Enter id of the record you want to delete: ";
	int id_de,x;
	cin>>id_de;
	ifstream fin1("customer");
	ofstream fout("temp");

	while(fin1)
	{
		fin1.getline(line,N);
		int j=atoi(line);
		if(j!=id_de)
		{
			fout<<line<<endl;
			x=1;
		}
	}
	fin1.close();
	fout.close();
	remove("customer");
	rename("temp","customer");
	if(x==1)
	{
		cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
		cout<<endl<<endl<<"File after performing deletion is as under";
	        ifstream fin2("customer");
        	while(fin2)
	        {
        	        fin2.getline(line,N);
                	cout<<line<<endl;
	        }
        	fin2.close();
	}

	else
		cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";

}

void supplier :: supplierdelete()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("supplier");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to delete??";
        cout<<endl<<"Enter id of the record you want to delete: ";
        int id_de,x;
        cin>>id_de;
        ifstream fin1("supplier");
        ofstream fout("stemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_de)
                {
                        fout<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        fout.close();
	remove("supplier");
        rename("stemp","supplier");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing deletion is as under";
                ifstream fin2("supplier");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";
}

void bill :: billdelete()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("bill");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to delete??";
        cout<<endl<<"Enter id of the record you want to delete: ";
        int id_de,x;
        cin>>id_de;
        ifstream fin1("bill");
        ofstream fout("btemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_de)
                {
                        fout<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        fout.close();
	remove("bill");
        rename("btemp","bill");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing deletion is as under";
                ifstream fin2("bill");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";
}

void catalogue :: cataldelete()
{
        cout<<endl<<"Here is your full database...";
        ifstream fin;
        fin.open("catalogue");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which record would you like to delete??";
        cout<<endl<<"Enter id of the record you want to delete: ";
        int id_de,x;
        cin>>id_de;
        ifstream fin1("catalogue");
        ofstream fout("catemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_de)
                {
                        fout<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        fout.close();
	remove("catalogue");
        rename("catemp","catalogue");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing deletion is as under";
                ifstream fin2("catalogue");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";
}

void shopping_cart :: customerscustomerdelete()
{
        cout<<endl<<"Here is your Shopping cart...";
        ifstream fin;
        fin.open("shopping_cart");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
        cout<<endl<<endl<<"Which product would you like to remove??";
        cout<<endl<<"Enter id of the product you want to remove: ";
        int id_de,x;
        cin>>id_de;
        ifstream fin1("shopping_cart");
        ofstream fout("sctemp");

        while(fin1)
        {
                fin1.getline(line,N);
                int j=atoi(line);
                if(j!=id_de)
                {
                        fout<<line<<endl;
                        x=1;
                }
        }
        fin1.close();
        fout.close();
	remove("shopping_cart");
        rename("sctemp","shopping_cart");
        if(x==1)
        {
                cout<<endl<<endl<<endl<<setw(60)<<"SUCCESSFUL";
                cout<<endl<<endl<<"File after performing removal of product, your shopping cart is as under";
                ifstream fin2("shopping_cart");
                while(fin2)
                {
                        fin2.getline(line,N);
                        cout<<line<<endl;
                }
                fin2.close();
                cout<<endl<<endl<<"Press 1. To Shop more";
		cout<<endl<<setw(23)<<"2. To remove more";
                cout<<endl<<setw(16)<<"9. to Exit";
                int ch;
                cout<<endl<<"Your choice: ";
                cin>>ch;
                switch(ch)
                {
                        case 1: customer_menu();
                                break;
                        case 2: customerscustomerdelete();
                                break;
                        case 9: cout<<endl<<endl<<endl<<setw(55)<<"Thank you for visiting... :)";
                                cout<<endl<<endl<<endl<<endl;
                                exit(0);
                                break;
                        default: default_msg_for_switch();
                                break;
                }

        }

        else
                cout<<endl<<endl<<endl<<setw(60)<<"UNSUCCESSFUL";
}




void ownercatalogue()
{
	catalogue Ca[100];
	ownerca_menu:
	cout<<endl<<"Below one is your online catalogue...";
	//here file of catalogue will be read
	cout<<endl<<endl<<"Press 1. to add item in the catalogue";
	cout<<endl<<setw(39)<<"2. Remove item from the catalogue";
	cout<<endl<<setw(28)<<"3. Show full catalogue";
	cout<<endl<<setw(39)<<"4. Search item from the catalogue";
	cout<<endl<<setw(39)<<"5. Update item from the catalogue";
	cout<<endl<<setw(28)<<"9. Go to previous menu";
	cout<<endl<<"Your choice:";
        int catalch,i=0;
        cin>>catalch;
	i++;
        switch(catalch)
        {
                case 1: Ca[i].cataladd();
			goto ownerca_menu;
			break;
                case 2: Ca[i].cataldelete();
			goto ownerca_menu;
			break;
		case 3: Ca[i].catalshow_full();
			goto ownerca_menu;
			break;
		case 4: Ca[i].catalsearch();
			goto ownerca_menu;
			break;
		case 5: Ca[i].catalupdate();
			goto ownerca_menu;
                case 9: owner_menu();
                        break;
                default: default_msg_for_switch();
                        break;
        }

}

void billmenu()
{
	bill B[100];
	ownerbillmenu:
        cout<<endl<<endl<<"How would you like to access Bill's information??";
        cout<<endl<<setw(19)<<"1. Add New Bill";
        cout<<endl<<setw(18)<<"2. Delete Bill";
        cout<<endl<<setw(18)<<"3. Update Bill";
        cout<<endl<<setw(35)<<"4. Search for Bill by Bill-name";
        cout<<endl<<setw(34)<<"5. Show Full Database of Bills";
        cout<<endl<<setw(26)<<"9. Go to previous menu";
        cout<<endl<<"Your choice:";
        int billmenu_ch,i=0;
        cin>>billmenu_ch;
	i++;
        switch(billmenu_ch)
        {
                case 1: B[i].billadd();
			goto ownerbillmenu;
			break;
                case 2: B[i].billdelete();
			goto ownerbillmenu;
			break;
                case 3: B[i].billupdate();
			goto ownerbillmenu;
			break;
                case 4: B[i].billsearch();
			goto ownerbillmenu;
			break;
                case 5: B[i].billshow_full();
			goto ownerbillmenu;
			break;
                case 9: owner_menu();
                        break;
                default: default_msg_for_switch();
                        break;
        }
}


void suppliermenu()
{
	supplier S[100];
	ownersuppliermenu:
        cout<<endl<<endl<<"How would you like to access supplier's information??";
        cout<<endl<<setw(29)<<"1. Add Supplier's Details";
        cout<<endl<<setw(31)<<"2. Delete Supplier's Detail";
        cout<<endl<<setw(31)<<"3. Update Supplier's Detail";
        cout<<endl<<setw(34)<<"4. Search for Supplier by name";
        cout<<endl<<setw(37)<<"5. Show Full Database of Supplier";
        cout<<endl<<setw(26)<<"9. Go to previous menu";
        cout<<endl<<"Your choice:";
        int suppliermenu_ch,i=0;
        cin>>suppliermenu_ch;
	i++;
        switch(suppliermenu_ch)
        {
                case 1: S[i].supplieradd();
			goto ownersuppliermenu;
			break;
                case 2: S[i].supplierdelete();
			goto ownersuppliermenu;
			break;
                case 3: S[i].supplierupdate();
			goto ownersuppliermenu;
			break;
                case 4: S[i].suppliersearch();
			goto ownersuppliermenu;
			break;
                case 5: S[i].suppliershow_full();
			goto ownersuppliermenu;
			break;
                case 9: owner_menu();
                        break;
                default: default_msg_for_switch();
                        break;
        }
}


void customermenu()
{
	customer C[100];
	ownercustomermenu:
        cout<<endl<<endl<<"How would you like to access customer's information??";
        cout<<endl<<setw(29)<<"1. Add Customer's Details";
        cout<<endl<<setw(31)<<"2. Delete Customer's Detail";
        cout<<endl<<setw(31)<<"3. Update Customer's Detail";
        cout<<endl<<setw(34)<<"4. Search for Customer by name";
        cout<<endl<<setw(37)<<"5. Show Full Database of Customer";
        cout<<endl<<setw(26)<<"9. Go to previous menu";
        cout<<endl<<"Your choice:";
        int customermenu_ch,i=0;
        cin>>customermenu_ch;
	i++;
        switch(customermenu_ch)
        {
                case 1:	C[i].customeradd();
			goto ownercustomermenu;
			break;
                case 2: C[i].customerdelete();
			goto ownercustomermenu;
			break;
                case 3: C[i].customerupdate();
			goto ownercustomermenu;
			break;
                case 4: C[i].customersearch();
			goto ownercustomermenu;
			break;
                case 5: C[i].customershow_full();
			goto ownercustomermenu;
			break;
                case 9: owner_menu();
                        break;
                default: default_msg_for_switch();
                        break;
        }
}

void customer_menu()
{
	shopping_cart SC[100];
	//customermenu:
	cout<<endl<<endl<<endl<<endl<<setw(55)<<"Welcome sir!";
	cout<<endl<<endl<<endl<<"Catalogue is as under... Happy Surfing.. :) ";
	cout<<endl<<endl;
	ifstream fin;
        fin.open("catalogue");
        const int N=200;
        char line[N];
        while(fin)
        {
                fin.getline(line,N);
                cout<<line<<endl;
        }
        fin.close();
	cout<<endl<<endl<<"Please Press 1. to add product in shopping cart";
	cout<<endl<<setw(42)<<"2. to open your shopping cart";
	cout<<endl<<setw(38)<<"9. to go to previous menu";
	cout<<endl<<"Your Choice Sir! :  ";
	int ch,i=0;
	cin>>ch;
	i++;
	switch(ch)
	{
		case 1: SC[i].customerscustomeradd();
			//goto customermenu;
			break;
		case 2: SC[i].customerscustomershow_full();
			break;
		case 9: cout<<endl<<endl<<endl<<setw(55)<<"Thank you for visiting... :)";
                        cout<<endl<<endl<<endl<<endl;
			break;
		default: default_msg_for_switch();
			break;
	}
}


void owner_menu()
{
	int ownermenu_ch;
	char ch;
	char downerch;
	do
	{
	cout<<endl<<"What would you like to do, Sir??";
	cout<<endl<<setw(28)<<"1. Scan Product Barcode";
	cout<<endl<<setw(26)<<"2. Customer's Details";
	cout<<endl<<setw(26)<<"3. Supplier's Details";
	cout<<endl<<setw(20)<<"4. Bill Details";
	cout<<endl<<setw(37)<<"5. To manipuate online catalogue";
	cout<<endl<<setw(18)<<"9. To log out";
	cout<<endl<<"Your choice:";
	cin>>ownermenu_ch;
	switch(ownermenu_ch)
	{
		case 1: cout<<setw(66)<<"Please keep the product against barcode scanning device!";
			cout<<endl<<endl<<"Do You want to choice agian?? Y. Yes N. No"<<endl<<"Your Choice:";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				owner_menu();
				break;
			}
			else
				break;
		case 2: customermenu();
			break;
		case 3: suppliermenu();
			break;
		case 4: billmenu();
			break;
		case 5:	ownercatalogue();
			break;
		case 9: cout<<endl<<endl<<endl<<setw(55)<<"Thank you for loging in";
			cout<<endl<<endl<<endl<<endl;
			break;
		default:default_msg_for_switch();
				break;
	}
	}while(downerch == 'y' || downerch == 'Y');
}

void start_screen()
{
	int loginch;
        int switchch;
	do
	{
	cout<<endl<<endl<<"How would you like to login - as a customer or as owner??";
	cout<<endl<<setw(22)<<"1. Customer"<<endl<<setw(19)<<"2. Owner"<<endl<<setw(25)<<"3. Exit System";
        cout<<"\nYour choice: ";
        cin>>loginch;
	switch(loginch)
        {
                case 1: customer_menu();
			break;
                case 2: int check;
                        check=owner_authen();
                        if(check == 1)
                        {
                                cout<<"Welcome Meet!";
                                owner_menu();
                                break;
                        }
                        else
                                cout<<endl<<"Invalid Username or Password!! Please try again...";
                                break;
		case 3: switchch=1;
			break;
		default: cout<<endl<<"Invalid Choice!!!";
                        break;
        }
        }while(switchch!=1);
}

int main()
{
    // IOS
    int k=1;
    // init();
    // cin>>k;
    //sieve();
    // int counter=1;
    while(k--)
    {
        // printf("Case #%d: ",counter++);
        start_screen();
    }

//	cout<<"In main  ";
	return 0;
}