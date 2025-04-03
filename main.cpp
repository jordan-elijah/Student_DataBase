#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;


int main() {
    //List of Students
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jordan-Elijah,Baez,jbaez65@wgu.edu,27,35,45,50,SOFTWARE"
    };
    //Output Heading
    cout << "C867: Scripting and Programming - Applications\nLanguage Used: C++\nStudent ID No. 011163565\nName: Jordan-Elijah Baez \n \n";
    roster* classRoster = new roster(5);
    student student;
    for (int n = 0; n < 5; n++) {
        classRoster->parse(studentData[n]);
    };

    //Prints List of all students in Student Data Table
    classRoster->printAll();
    cout << endl;
    cout << endl;
   
    //Prints output for average days in course for all students
    cout << "Now Displaying Average Course Time for Current Students: \n \n" << endl;
   
    for (int n = 0; n < 5; n++) {
       
        classRoster->printAvgDaysInCourse(classRoster->getStudentClassID(n));

    }

    //Prints out all Students with invalid emails
    cout << " \n \nNow Displaying All Invalid Student Emails: \n \n" << endl;
    
    {

        classRoster->printBadEmails();
    }
    cout <<"\n"<< endl;
    
    //Filters and prints students out by specified degree type
    cout << "Displaying All Students in the SOFTWARE Program:\n\n";

    {
        classRoster->printViaDegreeType(SOFTWARE);
    }
    cout << "\n \n" << endl;

    //Prints out students with inalid credentails, dplayed by Student ID
    cout << "Searching for Invalid Students to remove: \n \n" << endl;
    {
        classRoster->removeStudent("A3");
    }
    cout << "\n " << endl;

    //printAll() function called once more to prove student removal functionality
    {
        classRoster->printAll();
    }

    cout << "\n" << endl;
    //Uses same remove function to confirm student has been successfully removed
    cout << "Attempting to Remove Invalid Students Again: \n \n" << endl;

    {
        classRoster->removeStudent("A3");
    }

    cout << "\n" << endl;
//COUT used to declare end of script
    cout << "DONE." << endl;

  //destuctor called as requested
    {
        classRoster->~roster();
        delete classRoster;
    }

}