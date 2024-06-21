#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
// Function to calculate BMI
double calculateBMI(double weight, double height) {
return weight / pow(height / 100, 2);
}
// Function to get user input with validation
double getUserInput(string prompt, string errorMessage) {
double value = 0;
while (value <= 0) {
cout << prompt;
cin >> value;
if (value <= 0) {
cout << errorMessage << endl;
}
}
return value;
}
// Function to display health tips
void displayHealthTips(string healthStatus) {
if (healthStatus == "Underweight") {
cout << "Health tips for underweight individuals:\n";
cout << "- Eat nutrient-dense foods to help gain weight.\n";
cout << "- Consume more protein to build muscle.\n";
cout << "- Consume fiber dense food and whole grain.\n";
cout << "- Incorporate strength training into your exercise routine.\n";
} else if (healthStatus == "Healthy") {
cout << "Health tips for healthy individuals:\n";
cout << "- Maintain a balanced diet that includes a variety of nutrients.\n";
cout << "- Stay physically active for at least 30 minutes per day.\n";
cout << "- Get enough sleep to help your body recover.\n";

} else if (healthStatus == "Overweight") {
cout << "Health tips for overweight individuals:\n";
cout << "- Reduce your calorie intake to create a calorie deficit.\n";
cout << "- Increase your physical activity to help burn calories.\n";
cout << "- Incorporate strength training into your exercise routine.\n";
} else {
cout << "Health tips for obese individuals:\n";
cout << "- Consult a health care professional for guidance on weight loss.\n";
cout << "- Reduce your calorie intake to create a calorie deficit.\n";
cout << "- Increase your physical activity to help burn calories.\n";
}
}
// Function to validate user name
bool isValidUsername(string username) {
if (username.length() < 6 || username.length() > 12) {
return false;
}
for (int i = 0; i < username.length(); i++) {
if (!isalnum(username[i])) {
return false;
}
}
return true;
}
// Function to validate password
bool isValidPassword(string password) {
if (password.length() < 8 || password.length() > 20) {
return false;
}
bool hasUpperCase = false;
bool hasLowerCase = false;
bool hasDigit = false;
for (int i = 0; i < password.length(); i++) {
if (isupper(password[i])) {
hasUpperCase = true;
}
if (islower(password[i])) {
hasLowerCase = true;
}

if (isdigit(password[i])) {
hasDigit = true;
}
}
return hasUpperCase && hasLowerCase && hasDigit;
}
int main() {
cout<<"===================================================================
====================================================="<<endl;
cout<<" Welcome to User Health System "<<endl<<endl<<endl;
cout<<" please enter to continue..."<<endl<<endl<<endl;
cout<<"===================================================================
====================================================="<<endl;
cin.ignore();
cout<<" For enjoying our services you have to register first "<<endl<<endl;
cout<<" Sign up(press enter key)"<<endl<<endl<<endl;
cin.ignore();
string username, password;
bool validUsername = false;
bool validPassword = false;
while (!validUsername || !validPassword) {
cout << "Username \n(6-12 alphanumeric characters): ";
cin >> username;
if (isValidUsername(username)) {
validUsername = true;
}
cout << "Please enter a password" <<endl<<"(8-20 characters with at least one uppercase letter,
one lowercase letter, and one digit): ";
cin >> password;
if (isValidPassword(password)) {
validPassword = true;
cout<<endl<<endl<<"Registration successful"<<endl<<endl;
} else {
cout << "Invalid username." << endl;
cout << "Invalid password." << endl;
}
}

// Login
bool isRegistered = false, isLoggedIn = false;
cout << "\n\n << Login >>
\n________________________________________________________________________________
______________________________________\n";
while (!isLoggedIn) {
string enteredUsername, enteredPassword;
cout << "Username: ";
cin >> enteredUsername;
cout << "Password: ";
cin >> enteredPassword;
if (enteredUsername == username && enteredPassword == password) {
isLoggedIn = true;
cout <<endl<< "Login successful!\n\n";
} else {
cout << "Invalid username or password. Please try again.\n";
}
}
// Get user info and calculate BMI
double height = 0, weight = 0, age = 0, bmi = 0;
height = getUserInput("Enter your height (in cm): ", "Invalid input. Please enter a positive value.");
weight = getUserInput("Enter your weight (in kg): ", "Invalid input. Please enter a positive value.");
age = getUserInput("Enter your age: ", "Invalid input. Please enter a positive value.");
cout<<endl;
bmi = calculateBMI(weight, height);
cout << "Your BMI is: " << bmi << endl;
// Determine health status
string healthStatus;
if (bmi < 18.5) {
healthStatus = "Underweight";
} else if (bmi >= 18.5 && bmi < 25) {
healthStatus = "Healthy";
} else if (bmi >= 25 && bmi < 30) {
healthStatus = "Overweight";
} else {
healthStatus = "Obese";
}

cout << "You are " << healthStatus << endl;
// Write results to file
ofstream outputFile;
outputFile.open("results.txt");
outputFile << "\n\nUsername: " << username << endl;
outputFile << "Age: " << age << endl;
outputFile << "Height (cm): " << height << endl;
outputFile << "Weight (kg): " << weight << endl;
outputFile << "BMI: " << bmi << endl;
outputFile << "Health Status: " << healthStatus << endl;
outputFile.close();
// Ask user if they want to see past results
char viewResults;
cout << "\n\nWould you like to view past results? (y/n): ";
cin >> viewResults;
if (viewResults == 'y' || viewResults == 'Y') {
ifstream inputFile;
inputFile.open("results.txt");
string line;
while (getline(inputFile, line)) {
cout << line << endl;
}
inputFile.close();
}
//Ask user if they want some health tips
char healthtips;
cout<<"\n\nWould you like to get some health tips? (y/n):";
cin>> healthtips;
cout<<endl<<endl;
if (healthtips == 'y' || healthtips == 'Y') {
displayHealthTips( healthStatus);
}
return 0;
}
