#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unistd.h>
#include "cubo.h"
#include <functional>
#include <chrono>
#include <thread>
#include "learnopengl/shader_m.h"
#include "learnopengl/camera.h"
// #include "../../../../grafica/Rubik/CubeSolver-Master/CubeSolver-Master/Headers/Header.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random> 

using namespace std;

const char* vertex_shader_text =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
    "    ourColor = aColor;\n"
    "}\n";

const char* fragment_shader_text =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(ourColor, 1.0);\n"
    "}\n";
const char* light_cubevs =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
    "    ourColor = aColor;\n"
    "}\n";

const char* light_cubefs = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0);\n"
    "}\n";

const char* basic_lightingvs = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aNormal;\n"
    "layout (location = 2) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "out vec3 FragPos;\n"
    "out vec3 Normal;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    " FragPos = vec3(model * vec4(aPos, 1.0));\n"
    " Normal = mat3(transpose(inverse(model))) * aNormal;\n"
    " gl_Position = projection * view * vec4(FragPos, 1.0);\n"
    " ourColor = aColor;\n"

    "}\n";

const char* basic_lightingfs = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 Normal;\n"
    "in vec3 FragPos;\n"
    "uniform vec3 lightPos;\n"
    "uniform vec3 viewPos;\n"
    "uniform vec3 lightColor;\n"
    "uniform vec3 objectColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    " float ambientStrength = 0.1;\n"
    " vec3 ambient = ambientStrength * lightColor;\n"
    " vec3 norm = normalize(Normal);\n"
    " vec3 lightDir = normalize(lightPos - FragPos);\n"
    " float diff = max(dot(norm, lightDir), 0.0);\n"
    " vec3 diffuse = diff * lightColor;\n"
    " float specularStrength = 0.5;\n"
    " vec3 viewDir = normalize(viewPos - FragPos);\n"
    " vec3 reflectDir = reflect(-lightDir, norm);\n"
    " float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
    " vec3 specular = specularStrength * spec * lightColor;\n"
    " vec3 result = (ambient + diffuse + specular) * ourColor;\n"
    " FragColor = vec4(result, 1.0);\n"
    "}\n";
////############## CLASS STATE //////////////////////

class VirtualRubik{
public:

    char modoSolucion;
    char modoRotacion;
    string modoTraslacion;
    float traslationSpeed;
    int rotloop;
    int trasloop;
    string pasoslib;
    int iter ;
    // float theta;
    int delta;
    vector<string> pasos_solu;
    vector<string> mosaicMoves;
    cuboRubik* Cubo;
    Shader* ourShader;

    float theta = -5*(PI/180) ;
    // float thetaI = 5*(PI/180) ;


    VirtualRubik(float x, float y, float z, char centerColor){

        random_device rd;                    // Crea un generador de números aleatorios basado en hardware
        mt19937 gen(rd());                   // Inicializa el generador utilizando la semilla rd
        uniform_int_distribution<int> dis(10, 100);  // Define una distribución uniforme de enteros entre 10 y 100
        delta = dis(gen);    


        // theta = -5*(PI/180) ;
        modoSolucion = 'n';
        modoRotacion = 'n';
        modoTraslacion = "n";
        rotloop = 90;
        trasloop = delta;
        string pasoslib = "";
        Cubo = new cuboRubik(x,y,z,centerColor);
        iter = 0 ;
        // ourShader = ourShader_;
        Cubo->init();
    }

    void trasladar(float x,float y,float z){
        Cubo->trasladar(x,y,z);
    }

    void setMosaicPatron(vector<string> mosaicMoves_){

        for(const auto& action : mosaicMoves_){
            mosaicMoves.push_back(action);
        }
    }

    void draw(Shader ourShader){
        Cubo->dibujar(ourShader);
    }

    //traslations
    void trasladarZPos(){
        cout<<"\ntrasz+";
        trasloop -= 1; 
        Cubo->trasladar(0,0,0.1); // 0.1 speed
        if(trasloop == 0){
            trasloop = delta;
            modoTraslacion = 'n';
        }
    }
    void trasladarZNeg(){
        cout<<"\ntrasz-";
        trasloop -= 1; 
        Cubo->trasladar(0,0,-0.1); // 0.1 speed
        if(trasloop == 0){
            trasloop = delta;
            modoTraslacion = 'n';
        }
    }

