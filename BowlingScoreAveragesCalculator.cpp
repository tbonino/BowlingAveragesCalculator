// Bowling Scores Averages calculator By Tom Bonino
// playing around with structs

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// global variables
const int AVG_DIVISOR = 5;
const string FILE_NAME = "BowlingScores.txt";

// struct for bowlers
struct Bowler
{
    string name;
    int scores[5];
    int average_score;
};

// declare function prototypes
void header();
void spacer();
void PrettyPrintResults(const Bowler bowlers[]);
void GetAverageScore(Bowler bowlers[]);
bool GetBowlingData(const string file, Bowler bowlers[]);

int main()
{
    // intialize program header
    header();
    cout << left << setw(3) << setfill('>') << "" << " Bowling Averages Calculator by Tom Bonino " << setw(3) << setfill('<') << "" << endl;
    header();
    spacer();

    // struct array object
    Bowler Bowlers[10];

    bool flag = false;

    cout << "Reading file..." << endl;
    spacer();
    // call GetDatam function to read in bowling data
    flag = GetBowlingData(FILE_NAME, Bowlers);

    // fail program if file fails to open
    if (flag == false)
    {
        return 1;
    }

    cout << "Calculating averages..." << endl;
    spacer();
    // Calculate and print averages for each bowler
    GetAverageScore(Bowlers);

    cout << "Printing results..." << endl;
    // Print names array
    PrettyPrintResults(Bowlers);
    spacer();

    // pause program to allow viewing of results, then close successfully
    system("pause");
    return 0;
}

// function to print program header bars
void header()
{
    cout << left << setw(49) << setfill('*') << "" << endl;
}

// function to space output
void spacer()
{
    cout << endl;
}

// function to print names array
void PrettyPrintResults(const Bowler Bowlers[])
{
    // print names and scores arrays
    for (int i = 0; i < 10; i++)
    {
        cout << "Name: ";
        cout << Bowlers[i].name << " | Scores: ";
        for (int j = 0; j < 5; j++)
        {
            cout << Bowlers[i].scores[j] << " ";
        }
        cout << "| Average: " << Bowlers[i].average_score << " ";
        spacer();
    }
}

void GetAverageScore(Bowler Bowlers[])
{

    // loop to load averages array
    for (int i = 0; i < 10; i++)
        Bowlers[i].average_score = ceil((Bowlers[i].scores[0] + Bowlers[i].scores[1] + Bowlers[i].scores[2] + Bowlers[i].scores[3] + Bowlers[i].scores[4]) / AVG_DIVISOR); // rounded average.

}

bool GetBowlingData(const string file, Bowler Bowlers[])
{
    // declare file variable
    ifstream inFile;

    inFile.open(file);

    // fail program if file fails to open
    if (!inFile)
    {
        cout << "File failed to open." << endl;
        return false;
    }

    // temporary variables to hold file read data
    string temp_name;
    int temp_score_1 = 0;
    int temp_score_2 = 0;
    int temp_score_3 = 0;
    int temp_score_4 = 0;
    int temp_score_5 = 0;

    // read in data, then load into arrays
    for (int i = 0; i < 10; i++)
    {
        inFile >> temp_name >> temp_score_1 >> temp_score_2 >> temp_score_3 >> temp_score_4 >> temp_score_5;
        Bowlers[i].name = temp_name;
        Bowlers[i].scores[0] = temp_score_1;
        Bowlers[i].scores[1] = temp_score_2;
        Bowlers[i].scores[2] = temp_score_3;
        Bowlers[i].scores[3] = temp_score_4;
        Bowlers[i].scores[4] = temp_score_5;
    }

    // close file reading once complete
    inFile.close();

    // close function successfully
    return true;
}
