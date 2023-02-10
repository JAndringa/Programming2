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

/**
 * @brief Structure to store date information.
 *
 */
struct Date{
    int day;               //!< Day of the date
    int month;             //!< Month of the date
    int year;              //!< Year of the date
    /**
     * @brief Construct a new Date object
     *
     * @param day Day of the date
     * @param month Month of the date
     * @param year Year of the date
     */
    Date(int day, int month, int year) :
            day(std::min(31, std::max(1, day))),
            month(std::min(12, std::max(1, month))),
            year(std::min(2023, year)){
        if(day < 1 || day > 31 || month < 1 || month > 12 || year > 2023){
            std::cout << "!!WARNING!!!" << std::endl << "Invalid date entered, rounded to the nearest valid date." << std::endl;
        }
    }
};

/**
 * @brief Function to get the current date.
 *
 * @return Date Returns the current date.
 */
Date getCurrentDate(){
    time_t currentTime = time(0);               // Get the current time in seconds since epoch
    tm *now = localtime(&currentTime);         // Convert the time to broken-down time format
    return Date(now->tm_mday, now->tm_mon, now->tm_year+1900);
}

/**
 * @brief Class to store human information.
 *
 */
class Human{
private:
    std::string firstName;      //!< First name of the human
    std::string lastName;       //!< Last name of the human
    Date dateOfBirth;           //!< Date of birth of the human
public:
    /**
     * @brief Construct a new Human object
     *
     * @param firstName First name of the human
     * @param lastName Last name of the human
     * @param dateOfBirth Date of birth of the human
     */
    Human(std::string firstName, std::string lastName, Date dateOfBirth) :
            firstName(firstName),
            lastName(lastName),
            dateOfBirth(dateOfBirth){}

    /**
     * @brief Set the name of the human.
     *
     * @param firstName First name of the human
     * @param lastName Last name of the human
     */
    void setName(std::string firstName, std::string lastName){
        this->firstName = firstName;
        this->lastName = lastName;
    }

    /**
     * @brief Set the date of birth of the human.
     *
     * @param day Day of the date of birth
     * @param month Month of the date of birth
     * @param year Year of the date of birth
     */
    void setDateOfBirth(Date dateOfBirth){
        this->dateOfBirth = dateOfBirth;
    }

    /**
     * @brief Get the first name of the human.
     *
     * @return std::string Returns the first name of the human
     */
    std::string getFirstName(){return firstName;}

    /**
     * @brief Get the last name of the human.
     *
     * @return std::string Returns the last name of the human
     */
    std::string getLastName(){return lastName;}

    /**
     * @brief Get the date of birth of the human.
     *
     * @return Date Returns the date of birth of the human
     */
    Date getDateOfBirth(){return dateOfBirth;}

    /**
     * @brief Calculates the age of the human
     *
     * @return int Returns the age of the human
     */
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

    /**
     * @brief Calculate the maximum allowed heart rate for the human.
     *
     * @return int Returns the maximum allowed heart rate of the human
     */
    int calculateMaximumHeartRate(){
        return 220 - this->getAge();
    }

    /**
     * @brief Calculates the suggested target heart rate range of the human.
     *
     * @return std::map<std::string, int> Returns a mapping of the maximum and minimum target heart rate
     */
    std::map<std::string, int> calculateTargetHeartRates(){
        std::map<std::string, int> heartRates;
        heartRates["minimum"] = this->calculateMaximumHeartRate() * 0.5;
        heartRates["maximum"] = this->calculateMaximumHeartRate() * 0.85;
        return heartRates;
    }
};

/**
 * readInput - A function that prompts the user to input their full name and date of birth
 *
 * @return Human - A Human object created using the user-inputted information
 */
Human readInput(){
    // Variables to store the user's first name, last name, and date of birth
    std::string firstName, lastName;
    int day, month, year;

    // Prompt the user to enter their full name
    std::cout << "Please give your full name and press enter:" << std::endl;
    std::cin >> firstName >> lastName;

    // Prompt the user to enter their date of birth
    std::cout << "Please give your date of birth in the following format: day month year" << std::endl;
    std::cin >> day >> month >> year;

    // Return a Human object created using the user-inputted information
    return Human(firstName, lastName, {day, month, year});
}

/**
 * printInfo - A function that outputs various information about a Human object
 *
 * @param user - The Human object whose information is to be outputted
 */
void printInfo(Human user){
    // Output the user's name
    std::cout << std::left << std::setw(20) << "Name: " << user.getFirstName() << " " << user.getLastName() << std::endl;

    // Output the user's date of birth
    std::cout << std::left << std::setw(20) << "Birthday: " << std::right << std::setw(2) << std::setfill('0') << user.getDateOfBirth().day << "/" << std::right << std::setw(2) << std::setfill('0') << user.getDateOfBirth().month << "/" << user.getDateOfBirth().year << std::endl;

    // Output the user's age
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "Age: " << user.getAge() << std::endl;

    // Output the user's maximum heart rate
    std::cout << std::left << std::setw(20) << "Maximum heart rate: " << user.calculateMaximumHeartRate() << std::endl;

    // Output the user's heart rate range
    std::cout << std::left << std::setw(20) << "Heart rate range: " << user.calculateTargetHeartRates()["minimum"] << " - " << user.calculateTargetHeartRates()["maximum"] << std::endl;
}

/**
 * main - The entry point of the program
 *
 * @return int - The exit status of the program (0 for success)
 */
int main(){
    // Output information about the user created using the user-inputted information
    printInfo(readInput());

    // Return success status
    return 0;
}