#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<windows.h>
#include <stdio.h>
using namespace std;


                   //information taking class
class welcome
{ public:
    void welcome1()
   {
    
        cout<<"\t\t\t\t\tWelcome to ticket genereter softwer"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\tPlease enter the data as required  "<<endl;  
        cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"1.book the ticket"<<endl;
        cout<<"2.see the booked tickets"<<endl;
        cout<<"3.see available train"<<endl;
        cout<<"Enter exit to close this program"<<endl;

    }
}we;



class loading
{
    public:

    void loading_page()
    {
        system("COLOR 0e");
        system("cls");
        //printf ("*\e[?251") ;
        SetConsoleCP (437);
        SetConsoleOutputCP (437) ;
        int barl = 177, bar2 = 219;
        cout<< "\n\n\n\t\t\t\t Loading.....";
        cout << "\n\n\n\t\t\t\t";

        for(int i = 0; i < 25; i++)
        cout << (char)barl;

        cout<<"\r";

        cout <<"\t\t\t\t";

        for(int i=0;i<25;i++)
        {
            cout << (char)bar2;
            Sleep (100) ;
        }

        system("cls");
        // cout<<"\n\t\t\t\t"<<(char)1<<"!";
        // system("Pause");
    }

}lo;

class traveler_information
{
    public:
    //variable declaration
    string passenger_name,tem;
    string gender;
    int age;
    int male,female,total_passenger;
    long long int phonenumber;
    string journey_date;
       int day, month, year;
    string finaldate;


    //passenger detail taking function
        void prsonal_information()
        {

                cout<<endl<<"Enter passenger's name:";
                getline(cin>>ws, passenger_name);
                
                // re_enter_gender:
                // cout<<"Enter passenger's gender:";
                // cin>>gender;
                // if(gender!="male" )
                // {
                //     if(gender!="female")
                //     {
                //     cout<<"Enter valid data"<<endl;
                //     goto re_enter_gender;
                //     }                
                // }

                cout<<"Enter passenger's age:";
                cin>>age;
              
                cout<<"Enter phone number:";
                  reenterphonenumber:
                cin>>phonenumber;
                 if(phonenumber/10000000000!=0||phonenumber/1000000000==0)
                 {
                    cout<<"Enter valid phone number";
                    goto reenterphonenumber;
                }
                // cout<<"Enter jouney date:";
                // cin>>journey_date;
                    re_enter_date:
                      cout << "Enter journey date (dd mm yy): ";
                      cin >> day >> month >> year;
                      
                      if (day > 31 || day < 1 || month > 12 || month < 1 || year < 22)
                      {
                          cout << "Invalid date. Please re-enter.\n";
                          goto re_enter_date;
                      }
                      
                      finaldate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
            // if(gender=="male")
            // male++;
            // else if(gender=="female")
            // female++;
            cout<<"Enter total number of passenger:";
            cin>>total_passenger;
            cout<<"Enter total number of male passenger:";
            cin>>male;
            cout<<"Enter total number of female passenger:";
            cin>>female;

        }
};




class read_trainlist
{
    
    public:
    string temp;
    string temp1;
    string temp2;
    void read_available_trainlist()
    {
        fstream file;
        file.open("distancelist.txt");
        //file.seekg(0,ios::beg);
        while(file>>temp)
        {
        cout<<temp<<endl;   
        file>>temp1>>temp2;
        }
file.close();
    }
}trainlist_read;

