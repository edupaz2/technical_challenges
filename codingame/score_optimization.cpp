#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stack>
#include <limits>
/*
Objective
In this problem, you'll be creating an algorithm that finds the maximum score a user can get in a particular game. The game is as follows:

There are two players and a sequence of cards on the table (there will always be an even number of cards).
The game is turn-based, and the players alternate turns.
Each turn, a player will select a card to the left or right.
Each card has a positive integer value, and the value of the card that the player chooses will be added to the player's overall score.
The players both start off with a score of 0.
 

Assuming that both players know the entire card sequence and play optimally, your job is to figure out the final score for the player who goes first.

 

Implementation
Implement the function max_score(cards) which takes as input a vector of integers (cards), representing the scores of the cards in the sequence. The first integer represents the left of the sequence while the last integer represents the right of the sequence. For example:

[1, 9, 10, 5, 6, 4]
 

Your max_score function should return a positive integer representing the final score of the player who goes first in the game.

For the above example, the correct output would be 18, and the turns would go like this:

Player 1 takes 4
Player 2 takes 6
Player 1 takes 5
Player 2 takes 10
Player 1 takes 9
Player 2 takes 1
*/

using namespace std;

bool chooseLeftOrRight(const vector<int>& cards, int leftIdx, int rightIdx)
{
    int leftSum{0}, rightSum{0};
    int size = (rightIdx-leftIdx+1)/2;
    for(int i = 0; i < size; i += 2) {
        cerr << "L:" << leftIdx+i << "[" << cards[leftIdx+i] << "], R:" << rightIdx-i << "[" << cards[rightIdx-i] << "]" <<  endl;
        leftSum += cards[leftIdx+i];
        rightSum += cards[rightIdx-i];
    }
    if(leftSum >= rightSum) {
        cerr << "LS*:" << leftSum << ", RS:" << rightSum << endl;
        return true;
    } else {
        cerr << "LS:" << leftSum << ", RS:*" << rightSum << endl;
        return false;
    }

    // if(cards[leftIdx] >= cards[rightIdx]) {
    //     return true;
    // } else {
    //     return false;
    // }
    
    // int leftSum{0}, rightSum{0};
    // int size = rightIdx-leftIdx+1;
    // for(int i = 0; i < size; i += 2) {
    //     cerr << "L:" << leftIdx+i << "[" << cards[leftIdx+i] << "], R:" << rightIdx-i << "[" << cards[rightIdx-i] << "]" <<  endl;
    //     leftSum += cards[leftIdx+i];
    //     rightSum += cards[rightIdx-i];
    // }
    // if(leftSum >= rightSum) {
    //     cerr << "LS*:" << leftSum << ", RS:" << rightSum << endl;
    //     return true;
    // } else {
    //     cerr << "LS:" << leftSum << ", RS:*" << rightSum << endl;
    //     return false;
    // }
}

int max_score(vector<int> cards)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    int scorePlayerOne{0};
    int scorePlayerTwo{0};
    bool playerOneTakes = true;
    int leftIdx{0};
    int rightIdx{cards.size()-1};

    cerr << "Cards:";
    for(auto c: cards) {
        cerr << " " << c;
    }
    cerr << endl;

    bool lastWasLeft;
    while(leftIdx <= rightIdx) {
        int score{0};
        cerr << ((playerOneTakes) ? "--P1--" : "--P2--") << endl;
        if(playerOneTakes) {
            lastWasLeft = chooseLeftOrRight(cards, leftIdx, rightIdx);
            if(lastWasLeft) {
                score = cards[leftIdx++];
            } else {
                score = cards[rightIdx--];
            }
            scorePlayerOne += score;
        } else {
            chooseLeftOrRight(cards, leftIdx, rightIdx);
            if(lastWasLeft) {
                score = cards[leftIdx++];
            } else {
                score = cards[rightIdx--];
            }
            scorePlayerTwo += score;
        }
        cerr << "Score: " << score << ". Total score1:" << scorePlayerOne << ", score2:" << scorePlayerTwo << endl;
        playerOneTakes = !playerOneTakes;
    }
    
    return scorePlayerOne;
}

/* Ignore and do not change the code below */
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> cards;
    for (int i = 0; i < n; i++) {
        int cards_tmp;
        cin >> cards_tmp;
        cards.push_back(cards_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    int max = max_score(cards);
    dup2(std_out_fd, 1);
    cout << max << endl;
}
/* Ignore and do not change the code above */