Workshop #5: Member Operators, Helper functions

Version 0.9 Version 0.91 (Corrected lab due-date to Thursday)

In this workshop, you will implement different types of operator overload in a partially developed class.
Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

    define and create binary member operator
    define and create a type conversion operator
    define and a create unary member operator
    define and create helper binary operator between classes
    define and create a helper operator between a primitive type and a class.

Submission Policy

The workshop is divided into two coding parts; part 1, LAB and part 2, DIY and one non-coding part:

    LAB (part 1): worth 50% of the workshop's total price, is due on Thursday at 23:59:59 of the week of your scheduled lab.

    Please note that the LAB (part 1) section is not to be started in your lab session. You should start it on your own before the day of your lab and join the lab session to ask for help and correct your mistakes.

    DIY (part 2): worth 50% of the workshop's total price, is due on Sunday at 23:59:59 of the week of your scheduled lab. Submissions of DIY part that do not contain the reflection are not considered valid submissions and are ignored.

    reflection: non-coding part, to be submitted together with DIY part. The reflection doesn't have prices associated with it but can incur a penalty of max 40% of the whole workshop's price if your professor deems it insufficient (you make your prices from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of one day when you can submit the missing parts. The code parts that are submitted late receive 0%. After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), the price for the entire workshop is 0%.

Every file that you submit must contain (as a comment) at the top your name, your Seneca email, Seneca Employee ID and the date when you completed the work.

If the file contains only your work or work provided to you by your professor, add the following message as a comment at the top of the file:

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

If the file contains work that is not yours (you found it online or somebody provided it to you), write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from. By doing this you will only lose the price for the parts you got help for, and the person helping you will be clear of any wrongdoing.
Compiling and Testing Your Program

All your code should be compiled using this command on matrix:

g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...

    -Wall: the compiler will report all warnings
    -std=c++11: the code will be compiled using the C++11 standard
    -g: the executable file will contain debugging symbols, allowing valgrind to create better reports
    -o ws: the compiled application will be named ws

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is ws):

valgrind ws

To check the output, use a program that can compare text files. Search online for such a program for your platform, or use diff available on matrix.

    Note: All the code written in workshops and the project must be implemented in the sdds namespace.

LAB (50%) The Account module.

Your task for this lab is to complete the implementation of the Account module for holding a bank account number (an integer) and the balance of the account (a double value).
The Account class

The Account class has two attributes; one integer for an account number (m_number) and a double for the balance of the account (m_balance)

The Account class can be in three different states:

    Invalid Empty State
    An account is in an invalid state if invalid information is fed into the account. In these types of situations the account number is set to -1 and the balance is set to 0. The Account object in this case is rendered inactive and can not be used anymore.
    New
    An account is considered New or not set when it is just created and the account number is not assigned yet. This state of the Account class is flagged by setting the account number (m_number) to 0.
    Valid
    An Account is considered valid if the account number is a 5 digit integer with a zero or positive balance.

Already implemented parts:
Constructors

The Account can be created in two different ways:

    default constructor (implemented)

    Account();

    The default constructor sets the account as new with a balance of 0.
    Two argument constructor (and integer and a double) (implemented)

    Account(int number, double balance);

    The two-argument constructor sets the account number and balance to incoming arguments only if both values are valid. If an invalid account number or a negative balance is passed to the constructor, the object will be set into an invalid empty state.

display function.

(implemented)

   ostream& display() const

Displays the account on the screen.
If the account is invalid, it is going to print: Bad Account. If the account is a new account, instead of the account number it will print New.
At the end display will return the cout object.
To be implemented:
type conversion operators

    operator bool
    returns true if the account is valid and otherwise false. This operator can not modify the account object.
    operator int
    returns the account number. This operator can not modify the account object.
    operator double
    returns the balance value. This operator can not modify the account object.

Unary member operator

    bool operator ~()
    This operator returns true is the account is new or not set (i.e. if the account number is zero), otherwise it will return false. This operator can not modify the account object.

