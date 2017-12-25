import sys

class Stack:
    m_data = []

    def __init__(self):
        self.m_data = []

    def isEmpty(self):
        return self.m_data == []

    def peak(self):
        ch = ''
        if (len(self.m_data) > 0):
            ch = self.m_data[len(self.m_data)-1]
        
        return ch

    def pop(self):
        return self.m_data.pop()

    def push(self, item):
        self.m_data.append(item)

    def size(self):
        return len(self.m_data)

class bracketParser:
    m_num_input = 0
    m_input = []
    m_lookup = {}
    m_validity = []

    def __init__(self):
        self.m_lookup ['{'] = '}'
        self.m_lookup ['['] = ']'
        self.m_lookup ['('] = ')'
        self.m_lookup ['}'] = '{'
        self.m_lookup [']'] = '['
        self.m_lookup [')'] = '('

        self.m_num_input = int(sys.stdin.readline().strip('\n'))

        for i in range(0, self.m_num_input):
            self.m_input.append(sys.stdin.readline().strip('\n'))

    def pair(self, lhs, rhs):
        return (lhs in self.m_lookup and self.m_lookup[lhs] == rhs)

    def parse(self):
        for i in range(0, self.m_num_input):
            valid = self.parse_line(self.m_input[i])
            self.m_validity.append(valid)

    #problem solving code is here
    def parse_line(self, line):
        open_brackets = Stack()

        for ch in line:
            if (ch == '{' or ch == '[' or ch == '('):
                open_brackets.push(ch)

            if (ch == '}' or ch == ']' or ch == ')'):
                if (open_brackets.isEmpty() or
                    not self.pair(ch, open_brackets.peak())):
                    return False
                open_brackets.pop()
                    
        return open_brackets.size() == 0

        
    def printResults(self):
        for i in range(0, self.m_num_input):
            if (self.m_validity[i] == True):
                print ('YES')
            else:
                print ('NO')

def main():
    B = bracketParser()
    B.parse()
    B.printResults()

if __name__ == '__main__':
    main()
