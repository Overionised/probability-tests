#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

long int getInput() {
    long int value;
    while (!(cin >> value)) {
        cout << "Please enter a valid integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}
char getChar(){
   char value;
   while (!(cin >> value)) {
        cout << "Please enter a valid character : ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}
void display(long double sum, long int currentLoop, long int totalLoops) {
    system("clear");
    cout << "Current Sum: " << sum << endl
         << "Current Loop: " << currentLoop + 1 << endl
         << "Remaining Loops: " << totalLoops - (currentLoop + 1) << endl;
}

int main() {
    long double save = 0;
    long int samplesize;
    int maxnum; int iterator=0;
    char choice;

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Input sample size: ";
    samplesize = getInput();

    vector<long double> random(samplesize);

    cout << "Maximum number: ";
    maxnum = getInput();

    cout<<"print out sequence at the end? (y/n) :";

    choice = getChar();

    iterator = samplesize/100; //not to do calculations it every iteration


    for (long int i = 0; i < samplesize; ++i) {
        random[i] = 1 + (rand() % maxnum);
        save += random[i];

        if (i % iterator == 0) { display(save, i, samplesize);}
    }

    if (choice == 'y'){
        for (long int i = 0; i < samplesize; ++i) {cout<<" "<<random[i]<<" ";}
}
    cout << endl<<endl
         << "Largest number within range: " << maxnum << endl
         << "Sample size: " << samplesize << endl
         << "Accumulated mass: " << save << endl
         << "Average: " << save / samplesize << endl;
    return 0;
}
