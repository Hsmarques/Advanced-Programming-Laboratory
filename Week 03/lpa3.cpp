/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int bestScore = 0;
 
void GetBetterScore(vector<int> shootingballs,int position, int score, int lastseq) {
    int nelementos = 0, tempscore = 0;
    unsigned int i, j;
    //bool end=false;

    for (i = position; i < shootingballs.size(); ++i) {
        //se for a ultima posicao
        //Tratar a sequencia se existir

    //cout << "dentro do for na posicao i: " << i << endl;
        if (i == shootingballs.size()-1) {
            return;
        } else if (shootingballs.at(i) == shootingballs.at(i + 1)) { //encontrou uma sequencia
            vector<int> newvector = shootingballs; //cria novo vector temp igual ao anterior
            j = i; //vai ver atÃ© onde Ã© que a sequencia chega

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
            GetBetterScore(newvector, lastseq, tempscore,0);
            GetBetterScore(shootingballs, j+1, score, i);
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
        GetBetterScore(shootingballs, 0, 0, 0);

        cout << bestScore << endl;
        bestScore = 0;
        testcases--;
        shootingballs.resize(0);
    }

    return 0;
}
