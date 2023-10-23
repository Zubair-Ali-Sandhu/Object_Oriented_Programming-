#include<iostream>
using namespace std;
class Employee
{
	private:
		string id;
		string name;
		string title;
		int hrs;
	public:
		Employee()
		{
			id="Null";
			name="Null";
			title="Null";
			hrs=0;
		}
		void setid()
		{
			cout<<"\nEnter Employee's id:\n";
			cin>>id;
			
		}
		void setname()
		{
			cout<<"\nEnter Employee's name:\n";
			cin>>name;
		}
		void settitle()
	 	{
			cout<<"\nEnter Employee's job title:\n";
			cin>>title;
		}
		void sethrs()
		{
			cout<<"\nEnter the number of hrs Employee have worked:\n ";
			cin>>hrs;
		}
		int gethrs()
		{
		return hrs;
				
		}
			
		void cal_sal(Employee en[],int size)
		{
			int salary=0;
			for(int i=0;i<size;i++)
			{
				if(en[i].hrs<=40)
				{
					salary=en[i].hrs*100;
					cout<<"\nEmployee name:"<<en[i].name<<"\n";
					cout<<"Salary:"<<salary;
					salary=0;
				}
				else if(en[i].hrs>40)
				{
					int temp;
					temp=en[i].hrs%40;
					salary=40*100;
					salary=salary+temp*200;
					cout<<"\nEmployee name:"<<en[i].name<<"\n";
					cout<<"\nSalary:"<<salary;
					salary=0;
				}
			}
				
		}
		
			
		
};
int main()
{
	int size;
	cout<<"Enter your number of employees:\n";
	cin>>size;
	Employee ne[size],temp;
	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter details for Employee no "<<i+1<<":\n";
		ne[i].setid();
		ne[i].setname();
		ne[i].settitle();
		ne[i].sethrs();
	}
	temp.cal_sal(ne,size);
	
}
