import sys

def read_into_dict(a, b):
    dict = {}

    for ch in a:
        #check if this character has been encountered in string a before
        if ch in dict:
            tup = dict[ch]
            if tup[0] == 'a':
                count = tup[1]
                count += 1
                tup = ('a', count)
                dict[ch] = tup
        #if not add it
        else:
            dict[ch] = ('a', 1)

    for ch in b:
        #check if this character has been encountered before
        if ch in dict:
            tup = dict[ch]
            #if it has and it was in string b then increment the count of it
            if tup[0] == 'b':
                count = tup[1]
                count += 1
                tup = ('b', count)
            elif len(tup) == 4 and tup[2] == 'b':
                count = tup[3]
                count += 1
                a = tup[0]
                c_a = tup[1]
                tup = (a, c_a, 'b', count)
            else:
            #otherwise it was in string a only so expand the tuple to indicate it is now in both strings
                tup = tup + ('b', 1)
        else:
            tup = ('b', 1)
        dict[ch] = tup

    return dict
            

def number_needed(a, b):
    delta = 0
    dict = read_into_dict(a, b)
    #print (dict)

    #iterate through the dictionary and count all characters not in both strings or characters that don't occur the same number of times
    for pair in dict:
        tup = dict[pair]
        #if the tuple is of length two then this char only occured in one string
        if len(tup) == 2:
            delta += tup[1]
        #otherwise character occured in both strings so we need to diff counts to get delta
        elif len(tup) == 4:
            delta += abs(tup[1] - tup[3])

    return delta

def main():
    a = sys.stdin.readline().strip('\n')
    b = sys.stdin.readline().strip('\n')
    print(number_needed(a, b))

if __name__ == '__main__':
    main()
