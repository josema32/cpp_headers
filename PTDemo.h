/* Header File:     Final Exam Part 1 - PTDemo.h     
 * Authors:         Jose Ramirez & Christian Sherwood
 * Description:     This header file maintains demographic information for a 
 *                  patient. Its functions compute to return the patient's medical
 *                  record number, full name, state, home address, gender, date of 
 *                  birth, and age. It also contains a function to print the patient's
 *                  full demographic information.
 * 
 * Due Date:        Monday December 4th, 2017
 */

#ifndef PATIENT_DEMOGRAPHIC_INFORMATION
#define PATIENT_DEMOGRAPHIC_INFORMATION

// system defined preprocessor for input/output operations
#include <iostream>
// system defined preprocessor for input/output manipulation
#include <iomanip>
// system defined preprocessor for error handling
#include <cstdlib>
// system defined preprocessor for classifying/transforming individual characters.
#include <cctype>
// system defined preprocessor for string manipulation
#include <string>
// system defined preprocessor for date/time operations
#include <ctime>

using namespace std;

// maintains demographic information about the patient
class PatientDemographicInformation
{
    private:
	string patientMedicalRecordNo;		// patient’s medical record number
	string patientFirstName;		// patient’s first name
	char   patientMiddleInitial;		// patient’s middle initial
	string patientLastName;			// patient’s last name
	string patientStreetAddress1;		// patient’s street address (line 1)
	string patientStreetAddress2;		// patient’s street address (line 2)
	string patientCity;			// patient’s city
	string patientState;			// patient’s state
	string patientZip5;			// patient’s five digit zip code
	string patientZip4;			// patient’s four digit zip code
	string patientHomeAreaCode;             // patient’s home area code
	string patientHomePhoneNo;		// patient’s home phone number
	char   patientGender;			// patient’s gender 
	int    patientDateOfBirth;		// patient’s date of birth entered in the format MMDDYYYY

    public:
	// constructor, initializes account information
	PatientDemographicInformation(string recordNo, string fName, char mInitial, string lName, 
                                      string sAddress1, string sAddress2, string city, string state, 
                                      string zip5, string zip4, string areaCode, string phoneNo, 
                                      char gender, int dateOfBirth);
									   
	// returns the patient’s medical record number. 
	string getPatientMedicalRecordNo( );
		
	// returns the patient’s first name a space middle initial a space then the last name.
	string getPatientName( );
		
	// returns the patient’s state in all capital letters.
	string getPatientState( );
		
	// prints the patient’s street address
	void   printPatientAddress(int addressOutput);
		
	// returns the patient’s home area code enclosed in parenthesis, then the home phone number
	string getPatientPhoneNumber( );
		
	// returns the patient’s gender description.
	string getPatientGender( );
		
	// Prints the patient’s date of birth with dashes. 
	void printPatientDateOfBirth( );
		
	// returns the patient’s age. 
	int    getPatientAge( );
				
	// prints the patient demographic information.
	// - - - - - - - - - - - - - - - - - - - - PATIENT INFORMATION - - - - - - - - - - - - - - - - - - - - -
	// Medical Record No.:  XXXXXXXXX              <- Patient’s Medical Record No
        //     Patient’s Name:  XX…XX X XX…XX        <- Patient’s First Name (space) Middle (space) Last Name
        //            Address:  XX...XX                <- Patient’s Street Address Line 1
	//                      XX...XX                <- Patient’s Street Address Line 2				                                           
	//                      XX...X, XX XXXXX-XXXX  <- Patient’s City (comma & sp) State (sp) Zip5 (dash) Zip4
        //                      (XXX)XXX-XXXX          <- Patient’s Phone Number
        // Gender: X – Gender Description     Date of Birth: XX/XX/XXXX     Age: XXX
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  
        void   printPatientDemographicInformation( );
};

// ***********************************************************
//      PatientDemographicInformation Class Implementation
// ***********************************************************

