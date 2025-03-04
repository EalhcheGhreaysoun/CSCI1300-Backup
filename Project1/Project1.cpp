#include <iostream>
using namespace std;

bool isValidBase(char base){
    if (base == 'A' || base == 'C' || base == 'G' || base == 'T'){
        return true;
    } else{
        return false;
    }
}

bool isValidStrand(string strand){
    bool flag = true;
    if (strand.empty()){
        return false;
    }else{
        for (unsigned int i = 0; i < strand.length(); i++){                        //looping over the entire strand
            if (!isValidBase(strand[i])){                                          //checking if it is not A, C, G or T
                flag = false;
            }
        }
    }
    return flag;
    flag = true;
}

double strandSimilarity(string strand1, string strand2){
    int count = 0;
    double compared = 0;
    if (strand1.length() == strand2.length()){                                     //checking if the strands are the same length
        for (unsigned int i = 0; i < strand1.length(); i++){                       //looping over the strands
            if (strand1[i] == strand2[i]){                                         //if the elements of the strands are equal, add to the count
                count++;
            }
        }
        compared = (double)count / (double)strand2.length();                       //the total number of matching elements / # of elements
    }else{
        return 0;                                                                  //if the strands are not of equal length, return 0
    }
    return compared;
}

int bestStrandMatch(string input_strand, string target_strand){
    int bestMatch = 100;
    double prevSimScore = -1;                                                      //set prevSimScore to -1 for invalid score
    if (input_strand.length() < target_strand.length()){
        cout << "Best similarity score: 0.0" << endl;
        return -1;
    }
    else{
        for (unsigned i = 0; i < input_strand.length();i++){                       //loop over the longer strand: input_strand
            //if a section of the input strand has a better match with the target than any previous section...
            if (strandSimilarity(input_strand.substr(i,target_strand.length()), target_strand) > prevSimScore){ 
                bestMatch = i;                                                     //update the location of the best match
                //update the current best score
                prevSimScore = strandSimilarity(input_strand.substr(i,target_strand.length()), target_strand);
            }
        }
        cout << "Best similarity score: " << prevSimScore << endl;
        return bestMatch;
    }
}

void identifyMutations(string input_strand, string target_strand){
    unsigned int matchPos;
    bool flag = true;
    if(input_strand.length() < target_strand.length()){
        matchPos = bestStrandMatch(target_strand, input_strand);                   //uses previous function to find best matching location
        cout << "Best alignment index: " << matchPos << endl;
        for (unsigned i = 0; i < target_strand.length(); i++){                     //looping over the target strand
            if (i < matchPos || i > matchPos + input_strand.length()-1){           //if i is not in the matching section of input strand

                cout << "Insertion at position " << i+1 << ": " << target_strand[i] << " is inserted in target strand" << endl;
                flag = false;
            }else if(input_strand[i-matchPos] != target_strand[i]){                //checks for substitutions
                cout << "Substitution at position " << i+1 << ": " << input_strand[i-matchPos] << " -> " << target_strand[i] << endl;
                flag = false;
            }
        }
    }
    else{                                                                          //if the input strand is longer than the target strand
        matchPos = bestStrandMatch(input_strand, target_strand);
        cout << "Best alignment index: " << matchPos << endl;

        for(unsigned i = 0; i < input_strand.length(); i++){
            
            if (i < matchPos || i > matchPos + target_strand.length()-1){
                cout << "Deletion at position " << i+1 << ": " << input_strand[i] << " is deleted in target strand" << endl;
                flag = false;
            }else if(input_strand[i] != target_strand[i-matchPos]){
                cout << "Substitution at position " << i+1 << ": " << input_strand[i] << " -> " << target_strand[i-matchPos] << endl;
                flag = false;
            }
        }
    }
    if (flag){
        cout << "No mutations found." << endl;
    }
}

void transcribeDNAtoRNA(string strand){
    for(unsigned int i = 0; i < strand.length(); i++){
        if(strand[i] == 'T'){
            strand[i] = 'U';
        }
    }
    cout << strand << endl;
}

