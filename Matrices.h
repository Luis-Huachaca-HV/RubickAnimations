//#include "../../build/mak.vc16/x64/src/Matrices/Matrices.h"
#include <math.h>
#include <vector>
#include <iomanip>
#include <iostream>
#define PI           3.14159265358979323846

using namespace std;
float _theta = -5*(PI/180) ;
float _thetaI = 5*(PI/180) ;
// void theta_inv(){
//     theta = -theta ;
// }



const float movArriba[] = { 1.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.01f,
                      0.0f, 0.0f, 1.0f };

const float movAbajo[] = { 1.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, -0.01f,
                      0.0f, 0.0f, 1.0f };

const float movDerecha[] = { 1.0f, 0.0f, 0.01f,
                      0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 1.0f };

const float movIzquierda[] = { 1.0f, 0.0f, -0.01f,
                      0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 1.0f };
//,
const float escalaMenor[] = { 0.99f, 0.0f, 0.0f,
                        0.0f, 0.99f, 0.0f,
                        0.0f, 0.0f, 1.0f};

//.
const float escalaMayor[] = { 1.01f, 0.0f, 0.0f,
                        0.0f, 1.01f, 0.0f,
                        0.0f, 0.0f, 1.0f };

//k
//float theta = 0.0174533*2;

//float theta = 5*(PI/180);
//cambiar de a pocos

// float Ry[] = {cosf(theta), 0.0f, sinf(theta),
//                 0.0f, 1.0f, 0.0f,
//                 -sinf(theta), 0.0f, cosf(theta)};
// float RyI[] = {cosf(thetaI), 0.0f, sinf(thetaI),
// 0.0f, 1.0f, 0.0f,
// -sinf(thetaI), 0.0f, cosf(thetaI)};
// float Ry2[] = { cosf(theta), 0.0f, -sinf(theta),
//                 0.0f, 1.0f, 0.0f,
//                 sinf(theta), 0.0f, cosf(theta) };
// float Ry2I[] = { cosf(thetaI), 0.0f, -sinf(thetaI),
//                 0.0f, 1.0f, 0.0f,
//                 sinf(thetaI), 0.0f, cosf(thetaI) };

// float Rx[] = { 1.0f, 0.0f, 0.0f ,
//                 0.0f, cosf(theta), -sinf(theta),
//                 0.0f, sinf(theta), cosf(theta) };
// float RxI[] = { 1.0f, 0.0f, 0.0f ,
//                 0.0f, cosf(thetaI), -sinf(thetaI),
//                 0.0f, sinf(thetaI), cosf(thetaI) };
// float Rx2[] = { 1.0f, 0.0f, 0.0f ,
//                 0.0f, cosf(theta), sinf(theta),
//                 0.0f, -sinf(theta), cosf(theta) };
//                 float Rx2I[] = { 1.0f, 0.0f, 0.0f ,
//                 0.0f, cosf(thetaI), sinf(thetaI),
//                 0.0f, -sinf(thetaI), cosf(thetaI) };

// float Rz[] = { cosf(theta), -sinf(theta), 0.0f ,
//                 sinf(theta), cosf(theta), 0.0f,
//                 0.0f, 0.0f , 1.0f };
//                 float RzI[] = { cosf(thetaI), -sinf(thetaI), 0.0f ,
//                 sinf(thetaI), cosf(thetaI), 0.0f,
//                 0.0f, 0.0f , 1.0f };
// float Rz2[] = { cosf(theta), sinf(theta), 0.0f ,
//                 -sinf(theta), cosf(theta), 0.0f,
//                 0.0f, 0.0f , 1.0f };
// float Rz2I[] = { cosf(thetaI), sinf(thetaI), 0.0f ,
//                 -sinf(thetaI), cosf(thetaI), 0.0f,
//                 0.0f, 0.0f , 1.0f };

const float _Ry[] = {cosf(_theta), 0.0f, sinf(_theta),
               0.0f, 1.0f, 0.0f,
              -sinf(_theta), 0.0f, cosf(_theta)};
const float _RyI[] = {cosf(_thetaI), 0.0f, sinf(_thetaI),
                0.0f, 1.0f, 0.0f,
            -sinf(_thetaI), 0.0f, cosf(_thetaI)};
const float _Ry2[] = {cosf(_theta), 0.0f, -sinf(_theta),
                0.0f, 1.0f, 0.0f,
                sinf(_theta), 0.0f, cosf(_theta)};
const float _Ry2I[] = {cosf(_thetaI), 0.0f, -sinf(_thetaI),
                0.0f, 1.0f, 0.0f,
                sinf(_thetaI), 0.0f, cosf(_thetaI)};

const float _Rx[] = {1.0f, 0.0f, 0.0f,
            0.0f, cosf(_theta), -sinf(_theta),
            0.0f, sinf(_theta), cosf(_theta)};
const float _RxI[] = {1.0f, 0.0f, 0.0f,
                0.0f, cosf(_thetaI), -sinf(_thetaI),
                0.0f, sinf(_thetaI), cosf(_thetaI)};
const float _Rx2[] = {1.0f, 0.0f, 0.0f,
                0.0f, cosf(_theta), sinf(_theta),
                0.0f, -sinf(_theta), cosf(_theta)};
