#include "profile.h"

using namespace std;

string Profile::get_name()const{
    return name;
}

Date Profile::get_bday()const{
    return bday;
}

bool Profile::operator == (const Profile& other)const{
    return name == other.name && bday == other.bday;
}

bool Profile::operator != (const Profile& other)const{
    return name != other.name || bday != other.bday;
}

void Profile::input(istream& ins){
    if(&ins == &cin){
        cout << "Profile Name: ";
        getline(ins >> ws, name);
        cout << "Profile Birthday: ";
        ins >> bday;
    } else{
        getline(ins >> ws, name);
        ins >> bday;
    }
}

void Profile::output(ostream& outs)const{  
    if(&outs == &cout){
        outs << endl;
        outs << "Profile Name: " << name << endl;
        outs << "Profile Birthday: " << bday << endl;
        outs << endl;
    }else{
        outs << name << endl;
        outs << bday << endl;
    }
}

istream& operator >> (istream& ins, Profile& p){
    p.input(ins);
    return ins;
}

ostream& operator << (ostream& outs, const Profile& p){
    p.output(outs);
    return outs;
}