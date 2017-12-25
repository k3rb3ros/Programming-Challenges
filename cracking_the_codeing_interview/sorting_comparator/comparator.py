from sys import stdin

def main():
    data = []
    num_inp = int(stdin.readline().strip('\n'))

    for i in range(0, num_inp):
        line = stdin.readline().strip('\n').split(' ')
        P = Player(line[0], int(line[1]))
        data.append(P)

    S = Sorter(data)
    S.sort()

    for d in data:
        print(str(d))

class Player:
    def __init__(self, name, score):
        if (type(name) is not str):
            raise TypeError('name must be a string')
        if (type(score) is not int):
            raise TypeError('score must be an integer')
        self.name = name
        self.score = score

    def __repr__(self):
        return self.name + ' ' + str(self.score)

    def compare(self, rhs):
        if (type(rhs) is not Player):
            raise TypeError('Can only compare Player with other instances of Player')

        compare = 0

        if (self.score == rhs.score):
            if (self.name < rhs.name):
                compare = -1
            elif (self.name > rhs.name):
                compare = 1
        else:
            if (self.score > rhs.score):
               compare = -1
            elif (self.score < rhs.score):
               compare = 1

        return compare

class Sorter:
    def __init__(self, arr):
        self.data = arr

    def quicksort(self, left, right):
        if (left < right):
            pivot = self.data[int((left+right)/2)]
            index = self.partition(left, right, pivot)
            self.quicksort(left, index-1)
            self.quicksort(index, right)

    def sort(self):
        self.quicksort(0, len(self.data)-1)

    def swap(self, ind1, ind2):
        temp = self.data[ind1]
        self.data[ind1] = self.data[ind2]
        self.data[ind2] = temp

    def partition(self, left, right, pivot):
        while (left <= right):
            while (self.data[left].compare(pivot) < 0):
                left += 1
            while (self.data[right].compare(pivot) > 0):
                right -= 1

            if (left <= right):
                self.swap(left, right)
                left += 1
                right -= 1

        return left

if __name__ == '__main__':
    main()
