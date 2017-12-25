#include <cstring>
#include <iostream> //cin, cout
#include <stdint.h> //uintxx_t types, size_t
#include <unordered_map> //std::unordered_map, effectively a hash table

static const uint_fast32_t BFR_SIZE = 512000;

using namespace std;

class StringUtil
{
    private:
    bool valid_;
    size_t size_;
    const uint8_t* str_;
    unordered_map<uint_fast32_t, bool> map_;
    
    uint_fast32_t getWeight(const string &str) const
    {
        uint_fast32_t weight = 0;

        for (auto c: str)
        {
            //only lower case ascii count as valid input
            if (c < 0x61 || c > 0x7a) 
            {
                weight = -1;
                break;
            }
            else
            {
                weight += (c - 0x60);
            }
        }

        return weight;
    }
    
    bool hashUniformSubStrings()
    {
        size_t end = 0;
        size_t start = 0;
        uint_fast8_t curr = 0;
        uint_fast8_t prev = 0;

        while (start < size_) //move start until we get to the end of the string
        {
            end = start;
            curr = str_[start];

            //advance end while we are in a contiguous string
            while (end < size_)
            {
                if (prev == 0 || curr == prev)
                {
                    curr = str_[end];
                    prev = str_[++end];
                }
                else
                {
                    break;
                }

                if (end-start > 0)
                {
                    int64_t weight = 0;
                    for (size_t i=start; i<(start+(end-start)); ++i)
                    {
                        uint8_t ch = str_[i];
                        //only lower case ascii count as valid input
                        if (ch >= 0x61 && ch <= 0x7a) 
                        {
                            weight += (ch - 0x60);
                        }
                        else
                        {
                            weight = -1;
                            break;
                        }
                    }

                    if (weight > 0 && map_.find(weight) == map_.end())
                    {
                        map_[weight] = true;
                    }
                    else if (weight < 0)
                    {
                        cerr << "Error calculating weight" << endl;
                    }
                }
            }

            start++;
        }
       
        return map_.size() > 0;
    }
    
    public:
    StringUtil(const uint8_t* str) : str_(str) 
    {
        size_ = strlen((char*)str_);
        valid_ = hashUniformSubStrings();   
    }

    ~StringUtil()
    {
        if (str_ != nullptr) { delete[] str_; }
    }

    bool queryByWeight(const uint_fast32_t weight) const
    {
        return (map_.find(weight) != map_.end());
    }

    size_t size() { return size_; }
};

int main(void)
{
    int status = 0;
    size_t query_count = -1;
    uint8_t* str = new uint8_t[BFR_SIZE]();

    //read input
    int read = scanf("%s", (char*)str);
    cin >> query_count;
    StringUtil SU(str);

    if (read > 0 && query_count > 0)
    {
        for (size_t s=0; s<query_count; ++s)
        {
            int_fast32_t weight = -1;
            if (!cin.bad())
            {
                cin >> weight;
                if (weight > 0 && SU.queryByWeight(weight))
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }

                cout <<endl;
            }
            else
            {
                status = -1;
            }
        }
    }

    return status;
}
