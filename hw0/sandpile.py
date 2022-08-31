# take in all input sand piles, populate them into matrix
# iterate over entire matrix. for each cell, if < 8, += 1
# if == 8, add a value to each adjacent cell so long as it is not a sink
import time


class Sandpile:
    def __init__(self, inputs=[]):
        self.table = [[0 for i in range(22)] for j in range(22)]
        self.inputs = inputs
        self.initializeTable()
        self.printTable()
        while True:
            self.dropSandOnCenter()
            self.printTable()
            time.sleep(0.5)

    def initializeTable(self):
        for (x, y, h) in self.inputs:
            self.table[y][x] = h

    def dropSandOnCenter(self):
        if self.table[11][11] >= 8:
            self.toppleCell(11, 11)
        else:
            self.table[11][11] += 1

    def toppleCell(self, x, y):
        self.table[y][x] = 0
        neighbors = [(y-1, x-1), (y, x-1), (y+1, x-1), (y-1, x),
                     (y+1, x), (y-1, x+1), (y, x+1), (y+1, x+1)]
        for (u, v) in neighbors:
            if u < 0 or u > 21 or v < 0 or v > 21 or self.table[u][v] == -1:
                continue
            if self.table[v][u] >= 8:
                self.toppleCell(u, v)
            else:
                self.table[v][u] += 1

    def printTable(self):
        for y in range(22):
            line = ''
            for x in range(22):
                if self.table[y][x] == -1:
                    line += '#'
                else:
                    line += str(self.table[y][x])
            print(line)
        print('-----------------')


inputs = [(2, 2, -1), (14, 12, 5), (5, 16, 3), (12, 12, 6)]
sandpile = Sandpile(inputs)


