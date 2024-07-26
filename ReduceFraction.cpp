//Header files
#include <iostream>
using namespace std;

//Function prototype
int greatestCommonFactor(int numerator, int denominator);

//Structure with data members that represent numerator and the denominator
struct Fractions {

        int numerator;
        int denominator;
};

int main() {

        struct Fractions frac; //Create instance of structure called fractions 
        int factor;
        int wholeNumber;
        char answer;

        cout << "FRACTION CALCULATION" << endl;
        cout << "==================" << endl;

        do {

                cout << "Enter the numerator: ";
                cin >> frac.numerator;

                cout << "Enter the denominator: ";
                cin >> frac.denominator;

                cout << endl;

                //Adjustment is made so that denominator instead becomes positive and the numerator switches sign to negative
                if (frac.denominator < 0) {
                        frac.denominator = abs(frac.denominator);
                        frac.numerator = -1 * frac.numerator;
                }

                //Get highest common factor 
                factor = greatestCommonFactor(frac.numerator, frac.denominator);

                //Reduce terms by dividing nuemrator and denominator by factor 
                frac.numerator = frac.numerator / factor;
                frac.denominator = frac.denominator / factor;

                //Reduce fraction to mixed form 
                wholeNumber = frac.numerator / frac.denominator;
                frac.numerator = frac.numerator % frac.denominator;

                //Print out whole number only if it's bigger than zero and denominator is not a 1
                //Otherwise print out a different case 
                if (wholeNumber > 0 && frac.denominator != 1) {
                        cout << "The fraction can be abbreviated to : " << wholeNumber << " " << frac.numerator << "/" << frac.denominator << endl << endl;
                }
                else if (frac.denominator == 1) {
                        cout << "The fraction can be abbreviated to : " << wholeNumber << endl << endl;
                }
                else {
                        cout << "The fraction can be abbreviated to : " << frac.numerator << "/" << frac.denominator << endl << endl;
                }

                cout << "Do you want to calculate again? (Y/N) ";
                cin >> answer;

                cout << endl;

        } while (tolower(answer) == 'y');
}

//  Get greatest common factor
int greatestCommonFactor(int numerator, int denominator) {

        //Find the lowest value between numerator and denominator to use as loop counter 
        int loopCounter = abs(min(numerator, denominator));
        int maxFactor = 0;

        //Loops through to get the biggest common factor of numerator and denominator
        for (int i = 1; i <= loopCounter; i++) {
                if (numerator % i == 0 && denominator % i == 0) {
                        maxFactor = i;
                }
        }
        return maxFactor;
}


