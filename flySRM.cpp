#include <iostream>
#include <string>
using namespace std;
class flySRM
{
    public:
    string from, to, feedback;
    int day, month, year, num, fclass, amt, booking, meal, luggage, ff, offer, date_fee; //global variables
    flySRM() //constructor to initialize global variables
    {
        from="";
        to="";
        day=0;
        month=0;
        year=0;
        num=0;
        fclass=0;
        amt=0;
        booking=0;
        meal=0;
        luggage=0;
        ff=0;
        offer=0;
        date_fee=0;
        feedback="You have not given a feedback as of now!\n";
    }
    public: void book() //function to book flights
    {
        if(booking==1)
        {
            cout<<"You already have a booking with flySRM!\n";
            return;
        }
        cout<<"From: ";
        cin>>from;
        cout<<"To: ";
        cin>>to;
        cout<<"Date: ";
        cin>>day>>month>>year;
        if(day<0 || month<0 || year<0 || (month==2 && day>29) || ((month==4 || month==6 || month==9 || month==11) && day>30) || day>31)
        {                   //checking if the entered date is valid or not
            cout<<"Invalid date entered! Please try again from the main menu!\n";
            return;
        }
        cout<<"Which class do you want to fly?";
        cout<<"\n1) Executive\n2) Business\nOther) Economy\n\nEnter your choice by entering the code: ";
        cin>>fclass;
        cout<<"Number of Passengers: ";
        cin>>num;
        if(fclass==1)
        amt=num*10000;
        else if(fclass==2)
        amt=num*7500;
        else
        amt=num*5000;
        cout<<"Do you want to book a meal? Press 1 to select YES, any other key for NO: ";
        cin>>meal;
        cout<<"Do you want extra luggage weight? Press 1 to select YES, any other key for NO: ";
        cin>>luggage;
        cout<<"Are you a frequent flyer? Press 1 to select YES, any other key for NO: ";
        cin>>ff;
        cout<<"We have some special offers for you! Select ONE that is applicable with the given codes, or press any other key to proceed";
        cout<<"\n1) Student Offer\n2) Defence Personnel Offer\n3) First Time flySRM Customer Offer\n4) Elders Offer\nEnter your choice: ";
        cin>>offer;
        booking=1; //setting booking to TRUE
        if(offer==1) //offers
        {
            cout<<"You have selected the STUDENT OFFER! You have received extra luggage priveliges and a discount of Rs.500 per pax!\n";
            amt=amt-num*500;
            luggage=1;
        }
        else if(offer==2)
        {
            cout<<"You have selected the DEFENCE PERSONNEL OFFER! You have received a FREE MEAL and an upgrade to BUSINESS CLASS!\n";
            meal=1;
            fclass=2;
        }
        else if(offer==3)
        {
            cout<<"You are a FIRST TIME flySRM CUSTOMER! Please enjoy a FREE MEAL from our side and a discount of flat Rs.1000!\n";
            meal=1;
            amt=amt-1000;
        }
        else if(offer==4)
        {
            cout<<"You have selected the ELDERS OFFER! Please enjoy the comfort of BUSINESS CLASS and a discount of flat Rs.1500!\n";
            fclass=2;
            amt=amt-1500;
        }
        else if(ff==1)
        {
            cout<<"Thank you for trusting flySRM! You have received a free upgrade to BUSINESS CLASS on the house!\n";
            fclass=2;
        }
        cout<<"Please pay Rs."<<amt<<" through any method like debit card, credit card or UPI in the next 5 minutes.";
        cout<<"\n\nThank you for booking your flight with flySRM! Looking forward to seeing you in the skies with us!";
        cout<<"\n\nDo you want to see a summary of your booking?";
        cout<<"\nPress 1 to see booking summary or any other to proceed to the main menu...";
        int ch;
        cin>>ch;
        if(ch==1) //viewing it once after booking
        view();
    }
    public: void view() //viewing booking details
    {
        if(booking==1)
        {
            cout<<"Your booking\n\n";
            cout<<"From: "<<from;
            cout<<"\nTo: "<<to;
            cout<<"\nDate of Departure: "<<day<<" / "<<month<<" / "<<year;
            cout<<"\nClass: ";
            if(fclass==1)
            cout<<"Executive";
            else if(fclass==2)
            cout<<"Business";
            else
            cout<<"Economy";
            cout<<"\nNumber of Passengers: "<<num;
            cout<<"\nMeal: ";
            if(meal==1)
            cout<<"YES";
            else
            cout<<"NO";
            cout<<"\nExtra Luggage: ";
            if(luggage==1)
            cout<<"YES";
            else
            cout<<"NO";
            cout<<"\nAmount: Rs."<<amt;
            cout<<"\nYour Feedback: "<<feedback;
            cout<<"\n\nSeats are assigned on a first come-first serve basis for free.";
            cout<<"\n\nExtra luggage and meal costs will be assigned at the check-in counter if applicable.";
        }
        else
        {
            cout<<"\nYou don't have an active booking with us right now!";
            cout<<"\nDo you want to book a flight? Press 1 for YES, any other key for NO: ";
            int ch;
            cin>>ch;
            if(ch==1)
            book();
        }
    }
    public: void edit() //editing global variables if required
    {
        cout<<"\nWhat do you want to edit?";
        cout<<"\n1) Date\n2) Class\n3) Meal\n4) Luggage\n5) Offer\n\nUse the codes to select or press any other key to go back to the main menu: ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nEnter the new Date: ";
            cin>>day>>month>>year;
            if(day<0 || month<0 || year<0 || (month==2 && day>29) || ((month==4 || month==6 || month==9 || month==11) && day>30) || day>31)
            {
                cout<<"Invalid date entered! Please try again from the main menu!\n";
                return;
            }
            cout<<"Since you changed the date, an extra fee of Rs.750 has been applied per pax\n";
            amt=amt+num*750;
            date_fee=750;
            break;
            case 2:
            cout<<"\nWhich class do you want to fly?";
            cout<<"\n1) Executive\n2) Business\nOther) Economy\n\nEnter your choice by entering the code: ";
            cin>>fclass;
            break;
            case 3:
            cout<<"\nDo you want to book a meal? Press 1 to select YES, any other key for NO: ";
            cin>>meal;
            break;
            case 4:
            cout<<"\nDo you want extra luggage weight? Press 1 to select YES, any other key for NO: ";
            cin>>luggage;
            break;
            case 5:
            if(fclass==1)
            amt=num*10000;
            else if(fclass==2)
            amt=num*7500;
            else
            amt=num*5000;
            cout<<"We have some special offers for you! Select ONE that is applicable with the given codes, or press any other key to proceed";
            cout<<"\n1) Student Offer\n2) Defence Personnel Offer\n3) First Time flySRM Customer Offer\n4) Elders Offer\nEnter your choice: ";
            cin>>offer;
            if(offer==1)
            {
                cout<<"You have selected the STUDENT OFFER! You have received extra luggage priveliges and a discount of Rs.500 per pax!";
                amt=amt-num*500;
                luggage=1;
            }
            else if(offer==2)
            {
                cout<<"You have selected the DEFENCE PERSONNEL OFFER! You have received a FREE MEAL and an upgrade to BUSINESS CLASS!";
                meal=1;
                fclass=2;
            }
            else if(offer==3)
            {
                cout<<"You are a FIRST TIME flySRM CUSTOMER! Please enjoy a FREE MEAL from our side and a discount of flat Rs.1000!";
                meal=1;
                amt=amt-1000;
            }
            else if(offer==4)
            {
                cout<<"You have selected the ELDERS OFFER! Please enjoy the comfort of BUSINESS CLASS and a discount of flat Rs.1500!";
                fclass=2;
                amt=amt-1500;
            }
            else if(ff==1)
            {
                cout<<"Thank you for trusting flySRM! You have received a free upgrade to BUSINESS CLASS on the house!";
                fclass=2;
            }
            amt+=date_fee;
            break;
            cout<<"Please pay Rs."<<amt<<" through any method like debit card, credit card or UPI in the next 5 minutes.";
            cout<<"\n\nThank you for booking your flight with flySRM! Looking forward to seeing you in the skies with us!";
            cout<<"\n\nDo you want to see a summary of your updated booking?";
            cout<<"\nPress 1 to see booking summary or any other to proceed to the main menu...";
            int ch;
            cin>>ch;
            if(ch==1)
            view();
        }
    }
    public: void cancel() //cancelling the booking
    {
        cout<<"\nDo you want to cancel the booking made for "<<num<<" pax on "<<day<<" / "<<month<<" / "<<year<<" from "<<from<<" to "<<to<<"?";
        cout<<"\nPress 1 to CANCEL THE BOOKING, or any other key to proceed to the main menu: ";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            cout<<"You have cancelled the booking :-<\nSee you soon on flySRM!\n";
            booking=0;
        }
    }
    public: void customer_feedback()
    {
        cout<<"Please enter your feedback here: ";
        cin>>feedback;
        cout<<"Thank you for giving us for valuable feedback!\n";
    }
};
int main() //main function to call other functions
{
    int i=1, ch;
    flySRM obj; //class object to call functions
    while(i!=0) //will run as long as you enter a non-menu value
    {
        cout<<"WELCOME TO THE flySRM EASY TICKET BOOKING SYSTEM!";
        cout<<"\n\nHow can we help you today?\n\nI want to";
        cout<<"\n1) Book a Flight...";
        cout<<"\n2) View my Booking...";
        cout<<"\n3) Edit my Booking...";
        cout<<"\n4) Cancel my Booking...";
        cout<<"\n5) Give Feedback for flySRM...";
        cout<<"\n\nPress the numbers to select an option, or press any other key to exit: ";
        cin>>ch;
        switch(ch) //simple switch case to pick the function to be called
        {
            case 1:
            obj.book();
            break;
            case 2:
            obj.view();
            break;
            case 3:
            obj.edit();
            break;
            case 4:
            obj.cancel();
            break;
            case 5:
            obj.customer_feedback();
            break;
            default:
            i=0;
            break;
        }
    }
    cout<<"\n\nThank you for considering flySRM! See you soon!";
}