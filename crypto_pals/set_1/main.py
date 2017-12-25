from sys import argv
from sys import stdin
from BaseConverter import BaseConverter
from XOROperations import XOROperations

def read_input():
    try:
        inf = ''
        if not stdin.isatty():
            inf = stdin.read().rstrip('\n')
        else:
            print('input is empty')
    except:
        print('failed to parse input')
    return inf
#END read_input()

def main():
    C = BaseConverter()
    X = XOROperations()

    #TODO add command logic to choose which crypto pals challenge to solve based on user input

    #If just one argument then read input from stdin
    if (len(argv) == 1):
        inp = read_input()
        ''' Exercise 1 Convert Hex to Base64 '''
        print ('Set1 Exercise1 Convert Hex to Base64')
        print (C.base16_to_base64(inp))
    else: #assume multiple inputs, treat them each as separate files
        args = {}
        ''' Exercise 2 XOR two arbitrary (but same sized) base16 encoded strings together '''
        print('Set1 Exercise2 Fixed XOR')
        print('Write a function that takes two equal-length buffers and produces their XOR combinations')
        print('Multiple arguments provided reading each argument as input file')
        for i in range(1,len(argv)):
            try:
                args[i] = open(argv[i], 'r').read()
            except:
                print('failed to parse one or more input files')

        if (len(argv) == 3 and 1 in args and 2 in args):
            b1 = C.base16_to_base2(args[1])
            b2 = C.base16_to_base2(args[2])
            
            o1 = X.XORBytes(b1, b2)

            print('B1' + str(b1) + ' B2' + str(b2))
            print('O1' + str(o1))
            print('Base64 Output ' + C.base2_to_base16(o1))
        else:
            print('Dictionary does not contain keys \'1\' and \'2\'')


if __name__ == '__main__':
    main()
