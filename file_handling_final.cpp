#include <string>
#include<windows.h>
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include<fstream>
using namespace std;

class prod
{
    private:
        float price;
        char name[20];
        char store[20];
        int codedname[100];
        int codedstore[100];
        int ln,ls;
        int quantity;

    public:
        void getdata(float f, char n[20],char s[20], int q)
        {
            price = f;
            strcpy(name,n);
            strcpy(store,s);
            quantity = q;
        }
        void display_data()
        {
            cout << "Item : " << name << endl;
            cout << "Store : " << store << endl;
            cout << "Price : " << price << endl;
            cout << "Quantity left " << quantity << endl;
            int i;
        }
        char *getname()
        {
             return &name[0];
        }
       void encoder()
       {
           int i;
           for(i=0 ; store[i]!='\0' ; i++)
            {
                codedstore[i]=int(store[i]);
            }
            ls=i;
             for(i=0 ; name[i]!='\0' ; i++)
            {
                codedname[i]=int(name[i]);
            }
            ln=i;
        }
        void deleter()
        {
            name[0]='e';
            store[0]='e';
        }
       void  decoder()
       {
           int i;
           for(i=0 ; i<ls ; i++)
            {
                store[i]=(char)codedstore[i];
            }
            for(i=0 ; i<ln ; i++)
            {
                name[i]=(char)codedname[i];
            }
       }
};

void graphic()
{
    cout<<"================================================================="<<endl;
}

void push(int i)
{
    prod p;
    float price;
    char name[20];
    char store[20];
    int quantity;
    cout << "Item : ";
    cin>>name;
    cout << "Store : ";
    cin>>store;
    cout << "Price : ";
    cin >> price;
    cout << "Quantity ";
    cin >> quantity;
    p.getdata(price,name,store,quantity);
    p.encoder();
    if(i==1)
    {
        ofstream out;
        out.open("store1.dat",ios::app|ios::binary);
        out.write((char*)&p,sizeof(p));
        out.close();
    }
    else if(i==2)
    {
        ofstream out;
        out.open("store2.dat",ios::app|ios::binary);
        out.write((char*)&p,sizeof(p));
        out.close();
    }
    else if(i==3)
    {
        ofstream out;
        out.open("store3.dat",ios::app|ios::binary);
        out.write((char*)&p,sizeof(p));
        out.close();
    }
    else if(i==4)
    {
        ofstream out;
        out.open("store4.dat",ios::app|ios::binary);
        out.write((char*)&p,sizeof(p));
        out.close();
    }

}
void pop(int i)
{
    string del;
    int flag = 0, j;
    cout << "Enter the product to be deleted ";
    cin>>del;
    ifstream fd;
    ofstream ft;

    if(i==1)
    {
        fd.open("store1.dat",ios::binary|ios::in);
        ft.open("temp.dat",ios::binary|ios::out);
        int flag=0;
        prod p;

        while(!fd.eof())
        {
        fd.read((char*)&p,sizeof(p));
        if(!del.compare(p.getname()))
        {
            flag=1;
        }
           else
            ft.write((char*)&p,sizeof(p));
        }
        if(flag==0)
        cout<<"specified product not found \n";  fd.close(); ft.close();
        remove("store1.dat");
        rename("temp.dat","store1.dat");
        cout<<"product deleted successfully\n";
    }
    else if(i==2)
    {
        fd.open("store2.dat",ios::binary|ios::in);
        ft.open("temp.dat",ios::binary|ios::out);
        int flag=0;
        prod p;

        while(!fd.eof())
        {
        fd.read((char*)&p,sizeof(p));
        if(!del.compare(p.getname()))
        {
            flag=1;
        }
           else
            ft.write((char*)&p,sizeof(p));
        }
        if(flag==0)
        cout<<"specified product not found ";  fd.close(); ft.close();
        remove("store2.dat");
        rename("temp.dat","store2.dat");
        cout<<"product deleted successfully\n";

    }
    else if(i==3)
    {
        fd.open("store3.dat",ios::binary|ios::in);
        ft.open("temp.dat",ios::binary|ios::out);
        int flag=0;
        prod p;

        while(!fd.eof())
        {
        fd.read((char*)&p,sizeof(p));
        if(!del.compare(p.getname()))
        {
            flag=1;
        }
           else
            ft.write((char*)&p,sizeof(p));
        }
        if(flag==0)
        cout<<"specified product not found ";  fd.close(); ft.close();
        remove("store3.dat");
        rename("temp.dat","store3.dat");
        cout<<"product deleted successfully\n";

    }
    else if(i==4)
    {
        fd.open("store4.dat",ios::binary|ios::in);
        ft.open("temp.dat",ios::binary|ios::out);
        int flag=0;
        prod p;

        while(!fd.eof())
        {
        fd.read((char*)&p,sizeof(p));
        if(!del.compare(p.getname()))
        {
            flag=1;
        }
           else
            ft.write((char*)&p,sizeof(p));
        }
        if(flag==0)
        cout<<"specified product not found ";  fd.close(); ft.close();
        remove("store4.dat");
        rename("temp.dat","store4.dat");
        cout<<"product deleted successfully\n";
    }

}
void display(int i)
{
    prod p;
    cout<<endl;
    if(i==1)
    {
        ifstream in("store1.dat", ios::binary);
        while(!in.eof())
        {
            in.read((char*)&p, sizeof(p));
            
                p.decoder();
			    p.display_data();
                graphic();
			

        }
        in.close();
     }
    else if(i==2)
    {
        ifstream in("store2.dat", ios::binary);
        while(!in.eof())
        {
            in.read((char*)&p, sizeof(p));
            
                p.decoder();
			    p.display_data();
                graphic();
			

        }
        in.close();
     }
    else if(i==3)
    {
        ifstream in("store3.dat", ios::binary);
        while(!in.eof())
        {
            in.read((char*)&p, sizeof(p));
                p.decoder();
			    p.display_data();
                graphic();
			
        }
        in.close();
     }
    else if(i==4)
    {
        ifstream in("store4.dat", ios::binary);
        while(!in.eof())
        {
            in.read((char*)&p, sizeof(p));
        
                p.decoder();
			    p.display_data();
                graphic();
		

        }
        in.close();
     }

}
int search_prod1(string serch)
{
    graphic();
    ifstream fin("store1.dat", ios::in|ios::binary);
    prod p;
    
    int f=0;
    
    while(!fin.eof())
    {
        fin.read((char *)&p, sizeof(p));
        p.decoder();
        if(!serch.compare(p.getname()))
        {
            p.display_data();
            graphic();
            f=1;
            break;
        }
    }
    return f;
    fin.close();
}
int search_prod2(string serch)
{
    graphic();
    ifstream fin("store2.dat", ios::in|ios::binary);
    prod p;
    
    int f=0;
    while(!fin.eof())
    {
        fin.read((char *)&p, sizeof(p));
        p.decoder();
        if(!serch.compare(p.getname()))
        {
            p.display_data();
            graphic();
            f=1;
            break;
        }
    }
    return f;
    fin.close();
}
int search_prod3(string serch)
{
    graphic();
    ifstream fin("store3.dat", ios::in|ios::binary);
    prod p;
    
    int f=0;
    
    while(!fin.eof())
    {
        fin.read((char *)&p, sizeof(p));
        p.decoder();
        if(!serch.compare(p.getname()))
        {
            p.display_data();
            graphic();
            f=1;
            break;
        }
    }
    return f;
    fin.close();
}
int search_prod4(string serch)
{
    graphic();
    ifstream fin("store4.dat", ios::in|ios::binary);
    prod p;
    
    int f=0;
    
    while(!fin.eof())
    {
        fin.read((char *)&p, sizeof(p));
        p.decoder();
        if(!serch.compare(p.getname()))
        {
            p.display_data();
            graphic();
            f=1;
            break;
        }
    }
    return f;
    fin.close();
}