class siting_arrangemante
{
    public:
    string seat_no;
    string cheak;
    int select_class;
    string selected_class_name;
    void seat()
    {
    reenter:
    cout<<"Select your class:"<<endl;
    cout<<"1.second sitting(2S)"<<endl;
    cout<<"2.sleeper"<<endl;
    cout<<"3.AC 3 Tier"<<endl;
    cout<<"4.AC 2 Tier"<<endl;
    cout<<"5.Executive"<<endl;
    cin>>select_class;

switch(select_class)
{
    case 1:
        selected_class_name="second_sitting(2s)";
        break;
    case 2:
        selected_class_name="sleeper";
        break;
    case 3:
        selected_class_name="AC_3_Tier";
        break;        
    case 4:
        selected_class_name="AC_2_Tier";
        break;
    case 5:
        selected_class_name="Executive";
        break;
}

    cout<<"Enter the seat number: ";
    cin>>seat_no; 
    fstream seatcheak;
    seatcheak.open("seatnumber.txt");
    while(seatcheak>>cheak)
    {
        if(cheak==(selected_class_name+"_"+seat_no)){
            cout<<"seat is already booked"<<endl;
            goto reenter;
        }
    }
    cout<<"seat is allocated"<<endl;

    fstream seatnumber;
    seatnumber.open("seatnumber.txt",ios::app);
    seatnumber<<" "<<selected_class_name+"_"+seat_no;
    seatnumber.close();
    }
}siting;





class destination :public siting_arrangemante
{
    public:
    string from;
    string to;
    string name_in_file_formate;
    int distance;
    int time;
    float total_amount;
        void taking_placedetail()
        {
            cout<<endl<<"From:";
            cin>>from;
            cout<<"To:";
            cin>>to;
            name_in_file_formate =from+"-"+to;
        }

        void check_train_avability()
        {
            string list;
            string read_city;
            fstream readlist;
            readlist.open("distancelist.txt");

            while(readlist>>read_city)
            {
                if(read_city==name_in_file_formate)
                {
                    cout<<read_city<<endl;
                    readlist>>distance;
                    //total_amount=distance*0.50;
                     switch(siting.select_class) {
                    case 1:
                        total_amount = distance * 0.50;
                        break;
                    case 2:
                        total_amount = distance * 0.70;
                        break;
                    case 3:
                        total_amount = distance * 0.80;
                        break;
                    case 4:
                        total_amount = distance * 0.90;
                        break;
                     }
                    readlist>>time;
                }
        

            }
            
            readlist.close();
        }

}destination;



//------------------------------------------------------------------------------------------------------------
                          //file formating class


class file_formating
{
    public:
    void file__start()
    {
        //string date;
        string day;
           int day1, month1, year1;
           string finaldate;
       // cout<<"Enter date as 'dd/mm/yyyy':";
        //cin>>date;
                            re_enter_date:
                      cout << "Enter date (dd mm yy): ";
                      cin >> day1 >> month1 >> year1;
                      
                      if (day1 > 31 || day1 < 1 || month1 > 12 || month1 < 1 || year1 < 22)
                      {
                          cout << "Invalid date. Please re-enter.\n";
                          goto re_enter_date;
                      }
                      
                      finaldate = to_string(day1) + "/" + to_string(month1) + "/" + to_string(year1);
        cout<<"Enter day:";
        cin>>day;
        fstream file;
        file.open("bookedticket.txt", ios::app);
        file<<"Date:"<<finaldate<<endl;
        file<<"Day:"<<day<<endl;
        file.close();
    }


 void print_file(traveler_information &t)    {
 fstream out;
 out.open("bookedticket.txt",ios::app);
            out << "****************************************************************************" << endl;
            out << "*                             GUJRAT RAILWAY                               *" << endl;
            out << "****************************************************************************" << endl;
            out << "*                              TRAIN TICKET                                *" << endl;
            out << "****************************************************************************" << endl;
            out <<"Passenger Name "<<"        :"<<t.passenger_name<<endl;
            out << "Phone number   "<<"       :"<<left<<setw(15)<<t.phonenumber;
            out << "\t\t\t\tDeparture City "<<"       :"<<left<<setw(15)<<destination.from<<endl;
            out << "Destination City "<<"     :"<<left<<setw(15)<<destination.to;
            out << "\t\t\t\tDistance"<<"              :"<<left<<setw(3)<<destination.distance<<"Km"<<endl;
            out << "Time"<<"                  :"<<left<<setw(2)<<destination.time<<"Hr    ";
            out << "\t\t\t\t\t\tJourney Date "<<"     :"<<left<<setw(15)<<t.finaldate<<endl;
            out << "Journey Time "<<"         :"<<left<<setw(15)<<destination.time;
            out << "\t\t\t\tAge"<<"                   :"<<left<<setw(15)<<t.age<<endl;
            out << "Total passenger"<<"       :"<<left<<setw(15)<<t.total_passenger;
            out << "\t\t\t\tTotal male passenger"<<"  :"<<left<<setw(15)<<t.male<<endl;
            out << "Total female passenger"<<":"<<left<<setw(15)<<t.female<<endl;
            // out << "  Seat Number "<<"       :"<<seat_no << endl<<endl;
            out<<"\t\t\t\t\t\tYour final price is"<<" :"<<destination.total_amount<<"Rs"<<endl;
            out << "***************************************************************************"<<endl<<endl;
       }        


    
    
