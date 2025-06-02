#include <iostream>
#include <cstring>

using namespace std;


struct vertex {
    
    int data;
    
};

// function prototypes
void addVertex(int& input, int matrix[20][20], char label[20]);
void printGraph(int totalVertex, int matrix[20][20], char labels[]);
void addEdge(int matrix[20][20], char labels[], int totalVertex);
// with add edge, we have to connect two vertiices
int indexFunction(char labels[], int totalVertex, char label);
void removeEdge(int& totalVertex, int matrix[20][20], char labels[]);
void removeVertex(int& totalVertex, int matrix[20][20], char labels[]);
void shortestPath(int totalVertex, int matrix[20][20], char labels[]);




int main()
{

// all these variables are CRUCIAL
int matrix[20][20]; 
int totalVertex = 0;
// adjacency matrix is a 2D array
char labels[20]; // user will only be able to enter A B C, etc. One letter words
bool stillGoing = true; // this will keep the function going

  

for (int i = 0; i < 20; i++) {
    for (int a = 0; a < 20; a++) {
        matrix[i][a] = 0; // two vertexs are i and a
        // similar to how we did for ha table
        // we need to set each thing to 0, for right now.
    }
}
while (stillGoing) {
char userInput[50];
// user input
cout << "Please type 'ADD VERTEX' to add a vertex: " << endl;
cout << "Type 'PRINT' if you wish to print out the graph" << endl;
cout << "Type 'ADD EDGE' if you wish to add a edge that connects two nodes" << endl;
cout << "If you wish to REMOVE a vertex, type 'REMOVE VERTEX' "<< endl;
cout << "If you wish to remove an edge, type 'REMOVE EDGE'" << endl;
cout << "If you wish to find the shortest path, type 'SHORTEST'" << endl;

cin.getline(userInput, 50, '\n');


if (strcmp(userInput, "ADD VERTEX") == 0) {
    
    int input;
    cout << "Please enter the amount of verticies you wish to add" << endl;
    cin >> input; // input will be the vertex count
    cin.ignore();
    
    for (int i = 0; i < input; i++) {
    addVertex(totalVertex, matrix, labels);
    }
}

    else if (strcmp(userInput, "PRINT")==0) {
        printGraph(totalVertex, matrix, labels);
    }
    else if (strcmp(userInput, "ADD EDGE")==0) {
        addEdge(matrix, labels, totalVertex); // with add edge, we have to connect two vertiices

    }
    else if (strcmp(userInput, "REMOVE VERTEX")==0) {
    removeVertex(totalVertex, matrix, labels);

    }
    
    else if (strcmp(userInput, "REMOVE EDGE")==0) {
    removeEdge(totalVertex, matrix, labels);
    
    }
    
    else if (strcmp(userInput, "SHORTEST")==0) {
        shortestPath(totalVertex, matrix, labels);

    }

}


    return 0;
}

// printing out graph (with labels!!)
void printGraph(int totalVertex, int matrix[20][20], char labels[]) {
    
    
    
    cout << "   ";
    for (int i = 0; i < totalVertex; i++) {
        cout << labels[i] << " "; // printing out the "A B C.." on top.
    }
    cout << endl;
    for (int i = 0; i < totalVertex; i++) {
        
        cout << labels[i] << "  "; // printg ouot the A B C
        
        for (int a = 0; a < totalVertex; a++) {
            cout << matrix[i][a] << " "; // printing out te actual matrix
        }
        cout << endl;
    }
    
    
}





void addVertex(int& totalVertex, int matrix[20][20], char labels[]) {

    char label;
    cout << "What would you like to name this vertex?" << endl;
    cin >> label;// asks for a name for each vertex
    // we create a while  loop in the main function so it keeps asking
     
    if (totalVertex > 20) {
     cout << "You can only enter a maximum of 20 verticies! " << endl;   
    }
    
    
    labels[totalVertex] = label;
    

    
    for (int i = 0; i <= totalVertex; i++) {
        matrix[i][totalVertex] = 0;
        matrix[totalVertex][i] = 0;
        // here we are allocating new space for the new nodes (new row and column for each node)
    }
    
    
    totalVertex++;
    cout << "Added vertex with the label: " << label << endl;
    
    
}


// for addig edge

void addEdge(int matrix[20][20], char labels[], int totalVertex) { // with add edge, we have to connect two vertiices
    
    
    char originalNode;
    // get 
    char nextNode;
    
    int weight;
    
    cout << "Enter the inital node: " << endl;
    cin >> originalNode;
    
    cout << "Enter the node you want to connect with the inital node : " << endl;
    cin >> nextNode;
    // obtain the node the user wishes to connect
    // then the weight of each edge.
    cout << "Edge weight: " << endl;
    cin >> weight;
    cin.ignore();
    
    int originalIndex = indexFunction(labels, totalVertex, originalNode);
    int nextIndex = indexFunction(labels, totalVertex, nextNode);
// getting index


    if (originalIndex == -1 || nextIndex == -1) {
    // if node has these values, they do not eixst.
    cout << "These node(s) do NOT exist"<< endl;

        return;
    }

    if (matrix[originalIndex][nextIndex] != 0) {

    cout << "There is an already an edge with these two nodes, nice try !! HAHA" << endl;

        return;
    }

    matrix[originalIndex][nextIndex] = weight; // setting the weight of the path that attaches the two nodes
    // assigning weight to designated nodes.

    
}


