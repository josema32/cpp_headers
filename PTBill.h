/* Header File:     Final Exam Part 1 - PTBill.h     
 * Author:          Jose Ramirez
 * Description:     This header file maintains billing information for a 
 *                  patient. Its functions return the patient's diagnosis code,
 *                  monthly payment status for financing, and the balance. It also
 *                  prints the patient's full billing information.
 * 
 * Due Date:        Monday December 4th, 2017
 */

#ifndef PATIENT_BILLING_INFORMATION
#define PATIENT_BILLING_INFORMATION

// system defined preprocessor for input/output operations
#include <iostream>
// system defined preprocessor for input/output manipulation
#include <iomanip>
// system defined preprocessor for error handling
#include <cstdlib>

using namespace std;

// maintains billing information about the patient
class PatientBillingInformation
{
    private:
	string patientMedicalRecordNo;		// patient’s medical record number
	string patientDiagnosisCode;		// patient’s diagnosis code
	bool   patientMonthlyPaymentStatus;     // patient’s monthly payment status 					
        double patientMonthlyPaymentAmt;	// patient’s monthly payment amount
	double patientCharge;			// patient’s charge

    public:
	// constructor, initializes the patient billing information
	PatientBillingInformation(string recordNo,    string diagnosisCode, 
                                  bool paymentStatus, double paymentAmt, 
                                  double charge);
		
	// returns the patient’s diagnosis code
	string getPatientDiagnosisCode( );
		
	// returns a “Y” if the patient is utilizing the monthly payment plan; 
        // otherwise it returns an “N”
	char getPatientMonthlyPaymentStatus( );
		
	// returns the patient’s balance, if the patient monthly payment status  
	// is "Y" 10% finance charge will be added to the amount
	double getPatientBalance( );
		
	// prints the patient billing information:
	//
	// - - - - - - - - - - - - - - - - - - - - - BILLING INFORMATION - - - - - - - - - - - - - - - - - - - -
	//  Charge                  Finance Charge                  Payment Amount             Balance
	// $XXXX.XX                   $XXX.XX                           $XXX.XX               $XXXXX.XX          
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
	void printPatientBillingInformation( );
};

// ***********************************************************
//      PatientBillingInformation Class Implementation
// ***********************************************************

// constructor, initializes the patient billing information
PatientBillingInformation::PatientBillingInformation(string recordNo,    string diagnosisCode, 
                                                     bool paymentStatus, double paymentAmt, 
                                                     double charge)
{
    patientMedicalRecordNo      = recordNo;
    patientDiagnosisCode        = diagnosisCode;
    patientMonthlyPaymentStatus = paymentStatus;
    patientMonthlyPaymentAmt    = paymentAmt;  
    patientCharge               = charge;       
}
		
// returns the patient’s diagnosis code
string PatientBillingInformation::getPatientDiagnosisCode( )
{
    if (patientDiagnosisCode == "")
    {
	cerr << "The diagnosis code was not entered." << endl;
	exit(4);
    }
    else
    {
        return patientDiagnosisCode;
    }
}
		
// returns a 'Y' if the patient is utilizing the monthly payment plan 
// otherwise it returns 'N' or an error message
char PatientBillingInformation::getPatientMonthlyPaymentStatus( )
{  
    if (patientMonthlyPaymentStatus)
    {
	return 'Y';
    }
    else if (patientMonthlyPaymentStatus == false)
    {
        return 'N';
    }
    else
    {
        cerr << "Monthly payment status is not set." << endl;
        exit(1);
    }
}
		
// returns the patient’s balance, if the patient monthly payment status is 'Y'  
// 10% finance charge will be added to the amount
double PatientBillingInformation::getPatientBalance( )
{
    // finance charge %
    const double FINANCE_CHARGE = 0.10;
    
    // calculated finance charge amount
    double financeChargeAmt;
    
    // checks if the patient has a charge amount first
    if (patientCharge == 0.00)
    {
        cerr << "There is no balance on the patient's account." << endl;
        exit(1);
    }
    else if (getPatientMonthlyPaymentStatus() == 'Y')
    {
        financeChargeAmt = patientCharge * FINANCE_CHARGE;
	return (patientCharge += financeChargeAmt) - patientMonthlyPaymentAmt;
    }
    else
    {
        return patientCharge - patientMonthlyPaymentAmt;
    }
}
		
// prints the patient billing information with the following format:
// - - - - - - - - - - - - - - - - - - - - - BILLING INFORMATION - - - - - - - - - - - - - - - - - - - -
//  Charge                  Finance Charge                  Payment Amount             Balance
// $XXXX.XX                   $XXX.XX                           $XXX.XX               $XXXXX.XX          
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -	
void PatientBillingInformation::printPatientBillingInformation( )
{
    // finance charge %
    const double FINANCE_CHARGE = 0.10;
    
    // finance charge amount for output purposes
    double financeChargeAmt = 0.00;
    
    // checks if a finance charge is applicable
    if (getPatientMonthlyPaymentStatus()=='Y')
    {
        financeChargeAmt = patientCharge * FINANCE_CHARGE;
    }
    
    cout << "- - - - - - - - - - - - - - - - - - - - - BILLING INFORMATION - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "  Charge                  Finance Charge                  Payment Amount             Balance	  " << endl;
    cout << "  $"                         << setw(6) << setprecision(2) << fixed << patientCharge 
	 << "                $"           << setw(6) << setprecision(2) << fixed << financeChargeAmt 
         << "                         $"  << setw(6) << setprecision(2) << fixed << patientMonthlyPaymentAmt 
         << "                   $"        << setw(6) << setprecision(2) << fixed << getPatientBalance()             << endl;          
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

#endif