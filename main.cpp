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

  cout << name << endl; //display name of employee in accordance

  status = (empType == 1 ) ? "Fulltime" : "Parttime";
  cout << "\tStatus: " << status << endl;

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
  


  return netPay;
}