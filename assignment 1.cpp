


#include <iostream>
using namespace std;
class flight {
private:
    
    
    int flight_id = 0;
    string model;
    int capacity = 0;
    string airline;
    string destination;
    string departure_time;
    double ticket_price = 0;


public:

    flight(int f_id, string mod, int capa, string air__line, string dest_ination, string departure__time, double tick_price)
    {
        flight_id = f_id;
        model = mod;
        capacity = capa;
        airline = air__line;
        destination = dest_ination;
        departure_time = departure__time;
        ticket_price = tick_price;


        


    }
    flight() 
    {
    
    }

    void set_flight_id(int f_id)
    {
        flight_id = f_id;
    }

    void setmodel(string mod)
    {
        model = mod;
    }
    void setcapacity(int cap) {
        capacity = cap;
    }
    void setairline(string air_line)
    {
        airline = air_line;
    }
    void setdestination(string dest)
    {
        destination = dest;
    }
    void setdeparturetime(string deptime)
    {
        departure_time = deptime;
    }
    void setticketprice(double price)
    {
        ticket_price;
    }

    int get_flight_id() 
    {
       return flight_id;
    }
    string getmodel()
    {
        return model;
    }
    int getcap()
    {
        return capacity;
    }
    string getairline() 
    {
       return airline;
    }
    string getdestination() 
    {
       return destination;
    }
    string getdeparturetime()
    {
       return departure_time;
    }
    double getticketprice()
    {
        return ticket_price;
    }



    void display_flight_info()
    {
        cout << flight_id << endl;
        cout << model << endl;
        cout << capacity << endl;
        cout << airline << endl;
        cout << destination << endl;
        cout << departure_time << endl;
        cout << ticket_price << endl;

        cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        
        
    }

   







};
template <class T>

class node 
{
private:
    node<flight>* next;
    T data;
public:
   
    node(T E)
    {
        data = E;
        next = NULL;
    }


    void setnext(node<flight>* n)
    {
        next = n;
    }

    node<T>* getnext()
    {
        return next;
    }

    void setdata(T E)
    {
        data =  E;
    }
    T& getdata()
    {
        return data;
    }


};
template <class T>
class flightlist
{
private:
    node<T>* head;

public:
    flightlist()
    {
        head = NULL;
    }

    void sethead(node<T>* h)
    {
        head = h;
    }
    node<T>* gethead()
    {
        return head;
    }

    void addflight(T f)
    {
        if (head == NULL)
        {
            head = new node<T>(f);
        }
        else
        {
            node<T>* tmp = head;
            while (tmp->getnext() != NULL)
            {
                tmp = tmp->getnext();
            }
            node<T>* newnode = new node<T>(f);
            tmp->setnext(newnode);
        }
    }

    bool deleteflight(int fid)
    {
        node<T>* tmp = head;
        if (tmp == NULL)
        {
            cout << "There is no items in linked list" << endl;
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
            return false;
        }
        else if (tmp->getdata().get_flight_id() == fid && tmp == head)
        {
            head = head->getnext();
            delete tmp;
            cout << "You deleted the head" << endl;
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        }
        else
        {
            while (tmp->getnext() != NULL && fid != tmp->getnext()->getdata().get_flight_id())
            {
                tmp = tmp->getnext();
            }
            if (tmp->getnext() == NULL) {
                cout << "There is no flight with this ID" << endl;
                cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
                return false;
            }
            node<T>* toDelete = tmp->getnext();
            tmp->setnext(tmp->getnext()->getnext());
            delete toDelete;
            return true;
        }
    }

    void display_all()
    {
        node<T>* tmp = head;
        while (tmp != NULL)
        {
            tmp->getdata().display_flight_info();
            tmp = tmp->getnext();
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        }
        
    }
};

template <class T>
class flightstack
{
private:
    node<T>* top;
public:
    void settop(node<T>* tp)
    {
        top = tp;
    }
    node<T>* gettop()
    {
        return top;
    }

    flightstack()
    {
        top = NULL;
    }

    bool isempty()
    {
        return top == NULL;
    }

    T peek()
    {
        if (isempty())
        {
            cout << "There is no elements in this stack" << endl;
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
            return T();
        }
        else
        {
            
            top->getdata().display_flight_info();  
            return top->getdata(); 
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        }
    }
    void push(T data)
    {
        node<T>* newNode = new node<T>(data);
        newNode->setnext(top);
        top = newNode;
    }
    
