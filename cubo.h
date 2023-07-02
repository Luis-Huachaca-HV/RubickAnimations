
#include <vector>
#include <map>
#include <iostream>
#include <math.h>

#include "Matrices.h"
#include "Shaders/shader_s.h"
using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include "Shaders/shader_s.h"

using namespace std;

class Cubo {
public:

    vector<float> cubel;
    unsigned int VAO, VBO, EBO;
    vector<float> Centro;
    float x_,y_,z_;
     int debug = 0;
    // glm::mat4 model;

    Cubo(float x, float y, float z, float tam) {
       
        Centro.push_back(x);
        Centro.push_back(y);
        Centro.push_back(z);

       
        
        tam = tam / 2;
        vector<float>  R{ 1.0f, 0.0f, 0.0f }; //F
        vector<float>  O{ 1.0f, 0.5f, 0.0f }; //B
        vector<float>  B{ 0.0f, 0.0f, 1.0f }; //U
        vector<float>  G{ 0.0f, 1.0f, 0.0f }; //D
        vector<float>  Y{ 1.0f, 1.0f, 0.0f }; //R
        vector<float>  W{ 1.0f, 1.0f, 1.0f }; //L

        // vector<vector<float>> color{ R, O, B, G, Y, W };
         vector<vector<float>> color{ B, R, O, G, Y, W };

        vector<vector<float>> coord{
            {x - tam,  y + tam, z + tam}, //0
            {x + tam,  y + tam, z + tam}, //1
            {x - tam,  y - tam, z + tam}, //2
            {x + tam,  y - tam, z + tam}, //3
            {x - tam,  y + tam, z - tam}, //4
            {x + tam,  y + tam, z - tam}, //5
            {x - tam,  y - tam, z - tam}, //6
            {x + tam,  y - tam, z - tam}, //7
        };
        vector<int> point{
            0,1,2,3, //R
            4,5,6,7, //O
            4,5,0,1, //B
            6,7,2,3, //G
            1,5,3,7, //Y
            4,0,6,2, //W
        };


        for (int i = 0; i < 6;) {
            for (int j = 0; j < 4; j++) {
                vector<float>::iterator it = cubel.end();
                cubel.insert(it, coord[point[(i * 4) + j]].begin(), coord[point[(i * 4) + j]].end());
                it = cubel.end();
                cubel.insert(it, color[i].begin(), color[i].end());
            }
            i++;
        }
    }

    Cubo(float x, float y, float z, float tam, vector<bool> bCol, char centerColor) {
        // model = glm::mat4(1.0f);
        tam = tam / 2;
        vector<float>  R{ 1.0f, 0.0f, 0.0f }; //F
        vector<float>  O{ 1.0f, 0.5f, 0.0f }; //B
        vector<float>  B{ 0.0f, 0.0f, 1.0f }; //U
        vector<float>  G{ 0.0f, 1.0f, 0.0f }; //D
        vector<float>  Y{ 1.0f, 1.0f, 0.0f }; //R
        vector<float>  W{ 1.0f, 1.0f, 1.0f }; //L
        vector<float>  a{ 0.0f, 0.0f, 0.0f };

        map<char,vector<vector<float>>> colorPatron;

        colorPatron['R'] = { R, O, B, G, Y, W, a };
        colorPatron['O'] = { O, R, B, G, W, Y, a };
        colorPatron['B'] = { B, G, O, R, Y, W, a };
        colorPatron['G'] = { G, B, R, O, Y, W, a };
        colorPatron['Y'] = { Y, W, B, G, O, R, a };
        colorPatron['W'] = { W, Y, B, G, R, O, a };


        // vector<vector<float>> color{ R, O, B, G, Y, W,a };
        vector<vector<float>> color = colorPatron[centerColor];

        vector<vector<float>> coord{
            {x - tam,  y + tam, z + tam}, //0
            {x + tam,  y + tam, z + tam}, //1
            {x - tam,  y - tam, z + tam}, //2
            {x + tam,  y - tam, z + tam}, //3
            {x - tam,  y + tam, z - tam}, //4
            {x + tam,  y + tam, z - tam}, //5
            {x - tam,  y - tam, z - tam}, //6
            {x + tam,  y - tam, z - tam}, //7
        };
        vector<int> point{
            0,1,2,3, //R
            4,5,6,7, //O
            4,5,0,1, //B
            6,7,2,3, //G
            1,5,3,7, //Y
            4,0,6,2, //W
        };

        //vector<float> cubel;
        for (int i = 0; i < 6;) {
            for (int j = 0; j < 4; j++) {
                vector<float>::iterator it = cubel.end();
                cubel.insert(it, coord[point[(i * 4) + j]].begin(), coord[point[(i * 4) + j]].end());
                it = cubel.end();
                if (bCol[i])
                    cubel.insert(it, color[i].begin(), color[i].end());
                else
                    cubel.insert(it, color[6].begin(), color[6].end());
            }
            i++;
        }

        // cout<<"\ncubel init: \n";
        // for(int i=0;i<cubel.size();i++){
        //     cout<<cubel[i]<<" ";
        // }
    }

