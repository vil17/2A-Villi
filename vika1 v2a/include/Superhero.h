#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>
#include <iostream>
using namespace std;


class Superhero
{
    public:
        Superhero();
        Superhero(string name, int age, char superpower, char _current_function);
        void print_UI();
        string return_superpower(char power); // skilar "flying" eda sambarilegu


        void make_choice(); //skilar char fyrir hvad a ad gera.
        bool pVerbose;

        string set_name();
        int set_age();
        char set_superpower();



        friend istream& operator >> (istream& ins, Superhero &superhero); // instream til ad bua til
        friend ostream& operator << (ostream& outs, Superhero superhero); //oustream til ad prenta


    private:
        string _name;
        int _age;
        char _superpower;
};

#endif // SUPERHERO_H
