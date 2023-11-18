#include <iostream>
#include <fstream>
#include <cassert>

#include "reviews.h"

using namespace std;

int main() {

    // Some made up keywords/weights for testing purposes
    vector<string> keywords = {"snobby", "friendly", "expensive","peter", "song","seung","whan","korea"};
    vector<double> weights = {-1.10, 0.29, -0.21, 0.1, -0.213, 0.43, -0.321, -0.442};




    // A sample unit tests for the wordWeight function
    string testWord_0 = "snobby";
    double correctWeight_0 = -1.10;
    double actualWeight_0 = wordWeight(testWord_0, keywords, weights);

    // An assertion will pass by with no problem if the given expression is true.
    // If the expression is false, however, the assertion reports a test failure!
    assert(actualWeight_0 == correctWeight_0);




    // Here's a more concise way we could write another test for wordWeight
    // Unit test2 for the wordWeight function
    string testWord_1 = "expensive";
    double correctWeight_1 = -0.21;
    double actualWeight_1 = wordWeight(testWord_1, keywords, weights);

    // An assertion will pass by with no problem if the given expression is true.
    // If the expression is false, however, the assertion reports a test failure!
    //cout<<"this is the actual weight for Expensive: ";
    //cout<<actualWeight_1<<endl;
    assert(actualWeight_1 == correctWeight_1);





    // And here's a test for the reviewScore function.
    // (The review is "They were snobby, yet friendly!" but it's split
    //  into separate words as a vector for the test.)
    vector<string> testReview_0 = {"They", "were", "snobby,", "yet", "friendly!"};
    assert(reviewScore(testReview_0, keywords, weights) == -0.81);

    vector<string> testReview_1 = {"peter", "song", "was,", "seung", "18?"};
    assert(reviewScore(testReview_1, keywords, weights) == 0.317);




    // If we get to the bottom of main, that means no assertions failed and
    // that we passed all the tests. Nice!
    cout << "Tests PASS" << endl;
}



