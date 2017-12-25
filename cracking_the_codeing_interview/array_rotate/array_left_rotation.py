## Sample Input
# the first line contains two space-separated integrs denoting the respective values of 
# n the number of integers in the array
# and d the number of rotations to perform
## 5 4
## 1 2 3 4 5

## Expected output for a left rotation of 4
# 5 1 2 3 4

from enum import Enum
import sys

class ArrayRotator:

    def __init__(self):
        self.data = []
        self.size = 0

    def populate(self, size, input):

        data = input.split(' ')

        for i in range(0, int(size)):
            self.data.append(int(data[i]))
        
        self.size = int(size)

    def rotate(self, start, len, rotations):
        if (rotations%len > 0):
            start2 = start + len - rotations
            len2 = rotations

            if (2*rotations > len):
                start2 = start + rotations
                len2 = len - rotations

            self.swap(start, start2, len2)

            if (2*rotations <= len):
                len = len - rotations
            else:
                start = start + len - rotations
                tmp = rotations
                rotations = 2 * rotations - len
                len = tmp

            if (rotations < len):
                self.rotate(start, len, rotations)

    def swap(self, ind1, ind2, len):
        #print('swap', ind1, ind2, len)
        for i in range(0, len):
            tmp = self.data[ind1 + i]
            self.data[ind1 + i] = self.data[ind2 + i]
            self.data[ind2 + i] = tmp

def main():
    R = ArrayRotator()
    inp1 = sys.stdin.readline().strip('\n')
    args = inp1.split(' ')
    inp2 = sys.stdin.readline().strip('\n')
    R.populate(args[0], inp2)
    R.rotate(0, int(args[0]), int(args[1]))
    
    print (*R.data, sep=' ')

if __name__ == "__main__":
    main()
