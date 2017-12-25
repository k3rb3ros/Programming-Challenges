#!/usr/bin/python3

import queue

class graph:
    def __init__(self, name):
        self.name = name
        self.actors = {}
        self.movies = {}
        self.actors["Angelina Jollie"] = ["Mr. and Mrs Smith", "Salt"]
        self.actors["Brad Pitt"] = ["Mr. and Mrs Smith"]
        self.actors["Jake Jim"] = ["Mr. and Mrs Smith", "Haloween Joke"]
        self.movies["Mr. and Mrs Smith"] = ["Angelina Jollie", "Brad Pitt", "Jake Jim"]
        self.movies["Salt"] = ["Angelina Jolie", "Brad Pitt"]

    def getMoviesForActor(self, actor):
        movies_ = []
        if (actor in self.actors):
            movies_ = self.actors[actor]

        return movies_

    def getActorsInMovie(self, movie):
        actors_ = []
        if (movie in self.movies):
            actors_ = self.movies[movie]

        return actors_

def getDegreeOfSeperation(graph, actor1, actor2):
    Found = False
    N = 0
    Q = queue.Queue()
    Prev = {}

    Q.put(actor1)

    while (not Q.empty()):
        this_a = Q.get()
        Prev[this_a] = True

        #we found the actor we are looking for
        #print ("Comparing " + this_a + " with " + actor2)
        if (this_a == actor2):
            Found = True
            break
        else: #queue all connected actors
            movies_to_query = graph.getMoviesForActor(this_a)
            for m in movies_to_query:
                cons = graph.getActorsInMovie(m)
                for a in cons:
                    if (not a in Prev.keys()):
                        #print ("Queuing " + a)
                        Q.put(a)
        N += 1
    #end while

    if (not Found):
        N = -1

    return N

def main():
    G = graph("graph")
    print(getDegreeOfSeperation(G, "Angelina Jollie", "Jake Jim"))
    print(getDegreeOfSeperation(G, "Graham Bell", "Jake Jim"))
    print(getDegreeOfSeperation(G, "", ""))

if __name__ == "__main__": main()
