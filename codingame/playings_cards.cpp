#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stack>
#include <limits>

using namespace std;

struct Node {
    bool playerOneTakes = true;
    vector<int>::size_type leftIdx{0};
    vector<int>::size_type rightIdx{0};
    int scorePlayerOne{0};
    int scorePlayerTwo{0};
};

int max_score(vector<int> cards)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    int scorePlayerOne{0};
    int minimumDiff{std::numeric_limits<int>::max()};
    bool playerOneTakes = true;
    vector<int>::size_type leftIdx{0};
    vector<int>::size_type rightIdx{cards.size()-1};

    cerr << "Cards:";
    for(auto c: cards) {
        cerr << " " << c;
    }
    cerr << endl;

    stack<Node> nodes;
    nodes.push({true, 0, cards.size()-1, 0, 0});
    while(!nodes.empty())
    {
        Node n = nodes.top();
        cerr << "Nodes: " << nodes.size() << ", l:" << n.leftIdx << ", r:" << n.rightIdx << ", p1:" << n.playerOneTakes << ", s1:" << n.scorePlayerOne << ", s2:" << n.scorePlayerTwo << endl;
        nodes.pop();
        if(n.leftIdx == n.rightIdx) {
            // TODO compute second player score and look for the least difference among both player
            // Leaf node: ignore as the score is for the second player
            // if(n.playerOneTakes) {
            //     scorePlayerOne = std::max(scorePlayerOne, n.scorePlayerOne + cards[n.leftIdx]);
            // }
            n.scorePlayerTwo += cards[n.leftIdx];
            int leafDiff = std::abs(n.scorePlayerOne - n.scorePlayerTwo);
            if(minimumDiff >= leafDiff && n.scorePlayerOne > scorePlayerOne) {
                cerr << "Updating score: " << n.scorePlayerOne << ", min:" << leafDiff << endl;
                scorePlayerOne = n.scorePlayerOne;
                minimumDiff = leafDiff;
            }
        } else {
            // I want to go left first, so stack the R first
            // Create right node
            Node r = n;
            if(n.playerOneTakes) {
                r.scorePlayerOne += cards[r.rightIdx--];
            } else {
                r.scorePlayerTwo += cards[r.rightIdx--];
            }
            r.playerOneTakes = !n.playerOneTakes;
            if(r.leftIdx <= r.rightIdx && r.leftIdx < cards.size() && r.rightIdx >= 0) {
                // Ensure we don't push nodes with wrong indices
                nodes.push(r);
            }
            // Create left node
            Node l = n;
            if(n.playerOneTakes) {
                l.scorePlayerOne += cards[l.leftIdx++];
            } else {
                l.scorePlayerTwo += cards[l.leftIdx++];
            }
            l.playerOneTakes = !n.playerOneTakes;
            if(l.leftIdx <= l.rightIdx && l.leftIdx < cards.size() && l.rightIdx >= 0) {
                // Ensure we don't push nodes with wrong indices
                nodes.push(l);
            }
        }
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