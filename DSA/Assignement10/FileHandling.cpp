#include<iostream>
#include<fstream>
using namespace std;

class Student{

    public:

        int rollno;
        string name;
        string div;
        string address;
};

class FileHandling{
    private:
        Student sd;
        fstream fd;

    public:

        void createFile();
        void writetoFile();
        void displayFile();
        void addContents();
        void searchContent();
};

void FileHandling :: createFile(){

    fd.open("Student.txt" , ios::trunc | ios::out | ios::in);

    if(fd.is_open() == 0){

        cout<<"File did not open"<<"\n";
        return;
    }
}

void FileHandling :: writetoFile(){

    cout<<"Enter roll no : ";
    cin>>sd.rollno;

    cout<<"Enter Name : ";
    cin>>sd.name;

    cout<<"Enter division : ";
    cin>>sd.div;

    cout<<"Enter Address : ";
    cin>>sd.address;

    fd.write((char *)&sd , sizeof(sd));

    cout<<"Successfully  written to file";

}

void FileHandling :: displayFile(){

    string line;

    fd.seekg(0 , ios::beg);

    while(fd){

        getline(fd , line);

        cout<<line<<"\n";

    }
}

void FileHandling :: addContents(){

    string line;

    fd.seekg(ios::end);

    cout<<"Enter roll no : ";
    cin>>sd.rollno;

    cout<<"Enter Name : ";
    cin>>sd.name;

    cout<<"Enter division : ";
    cin>>sd.div;

    cout<<"Enter Address : ";
    cin>>sd.address;

    fd.write((char *)&sd , sizeof(sd));

    cout<<"Successfully added the contents \n";
}

int main(){

    FileHandling fobj;

    fobj.createFile();
    fobj.writetoFile();
    fobj.displayFile();



    return 0;
}