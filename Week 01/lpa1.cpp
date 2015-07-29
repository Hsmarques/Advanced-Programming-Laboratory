/* 
 * Author: Hugo
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*
 * The first line contains three integers:
 * the number of topics (m),      1 ≤ m ≤ 5 000 
 * the number of precedences (n)  1 ≤ n ≤ 300 000
 * and the maximum number of topics that Jocas can study in a single day.
 * Then, n lines follow.
 * Each line has two integers, a and b, where a is the topic that must be studied before topic b.
 */

static int done[5000];
static int array2d[5000][5000];
int topics, notdonetopics, maxtopics, temptopics = 0;
int maxTopicsIn1Day = 0;
int desperateDays = 0;
int exists = 0;

void cleanTopics() {
    int i, j;
    /*percorre o array done[] por topicos estudados 
     *percorre a matrix para decrementar o valor dos topicos para que possam ser estudados*/

    for (i = 0; i < topics; i++) {
        if (done[i] == -1) {
            done[i] = -2;
            for (j = 0; j < topics; j++) {
                if (array2d[i][j] == 1) {
                    done[j]--;
                }
            }
        }
    }
}

void study() {
    int i;

    for (i = 0; i < topics; i++) {
        if (done[i] == 0) {
            done[i]--;
            notdonetopics--;
            temptopics++;
        }

    }

    cleanTopics();

    if (temptopics > maxTopicsIn1Day) {
        maxTopicsIn1Day = temptopics;
    }
    if (temptopics > maxtopics) {
        desperateDays++;
    }

    temptopics = 0;

}

int main() {

    int precedences, a, b;
    cin >> topics;
    cin >> precedences;
    cin >> maxtopics;
    
    notdonetopics = topics;

    while (precedences > 0) {
        cin >> a;
        cin >> b;
        array2d[a][b] = 1;
        precedences--;
        done[b]++;
    }

    while (notdonetopics > 0) {
        study();
    }

    cout << maxTopicsIn1Day << " " << desperateDays << endl;

    return 0;
}