    void init2() {

        unsigned int indices[] = {
            0,1,2, //R
            1,2,3, //
            4,5,6, //O
            5,6,7, //
            8,9,10, //B
            9,10,11, //
            12,13,14, //G
            13,14,15, //
            16,17,18, //Y
            17,18,19, //
            20,21,22, //W
            21,22,23 //
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, cubel.size() * sizeof(float), &cubel[0], GL_STATIC_DRAW); // Cambio

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        //pos
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        //color
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void dibujar2(Shader OurShader) {
        OurShader.use();
        glm::mat4 model = glm::mat4(1.0f);
        OurShader.setMat4("model", model);
        glBindVertexArray(this->VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    }



    // void rotar1(float x,float y,float z){
    //      cout<<"\nMultiplicacion\n";

    //    MultMatrices9(Matrix, this->cubel, cubel.size() / 6);

    //    float traslacion[] ={
    //     1.0f, 0.0f, 0.0f, ,
    //     0.0f, 1.0f, 0.0f, 0.0f,
    //     0.0f, 0.0f, 1.0f, 0.0f,
    //     };

    //    MultMatrices99(traslacion, this->cubel, cubel.size() / 6);
    // }


    void rotar(float* Matrix) {

        /*cout << "1" << endl;

        for (int i = 0, j = 1; i < cubel.size(); i++, j++) {
            cout << cubel[i] << " , ";
            if (j % 6 == 0) {
                cout << endl;
            }
        }*/

       // cout << "------------------------------------------------" << endl;;
    //    cout<<"\nMultiplicacion\n";

       

        
       float identidad[] ={
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        };

        identidad[3] = -x_; 
        identidad[7] = -y_;
        identidad[11] = -z_;

        // Traslacion(identidad,this->cubel, cubel.size()/6);

        for (int i = 0; i < cubel.size();i+=6) {
            cubel[i+0] -=x_;
            cubel[i+1] -=y_;
            cubel[i+2] -=z_;
        }


        MultMatrices9(Matrix, this->cubel, cubel.size() / 6);


        for (int i = 0; i < cubel.size();i+=6) {
            cubel[i+0] +=x_;
            cubel[i+1] +=y_;
            cubel[i+2] +=z_;
        }
  

        // Traslacion(identidad,this->cubel, cubel.size()/6);

    //    MultMatrices99(traslacion, this->cubel, cubel.size() / 6);

        // if( debug < 1){
        //      MultMatrices99(Matrix, this->cubel, cubel.size() / 6);
        // }else{
        //     MultMatrices9(Matrix, this->cubel, cubel.size() / 6);
        // }



        // glm::vec3 center(0,0,0);
        // glm::vec3 center(x_,y_,z_);
        // model = glm::translate(model, -center);

        // // Realizar la rotación horizontal en funcion al centro dado 
        // glm::mat4 Rotation = glm::rotate(glm::mat4(1.0f), theta, glm::vec3(0.0f, 0.0f, 1.0f));
        // model = Rotation * model;

        // // Regresar a la posición original
        // model = glm::translate(model, center);
      

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, cubel.size() * sizeof(float), &cubel[0], GL_STATIC_DRAW);

        /*for (int i = 0, j = 1; i < cubel.size(); i++, j++) {
            cout << cubel[i] << " , ";
            if (j % 6 == 0) {
                cout << endl;
            }
        } */   
        // debug++;
    }

    //vector<vector<float>> rotacionX(int a) {
    //    float ang = a * PI / 180; // modificar angulo(sexagesimales)
    //    vector<vector<float>> aux = {
    //        {cos(ang),sin(ang),0},
    //        {-sin(ang),cos(ang),0},
    //        {0,0,1},
    //    };
    //    return aux;
    //}
    //void MultMat3(vector<float>& vec, vector<vector<float>> mat) {
    //    for (int i = 0; i < vec.size(); i++) { // 4 vecs
    //        if (i % 6 == 0) cout << endl;
    //        cout << "," << vec[i];
    //    }
    //    cout << "Proc" << endl;
    //    for (int i = 0; i < vec.size(); i += 6) { // 4 vecs
    //        for (int j = 0; j < mat.size(); j++) {
    //            float aux = 0;
    //            for (int k = 0; k < mat.size(); k++) {
    //                //if ((i + k) % 3 == 2) { vec[i + k] = 1.0; } // paso innecesario?
    //                aux += mat[j][k] * vec[i + k];
    //            }
    //            //cout << "," << vec[i + j] << "->";
    //            vec[i + j] = aux;
    //            //cout << ","<< vec[i + j] <<endl;
    //        }
    //    }
    //    for (int i = 0; i < vec.size(); i++) { // 4 vecs
    //        if (i % 6 == 0) cout << endl;
    //        cout << "," << vec[i];
    //    }
    //    cout << endl;
    //}
    //void Rotar(int orientacion) {
    //    vector<vector<float>> giro;
    //    if (orientacion == 0)
    //        giro = rotacionX(45);
    //    if (orientacion == 1)
    //        giro = rotacionX(-90);
    //    MultMat3(cubel, giro);
    //}
    
    vector<float> getCenter() {
        
        return Centro;
    }
};


class cuboRubik {
    public:
    vector<int> cOri;
    vector<int> eOri;
    float theta = -5*(PI/180) ;

