#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
using namespace std;

double weeklyPay(double, double, string, int); //function prototype


int main() 

{
  
  cout << fixed << setprecision(2);
  cout << weeklyPay (47.00, 505.75, "Orlando", 1) << endl;
  cout << weeklyPay (45.00, 55.25, "Melvin", 1) << endl;
  cout << weeklyPay (15.00, 65.25, "Susan", 2) << endl;
  cout << weeklyPay (41.00, 14.75, "Mika", 1) << endl;
  cout << weeklyPay (25.00, 15.00, "Eldridge", 2) << endl;
  cout << weeklyPay (55.00, 203.50, "Freedom", 1) << endl;
  cout << weeklyPay (32.50, 100.25, "Tyson", 1) << endl;
  
  
  return 0;
}

double weeklyPay(double hours, double rate, string name, int empType)
{
  double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
  double ss = 0.062, med = 0.0145, sSwages = 0.0, medWages = 0.0;
  double FIT = 0.0, fitTax = 0.0, dental = 0.0, retirement = 0.0;
  double clockHours = 40.0, overtimeRate = 2.0, overTimeIfAny = 0.0;
  locale loc;
  string status = "";

  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(31) + ";1m";

  cout << color << endl;
  for(int i = 0; i < name.length(); i++ )
  {
    cout << toupper(name[i],loc); 
  } 
cout << reset << endl;  //display name of employee in accordance to all capitals

  status = (empType == 1 ) ? "Fulltime" : "Parttime";
  

  overTimeIfAny = ((hours - clockHours) > 0.0 ) ? (hours-clockHours) : 0.0; 
  //Processing
  grossPay = (hours <= clockHours) ? (hours * rate) :
     ((clockHours * rate) + ((overTimeIfAny) * (overtimeRate *
       rate)));

  dental = (empType == 1 ) ? 17.0 : 0.0;
  
  retirement = (empType == 1 ) ? 77.0 : 0.0;

  FIT = (rate < 15.00 ) ? 0.12 : 0.15;

  taxableWages = grossPay -(dental + retirement);
  
  fitTax = taxableWages * FIT;
  
  sSwages = grossPay * ss;
  
  medWages = grossPay * med;
  
  netPay = grossPay - (dental + retirement + fitTax + sSwages + medWages);

  //Output
  cout << "Status: " << status << endl;
  cout << "Gross Pay: $" << grossPay << endl;
  cout << "Dental Deduction: $" << dental << endl;
  cout << "Retirement Deduction: $" << retirement << endl;
  cout << "Taxable Wages: $" << taxableWages << endl;
  cout << "Federal Income Tax: $" << fitTax << endl;
  cout << "Social Security Taxes: $" << sSwages << endl;
  cout << "Medicare Taxes: $" << medWages << endl;
  cout << "Net Pay: $";


  return netPay;
}