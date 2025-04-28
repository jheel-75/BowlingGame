/******************************************************************************
	Program calculating the score of player in bowling                      
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int calculateScore(const vector<int>& rolls) 
{
    int totalScore = 0;
    int i = 0; //rollIndex

    for (int frame = 1; frame <= 10; ++frame) 
    {
        //10th frame case 
        if(frame == 10)
        {
            totalScore += rolls[i] + rolls[i + 1];
            if(rolls[i] == 10 || rolls[i] + rolls[i + 1] == 10) //strike or spare
            {
                totalScore += rolls[i+2];
            }
            cout<<"Score in frame "<<frame<<": "<<totalScore<<endl;//log print
            break;
        }
        
        if (rolls[i] == 10) //Strike
        { 
            totalScore += 10 + rolls[i + 1] + rolls[i + 2];
            i += 1;
        } 
        else if (rolls[i] + rolls[i + 1] == 10) //Spare
        { 
            totalScore += 10 + rolls[i + 2];
            i += 2;
        } 
        else 
        { //Regular Frame
            totalScore += rolls[i] + rolls[i + 1];
            i += 2;
        }
        cout<<"Score in frame "<<frame<<": "<<totalScore<<endl;//log print
    }
    return totalScore;
}

int main() {
    vector<int> player;
    int pins;

    cout << "Enter the scores for each roll (Full game of 10 frames, maximum rolls = 21 rolls):" << endl;
    int rollCnt = 0;
    for (int i = 0; i < 21; ++i) {
        cout << "Roll " << rollCnt + 1 << ": ";
        rollCnt++;
        cin >> pins;
        if(pins == 10)
        {
            i++;
        }
        player.push_back(pins);

        // Stop input if 10th frame does not require extra ball
        if (player.size() >= 18)
        {
            if (player[16] != 10 && player[16] + player[17] < 10)
                break;
        }
    }

    int totalScore = calculateScore(player);
    cout << "Final Score of player: " << totalScore << endl;

    return 0;
}