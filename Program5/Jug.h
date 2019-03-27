#ifndef JUG_H
#define JUG_H
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <list>
using namespace std;

struct Vertex {
public:
  pair<int, int> neighbor[6];
  pair<int, int> state;
  string label;
  int distance;
  string color;
  Vertex* prev;
  
  Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};

class Jug {
    public:
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
    private:
        int locate(Vertex &);
        void fillA(Vertex &);
        void fillB(Vertex &);
        void pourAB(Vertex &);
        void pourBA(Vertex &);
        void emptyA(Vertex &);
        void emptyB(Vertex &);
        void createGraph(vector<Vertex> &);
        bool solutionExists(Vertex &);
        void relax();
        //bool solutionExists?
        //anything else you need
        vector<Vertex> adjList;
        int capacityA;
        int capacityB;
        int goal;
        int costFillA;
        int costFillB;
        int costPourAB;
        int costPourBA;
        int costEmptyA;
        int costEmptyB;
        
        
};
#endif
