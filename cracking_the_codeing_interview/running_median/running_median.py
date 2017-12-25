import bisect
from math import floor
import sys

class NumStater:
    data = None
    data_size = None
    total_inputs = None
    MAXLEN = None

    def __init__(self):
        self.data = []
        self.data_size = 0

    def read(self):
        inp = int(sys.stdin.readline().strip('\n'))
        
        bisect.insort(self.data, inp)
        self.data_size += 1

    def rollingMedian(self):
        median = 0.0
        if (self.data_size > 0):
            #if number of digits in data is odd we need to only return the middle number
            if (self.data_size % 2 == 0):
                mid_ind = int(floor(self.data_size/2))-1
                median = (self.data[mid_ind] + self.data[mid_ind+1]) / 2
            else: #for an even number of digits we need to average the middle two digits
                median = self.data[int(floor(self.data_size/2))]

        return median
def main():
    N = NumStater()
    inp_len = int(sys.stdin.readline().strip('\n'))

    for i in range(0, inp_len):
        N.read()
        print('%.1f' % N.rollingMedian())

if __name__ == '__main__':
    main()
