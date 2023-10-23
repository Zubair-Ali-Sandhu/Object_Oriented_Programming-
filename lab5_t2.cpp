#include<iostream>
using namespace std;
class Store{
	private:
		int id;
		string name;
		int price;
		int quantity;
	public:
		Store()
		{
			id=0;
			name="Null";
			price=0;
			quantity=0;
		}
		void setid()
		{
			cout<<"\nEnter the item's id:\n";
			cin>>id;
			
		}
		void setname()
		{
			cout<<"\nEnter the item's name:\n";
			cin>>name;
		}
		void setprice()
		{
			cout<<"\nEnter the price of the item:\n";
			cin>>price;
		}
		void setquantity()
		{
			cout<<"\nEnter the quantity:\n ";
			cin>>quantity;
		}
		
		
		void displayitems(int size,Store item[])
		{
			for(int i=0;i<size;i++)
			{
				cout<<"\nDetails of item no "<<i+1<<":\n";
				cout<<"\nId:"<<item[i].id<<endl;
				cout<<"\nName:"<<item[i].name<<endl;
				cout<<"\nPrice:"<<item[i].price<<endl;
				cout<<"\nQuantity:"<<item[i].quantity<<endl;
			}
		}
		void updateitem(int size,Store item[])
		{
			string itemname;
			int choice;
			int check=0;
			cout<<"\nEnter the name of the item you want to update:\n";
			cin>>itemname;
			for(int i=0;i<size;i++)
			{
				if(item[i].name==itemname)
				{
					check=1;
					cout<<"\nEnter\n1 for updating price\n2 for updating quantity:\n";
					cin>>choice;
					if(choice==1)
					{
						item[i].setprice();
						break;
					}
					else if(choice==2)
					{
						item[i].setquantity();
						break;
					}
					else
					{
						cout<<"\nInvalid choice!\n";
						break;
					}
				}
				else if(i==size-1&&check==0)
				{
					cout<<"\nItem not found\n";
				}
			}
		}
		void idsearch(int size,Store item[],int id)
		{
			int check=0;
			for(int i=0;i<size;i++)
			{
				if(id==item[i].id)
				{
					check=1;
					cout<<"\nId:"<<item[i].id<<endl;
					cout<<"\nName:"<<item[i].name<<endl;
					cout<<"\nPrice:"<<item[i].price<<endl;
					cout<<"\nQuantity:"<<item[i].quantity<<endl;
				}
				else if(i==size-1&&check==0)
				{
					cout<<"\nItem not found\n";
				}
			}
		}
		~Store()
		{
			cout<<"\nObject destroyted\n";
		}
		
};

int main()
{
	int size;
	cout<<"\nEnter total number of items to store:\n";
	cin>>size;
	Store item[size],temp;
	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter details for item no "<<i+1<<":\n";
		item[i].setid();
		item[i].setname();
		item[i].setprice();
		item[i].setquantity();
	}
	
	int choice;
	do
	{
		cout<<"\nSelect your choice:\n1. Display Items\n2. Update item details\n3. Search for items by ID\n4. Exit the program:\n";
		cin>>choice;
		if(choice==1)
		{
			temp.displayitems(size,item);
		}
		else if(choice==2)
		{
			temp.updateitem(size,item);
		}
		else if(choice==3)
		{
			int id;
			cout<<"\nEnter id:\n";
			cin>>id;
			temp.idsearch(size,item,id);
			
		}
		else if(choice==4)
		{
			cout<<"\nThanks for using the program!\n";
			break;
		}
		else
		{
			cout<<"\ninvalid choice\n";
		}
	}
	while(choice!=4);
	
}
