#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

class Student
{  
    public:
        int roll;
        char name[20] , city[20];
        char div;

        Student()
        {
            roll = 0;
            strcpy(name , "");
            strcpy(city, "");
            div = '\0';
        }

        Student(int roll , char name[20] , char city[20] , char div)
        {
            this -> roll = roll;
            strcpy(this -> name , name);
            strcpy(this -> city , city);
            this -> div = div;
        }
};

class FileOperations
{
    private:
        fstream file;

    public:
        FileOperations(char *);
        void insertRecord(int roll , char name[20] , char city[20] , char div);
        void displayAll();
        void displayRecord(int roll);
        void deleteRecord();
};

FileOperations :: FileOperations(char * filename)
{
    file.open(filename , ios::in|ios::out|ios::ate|ios::binary);
}

void FileOperations :: insertRecord(int roll , char name[20] , char city[20] , char div)
{
    Student s(roll, name, city, div);
    file.seekp(0 , ios::end);
    file.write((char*)&s , sizeof(s));
    file.clear();
}

void FileOperations::displayAll()
{
    Student s;
    file.seekg(0 , ios::beg);
    while(file.read((char *)&s , sizeof(s)))
    {
        cout<<s.roll<<"\n";
        cout<<s.name<<"\n";
        cout<<s.city<<"\n";
        cout<<s.div<<"\n";
    }
    file.close();
}

void FileOperations::displayRecord(int roll)
{
    Student s;
    file.seekg(0 , ios::beg);
    while(file.read((char *)&s , sizeof(s)))
    {   
        if(s.roll == roll)
        {
            cout<<s.roll<<"\n";
            cout<<s.name<<"\n";
            cout<<s.city<<"\n";
            cout<<s.div<<"\n";
            break;
        }

    }
    file.close();
}

void FileOperations :: deleteRecord()
{
	int n, flag=0;
	cout<<"\nEnter Roll Number Whose Record To Be Deleted:";
	cin>>n;
	ifstream infile("student.txt");
	ofstream temp("temp.txt");
	Student s;
	while(infile.read((char *)&s, sizeof(s)))
	{
		if(s.roll!=n)
		{
			temp.write((char *)&s, sizeof(s));
		}

		else
		{
			flag=1;
			cout<<"\nRecord Successfully Deleted.";
		}
	}

		if(flag==0)
		{
			cout<<"\nRecord Not Found.";
		}

		infile.close();
		temp.close();

        ifstream infile2("temp.txt");
        Student s1;
        file.seekg(0 , ios::beg);
        while(file.read((char *)&s1 , sizeof(s1)))
        {
            cout<<s1.roll<<"\n";
            cout<<s1.name<<"\n";
            cout<<s1.city<<"\n";
            cout<<s1.div<<"\n";
        }
        file.close();
}

int main()
{
    ofstream newfile("student.txt" , ios::app | ios::binary);
    newfile.close();

    FileOperations fobj((char *)"student.txt");

    int roll;
    char name[20] , city[20];
    char div;

    cout<<"Enter the rollno : \n";
    cin>>roll;

    cout<<"Enter the name : \n";
    cin>>name;

    cout<<"Enter the city : \n";
    cin>>city;

    cout<<"Enter the div : \n";
    cin>>div;

    fobj.insertRecord(roll , name , city , div);

    // fobj.displayAll();

    // fobj.displayRecord(23);

    fobj.deleteRecord();
    // fobj.displayAll();

    return 0;
}