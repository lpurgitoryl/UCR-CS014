#include "Graph.h"
#include "Vertex.h"


Graph::~Graph(){
    int size = vertices.size();

    while (size !=0)
    {
        vertices.at(size - 1).neighbors.clear();
        vertices.pop_back();
        --size;
    }
    
}
Graph::Graph(ifstream& input){
    int NumNodes = 0;
    int numEdges = 0;
    string vec1;
    string vec2;
    int cost;
    

    string newLabel;
    //dont need to change color yet until search
    input >> NumNodes;
    cout << NumNodes << endl;
    input >> numEdges;
    cout << numEdges << endl;
    //no spaces in label so i can just extract from file
    cout << "These are the graph nodes" << endl;

    for( int i = 0; i < NumNodes; ++i){
        Vertex newVert;
        input >> newLabel;
        cout << newLabel << endl;
        newVert.label = newLabel;
        vertices.push_back(newVert);
    }
    // next for loop takes in the param vect and its edge

     cout << "This is the edges section" << endl;
     cout << endl << endl;
    int counter = 1;
    for(int i = 0; i < numEdges ; ++i){
        cout << "EDGE NUMBER " << counter << endl << endl;
        ++counter;
        input >> vec1;
        cout << "this is the vert " << vec1 << endl; 
        input >> vec2;
        cout << "this is the connecting vert " << vec2 << endl;
        input >> cost;
        cout << "this is the cost " << cost << endl << endl;
        int indexVec1 = 0;
        int indexVec2 = 0;

        //find vec1, vec2
        for(unsigned int j = 0; j < vertices.size() ; ++j){
            if(vertices.at(j).label == vec1){
                indexVec1 = j;
            }
            else if(vertices.at(j).label == vec2){
                indexVec2= j;
            }
        }
        
        vertices.at(indexVec1).neighbors.push_back(make_pair(indexVec2, cost));
    }

}
void Graph::bfs(){
    string color = "WHITE";
   // int distance = 0;
    Vertex* checkedNode = nullptr;
    
    queue<Vertex*> vistNodes;
    vertices.at(0).distance = 0;
    vistNodes.push(&vertices.at(0));


    while( !vistNodes.empty() ){
        checkedNode = vistNodes.front();
        //checkedNode->distance = 0;
        checkedNode->color = "RED";
        vistNodes.pop();

         for (list<pair<int, int> >::iterator it = checkedNode->neighbors.begin(); it != checkedNode->neighbors.end(); it++){
            int itemIndex = it->first;
            vertices.at(itemIndex).prev = checkedNode;
            if(vertices.at(itemIndex).color == color){
                vertices.at(itemIndex).color = "BLACK";
                vertices.at(itemIndex).distance = vertices.at(itemIndex).prev->distance + 1;//vertices.at(itemIndex).distance;
                vistNodes.push(&vertices.at(itemIndex));
            }     
        }

        checkedNode->color = "BLACK";
    }

}

void Graph::output_graph(const string & outputFile){
    ofstream output(outputFile);

    if( !output.is_open()){
        cout << "ERROR OPENING OUTPPUTFILE" << endl;
    }

    output << "digraph G {" << endl;
     for(unsigned int j = 0; j < vertices.size() ; ++j){
            output << vertices.at(j).label << " [ label= \"" << vertices.at(j).label << " : " << vertices.at(j).distance << "\"];" << endl;
    } 
     for(unsigned int j = 0; j < vertices.size() ; ++j){
            for (list<pair<int, int> >::iterator it = vertices.at(j).neighbors.begin(); it != vertices.at(j).neighbors.end(); it++){
                output << vertices.at(j).label << " ->" << vertices.at(it->first).label << endl;
            }
    } 
            
    output <<"}";
}
void Graph::output_graph(){
    cout << "this the vertices graph" << endl;
    for(unsigned int j = 0; j < vertices.size() ; ++j){
            cout << vertices.at(j).label << endl;
            cout << "these are the pairs" << endl;
             for (list<pair<int, int> >::iterator it = vertices.at(j).neighbors.begin(); it != vertices.at(j).neighbors.end(); it++){
                cout << it->first << ' ' << it->second << " then|";
            }
            cout << endl;
        }
}