    float Ry[sizeof(_Ry) / sizeof(_Ry[0])];
    float RyI[sizeof(_RyI) / sizeof(_RyI[0])];
    float Ry2[sizeof(_Ry2) / sizeof(_Ry2[0])];
    float Ry2I[sizeof(_Ry2I) / sizeof(_Ry2I[0])];

    float Rx[sizeof(_Rx) / sizeof(_Rx[0])];
    float RxI[sizeof(_RxI) / sizeof(_RxI[0])];
    float Rx2[sizeof(_Rx2) / sizeof(_Rx2[0])];
    float Rx2I[sizeof(_Rx2I) / sizeof(_Rx2I[0])];

    float Rz[sizeof(_Rz) / sizeof(_Rz[0])];
    float RzI[sizeof(_RzI) / sizeof(_RzI[0])];
    float Rz2[sizeof(_Rz2) / sizeof(_Rz2[0])];
    float Rz2I[sizeof(_Rz2I) / sizeof(_Rz2I[0])];

    vector<Cubo*> C;
    enum corner { ufl, urf, dlf, dfr, ulb, ubr, dbl, drb}; //0-8
    enum edge { uf, fl, fr, df, ul, ur, dl, dr, ub, bl, br, db };
    //corner cPos[8] = { urf, ubr, dlf, dfr, ulb, ufl, drb, dbl };
    

