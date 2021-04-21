#include <iostream>
using namespace std;

enum Answer
{
    SMALLER = -1,
    EQUAL = 0,
    LARGER = 1
};

class Select
{
    public:
        int start;
        int end;
        int length;

        void setRange(int s, int e)
        {
            start = s;
            end = e;
            setLength();
        }

        void setRange(Select sel)
        {
            start = sel.start;
            end = sel.end;
            setLength();
        }

        void setLength()
        {
            length = end - start + 1;
        }

        void fixIndexing()
        {
            start--; end--;
            setLength();
        }
};

const int BASE = 29;
const int MOD = 1e9 + 7;
const int MAX_LEN = 1e6 + 2;

long long base_powers[MAX_LEN];
long long hash_table[MAX_LEN];

string word;
Select first, second;

void build_base_powers()
{
    base_powers[0] = 1;
    base_powers[1] = BASE;

    size_t length = sizeof(base_powers) / sizeof(long long);
    for (size_t i = 2; i < length; i++)
    {
        base_powers[i] = (base_powers[i-1] * BASE) % MOD;
    }
}

void build_hash_table()
{
    hash_table[0] = word[0] - 'a' + 1;
    for (size_t i = 1; i < word.size(); i++)
    {
        char c = word[i] - 'a' + 1;

        hash_table[i] = ( hash_table[i-1] + (c * base_powers[i]) ) % MOD;
    }
}

bool hash_is_equal(Select& f, Select& s)
{
    // different sizes => substrings not equal
    if (f.length != s.length) return false;
    
    long long hash_f = hash_table[f.end] - hash_table[f.start - 1];
    long long hash_s = hash_table[s.end] - hash_table[s.start - 1];
    if (hash_f < 0) hash_f += MOD;
    if (hash_s < 0) hash_s += MOD;

    int power_index = s.start - f.start;
    long long multiply_by = base_powers[power_index];
    hash_f = (hash_f * multiply_by) % MOD;

    // if hashes equal => substrings equal
    return hash_f == hash_s;
}

pair<int, int> bin_search_different_index()
{
    Select left_f, left_s;
    int left = 0;
    int right = first.length - 1;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;

        left_f.setRange(first.start + left, first.start + middle);
        left_s.setRange(second.start + left, second.start + middle);

        if (left_f.end < left_f.start || left_s.end < left_s.start)
        {
            left_f.setRange(left_f.start, left_f.start);
            left_s.setRange(left_s.start, left_s.start);
        }

        if(hash_is_equal(left_f, left_s))
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return make_pair(first.start + left, second.start + left);
}

Answer query()
{
    // if they are equal => instant answer
    if(hash_is_equal(first, second)) return Answer::EQUAL;

    auto index = bin_search_different_index();
    char f = word[index.first];
    char s = word[index.second];

    if (f > s) return Answer::LARGER;
    else       return Answer::SMALLER;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries;
    cin >> word;
    cin >> queries;

    build_base_powers();
    build_hash_table();

    string output;
    int invert, answer;
    
    for (int i = 0; i < queries; i++)
    {
        cin >> first.start >> first.end >> second.start >> second.end;
        first.fixIndexing(); second.fixIndexing();

        invert = 1;
        if (first.start > second.start)
        {
            swap(first, second);
            invert = -1;
        }

        bool first_trim = false, second_trim = false;
        if (first.length != second.length)
        {
            if(first.length > second.length)
            {
                first.end -= (first.length - second.length);
                first.setLength();
                first_trim = true;
            }
            else
            {
                second.end -= (second.length - first.length);
                second.setLength();
                second_trim = true;
            }
        }

        answer = query();
        if (answer == Answer::EQUAL)
        {
            if (first_trim)  answer = Answer::LARGER; // if first one was longer
            if (second_trim) answer = Answer::SMALLER;  // if second one was longer
        }
        answer *= invert;
        
        switch (answer)
        {
            case Answer::SMALLER:
                output = "MNIEJSZY";
            break;

            case Answer::EQUAL:
                output = "ROWNY";
            break;

            case Answer::LARGER:
                output = "WIEKSZY";
            break;
        }

        cout << output << "\n";
    }
}