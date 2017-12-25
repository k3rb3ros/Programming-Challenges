/*
 * Written by Ryan Morris to answer pre-interview screening technical challenge for istream planet
 *
 * Problem: Given a string that represents a block of text, write a function that will identify
 * the most commonly-used word or words in the string.
 *
 * Notes:
 *
 * The format for output in the case of multiple words being the most commoon word was not 
 * explicitly specified so I had to guess on how output should be formatted.
 *
 * Assumptions:
 *
 * Input is ascii or extended ascii (not unicode)
 *
 * The input string will not contain eol characters (\n or \r\n) in the middle of a sentence
 *
 * The input string will not contain null characters (\0) in the middle of a sentence
 *
 * Words in the string are space delimited and ' ' is the only kind of whitespace used to
 * delimit words
 *
 */

#include <iostream> //cin, cout
#include <unordered_map> //std::unordered_map, effectively a hash table
#include <memory> //unique_ptr
#include <stdint.h> //uintxx_t types, size_t
#include <string> //std::string
#include <vector> //std::vector

using namespace std;

class wordCounter
{
    private:
    /****************
     * private data *
     ***************/
    unordered_map<string, unsigned int> word_count_;
    string sentence_;

    /*******************
     * private methods *
     ******************/
    bool split(vector<string> &splits, const uint8_t delim = '\n') const
    {
        //store string size to reduce function call overhead of referencing it multiple times
        const size_t sent_len = sentence_.size();
        size_t start = 0;
        size_t offset = 0;

        if (sent_len > 0)
        {
            while (offset < sent_len)
            {
                //move the start index until it is not pointing at an instance of delim
                while (sentence_[start] == delim && start < (sent_len)) { offset = ++start; }
                //move offset until we encounter delim or the end of the string
                while (sentence_[offset] != delim && offset < (sent_len)) { offset++; }
                
                //we found an instance of delim so split on it
                splits.push_back(sentence_.substr(start, (offset-start)));
                start = offset++;
            }
        }

        return splits.size() > 0;
    }
   
    //convert all alphabatical characters to lower case and strip any punctuation characters
    string lowerAndStrip(const string &str)
    {
        const size_t str_size = str.size();
        //buffer to hold the new string while we are modifying it
        //this assumes chars are byte size
        unique_ptr<uint8_t[]> new_str(new uint8_t[str_size+1]());

        for (size_t s=0, i=0; s<str_size; ++s)
        {
            uint8_t ch = str[s];

            //make any alphabetical characters lower case
            if (ch >= 0x41 && ch <= 0x5a) { ch += 32; }

            //strip out punctuation characters not including ' as apostrophies are valid english
            if (ch != '.' && ch != ',' && ch != '"' && ch != ':' &&
                ch != ';' && ch != '!' && ch != '?')
            {
                new_str[i] = ch;
                i++;
            }
            //else ignore the punctuation character
        }

        //construct a std::string from the C string in our buffer
        return string((char*)new_str.get());
    }

    public:
    /***************
     * constructor *
     **************/
    wordCounter(string sentence): sentence_(sentence) { /*nop*/ }

    /******************
     * public methods *
     *****************/
    bool get_most_common_words(vector<string> &mc_words)
    {
        bool success = false;
        size_t max_word_count = 0;
        vector<string> words;

        if (this->split(words, ' ') == true)
        {
            for (auto w: words)
            {
                string cmp_word = this->lowerAndStrip(w);

                //increment the word count if the word is already in the hash map
                if (word_count_.find(cmp_word) != word_count_.end())
                {
                    word_count_[cmp_word] ++;
                }
                else //add a new word to the hash map
                {
                    word_count_[cmp_word] = 1;
                }

                //keep track of the maximum time any given word(s) occur
                if (word_count_[cmp_word] > max_word_count)
                { max_word_count = word_count_[cmp_word]; }
            }

            //put all words that occur the maximum number of times in the output vector
            for (auto &w: word_count_)
            {
                if (w.second == max_word_count) { mc_words.push_back(w.first); }
            }

            //we consider success finding 1 or more words in the sentence that occur at least 1 time
            if (mc_words.size() > 0) { success = true; }
        }

        return success;
    }
};

int main(void)
{
    int status = 0;
    string sentence;
    vector<string> mcws;

    getline(cin, sentence);
    wordCounter WC(sentence);

    if (WC.get_most_common_words(mcws))
    {
        //unsure how you want output formatted
        //cout << "The most common word(s) in the sentence \"" << sentence << "\" are:" << endl;
        //cout << "{ ";
        for (size_t s=0; s<mcws.size(); ++s)
        {
            cout << mcws[s];
            if (s < mcws.size()-1) { cout << ", "; }
        }
        //cout << " }" << endl;
    }
    else
    {
        cout << "Unable to parse sentence for words" << endl;
        status = -1;
    }

    return status;
}
