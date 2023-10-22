#include <iostream>
#include <fstream>
using namespace std;

class Book {
protected:
	int id;
    string title;
    string author;
    int publicationYear;
    int quantity;
public:
	virtual string get_booktype()
	{
		
	}
    void inputDetails() {
    	cout<<"\nEnter id   :" ;
    	cin>>id;
    	 cin.ignore();
        cout << "\nEnter Title: ";
        getline(cin, title);
        cout << "\nEnter Author: ";
        getline(cin, author);
        cout << "\nEnter Publication Year: ";
        cin >> publicationYear;
        cout<<"\n\nEnter quantity:";
        cin>>quantity;
        cin.ignore();  // To clear the input buffer
    }
    virtual void displayDetails() {
        cout << "\nTitle: " << title ;
        cout << "\nAuthor: " << author ;
        cout << "\nPublication Year: " << publicationYear ;
    }
    string get_author()
    {
    	return author;
	}
	string get_title()
	{
		return title;
	}
	int getPublicationYear()
	{
		return publicationYear;
	}
	int get_id()
	{
		return id;
	}
};

class ReferenceBook : public Book {
private:
    string category;
public:
	string get_booktype()
	{
		return "Reference Book";
		
	}
    void inputDetails() {
        Book::inputDetails();
        cout << "\nEnter Category: ";
        getline(cin, category);
    }
    void displayDetails() {
        Book::displayDetails();
        cout << "\nCategory: " << category << endl;
    }
};

class FictionBook : public Book {
private:
    string genre;
public:
	string get_booktype()
	{
		return"Fiction Book";
		
		
	}
    void inputDetails() {
        Book::inputDetails();
        cout << "\nEnter Genre: ";
        getline(cin, genre);
    }
    void displayDetails() {
        Book::displayDetails();
        cout << "\nGenre: " << genre << endl;
    }
};
class Transaction {
	private:
   	 	int id;
    	int user_id;
    	string date_issued;
    	string due_date;
    	string date_returned;
	public:
		Transaction(int i=0,int ui=0, string di="",string dd="",string dr="")
		{
			
			id=i;
			user_id=ui;
			date_issued=di;
			due_date=dd;
			date_returned=dr;
			
		}
		void trans(int id,int user_id,string date_issued,string due_date)
		{
   	 	this-> id=id;
    	this->user_id=user_id;
    	this-> date_issued=date_issued;
    	this-> due_date=due_date;
   	 	
		}
		void returnitem(string date)
		{
			date_returned=date;
		}
		//set
		int getid()
		{
			return id;
		}
		string getissuedate()
		{
			return date_issued;
		}
		string getreturndate()
		{
			return date_returned;
		}
		string getduedate()
		{
			return due_date;
		}
		int getuserid()
		{
			return user_id;
		}
		
};