int main()
{
        int ch,f,n,m,condition = 1;
        float price;
        string name, query,serch;
        do
        {
                graphic();
                cout << "\n     Menu\n";
                cout << "1)Back-end \n";
                cout << "2)Front-end \n";
                cout << "3)Exit\n";
                cout << "4)Enter your choice:";
                cin >> ch;
                switch (ch)
                {
                case 1:
                        graphic();
                        cout << "    Back-end\n";
                        cout << "1) Enter new product\n";
                        cout << "2) Delete a product \n";
                        cout << "3) View inventory   \n ";
                        cout << "Enter your choice: ";
                        cin >> n;
                        graphic();
                        cout << " Store menu \n";
                        cout << "1) store 1\n";
                        cout << "2) store 2\n";
                        cout << "3) store 3\n";
                        cout << "4) store 4\n";
                        cout << "Enter your choice: ";
                        cin >> m;
                        switch (n)
                        {
                        case 1:
                                push(m);
                                break;
                        case 2:
                                pop(m);
                                break;
                        case 3:
                                display(m);
                                break;
                        }
                        break;
                case 2:
                        f=0;
                        cout<<"Enter the product to be searched ";
                        cin>>serch;
                        
                        f+=search_prod1(serch);
                        f+=search_prod2(serch);
                        f+=search_prod3(serch);
                        f+=search_prod4(serch);
                        
                        
                        if(f==0)
                          cout<<"Product not found in any store. \nTry another product"<<endl;
                        else if(f!=0)
                        {
                            continue;
                        }
                        
                        graphic();

                        break;
                case 3:
                        graphic();
                        cout << "Thank you";
                        condition = 0;
                        break;
                default:
                        graphic();
                        cout << "Enter valid choice"<<endl;
                }
        }
        while (condition);
        return 0;
}