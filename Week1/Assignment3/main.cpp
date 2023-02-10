//==============================================================
// Filename : main.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Calculate a target heart rate range for the user
//==============================================================

#include <iostream>
#include <string.h>
#include <ctime>
#include <map>
#include <iomanip>

struct Date{
    int day;
    int month;
    int year;
    Date(int day, int month, int year) :
    day(std::min(31, std::max(1, day))),
    month(std::min(12, std::max(1, month))),
    year(std::min(2023, year)){
        if(day < 1 || day > 31 || month < 1 || month > 12 || year > 2023){
            std::cout << "!!WARNING!!!" << std::endl << "Invalid date entered, rounded to the nearest valid date." << std::endl;
        }
    }
};

Date getCurrentDate(){
    time_t currentTime = time(0);
    tm *now = localtime(&currentTime);
    return Date(now->tm_mday, now->tm_mon, now->tm_year+1900);
}

class Human{
private:
    std::string firstName;
    std::string lastName;
    Date dateOfBirth;
public:
    Human(std::string firstName, std::string lastName, Date dateOfBirth) :
        firstName(firstName),
        lastName(lastName),
        dateOfBirth(dateOfBirth){}

    void setName(std::string firstName, std::string lastName){
        this->firstName = firstName;
        this->lastName = lastName;
    }
    void setDateOfBirth(int day, int month, int year){
        dateOfBirth.day = day;
        dateOfBirth.month = month;
        dateOfBirth.year = year;
        if(day < 1 || day > 31 || month < 1 || month > 12 || year > 2023){
            std::cout << "!!WARNING!!!" << std::endl << "Invalid date entered, rounded to the nearest valid date." << std::endl;
        }
    }
    void setDateOfBirth(Date dateOfBirth){
        this->dateOfBirth = dateOfBirth;
    }

    std::string getFirstName(){return firstName;}
    std::string getLastName(){return lastName;}
    Date getDateOfBirth(){return dateOfBirth;}

    int getAge(){
        Date now = getCurrentDate();
        int age = now.year - this->dateOfBirth.year;
        if(this->dateOfBirth.month > now.month){
            return --age;
        }
        else if(this->dateOfBirth.month = now.month){
            if(this->dateOfBirth.day > now.day){
                return --age;
            }
            else if(this->dateOfBirth.day <= now.day){
                return age;
            }
            else{
                std::cout << "ERROR: impossible date. This should never happen!" << std::endl;
                return -1;
            }
        }
        else if(this->dateOfBirth.month < now.month){
            return age;
        }
        else {
            std::cout << "ERROR: impossible date. This should never happen!" << std::endl;
            return -1;
        }
    }

    int calculateMaximumHeartRate(){
        return 220 - this->getAge();
    }

    std::map<std::string, int> calculateTargetHeartRates(){
        std::map<std::string, int> heartRates;
        heartRates["minimum"] = this->calculateMaximumHeartRate() * 0.5;
        heartRates["maximum"] = this->calculateMaximumHeartRate() * 0.85;
        return heartRates;
    }
};

Human readInput(){
    std::string firstName, lastName;
    int day, month, year;
    std::cout << "Please give your full name and press enter:" << std::endl;
    std::cin >> firstName >> lastName;
    std::cout << "Please give your date of birth in the following format: day month year" << std::endl;
    std::cin >> day >> month >> year;
    return Human(firstName, lastName, {day, month, year});
}

void printInfo(Human user){
    std::cout << std::left << std::setw(20) << "Name: " << user.getFirstName() << " " << user.getLastName() << std::endl;
    std::cout << std::left << std::setw(20) << "Birthday: " << std::right << std::setw(2) << std::setfill('0') << user.getDateOfBirth().day << "/" << std::right << std::setw(2) << std::setfill('0') << user.getDateOfBirth().month << "/" << user.getDateOfBirth().year << std::endl;
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "Age: " << user.getAge() << std::endl;
    std::cout << std::left << std::setw(20) << "Maximum heart rate: " << user.calculateMaximumHeartRate() << std::endl;
    std::cout << std::left << std::setw(20) << "Heart rate range: " << user.calculateTargetHeartRates()["minimum"] << " - " << user.calculateTargetHeartRates()["maximum"] << std::endl;
}

int main(){
    printInfo(readInput());
    return 0;
}