Binary member operators

    Note: All the binary member operators will not take any action if the account is in an invalid state.

assignment operators

    overload the assignment operator so a NEW account can be set to an integer. Doing so should set the account number of the account to the integer value.
    If the integer value is an invalid account number, the object should be set to an invalid empty state instead.
    If the account is not new, then this operator should not perform any action.
    In any case, a reference of the current object (account) should be returned.

    Account A,B; 
     A = 55555;  // the account number of A will be set to 55555
     B = 555; // the account B will be set to invalid state
     B = 66666; // no action will be taken since the B is in not new
     A = 66666; // no action will be taken since the A is in not new

    overload the assignment operator so a NEW account can be set to another Account object. This action should move the balance and the account number from one account to another; therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the balance of the left account will be set to the balance of the right account and then the balance of the right account will be set to zero. The same will happen to the account number
    If the left Account operand is not new or the right account operand is not valid, no action should be taken.
    In any case, a reference of the current object (account) should be returned.

     Account A, B(66666, 400), Bad(555, -10);
     A = B;  // A will have the properties of B and B will become a NEW account
     B = Bad; // Nothing will happen since Bad is not new
     Bad = B; // Nothing will hapen since Bad is invalid

    overload the += operator to add a double value to an account. This should act like depositing money into an account. (i.e. the value of the double should be added to the balance)
    if the account is in an invalid state or the double value is negative, no action should be taken.
    In any case, a reference of the current object (account) should be returned.

    Account A(55555, 400.0), Bad(555, -10);
     A += 200.0;  // A will have a balance of 600 
     Bad += 300.0; // Nothing will happen since Bad is invalid
     A += -20.0; // Nothing will happen since double value is negative

    overload the -= operator to reduce an account balance by a double value . This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)
    if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.
    In any case, a reference of the current object (account) should be returned.

    Account A(55555, 400.0), Bad(555, -10);
     A -= 150.0;  // A will have a balance of 250 
     A -= 300.0; // Nothing will happen since there not enough money in A
     A -= -20.0; // Nothing will happen since double value is negative
     Bad -= 20.0 // Nothing will happen since Bad is invalid

    overload the << operator** (left shift operator) to move funds from the right account to the left. After this operation, the balance of the left account will be the sum of both and the balance of the right account will be zero.
    Funds of an account should not be able to be moved to itself. This operation does not affect the account.
    In any case, a reference of the **current object (account) should be returned.

    Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
     A << B;  // A will have a balance of 900.0, B will have a balance of zero
     A << A; // Nothing will happen 
     A << Bad; // Nothing will happen
     Bad << A; // Nothing will happen

    overload the >> operator (right shift operator) to move funds from the left account to the right. After this operation, the balance of the right account will be the sum of both and the balance of the left account will be zero.
    Funds of an account should not be able to be moved to itself. This operation does not affect the account.
    In any case, a reference of the current object (account) should be returned.

    Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
     A >> B;  // B will have a balance of 900.0, A will have a balance of zero
     B >> B; // Nothing will happen 
     B >> Bad; // Nothing will happen
     Bad >> B; // Nothing will happen

Binary helper operators

-- create a binary stand alone helper + operator that accepts a constant account reference at left and another constant account reference at right and returns a double value.
The double value should be the sum of the balances of the two accounts.
If any of the two accounts is invalid, then zero is returned.

   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Bad; // sum should be 0 since Bad is invalid
   sum = Bad + B; // sum should be 0 since Bad is invalid

-- create a binary stand alone helper += operator that accepts a double reference at left and a constant account reference at right and returns a double value.
The value of the balance of the right operand (account reference) should be added to the left operand (double reference)
Then the value of the double reference is returned.

   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0

The tester program.

The tester program tests all the operator overloads and the output should be as follows:

