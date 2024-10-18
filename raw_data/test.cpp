#include<iostream>
#include<utility>
#include<vector>
#include<map>
#include<string>
using namespace std;
class MenuItem
{
    protected:
    int id;
    string name;
    double price;
    public:
    MenuItem(int id,string name,double price)
    {
        this->id=id;
        this->name=name;
        this->price=price;
    }  
    virtual void displayItem()const{
     cout<< "ID : "<<id<<"\n Name: "<<name<<"\n Price: Rs"<<price<<endl; 
    }
    virtual ~MenuItem(){}
};
class Restaurant
{
    string restaurantname;
    string address;
    string contactnumber;
    vector <MenuItem> p;
};