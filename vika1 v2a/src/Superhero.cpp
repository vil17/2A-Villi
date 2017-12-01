#include "Superhero.h"

Superhero::Superhero(){
    _name = "";
    _age = 0;
    _superpower = 'n';
};

Superhero::Superhero(string name, int age, char superpower, char current_function){
    _name = name;
    _age = age;
    _superpower = superpower;
};

string set_name();
int set_age();
char set_superpower();


string Superhero::return_superpower(char superpower){
    if(superpower == 'f'){
        return "Flying";
    }
    else if(superpower == 'h'){
        return "Hacker";
    }
    else if(superpower == 'g'){
        return "Giant";
    }
    else if(superpower == 'n'){
        return "None";
    }
    else{
        return "Weakling";
    }
};

void Superhero::print_UI(){
    cout << "Select 1 to write a new hero to file." << endl;
    cout << "Select 2 to list heroes from file." << endl;
        cout << "Choice: ";
};

void Superhero::make_choice(){
    int choice;
    cin >> choice;
    if(choice == 1){
        pVerbose = true;
    }
    else{
        pVerbose = false;
    }
};

istream& operator >> (istream& ins, Superhero &superhero){

    if(superhero.pVerbose){
        cout << "Please enter superhero name" << endl << ": ";
        ins >> superhero._name;
        cout << "Enter age: " << endl << ": ";
        ins >> superhero._age;
        cout << "Enter heroes superpower" << endl << ": ";
        ins >> superhero._superpower;
    }
    else{
        string remove_delim;
        ins >> remove_delim; // removes delimiter from file
        ins >> superhero._name;
        ins >> superhero._age;
        ins >> superhero._superpower;
    };
    return ins;
}

ostream& operator << (ostream& outs, Superhero superhero){
    if(!superhero.pVerbose){ //prenta hetju a skja
        outs << superhero._name;
        outs << " (";
        outs <<  superhero._age;
        outs << "): ";
        outs << superhero.return_superpower(superhero._superpower) << endl;
    }
    else{ // to write to file
        string delim = "------------";
        outs << endl << delim << endl; // writes a delimiter below last hero on list and adds the new hero belor
        outs << superhero._name << endl;
        outs << superhero._age << endl;
        outs << superhero._superpower;;

    }
    return outs;
};