Using bool conversion overload and operator ~ to print the accounts:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       111.11 |
|002| 22222 |       222.22 |
|003|  BAD  |    ACCOUNT   |
|004| 44444 |      4444.44 |
|005| 55555 |       555.55 |
|006|  BAD  |    ACCOUNT   |
|007| 77777 |       777.77 |
|008|  NEW  |         0.00 |
|009|  NEW  |         0.00 |
|010|  NEW  |         0.00 |
+---+-------+--------------+
Depositing $50.02 into account #1 using += operator:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       161.13 |
+---+-------+--------------+
Withdrawing $100.01 from account #2 using -= operator:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 22222 |       122.21 |
+---+-------+--------------+
Attempting to withdraw too much from account #4 using -= operator:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 44444 |      4444.44 |
+---+-------+--------------+
Attempting to deposit and withdraw negative amounts on account #4:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 44444 |      4444.44 |
+---+-------+--------------+
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 44444 |      4444.44 |
+---+-------+--------------+
Having these two accounts:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       161.13 |
|002| 22222 |       122.21 |
+---+-------+--------------+
Moving funds from first account to second:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |         0.00 |
|002| 22222 |       283.34 |
+---+-------+--------------+
Moving funds from second account to first:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       283.34 |
|002| 22222 |         0.00 |
+---+-------+--------------+
Attempting to move funds from an account to itself
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       283.34 |
+---+-------+--------------+
Sum of the balance of accounts 5 and 7
   in three different ways: 1333.32, 1333.32, and 1333.32