    void file__end()
    {
            fstream file;
        //file ending formating 
        file.open("bookedticket.txt", ios::app);
        file<<"--------------------------------------------------------------------------------------------"<<endl;
        file.close();
    }
}formating;

class read_booked_ticket
{public:

    string date_of_data;
    string first,second;
    void read_tickets(){
       cout<<"data of which date you want(enter date as dd/mm/yy):";
       cin>>date_of_data;
       fstream file;
       file.open("bookedticket.txt");
       while(!file.eof( )){
        file>>first;
        if(first=="Date:"+date_of_data){

            for(int i=0;i<15;i++){
            getline(file,second);
            cout<<second<<endl;
            }
           //break;
        }
       }
file.close();
    }
}booked_tickets;
 
// //class consol_display
// {
//     public:
//     void display(traveler_information &z)
//     {
//      cout << "****************************************************************************" << endl;
//      cout << "*                             GUJRAT RAILWAY                               *" << endl;
//      cout << "****************************************************************************" << endl;
//      cout << "*                              TRAIN TICKET                                *" << endl;
//      cout << "****************************************************************************" << endl;
//      cout <<"Passenger Name "<<"    :"<<left<<setw(25)<<z.passenger_name<<endl;
//      cout << "Phone number   "<<"    :"<<setw(15)<<z.phonenumber;
//      cout << "\t\t\t\tDeparture City "<<"    :"<<setw(15)<<destination.from<<endl;
//      cout << "Destination City "<<"  :"<<setw(15)<<destination.to;
//      cout << "\t\t\t\tDistance"<<"           :"<<setw(3)<<destination.distance<<"Km"<<endl;
//      cout << "Time"<<"               :"<<setw(2)<<destination.time<<"Hr";
//      cout << "\t\t\t\tJourney Date "<<"      :"<<setw(15)<<z.journey_date;
//      cout << "Journey Time "<<"      :"<<setw(15)<<destination.time<<endl;
//      cout << "\t\t\t\tAge"<<"                :"<<setw(15)<<z.age;
//      cout << "Gender"<<"             :"<<setw(15)<<z.gender<<endl;
//      // out << "  Seat Number "<<"       :"<<seat_no << endl<<endl;
//      cout<<"\t\t\t\t\t\tYour final price is"<<" :"<<destination.total_amount<<"Rs"<<endl;
//      cout << "***************************************************************************"<<endl<<endl;

//     }
// }consol;
//-----------------------------------------------------------------------------------------------

                                 //main function


int main()
{
    string choice;
    start2:
    start1:
    we.welcome1();
            cin>>choice;
            system("cls");
            lo.loading_page();
    if(choice=="1"){
                // int number_of_passengers;
                // cout<<endl<<"Enter total number's of passengers:";
                // cin>>number_of_passengers;

//traveler_information information[number_of_passengers];
traveler_information information;
formating.file__start();
//for(int i=0;i<number_of_passengers;i++){
//information[i].prsonal_information();
information.prsonal_information();
destination.taking_placedetail();

siting.seat();
destination.check_train_avability();
//formating.print_file(information[i]);
formating.print_file(information);
formating.file__end();
goto start1;
}


else if(choice=="2"){
booked_tickets.read_tickets();
}

else if(choice=="3")
{
    trainlist_read.read_available_trainlist();
    goto start2;
}
//consol.display(information[i]);
//}
else if(choice=="exit")
{
    SetConsoleOutputCP(CP_UTF8);
    cout<<"Thank you for using this program 🙏";
     
}

return 0; 

}
