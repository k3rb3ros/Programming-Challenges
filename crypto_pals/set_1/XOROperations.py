''' By Ryan Morris
    Written to do XOR operations and detectoin for the Crypto Pals challenges
'''

class XOROperations:

    def __init__(self):
        __doc__ = 'A class written to do basic XOR operations on Python Byte types'

    ''' XOR any two given byte strings of the same size '''
    def XORBytes(self, byte_str_1, byte_str_2):

        #print('XORBytes()')

        if (len(byte_str_1) != len(byte_str_2)):
            exception.BufferError('XORBytes can only be performed on buffers of the same size')
        
        out_bytes = bytearray(len(byte_str_1))

        #print ('Input B1' + str(byte_str_1) + ' B2' + str(byte_str_2))

        for i in range(0,len(byte_str_1)):
            out_bytes[i] = byte_str_1[i] ^ byte_str_2[i]

        return out_bytes