    vector< vector<int>> camadas{
        {0,1,2,3,4,5,6,7,8},          //F
        {18,19,20,21,22,23,24,25,26}, //B
        {18,19,20,9,10,11,0,1,2},     //U
        {24,25,26,15,16,17,6,7,8},    //D
        {2,5,8,11,14,17,20,21,22},    //R
        {0,3,6,9,12,15,18,21,24}      //L
    };
    vector< vector<corner>> camadasC{
        {ufl,urf,dlf,dfr}, //F
        {ulb,ubr,dbl,drb}, //B
        {ufl,urf,ulb,ubr}, //U
        {dlf,dfr,dbl,drb}, //D
        {urf,dfr,ubr,drb}, //R
        {ufl,dlf,ulb,dbl}  //L
    };
     vector< vector<edge>> camadasE{
        {uf,fl,fr,df}, //F
        {ub,bl,br,db}, //B
        {uf,ul,ur,ub}, //U
        {df,dl,dr,db}, //D
        {fr,ur,dr,br}, //R
        {fl,ul,dl,bl}  //L
    };
    
    cuboRubik(float x, float y, float z, char centerColor='R') {
        cOri = { 0,2,6,8,17,19,23,25 };
        eOri = { 1,3,5,7,9,11,14,16,18,20,22,24 };

        ///////////////////////////////
    
        std::copy(std::begin(_Ry), std::end(_Ry), Ry);
        std::copy(std::begin(_RyI), std::end(_RyI), RyI);
        std::copy(std::begin(_Ry2), std::end(_Ry2), Ry2);
        std::copy(std::begin(_Ry2I), std::end(_Ry2I), Ry2I);
        std::copy(std::begin(_Rx), std::end(_Rx), Rx);
        std::copy(std::begin(_RxI), std::end(_RxI), RxI);
        std::copy(std::begin(_Rx2), std::end(_Rx2), Rx2);
        std::copy(std::begin(_Rx2I), std::end(_Rx2I), Rx2I);
        std::copy(std::begin(_Rz), std::end(_Rz), Rz);
        std::copy(std::begin(_RzI), std::end(_RzI), RzI);
        std::copy(std::begin(_Rz2), std::end(_Rz2), Rz2);
        std::copy(std::begin(_Rz2I), std::end(_Rz2I), Rz2I);

//         ////////////////////////////////
        
        vector<vector<float>> centers{
            //Front
            {-0.5f, 0.5f, 0.5f}, //0  ufl
            { 0.0f, 0.5f, 0.5f}, //1  uf
            { 0.5f, 0.5f, 0.5f}, //2  urf
            {-0.5f, 0.0f, 0.5f}, //3  fl  
            { 0.0f, 0.0f, 0.5f}, //4  RED
            { 0.5f, 0.0f, 0.5f}, //5  fr
            {-0.5f, -0.5f, 0.5f}, //6 dlf
            { 0.0f, -0.5f, 0.5f}, //7 df
            { 0.5f, -0.5f, 0.5f}, //8 dfr
            //Mid
            {-0.5f, 0.5f, 0.0f}, //9  ul
            { 0.0f, 0.5f, 0.0f}, //10 BLUE
            { 0.5f, 0.5f, 0.0f}, //11 ur
            {-0.5f, 0.0f, 0.0f}, //12  WHITE
            //{ 0.0f, 0.0f, 0.0f}, //13
            { 0.5f, 0.0f, 0.0f}, //13 YELLOW
            {-0.5f, -0.5f, 0.0f}, //14  dl
            { 0.0f, -0.5f, 0.0f}, //15 GREEN
            { 0.5f, -0.5f, 0.0f}, //16  dr
             //Back
            {-0.5f, 0.5f, -0.5f}, //17  ulb
            { 0.0f, 0.5f, -0.5f}, //18  ub
            { 0.5f, 0.5f, -0.5f}, //19 ubr
            {-0.5f, 0.0f, -0.5f}, //20  bl
            { 0.0f, 0.0f, -0.5f}, //21 ORANGE
            { 0.5f, 0.0f, -0.5f}, //22  br
            {-0.5f, -0.5f, -0.5f}, //23  dbl
            { 0.0f, -0.5f, -0.5f}, //24  db
            { 0.5f, -0.5f, -0.5f} //25  drb
        };
        vector<vector<bool>> color{
            //Front
            {1,0,1,0,0,1}, //0
            {1,0,1,0,0,0}, //1
            {1,0,1,0,1,0}, //2
            {1,0,0,0,0,1}, //3
            {1,0,0,0,0,0}, //4
            {1,0,0,0,1,0}, //5
            {1,0,0,1,0,1}, //6
            {1,0,0,1,0,0}, //7
            {1,0,0,1,1,0}, //8
            //Mid
            {0,0,1,0,0,1}, //9
            {0,0,1,0,0,0}, //10
            {0,0,1,0,1,0}, //11
            {0,0,0,0,0,1}, //12
            //{0,0,0,0,0,0}, //13
            {0,0,0,0,1,0}, //14
            {0,0,0,1,0,1}, //15
            {0,0,0,1,0,0}, //16
            {0,0,0,1,1,0}, //17
             //Back
            {0,1,1,0,0,1}, //18
            {0,1,1,0,0,0}, //19
            {0,1,1,0,1,0}, //20
            {0,1,0,0,0,1}, //21
            {0,1,0,0,0,0}, //22
            {0,1,0,0,1,0}, //23
            {0,1,0,1,0,1}, //24
            {0,1,0,1,0,0}, //25
            {0,1,0,1,1,0}, //26
        };
        for (int j = 0; j < centers.size(); j++) {
            C.push_back(new Cubo(centers[j][0]+x, centers[j][1]+y, centers[j][2]+z, 0.47f, color[j], centerColor));
            C[j]->x_ = x;
            C[j]->y_ = y;
            C[j]->z_ = z;


            if(j == 4){
                
                cout<<"\ncubel init con theta: "<<this->theta<<" \n";

                for(int i=0;i<C[4]->cubel.size();i++){
                    if(i % 6 == 0) cout<<"\n";
                    cout<<C[4]->cubel[i]<<" ";
                }
            }
        };
    }


    
    std::vector<std::vector<float>> movePoints(float x, float y, float z) {
    
        for(int j = 0; j < C.size();j++){
            C[j]->Centro[0] += x;
            C[j]->Centro[1] += y;
            C[j]->Centro[2] += z;
        }
 
    }

