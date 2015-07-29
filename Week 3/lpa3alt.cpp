/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int bestScore = 0;

void GetBetterScore(vector<int> shootingballs,int position, int score) {
    int nelementos = 0, tempscore = 0, blabla=0;
    unsigned int i, j;

    for (i=position-blabla ; i < shootingballs.size(); ++i) {
        //se for a ultima posicao
        //Tratar a sequencia se existir
        

        if (i == shootingballs.size()-1) {
            return;
        } else if (shootingballs.at(i) == shootingballs.at(i + 1)) { //encontrou uma sequencia
            vector<int> newvector = shootingballs; //cria novo vector temp igual ao anterior
            j = i; //vai ver até onde é que a sequencia chega

            while (j < (shootingballs.size() - 1) && shootingballs.at(j) == shootingballs.at(j + 1)) {
                    nelementos++;
                    j++;
            }

            //calcular o score de eliminar a sequencia
            tempscore = (nelementos + 1)*(nelementos + 2)+score;

            //remove a sequencia do vector temporario
            newvector.erase(newvector.begin()+i, newvector.begin()+j+1);


            if ((tempscore) > bestScore) {
                bestScore = tempscore;
            }
            
            
            while(i>0){
                if((i-1)<0){
                    break;
                }else if (shootingballs.at(j+1)==shootingballs.at(i-1)){
                    i--;
                }else{
                    break;
                }
            }
            GetBetterScore(newvector,i,tempscore);
            GetBetterScore(shootingballs, j+1, score);
            return;
        }

        //reset das variaveis temp usadas para tratar
        tempscore = 0;
        nelementos = 0;
    }

    return;
}

int main() {

    int testcases, nballs, i, tempval;

    cin >> testcases;

    while (testcases > 0) {
        cin >> nballs;
        vector<int> shootingballs;
        shootingballs.reserve(nballs);
        for (i = 0; i < nballs; ++i) {
            cin >> tempval;
            shootingballs.push_back(tempval);
        }
        GetBetterScore(shootingballs, 0, 0);

        cout << bestScore << endl;
        bestScore = 0;
        testcases--;
        shootingballs.resize(0);
    }

    return 0;
}