// this function makes it simple to get the index value of smth in the adjcency natriux
int indexFunction(char labels[], int totalVertex, char label) {
    for (int i = 0; i < totalVertex; i++) {
        if (labels[i] == label) {
           return i;
        }
    }
    return -1;
}



// removing the edge that connects two verticies
void removeEdge(int& totalVertex, int matrix[20][20], char labels[20]) {
    
    char removeFirst; // asking for user input
    char removeSecond;
    
    cout << "Please enter the first node's label of the edge you want to delete" << endl;
    
    cin >> removeFirst;
    
    cout << "PLease enter the second node's label of the edge you wish to delete" << endl;
    cin >> removeSecond;
    
    // obtaining index
  int vertexOne = indexFunction(labels, totalVertex, removeFirst);
  int vertexTwo = indexFunction(labels, totalVertex, removeSecond);
   
matrix[vertexOne][vertexTwo] = 0; 
// resetting to blank (0)

    
}


void removeVertex(int& totalVertex, int matrix[20][20], char labels[]) {
    // for this function we need to delete corresponding row and column.
    int numberOfVertexToDelete;
    
    cout << "Enter the number of vertex/verticies you wish to delete: " << endl;
    cin >> numberOfVertexToDelete;
    
    for (int i = 0; i < numberOfVertexToDelete; i++) {
    
    
    
    
    char vertexToDelete;
    
    cout << "Enter the label of the vertex you wish to delete" << endl;
    cin >> vertexToDelete;
    
    int nodeIndex = indexFunction(labels, totalVertex, vertexToDelete);
    
    for (int i = nodeIndex; i < totalVertex-1; i++) {
        labels[i] = labels[i+1]; // removing the label
    }
    
    
   for (int i = nodeIndex; i < totalVertex - 1; i++) {
        for (int a = 0; a < totalVertex; a++) {
            matrix[i][a] = matrix[i + 1][a]; 
            // removing row
        }
    }

    for (int j = nodeIndex; j < totalVertex - 1; j++) {
        for (int a = 0; a < totalVertex; a++) {
            matrix[a][j] = matrix[a][j + 1];
            // removing column
        }
    }
    
    
    totalVertex--; // deincrement the total Vertex count, as we just removed one
    }
}

//  djikstra algorithim (useful for finding the shortest path, travelling salesman problem)
void shortestPath(int totalVertex, int matrix[20][20], char labels[]) {
    
    char firstNode;
    
    char secondNode;
    
    cout << "Enter the first vertex: " << endl;
  
  
    cin >> firstNode;
  
    //  getting starting and ending verticies.  
            
    cout << "Enter the connecting vertex: " << endl;
  
    cin >> secondNode;
    
    int distance[20]; // will be used to kepe the shortest distance

    bool nodeIterated[20] = {false};
    int number = 1949413; // large big fat number

    
    
    int firstIndex = -1;
    int nextIndex = -1;
    
   // distance[firstIndex] = 0;
        
    for (int i = 0; i < totalVertex; i++) {
        if (labels[i] == firstNode) {
            firstIndex = i; // index gets altered
        }
        
        if (labels[i] == secondNode) {
            nextIndex = i;
        }
    }
    //if index does not get altered, these nodes are not valid.
    if (firstIndex == -1 || nextIndex == -1) {
        cout << "YOU CANNOT USE THESE" << endl;
        return;
    }
    
    
    for (int i = 0; i < 20; i++) { // initalizing the distance array
    // becaues we do not know the shortest path, we temproarily have to assume every path is some insane number
    // usually infinity, though I did not use that
        distance[i] = number;
    }

    // this is literally saying the distance from the first Node to the same node (the starting node) is 0
    distance[firstIndex]=0;

     for (int total = 0; total < totalVertex; total++) {
        int x = -1;
        int minimumDistance = number;
        

// finding the vertext which HAS NOT been visited.
        for (int i = 0; i < totalVertex; i++) {
            // we use the < > operators to find the SHORTEST path, we nee dto iterate and find the shortest pa th!
            if (!nodeIterated[i] && distance[i] < minimumDistance) {
                minimumDistance = distance[i];
                x = i;
            }
        }
    
    if (x == -1) {
        return; // if cant find a node that has not been visited, will return. 
    }
    
    
    nodeIterated[x] = true;
    
    for (int i = 0; i < totalVertex; i++) {
        if (matrix[x][i] > 0 && !nodeIterated[i] && distance[x] + matrix[x][i] < distance[i]) {
    // checkign if we should update shortest distance.
    
    distance[i] = distance[x] + matrix[x][i];
  
    // updating shortest  distance considering the path goes through the node
    }
    }
    cout << "We get here" << endl;
     
     
    if (distance[nextIndex] == number) {
        cout << "This path does not, and CAN not exist." << endl;
        
}
else { // printig out the shortest path
    cout << "Distance from" << firstNode << " to" << secondNode << " is: " << distance[nextIndex] << endl;
    }
     }
}
