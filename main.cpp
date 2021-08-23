#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class BankOperations
{
    private:
        long custid;
        string name;
        double balance;
        long shareno;

    public:
        void Newcustomerinput1();
        void printcustomerinfo2();
        void customerlist3();
        void sortarray(long [], int);
        void customerlistbelowAMB4();
        void customerlistshares5();
 
};

//function for entering new customer information


void BankOperations::Newcustomerinput1()
{
    
    
    cout<<"\nEnter Name of the customer:  ";
    cin>>name;

    cout<<"\nEnter customer id:  ";
    cin>>custid;

    cout<<"\nEnter account balance:  ";
    cin>>balance;

    cout<<"\nDoes customer have any no. of the shares: ";
    cin>>shareno;
    
    ofstream obj1;
    ofstream objbank("bankfile.txt",ios::app);

    string a = name;
    a.insert(name.length(),".txt"); 
    obj1.open(a);

    obj1<<custid<<" "<<name<<" "<<balance<<" "<<shareno<<endl;
    objbank<<custid<<" "<<name<<" "<<balance<<" "<<shareno<<endl;
    
}

//function for giving info of a customer

void BankOperations::printcustomerinfo2()
{
    
    // ifstream obj2("bankfile.txt");
    // cout<<"\n------------------------------------------------------------------------\n";
    // cout<<"Account ID"<<"    "<<"Account No. "<<"     "<<"Name"<<"     "<<"Current balance"<<"     "<<"Account Type"<<endl;                         
    // cout<<"------------------------------------------------------------------------\n\n";
    // while(obj2>>nam>>ao>>ae>>ad>>cl)
    // {
        
    //     cout<<ad<<"             "<<ao<<"                "<<nam<<"        "<<cl<<"                   "<<ae<<endl;
          
    // }
    // string var_name;
    // long var_custid;
    cout<<"Enter name and customer id : \nName = ";
    cin>>name;
    cout<<"\nCustomer Id = ";
    cin>>custid;

    cout<<"\n------------------------------------------------------------------------\n";
    cout<<"ID\t\t\t"<<"Name\t\t\t"<<"Balance\t\t\t"<<"Shares\t\t\t"<<endl;                         
    cout<<"------------------------------------------------------------------------\n\n";


    string a = name;
    a.insert(name.length(),".txt");
    ifstream obj2;
    obj2.open(a);

    while (obj2>>custid>>name>>balance>>shareno)
    {
        cout<<custid<<"\t\t\t"<<name<<"\t\t\t"<<balance<<"\t\t\t"<<shareno<<endl;
    }
    

}

//function for sort array using insertion sort in descending order

void BankOperations::sortarray(long a[], int n)
{
    int j,i=1;
    long temp;

    cout<<"Before: [";
    for(j=0;j<n;j++){
        cout<<a[j]<<" ";
    } cout<<"]\n";

    for(i=1;i<n;i++){
        temp  = a[i];
        j = i-1;
        while(j>=0 && a[j]<temp){
            a[j+1] = a[j];
            j = j-1;
            a[j+1] = temp;
        }
    } 
    
    cout<<"\nAfter: [";
    for(j=0;j<n;j++){
        cout<<a[j]<<" ";
    } cout<<"]\n";

    
}

//function for printing highest current baalnce accounts accesing from the files

void BankOperations::customerlist3()
{
    long cl,arr[10];
    int i = 0;
    ifstream obj2("bankfile.txt");
    while(obj2>>custid>>name>>balance>>shareno)
    {
        
        arr[i] = custid;
        i++;
        
    }
    
    sortarray(arr,i);

    cout<<"\n------------------------------------------------------------------------\n";
    cout<<"ID\t\t\t"<<"Name\t\t\t"<<"Balance\t\t\t"<<"Shares\t\t\t"<<endl;                         
    cout<<"------------------------------------------------------------------------\n\n";

    int j=0;
    while(obj2>>custid>>name>>balance>>shareno){
        
        for(j;j<i;j++){

        if(arr[j] == custid)
        {
            cout<<custid<<"\t\t\t"<<name<<"\t\t\t"<<balance<<"\t\t\t"<<shareno<<endl;
        }

        }
    }

}

void BankOperations::customerlistbelowAMB4()
{
    ifstream obj3("bankfile.txt");
    while(obj3>>custid>>name>>balance>>shareno)
    {
        if(balance<=10000){
            cout<<custid<<"\t\t\t"<<name<<"\t\t\t"<<balance<<"\t\t\t"<<shareno<<endl;
        }
    }
}

void BankOperations::customerlistshares5()
{
    ifstream obj4("bankfile.txt");
    while(obj4>>custid>>name>>balance>>shareno)
    {
        if(shareno>0){
            cout<<custid<<"\t\t\t"<<name<<"\t\t\t"<<balance<<"\t\t\t"<<shareno<<endl;
        }
    }
}

int main()
{
    int input;
    char ch='n';
    BankOperations b;
    while (ch=='n')
    {
        
        cout<<"\n\n1.Add New Customer\n\n2.Access the existing customer information\n\n3.All customers list\n\n4.Below AMB customers (Average Monthly Balance)\n\n5.List of Customers holding shares of the bank\n\n6.Close Program\n\nEnter: ";
        cin>>input;

        switch(input)
        {
            case 1:     b.Newcustomerinput1();
                        cout<<"\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
                        break;

            case 2:     b.printcustomerinfo2();
                        cout<<"\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
                        break;

            case 3:     b.customerlist3();
                        cout<<"\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
                        break;
            
            case 4:     b.customerlistbelowAMB4();
                        cout<<"\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
                        break;

            case 5:     b.customerlistshares5();
                        cout<<"\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
                        break;

            case 6:     cout<<"\nProgram Closed"<<endl;
                        ch ='y';
                        break;
            
            default:    
                        cout<<"\nWrong Choice\nPress 'n' to exit to main menu\nInput: ";
                        cin>>ch;
        

        }
    }
    
    
    

}