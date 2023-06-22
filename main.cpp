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
#include "Headers/Header.h"
#include "Shaders/shader_s.h"
//#include "../../../../grafica/Rubik/CubeSolver-Master/CubeSolver-Master/Headers/Header.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

using namespace std;

int modoCamara = 0;

char modoSolucion = 'n';
char modoRotacion = 'n';
int rotloop = 90;
vector<string> pasos;
string pasoslib;
vector<char> pasos2;
vector<string>pasos_solu;
 std::vector<std::string> replacedVector;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
// settings

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

bool firstMouse = true;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame


std::vector<std::string> parseMovements(const std::string& input) {
    std::vector<std::string> movements;
    std::stringstream ss(input);
    std::string movement;

    while (ss >> movement) {
        movements.push_back(movement);
    }

    return movements;
}

std::string convertToDoubleMove(const std::string& move) {
    std::string convertedMove;
    if (move.back() == '2') {
        convertedMove = move.substr(0, move.length() - 1) + " " + move.substr(0, move.length() - 1);
    } else {
        convertedMove = move;
    }
    return convertedMove;
}

std::vector<std::string> convertMoves(const std::string& moves) {
    std::vector<std::string> convertedMoves;
    std::istringstream iss(moves);
    std::string move;
    while (iss >> move) {
        std::string convertedMove = convertToDoubleMove(move);

        // Split the converted move into individual moves
        std::istringstream issSplit(convertedMove);
        std::string singleMove;
        while (issSplit >> singleMove) {
            convertedMoves.push_back(singleMove);
        }
    }
    return convertedMoves;
}

