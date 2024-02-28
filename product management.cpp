#include<iostream>
#include<string>
using namespace std;

void id();
void name();
void total();
void addproduct();
void productinfo();
void category();
void restock();

struct product{
    int idno;
    string productname;
    string category;
    int quantity;
    string flag;
}p[100];

int cont = 0;

int main()
{
    cout<<"Product Stock Management System\n"<<endl;
       while(true)
       {
           cout<<endl;
           cout<<"===================================================\n";
           cout<<"1.Adding Product Information:\n";
           cout<<"2.Display Product Information:\n";
           cout<<"3.List All Products Of Given Category:\n";
           cout<<"4.List The Count Of Products In Stock:\n";
           cout<<"5.List The Name Of Specified Product:\n";
           cout<<"6.Restock Products:\n";
           cout<<"7.Exit:\n";
           cout<<"Your choice: ";
           int x;
           cin>>x;
           switch(x)
           {
               case 1:
                   addproduct();
                   break;
               case 2:
                   productinfo();
                   break;
               case 3:
                   category();
                   break;
               case 4:
                   total();
                   break;
               case 5:
                   name();
                   break;
               case 6:
                   restock();
                   break;
               case 7:
                   exit(0);
                   break;
               default:
                  cout<<"invalid entry";
           }
       }
       return 0;
}

void addproduct()
{
    cont = cont + 1;
    cin.ignore(INT_MAX,'\n');
    cout<<"\nEnter Product Name: ";
    getline(cin, p[cont].productname);
    cout<<"\nEnter Category: ";
    getline(cin, p[cont].category);
    cout<<"\nEnter Product ID: ";
    cin>>p[cont].idno;
    cout<<"\nEnter Quantity: ";
    cin>>p[cont].quantity;
    cin.ignore(INT_MAX,'\n');
    cout<<"\nProduct Available (Yes or No): ";
    getline(cin, p[cont].flag);
}

void productinfo()
{
    cout<<"Display Product Information\n";
    for(int i=1; i<=cont; i++)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"\nID Number of Product is: "<<p[i].idno<<endl;
        cout<<"\nName of Product is: "<<p[i].productname<<endl;
        cout<<"\nCategory: "<<p[i].category<<endl;
        cout<<"\nQuantity: "<<p[i].quantity<<endl;
        cout<<"\nProduct Available (Yes or No): "<<p[i].flag<<endl;
        cout<<"---------------------------------------------------"<<endl;
    }
}

void category()
{
    string c;
    cin.ignore(INT_MAX,'\n');
    cout<<"\nEnter category: ";
    getline(cin, c);
    for(int i=1;i<=cont;i++)
    {
        if(c==p[i].category)
        {
           cout<<"---------------------------------------------------"<<endl;
           cout<<"\nName of Product is: "<<p[i].productname<<endl;
           cout<<"\nID Number of Product is: "<<p[i].idno<<endl;
           cout<<"---------------------------------------------------"<<endl;
        }
    }
}

void total()
{
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Total Number of products in stock is "<<cont;
}

void name()
{
    string n;
    int count=0, found = 0;
    cin.ignore(INT_MAX,'\n');
    cout<<"\nEnter Name of the Product: ";
    getline(cin, n);
    cout<<"---------------------------------------------------"<<endl;
    for(int i=1;i<=cont;i++)
    {
        if(n==p[i].productname)
        {
            cout<<"\nID Number of Product is: "<<p[i].idno<<endl;
            cout<<"\nName of Product is: "<<p[i].productname<<endl;
            cout<<"\nCategory: "<<p[i].category<<endl;
            cout<<"\nQuantity: "<<p[i].quantity<<endl;
            cout<<"\nProduct Available (Yes or No): "<<p[i].flag<<endl;
            count++;
            found = 1;
        }
    }
    if (found == 0){
        cout<<"Product not found!!";
    }
}

void id()
{
    int a;
    cout<<"\nEnter the ID: ";
    cin>>a;
    for(int i=1;i<=cont;i++)
    {
        if(a==p[i].idno)
        {
            cout<<"---------------------------------------------------"<<endl;
            cout<<"\nID Number of Product is: "<<p[i].idno<<endl;
            cout<<"\nName of Product is: "<<p[i].productname<<endl;
            cout<<"\nCategory: "<<p[i].category<<endl;
            cout<<"\nQuantity: "<<p[i].quantity<<endl;
            cout<<"\nProduct Available (Yes or No): "<<p[i].flag<<endl;
            cout<<"---------------------------------------------------"<<endl;
        }
    }
}

void restock()
{
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Restocking The Product\n";
    addproduct();
}
