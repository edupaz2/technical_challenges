#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stack>
#include <limits>

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