#include <iostream>
#include <sstream>
#include <fstream>
#include <array> 
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

struct Time {
    u_int hour;
    u_int minute;

    Time() : 
        hour{0}, minute{0} {}
    
    Time(u_int hour_in, u_int minute_in) :
        hour{hour_in}, minute{minute_in} {}

};

Time readTime(string stringy) {
    Time final;
    u_int hour;
    final.hour = static_cast<u_int>(hour);
    return final;
}

struct taskLess {
    bool operator() (task task1, task task2) {
        if (task1.priority == task2.priority) {
            return task1.time < task2.time; // tiebreaker can change later
        }
        return task1.priority < task2.priority;
    }
};

class Task { 

    private: 
        string description;
        bool task_type;   
        Time time;
        int priority; 
        Time after; 
        Time by; 
        friend class taskLess;
    
    public: 
    
    //task
    task(string description_in, Time time_in, int priority_in, Time after_in, Time by_in) :  
        description(description_in),
        task_type(false),
        time(time_in),
        priority(priority_in),
        after(after_in),
        by(by_in) {}

    //scheduled event
    task(string description_in, Time start_in, Time end_in) : 
        description(description_in), 
        task_type(true), 
        after(start_in),
        by(end_in) {}
};

//read the csv file of tasks to do 
vector<task> read_tasks(string filename, priority_queue<task, vector<task>, taskLess> pq) { 
    vector<task> tasks;
    ifstream file(filename); 
    
    if (!file.is_open()) { 
        cerr << "Error opening file: " << filename; 
        return tasks; 
    }
    
    stringstream stream; 
    string task_line; 
    // vector<string> lines; 
    while (getline(stream, task_line)) { 
        stringstream ss(task_line); 
        string word; 
        getline(ss, word, ',');
        string duration;
        getline(ss, duration, ',');
        string priority;
        getline(ss, priority, ',');
        string after;
        getline(ss, after, ',');
        string before;
        getline(ss, before);




        while (getline(ss, word, ',')) { 
            if (word == "N") {
                break;
            }
        }
    }
    
    string line;

}

//read the already set schedule
vector<task> read_schedule(string filename) { 
    vector<task> schedule;
    ifstream file(filename); 
    
    if (!file.is_open()) { 
        cerr << "unable to find the schedule :(" << filename; 
        return schedule; 
    }
    
    stringstream stream;
    string word;
    vector<string> words;  
    while (getline(stream, word, ',')) { 
        if (words.size() == 3) { 
            Time start = readTime(words[1]); 
            Time end = readTime(words[2]);
            task new_task(words[0], start, end);
            words.clear(); 
        }
        words.push_back(word);
    }
    return schedule; 
    
}







int main(int argc, char* argv[]) {
    assert(argc > 0);
    string filename = static_cast<string>(argv[1]);
    priority_queue<task, vector<task>, taskLess> pq;
    // TODO: read schedule via read_schedule
    read_tasks(filename, pq);
    return 0;
}
