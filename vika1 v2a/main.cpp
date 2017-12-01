#include <iostream>
#include "Superhero.h"
#include <fstream>

using namespace std;

int main()
{

    Superhero superhero;
    superhero.print_UI();
    superhero.make_choice();       // byr til bool, true fyrir insert hero og prenta leidbeiningar
    if(superhero.pVerbose) {
        ofstream fout;             // by til stream thar sem tharf til spara minni, vil ekki bua til fullt af breytum ef eg tharf bara ad taka ur skjali
        cin >> superhero;
        fout.open("Superherolist.txt", ios::app);
        if(fout.is_open()) {
            fout << superhero;
            superhero.pVerbose = false;
            cout << superhero;
        } else {
            cout << "error opening herolist to write";
        }
        fout.close();
    } else {                       //if bool called for print this happens
        ifstream fin;
        string scroll_lines;

        fin.open("Superherolist.txt");
        if(fin.is_open()) {
            while(getline(fin, scroll_lines)) {
                fin >> superhero;
                cout << superhero;
            }
        } else {
            cout << "error opening herolist to write";
        }
        fin.close();
    }

    return 0;
}
