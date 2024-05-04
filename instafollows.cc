#include "instafollows.h"

using namespace std;

/////// CONSTRUCTORS ///////
InstaFollows::InstaFollows(){
    used = 0;
    capacity = 5;
    current_index = 0;
    data = new Profile[capacity];
}

InstaFollows::~InstaFollows(){
    delete []data;
}

InstaFollows::InstaFollows(const InstaFollows& other){ // Copy Constructor
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;

    data = new Profile[capacity];
    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}

void InstaFollows::operator = (const InstaFollows& other){
    if(this == &other){ //Self Assignment Check
        return;
    } 

    delete []data;  //Delete old data

    //Make Copy
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;

    data = new Profile[capacity];
    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}



/////// INTERNAL ITERATOR FUNCTIONS ///////
void InstaFollows::start(){
    current_index = 0;
}

void InstaFollows::advance(){
    current_index++;
}

bool InstaFollows::is_item()const{  //ERROR
    return current_index < used - 1;
}

Profile InstaFollows::current()const{
    return data[current_index];
}

void InstaFollows::remove_current(){
    if(current_index >= used - 1){
        return; //OUT OF BOUNDS
    }
    for(int i = current_index; i < used - 1; i++){
        data[i] = data[i + 1];
    }
    used--;
    if(current_index >= used){
        current_index = used - 1; //Making sure current_index does not go out of bounds
    }
}

void InstaFollows::insert(const Profile& p){    // RETURNING P9 SHOULD BE P1
    if(used == capacity){   // Resize if necessary
        resize();
    }
    if(used == 0 || current_index < 0 || current_index >= used){    // Checks if there are no profiles yet or if the current_index is pointing out of bounds.
        for(int i = used; i > 0; i--){ 
            data[i] = data[i - 1];    // Shift elements
        }
        data[0] = p; // Inserts profile at beginning
        used ++;
        return;
    }else{
        for(int i = used; i > current_index; i--){
            data[i] = data[i - 1];
        }
        data[current_index] = p;
        current_index++;
        used++;
    }
}

void InstaFollows::attach(const Profile& p){
    if(used == capacity){   // Resize if necessary
        resize();
    }
    if(current_index < used){    // Checks if there are no profiles yet or if the current_index is pointing out of bounds.
        if(used + 1 == capacity){
            resize();
        }
        for(int i = used + 1; i > current_index + 1; i--){
            data[i] = data[i - 1];
        }
        data[current_index + 1] = p;
        used++;
    }else{
        data[used - 1] = p; // Inserts profile at end
        used++;
    }
}  


/////// USEFUL FUNCTIONS ///////
void InstaFollows::show_all(ostream& outs)const{
    for(int i = 0; i < used - 1; i++){
        outs << data[i];
    }
}

void InstaFollows::bday_sort(){ // Insertion Sort
    int next;

    for(int i = 0; i < used; i++)
    {
        next = i; //Saves value to be inserted/sorted
        for(int j = i + 1; j < used - 1; j++){ // J is index to the right of I
            if(data[j].get_bday() < data[next].get_bday()){
                next = j; // Next = i + 1
            }
        }
        if(next != i){
            swap(data[next], data[i]);
        }
    }
}

Profile InstaFollows::find_profile(const string& name)const{
    for(int i = 0; i < used; i++){
        if(data[i].get_name() == name){
            return data[i];
        }else{
            Profile p;
            return p;
        }
    }
}

bool InstaFollows::is_profile(const Profile& p)const{
    for(int i = 0; i < used; i++){
        if(data[i] == p){
            return true;
        }
    }
}   


/////// FILE I/O FUNCTIONS ///////
void InstaFollows::load(istream& ins){
    while(!ins.eof()){
        if(used == capacity){
            resize();
        }
        Profile p;
        p.input(ins);
        data[used] = p;
        used++;
    }
}

void InstaFollows::save(ostream& outs)const{
    for(int i = 0; i < used - 1; i++){
        data[i].output(outs);   //Outputs all profiles back
    }
}


/////// PRIVATE ///////
void InstaFollows::resize(){
    Profile *tmp;
    tmp = new Profile[capacity + 5];

    for(int i = 0; i < used; i++){
        tmp[i] = data[i];
    }
    capacity += 5;
    delete []data;
    data = tmp;
}