    ~cuboRubik() {
        cout<< "Why\n";
    }

    void init() {
        for (int i = 0; i < C.size(); i++) {
            C[i]->init2();
        }
    }

    void dibujar(Shader OurShader) {

        for (int i = 0; i < C.size(); i++) {
            glBindVertexArray((C[i])->VAO);
            C[i]->dibujar2(OurShader);
        }
    }

    void Up(bool p,int val) {
        //theta = -theta;
     
        if (!p) {
            C[10]->rotar(Ry); // BLUE
            for (int i = 0; i < camadasC[2].size(); i++) {
                //cout << "camadas: " << camadasC[2][i] << "  " << i << ": " << cOri[camadasC[2][i]] << " , ";
                C[cOri[camadasC[2][i]]]->rotar(Ry);
            }
            for (int i = 0; i < camadasE[2].size(); i++) {
                C[eOri[camadasE[2][i]]]->rotar(Ry);
            }
            //cout << "Time2" << endl;
        }
        else {
         

            int tOri = cOri[urf];
            cOri[urf] = cOri[ubr];
            cOri[ubr] = cOri[ulb];
            cOri[ulb] = cOri[ufl];
            cOri[ufl] = tOri;

            tOri = eOri[ub];
            eOri[ub] = eOri[ul];
            eOri[ul] = eOri[uf];
            eOri[uf] = eOri[ur];
            eOri[ur] = tOri;
            


        }

       
    }

    
    void UpI(bool p,int val) {
        //theta = -theta;
        //cout << "theta : " <<theta << endl;
        if (!p) {
            C[10]->rotar(RyI); // BLUE
            for (int i = 0; i < camadasC[2].size(); i++) {
                //cout << "camadas: " << camadasC[2][i] << "  " << i << ": " << cOri[camadasC[2][i]] << " , ";
                C[cOri[camadasC[2][i]]]->rotar(RyI);
            }
            for (int i = 0; i < camadasE[2].size(); i++) {
                C[eOri[camadasE[2][i]]]->rotar(RyI);
            }
            //cout << "Time2" << endl;
        }
        else {
           

            int tOri = eOri[ur];
            eOri[ur] = eOri[uf];
            eOri[uf] = eOri[ul];
            eOri[ul] = eOri[ub];
            eOri[ub] = tOri;

            tOri = cOri[ufl];
            cOri[ufl] = cOri[ulb];
            cOri[ulb] = cOri[ubr];
            cOri[ubr] = cOri[urf];
            cOri[urf] = tOri;

        }

       
    }

