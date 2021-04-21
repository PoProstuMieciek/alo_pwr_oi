// !!!!!!!!!!!!!
// !!! BRUTE !!!
// !!! BRUTE !!!
// !!! BRUTE !!!
// !!!!!!!!!!!!!

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string word;
    int queries;

    cin >> word >> queries;

    for (int i = 0; i < queries; i++)
    {
        int fs, fe, ss, se;
        cin >> fs >> fe >> ss >> se;
        fs--; fe--; ss--; se--;

        string first =  string(word.begin() + fs, word.begin() + fe + 1);
        string second = string(word.begin() + ss, word.begin() + se + 1);

        // printf("first =  %s\nsecond = %s\n\n", first.c_str(), second.c_str());

        if (first == second)
        {
            printf("ROWNY\n");
            continue;
        }

        auto cmp = lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
        if(cmp) printf("MNIEJSZY\n");
        else printf("WIEKSZY\n");
    }
}