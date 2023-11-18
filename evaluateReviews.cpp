// <Seung Whan Song> 
// <none> 
// <015> 
// <11/14/2023>

//------------------------------------------------------
// AUTOGRADER INFO -- IGNORE BUT DO NOT REMOVE 
// test_cases: true
// feedback('all')
// c269759b-5ea7-4702-bff4-ebc05443d45d
//------------------------------------------------------



// Add any #includes for C++ libraries here.
// We have already included iostream as an example.
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// This #include adds all the function declarations (a.k.a. prototypes) from the
// reviews.h file, which means the compiler knows about them when it is compiling
// the main function below (e.g. it can verify the parameter types and return types
// of the function declarations match the way those functions are used in main() ).
// However, the #include does not add the actual code for the functions, which is
// in reviews.cpp. This means you need to compile with a g++ command including both
// .cpp source files. For this project, we will being using some features from C++11,
// which requires an additional flag. Compile with this command:
//     g++ --std=c++11 evaluateReviews.cpp reviews.cpp -o evaluateReviews
#include "reviews.h"

using namespace std;

const double SCORE_LIMIT_TRUTHFUL = 3;
const double SCORE_LIMIT_DECEPTIVE = -3;


int main(){
    // TODO: implement the main program
    //Declare the variables we will use to keep track
    int bigIndex = 0;
    int littleIndex = 0;
    int numFiles = 0;
    int numTruth = 0;
    int numFalse = 0;
    int numUncat = 0;
    double finalHighscore = 0;
    double finalLowscore = 0;

    //Check if the file is open
    ifstream iKey("keywordWeights.txt");
    if (!iKey.is_open()) {
        cout << "Error: keywordWeights.txt could not be opened." << endl;
        return 1;
    }

    //Read in Key words and their weights
    vector<string> keywords;
    vector<double> weights;
    readKeywordWeights(iKey, keywords, weights);

    //Create a report
    ofstream report;
    report.open("report.txt");
    report<<"review score category"<<endl;
    for(int i = 0; i < 100; i++){ 
        string temp = makeReviewFilename(i);
        ifstream ireview(temp);
        if (!ireview.is_open()){
            break;
        } 
        
        else{
            vector<string> reviewWords;
            readReview(ireview, reviewWords);
            double finalScore = reviewScore(reviewWords, keywords, weights);
            if(i == 0){
                finalHighscore = finalScore; 
                finalLowscore = finalScore;
            }
            else{
                if(finalHighscore<finalScore){
                    finalHighscore = finalScore;
                    bigIndex = i;
                }
                if(finalLowscore>finalScore){
                    finalLowscore = finalScore;
                    littleIndex = i;
                }
            }

            if(finalScore>3.0){
                report<<i<<" "<<finalScore<<" "<<"truthful"<<endl;
                numTruth ++;
            }

            else if (finalScore<-3.0)
            {
               report<<i<<" "<<finalScore<<" "<<"deceptive"<<endl;
               numFalse ++;
            }

            else{
                report<<i<<" "<<finalScore<<" "<<"uncategorized"<<endl;
                numUncat ++;
            }
        }

        numFiles ++;
    }
    
    report<<" "<<endl;

    report<<"Number of Reviews: "<< numFiles << endl;
    report<<"Number of truthful reviews: " << numTruth << endl;
    report<<"Number of deceptive reviews: " << numFalse << endl;
    report<<"Number of uncategorized reviews: " << numUncat << endl;

    report<<" "<<endl;

    report<<"Review with highest score: "<< bigIndex << endl;
    report<<"Review with lowest score: "<< littleIndex << endl;
    
    report.close();
}



