from __future__ import print_function
from aes_cbc_cipher import AES_CBC_Cipher
import argparse
import base64


def analyze(token):
    print('Original token:' + token)
    CT = base64.b64decode(token)
    IV = []
    MSG = []

    #print the base 16 breakdown of the CT
    print('Cipher text: [ ', end='')
    for i in range(0, len(CT)):
        if (i < 16):
            IV.append(CT[i])
        else:
            MSG.append(CT[i])
        print('0x' + base64.b16encode(CT[i]) + ' ', end='')    
    print(']')

    print('IV:' + str(IV))
    print('MSG:' + str(MSG))

def read_input(in_file):
    data = ''
    try:
        f = open(in_file, 'rb')
        data = str.rstrip(f.read())
    except:
        print('Unable to read file "' + in_file + '"')

    return data

def main():
    parser = argparse.ArgumentParser(description='Enter a token to analyze')
    parser.add_argument('token_path', type=str, help='the path to a valid token to analyze')
    args = parser.parse_args()

    data = read_input(args.token_path)
    if (data != '' and len(data) == 44):
        analyze(data)
    else:
        print('file doesn\'t appear to be a valid token')

if __name__ == '__main__':
    main()
