#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "mergesort.hpp"
#include "algs.hpp"


using namespace std;

int main(int argc, char *argv[]){
    int N;  //Money to be spent on the trip
    int M;  //Number of islands

    ifstream file (argv[1]);
    if (file.is_open()){
        file >> N >> M;

        island Island[M];
        
        int Ilhas[M][2];
        float razao[M];

        for (int i = 0; i < M; i++){
            file >> Island[i].cost >> Island[i].points;
            Island[i].ratio = float(Island[i].cost)/float(Island[i].points);
        }

        //Dynamic:

        //Creating Matriz M*N to store values in DP
        int** Mem = new int*[M];
        for(int i = 0; i < M; ++i)
            Mem[i] = new int[N];
        
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                Mem[i][j] = -1;
            }
        }

        int ans_dy = dynamic(Island,N,M-1,Mem);
        
        //Finding number of days of the trip
        int days = 0;
        int aux_N = N-1;
        int aux_M = M-1;

        while(aux_M > 0) {
            if (Mem[aux_M][aux_N] != Mem[aux_M-1][aux_N]) {
                aux_N = aux_N - Island[aux_M].cost;
                days++;
            }
            aux_M--;
        }
        if(Mem[aux_M][aux_N] != 0) //Cases that the first island is selected 
            days++;
        

        //Greed
        island aux[N];

        mergesort(Island,0,(M-1),aux);

        greed(Island, N, M); //the function print the results

        //Printing the results of dynamic
        cout << ans_dy << " " << days << endl;

        free(Mem);
    }
    
    else{
        cout << "Unable to open file" << endl;
        return(1);
    }

    file.close();

  return(0);
}