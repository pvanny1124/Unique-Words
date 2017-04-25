
#include <iostream>
#include <set>
#include <string>

using namespace std;

unsigned long countChars(const string& s);      //Prototypes
unsigned long countWords(const string& s);
unsigned long countUniW(const string& s, set<string>& wl);

int main()
    {                            // variables

        unsigned long total = 0; // done
        unsigned long chars = 0; // done
        unsigned long uni_l = 0; // done
        unsigned long uni_w = 0;
        unsigned long words = 0; // done
        set<string> user_list;
        set<string> get_str;
        string input;

                                               // * ask input in form of a line from user
        while(getline(cin, input))
        {
            total++;                           // * total lines so far

            user_list.insert(input);           // * stores lines into set

            chars += countChars(input) + 1;    // * total chars so far : +1 for every new line

            words += countWords(input);        // * counts words so far

            countUniW(input, get_str);

        }
            uni_l = user_list.size();          // * gives unique lines from the set size
            uni_w = get_str.size();



            cout << total << '\t'
            << words << '\t'
            << chars << '\t'
            << uni_l << '\t'
            << uni_w << '\t' //STILL NEED THIS
            << endl;


return 0;
        }


unsigned long countChars(const string& s)

       {
            int num_of_chars = s.size();
            return num_of_chars;
       }

unsigned long countWords(const string& s)

    {
            int wc = 0;

            if (s[0] != ' ' && s[0] != '\t')
            {
                           wc++;

            }

            for(size_t i = 0; i < s.size(); i++)
            {
                if((s[i-1] == ' ' && (s[i] != ' ' && s[i] != '\t'))     // * This if statement makes sure that if
                || (s[i-1] == '\t' && (s[i] != ' ' && s[i] != '\t')))   // * a whitespace is followed by a character,
                   {                                                    // * then wc will increment.
                       wc++;


                   }
            }
                    return wc;
    }

unsigned long countUniW(const string& s, set<string>& wl )
{

    int boundStart = 0; // "SCAN A WORD"
    int boundEnd = 0;

    for(size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
        {
            boundEnd++;
            boundStart++;
            continue;

        }
            boundEnd++;



            if(s[i+1] == ' ' || s[i+1] == '\t' || s[i+1] == '\0')
            {
                string temp = "";
                int c = 0;
                for (int j = boundStart; j < boundEnd; j++)
                {

                    temp.insert(c, 1, s[j]);
                    c++;
                    boundStart = boundEnd;


                }
                    wl.insert(temp);
            }


    }

}
























