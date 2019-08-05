#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string str1 , str2;
string addition(string str1 , string str2){

    //let the length of string 2 be greater
    if(str1.length()> str2.length()){
        swap(str1 , str2);
    }
        //empty string for storing result
        string str ;
        //calculating the length of both the string
        int n1= str1.length();
        int n2 = str2.length();
        //reverse both the strings
         reverse(str1.begin(), str1.end());
         reverse(str2.begin(), str2.end());

          int carry = 0;
    for (int i=0; i<n1; i++)
    {
        //adding numbers one by one from n1 and n2 and then adding resulting
        // carry to the next pair of the numbers from n1 and n2
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

         // Calculate carry for next step
        carry = sum/10;
}

          // Adding remaining digits of larger number i.e, string 2
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

       // Add remaining carry
    if (carry)
      {str.push_back(carry+'0'); }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
int main()

{
      cin >> str1>> str2;

      cout << addition(str1, str2)<< endl;
    return 0;
}
