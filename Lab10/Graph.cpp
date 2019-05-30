 #include "Graph.h"
 #include <iostream>

Graph::Graph() {
    //vertices = 0;
    //not needed, vector of vertices already initialized to 0.
}  

Graph::Graph(ifstream & inFS) {
    int N = 0;
    int M = 0;
    
    inFS >> N;
    inFS >> M;
    string s;
    int pos1 = 0;
    int pos2 = 0;
    
    for(int i = 0; i < N; i++) {
        inFS >> s;
        Vertex v;
        v.label = s;
        vertices.push_back(v);
    }

    for(int i = 0; i < M; M--) {
        //find start edge
        inFS >> s;
        pos1 = find(s);
        
        //find neighbor
        inFS >> s;
        pos2 = find(s);
        
        int num = 0;
        inFS >> num;
        i
        pair<int,int> p(pos2,num);
        vertices.at(pos1).neighbors.push_back(p);
    }
    
}

Graph::~Graph(){
    
}

void Graph::output_graph(const string & s) {
    ofstream outFS(s.c_str());
    if(!outFS.is_open()){
        cout << "Error opening file" << endl;
        return;
    }
    outFS << "digraph G {" << endl;
    output_graph(outFS);
    outFS << "}";
    outFS.close(); 
    
    string jpegFileName = s.substr(0, s.size()-4) + ".jpg";
    string command = "dot -Tjpg " + s + " -o " + jpegFileName;
    system(command.c_str());
  
}

void Graph::output_graph(ofstream & s) {
    for(unsigned i = 0; i < vertices.size(); i++) {
        s << vertices.at(i).label << " [label=\"" << vertices.at(i).label << ", distance = " << vertices.at(i).distance << "\"];" << endl;
        cout << vertices.at(i).distance << endl;
        Vertex v = vertices.at(i);
            for (list<pair<int,int> >::iterator it = v.neighbors.begin(); it != v.neighbors.end(); it++) {
                int first = i;
                int last = it->first;
                s << vertices.at(first).label << " -> " << vertices.at(last).label << ";" << endl;
            }
    }
  
}

void Graph::bfs() {
    queue<Vertex> q;
	vertices.at(0).color = "GREY";
	vertices.at(0).distance = 0; 
	q.push(vertices.at(0));
	while(!q.empty()) {
		Vertex v = q.front();
		q.pop();
		  for (list< pair<int,int> >::iterator it = v.neighbors.begin(); it != v.neighbors.end(); it++) {
		      int pos = it->first; 
                if(vertices.at(pos).color == "WHITE") {
				    vertices.at(pos).color = "GREY";
				    vertices.at(pos).distance = v.distance + 1;
				    cout << vertices.at(pos).distance << endl;
				    vertices.at(pos).prev = &v;
		
				    q.push(vertices.at(pos));
                }

			v.color = "BLACK";
	}
        
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).color == "WHITE") {
            vertices.at(i).distance = INT_MAX;
            
        }
    }
    }   
}


int Graph::find(string s) {
    for(unsigned i = 0; i < vertices.size(); i++) {
        if(vertices.at(i).label == s) {
            return i;
        }
    }
    return -1;
}

void Graph::dfs_visit(Vertex &v) {
    v.color = "GRAY";
        cout << v.label << ", ";
    for (list<pair<int,int> >::iterator it = v.neighbors.begin(); it != v.neighbors.end(); it++) {
        if(vertices.at(it->first).color == "WHITE") {
            vertices.at(it->first).prev = &v;
            vertices.at(it->first).distance = v.distance + 1;
            dfs_visit(vertices.at(it->first));
        }
        v.color = "BLACK";
    }
}

void Graph::dfs() {
    vertices.at(0).distance = 0;
    for(unsigned i = 0; i<vertices.size();i++)
    {
        if(vertices.at(i).color == "WHITE")
            dfs_visit(vertices.at(i));
    }
}