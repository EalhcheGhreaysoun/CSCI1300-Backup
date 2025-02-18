/*
4.a: psudocode
define function applyDeductions
pass in income
pass in number of dependants
if number of dependants is greater than zero
return income - 14600 - 500
else
return income -14600
end

define function calculateTax
pass in income
if income <= 10000:
return income * 0.9
else if income <= 50000: 
return income * 0.85
else: 
return income * 0.8
end

define function computeNetIncome
pass in gross income, number of dependants
declare double variable money
set money to calculateTac(applyDeductions(income, number of dependants))
if number of dependants is greater than zero: 
return money + 14600 + 500
else: 
return money + 14600
end


assert(computeNetIncome(100000, 2) == 83020)
    assert(computeNetIncome(10000, 0) == 10000)

*/
#include <iostream>
#include <cassert>

using namespace std;

double applyDeductions(double income, int numDependents) {
    if(income < 14600){
        return 0;
    }else{
        if(numDependents >=0){
            return income - 14600 -500;
        }else{
            return income -14600;
        }
    }
}

double calculateTax(double taxableIncome) {
    if(taxableIncome <= 10000){
        return taxableIncome * 0.9;
    } else if (taxableIncome <= 50000){
        return taxableIncome * 0.85;
    } else{
        return taxableIncome * 0.8;
    }
}

double computeNetIncome(double grossIncome, int numDependents) {
    double money = calculateTax(applyDeductions(grossIncome, numDependents));
    if (money == 0){
        return grossIncome;
    }else{
        if(numDependents > 0){
            return money + 14600 +500;
        }else{
            return money + 14600;
        }
    }
}

int main(){
    assert(computeNetIncome(100000, 2) == 83020);
    assert(computeNetIncome(10000, 0) == 10000);
}