from enum import Enum
import sys

class Stack:
    m_data = None

    def __init__(self):
        self.m_data = []

    def isEmpty(self):
        return self.m_data == []

    def peak(self):
        ch = None
        if (len(self.m_data) > 0):
            ch = self.m_data[len(self.m_data)-1]

        return ch

    def pop(self):
        return self.m_data.pop()

    def push(self, item):
        self.m_data.append(item)

    def size(self):
        return len(self.m_data)

class Queue:
    S1 = None
    S2 = None

    def __init__(self):
        self.S1 = Stack()
        self.S2 = Stack()

    def enque(self, val):
        self.S1.push(val)
        
    def deque(self):
        val = None
        if (self.S2.isEmpty() and not self.S1.isEmpty()):
            while(not self.S1.isEmpty()):
                self.S2.push(self.S1.pop())

        if (not self.S2.isEmpty()):
            val = self.S2.pop()

        return val

    def peak(self):
        val = None
        if (self.S2.isEmpty() and not self.S1.isEmpty()):
            while(not self.S1.isEmpty()):
                self.S2.push(self.S1.pop())
       
        if (not self.S2.isEmpty()):
            val = self.S2.peak()

        return val

class Action(Enum):
    ENQUE = 1
    DEQUE = 2
    PRINT = 3
    NO_ACTION = -1

class Controller:
    #m_actions = None
    m_size = None
    m_Q = None
    m_ouput = None

    def __init__(self):
        #self.m_actions = []
        self.m_size = 0
        self.m_Q = Queue()

    def execute(self, action):
        if (action == None):
            print('Invalid action')
        elif (action[0] == Action.ENQUE):
            #print('Enqueueing ' + str(action[1]))
            self.m_Q.enque(action[1])
            #print(self.m_Q.S1.m_data, self.m_Q.S2.m_data)
        elif (action[0] == Action.DEQUE):
            #print('Dequeing ' + str(self.m_Q.peak()))
            self.m_Q.deque()
            #print(self.m_Q.S1.m_data, self.m_Q.S2.m_data)
        elif (action[0] == Action.PRINT):
            #print('Printing')
            print(self.m_Q.peak())
            #print(self.m_Q.S1.m_data, self.m_Q.S2.m_data)

    def parse(self, str):
        action = None
        val = None
        if (not str == None):
            intermediate = str.split(' ')
            action = Action(int(intermediate[0]))
            if (len(intermediate) > 1):
                val = int(intermediate[1])

            return (action, val)

    def run(self):
        self.m_size = int(sys.stdin.readline().strip('\n'))
        for i in range(0, self.m_size):
            self.execute(self.parse(sys.stdin.readline().strip('\n')))
    
def main():
    C = Controller()
    C.run()

if __name__ == '__main__':
    main()
