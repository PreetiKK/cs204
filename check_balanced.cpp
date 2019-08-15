#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;


string Chcek_Balance(string s)
{
    stack <char> sk;
    for(auto c:s){
        switch(c){
         case'(':
         case'{':
         case'[':
         case'<':
         case'|':

         sk.push(c);
         break;

         case'|':
            if(st.empty() || st.top()!='|')
        {
            return "NO";

        }
        sk.pop();
        break;

        case'|':
            if(st.empty() || st.top()!='|')
        {
            return "NO";

        }
        sk.pop();
        break;

         case'>':
            if(st.empty() || st.top()!='<')
        {
            return "NO";

        }
        st.pop();
        break;

         case']':
            if(st.empty() || sk.top()!='[')
        {
            return "NO";

        }
        sk.pop();
        break;

         case'}':
            if(st.empty() || sk.top()!='{')
        {
            return "NO";

        }
        sk.pop();
        break;

         case')':
            if(st.empty() || sk.top()!='(')
        {
            return "NO";

        }
        sk.pop();
        break;
        }
    }


}
int main()
{
   int t; //Number of test cases it will run
   cin>> t;
   for(int i=0 ; i<t ; i++){

    string s;
    cin >> s;
    cout << Check_Balance(s) << endl;

   }

    return 0;
}
