#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

/*  @Author
    Student Name:Büşra Asan
    Student ID :150180100
    Date:13/08/2021
*/

using namespace std;

typedef vector<vector<int>> Matrix;

struct VertexInfo{
    string name;
    int index;
    int count;
};

vector<string> walksArray;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isInfoListValid(const vector<VertexInfo>& infos){
    for(const VertexInfo &info : infos){
        if(info.count > 0) return false;
    }
    return true;
}

void printMatrix(const Matrix& mat){
    int len = mat[0].size();
    for(int i=0; i < len; i++){
        for(int j=0; j < len; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void printVertexInfos(const vector<VertexInfo>& infos){
    for(const VertexInfo &info : infos){
        cout << info.name << ": " << info.count << " ";
    }
    cout << endl;
}
void recursiveTraverse(const string& currentStr, const Matrix& adjMatrix, int currentlyAt, int length, const vector<VertexInfo>& infos, int mandatoryLeft){
    int len = adjMatrix[0].size();
    int stringLen = currentStr.length();
    if(length - stringLen < mandatoryLeft) return;
    if(stringLen == length){
        if(isInfoListValid(infos))  walksArray.emplace_back(currentStr);
        return;
    }

    for(int i = 0; i < len; i++){
        int mandatorySpent = 0;
        if(adjMatrix[currentlyAt][i]){ // walkable
            // update infos
            vector<VertexInfo> newInfos = infos;
            Matrix newAdjMatrix = adjMatrix;
            for(VertexInfo& info : newInfos){
                if(info.index == i && info.count > 0){
                    info.count -= 1;
                    mandatorySpent = 1;
                    if(info.count == 0){
                        for(int j = 0; j < len; j++){
                            newAdjMatrix[j][i] = 0;
                        }
                    }
                }
            }
            recursiveTraverse(currentStr + alphabet[i], newAdjMatrix, i, length, newInfos, mandatoryLeft - mandatorySpent);
        }
    }
}

int main(int argc, char* argv[]){

    string filename = argv[1];
    ifstream file(filename);
    string line;
    getline(file,line);
    istringstream firstLine(line);
    int numOfVertices = 0;
    firstLine >> numOfVertices;

    // READ THE ADJACENCY MATRIX

    Matrix matrix;
    matrix.resize(numOfVertices, std::vector<int>(numOfVertices, 0));

    for(int y=0; y < numOfVertices; y++){
        getline(file, line);
        istringstream matrixLine(line);
        for(int x=0; x < numOfVertices; x++){
            int element = 0;
            matrixLine >> element;
            matrix[y][x] = element;
        }
    }
    vector<VertexInfo> vertexInfos;

    // READ VERTEX INFO
    for(int i = 0; i < numOfVertices; i++){
        getline(file, line);
        istringstream vertexInfo(line);
        VertexInfo info;
        vertexInfo >> info.name >> info.count;
        info.index = alphabet.find(info.name);
        vertexInfos.push_back(info);
    }

    // READ WALK LENGTH
    getline(file, line);
    istringstream walks(line);
    int walkLength = 0;
    walks >> walkLength;


    int mandatoryLeft = 0;
    for( VertexInfo &info : vertexInfos){
        if(info.count == 0){
            for(int i = 0; i < numOfVertices; i++){
                matrix[i][info.index] = 0;
                matrix[info.index][i] = 0;
            }
        }
        else if (info.count > 0){
            mandatoryLeft += info.count;
        }
    }
    

    for(int i = 0; i < numOfVertices; i++){
        int mandatorySpent = 0;
        vector<VertexInfo> newInfos = vertexInfos;
        Matrix newAdjMatrix = matrix;
        for(VertexInfo& info : newInfos){
                if(info.index == i && info.count > 0){
                    info.count -= 1;
                    mandatorySpent = 1;
                    if(info.count == 0){
                        for(int j = 0; j < numOfVertices; j++){
                            newAdjMatrix[j][i] = 0;
                        }
                    }
                }
            }
        recursiveTraverse(string(1, alphabet[i]), newAdjMatrix, i, walkLength, newInfos, mandatoryLeft - mandatorySpent);
    }
    for(string &str : walksArray){
        cout << str << " ";
    }
    return 0;
}
