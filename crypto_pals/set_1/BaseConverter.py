''' By Ryan Morris
    Written to solve the crypto pals challenges
'''

class BaseConverter:

    def __init__(self):
        __doc__ = 'A class written to do base conversions for the Crypto Pals excercises'
    #END __init__


    def base64_alpha_lookup(self, b64_letter):
        #base64 letters are 64 bits long this lookup assumes they in a left padded Big endian byte
        b64_char = '='

        #left 2 bits are discarded
        b64_letter = (b64_letter[0] & 0x3f)

        if b64_letter == 0:
            b64_char = 'A'
        elif b64_letter == 1:
            b64_char = 'B'
        elif b64_letter == 2:
            b64_char = 'C'
        elif b64_letter == 3:
            b64_char = 'D'
        elif b64_letter == 4:
            b64_char = 'E'
        elif b64_letter == 5:
            b64_char = 'F'
        elif b64_letter == 6:
            b64_char = 'G'
        elif b64_letter == 7:
            b64_char = 'H'
        elif b64_letter == 8:
            b64_char = 'I'
        elif b64_letter == 9:
            b64_char = 'J'
        elif b64_letter == 10:
            b64_char = 'K'
        elif b64_letter == 11:
            b64_char = 'L'
        elif b64_letter == 12:
            b64_char = 'M'
        elif b64_letter == 13:
            b64_char = 'N'
        elif b64_letter == 14:
            b64_char = 'O'
        elif b64_letter == 15:
            b64_char = 'P'
        elif b64_letter == 16:
            b64_char = 'Q'
        elif b64_letter == 17:
            b64_char = 'R'
        elif b64_letter == 18:
            b64_char = 'S'
        elif b64_letter == 19:
            b64_char = 'T'
        elif b64_letter == 20:
            b64_char = 'U'
        elif b64_letter == 21:
            b64_char = 'V'
        elif b64_letter == 22:
            b64_char = 'W'
        elif b64_letter == 23:
            b64_char = 'X'
        elif b64_letter == 24:
            b64_char = 'Y'
        elif b64_letter == 25:
            b64_char = 'Z'
        elif b64_letter == 26:
            b64_char = 'a'
        elif b64_letter == 27:
            b64_char = 'b'
        elif b64_letter == 28:
            b64_char = 'c'
        elif b64_letter == 29:
            b64_char = 'd'
        elif b64_letter == 30:
            b64_char = 'e'
        elif b64_letter == 31:
            b64_char = 'f'
        elif b64_letter == 32:
            b64_char = 'g'
        elif b64_letter == 33:
            b64_char = 'h'
        elif b64_letter == 34:
            b64_char = 'i'
        elif b64_letter == 35:
            b64_char = 'j'
        elif b64_letter == 36:
            b64_char = 'k'
        elif b64_letter == 37:
            b64_char = 'l'
        elif b64_letter == 38:
            b64_char = 'm'
        elif b64_letter == 39:
            b64_char = 'n'
        elif b64_letter == 40:
            b64_char = 'o'
        elif b64_letter == 41:
            b64_char = 'p'
        elif b64_letter == 42:
            b64_char = 'q'
        elif b64_letter == 43:
            b64_char = 'r'
        elif b64_letter == 44:
            b64_char = 's'
        elif b64_letter == 45:
            b64_char = 't'
        elif b64_letter == 46:
            b64_char = 'u'
        elif b64_letter == 47:
            b64_char = 'v'
        elif b64_letter == 48:
            b64_char = 'w'
        elif b64_letter == 49:
            b64_char = 'x'
        elif b64_letter == 50:
            b64_char = 'y'
        elif b64_letter == 51:
            b64_char = 'z'
        elif b64_letter == 52:
            b64_char = '0'
        elif b64_letter == 53:
            b64_char = '1'
        elif b64_letter == 54:
            b64_char = '2'
        elif b64_letter == 55:
            b64_char = '3'
        elif b64_letter == 56:
            b64_char = '4'
        elif b64_letter == 57:
            b64_char = '5'
        elif b64_letter == 58:
            b64_char = '6'
        elif b64_letter == 59:
            b64_char = '7'
        elif b64_letter == 60:
            b64_char = '8'
        elif b64_letter == 61:
            b64_char = '9'
        elif b64_letter == 62:
            b64_char = '+'
        elif b64_letter == 63:
            b64_char = '/'
        else: #anything else is treated as padding
            b64_char = '='

        return b64_char
    # END base64_alpha_lookup()

    def base64_word_encode(self, base64Word):

        base64Encoding = ''
        #print ('base64WordLookup ' + str(base64Word))
        #pad any part of the word that isn't filled
        if (len(base64Word) == 1):
            base64Word += bytes([0xff]) + bytes([0xff])
        elif (len(base64Word) == 2):
            base64Word += bytes([0xff])
        #else: no padding necessary for 3 byte input
        ''' anything else is assumed to be 3 bit input if its longer then that anything past 3 bytes gets 
    ignored'''

        b1 = bytes([ (base64Word[0] & 0xfc) >> 2 ])
        b2 = bytes([ ((base64Word[0] & 0x3) << 4) + ((base64Word[1] & 0xf0) >> 4) ])
        b3 = bytes([ ((base64Word[1] & 0xf) << 2) + ((base64Word[2] & 0xc0) >> 6) ])
        b4 = bytes([ (base64Word[2] & 0x3f)])

        base64Encoding = (self.base64_alpha_lookup(b1) + self.base64_alpha_lookup(b2) +
                          self.base64_alpha_lookup(b3) + self.base64_alpha_lookup(b4))

        return base64Encoding
    #END base64_word_encode()

    def base2_to_base16(self, base2Str):
        return 'TODO implement me'

    def base2_to_base64(self, base2Str):
        base64Str = ""
        ind = 0
        strSize = len(base2Str)

        #print('Intermediate (Base10): ' + str(base2Str))
        ''' Converting from base2 to base64 occurs in 4 x 6bit characters at a time or
        one 24 bit block. 
        If the input is less the 24bits then the unfilled output will be padded'''

        while (ind < strSize):
            base64Word = ''
            if ((strSize - (ind)) >=3): #encode 3 bytes (24bits)
                base64Word = self.base64_word_encode(base2Str[ind:ind+3])
                ind += 3
            elif ((strSize - (ind)) == 2): #encode 2 bytes pad the 3rd
                base64Word = self.base64_word_encode(base2Str[ind:ind+2])
                ind += 2
            else: #encode 1 byte pad the remaining 2
                base64Word = self.base64_word_encode(base2Str[ind:ind+1])
                ind +=1

            base64Str += base64Word

        return base64Str
    #END base2_to_base64()

    def base16_to_base2_lookup(self, nibble):
        b2 = 0

        if nibble == '0':
            b2 = 0
        elif nibble == '1':
            b2 = 1
        elif nibble == '2':
            b2 = 2
        elif nibble == '3':
            b2 = 3
        elif nibble == '4':
            b2 = 4
        elif nibble == '5':
            b2 = 5
        elif nibble == '6':
            b2 = 6
        elif nibble == '7':
            b2 = 7
        elif nibble == '8':
            b2 = 8
        elif nibble == '9':
            b2 = 9
        elif nibble == 'A' or nibble == 'a':
            b2 = 10
        elif nibble == 'B' or nibble == 'b':
            b2 = 11
        elif nibble == 'C' or nibble == 'c':
            b2 = 12
        elif nibble == 'D' or nibble == 'd':
            b2 = 13
        elif nibble == 'E' or nibble == 'e':
            b2 = 14
        elif nibble == 'F' or nibble == 'f':
            b2 = 15

        return b2
    #base16_to_base2_lookup()

    def base16_to_base2_byte(self, hex_dec_pair):
        binDigit = 0

        if (len(hex_dec_pair) is 2):
            leftNibble = (self.base16_to_base2_lookup(hex_dec_pair[0]) << 4)
            rightNibble = (self.base16_to_base2_lookup(hex_dec_pair[1]))
            binDigit = (leftNibble | rightNibble)
        elif (len(hex_dec_pair) is 1):
            binDigit = self.base16_to_base2_lookup(hex_dec_pair)

        return (bytes([binDigit]))
    #END base16_to_base2_byte()

    def base16_to_base2(self, str):
        binaryStr = []
        ind = 0

        while (ind < (len(str) - 1)):
            subStr = ''
            #Single hex digit
            if (ind == (len(str) - 1)):
                subStr = str[ind]
                ind = ind + 1
            #Two hex digits
            else:
                subStr = str[ind:ind+2]
                ind = ind + 2

            self.base16_to_base2_byte(subStr)
            binaryStr += self.base16_to_base2_byte(subStr)

        return binaryStr
    #END base16_to_base2()

    def base16_to_base64(self, str):
        #print('Input (Base16): [' + str + ']')
        return self.base2_to_base64(self.base16_to_base2(str))
    #END base16_to_base64()