class Library {
private:
    Book* books[100];
    Transaction Trans[100];
    static int Transaction_counter;
   static int numBooks;
public:
    void addBook() {
        char choice;
        do {
            cout << "\nAdd a Book:" ;
            cout << "\n1. Add a Reference ";
            cout << "\n2. Add a Fiction Book" ;
            cout << "\nEnter your choice: ";
            cin >> choice;
            cin.ignore();  

            switch (choice) {
                case '1': {
                    ReferenceBook* refBook=new ReferenceBook;
                    refBook->inputDetails();
                    books[numBooks] = refBook;
                    numBooks++;
                    cout << "\nReference Book added successfully!" ;
                    break;
                }
                case '2': {
                    FictionBook* ficBook=new FictionBook;
                    ficBook->inputDetails();
                    books[numBooks] = ficBook;
                    numBooks++;
                    cout << "\nFiction Book added successfully!";
                    break;
                }
                default:
                    cout << "\nInvalid choice. Try again." ;
                    break;
            }

            cout << "\nDo you want to add another book? (y/n): ";
            cin >> choice;
            cin.ignore();  
        } while (choice == 'y' || choice == 'Y');
    }
    void displayAllBooks() 
	{
        if (numBooks == 0)
	 	{
            cout << "\nNo books in the library." ;
            return;
        }
        cout << "\nBooks in the Library:" ;
        for (int i = 0; i < numBooks; i++) {
            cout << "\nBook " << (i + 1) << ":" ;
            books[i]->displayDetails();
            cout << endl;
        }
    }
    void printtransactions()
    	{
    		if(Transaction_counter>0)
    		{
    			cout<<"\nBELOW IS THE TRACK RECORD OF TRANSACTION:\n";
    			for(int i=0;i<Transaction_counter;i++)
    		{
    			cout<<"\nUser id               :"<<Trans[i].getuserid();
    			cout<<"\nITEM id               :"<<Trans[i].getid();
    			cout<<"\nIssuance date         :"<<Trans[i].getissuedate();
    			cout<<"\nDue date              :"<<Trans[i].getduedate();
    			cout<<"\nReturning Date        :"<<Trans[i].getreturndate();
			}
    		}
    		else
    		{
    			cout<<"\nYou have not performed any transactions yet\n";
			}
    		
		}
		void checkbook(int id)
		{
			bool check=false;
			for(int i=0;i<numBooks;i++)
			{
				if(books[i]->get_id()==id)
				{
					cout<<"\nBook id           :"<<books[i]->get_id();
					cout<<"\nBook title        :"<<books[i]->get_title();
					cout<<"\nAuthor name       :"<<books[i]->get_author();
					cout<<"\nPublishing year   :"<<books[i]->getPublicationYear();
					check=true;
				}
			}
			if(check!=true)
			{
				cout<<"\nBOOK WITH SUCH ID DOES NOT EXIST\n";
			}
		}
    void issuebook(int book_id)
		{
			bool check=false;
			if(numBooks>0)
			{
				Transaction_counter++;
				for(int i=0;i<numBooks;i++)
				{
				
					if(books[i]->get_id()==book_id)
					{
						int user_id;
						string date_issued;
						string due_date;
						cout<<"\nEnter User id		        :";
						cin>>user_id;
						
						cin.ignore();
						cout<<"\nEnter Issuance date        :";
						getline(cin,date_issued);
						
						cout<<"\nEnter Due Date             :";
						getline(cin,due_date);
			
						Transaction t1;
						t1.trans(book_id,user_id,date_issued,due_date);
						t1.returnitem("Not returned yet");
			
						Trans[i]=t1;
						check=true;
					}	
				}
				if(check!=true)
				{
					cout<<"\nBOOK WITH SUCH ID DOES NOT EXIST\n";
					}	
			}
			else
			{
				cout<<"\nYOU CAN NOT ISSUE BOOK BEACAUSE THERE ARE ZERO BOOKS IN THE LIBRARY\n";
			}
		}
		void return_item(int id )
		{
			int userid;
			bool check=false;
			cout<<"\nEnter user id:";
			cin>>userid;
        	for (int i = 0; i < Transaction_counter; i++) 
			{
            	if (Trans[i].getid() == (id)&&Trans[i].getuserid()==userid)
				{
					string date_returned;
					cin.ignore();
					cout<<"\nEnter return date: ";
					getline(cin,date_returned);
            	    Trans[i].returnitem(date_returned);
                	check=true;
                	cout<<"\n    BOOK RETURNED SUCCEFULLY    ";
                	//break;
            	}
            	
            	
			}
		if(check==false)
		{
			cout<<"\nYOUR ENTERED DATA DOES NOT MATCH WITH TRANSACTION HISTORY\n";
		}
		else
		{
			
		}
		}
    void saveToFile() {
        ofstream outFile("library.txt");
        if (!outFile) {
            cout << "\nError creating the file." ;
            return;
        }
        for (int i = 0; i < numBooks; i++) {
            outFile << "Book " << (i + 1) << ":" << endl;
           
            books[i]->displayDetails();
            outFile<<"\nid               :"<<books[i]->get_id();
            outFile<<"\nTitle            :"<< books[i]->get_title() ;
            outFile<<"\nBook Type        :"<<books[i]->get_booktype();
            outFile<<"\nAuthor          :"<< books[i]->get_author() ;
            outFile<<"\nPublication Year:"<< books[i]->getPublicationYear();
            outFile<< endl;
        }
        outFile.close();
        cout << "Library data saved to file successfully!" << endl;
    }
    void saveTransaction() {
        ofstream TFile("Transaction.txt");
        if (!TFile) {
            cout << "\nError creating the file." ;
            return;
        }
        for (int i = 0; i < numBooks; i++) 
		{
            TFile << "Book " << (i + 1) << ":" << endl;
           
            books[i]->displayDetails();
            TFile<<"\nBook id               :"<<Trans[i].getid();
            TFile<<"\nUser id            :"<< Trans[i].getuserid() ;
            TFile<<"\nIssuance Date       :"<<Trans[i].getissuedate();
            TFile<< "\nReturn Date         :"<< Trans[i].getreturndate() ;
            TFile<< "\nPublication Year:"<< books[i]->getPublicationYear();
            TFile<< endl;
        }
        TFile.close();
        cout << "Library data saved to file successfully!" << endl;
    }
    void loadFromFile() {
        ifstream inFile("library.txt");
        if (!inFile) {
            cout << "Error opening the file." << endl;
            return;
        }
        string line;
        while (getline(inFile, line))
	    {
            cout << line << endl;
    	}
        inFile.close();
    }
        void loadTransaction() 
		{
        ifstream Trans("Transaction.txt");
        if (!Trans) {
            cout << "Error opening the file." << endl;
            return;
        }
        string line;
        while (getline(Trans, line)) {
            cout << line << endl;
        }
        Trans.close();
    }
};

int Library::numBooks=0;
int Library::Transaction_counter;
int main() 
{
	cout<<"               					PRESENTER: ZUBAIR ALI         ROLL NO: 22P-9232        SECTION: BCS-2C                 \n\n\n";
	cout<<"                           					WELCOME TO THE LIBRARY MANAGEMENT SYSTEM                               \n";
    Library library;
    int choice;
    do {
    	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------";
        //cout << "Library Management System" << endl;
        cout << "\n\n\n1. Add a Book" << endl;
        cout << "2. Display all Books" << endl;
        cout<<  "3.Search book by id  \n";
        cout<<  "4.Issue Book       \n";
        cout<<  "5.Return Book       \n";
        cout<<  "6.Print Transaction History\n";
        cout << "7. Save Library to File" << endl;
        cout << "8. Load Library from File" << endl;
        cout<<  "9.Save Transaction History To file"<<endl;
        cout<<  "10.Load Transaction History from file"<<endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  
        int id;
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------";

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayAllBooks();
                break;
            case 3:
            	
            	cout<<"\nEnter book id :";
            	cin>>id;
                library.checkbook(id);
                break;
            case 4:
            	cout<<"\nEnter book id :";
            	cin>>id;
                library.issuebook(id);
                break;
            case 5:
            	cout<<"\nEnter book id :";
            	cin>>id;
				library.return_item(id);  
				break;
			case 6:
				library.printtransactions();
				break;
			case 7:
				library.saveToFile();
				break;
			case 8:
				library.loadFromFile();
				break;
			case 9:
				library.saveTransaction();
				break;
			case 10:
				library.loadTransaction();
				break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != '0');

    return 0;
}

