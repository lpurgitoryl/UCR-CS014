#include "Graph.h"

Graph::Graph(ifstream& input){
    int NumNodes = 0;
    int numEdges = 0;

    string newLabel;
    //dont need to change color yet until search
    cin >> NumNodes;
    cin >> numEdges;
    //no spaces in label so i can just cin
    for( int i = 0; i < NumNodes; ++i){
        Vertex newVert;
        input >> newLabel;
        newVert.label = newLabel;
        vertices.push_back(newVert);
    }
    // next for loop takes in the param vect and its edge
    


}