    void updateAccordingRoutine(string routine){
        for(int i =0; i < routine.size(); i++){
            routine[i];
        }
    }

    void Down(bool p, int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[15]->rotar(Ry2); // GREEN
            for (int i = 0; i < camadasC[3].size(); i++) {
                //cout << "camadas: " << camadasC[3][i] << "  " << i << ": " << cOri[camadasC[3][i]] << " , ";
                C[cOri[camadasC[3][i]]]->rotar(Ry2);
            }
            for (int i = 0; i < camadasE[3].size(); i++) {
                C[eOri[camadasE[3][i]]]->rotar(Ry2);
            }
        }
        else {
            char tOri = cOri[dfr];
            cOri[dfr] = cOri[dlf];
            cOri[dlf] = cOri[dbl];
            cOri[dbl] = cOri[drb];
            cOri[drb] = tOri;

            tOri = eOri[df];
            eOri[df] = eOri[dl];
            eOri[dl] = eOri[db];
            eOri[db] = eOri[dr];
            eOri[dr] = tOri;
        }

    }

    void DownI(bool p, int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[15]->rotar(Ry2I); // GREEN
            for (int i = 0; i < camadasC[3].size(); i++) {
                //cout << "camadas: " << camadasC[3][i] << "  " << i << ": " << cOri[camadasC[3][i]] << " , ";
                C[cOri[camadasC[3][i]]]->rotar(Ry2I);
            }
            for (int i = 0; i < camadasE[3].size(); i++) {
                C[eOri[camadasE[3][i]]]->rotar(Ry2I);
            }
        }
        else {
            char tOri = eOri[dr];
            eOri[dr] = eOri[db];
            eOri[db] = eOri[dl];
            eOri[dl] = eOri[df];
            eOri[df] = tOri;

            tOri = cOri[drb];
            cOri[drb] = cOri[dbl];
            cOri[dbl] = cOri[dlf];
            cOri[dlf] = cOri[dfr];
            cOri[dfr] = tOri;


        }

    }


    
    void Rigth(bool p,int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[13]->rotar(Rx); // YELL
            for (int i = 0; i < camadasC[4].size(); i++) {
                //cout << "camadas: " << camadasC[4][i] << "  " << i << ": " << cOri[camadasC[4][i]] << " , ";
                C[cOri[camadasC[4][i]]]->rotar(Rx);
            }
            for (int i = 0; i < camadasE[4].size(); i++) {
                C[eOri[camadasE[4][i]]]->rotar(Rx);
            }
        }
        else {
           

                char tOri = cOri[urf];
                cOri[urf] = cOri[dfr];
                cOri[dfr] = cOri[drb];
                cOri[drb] = cOri[ubr];
                cOri[ubr] = tOri;

                tOri = eOri[fr];
                eOri[fr] = eOri[dr];
                eOri[dr] = eOri[br];
                eOri[br] = eOri[ur];
                eOri[ur] = tOri;

           
        }

      

    }

    void RigthI(bool p,int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[13]->rotar(RxI); // YELL
            for (int i = 0; i < camadasC[4].size(); i++) {
                //cout << "camadas: " << camadasC[4][i] << "  " << i << ": " << cOri[camadasC[4][i]] << " , ";
                C[cOri[camadasC[4][i]]]->rotar(RxI);
            }
            for (int i = 0; i < camadasE[4].size(); i++) {
                C[eOri[camadasE[4][i]]]->rotar(RxI);
            }
        }
        else {
           

                char tOri = eOri[ur];
                eOri[ur] = eOri[br];
                eOri[br] = eOri[dr];
                eOri[dr] = eOri[fr];
                eOri[fr] = tOri;

                tOri = cOri[ubr];
                cOri[ubr] = cOri[drb];
                cOri[drb] = cOri[dfr];
                cOri[dfr] = cOri[urf];
                cOri[urf] = tOri;



        }

      

    }

    void Left(bool p, int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[12]->rotar(Rx2); // BLUE
            for (int i = 0; i < camadasC[5].size(); i++) {
                //cout << "camadas: " << camadasC[5][i] << "  " << i << ": " << cOri[camadasC[5][i]] << " , ";
                C[cOri[camadasC[5][i]]]->rotar(Rx2);
            }
            for (int i = 0; i < camadasE[5].size(); i++) {
                C[eOri[camadasE[5][i]]]->rotar(Rx2);
            }
        }
        else {
            int tOri = cOri[dlf];
            cOri[dlf] = cOri[ufl];
            cOri[ufl] = cOri[ulb];
            cOri[ulb] = cOri[dbl];
            cOri[dbl] = tOri;

            tOri = eOri[bl];
            eOri[bl] = eOri[dl];
            eOri[dl] = eOri[fl];
            eOri[fl] = eOri[ul];
            eOri[ul] = tOri;
        }
    }

    void LeftI(bool p, int val) {
        this->theta = this->theta * val;
        if (!p) {
            C[12]->rotar(Rx2I); // BLUE
            for (int i = 0; i < camadasC[5].size(); i++) {
                //cout << "camadas: " << camadasC[5][i] << "  " << i << ": " << cOri[camadasC[5][i]] << " , ";
                C[cOri[camadasC[5][i]]]->rotar(Rx2I);
            }
            for (int i = 0; i < camadasE[5].size(); i++) {
                C[eOri[camadasE[5][i]]]->rotar(Rx2I);
            }
        }
        else {
            int tOri = eOri[ul];
            eOri[ul] = eOri[fl];
            eOri[fl] = eOri[dl];
            eOri[dl] = eOri[bl];
            eOri[bl] = tOri;

            tOri = cOri[dbl];
            cOri[dbl] = cOri[ulb];
            cOri[ulb] = cOri[ufl];
            cOri[ufl] = cOri[dlf];
            cOri[dlf] = tOri;


        }
    }

    void Front(bool p,int val) {
        // theta = theta * val;
        this->theta = this->theta * val;
        if (!p) {
            C[4]->rotar(Rz); // RED

            // int index = eOri[camadasE[0][0]];
            int index = 4;
            // C[index]->rotar(Rz);
            cout<<"\ncubel rotado con theta: "<<theta<<" \n";
            for(int i=0;i<C[index]->cubel.size();i++){
                    if(i % 6 == 0) cout<<"\n";
                    cout<<C[index]->cubel[i]<<" ";
            }

            for (int i = 0; i < camadasC[0].size(); i++) {
                C[cOri[camadasC[0][i]]]->rotar(Rz);
            }
            for (int i = 0; i < camadasE[0].size(); i++) {
                C[eOri[camadasE[0][i]]]->rotar(Rz);
            }
        }
        else {
            int tOri = cOri[urf];
            cOri[urf] = cOri[ufl];
            cOri[ufl] = cOri[dlf];
            cOri[dlf] = cOri[dfr];
            cOri[dfr] = tOri;

            tOri = eOri[uf];
            eOri[uf] = eOri[fl];
            eOri[fl] = eOri[df];
            eOri[df] = eOri[fr];
            eOri[fr] = tOri;
        }
    }

    void FrontI(bool p,int val) {
        // theta = theta * val;
        this->theta = this->theta * val;
        if (!p) {
            C[4]->rotar(RzI); // RED
            for (int i = 0; i < camadasC[0].size(); i++) {
                C[cOri[camadasC[0][i]]]->rotar(RzI);
            }
            for (int i = 0; i < camadasE[0].size(); i++) {
                C[eOri[camadasE[0][i]]]->rotar(RzI);
            }
        }
        else {
            int tOri = eOri[fr];
            eOri[fr] = eOri[df];
            eOri[df] = eOri[fl];
            eOri[fl] = eOri[uf];
            eOri[uf] = tOri;

            tOri = cOri[dfr];
            cOri[dfr] = cOri[dlf];
            cOri[dlf] = cOri[ufl];
            cOri[ufl] = cOri[urf];
            cOri[urf] = tOri;


        }
    }

    void Back(bool p,int val) {
        // theta = theta * val;
        this->theta = this->theta * val;
        if (!p) {
            C[21]->rotar(Rz2); // ORA
            for (int i = 0; i < camadasC[1].size(); i++) {
                C[cOri[camadasC[1][i]]]->rotar(Rz2);
            }
            for (int i = 0; i < camadasE[1].size(); i++) {
                C[eOri[camadasE[1][i]]]->rotar(Rz2);
            }
        }
        else {
            int tOri = cOri[ulb];
            cOri[ulb] = cOri[ubr];
            cOri[ubr] = cOri[drb];
            cOri[drb] = cOri[dbl];
            cOri[dbl] = tOri;

            tOri = eOri[br];
            eOri[br] = eOri[db];
            eOri[db] = eOri[bl];
            eOri[bl] = eOri[ub];
            eOri[ub] = tOri;
        }

    }

    void BackI(bool p,int val) {
        // theta = theta * val;
        this->theta = this->theta * val;
        if (!p) {
            C[21]->rotar(Rz2I); // ORA
            for (int i = 0; i < camadasC[1].size(); i++) {
                C[cOri[camadasC[1][i]]]->rotar(Rz2I);
            }
            for (int i = 0; i < camadasE[1].size(); i++) {
                C[eOri[camadasE[1][i]]]->rotar(Rz2I);
            }
        }
        else {
            int tOri = eOri[ub];
            eOri[ub] = eOri[bl];
            eOri[bl] = eOri[db];
            eOri[db] = eOri[br];
            eOri[br] = tOri;

            tOri = cOri[dbl];
            cOri[dbl] = cOri[drb];
            cOri[drb] = cOri[ubr];
            cOri[ubr] = cOri[ulb];
            cOri[ulb] = tOri;

        }

    }
 

    //void dibujarCamada(int a) {
    //    vector<int> cam = camadas[a];
    //    for (int i = 0; i < cam.size(); i++) {
    //        glBindVertexArray((C[cam[i]])->VAO);
    //        C[cam[i]]->dibujar2();
    //    }
    //}

    //void Rotar(int a) {
    //    vector<int> cam = camadas[0];
    //    for (int i = 0; i < cam.size(); i++) {
    //        //glBindVertexArray((C[cam[0]])->VAO);
    //        C[cam[i]]->Rotar(a);
    //    }
    //}

    void deleteCubo() {
        for (int i = 0; i < C.size(); i++) {
            glDeleteVertexArrays(1, &C[i]->VAO);
            glDeleteBuffers(1, &C[i]->VBO);
        }
    }
};