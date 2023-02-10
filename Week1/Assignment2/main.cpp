//==============================================================
// Filename : main.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Calculate BMI of the user
//==============================================================

#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>

/**
 * Reads the weight and height of the user from standard input.
 * @param weight float reference to store the user's weight.
 * @param height float reference to store the user's height.
 */
void readInput(float &weight, float &height){
    std::string weightStr, heightStr;
    std::cout << "Please enter you weight in kg and press enter:" << std::endl;
    std::cin >> weightStr;
    std::cout << "Your weight is " << weightStr << "kg" << std::endl << "Please enter your height in meters:" << std::endl;
    std::cin >> heightStr;
    std::cout << "Your height is " << heightStr << "m" << std::endl << std::endl;
    weight = std::stof(weightStr);
    height = std::stof(heightStr);
}

/**
 * Calculates the body mass index (BMI) of the user.
 * @param weight float weight of the user.
 * @param height float height of the user.
 * @return float value of the user's BMI.
 */
float calculateBMI(float weight, float height){
    return weight / (height * height);
}

/**
 * Evaluates the user's BMI and prints the corresponding message.
 * @param BMI float user's body mass index.
 */
void evaluateAndPrintBMI(float BMI){
    std::cout << "Your weight is ";
    if(BMI < 18.5) {
        std::cout << "underweight.";
    }
    else if(18.5 <= BMI && BMI < 25) {
        std::cout << "normal.";
    }
    else if(25 <= BMI && BMI < 30) {
        std::cout << "overweight.";
    }
    else if(30 <= BMI)
    {
        std::cout << "obese.";
    }
    else {
        std::cout << std::endl << "Error: your BMI broke the system!!!" << std::endl;
    }
    std::cout << std::endl << std::endl;
}

/**
 * Prints information about the BMI values.
 */
void printInfo(){
    std::cout << "BMI VALUES:" << std::endl;
    std::cout << std::left << std::setw(16) << "Underweight:" << std::left << std::setw(32) << "less than 18.5" << std::endl;
    std::cout << std::left << std::setw(16) << "Normal:" << std::left << std::setw(32) << "between 18.5 and 24.9" << std::endl;
    std::cout << std::left << std::setw(16) << "Overweight:" << std::left << std::setw(32) << "between 25 and 29.9" << std::endl;
    std::cout << std::left <<   std::setw(16) << "Obese:" << std::left << std::setw(32) << "more than 30" << std::endl;
}

int main(){
    float weight, height, BMI;
    readInput(weight, height);
    BMI = calculateBMI(weight, height);
    std::cout << "Your BMI is: " << BMI << std::endl;
    evaluateAndPrintBMI(BMI);
    printInfo();
    return 0;
}