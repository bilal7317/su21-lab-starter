#include <string.h>
#include "pwd_checker.h"
#include <assert.h>

// Checks if the length of the password is at least 10
bool check_length(const char *password) {
    int length = strlen(password); // Get the length of the password
    bool meets_len_req = (length >= 10); // Check if the length is at least 10
    return meets_len_req; 
}

// Checks if a character is within a specified range
bool check_range(char letter, char lower, char upper) {
    bool is_in_range = (letter >= lower && letter <= upper); // Check if the letter is within the range
    return is_in_range; 
}

// Checks if the password contains at least one uppercase letter
bool check_upper(const char *password) {
    while (*password != '\0') { // Loop through each character in the password
        bool is_in_range = check_range(*password, 'A', 'Z'); // Check if the character is an uppercase letter
        if (is_in_range) { // If an uppercase letter is found
            return true; 
        }
        ++password; // Move to the next character
    }
    return false; 
}

// Checks if the password contains at least one lowercase letter
bool check_lower(const char *password) {
    while (*password != '\0') { // Loop through each character in the password
        bool is_in_range = check_range(*password, 'a', 'z'); // Check if the character is a lowercase letter
        if (is_in_range) { // If a lowercase letter is found
            return true; 
        }
        ++password; // Move to the next character
    }
    return false; 
}

// Checks if the password contains at least one number
bool check_number(const char *password) {
    while (*password != '\0') { // Loop through each character in the password
        if (check_range(*password, 49, 58)) { // Check if the character is a number (ASCII values 49-58 correspond to 1-9)
            return true; // If a number is found, return true
        }
        ++password; // Move to the next character
    }
    return false; 
}

// Checks if the person's first and last name are not in the password
bool check_name(const char *first_name, const char *last_name, const char *password) {
    const char *first = strstr(password, first_name); // Check if the first name is in the password
    const char *last = strstr(password, last_name); // Check if the last name is in the password
    return (!(first || last)); // If neither the first nor the last name is in the password, return true
}

// Checks if the password meets all the specified conditions
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length, upper, lower, number, name;
    lower = check_lower(password); 
    length = check_length(password); 
    name = check_name(first_name, last_name, password); 
    number = check_number(password); 
    upper = check_upper(password); 
    return (lower && length && name && upper && number); 
}

