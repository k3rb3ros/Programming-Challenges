from collections import defaultdict
from sys import stdin

class Node:
    __slots__ = ['char','is_word', 'links', 'word_count']

    def __init__(self, ch='*'):
        self.char = ch
        self.is_word = False
        self.links = defaultdict(Node)
        self.word_count = 0

    def get_child(self, ch):
        if (ch in self.links):
            return self.links[ch]
        return None

class Trie:

    def __init__(self):
        self.root = Node()
        self.words = {}

    def find_partial(self, partial_word):
        words = 0

        if (type(partial_word) is str):

            if (len(partial_word) > 0):
                C = self.root
                for ch in partial_word:
                    C = C.get_child(ch)
                    if (C is None):
                        break
            if (not C is None):
                words = C.word_count

        #print('find_partial(', partial_word, ')', words)
        return words

    def insert(self, word):
        C = self.root
        if (not type(word) is str):
            print('Invalid data type passed to insert')
        else:
            for ch in word:
                N = C.get_child(ch)
                if (ch not in C.links):
                    N = Node(ch)
                    C.links[ch] = N
                N.word_count += 1
                C = N
            C.is_word = True

    def in_order_traversal(self):
        self.in_order_helper(self.root, 0)

    def in_order_helper(self, node, level):
        if (node is not None and type(node) is Node):
            print (node.char, level, node.is_word, node.word_count)

            for ch in node.links:
                self.in_order_helper(node.links[ch], level+1)

def main():
    T = Trie()
    num_inpt = int(stdin.readline().strip('\n'))

    for inp in range(0, num_inpt):
        inp = stdin.readline().strip('\n').split(' ')
        action = inp[0]
        full_name = inp[1]

        #print(action)
        if (action == 'add'):
            T.insert(full_name)
        elif (action == 'find'):
            N = T.root
            print(T.find_partial(full_name))

    #T.in_order_traversal()

if __name__ == '__main__':
    main()