// class constructor and passed arguments
PatientDemographicInformation::PatientDemographicInformation(string recordNo, string fName, char mInitial, string lName, 
                                                             string sAddress1, string sAddress2, string city, string state, 
                                                             string zip5, string zip4, string areaCode, string phoneNo, 
                                                             char gender, int dateOfBirth)
{
	patientMedicalRecordNo = recordNo;
	patientFirstName       = fName;
	patientMiddleInitial   = mInitial;
	patientLastName        = lName;
	patientStreetAddress1  = sAddress1;
	patientStreetAddress2  = sAddress2;
	patientCity            = city;
	patientState           = state;
	patientZip5            = zip5;
	patientZip4            = zip4;
	patientHomeAreaCode    = areaCode;
	patientHomePhoneNo     = phoneNo;
	patientGender          = gender;
	patientDateOfBirth     = dateOfBirth;
}

// Author: Jose Ramirez
// returns the patient’s medical record number. 
string PatientDemographicInformation::getPatientMedicalRecordNo( )
{
    // checks if the patient medical record is blank
    if (patientMedicalRecordNo == "")
    {
        cerr << "No medical record number available." << endl;
	exit(1);
    }
    else
    {
        return patientMedicalRecordNo;
    }
}

// Author: Jose Ramirez
// returns the patient’s first name a space middle initial a space then the last name
string PatientDemographicInformation::getPatientName( )
{
    // checks if the name of the patient was submitted then returns the full name
    if (patientFirstName == "" && patientLastName == "")
    {
        cerr << "Patient name was not submitted." << endl;
        exit(1);
    }
    else
    {
        return patientFirstName + " " + patientMiddleInitial + " " + patientLastName;
    }
}

// Author: Jose Ramirez
// returns the patient’s state in all capital letters.
string PatientDemographicInformation::getPatientState( )
{
    string allCapsState;
    
    // checks if the patient state is available and then iterates through
    //  each character of the state and converts it to upper case
    if (patientState == "")
    {
        cerr << "The patient state is not on record!" << endl;
	exit(1);
    }
    else
    {
        for (int i=0; i < patientState.length(); i++)
        {
            patientState[i] = toupper(patientState[i]);
            allCapsState   += patientState[i];
        }
        return allCapsState;
    }
}

// Author: Jose Ramirez
// prints the patient’s street address with two different outputs,
// argument "1" outputs the patients address if available, argument "2" 
// formats the output to be used with printPatientDemographiInformation()
void PatientDemographicInformation::printPatientAddress(int addressOutput)
{
    // checks if the patient address is available then outputs the address
    if (patientStreetAddress1 == "" || patientCity == "" ||
        patientState          == "" || patientZip5 == "")
        
    {
        cout << "Patient address was not submitted." << endl;
    }
    else if (addressOutput == 1)
    {
        if (patientStreetAddress2 == "")
        {
            cout << patientStreetAddress1 << endl
                 << patientCity + ", " + getPatientState() 
                                + "  " + patientZip5 
                                + "-"  + patientZip4 
                 << endl;  
        }
        else 
        {
            cout << patientStreetAddress1 << endl
                 << patientStreetAddress2 << endl
                 << patientCity + ", " + getPatientState() 
                                + "  " + patientZip5 
                                + "-"  + patientZip4 
                 << endl;
        }
    }
    else if (addressOutput == 2)
    {
        if (patientStreetAddress2 == "")
        {
            cout << patientStreetAddress1 << endl
                 << "                    "  + patientCity + ", " + getPatientState() + "  " 
                                            + patientZip5 + "-"  + patientZip4 
                 << endl;  
        }
        else 
        {
            cout << patientStreetAddress1 << endl
                 << "                    "  + patientStreetAddress2 << endl
                 << "                    "  + patientCity + ", " + getPatientState() + "  " 
                                            + patientZip5 + "-"  + patientZip4 
                 << endl;
        }
    }
    else
    {
        cerr << "Invalid address output has been passed!" << endl;
        exit(1);
    }
}