void rotarUp(cuboRubik &Cubo) {   
    rotloop-= 5;
    Cubo.Up(0,1);
    //cout << "theta u: " <<theta << endl;
    theta = -5*(PI/180);

    if (rotloop == 0) {
        Cubo.Up(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarUpInv(cuboRubik &Cubo) {   
    rotloop-= 5;
    //cout << "theta ui: " <<theta << endl;
    theta = 5*(PI/180);

    Cubo.UpI(0,-1);
    if (rotloop == 0) {
        Cubo.UpI(1,-1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarDown(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.Down(0,1);
    if (rotloop == 0) {
        Cubo.Down(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarDownI(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.DownI(0,1);
    if (rotloop == 0) {
        Cubo.DownI(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarRigth(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.Rigth(0,1);
    if (rotloop == 0) {
        Cubo.Rigth(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarRigthI(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.RigthI(0,1);
    if (rotloop == 0) {
        Cubo.RigthI(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarLeft(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.Left(0,1);
    if (rotloop == 0) {
        Cubo.Left(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarLeftI(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.LeftI(0,1);
    if (rotloop == 0) {
        Cubo.LeftI(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarFront(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.Front(0,1);
    if (rotloop == 0) {
        Cubo.Front(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarFrontI(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.FrontI(0,1);
    if (rotloop == 0) {
        Cubo.FrontI(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarBack(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.Back(0,1);
    if (rotloop == 0) {
        Cubo.Back(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
}
void rotarBackI(cuboRubik &Cubo) {
    rotloop -= 5;
    Cubo.BackI(0,1);
    if (rotloop == 0) {
        Cubo.BackI(1,1);
        rotloop = 90;
        modoRotacion = 'n';
    }
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
cuboRubik cubo1(0,0,0);
/*cuboRubik cubo2(2.0,0,0);
cuboRubik cubo3(4.0,0,0);
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
std::map<std::string, char > movs;

void initializeMap() {
    movs["R"] = 'r';
    movs["R'"] = 'h';
    movs["L"] = 'l';
    movs["L'"] ='k';
    movs["F"] = 'f';
    movs["F'"] = 't';
    movs["B"] = 'b';
    movs["B'"] = 'g';
    movs["U"] = 'u';
    movs["U'"] = 'o';
    movs["D"] = 'd';
    movs["D'"] =  'm';
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

int i =0;





int main()
{
    //cubo1.Up();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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

    ourShader.use();

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    cubo1.init();
    //cubo2.movePoints(0,0,0.3);
    /*cubo2.init();
    cubo3.init();
    cubo4.init();
    cubo5.init();
    cubo6.init();
    cubo7.init();
    cubo8.init();
    cubo9.init();
    cubo10.init();
    cubo11.init();
    cubo12.init();
    cubo13.init();*/
    glPointSize(10);
    string shuffleCube;
    string solvecube;
    initializeMap();
    //cout << "ingresa solvecube " << endl;
            //cin >> solvecube;
            //solvecube = "LFLFLFLLFFFL";
            //pasos_solu = parseMovements("F F U F F U' F F L L U' L L U L L U B' U' B U U B' U B L U F' U' L' U L F L D F' U F' U' F D' L L B' U B U U");

        
   
    //std::cout << "File content:\n" << textContent << std::endl;

    while (!glfwWindowShouldClose(window))
    {
       
        if(modoSolucion != 'n'){
              cout<<"\nMODO SOL: "<<modoSolucion;
        }
        if(modoRotacion != 'n'){
              cout<<"\nMODO ROTACION: "<<modoRotacion;
        }
      
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /*if(modoCamara == 4){
            solvecube = "LFLFLFLFL";
            //if(modoRotacion != 'n'){
                std::string key(1, solvecube[i]);
                if (movs.find(key) != movs.end()) {
                    
                    movs[key]();
                    //continue; // Call the function associated with the key
                }
                else {
                    std::cout << "Invalid input" << std::endl;
                    modoRotacion = 'n';
                }
            //}
            cubo1.dibujar(ourShader);

                //test

                glfwSwapBuffers(window);
                std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Adjust the sleep time as per your preference (e.g., 10 milliseconds).
                glfwPollEvents();
            if (i >= solvecube.size()){
                modoCamara =2;

                }
                if(modoRotacion == 'n'){
                    i++;
              //  }
                }
                continue;
        }*/

         if (modoSolucion == '3' && modoRotacion == 'n'){
                if (i < pasos_solu.size()) {
                    modoRotacion =  movs[pasos_solu[i]];
                }
                else {
                    std::cout << "Invalid input" << std::endl;
                    modoSolucion = 'n';
                    modoCamara =2;
                    i=0;
                }
                i++;
        }

        
        if (modoCamara == 0) {

            ourShader.use();
            glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
            ourShader.setMat4("view", view);

        }if (modoCamara == 1) {

            ourShader.use();
            const float radius = 5.0f;
            float camX = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            glm::mat4 view;
            view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
            ourShader.setMat4("view", view);

        }if (modoCamara == 2) {

            ourShader.use();
            const float radius = 5.0f;
            float camY = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;

            //std::cout << camY << " " << camZ << std::endl;
            glm::mat4 view;
            view = glm::lookAt(glm::vec3(0.0, camY, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
            ourShader.setMat4("view", view);

        }
        
        if (modoRotacion == 'u') {
            rotarUp(cubo1);
        }
        else if(modoRotacion == 'o'){
            rotarUpInv(cubo1);
        }
        else if (modoRotacion == 'd') {
            rotarDown(cubo1);
        }
        else if (modoRotacion == 'm') {
            rotarDownI(cubo1);
        }      
        else if (modoRotacion == 'r') {
            rotarRigth(cubo1);
        }
        else if (modoRotacion == 'h') {
            rotarRigthI(cubo1);
        }
        else if (modoRotacion == 'l') {
            rotarLeft(cubo1);
        }
        else if (modoRotacion == 'k') {
            rotarLeftI(cubo1);
        }
        else if (modoRotacion == 'f') {
            rotarFront(cubo1);
        }
        else if (modoRotacion == 't') {
            rotarFrontI(cubo1);
        }
        else if (modoRotacion == 'b') {
            rotarBack(cubo1);
        }
        else if (modoRotacion == 'g') {
            rotarBackI(cubo1);
        }
        

        cubo1.dibujar(ourShader);
        /*cubo2.dibujar(ourShader);
        cubo3.dibujar(ourShader);
        cubo4.dibujar(ourShader);
        cubo5.dibujar(ourShader);
        cubo6.dibujar(ourShader);
        cubo7.dibujar(ourShader);
        cubo8.dibujar(ourShader);
        cubo9.dibujar(ourShader);
        cubo10.dibujar(ourShader);
        cubo11.dibujar(ourShader);
        cubo12.dibujar(ourShader);
        cubo13.dibujar(ourShader);*/
        //test

        glfwSwapBuffers(window);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Adjust the sleep time as per your preference (e.g., 10 milliseconds).
        glfwPollEvents();

    }
    //cout << "pasos " << pasoslib << endl;
    //pasoslib = "LFLFLFLLFFFL";
    //TestFromCMD();
    //testFromCube(pasoslib);
    
    
    //SolveCube();

    cubo1.deleteCubo();
        /*cubo2.deleteCubo();
        cubo3.deleteCubo();
        cubo4.deleteCubo();
        cubo5.deleteCubo();
        cubo6.deleteCubo();
        cubo7.deleteCubo();
        cubo8.deleteCubo();
        cubo9.deleteCubo();
        cubo10.deleteCubo();
        cubo11.deleteCubo();
        cubo12.deleteCubo();
        cubo13.deleteCubo();*/
    
    cout << endl;
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    float cameraSpeed = 2.5f * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
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
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS){
        pasos_solu = convertMoves(testFromCube(pasoslib));
        cout << "pasoslib: " << pasoslib <<endl;
            cout << "pasos solucion" << endl;
            for(int i=0; i<pasos_solu.size(); i++){
                cout << pasos_solu[i] << "|"; 
            }
            cout <<endl;
        modoRotacion = 'n';

    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS){
        cubo1.deleteCubo();
        cuboRubik cubo2(0,0,0);
        cubo2.init();
        pasoslib = "";
        pasos_solu.clear();
        cout << "deletes" << endl;
        cubo1 = cubo2;
        //cubo1.init();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS){
        //cubo2.dibujar();

    }
    //if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        //modoCamara = 4;
    if (modoRotacion == 'n') {
        //i++;
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
            modoSolucion = '3';
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
            modoRotacion = 'u';
            pasos.push_back("U");
            pasoslib += "U";
        }
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
            modoRotacion = 'o';
            pasos.push_back("U'");
            pasoslib += "U'";
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            modoRotacion = 'd';
            pasos.push_back("D");
            pasoslib += "D";
        }
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
            modoRotacion = 'm';
            pasos.push_back("D'");
            pasoslib += "D'";
        }
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            modoRotacion = 'r';
            pasos.push_back("R");
            pasoslib += "R";
        }
        if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
            modoRotacion = 'h';
            pasos.push_back("R'");
            pasoslib += "R'";
        }
        
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            modoRotacion = 'l';
            pasos.push_back("L");
            pasoslib += "L";
        }
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
            modoRotacion = 'k';
            // pasos.push_back("R'");
            pasos.push_back("L'");
            pasoslib += "L'";
        }
        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
            modoRotacion = 'f';
            pasos.push_back("F");
            pasoslib += "F";
        }
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
            modoRotacion = 't';
            pasos.push_back("F'");
            pasoslib += "F'";
        }
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
            modoRotacion = 'b';
            pasos.push_back("B");
            pasoslib += "B";
        }
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
            modoRotacion = 'g';
            pasos.push_back("B'");
            pasoslib += "B'";
        }

    }
    

};

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
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
