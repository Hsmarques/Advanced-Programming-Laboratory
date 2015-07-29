/* 
 * Author: Hugo
 */
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#define D1 1
#define D2 2
#define L1 3
#define L2 4
#define R1 5
#define R2 6
#define U1 7
#define U2 8

using namespace std;

int maxSpins, bestSize = 11;
string output = "";


/* L R U D Imagem Feito por Leonel e Madalena, v2.0*/
int mat[24][4] = {
    { 12, 4, 20, 16}, /* 1*/
    { 13, 5, 23, 17}, /* 2*/
    { 14, 6, 22, 18}, /* 3*/
    { 15, 7, 21, 19}, /* 4*/
    { 0, 8, 5, 7}, /* 5*/
    { 1, 9, 6, 4}, /* 6*/
    { 2, 10, 7, 5}, /* 7*/
    { 3, 11, 4, 6}, /* 8*/
    { 4, 12, 18, 22}, /* 9*/
    { 5, 13, 19, 21}, /*10*/
    { 6, 14, 16, 20}, /*11*/
    { 7, 15, 17, 23}, /*12*/
    { 8, 0, 15, 13}, /*13*/
    { 9, 1, 12, 14}, /*14*/
    { 10, 2, 13, 15}, /*15*/
    { 11, 3, 14, 12}, /*16*/
    { 19, 17, 0, 10}, /*17*/
    { 16, 18, 1, 11}, /*18*/
    { 17, 19, 2, 8}, /*19*/
    { 18, 16, 3, 9}, /*20*/
    { 23, 21, 10, 0}, /*21*/
    { 20, 22, 9, 3}, /*22*/
    { 21, 23, 8, 2}, /*23*/
    { 22, 20, 11, 1} /*24*/
};

void rotate(int a, int b, int c, int d, int size, int move, string temp) {

    int tempA = a, tempB = b, tempC = c, tempD = d;
    string local = temp;

    if (move == D1) {
        tempA = mat[tempA][3];
        tempC = mat[tempC][3];
        local = local + "D1 ";
    }
    if (move == D2) {
        tempB = mat[tempB][3];
        tempD = mat[tempD][3];
        local = local + "D2 ";
    }
    if (move == L1) {
        tempA = mat[tempA][0];
        tempB = mat[tempB][0];
        local = local + "L1 ";
    }
    if (move == L2) {
        tempC = mat[tempC][0];
        tempD = mat[tempD][0];
        local = local + "L2 ";
    }
    if (move == R1) {
        tempA = mat[tempA][1];
        tempB = mat[tempB][1];
        local = local + "R1 ";
    }
    if (move == R2) {
        tempC = mat[tempC][1];
        tempD = mat[tempD][1];
        local = local + "R2 ";
    }
    if (move == U1) {
        tempA = mat[tempA][2];
        tempC = mat[tempC][2];
        local = local + "U1 ";
    }
    if (move == U2) {
        tempB = mat[tempB][2];
        tempD = mat[tempD][2];
        local = local + "U2 ";

    }

//cout <<"tempA: " << tempA << " tempB " << tempB << " tempC " << tempC << " tempD " << tempD << endl;

    if (tempA == 0 && tempB == 0 && tempC == 0 && tempD == 0 && size <= maxSpins) {
        if (size < bestSize) {
            bestSize = size;
            output = "" + local;
        }
        return;
    } else if (size > maxSpins) {
        return;
    }

    rotate(tempA, tempB, tempC, tempD, size + 1, D1, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, D2, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, L1, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, L2, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, R1, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, R2, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, U1, local);
    rotate(tempA, tempB, tempC, tempD, size + 1, U2, local);
    return;

}

int main() {

    int matrix[2][2];

    cin >> maxSpins;
    cin >> matrix[0][0];
    cin >> matrix[0][1];
    cin >> matrix[1][0];
    cin >> matrix[1][1];

    /*mandar a,b,d,d, profundidade, movimento e string*/

    /*void rotate(int a, int b,        int c,        int d,        int size, int move, string temp)*/
    rotate(matrix[0][0]-1, matrix[0][1]-1, matrix[1][0]-1, matrix[1][1]-1, 0, 0, output);
    
    cout << output << endl;
    return 0;
}

