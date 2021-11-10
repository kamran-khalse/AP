#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct Contact {
    string first_name;
    string last_name;
    vector<string> phone_numbers;
};

using ContactList = vector<Contact>;

Contact search_by_name(ContactList &contacts, string name);

Contact search_by_family(ContactList &contacts, string family);

Contact search_by_phone(ContactList &contacts, const string phone_number);

void delete_contact(ContactList &contacts);

void add_contact(ContactList &contacts);

void print_contacts(const ContactList &contacts);

void sort_by_family(ContactList &contacts);

void print_menu();

string standard_name(string name);

int main() {
    ContactList contacts;
    bool doSelect=true;
    contacts.push_back(Contact{"ali", "Reza", vector<string>{"123", "09121212121"}});
    contacts.push_back(Contact{"Gholi", "Faza", vector<string>{"567"}});
    contacts.push_back(Contact{"Ali", "Gholi", vector<string>{"12", "33", "23"}});
    contacts.push_back(Contact{"Soltan ali reza", "Gholi", vector<string>{"12", "33", "3213231312"}});
    while(doSelect)
    {
        char select;
        print_menu();
        fflush(stdin);
        select=getchar();
        if(select=='a')
        {
            add_contact(contacts);
        }
        if(select=='b')
        {
            delete_contact(contacts);
        }
        if(select=='c')
        {
            print_contacts(contacts);
        }
        if(select=='d')
        {
            sort_by_family(contacts);
        }
        if(select=='e')
        {

        }
        if(select=='f'){return 0;}
    }
}

void print_menu() {
    cout<<"Select the operation you want\n";
    cout<<" a : Add a new person to the phonebook\n";
    cout<<" b : Delete a person from the phonebook\n";
    cout<<" c : View all phonebook people\n";
    cout<<" d : Sort phonebook by last name\n";
    cout<<" e : Search for a person by first name, last name or phone number\n";
    cout<<" f : Exit the app\n";
    cout<<"\nEnter your selection :";
}

void add_contact(ContactList &contacts) {
    Contact contact;
    // Get data
    string fName ,lName ,phone;
    // first letters should be upper case -> use standard_name()
    cout<<"\nEnter FirstName :";
    cin>>fName;
    contact.first_name=standard_name(fName);
    cout<<"\nEnter LastName :";
    cin>>lName;
    contact.last_name = standard_name(lName);

    int counterOfPhoneNumbers=0;
    // check if phone numbers are less than 3 or not
    string next;
    while(counterOfPhoneNumbers<3)
    {
        cout<<endl<<counterOfPhoneNumbers+1<<"_Phone Number :";
        cin>>phone;
        contact.phone_numbers.push_back(phone);

        cout<<"Next Phone Number (Y/N) ?";
        cin>>next;
        if(next=="N")
        {
            break;
        }
        counterOfPhoneNumbers++;
    }

    contacts.push_back(contact);
}

void delete_contact(ContactList &contacts) {
    // get name or family or number
    int selectNum;
    bool doSearch=true;
    string fName ,lName ,PhoneNumber;

    while(doSearch)
    {
        cout<<"\nDelete Contact (Based on):\n1_First_Name\n2_Last_Name\n3_PhoneNumber\n4_Return to Pervious Page";
        cout<<"\nEnter Select num :";
        cin>>selectNum;
        if(selectNum==1)
        {
            cout<<"\nEnter First Name :";
            Contact Cnt;
            cin>>fName;
            Cnt=search_by_name(contacts,fName);
            for(int i=0;i<contacts.size();i++)
            {
                if((contacts[i].first_name==Cnt.first_name)&&(contacts[i].last_name==Cnt.last_name))
                {
                    contacts.erase(contacts.begin()+i);
                }
            }
        }
        if(selectNum==2)
        {
            cout<<"\nEnter Last Name :";
            Contact Cnt;
            cin>>lName;
            Cnt=search_by_family(contacts,lName);
            for(int i=0;i<contacts.size();i++)
            {
                if((contacts[i].first_name==Cnt.first_name)&&(contacts[i].last_name==Cnt.last_name))
                {
                    contacts.erase(contacts.begin()+i);
                }
            }

        }
        if(selectNum==3)
        {
            cout<<"\nEnter PhoneNumber:";
            Contact Cnt;
            cin>>PhoneNumber;
            Cnt=search_by_phone(contacts,PhoneNumber);
            for(int i=0 ;i<contacts.size();i++)
            {
                if(Cnt.phone_numbers.size()==contacts[i].phone_numbers.size())
                {
                    for(int j=0;j<Cnt.phone_numbers.size();j++)
                    {
                        if(Cnt.phone_numbers[j]==contacts[i].phone_numbers[j])
                        {
                            contacts.erase(contacts.begin()+i);
                        }
                    }
                }
            }
        }
        if(selectNum==4)
        {
            doSearch=false;
        }
    }
    // using one of the search functions
    // delete the contact
    // return 0 to invalid contact
    // return 1 to successful delete
}

