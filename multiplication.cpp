#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include<sstream>
using namespace std;

string str1 , str2;
// Multiplies string 1 and string 2, and prints result.
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    // keeping  result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // two indexes, used to find positions in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in number 1

     for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in number 2
        i_n2 = 0;

        // Go from right to left in number 2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number and add result to previously stored result at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Storing result
            result[i_n1 + i_n2] = sum % 10;

              i_n2++;
        }

        // storing carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in number 1.
        i_n1++;
    }

    // ignore zero's from right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were zero's - means either both or
    // one of number 1 or number 2 were zero
    if (i == -1)
    return "0";

    // generating the result string
    string s = "";

    while (i >= 0){
        s += std::string to_string(result[ i--]);
    }
    return s;
}

int main()
{
    cin >> str1 >> str2 ;


    if((str1.at(0) == '-' || str2.at(0) == '-') &&
        (str1.at(0) != '-' || str2.at(0) != '-' ))
        cout<<"-";


    if(str1.at(0) == '-' && str2.at(0)!='-')
        {
            str1 = str1.substr(1);
        }
        else if(str1.at(0) != '-' && str2.at(0) == '-')
        {
            str2 = str2.substr(1);
        }
        else if(str1.at(0) == '-' && str2.at(0) == '-')
        {
            str1 = str1.substr(1);
            str2 = str2.substr(1);
        }
    cout << multiply(str1, str2)<< endl;
    return 0;
}