    void printstack()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        }
        else
        {
            node<T>* tmp = top;
            while (tmp != NULL)
            {
                tmp->getdata().display_flight_info();
                tmp = tmp->getnext();
                cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
            }
        }
    }
    void delete_element_in_stack()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            cout << "////////////////////////////////////////// SEPERATOR //////////////////////////////////////////" << endl;
        }
        else
        {
            node<T>* tmp = top;
            top = top->getnext();
            delete tmp;
        }

    }

   void edit_element()
    {
        int o = 0;
        int in = 0;
        double bin = 0;
        string str_in;

        if (top == NULL)
        {
            cout << "No flights in stack" << endl;       

           
        }

        else if(top!=NULL)
        {
            cout << "To edit flight id input 1" << endl;
            cout << "To edit model input 2" << endl;
            cout << "To edit capacity input 3" << endl;
            cout << "To edit airline input 4" << endl;
            cout << "To edit destination input 5" << endl;
            cout << "To edit departure time input 6" << endl;
            cout << "To edit ticket price input 7" << endl;


            cin >> o;


            if (o == 1)
            {
                cout << "input new flight id:" << endl;
                cin >> in;
                top->getdata().set_flight_id(in);
            }
            else if (o == 2)
            {
                cout << "input new model:" << endl;
                cin >> str_in;
                top->getdata().setmodel(str_in);
            }
            else if (o == 3)
            {
                cout << "input new capacity:" << endl;
                cin >> in;
                top->getdata().setcapacity(in);
            }
            else if (o == 4)
            {
                cout << "input new airline:" << endl;
                cin >> str_in;
                top->getdata().setairline(str_in);
            }
            else if (o == 5)
            {
                cout << "input new destination:" << endl;
                cin >> str_in;
                top->getdata().setdestination(str_in);
            }
            else if (o == 6)
            {
                cout << "input new departure time:" << endl;
                cin >> str_in;
                top->getdata().setdeparturetime(str_in);
            }
            else if (o == 7)
            {
                cout << "input new ticket price:" << endl;
                cin >> bin;
                top->getdata().setticketprice(bin);
            }

        }
 
        

       
    }


};

int main()
{
 
    
    




    flight f1;
    flightlist<flight> fl;
    flightstack<flight> fs;
    int maininput = 0;
mainmenu:
    maininput = 0;
    cout << "Input 1 to use linked list" << endl;
    cout << "Input 2 to use stack" << endl;
    cout << "Input 3 to completely close program" << endl;
    cin >> maininput;
    if (maininput != 1 && maininput != 2 && maininput != 3)
    {
        goto mainmenu;
    }
    else if (maininput == 3)
    {
        goto exitcode;
    }
    else if (maininput == 1)
    {
        int subinput = 0; 

        cout << "To insert new flight input 1" << endl;
        cout << "To Delete flight input 2" << endl;
        cout << "To Display all flights input 3" << endl;
        cout << "To return to main menu input 4" << endl;
        cout << "To completely close program input 0" << endl;

        cin >> subinput;
        if (subinput == 4)
        {
            goto mainmenu;
        }
        else if (subinput == 1)
        {
            cout << "Input Flight ID , Model , capacity , Airline , destination , Departure Time and Price  respectively" << endl;
            int lid; string lmodel; int lcap; string lairline; string ldestination; string ldeptime; double lprice;
            cin >> lid;
            cin >> lmodel;
            cin >> lcap;
            cin >> lairline;
            cin >> ldestination;
            cin >> ldeptime;
            cin >> lprice;
            flight f1(lid, lmodel, lcap, lairline, ldestination, ldeptime, lprice);
            fl.addflight(f1);

            goto mainmenu;
        }

        else if (subinput == 2)
        {
            int id_to_del = 0;
            cout << "Input ID of flight to delete" << endl;
            cin >> id_to_del;
            fl.deleteflight(id_to_del);
            goto mainmenu;
        }
        else if (subinput == 3)
        {
            fl.display_all();
            goto mainmenu;
        }
       


    }
    else if (maininput == 2)
    {
        int subinput = 0;

        cout << "To insert new flight input 1" << endl;
        cout << "To Check latest added flight input 2" << endl;
        cout << "To Print all flights  input 3" << endl;
        cout << "To Edit flight input 4" << endl;
        cout << "To Delete flight input 5" << endl;
        cout << "To retrun to main menu input 6" << endl;
        cout << "To close program input 0" << endl;

        cin >> subinput;

        if (subinput == 6)
        {
            goto mainmenu;
        }

        if (subinput == 0)
        {
            goto exitcode;
        }

        else if (subinput == 1)
        {
            cout << "Input Flight ID , Model , capacity , Airline , destination , Departure Time and Price  respectively" << endl;
            int sid; string smodel; int scap; string sairline; string sdestination; string sdeptime; double sprice;
            cin >> sid;
            cin >> smodel;
            cin >> scap;
            cin >> sairline;
            cin >> sdestination;
            cin >> sdeptime;
            cin >> sprice;
            flight f1(sid, smodel, scap, sairline, sdestination, sdeptime, sprice);
            fs.push(f1);

            goto mainmenu;
        }
        else if (subinput == 2)
        {
            fs.peek();

            goto mainmenu;
        }
        else if (subinput == 3)
        {
            fs.printstack();

            goto mainmenu;
        }
        else if (subinput == 4)
        {
            fs.edit_element();

            goto mainmenu;
        }
        else if (subinput == 5)
        {
            fs.delete_element_in_stack();

            goto mainmenu;
        }

    }

exitcode:
cout << "closing program" << endl;


   
}

