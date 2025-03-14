#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

struct Restaurant
{
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
};

int readRestaurantDetails( string filename, Restaurant restaurant[], const int MAX_RESTAURANTS ){
    ifstream fileIn(filename);
    string line;
    string element;
    int idx, idy = 0;
    int numElements = 0;

    if(fileIn.fail()){
        return -1;
    }else{
        while(getline(fileIn, line)){
            if(line != ""){
                stringstream lineStream(line);
                idx = 0;
                while(getline(lineStream, element, '~')){
                    numElements++;
                }
                element = "";
                if(numElements == 5){
                    while(getline(lineStream, element, '~')){
                        switch (idx)
                        {
                            case 0:
                                restaurant[idy].name = element;
                                break;
                            case 1:
                                restaurant[idy].food_quality = stoi(element);
                                break;
                            case 2:
                                restaurant[idy].cleanliness = stoi(element);
                                break;
                            case 3:
                                restaurant[idy].wait_time = stoi(element);
                                break;
                            case 4:
                                restaurant[idy].overall = stod(element);
                                break;
                            default:
                                break;
                        }
                        idx++;
                    }
                }
            }
            idy++;
        }
        return idy;
    }
}

int getBest( Restaurant restaurants[], int arr_size, string metric ){
    int bestRest = 0;
    for(int i = 0; i < arr_size; i++){
        if((metric == "Food Quality")){
            if((restaurants[i].food_quality > restaurants[bestRest].food_quality)){bestRest = i;}
        }else if(metric == "Cleanliness"){
            if((restaurants[i].cleanliness > restaurants[bestRest].cleanliness)){bestRest = i;}
        }else if(metric == "Wait Time"){
            if(restaurants[i].wait_time > restaurants[bestRest].wait_time){bestRest = i;}
        }else if(metric == "Overall"){
            if(restaurants[i].overall > restaurants[bestRest].overall){bestRest = i;}
        }else{
            bestRest = -1;
        }
    }
    return bestRest;
}

double getOverallRating(Restaurant restaurant){
    if((restaurant.food_quality>=0 && restaurant.food_quality <=10)&&(restaurant.cleanliness>=0 && restaurant.cleanliness <=10)&&(restaurant.wait_time>=0 && restaurant.wait_time <=5)){
        return (0.5*restaurant.food_quality) + (0.3*restaurant.cleanliness) + (0.2*restaurant.wait_time);
    }
    else{
        return -1;
    }
}

int main()
{
    // PART A
    Restaurant restaurants[30];

    cout << " ." << readRestaurantDetails("testFile.txt", restaurants, 30) << endl;
    cout << "." << getBest(restaurants, readRestaurantDetails("testFile.txt", restaurants, 30), "Food Qualxty");

    // Checking if the file was opened correctly
    
}