// Author: Christian Sherwood
// Concatenate the parenthesis around the area code, and use a substring to separate the first
// 3 numbers, add a dash, and use a substring for the last 4 numbers.
string PatientDemographicInformation::getPatientPhoneNumber()
{
    if (patientHomeAreaCode == "" || patientHomePhoneNo == "")
    {
        cerr << "The patient phone number is not on record!" << endl;
	exit(1);
    }
    else
    {
        return "(" + patientHomeAreaCode + ")" + patientHomePhoneNo.substr(0,3) + "-" + patientHomePhoneNo.substr(3,8);
    }
}

// Author: Christian Sherwood
// Use an if statement to determine the gender, then concatenate 
// the gender description onto the end.
string PatientDemographicInformation::getPatientGender( )
{
    if(patientGender == 'F' || patientGender == 'f')
        {
            return "F - Female";
	}
    else if(patientGender == 'M' || patientGender == 'm')
        {
            return "M - Male";
	}
    else
        {
            cout << "Invalid Gender!";
	}
}

// Author: Christian Sherwood
// Breaks the date into month, day, and year with division and remainder
// then prints the date to the screen with the format MM/DD/YYYY
void PatientDemographicInformation::printPatientDateOfBirth( )
{
    // Subtract the 1 added at the beginning of the date to break the octet rule
    // and allow for leading zeroes
    patientDateOfBirth -= 100000000;
    
    int month = (patientDateOfBirth / 1000000); 
    int day   = (patientDateOfBirth % 1000000)/10000;
    int year  = (patientDateOfBirth % 10000);
	
    cout << month << "/" << day << "/" << year;
}

// Author: Christian Sherwood
// returns the patient age
int PatientDemographicInformation::getPatientAge( )
{
    // initialize a time_t object
    time_t currentDate;

    // create a tm structure to find the current year
    struct tm currentYear;
	
    // take the time_t value and set it to a readable local value
    currentDate =  time(NULL);
    currentYear =* localtime(&currentDate);
    
    // return the current year + 1900 minus the patient's birth year to get age
    // *NOTE* The computer views date years as years past 1900, so you have to add
    // 1900 to get a current 4 digit year.
    return ((currentYear.tm_year + 1900) - (patientDateOfBirth % 10000));
}

// Author: Christian Sherwood
// prints the patient demographic information.
// - - - - - - - - - - - - - - - - - - - - PATIENT INFORMATION - - - - - - - - - - - - - - - - - - - - -
// Medical Record No.:  XXXXXXXXX              <- Patient’s Medical Record No
//     Patient’s Name:  XX…XX X XX…XX         <- Patient’s First Name (space) Middle (space) Last Name
//            Address:  XX...XX                <- Patient’s Street Address Line 1
//                      XX...XX                <- Patient’s Street Address Line 2				                                           
//                      XX...X, XX XXXXX-XXXX  <- Patient’s City (comma & sp) State (sp) Zip5 (dash) Zip4
//                      (XXX)XXX-XXXX          <- Patient’s Phone Number
// Gender: X – Gender Description     Date of Birth: XX/XX/XXXX     Age: XXX
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void PatientDemographicInformation::printPatientDemographicInformation( )
{
    cout << "- - - - - - - - - - - - - - - - - - - - PATIENT INFORMATION - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Medical Record No.: " << getPatientMedicalRecordNo()                                                   << endl;
    cout << "    Patient's Name: " << getPatientName()                                                              << endl;
    cout << "           Address: "; 
    
    printPatientAddress(2); 
        
    cout << "                    " << getPatientPhoneNumber()                                                       << endl;
    cout << "Gender: "             << getPatientGender();
    cout << "    Date of Birth: ";
    
    printPatientDateOfBirth();
    
    cout << "    Age: " << getPatientAge() << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

#endif
