#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ASCII_RANGE 256
#define _GNU_SRC

//Converts any upper case letters to lower case letter anything else will pass through
static inline uint8_t toLower(uint8_t ch)
{
    uint8_t C = 0;

    switch (ch)
    {
        case 'A':
            C = 'a';
        break;
        case 'B':
            C = 'b';
        break;
        case 'C':
            C = 'c';
        break;
        case 'D':
            C = 'd';
        break;
        case 'E':
            C = 'e';
        break;
        case 'F':
            C = 'f';
        break;
        case 'G':
            C = 'g';
        break;
        case 'H':
            C = 'h';
        break;
        case 'I':
            C = 'i';
        break;
        case 'J':
            C = 'j';
        break;
        case 'K':
            C = 'k';
        break;
        case 'L':
            C = 'l';
        break;
        case 'M':
            C = 'm';
        break;
        case 'N':
            C = 'n';
        break;
        case 'O':
            C = 'o';
        break;
        case 'P':
            C = 'p';
        break;
        case 'Q':
            C = 'q';
        break;
        case 'R':
            C = 'r';
        break;
        case 'S':
            C = 's';
        break;
        case 'T':
            C = 't';
        break;
        case 'U':
            C = 'u';
        break;
        case 'V':
            C = 'v';
        break;
        case 'W':
            C = 'w';
        break;
        case 'X':
            C = 'x';
        break;
        case 'Y':
            C = 'y';
        break;
        case 'Z':
            C = 'z';
        break;
        default:
            C = ch;
        break;
    }

    return C;
}

static inline void convertToLower(uint8_t* c_str)
{
    for (size_t s=0; c_str[s]!='\0'; ++s)
    {
        c_str[s] = toLower(c_str[s]);
    }
}

//Hashes the count of the input as its ascii value in an array of ints
//We can only get an accurate count of all letters if they are all in one case i.e. all lower case
static inline void hashInput(uint32_t* hash, uint8_t* input, size_t size)
{
    for (size_t s=0; s<size; ++s)
    {
        uint8_t index = input[s];
        hash[index] ++;
    } 
}

static inline bool isPangram(uint32_t* hash)
{
    bool Pangram = true;

    //Iterate through the lower case english alphabet subset of the ascii range
    for (uint8_t c='a'; c<='z'; ++c)
    {
        if (hash[c] == 0)
        {
            Pangram = false;
            break;
        }
    }

    //if they all have at least one occurance hashed then the hashed string is a pangram
    return Pangram;
}

int main(int arc, char** argv)
{
    uint8_t* inp = NULL;
    uint32_t count_hash[ASCII_RANGE] = { 0 };
    size_t size = 0; 
    
    if (getline(&inp, &size, stdin) != 0)
    {
        convertToLower(inp);
        hashInput(count_hash, inp, size);
        if (isPangram(count_hash))
        {
            printf("pangram\n");   
        }
        else
        {
            printf("not pangram\n");
        } 
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}
