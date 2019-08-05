#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Returns true if string 1 is smaller than string 2.
string str1 , str2;
bool isSmaller(string str1, string str2)
{
    // Calculating lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

         return false;
}

// Function for finding difference of larger numbers
string difference(string str1, string str2)
{
    //  making sure string 1
    // is not smaller than string 2
    if (isSmaller(str1, str2))
        swap(str1, str2);

    //an empty string for storing result
    string str ;

    // Calculating length of both the string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
     int carry = 0;

    // Run the loop till small string length
    // and subtract digit of string 1 to string 2
    for (int i=0; i<n2; i++)
    {
        // computing difference of current digits


        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtracting remaining digits of larger number i.e, String 1
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);

        // if the sub value is negative , then we make it positive
         if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reversing resultant string
    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    cin >> str1>> str2;
    cout << difference(str1 , str2)<< endl;
    return 0;
}