Setting the account number of account#8 to 88888:
before:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001|  NEW  |         0.00 |
+---+-------+--------------+
After:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 88888 |         0.00 |
+---+-------+--------------+
Moving the Account from Account# 8 to Account #9 using operator=:
Before:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 88888 |         0.00 |
|002|  NEW  |         0.00 |
+---+-------+--------------+
After:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001|  NEW  |         0.00 |
|002| 88888 |         0.00 |
+---+-------+--------------+
Displaying all accounts:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 11111 |       283.34 |
|002| 22222 |         0.00 |
|003|  BAD  |    ACCOUNT   |
|004| 44444 |      4444.44 |
|005| 55555 |       555.55 |
|006|  BAD  |    ACCOUNT   |
|007| 77777 |       777.77 |
|008|  NEW  |         0.00 |
|009| 88888 |         0.00 |
|010|  NEW  |         0.00 |
+---+-------+--------------+
Attempting to change the account number of the valid account#7:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 77777 |       777.77 |
+---+-------+--------------+
Attempting to set accounts that are not new: (7 and 6)
This attempt should not affect either account
Before:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001|  BAD  |    ACCOUNT   |
|002| 77777 |       777.77 |
+---+-------+--------------+
After:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001|  BAD  |    ACCOUNT   |
|002| 77777 |       777.77 |
+---+-------+--------------+
Setting a new account (#8) to a valid account(#7)
Before:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001| 77777 |       777.77 |
|002|  NEW  |         0.00 |
+---+-------+--------------+
After:
+---+-------+--------------+
|ROW| ACC#  |    BALANCE   |
+---+-------+--------------+
|001|  NEW  |         0.00 |
|002| 77777 |       777.77 |
+---+-------+--------------+
Display raw account numbers of all the accounts
 using int conversion operator
11111 22222 -1 44444 55555 -1 0 77777 88888 0
Display raw balances of the accounts:
 using double conversion operator
283.34 0.00 0.00 4444.44 555.55 0.00 0.00 777.77 0.00 0.00
Total of 2 new accounts
Total of 2 invalid accounts

LAB Submission (part 1)

Files to submit:

Account.cpp
Account.h
accountMain.cpp

Upload your source code and data file to your matrix account. Compile and run your code using the g++ compiler as shown above and make sure that everything works properly.

Then, run the following command from your account

    replace profname.proflastname with your professor’s Seneca user-id
    replace # with the workshop number
    replace ?? with your subject code (200 or 244)

    ~profname.proflastname/submit 2??/w#/p1

and follow the instructions.

    ⚠️Important: Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

DIY (50%)

    Please note that you can (and probably should) add more member functions to make the DIY part work.

Files to submit:

Mark.cpp
Mark.h
markMain.cpp

Create a Module for a Mark to encapsulate a mark between 0 and 100.
Mark 	Grade 	Scale 4 mark
0 < = Mark < 50 	F 	0.0
50 < = Mark < 60 	D 	1.0
60 < = Mark < 70 	C 	2.0
70 < = Mark < 80 	B 	3.0
80 < = Mark < = 100 	A 	4.0

The class name must be Mark.

    :warning:Important: No values are allowed to be kept in mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This condition will not be repeated in during the workshop and applies to all the functions and operators of class Mark

Construction

Mark can be created using an integer value (one argument constructor)that sets the value of the mark. If this value is not provided (no-argument constructor), the value of the mark will be zero.

   Mark m, n(25), k(200), p(-10);
   // value of m is 0
   // value of n is 25
   // k is invalid
   // p is invalid

Operator and conversion overloads

    Mark can be casted to an integer (int type). The result would be the value of the mark or zero if the mark is in an invalid state.

    Mark m, n(25), k(200), p(-10);
     cout << int(m) << endl;
     cout << int(n) << endl;
     cout << int(k) << endl;
     cout << int(p) << endl;

Ouptut:

0
25
0
0

    An integer can be added to the value of the mark using += operator; if the mark is invalid, the action is omitted. Reference of the mark is returned after the operation.

    Mark m, n(25), k(200);
    cout << int(m += 20) << endl;
    cout << int(n += 20) << endl;
    cout << int(k += 20) << endl;
    cout << int(n += 60) << endl;

Output:

20
45
0
0

    Mark can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment. Reference of the mark is returned after the operation.

    Mark m, n(25), k(200);
    cout << int(m = 80) << endl;
    cout << int(n = 120) << endl;
    cout << int(k = 70) << endl;

Output:

80
0
70

    Mark can be casted to a double, the result would be the GPA equivalent of the integer value. See the table of mark values above. Casting an invalid mark will result in a zero value.

     Mark m(50), n(80), k(120);
     cout << double(m) << endl;
     cout << double(n) << endl;
     cout << double(k) << endl;

Output:

1
4
0

    Mark can be casted to a character (char type), the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result in an 'X' value.

     Mark m(50), n(80), k(120);
     cout << char(m) << endl;
     cout << char(n) << endl;
     cout << char(k) << endl;

Output:

D
A
X

    Mark can be added to an integer, returning the integer after the operation. Invalid marks will not add any value to the integer.

     Mark n(80), k(120);
     cout << (val += n) << endl;
     cout << (val += k) << endl;

Output:

140
140

##Tester program:

// Workshop 5:
// Version: 1.0
// Date: 10/18/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Mark.h"
using namespace std;
using namespace sdds;
int main() {
   Mark m, n(25), k(200), p(-10);
   cout << "int ............" << endl;
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl;
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120;
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl;
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl;
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   return 0;
}

Here is the execution sample for the tester program

int ............
0
25
0
0
+= .............
20
45
0
0
= ..............
80
0
70
double .........
1
4
0
char ...........
D
A
X
int += Mark ...
140
140

    Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.

Create a file named reflect.txt that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.
DIY Submission (part 2)

Files to submit:

Mark.h
Mark.cpp
markMain.cpp

Upload your source code to your matrix account. Compile and run your code using the g++ compiler as shown above and make sure that everything works properly.

Then, run the following command from your account

    replace profname.proflastname with your professor’s Seneca user-id
    replace # with the workshop number
    replace ?? with your subject code (200 or 244)

    ~profname.proflastname/submit 2??/w#/p2

    and follow the instructions.

    :warning:Important: Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
