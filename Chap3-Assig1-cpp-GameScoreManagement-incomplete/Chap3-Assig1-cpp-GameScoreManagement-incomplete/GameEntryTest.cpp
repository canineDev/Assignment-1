#include <iostream>
#include "Scores.h"  // Assuming this is the header file name

using namespace std;
void insertionSort(vector<GameEntry>& entries, bool ascending);
int main() {
    // Creating GameEntry objs
    cout << "--- Populating scores ---" << endl;
    GameEntry mike("Mike", 1105);
    GameEntry rob("Rob", 750);
    GameEntry paul("Paul", 720);
    GameEntry anna("Anna", 660);
    GameEntry rose("Rose", 590);
    GameEntry jack("Jack", 510);
    GameEntry jill("Jill", 740);

    // Creating Scores objs BAM and populating them with
    // GameEntry objs
    Scores BAM;
    BAM.add(mike);
    BAM.add(rob);
    BAM.add(paul);
    BAM.add(anna);
    BAM.add(rose);
    BAM.add(jack);
    BAM.add(jill);

    // Testing on a populated list
    cout << "--- 1. Testing on a populated list ---" << endl;

    // Search for existing player
    cout << "Searching for Rob's score..." << endl;
    int robScore = BAM.searchScore("Rob");
    if (robScore != -1) // Print score if not negative
        cout << "Rob's score is: " << robScore << endl;
    else
        cout << "Rob not found." << endl;

    // Search for non-existing player
    cout << "Searching for Zelda's score..." << endl;
    int zeldaScore = BAM.searchScore("Zelda");
    if (zeldaScore != -1)
        cout << "Zelda's score is: " << zeldaScore << endl;
    else
        cout << "Zelda not found." << endl;

    // Calculating the average score
    cout << "Calculating the average score..." << endl;
    cout << "Average score: " << BAM.averageMaxScores() << endl;

    // Calculating the min/max
    cout << "Finding minimum and maximum scores..." << endl;
    pair<int, int> minMax = BAM.findMinMaxScores();
    cout << "Minimum score: " << minMax.first << endl;
    cout << "Maximum score: " << minMax.second << endl;
    cout << endl;
    
    // Testing on an empty list
    cout << "--- 2. Testing on an empty list ---" << endl;
    Scores emptyScores;
    cout << "Searching for player in empty list..." << endl;
    int marioScore = emptyScores.searchScore("Mario");
    
    if (marioScore != -1)
        cout << "Mario's score is: " << marioScore << endl;
    else
        cout << "Mario not found." << endl;

    cout << "Average of empty list: " << emptyScores.averageMaxScores() << endl;
    pair<int, int> emptyMinMax = emptyScores.findMinMaxScores();
    cout << "Min score in empty list: " << emptyMinMax.first << endl;
    cout << "Max score in empty list: " << emptyMinMax.second << endl;

    return 0;
}

void insertionSort(vector<GameEntry>& entries, bool ascending = true) {
    int numEntries = entries.size();
    for (int i = 1; i < numEntries; i++) {
        GameEntry key = entries[i];
        int j = i - 1;
        if (ascending) {
            // Sort in ascending order
            while (j >= 0 && entries[j].getScore() > key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        } else {
            // Sort in descending order
            while (j >= 0 && entries[j].getScore() < key.getScore()) {
                entries[j + 1] = entries[j];
                j--;
            }
        }
        entries[j + 1] = key;
    }
}