const float _Rx2I[] = {1.0f, 0.0f, 0.0f,
                0.0f, cosf(_thetaI), sinf(_thetaI),
                0.0f, -sinf(_thetaI), cosf(_thetaI)};

const float _Rz[] = {cosf(_theta), -sinf(_theta), 0.0f,
            sinf(_theta), cosf(_theta), 0.0f,
            0.0f, 0.0f, 1.0f};
const float _RzI[] = {cosf(_thetaI), -sinf(_thetaI), 0.0f,
                sinf(_thetaI), cosf(_thetaI), 0.0f,
                0.0f, 0.0f, 1.0f};
const float _Rz2[] = {cosf(_theta), sinf(_theta), 0.0f,
                -sinf(_theta), cosf(_theta), 0.0f,
                0.0f, 0.0f, 1.0f};
const float _Rz2I[] = {cosf(_thetaI), sinf(_thetaI), 0.0f,
                -sinf(_thetaI), cosf(_thetaI), 0.0f,
                0.0f, 0.0f, 1.0f};

const  float rotarHorario[] = { cos(_theta), sin(_theta), 0.0f,
                -sin(_theta), cos(_theta), 0.0f,
                0.0f,0.0f,1.0f };

//l

const float rotarAntiHorario[] = { cos(_theta), -sin(_theta), 0.0f,
                            sin(_theta), cos(_theta), 0.0f,
                            0.0f,0.0f,1.0f };

//w
const float cutRight[] = { 1.0f, tan(_theta), 0.0f,
                        0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 1.0f };

//q
const float cutLeft[] = { 1.0f, 0.0f, 0.0f,
                        tan(_theta), 1.0f, 0.0f,
                        0.0f, 0.0f, 1.0f };


float round_up(float value, int decimal_places) {
    const float multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

//MATRICES
void MultMatrices(float* mMatrix, float* vertices, int numVertices) {

    for (int i = 0, k = 0; i < numVertices; i++, k += 3) {
        float vector[3];
        for (int j = 0; j < 3; j++) {
            vector[j] = vertices[j + k];
        }

        for (int l = 0, aux = 0; l < 3; l++, aux += 3) {
            float auxVertices = 0;
            for (int m = 0; m < 3; m++) {
                auxVertices += mMatrix[aux + m] * vector[m];
            }
            vertices[l + k] = (auxVertices);
        }

    }

    //for (int i = 0; i < numVertices * 3; i++) {
    //    if (i % 3 == 0) {
    //        std::cout << std::endl;
    //    }
    //    std::cout << vertices[i] << " ";
    //}

}

void MultMatrices6(float* mMatrix, float* vertices, int numVertices) {

    for (int i = 0, k = 0; i < numVertices; i++, k += 6) {
        float vector[3];
        for (int j = 0; j < 3; j++) {
            vector[j] = vertices[j + k];
        }

        for (int l = 0, aux = 0; l < 3; l++, aux += 3) {
            float auxVertices = 0;
            for (int m = 0; m < 3; m++) {
                auxVertices += mMatrix[aux + m] * vector[m];
            }
            vertices[l + k] = auxVertices;
        }

    }

    //for (int i = 0; i < numVertices * 6; i++) {
    //    if (i % 6 == 0) {
    //        std::cout << std::endl;
    //    }
    //    std::cout << vertices[i] << " ";
    //}

}


void MultMatrices9(float* mMatrix, vector<float>& vertices, int numVertices) {
    for (int i = 0, k = 0; i < numVertices; i++, k += 6) {
        float vector[3];
        for (int j = 0; j < 3; j++) {
            vector[j] = vertices[j + k];
        }

        for (int l = 0, aux = 0; l < 3; l++, aux += 3) {
            float auxVertices = 0;
            for (int m = 0; m < 3; m++) {
                auxVertices += mMatrix[aux + m] * vector[m];
            }
            vertices[l + k] = auxVertices;
        }
    }
}

//VECTORES

float norma(float* vector, int dim) {
    float aux = 0.0f;
    for (int i = 0; i < dim; i++) {
        aux += vector[i] * vector[i];
    }
    return sqrt(aux);
}

void mover(float* vertices, float* dir, int v) {
    // normalizar
    float normaV = norma(dir, 3);
    for (int i = 0; i < 3; i++) {
        dir[i] = dir[i] / normaV;
    }

    //Multiplicar por K
    float k = 0.1f;
    for (int i = 0; i < 3; i++) {
        dir[i] = dir[i] * k;
    }

    for (int i = 0; i < v * 3; i++) {
        vertices[i] += dir[i % 3];
    }

}

//void moverRandom(float* vertices, int v) {
//    float RandomVector[3];
//    for (int i = 0; i < 3; i++) {
//        RandomVector[i] = (rand() % 10) - (rand() % 8);
//    }
//
//    // normalizar
//    float normaV = norma(RandomVector, 3);
//    for (int i = 0; i < 3; i++) {
//        RandomVector[i] = RandomVector[i] / normaV;
//    }
//
//    //Multiplicar por K
//    float k = 0.1f;
//    for (int i = 0; i < 3; i++) {
//        RandomVector[i] = RandomVector[i] * k;
//    }
//
//    for (int i = 0; i < v * 3; i++) {
//        vertices[i] += RandomVector[i % 3];
//    }
//
//}
