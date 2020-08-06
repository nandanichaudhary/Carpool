#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
T get_input(const string &strQuery);
string get_username();
string get_password();
void save_user(const string &username, const string &password);
void login();
void register_user();
void main_menu();

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();
    while (!(cin >> out))
    {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << "\t\t\t\t\tError!" "\n";
    }
    return out;
}
/////
string get_password()
{
    string password1 = get_input <string> ("\t\t\tPlease enter your password.");
    string password2 = get_input <string> ("\t\t\tPlease re-enter your password.");

    while (password1 != password2)
    {
        cout << "\t\t\t\t\tError! Passwords do not match." "\n";
        password1 = get_input <string>("\t\t\tPlease enter your password.");
        password2 = get_input <string>("\t\t\tPlease re-enter your password.");
    }
    return password1;
}
/////
string get_username()
{
    string username = get_input <string>("\t\t\tPlease enter a Username.");
    cout << "\t\t\tUsername: " << username << "\t\t";

    while (get_input <int>("\t\t\tIf you wish to confirm your Username please enter 1.") != 1)
    {
        username = get_input <string>("\t\t\tPlease enter a Username.");
        cout << "\t\t\tUsername: " << username << "\t\t";
    }
    return username;
}
/////
void login()
{
    string line = " ";
    ifstream readFile("userandpassword.txt");
    string UserName;
    string Password;
    string _UserName;
    string _Password;
    cout << "\n\n\t\t\t\t\tEnter UserName: ";
    cin >> UserName;
    cout << "\n\n\t\t\t\t\tEnter Password: ";
    cin >> Password;
    cout<<"\n\n";
    bool found = false;

    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> _UserName >> _Password;
        if (UserName == _UserName && Password == _Password)
        {
            cout<<"\t\t\t\t\t\t";

            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "\n\t\t\t\t\tLogin Successful!\n"<< endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\n\n\t\t\t\t\tInvalid Username And Password\n\n"<< endl;
        cout<<"\n\n\t\t\t\tTo Register press 1 and for trying Logging again press 2\n\n"<<endl;
        int choice;
        cout<<"\t\t\t\t\t";
        A:
        cin>>choice;
        switch(choice)
        {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            default:
            cout<<"\n\nWrong input. Please choose again.\n> ";
            goto A;
        }
    }

}
/////
void main_menu()
{
    int choice = get_input <int>("\n\n\n\n\n\n\n"
        "\t\t\t\tHello, Would you like to Log in or Register?" "\n\n\n"
        "\t\t\t\t[1] Login" "\n"
        "\t\t\t\t[2] Register" "\n"
        "\t\t\t\t[3] Exit\n\n\t\t\t\tPlease Enter Your choice \n\n\t\t\t\t");
    B:
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            register_user();
            cout<<"\t\t\t\t\t\t";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout <<"\n\t\t\t\t\tRegistered Successfully!\n"<< endl;
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\nWrong input. Please enter your choice again.\n> ";
            cin>>choice;
            goto B;
    }
}
/////
void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
}
/////
void save_user(const string &username, const string &password)
{
    ofstream myfile;
    myfile.open ("userandpassword.txt",ios::app);
    myfile << username<< " "<< password;
    myfile<<'\n';
    myfile.close();
}
/////
void Welcome_window()
{   cout<<"\n\n";
    cout<<"************************************************************************************************************************************************************************";

    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWelcome  to  CAR   MATE\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tFramed and Coded By \n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tSNo   Enroll No  Name\n\n";
    cout<<"\t\t\t\t\t\t\t\t 1.   18103032   Aishwariya Singh\n\n";
    cout<<"\t\t\t\t\t\t\t\t 2.   18103047   Nandini choudhary\n\n";
    cout<<"\t\t\t\t\t\t\t\t 3.   18103056   Shivang Chaturvedi\n\n";

}
/////
class Pair
{
    public:
        string destination;
        float dist;
        int condition;
        Pair(string dest, float weight,int cond=1)
        {
            destination=dest;
            dist=weight;
            condition=cond;
        }
};
/////
class myComparator
{
    public:
        int operator() (Pair p1, Pair p2)
        {
            return p1.dist > p2.dist;
        }
};
/////
class Graph
{
    int V;
    map<string, list< Pair > > adjList;
    public:
        Graph(int v)
        {
            V=v;
        }
        void addEdge(string src, string dest,float wt,int condition)
        {
            Pair p (dest,wt,condition);
            Pair k (src,wt,condition);
            adjList[src].push_back(p);
            adjList[dest].push_back(k);
        }
        void print()
        {
            /*to print the source and destination the place is connected to*/
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                cout<<"\t\t\t"<<(it)->first<<"-->\t\t";
                for(auto lit=((it)->second).begin();lit!=((it)->second).end();lit++)
                {
                   cout<<(lit)->destination<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void printAllPathsUtil(string u, string d, map<string,bool> &visited, string path[], int &path_index,int cond,float wt,int rate)
        {
            visited[u] = true;
            path[path_index] = u;
            path_index++;
            if (u.compare(d)==0)
            {
                cout<<"\t\t\t";
                int i;
                for (i = 0; i<path_index-1; i++)
                    cout << path[i] << "-->";
                cout << path[i];
                cout << endl;
                cout << endl;
                if(cond<=-1)
                    cout<<"\t\t\t\tThe travel conditions are Bad "<<endl;
                else if(cond==0)
                    cout<<"\t\t\t\tThe travel conditions are Normal "<<endl;
                else
                    cout<<"\t\t\t\tThe travel conditions are Good "<<endl;
                cout << endl;
                cout<< "\t\t\t\tThe distance for the route being "<< wt<<" KM"<<endl;
                cout << endl;
                cout<<"\t\t\t\tThe cost of Travel Inclusive of Taxes : Rs "<<wt*rate<<endl;
                cout << endl;
                cout << endl;
                cout << endl;
            }
            else
            {
                for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
                    if (!visited[i->destination])
                        printAllPathsUtil(i->destination,d, visited, path, path_index,cond+i->condition,wt+i->dist,rate);
            }
            path_index--;
            visited[u] = false;
        }
        void Validate_input(string &src,string &des)
        {
            if(( adjList.find(src) == adjList.end() ))
            {
                cout<<"\n\n\t\t\t\t\tSource Could Not be Found, Renter \t ";
                string src1;
                cin>>src1;
                src=src1;
            }
            if(( adjList.find(des) == adjList.end() ))
            {
                cout<<"\n\n\t\t\t\t\tDestination Could Not be Found, Renter \t ";
                string des1;
                cin>>des1;
                des=des1;
            }

        }
        void printAllPaths(string s, string d,int rate)
        {
            map<string,bool> visited;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                visited[it->first]=false;
            }
            string *path = new string[V];
            int path_index = 0;
            printAllPathsUtil(s, d, visited, path, path_index,0,0,rate);
        }
        void Dijkstras(string src,string des,int rate)
        {
            /*to print the path having the shortest distance*/
            map<string ,float > distance;
            map<string, int> conditions;
            map<string,string> parent;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                distance[it->first]=INT_MAX;
            }
            distance[src]=0;
            conditions[src]=0;
            priority_queue<Pair,vector<Pair>, myComparator> Q;
            Pair P(src,distance[src],conditions[src]);
            Q.push(P);
            string last;
            while(!Q.empty())
            {
                Pair Temp=Q.top();
                Q.pop();
                string u=Temp.destination;last=Temp.destination;
                for(auto it=adjList[u].begin();it!=adjList[u].end();it++)
                {
                    Pair f = *it;
                    string v = f.destination;
                    float w = f.dist;
                    int cond=f.condition;
                    if(distance[u]+w<distance[v])
                    {
                        parent[v]=u;
                        distance[v]=distance[u]+w;
                        conditions[v]=conditions[u]+cond;
                        Pair L(v,distance[v],conditions[v]);
                        Q.push(L);
                    }
                }
            }
            if(distance[des]==INT_MAX)
            {
                cout<<"\n\n\n\n\n\n\n";
                cout<<"\t\t\t\t\tNo Path between the source and the destination Exists, Sorry for the Inconvenience";
                exit(0);
            }
            cout<<"-----------------------------------SHORTEST ROUTE BETWEEN THE SORCE AND DESTINATION-----------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\tThe shortest distance between "<<src<<" and "<<des<< " is : "<<distance[des]<<" KM"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\tThe cost of Travel Inclusive of Taxes : Rs "<<distance[des]*rate<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\tThe path Of the Shortest Route is: "<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t";
            string k=des;
            cout<<k<<"<--";
            while(parent[k].compare(src)!=0)
            {
                cout<<parent[k]<<" <--";
                k=parent[k];
            }
            cout<<src;
            cout<<endl;
            cout<<endl;
            if(conditions[des]<=-1)
                cout<<"\t\t\t\tThe travel conditions are Bad"<<endl;
            else if(conditions[des]==0)
                cout<<"\t\t\t\tThe travel conditions are Normal"<<endl;
            else
                cout<<"\t\t\t\tThe travel conditions are Good"<<endl;
        }
};
/////
int main()
{
    Welcome_window();
    Sleep(6000);

     pp:
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";

            for(int i=0;i<10;i++)
            {
                cout<<"..";
                Sleep(100);
            }
             system("cls");

    Graph g(75);
    main_menu();
    Sleep(2000);
    system("cls");
    string line = " ";
    ifstream readFile("Distance-From-City.txt");
    string source;
    string destination;
    string distance;
    string condition;
    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> source >> destination >> distance >> condition;
        float D= strtof((distance).c_str(),0);
        int C= atoi((condition).c_str());
        g.addEdge(source,destination,D,C);
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<"\t\t\t"<<endl;
    }
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"-----------------------THE LIST OF CITIES THAT THE AGENCY MANAGES ARE---------------------------";
    Sleep(1000);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    g.print();
    cout<<"\n\n\t\t\t\t\tEnter the City from the list above:\t";
    string src;
    cin>>src;
    cin.ignore();
    cout<<"\n\n\t\t\t\t\tEnter Your Destination:    \t";
    string dest;
    cin>>dest;

    if(src.compare(dest)==0)
    {
        cout<<"\n\t\t\t\t\tHey, you do not need a travel agency for staying in the same city!! ;p\n";
        return 0;
    }
    g.Validate_input(src,dest);
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<endl;

    }
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
  /*  cout<<"\t\t\t\t\tSelect The Mode of Transport You Want to Travel By: "<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t[1] Aeroplane \n \t\t\t\t\t[2] Train \n \t\t\t\t\t[3] Bus \n\t\t\t\t\t[4] Taxi"<<endl;
    int choice;
    C:
    cout<<"\t\t\t\t\t";
    cin>>choice;
    if(choice<1||choice>4)
    {
        cout<<"Wrong input. Please enter your choice again.\n";
        goto C;
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<endl;
    }
    system("cls");
    */
    /*switch(choice)
    {
        case 1:
        {
            g.Dijkstras(src, dest, 10);
            cout<<"\n\n-----------------------------------ALL ROUTES FROM SOURCE TO DESTINATION--------------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            g.printAllPaths(src,dest,10);
            break;
        }
        case 2:
        {
            g.Dijkstras(src, dest, 5);
            cout<<"\n\n-----------------------------------ALL ROUTES FROM SOURCE TO DESTINATION--------------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            g.printAllPaths(src,dest,5);
            break;
        }
        case 3:
        {
            g.Dijkstras(src, dest, 7);
            cout<<"\n\n-----------------------------------ALL ROUTES FROM SOURCE TO DESTINATION--------------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            g.printAllPaths(src,dest,7);
            break;
        }
        case 4:
        {*/
            g.Dijkstras(src, dest, 8);
            cout<<"\n\n-----------------------------------ALL ROUTES FROM SOURCE TO DESTINATION--------------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            g.printAllPaths(src,dest,8);
           // break;
        //}
    //}
    cout<<"\n\n\n\t\t\t\tEnter 1 to go to Home Page & 2 to exit\n\n\n";
    int xy;
    cout<<"\t\t\t\tPlease Enter Your Choice \t";
    cin>>xy;
    if(xy==1)
        goto pp;
system("cls");

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t\t";
        for(int k=9-i;k>=0;k--)
            cout<<" ";
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
            Sleep(50);
        }
        cout<<"\t\t"<<endl;
    }
    system("cls");
    Sleep(1000);
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t-------------------  THANKS FOR VISITING  -------------------  \n\n\n\n\n\n\n ";
    return 0;
}
