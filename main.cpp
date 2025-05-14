// auther: Fahd Deya El-din Salah
// Date: 25 Nov. 2024
// this is problem 5 which is task manager problem which takes the data by using 
// tasklist command like in cmd and creat a new text file named data (data.txt)
// and store the whole running program in your computer with some information about the program 
// such as (pid - session name - session # - memory usage) and then it stores this data in vector of process class
// and display it sorted as user desire and keeps loop till the user exits.





#include<bits/stdc++.h>

using namespace std;

class Process{
    string image_name, session_name,  mem_usage;
    string PID, session_number;

public:
    Process(string Iname, string Sname, string pid, string Snum, string MU){
            image_name = Iname;
            session_name = Sname;
            PID = pid;
            session_number = Snum;
            mem_usage = MU;
        }

    void display(){
        cout << left << setw(25) << image_name
             << right << setw(10) << PID
             << right << setw(15) << session_name
             << right << setw(10) << session_number
             << right << setw(12) << mem_usage << "\n";
    }

    string getName(){
        return image_name;
    }
    int getPIDInt(){
        try{
            return stoi(PID);
        }catch (const invalid_argument&){
            return -1;
        }catch(const out_of_range&){
            return -1;
        }
    }
    int getMemoryUsageInt(){
        string memWithoutK = mem_usage;
        memWithoutK.erase(remove(memWithoutK.begin(), memWithoutK.end(), ','), memWithoutK.end());
        if(memWithoutK.back() == 'K') {
            memWithoutK.pop_back();
        }
        try{
            return stoi(memWithoutK);
        }catch (const invalid_argument&){
            return -1;
        }catch (const out_of_range&){
            return -1;
        }
    }
};

class Processeslist{
    vector<Process> processes;

public:
    void loadProcesses(){
        system("tasklist > data.txt");
        ifstream file("data.txt");
        string line;
        getline(file, line);
        getline(file, line);
        getline(file, line);
        while (getline(file, line)){
            stringstream ss(line);
            vector<string> tokens;
            string token;
            string imageName;

            while(ss >> token && !isdigit(token[0])){
                if(!imageName.empty()){
                    imageName += " ";
                }
                imageName += token;
            }

            if(!token.empty()){
                tokens.push_back(token);
            }
            while (ss >> token){
                tokens.push_back(token);
            }

            if(tokens.size() >= 4){
                string pid = tokens[0];
                string sessionName = tokens[1];
                string sessionNumber = tokens[2];
                string memUsage = tokens[3];
                processes.emplace_back(imageName, sessionName, pid, sessionNumber, memUsage);
            }
        }
        file.close();
    }

    void displayProcesses(){
        cout << left << setw(25) << "Image Name"
             << right << setw(10) << "PID"
             << right << setw(15) << "Session Name"
             << right << setw(10) << "Session#"
             << right << setw(12) << "Mem Usage\n" ;
        cout << string(77, '-') << "\n"; 

        for(auto& process : processes){
            process.display();
        }
    }
    void sortByName(){
        sort(processes.begin(), processes.end(), []( Process a,  Process b){
            return a.getName() < b.getName();
            }
        );
    }

    void sortByPID(){
        sort(processes.begin(), processes.end(), [](Process a, Process b) {
            return a.getPIDInt() < b.getPIDInt();
            }
        );
    }

    void sortByMemoryUsage(){
        sort(processes.begin(), processes.end(), [](Process a, Process b) {
            return a.getMemoryUsageInt() > b.getMemoryUsageInt();
            }
        );
    }
};

int main(){
    cout << "Welcome to the task manager.\n";
    Processeslist plist;
    plist.loadProcesses();
    string choice;
    do {
        cout << "Please choose how you want your data to be displayed.\n";
        cout << "A) Sorted by Name.\n";
        cout << "B) Sorted by PID.\n";
        cout << "C) Sorted by Memory Usage.\n";
        cout << "D) Exit\n";
        cin >> choice;
        choice[0] = toupper(choice[0]);
        while (choice != "A" && choice != "B" && choice != "C" && choice != "D") {
            cout << "Error wrong choice, please try again: \n";
            cin >> choice;
            choice[0] = toupper(choice[0]);
        }

        if (choice == "A"){
            cout << "Processes sorted by Name:" << endl;
            plist.sortByName();
            plist.displayProcesses();
        }
        else if (choice == "B"){
            cout << "\nProcesses sorted by PID:" << endl;
            plist.sortByPID();
            plist.displayProcesses();
        }
        else if (choice == "C"){
            cout << "\nProcesses sorted by Memory Usage:" << endl;
            plist.sortByMemoryUsage();
            plist.displayProcesses();
        }

    }while(choice != "D");
    cout << "See you soon :)\n";
}