void reverseComplement(string strand){
    string finalStrand;
    for(unsigned int i = strand.length(); i > 0; i--){
        switch (strand[i-1]){
            case 'A':
                finalStrand += 'T';
                break;
            case 'T':
                finalStrand += 'A';
                break;
            case 'C':
                finalStrand += 'G';
                break;
            case 'G':
                finalStrand += 'C';
                break;
        }
    }
    cout << finalStrand << endl;
}

void getCodingFrames(string strand){
    string finalStrand;
    
    unsigned int previousStrandLoc = 0;
    for(unsigned int i = 0; i + previousStrandLoc < strand.length(); i++){
        if (strand.substr(i+previousStrandLoc, 3) == "ATG"){ 
            for(unsigned int j = 0; 3*j+i+previousStrandLoc < strand.length(); j++){
                if(strand.substr(i+previousStrandLoc+3*j, 3) == "TAA" || strand.substr(i+previousStrandLoc+3*j, 3) == "TAG" || strand.substr(i+previousStrandLoc+3*j, 3) == "TGA"){
                    finalStrand += strand.substr(i+previousStrandLoc, 3*j+3) + '\n';
                    previousStrandLoc = previousStrandLoc+(3*j);
                    break;
                }
            }
        }
    }
    previousStrandLoc = 0;
    if(finalStrand.empty() == true){
        cout << "No reading frames found." << endl;
    }else{      cout << finalStrand << endl;    }
}

int main(){
    int input;
    bool flag = true;
    bool otherFlag = true;
    string in1;
    string in2;
    while(flag){
        cout << "--- DNA Analysis Menu ---" << endl;
        cout << "1. Calculate the similarity between two sequences of the same length" << endl;
        cout << "2. Calculate the best similarity between two sequences of either equal or unequal length" << endl;
        cout << "3. Identify mutations" << endl;
        cout << "4. Transcribe DNA to RNA" << endl;
        cout << "5. Find the reverse complement of a DNA sequence" << endl;
        cout << "6. Extract coding frames" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter your choice (1 - 7):" << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            while(otherFlag){
                cout << "Enter the first DNA sequence:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;
            while(otherFlag){
                cout << "Enter the second DNA sequence:" << endl;
                cin >> in2;
                if(isValidStrand(in2)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;
        
            if(in1.length() == in2.length()){
                cout << "Similarity score: " << strandSimilarity(in1, in2) << endl;
                otherFlag = false;
            }else{
                cout << "Error: Input strands must be of the same length." << endl;
            }
            in1 = "";
            in2 = "";
            break;
        case 2:
            while(otherFlag){
                cout << "Enter the first DNA sequence:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;
            while(otherFlag){
                cout << "Enter the second DNA sequence:" << endl;
                cin >> in2;
                if(isValidStrand(in2)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;
    
            if (in1.length() >= in2.length()){
                strandSimilarity(in1.substr(bestStrandMatch(in1, in2), in2.length()), in2);
            }else{
                cout << "Best similarity score: 0.0" << endl;
            }
            
            in1 = "";
            in2 = "";
            break;
        case 3:
            while(otherFlag){
                cout << "Enter the first DNA sequence:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;
            while(otherFlag){
                cout << "Enter the second DNA sequence:" << endl;
                cin >> in2;
                if(isValidStrand(in2)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;

            identifyMutations(in1, in2);
            in1 = "";
            in2 = "";
            break;
        case 4:
            while(otherFlag){
                cout << "Enter the DNA sequence to be transcribed:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;

            cout << "The transcribed DNA is: ";
            transcribeDNAtoRNA(in1);
            in1 = "";
            break;
        case 5:
            while(otherFlag){
                cout << "Enter the DNA sequence:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = true;

            cout << "The reverse complement is: ";
            reverseComplement(in1);

            in1 = "";
            break;
        case 6:

            while(otherFlag){
                cout << "Enter the DNA sequence:" << endl;
                cin >> in1;
                if(isValidStrand(in1)){
                    otherFlag = false;
                }else{
                    cout << "Invalid input. Please enter a valid sequence." << endl;
                }
            }
            otherFlag = false;

            cout << "The extracted reading frames are:" << endl;
            getCodingFrames(in1);
            otherFlag = false;

            in1 = "";    
        
            otherFlag = true;
            break;
        case 7:
            flag = false;
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid input. Please select a valid option." << endl;
            break;
        }
    }
}