void print_contacts(const ContactList &contacts) {
    string line = "-----|------------------------|--------------------------|-------------------------------\n";
    cout << "  #  |                  Name  |                  Family  |          Phone numbers" << endl;
    cout << line;//16|18
    for (int i = 0; i < contacts.size(); ++i) {

        cout << setw(3) << i + 1 << "  |";
        cout << setw(22) << contacts[i].first_name << "  |";
        cout << setw(24) << contacts[i].last_name << "  |";
        cout << setw(22) << contacts[i].phone_numbers[0];

        if (contacts[i].phone_numbers.size() > 1) {
            cout << endl;
            for (int j = 0; j < contacts[i].phone_numbers.size() - 1; ++j) {
                cout << setw(6) << "  |" << setw(25) << "  |" << setw(27) << "  |";
                cout << setw(22) << contacts[i].phone_numbers[j + 1] << endl;
            }
        }else{
            cout << endl;
        }

        cout << line;
    }

}

Contact search_by_name(ContactList &contacts, string name) {
    ContactList same_name;
    name = standard_name(name);
    for (int i = 0; i < contacts.size(); ++i) {
        if (name == standard_name(contacts[i].first_name)) {
            same_name.push_back(contacts[i]);
        }
    }

    if (same_name.size() == 1) {
        return same_name[0];
    } else if (same_name.empty()) {
        cout << "There is no contact with this name" << endl;
        return Contact{string(""), string(""), vector<string>{}};
    } else {
        int position;
        cout << "There is several contact with this name, as shown below:" << endl;
        print_contacts(same_name);
        cout << "Which " << name << " do you mean?" << endl;
        cout << "Enter the number: ";
        cin >> position;
        return same_name[position - 1];
    }
}

string standard_name(string name) {
    string result = name;
    if (name[0] >= 'a' && name[0] <= 'z') {
        result[0] -= 32;
    }

    return result;
}

Contact search_by_family(ContactList &contacts,string family) {
    ContactList same_family;
    family = standard_name(family);
    for (int i = 0; i < contacts.size(); ++i) {
        if (family == standard_name(contacts[i].last_name)) {
            same_family.push_back(contacts[i]);
        }
    }

    if (same_family.size() == 1) {
        return same_family[0];
    } else if (same_family.empty()) {
        cout << "There is no contact with this last name" << endl;
        return Contact{string(""), string(""), vector<string>{}};
    } else {
        int position;
        cout << "There is several contact with this last name, as shown below:" << endl;
        print_contacts(same_family);
        cout << "Which " << family << " do you mean?" << endl;
        cout << "Enter the number: ";
        cin >> position;
        return same_family[position - 1];
    }
}

Contact search_by_phone(ContactList &contacts, const string phone_number) {
    ContactList x;
    for (int i = 0; i < contacts.size(); ++i) {
        for (int j = 0; j < contacts[i].phone_numbers.size(); ++j) {
            if (phone_number == contacts[i].phone_numbers[j]) {
                x.push_back(contacts[i]) ;
                break;
            }
        }
    }
    if(x.empty()){
        cout << "There is no contact with this phone number" << endl;
    }else if (x.size() > 1){
        int pos;
        cout << "Which contact do you mean?" << endl;
        print_contacts(x);
        cout << "Enter number: " << pos;
        cin >> pos;
        return x[pos-1];
    }
    return x[0];
}

void sort_by_family(ContactList &contacts)
{
    int flag;
    Contact temp;
    for (int k=1;k<contacts.size(); k++)
    {
        flag=0;

       for (int i=0; i< contacts.size()-k; i++)
       {
         if (contacts[i].last_name < contacts[i+1].last_name)
           {
                temp=contacts[i];
                contacts[i]=contacts[i+1];
                contacts[i+1]=temp;
                flag=1;
           }
       }
       if(flag==0){break;}

    }

}
