import sys

class Ransomizer:
    avail_words = {}
    target_words = {}

    def __init__(self, m, n):
        m_words = m.strip('\n').split(' ')
        m_target = n.strip('\n').split(' ')

        #hash the count of all words in the magazin
        for w in m_words:
            if w in self.avail_words:
                self.avail_words[w] += 1
            else:
                self.avail_words[w] = int(1)

        for w in m_target:
            if w in self.target_words:
                self.target_words[w] += 1
            else:
                self.target_words[w] = int(1)

    def can_print_target(self):
        words = self.avail_words
        target = self.target_words

        #iterate through target words and source words decrimenting word count whenever we find a match
        for w in target:
            if w not in words:
                print (w + ' not in words')
                return False

            while (target[w] > 0 and words[w] > 0):
                target[w] -= 1
                words[w] -= 1

            if (target[w] > 0):
                return False

        return True

def main():
    sys.stdin.readline()
    m = sys.stdin.readline()
    n = sys.stdin.readline()

    R = Ransomizer(m, n)
    if R.can_print_target():
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