    // Rotations
    void rotarUp()
    {
        rotloop -= 5;
        Cubo->Up(0, 1);
        // cout << "theta u: " <<theta << endl;
        Cubo->theta = -5 * (PI / 180);

        if (rotloop == 0)
        {
            Cubo->Up(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarUpInv()
    {
        rotloop -= 5;
        // cout << "theta ui: " <<theta << endl;
        Cubo->theta = 5 * (PI / 180);

        Cubo->UpI(0, -1);
        if (rotloop == 0)
        {
            Cubo->UpI(1, -1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarDown()
    {
        rotloop -= 5;
        Cubo->Down(0, 1);
        if (rotloop == 0)
        {
            Cubo->Down(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarDownI()
    {
        rotloop -= 5;
        Cubo->DownI(0, 1);
        if (rotloop == 0)
        {
            Cubo->DownI(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarRigth()
    {
        rotloop -= 5;
        Cubo->Rigth(0, 1);
        if (rotloop == 0)
        {
            Cubo->Rigth(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarRigthI()
    {
        rotloop -= 5;
        Cubo->RigthI(0, 1);
        if (rotloop == 0)
        {
            Cubo->RigthI(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarLeft()
    {
        rotloop -= 5;
        Cubo->Left(0, 1);
        if (rotloop == 0)
        {
            Cubo->Left(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarLeftI()
    {
        rotloop -= 5;
        Cubo->LeftI(0, 1);
        if (rotloop == 0)
        {
            Cubo->LeftI(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarFront()
    {
        rotloop -= 5;
        Cubo->Front(0, 1);
        if (rotloop == 0)
        {
            Cubo->Front(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarFrontI()
    {
        rotloop -= 5;
        Cubo->FrontI(0, 1);
        if (rotloop == 0)
        {
            Cubo->FrontI(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarBack()
    {
        rotloop -= 5;
        Cubo->Back(0, 1);
        if (rotloop == 0)
        {
            Cubo->Back(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }
    void rotarBackI()
    {
        rotloop -= 5;
        Cubo->BackI(0, 1);
        if (rotloop == 0)
        {
            Cubo->BackI(1, 1);
            rotloop = 90;
            modoRotacion = 'n';
        }
    }

};

////////////////////////////////////////////////////////

// char modoSolucion = 'n';
// char modoRotacion = 'n';
// int rotloop = 90;
// string pasoslib;
// vector<string> pasos_solu;


void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
// settings

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int modoCamara = 0;
bool zoomComplete = false;
float rotationSpeed = 0.55f;
const float cameraSpeed = 0.07f;

bool firstMouse = true;
float yaw = -90.0f; // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

std::vector<std::string> parseMovements(const std::string &input)
{
    std::vector<std::string> movements;
    std::stringstream ss(input);
    std::string movement;

    while (ss >> movement)
    {
        movements.push_back(movement);
    }

    return movements;
}

std::string convertToDoubleMove(const std::string &move)
{
    std::string convertedMove;
    if (move.back() == '2')
    {
        convertedMove = move.substr(0, move.length() - 1) + " " + move.substr(0, move.length() - 1);
    }
    else
    {
        convertedMove = move;
    }
    return convertedMove;
}

std::vector<std::string> convertMoves(const std::string &moves)
{
    std::vector<std::string> convertedMoves;
    std::istringstream iss(moves);
    std::string move;
    while (iss >> move)
    {
        std::string convertedMove = convertToDoubleMove(move);

        // Split the converted move into individual moves
        std::istringstream issSplit(convertedMove);
        std::string singleMove;
        while (issSplit >> singleMove)
        {
            convertedMoves.push_back(singleMove);
        }
    }
    return convertedMoves;
}

/*
void RotationCube(cuboRubik &Cubo, string solvestring){

    for(int i =0; i < solvestring.size(); i++){
        movs[solvestring[i]];
    }
}

void shuffleCube(cuboRubik &Cubo, string shufflestring){

    for(int i =0; i < shufflestring.size(); i++){
        movs[shufflestring[i]];
    }
}
*/
// cuboRubik cubo1(0, 0, 0,'W');
// cuboRubik cubo2(2.0,0,0,'O');


/*cuboRubik cubo3(4.0,0,0);
cuboRubik cubo4(6.0,0,0);
cuboRubik cubo5(-2.0,0,0);
cuboRubik cubo6(-4.0,0,0);
cuboRubik cubo7(-6.0,0,0);
cuboRubik cubo8(0.0,2.0,0);
cuboRubik cubo9(0.0,4.0,0);
cuboRubik cubo10(0.0,6.0,0);
cuboRubik cubo11(0.0,-2.0,0);
cuboRubik cubo12(0.0,-4.0,0);
cuboRubik cubo13(0.0,-6.0,0);*/

// std::map<std::string, std::function<void()>> movs;
std::map<std::string, char> movs;

void initializeMap()
{
    movs["R"] = 'r';
    movs["R'"] = 'h';
    movs["L"] = 'l';
    movs["L'"] = 'k';
    movs["F"] = 'f';
    movs["F'"] = 't';
    movs["B"] = 'b';
    movs["B'"] = 'g';
    movs["U"] = 'u';
    movs["U'"] = 'o';
    movs["D"] = 'd';
    movs["D'"] = 'm';
}
// void initializeMap() {
//     movs["R"] = [&]() { rotarRigth(cubo1); };
//     movs["R'"] = [&]() { rotarRigthI(cubo1); };
//     movs["L"] = [&]() { rotarLeft(cubo1); };
//     movs["L'"] = [&]() { rotarLeftI(cubo1); };
//     movs["F"] = [&]() { rotarFront(cubo1); };
//     movs["F'"] = [&]() { rotarFrontI(cubo1); };
//     movs["B"] = [&]() { rotarBack(cubo1); };
//     movs["B'"] = [&]() { rotarBackI(cubo1); };
//     movs["U"] = [&]() { rotarUp(cubo1); };
//     movs["U'"] = [&]() { rotarUpInv(cubo1); };
//     movs["D"] = [&]() { rotarDown(cubo1); };
//     movs["D'"] = [&]() { rotarDownI(cubo1); };
// }



// mosaic solver

// std::vector<std::vector<std::string>> mosaicMoves(6, std::vector<std::string>(5));
// vector<vector<vector<string>>> mosaicMoves(6, vector<vector<string>>(5));


const int row = 6;
const int col = 5;

vector<VirtualRubik*> Grid(row*col);
vector<bool> animations(Grid.size(),false);

void initGrid(){
    Grid[0] = new VirtualRubik(-3, 3, 0,'W'); //00
    Grid[1] = new VirtualRubik(-1.5, 3, 0,'R'); //01
    Grid[2] = new VirtualRubik(0, 3, 0,'R'); //02
    Grid[3] = new VirtualRubik(1.5, 3, 0,'W'); //03
    Grid[4] = new VirtualRubik(3, 3, 0,'W'); //04

    Grid[5] = new VirtualRubik(-3, 1.5, 0,'W'); //10
    Grid[6] = new VirtualRubik(-1.5, 1.5, 0,'O'); //11
    Grid[7] = new VirtualRubik(0, 1.5, 0,'Y'); //12
    Grid[8] = new VirtualRubik(1.5, 1.5, 0,'Y'); //13
    Grid[9] = new VirtualRubik(3, 1.5, 0,'W'); //14

    Grid[10] = new VirtualRubik(-3, 0, 0,'W'); //20
    Grid[11] = new VirtualRubik(-1.5, 0, 0,'Y'); //21
    Grid[12] = new VirtualRubik(0, 0, 0,'Y'); //22
    Grid[13] = new VirtualRubik(1.5, 0, 0,'W'); //23
    Grid[14] = new VirtualRubik(3, 0, 0,'W'); //24

    Grid[15] = new VirtualRubik(-3, -1.5, 0,'R'); //30
    Grid[16] = new VirtualRubik(-1.5, -1.5, 0,'R'); //31
    Grid[17] = new VirtualRubik(0, -1.5, 0,'B'); //32
    Grid[18] = new VirtualRubik(1.5, -1.5, 0,'R'); //33
    Grid[19] = new VirtualRubik(3, -1.5, 0,'W'); //34

    Grid[20] = new VirtualRubik(-3, -3, 0,'Y'); //40
    Grid[21] = new VirtualRubik(-1.5, -3, 0,'B'); //41
    Grid[22] = new VirtualRubik(0, -3, 0,'B'); //42
    Grid[23] = new VirtualRubik(1.5, -3, 0,'B'); //43
    Grid[24] = new VirtualRubik(3, -3, 0,'W'); //44

    Grid[25] = new VirtualRubik(-3, -4.5, 0,'O'); //50
    Grid[26] = new VirtualRubik(-1.5, -4.5, 0,'O'); //51
    Grid[27] = new VirtualRubik(0, -4.5, 0,'W'); //52
    Grid[28] = new VirtualRubik(1.5, -4.5, 0,'O'); //53
    Grid[29] = new VirtualRubik(3, -4.5, 0,'W'); //54
}

void initializeMosaic()
{
    Grid[0]->setMosaicPatron( {} ); //00
    Grid[1]->setMosaicPatron( { "U'", "B'", "D", "U'", "L", "D'", "U" } ); //01
    Grid[2]->setMosaicPatron( {"U'"} ); //02
    Grid[3]->setMosaicPatron( {"D'"} ); //03
    Grid[4]->setMosaicPatron( {} ); //04

    Grid[5]->setMosaicPatron( {  "B'", "U", "R'", "U'" }); //10
    Grid[6]->setMosaicPatron( { "B'", "U'", "L", "U", "B'", "U", "D'", "R'", "U'", "D" }); //11
    Grid[7]->setMosaicPatron( { "B'", "D'", "R", "D" }); //12
    Grid[8]->setMosaicPatron( { "L", "B'", "L'", "B'", "L", "U", "U", "L'", "B", "B", "U'", "B", "U" } ); //13
    Grid[9]->setMosaicPatron( { "L", "B", "L'", "B", "L", "B'", "L'" } ); //14


    Grid[10]->setMosaicPatron( {} ); //20
    Grid[11]->setMosaicPatron( { "R", "D", "R'", "B", "D", "B", "D'", "U'", "D", "L", "U", "D'", "L'", "B", "L" } ); //21
    Grid[12]->setMosaicPatron( { "B'", "U'", "B", "U", "D", "D", "B'", "B'", "D'", "B", "D", "B'", "D'" }); //22
    Grid[13]->setMosaicPatron( { "U", "U", "L", "L", "U'", "R", "D'", "R'" }); //23
    Grid[14]->setMosaicPatron( {} ); //24

    Grid[15]->setMosaicPatron({ "U", "F'", "L'", "D'", "L", "B'", "R'", "L", "U", "U", "R", "B", "L" }); //30---------
    Grid[16]->setMosaicPatron({ "R'", "B'", "L'", "R", "D'", "L", "R'", "R'", "B", "R" }); //31
    Grid[17]->setMosaicPatron({ "R'", "F'", "L'", "B'", "F", "R" }); //32
    Grid[18]->setMosaicPatron( { "L", "B", "B", "L'", "R'", "B", "R" } ); //33
    Grid[19]->setMosaicPatron( { "B", "U'", "L", "U", "L", "B", "B", "L'" } ); //34

    Grid[20]->setMosaicPatron( { "D", "D", "L", "B", "B", "L", "B'", "L'", "B", "L" }); //40
    Grid[21]->setMosaicPatron( { "L'", "B", "L" } ); //41 ----
    Grid[22]->setMosaicPatron( { "R", "D", "R'" } ); //42
    Grid[23]->setMosaicPatron( { "L", "R'", "U", "U", "R", "U'", "L'", "B'", "U", "R", "R", "U'" } ); //43
    Grid[24]->setMosaicPatron( { "D", "L", "L", "D'", "U'", "L", "U", "L'" } ); //44

    Grid[25]->setMosaicPatron( { "D'", "U", "B", "U'", "D", "L", "D'", "U", "B'", "U'", "B", "U" } ); //50
    Grid[26]->setMosaicPatron( { "B'", "D'", "R" } ); //51 ------
    Grid[27]->setMosaicPatron( {} ); //52
    Grid[28]->setMosaicPatron( { "D'"} ); //53
    Grid[29]->setMosaicPatron( { "B'", "U'", "D", "L", "U", "D'" } ); //54
}


vector<VirtualRubik*> Zpos;
vector<VirtualRubik*> Zneg;

void setTraslationsZpos(vector<int> indexs){
    for( int i=0; i < indexs.size(); i++){
        Zpos.push_back(Grid[indexs[i]]);
    }
}

void setTraslationsZneg(vector<int> indexs){
    for( int i=0; i < indexs.size(); i++){
        Zneg.push_back(Grid[indexs[i]]);
    }
}

void setTraslations(){
    setTraslationsZpos({1,3,5,7,9,11,13,15,17,19,21,23,25,27,29});
    setTraslationsZneg({0,2,4,6,8,10,12,14,16,18,20,22,24,26,28});
}

bool animationsFinished(){
    bool res = true;
    for( int i=0; i < Grid.size();i++){
        res = res && animations[i];
    }
    return res;
}

void triggerModoSolucion(char modoSolucion_){
    for(int i=0; i<Grid.size();i++){
        Grid[i]->modoSolucion = modoSolucion_;
    }
}

void triggerModoRotacion(char modoRotacion_){
    for(int i=0; i<Grid.size();i++){
        Grid[i]->modoRotacion = modoRotacion_;
    }
}


glm::vec3 lightPos(1.2f, 1.5f, 1.0f);


int main()
{
    // cubo1.Up();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Shader ourShader(vertex_shader_text, fragment_shader_text);
    Shader lightingShader(basic_lightingvs, basic_lightingfs);
    Shader lightCubeShader(light_cubevs, light_cubefs);
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    lightingShader.use();
    lightCubeShader.use();
    //ourShader.use();

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    lightingShader.setMat4("projection", projection);
    lightCubeShader.setMat4("projection", projection);
   
    glPointSize(10);
    string shuffleCube;
    string solvecube;

    // initGrid()
    initializeMap();
    // initializeMosaic();

    initGrid();
    initializeMosaic();
    setTraslations();

    //threads
    // vector<thread> ths(1);

    int init = 0;
    int end = Grid.size() - 1;
    bool TraslationReverse = true;
    // ths[0] = thread(listenActions,init,end,ref(ourShader));
    unsigned int VBO, cubeVAO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cubeVAO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        // cout<<"\nloop";

        // if(modoSolucion != 'n'){
        //       cout<<"\nMODO SOL: "<<modoSolucion;
        // }
        // if(modoRotacion != 'n'){
        //       cout<<"\nMODO ROTACION: "<<modoRotacion;
        // }

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /////////////////////////////////////////////////////////////////////////////
         // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("objectColor", 220.0f, 220.0f, 220.0f);
        lightingShader.setVec3("lightColor", 5.0f, 2.0f, 3.0f);
        lightingShader.setVec3("lightPos", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);


        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        lightingShader.setMat4("model", model);
         // change the light's position values over time (can be done anywhere in the render loop actually, but try to do it at least before using the light source positions)
        lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
        lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
        // render the cube
        //glBindVertexArray(cubeVAO);
        //glDrawArrays(GL_TRIANGLES, 0, 36);


        // also draw the lamp object
        
        lightCubeShader.use();
        lightCubeShader.setMat4("projection", projection);
        lightCubeShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lightCubeShader.setMat4("model", model);
        

        glBindVertexArray(lightCubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        /*
        */




        /////////////////////////////////////////////////////////////////////////////

        // camera
        if (modoCamara == 0)
        {
            lightingShader.use();
            glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
            lightingShader.setMat4("view", view);
            
        
        }
        if (modoCamara == 1)
        {
            lightingShader.use();
            const float radius = 20.0f;
            float camX = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            glm::mat4 view;
            view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
            lightingShader.setMat4("view", view);
        }
        if (modoCamara == 2)
        {
            lightingShader.use();
            
            const float radius = 20.0f;
            float camY = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;

            //god fix
            glm::vec3 up;
            if (camZ >= 0)
                up = glm::vec3(0.0f, 1.0f, 0.0f);
            else
                up = glm::vec3(0.0f, -1.0f, 0.0f);

            glm::mat4 view = glm::lookAt(
                    glm::vec3(0.0f, camY, camZ),
                    glm::vec3(0.0f, 0.0f, 0.0f),
                    up
            );

            lightingShader.setMat4("view", view);
        }
        if (modoCamara == 3) {
            const float minCamZ = 2.0f;
            const float maxCamZ = 20.0f;
            const float radius = 20.0f;

            float initialAngle = 0.0f;
            float currentTime = glfwGetTime();
            if (!zoomComplete) {
            
                if (cameraPos.z < maxCamZ) {
                    cameraPos.z += cameraSpeed;
                } else {
                    zoomComplete = true;
                    //std::cout << "Initial angle: " << initialAngle << std::endl;
                    //std::cout << "Camera position: (" << cameraPos.x << ", " << cameraPos.y << ", " << cameraPos.z << ")" << std::endl;
                    //std::cout << "zoomComplete!"<<endl;
                }
                // Clamp the camZ value to the minimum and maximum values
                cameraPos.z = glm::clamp(cameraPos.z, minCamZ, maxCamZ);

                glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

                lightingShader.use();
                lightingShader.setMat4("view", view);
            } else {

                for(int i=init; i <= end ; i++)
                {

                    VirtualRubik* cubo = Grid[i];

                    // rubik solver
                    if (cubo->modoSolucion == '3' && cubo->modoRotacion == 'n')
                    {
                        if (cubo->iter < cubo->pasos_solu.size())
                        {
                            cubo->modoRotacion = movs[ cubo->pasos_solu[cubo->iter]];
                            //cout<<cubo->modoRotacion<<" - ";
                            cubo->iter++;
                        }
                        else
                        {
                            std::cout << "Invalid input" << std::endl;
                            cubo->modoSolucion = 'n';
                            // modoCamara = 2;
                            cubo->iter = 0;
                            //cout<<"\n";
                        }
                        
                    }

                    // mosaic generator
                    if (cubo->modoSolucion == '7' && cubo->modoRotacion == 'n')
                    {
                        // if(cubo->iter == 0){
                        //     cout<<"\nMOD Mosaic:\n";
                        // }

                        //cout<<"\nCubo["<<i<<"]: ";
                        if (cubo->iter < cubo->mosaicMoves.size())
                        {
                            cubo->modoRotacion = movs[ cubo->mosaicMoves[cubo->iter] ];
                            //cout<<cubo->modoRotacion<<" ";
                            cubo->iter++;
                        }
                        else
                        {
                            //std::cout << " Animation Finished!!" << std::endl;
                            cubo->modoSolucion = 'n';
                            // modoCamara = 2;
                            cubo->iter = 0;
                            animations[i] = true; // animation finished!!
                            //cout<<"\n";
                        }
                        
                    }

                

                    //traslations
                    if(cubo->modoTraslacion == "Z+"){
                        //Trasladar
                        cubo->trasladarZPos();
                    }
                    else if(cubo->modoTraslacion == "Z-"){
                        //Trasladar
                        cubo->trasladarZNeg();
                    }


                    // cube rotations
                    if (cubo->modoRotacion == 'u')
                    {
                        cubo->rotarUp();
                        cubo->pasoslib += "U";
                    }
                    else if (cubo->modoRotacion == 'o')
                    {
                        cubo->rotarUpInv();
                        cubo->pasoslib += "U'";
                    }
                    else if (cubo->modoRotacion == 'd')
                    {
                        cubo->rotarDown();
                        cubo->pasoslib += "D";
                    }
                    else if (cubo->modoRotacion == 'm')
                    {
                        cubo->rotarDownI();
                        cubo->pasoslib += "D'";
                    }
                    else if (cubo->modoRotacion == 'r')
                    {
                        cubo->rotarRigth();
                        cubo->pasoslib += "R";
                    }
                    else if (cubo->modoRotacion == 'h')
                    {
                        cubo->rotarRigthI();
                        cubo->pasoslib += "R'";
                    }
                    else if (cubo->modoRotacion == 'l')
                    {
                        cubo->rotarLeft();
                        cubo->pasoslib += "L";
                    }
                    else if (cubo->modoRotacion == 'k')
                    {
                        cubo->rotarLeftI();
                        cubo->pasoslib += "L'";
                    }
                    else if (cubo->modoRotacion == 'f')
                    {
                        cubo->rotarFront();
                        cubo->pasoslib += "F";
                    }
                    else if (cubo->modoRotacion == 't')
                    {
                        cubo->rotarFrontI();
                        cubo->pasoslib += "F'";
                    }
                    else if (cubo->modoRotacion == 'b')
                    {
                        cubo->rotarBack();
                        cubo->pasoslib += "B";
                    }
                    else if (cubo->modoRotacion == 'g')
                    {
                        cubo->rotarBackI();
                        cubo->pasoslib += "B'";
                    }
                }    

                lightingShader.use();

                const float radiusYZ = 20.0f;
                float camY = sin(glfwGetTime()*rotationSpeed) * radiusYZ;
                float camZ = cos(glfwGetTime()*rotationSpeed) * radiusYZ;

                const float radiusXZ = 20.0f;
                float camX = sin(glfwGetTime()*rotationSpeed) * radiusXZ;

                glm::mat4 view;
                view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
                lightingShader.setMat4("view", view);
                cout << "glfwGetTime():" << glfwGetTime();
                cout << "\n" << rotationSpeed;
                
                if(currentTime > 11.7814)
                {
                    rotationSpeed = 0.01f;
                }
            }
        }


       
       //draw cubes
        for(auto cubo :Grid){
            cubo->draw(lightingShader);
        }


        if (animationsFinished() && TraslationReverse){
            //cout<<"\nALL animation finished!!!";
            //trigger traslations
            for(int i=0; i< Zpos.size(); i++){
                Zpos[i]->modoTraslacion= "Z-";
            }
            for(int i=0; i< Zneg.size(); i++){
                Zneg[i]->modoTraslacion= "Z+";
            }
            TraslationReverse = false;
        }


        
        glfwSwapBuffers(window);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Adjust the sleep time as per your preference (e.g., 10 milliseconds).
        glfwPollEvents();
    }



    //cout << endl;
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    //camera
    const float cameraSpeed = 0.05f;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += cameraUp * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
        cameraPos -= cameraUp * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
        modoCamara = 0;
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        modoCamara = 1;
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        modoCamara = 2;
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS){
        modoCamara = 3;
        zoomComplete = false;
        cameraPos = glm::vec3(0.0f,0.0f,3.0f);

        // trigger mosaic generator
        for(int i=0; i< Grid.size(); i++){
            Grid[i]->modoSolucion= '7';
        }
        //trigger traslations
        for(int i=0; i< Zpos.size(); i++){
            Zpos[i]->modoTraslacion= "Z+";
        }
         for(int i=0; i< Zneg.size(); i++){
            Zneg[i]->modoTraslacion= "Z-";
        }
    }
    //rubik solver
    // if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    // {

    //     pasos_solu = convertMoves(testFromCube(pasoslib));
    //     cout << "pasoslib: " << pasoslib << endl;
    //     cout << "pasos solucion" << endl;
    //     for (int i = 0; i < pasos_solu.size(); i++)
    //     {
    //         cout << pasos_solu[i] << "|";
    //     }
    //     cout << endl;
    //     modoRotacion = 'n';
    // }

    // reset
    // if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    // {
    //     cubo1.deleteCubo();
    //     cuboRubik cubo2(0, 0, 0);
    //     cubo2.init();
    //     pasoslib = "";
    //     pasos_solu.clear();
    //     cout << "deletes" << endl;
    //     cubo1 = cubo2;
    //     // cubo1.init();
    // }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        // cubo2.dibujar();
    }
    // if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    // modoCamara = 4;


    //Modo Solver
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS){
        // triggerModoSolucion(0,1,'3');
         for(int i=0; i< Grid.size(); i++){
            Grid[i]->modoSolucion= '3';
        }
    }
    //Modo Mosaico generator
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS){
        
        // trigger mosaic generator
        for(int i=0; i< Grid.size(); i++){
            Grid[i]->modoSolucion= '7';
        }
        //trigger traslations
        for(int i=0; i< Zpos.size(); i++){
            Zpos[i]->modoTraslacion= "Z+";
        }
         for(int i=0; i< Zneg.size(); i++){
            Zneg[i]->modoTraslacion= "Z-";
        }
    }


    //Modo Rotacion
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
        triggerModoRotacion('u');
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        triggerModoRotacion('o');
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        triggerModoRotacion('d');
    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        triggerModoRotacion('m');
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        triggerModoRotacion('r');
    }
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        triggerModoRotacion('h');

    }

    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        triggerModoRotacion('l');

    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        triggerModoRotacion('k');

    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        triggerModoRotacion('f');

    }
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        triggerModoRotacion('t');

    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        triggerModoRotacion('b');

    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        triggerModoRotacion('g');

    }
    // }
};

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}
