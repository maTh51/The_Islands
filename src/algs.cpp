#include "algs.hpp"

void greed(island *v, int N, int M){

    int quoci, points=0, days=0, count=0;

    while(N > 0 && count < M){
        if(v[count].cost <= N){
            quoci = N/v[count].cost;
            N = N%v[count].cost;
            
            points = points + quoci*v[count].points;
            days = days + quoci;
        }
        count++;    
    }

    std::cout << points << " " << days << std::endl;
}

int dynamic(island *v, int money, int it, int **Mem){
    int points;

    if(it < 0 || money == 0){
        points=0;
        return(0);
    }

    else if(Mem[it][money-1] != -1)
        return(Mem[it][money-1]);
    
    else if(v[it].cost > money)
        points = dynamic(v,money,(it-1),Mem);

    else{
        int ans1 = dynamic(v,money,(it-1),Mem);
        int ans2 = v[it].points + dynamic(v,(money - v[it].cost), (it-1), Mem);
        if(ans1 >= ans2)
            points = ans1;
        else
            points = ans2;
    }

    Mem[it][money-1] = points;   
    return(points);
}