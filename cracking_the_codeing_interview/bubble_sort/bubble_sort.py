from sys import stdin

class Sorter:

    def __init__(self, data):
        if type(data) is list:
            self.data = data
            self.swaps = 0
        else:
            print('Invalid data type passed into Sorter')

    def printStats(self):
        print('Array is sorted in', self.swaps, 'swaps.')
        print('First Element:', self.data[0])
        print('Last Element:', self.data[len(self.data)-1])

    def sort(self):
        for i in range(0,len(self.data)):
            for j in range(0, len(self.data)-1):
                if (self.data[j] > self.data[j+1]):
                    self.swap(j, j+1)

    def swap(self, ind1, ind2):
        temp = self.data[ind1]
        self.data[ind1] = self.data[ind2]
        self.data[ind2] = temp
        self.swaps += 1

def main():
    num_elems = int(stdin.readline().strip('\n'))

    data = list(map(int, stdin.readline().strip('\n').split(' ')))

    S = Sorter(data)
    S.sort()
    S.printStats()

if __name__ == '__main__':
    main()
