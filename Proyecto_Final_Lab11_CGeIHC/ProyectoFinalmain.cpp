#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"
const float toRadians = 3.14159265f / 180.0f;

//variables para animación
float movCoche;
float movOffset;
float sube;
float subeOffset;
float rotllanta;
float rotllantaOffset;
float rotletrero;
float rotletreroOffset;

bool subir;
bool girar;
bool avanza;
//variables para la animacion del Helicoptero
bool rot1;
bool rot2;
bool rot3;
bool rot4;
int vuelta;
float movH;
float movHZ;
float movHOffset;
float rotHelices;
float rotHelicesOffset;
int rot;
//variables para la animacion del dirigible 
bool rot5;
bool rot6;
bool rot7;
bool rot8;
bool asignacion;
int vuelta2;
float movD;
float movDZ;
float movDOffset;
float rotHelicesD;
float rotHelicesDOffset;
int rotD;
int j;
//========================================================================
//variables para los dados 
int randomNum;
int rotx;
int rotz;
int roty;
int randomNum8;
int rotx8;
int rotz8;
int roty8;
float subeD;
float subeDOffset;
float rotDado;
float rotDadoOffset;
//=========================================================================
float temporizador;
float tiempoespera;
int i;
//=========================================================================
//variables para la animacion de Hipo (recorrido)
bool rotH;
bool rotH2;
bool rotH3;
bool rotH4;
float movHipo;
float movHipoOffset;
float rotHipo;

float rotBrazoD;
float rotBrazoI;
float rotPiernaD;
float rotPiernaI;
float vueltaHipo;
float casillas;
float sumDado;
float restante;
float movx;
float movz;
bool valor;
//=========================================================================
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
//Camaras
Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture AgaveTexture;
Texture negroTexture;
Texture blancoTexture;
Texture rojoTexture;
Texture helicoptero;
Texture Dirigible;
//=========================================================================
//texturas de Hipo y Link
Texture Hipo;
Texture linkCuerpoTexture;
Texture linkOrejaTexture;
Texture linkOjoTexture;
Texture linkCabelloTexture;
Texture linkBocaTexture;
Texture linkEscudoAdelanteTexture;
Texture linkAtrasTexture;
Texture linkEspejoTexture;
Texture linkEspadaAdelanteTexture;
Texture linkEspadaAtrasTexture;
//=========================================================================
//texturas personajes casillas
Texture tmonitor;
Texture tkirbycuerpo;
Texture tkirbycara;
Texture tkirbytrans;
Texture tflor;
Texture todst;
Texture todstcasco;
Texture tconejocuerpo;
Texture tconejoojo;
Texture tastrid;
Texture telitecuerpo;
Texture telitebrazo;
Texture telitecabeza;
Texture telitepiernas;
Texture tbuho;
Texture tbuhoojo;
Texture tbuhoojito;
Texture testoico;
Texture tcuatro;
Texture tcuatrobump;
Texture tpulpo;
Texture tbocon;
Texture tapeman;
Texture tcuco;
Texture tcucoojo;
Texture tbrutacio;
Texture tflood;
Texture tfloodbrazo;
Texture tmutt;
Texture tmuttojo;
Texture tbrutilda;
Texture trata;
Texture ttienda;
Texture ttiendados;
Texture tpatapez;
Texture tflores;
Texture tpina;
Texture tcasa;
Texture tarbusto;
Texture tpanal;
Texture tchimuelo;
Texture tarbol;
Texture tarboltronco;
Texture tcofre;
Texture trompehuesos;
Texture ttormenta;
Texture tpilaruno;
Texture tpilardos;
Texture tpilartres;
Texture tpilarcuatro;
Texture tpilarcinco;
Texture tpilarseis;
Texture tpilarsiete;
Texture tmarincuerpo;
Texture tmarinojo;
Texture tmarincabeza;
Texture tmarinboca;
Texture thuevo;
Texture thuevonormal;
Texture tsc;
Texture tmoblin;
Texture tmoblinescudo;
Texture tmoblinespada;
Texture tpatan;
Texture thalouno;
Texture thalodos;
Texture thalotres;
Texture thalocuatro;
Texture tzora;
Texture tzoraojo;
//=========================================================================
//textura dado 
Texture dado10Texture;
Texture tableroTexture;
Texture D8;
Texture D4;
Texture Lampara;
Model Letrero;
Model BaseL;
Model cuerpoHelicoptero;
Model HSHelicoptero;
Model HTHelicoptero;
//=========================================================================
//Partes de Hipo
Model BrazoDH;
Model BrazoIH;
Model CuerpoH;
Model PiernaDH;
Model PiernaIH;
Model esferaPI;
Model esferaPD;
Model esferaBI;
Model esferaBD;
//Link
Model Link;
//=========================================================================
//modelos personajes casillas
Model casilla2spark;
Model casilla3kirby;
Model casilla4flor;
Model casilla5odst;
Model casilla6conejo;
Model casilla7astrid;
Model casilla8elite;
Model casilla9buho;
Model casilla10estoico;
Model casilla11cuatro;
Model casilla12pulpo;
Model casilla13bocon;
Model casilla14apeman;
Model casilla15cuco;
Model casilla16brutacio;
Model casilla17flood;
Model casilla18mutt;
Model casilla19brutilda;
Model casilla20rata;
Model casilla21tienda;
Model casilla22patapez;
Model casilla23flores;
Model casilla24pina;
Model casilla25casa;
Model casilla26arbusto;
Model casilla27panal;
Model casilla28chimuelo;
Model casilla29arbol;
Model casilla30cofre;
Model casilla31rompehuesos;
Model casilla32tormenta;
Model casilla33pilar;
Model casilla34marin;
Model casilla35huevo;
Model casilla36sc;
Model casilla37moblin;
Model casilla38patan;
Model casilla39halo;
Model casilla40zora;
//=========================================================================
Model Casilla_1;
Model Casilla_2;
Model Casilla_3;
Model Casilla_4;
Model Casilla_5;
Model Casilla_6;
Model Casilla_7;
Model Casilla_8;
Model Casilla_9;
Model Casilla_10;
Model Casilla_11;
Model Casilla_12;
Model Casilla_13;
Model Casilla_14;
Model Casilla_15;
Model Casilla_16;
Model Casilla_17;
Model Casilla_18;
Model Casilla_19;
Model Casilla_20;
Model Casilla_21;
Model Casilla_22;
Model Casilla_23;
Model Casilla_24;
Model Casilla_25;
Model Casilla_26;
Model Casilla_27;
Model Casilla_28;
Model Casilla_29;
Model Casilla_30;
Model Casilla_31;
Model Casilla_32;
Model Casilla_33;
Model Casilla_34;
Model Casilla_35;
Model Casilla_36;
Model Casilla_37;
Model Casilla_38;
Model Casilla_39;
Model Casilla_40;
Model Dado8;
Model Dado4;
Model lampara;
Model dirigible;
Model Hdirigible;
Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;


//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";
int random_number(int lower, int upper) {
	return (rand() % (upper - lower + 1)) + lower;
}


//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,


	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);

}
void CrearDecaedro() {
	unsigned int decaedro_indices[] = {
		// Caras del decaedro (10 triángulos)
		0, 1, 2,    // Cara 1
		3, 4, 5,    // Cara 2
		6, 7, 8,    // Cara 3
		9, 10, 11,  // Cara 4
		12, 13, 14, // Cara 5
		15, 16, 17, // Cara 6
		18, 19, 20, // Cara 7
		21, 22, 23, // Cara 8
		24, 25, 26, // Cara 9
		27, 28, 29,  // Cara 10
	};

	GLfloat decaedro_vertices[] = {
		//x		y		z		S		T			NX		NY		NZ
		0.0f, 1.0f,  0.0f,	    0.24f,  0.46f,	0.0f,	1.0f,	1.0f,
		1.0f, 0.0f,  0.0f,		0.04,  0.26f,	0.0f,	1.0f,	1.0f,
		0.31f, 0.0f, -0.95f,	0.25f,	 0.06f,	0.0f,	1.0f,	1.0f,

		0.31f, 0.0f, -0.95f, 	0.04f,  0.68f,		01.0f,	0.0f,	01.0f,
		-0.81f, 0.0f, -0.59f,	0.03f,  0.28f,		01.0f,	0.0f,	01.0f,
		 0.0f, 1.0f, 0.0f,      0.24f,  0.48f,		01.0f,	0.0f,	01.0f,

		  0.0f, 1.0f, 0.0f,		 	0.24f,  0.52f,		1.0f,	0.0f,	1.0f,
		  -0.81f, 0.0f, -0.59f,		0.25f,  0.89f,		1.0f,	0.0f,	1.0f,
		  -0.809f, 0.0f, 0.59f,  	0.05f,	0.7f,	    1.0f,	0.0f,	1.0f,

		  -0.809f, 0.0f, 0.59f, 	0.46f,  0.7f,		1.0f,	1.0f,	0.0f,
		  0.309f, 0.0f, 0.95f,		0.27f,	0.89f,		1.0f,	1.0f,	0.0f,
		  0.0f, 1.0f, 0.0f, 	    0.27f,  0.51f,		1.0f,	1.0f,	0.0f,

		  0.0f, 1.0f, 0.0f,    		0.27f,  0.48f,	0.0f,	1.0f,	-1.0f,
		  0.309f, 0.0f, 0.95f,		0.48f,	 0.28f,	0.0f,	1.0f,	-1.0f,
		  1.0f, 0.0f,0.0f,  	    0.48f,  0.68f,	0.0f,	1.0f,	-1.0f,

		   1.0f,  0.0f,   0.0f,		0.5f, 0.28f,		0.0f,	1.0f,	1.0f,
		   0.0f, -1.0f,   0.0f,		0.7f, 0.48f,		0.0f,	1.0f,	1.0f,
		  0.31f,  0.0f, -0.95f,		0.5f, 0.67f,		0.0f,	1.0f,	1.0f,

		  0.31f, 0.0f, -0.95f, 		0.51f,  0.7f,		1.0f,	0.0f,	1.0f,
		  0.0f, -1.0f, 0.0f,  		0.71f,	0.51f,		1.0f,	0.0f,	1.0f,
		  -0.81f, 0.0f, -0.59f,  	0.71f,  0.89f,		1.0f,	0.0f,	1.0f,

		  -0.81f, 0.0f, -0.59f,  	0.74f,  0.89f,		1.0f,	0.0f,	1.0f,
		  0.0f, -1.0f, 0.0f,  		0.73f,	0.5f,		1.0f,	0.0f,	1.0f,
		  -0.809f, 0.0f, 0.59f,		0.93f,  0.7f,		1.0f,	0.0f,	1.0f,

		  -0.809f, 0.0f, 0.59f, 	0.95f,  0.68f,		1.0f,	1.0f,	0.0f,
		  0.309f, 0.0f, 0.95f,		0.94f,	0.28f,		1.0f,	1.0f,	0.0f,
		  0.0f, -1.0f, 0.0f,	    0.74f,  0.48f,		1.0f,	1.0f,	0.0f,

		  0.0f, -1.0f, 0.0f,     	0.73f,  0.46f,		0.0f,	1.0f,	-1.0f,
		  0.309f, 0.0f, 0.95f,		0.93f,	0.26f,		0.0f,	1.0f,	-1.0f,
		  1.0f, 0.0f,0.0f,  	    0.73f,  0.06f,		0.0f,	1.0f,	-1.0f,
	};

	Mesh* dad010c = new Mesh();
	dad010c->CreateMesh(decaedro_vertices, decaedro_indices, 240, 30);
	meshList.push_back(dad010c);
}
//=========================================================================================
//Función para crear el dado de 4 caras
void CrearPiramideTriangular() {
	unsigned int piramide_indices[] = {
		// Cada cara tiene tres índices, sin reutilizar vértices
		0, 1, 2,    // Cara de la base
		3, 4, 5,    // Cara lateral 1
		6, 7, 8,    // Cara lateral 2
		9, 10, 11   // Cara lateral 3
	};

	GLfloat piramide_vertices[] = {
		// Base de la pirámide (cada vértice ajustado)
		-0.5f, -0.25f, -0.333f,   0.7f, 0.5f,   0.0f, -1.0f, 0.0f,  // Vértice 0 - Base
		 0.5f, -0.25f, -0.333f,   0.32f, 0.5f,  0.0f, -1.0f, 0.0f,  // Vértice 1 - Base
		 0.0f, -0.25f,  0.667f,   0.51f, 0.27f, 0.0f, -1.0f, 0.0f,  // Vértice 2 - Base

		 // Cara lateral 1
		 -0.5f, -0.25f, -0.333f,   0.71f, 0.52f, -0.5f, 0.5f, 0.5f,  // Vértice 3
		  0.5f, -0.25f, -0.333f,   0.3f, 0.52f, -0.5f, 0.5f, 0.5f,  // Vértice 4
		  0.0f,  0.75f,  0.167f,   0.51f, 0.76f, -0.5f, 0.5f, 0.5f,  // Vértice 5

		  // Cara lateral 2
		   0.5f, -0.25f, -0.333f,   0.73f, 0.5f,  0.5f, 0.5f, 0.5f,  // Vértice 6
		   0.0f, -0.25f,  0.667f,   0.53f, 0.26f, 0.5f, 0.5f, 0.5f,  // Vértice 7
		   0.0f,  0.75f,  0.167f,   0.92f, 0.26f, 0.5f, 0.5f, 0.5f,  // Vértice 8

		   // Cara lateral 3
			0.0f, -0.25f,  0.667f,   0.3f, 0.5f, -0.5f, 0.5f, -0.5f,  // Vértice 9
		   -0.5f, -0.25f, -0.333f,   0.49f, 0.26f, -0.5f, 0.5f, -0.5f,  // Vértice 10
			0.0f,  0.75f,  0.167f,   0.1f, 0.27f, -0.5f, 0.5f, -0.5f   // Vértice 11
	};


	Mesh* piramideMesh = new Mesh();
	piramideMesh->CreateMesh(piramide_vertices, piramide_indices, 96, 12);
	meshList.push_back(piramideMesh);
}
//=========================================================================================

void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}
//=========================================================================================
//Función para visualizar las caras de los dados
struct Giro {
	float x, y, z;
};

// Dado de 4 caras
Giro Vista_Caras_4[4] = {
	{0.0f, 0.0f, 0.0f},  // Cara 1
	{240.0f, 0.0f, 0.0f}, // Cara 2
	{310.0f, 240.0f, 210.0f}, // Cara 3
	{80.0f, 290.0f, 185.0f}   // Cara 4
};

// Dado de 8 caras
Giro Vista_Caras_8[8] = {
	{30.0f, 0.0f, 0.0f},   // Cara 1
	{30.0f, 170.0f, 265.0f}, // Cara 2
	{260.0f, 310.0f, 260.0f}, // Cara 3
	{245.0f, 230.0f, 150.0f}, // Cara 4
	{65.0f, 230.0f, 150.0f},  // Cara 5
	{320.0f, 200.0f, 160.0f}, // Cara 6
	{230.0f, 135.0f, 230.0f}, // Cara 7
	{230.0f, 320.0f, 40.0f}   // Cara 8
};
//=========================================================================================

int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();
	CrearDecaedro();
	//=========================================================================================
	//Se manda a llamar la función para crear el dado de 4 caras
	CrearPiramideTriangular();
	//=========================================================================================
	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/piso.tga");
	pisoTexture.LoadTextureA();
	blancoTexture = Texture("Textures/blanco-opt.jpg");
	blancoTexture.LoadTextureA();
	negroTexture = Texture("Textures/negro-opt.jpg");
	negroTexture.LoadTextureA();
	rojoTexture = Texture("Textures/rojo-opt.jpg");
	rojoTexture.LoadTextureA();
	helicoptero = Texture("Textures/HH65C.jpg");
	helicoptero.LoadTextureA();
	//=======================================================================
	//Textura de Hipo
	Hipo = Texture("Textures/HiccupTeen.png");
	Hipo.LoadTextureA();
	//Textura de Link
	linkCuerpoTexture = Texture("Textures/mi_body_alb.0.png");
	linkCuerpoTexture.LoadTextureA();
	linkOrejaTexture = Texture("Textures/mi_ear_alb.0.png");
	linkOrejaTexture.LoadTextureA();
	linkOjoTexture = Texture("Textures/mi_eye_alb.0.png");
	linkOjoTexture.LoadTextureA();
	linkCabelloTexture = Texture("Textures/mi_hair_alb.png");
	linkCabelloTexture.LoadTextureA();
	linkBocaTexture = Texture("Textures/mi_mouth_alb.0.png");
	linkBocaTexture.LoadTextureA();
	linkEscudoAdelanteTexture = Texture("Textures/mi_shielda_alb.png");
	linkEscudoAdelanteTexture.LoadTextureA();
	linkAtrasTexture = Texture("Textures/mi_shieldb_alb.png");
	linkAtrasTexture.LoadTextureA();
	linkEspejoTexture = Texture("Textures/mi_shieldbmirror_alb.png");
	linkEspejoTexture.LoadTextureA();
	linkEspadaAdelanteTexture = Texture("Textures/mi_sowrda_alb.png");
	linkEspadaAdelanteTexture.LoadTextureA();
	linkEspadaAtrasTexture = Texture("Textures/mi_sowrdb_alb.png");
	linkEspadaAtrasTexture.LoadTextureA();
	//======================================================================
	//Texturas personajes casillas
	tmonitor = Texture("Textures/monitor_base.png");
	tmonitor.LoadTextureA();
	tkirbycuerpo = Texture("Textures/mi_body1_alb.png");
	tkirbycuerpo.LoadTextureA();
	tkirbycara = Texture("Textures/mi_bodytrans_alb.0.png");
	tkirbycara.LoadTextureA();
	tkirbytrans = Texture("Textures/mi_bodytrans_smt.0.png");
	tkirbytrans.LoadTextureA();
	tflor = Texture("Textures/Image_0.001.png");
	tflor.LoadTextureA();
	todst = Texture("Textures/odst_body_diffuse-Alpha.png");
	todst.LoadTextureA();
	todstcasco = Texture("Textures/odst_helmet_diffuse-Alpha.png");
	todstcasco.LoadTextureA();
	tconejocuerpo = Texture("Textures/mi_body_alb.png");
	tconejocuerpo.LoadTextureA();
	tconejoojo = Texture("Textures/mi_eye_alb.02.png");
	tconejoojo.LoadTextureA();
	tastrid = Texture("Textures/Astrid.png");
	tastrid.LoadTextureA();
	telitecuerpo = Texture("Textures/elite_torso.png");
	telitecuerpo.LoadTextureA();
	telitebrazo = Texture("Textures/elite_arms.png");
	telitebrazo.LoadTextureA();
	telitecabeza = Texture("Textures/elite_head.png");
	telitecabeza.LoadTextureA();
	telitepiernas = Texture("Textures/elite_legs.png");
	telitepiernas.LoadTextureA();
	tbuho = Texture("Textures/mi_body_alb.png");
	tbuho.LoadTextureA();
	tbuhoojo = Texture("Textures/mi_eye_alb.png");
	tbuhoojo.LoadTextureA();
	tbuhoojito = Texture("Textures/mi_eyelid0_alb.0.png");
	tbuhoojito.LoadTextureA();
	testoico = Texture("Textures/Stoick1024_Tex.png");
	testoico.LoadTextureA();
	tcuatro = Texture("Textures/masterchief.png");
	tcuatro.LoadTextureA();
	tcuatrobump = Texture("Textures/masterchief_bump.png");
	tcuatrobump.LoadTextureA();
	tpulpo = Texture("Textures/mi_body_albpulpo.png");
	tpulpo.LoadTextureA();
	tbocon = Texture("Textures/GobberTex.png");
	tbocon.LoadTextureA();
	tapeman = Texture("Textures/tree_object_aka_apeman.png");
	tapeman.LoadTextureA();
	tcuco = Texture("Textures/mi_body_albcuco.png");
	tcuco.LoadTextureA();
	tcucoojo = Texture("Textures/mi_eye_alb.0cuco.png");
	tcucoojo.LoadTextureA();
	tbrutacio = Texture("Textures/TuffnutTeen.png");
	tbrutacio.LoadTextureA();
	tflood = Texture("Textures/flood_infection.png");
	tflood.LoadTextureA();
	tfloodbrazo = Texture("Textures/infection_tentacles.png");
	tfloodbrazo.LoadTextureA();
	tmutt = Texture("Textures/mi_body_albmutt.png");
	tmutt.LoadTextureA();
	tmuttojo = Texture("Textures/mi_eye_alb.0mutt.png");
	tmuttojo.LoadTextureA();
	tbrutilda = Texture("Textures/RuffnutTeen.png");
	tbrutilda.LoadTextureA();
	trata = Texture("Textures/rat.png");
	trata.LoadTextureA();
	ttienda = Texture("Textures/MI_BdShop_01_alb.png");
	ttienda.LoadTextureA();
	ttiendados = Texture("Textures/MI_Bdshop_signboard_01_alb.png");
	ttiendados.LoadTextureA();
	tpatapez = Texture("Textures/Fishlegs.png");
	tpatapez.LoadTextureA();
	tflores = Texture("Textures/T_np_flowers_D.png");
	tflores.LoadTextureA();
	tpina = Texture("Textures/MI_pineapple_alb.png");
	tpina.LoadTextureA();
	tcasa = Texture("Textures/default-PBR-BaseColor.png");
	tcasa.LoadTextureA();
	tarbusto = Texture("Textures/texturefile_472.png");
	tarbusto.LoadTextureA();
	tpanal = Texture("Textures/mi_honeycomb_alb.png");
	tpanal.LoadTextureA();
	tchimuelo = Texture("Textures/SoD_PC_DRAGON_Nightfury_Body_D.png");
	tchimuelo.LoadTextureA();
	tarbol = Texture("Textures/firLeaf.png");
	tarbol.LoadTextureA();
	tarboltronco = Texture("Textures/firBark.png");
	tarboltronco.LoadTextureA();
	tcofre = Texture("Textures/mi_dungeontreasurebox_01_alb.png");
	tcofre.LoadTextureA();
	trompehuesos = Texture("Textures/BoneKnapper.png");
	trompehuesos.LoadTextureA();
	ttormenta = Texture("Textures/DeadlyNadder1024Tex.png");
	ttormenta.LoadTextureA();
	tpilaruno = Texture("Textures/pillar_of_autumn_decals.png");
	tpilaruno.LoadTextureA();
	tpilardos = Texture("Textures/pillar_of_autumn_tiler_ao.png");
	tpilardos.LoadTextureA();
	tpilartres = Texture("Textures/pillar_of_autumn1_ao.png");
	tpilartres.LoadTextureA();
	tpilarcuatro = Texture("Textures/pillar_of_autumn1_illum.png");
	tpilarcuatro.LoadTextureA();
	tpilarcinco = Texture("Textures/pillar_of_autumn2_ao.png");
	tpilarcinco.LoadTextureA();
	tpilarseis = Texture("Textures/poa_hull_detail_map.png");
	tpilarseis.LoadTextureA();
	tpilarsiete = Texture("Textures/unsc_poa_details.png");
	tpilarsiete.LoadTextureA();
	tmarincuerpo = Texture("Textures/mi_body_albmarin.png");
	tmarincuerpo.LoadTextureA();
	tmarinojo = Texture("Textures/mi_eye_alb.0marin.png");
	tmarinojo.LoadTextureA();
	tmarincabeza = Texture("Textures/mi_head_alb.png");
	tmarincabeza.LoadTextureA();
	tmarinboca = Texture("Textures/mi_mouth_alb.0marin.png");
	tmarinboca.LoadTextureA();
	thuevo = Texture("Textures/EggBuffalord.png");
	thuevo.LoadTextureA();
	thuevonormal = Texture("Textures/EggBuffalord_Normal.png");
	thuevonormal.LoadTextureA();
	tsc = Texture("Textures/supercarrier_diffuse.png");
	tsc.LoadTextureA();
	tmoblin = Texture("Textures/mi_body_albmoblin.png");
	tmoblin.LoadTextureA();
	tmoblinescudo = Texture("Textures/mi_shield_alb.png");
	tmoblinescudo.LoadTextureA();
	tmoblinespada = Texture("Texturesmi_sword_albpng");
	tmoblinespada.LoadTextureA();
	tpatan = Texture("Textures/SnotloutTeen.png");
	tpatan.LoadTextureA();
	thalouno = Texture("Textures/halo inner ring destroyed.png");
	thalouno.LoadTextureA();
	thalodos = Texture("Textures/halo outer ring.png");
	thalodos.LoadTextureA();
	thalotres = Texture("Textures/halo_inner_ring_destroyed.png");
	thalotres.LoadTextureA();
	thalocuatro = Texture("Textures/halo_outer_ring.png");
	thalocuatro.LoadTextureA();
	tzora = Texture("Textures/mi_body_albzora.png");
	tzora.LoadTextureA();
	tzoraojo = Texture("Textures/mi_eye_alb.0zora.png");
	tzoraojo.LoadTextureA();
	//======================================================================
	//dado 
	dado10Texture = Texture("Textures/dado10.jpg");
	dado10Texture.LoadTextureA();
	tableroTexture = Texture("Textures/dia.png");
	tableroTexture.LoadTextureA();
	D4 = Texture("Textures/Dado4-opt.tga");
	D4.LoadTextureA();
	D8 = Texture("Textures/Dado8-opt.tga");
	D8.LoadTextureA();
	Lampara = Texture("Textures/LamparaTexture.tga");
	Lampara.LoadTextureA();
	Dirigible = Texture("Textures/DirigibleTextura.tga");
	Dirigible.LoadTextureA();
	Letrero = Model();
	Letrero.LoadModel("Models/letrero.obj");
	BaseL = Model();
	BaseL.LoadModel("Models/baseL.obj");
	cuerpoHelicoptero = Model();
	cuerpoHelicoptero.LoadModel("Models/cuerpoHelicoptero.obj");
	HSHelicoptero = Model();
	HSHelicoptero.LoadModel("Models/HSHelicoptero.obj");
	HTHelicoptero = Model();
	HTHelicoptero.LoadModel("Models/HTHelicoptero.obj");

	//==================================================
	/////Personaje/////
	Link = Model();
	Link.LoadModel("Models/link.obj");
	/////////Modelos casillas//////////
	casilla2spark = Model();
	casilla2spark.LoadModel("Models/343halo.obj");
	casilla3kirby = Model();
	casilla3kirby.LoadModel("Models/EnemyKirby.obj");
	casilla4flor = Model();
	casilla4flor.LoadModel("Models/Blue_Blossom_1101181354.obj");
	casilla5odst = Model();
	casilla5odst.LoadModel("Models/odsthalo.obj");
	casilla6conejo = Model();
	casilla6conejo.LoadModel("Models/conejo.obj");
	casilla7astrid = Model();
	casilla7astrid.LoadModel("Models/Astrid.obj");
	casilla8elite = Model();
	casilla8elite.LoadModel("Models/elite.obj");
	casilla9buho = Model();
	casilla9buho.LoadModel("Models/buho.obj");
	casilla10estoico = Model();
	casilla10estoico.LoadModel("Models/Stoick.obj");
	casilla11cuatro = Model();
	casilla11cuatro.LoadModel("Models/masterchetos.obj");
	casilla12pulpo = Model();
	casilla12pulpo.LoadModel("Models/pulpo.obj");
	casilla13bocon = Model();
	casilla13bocon.LoadModel("Models/Gobber.obj");
	casilla14apeman = Model();
	casilla14apeman.LoadModel("Models/apeman.obj");
	casilla15cuco = Model();
	casilla15cuco.LoadModel("Models/cuco.obj");
	casilla16brutacio = Model();
	casilla16brutacio.LoadModel("Models/Tuffnut.obj");
	casilla17flood = Model();
	casilla17flood.LoadModel("Models/flood.obj");
	casilla18mutt = Model();
	casilla18mutt.LoadModel("Models/mutt.obj");
	casilla19brutilda = Model();
	casilla19brutilda.LoadModel("Models/Ruffnut.obj");
	casilla20rata = Model();
	casilla20rata.LoadModel("Models/ratahalo.obj");
	casilla21tienda = Model();
	casilla21tienda.LoadModel("Models/tienda.obj");
	casilla22patapez = Model();
	casilla22patapez.LoadModel("Models/Fishlegs.obj");
	casilla23flores = Model();
	casilla23flores.LoadModel("Models/flores.obj");
	casilla24pina = Model();
	casilla24pina.LoadModel("Models/pina.obj");
	casilla25casa = Model();
	casilla25casa.LoadModel("Models/Casa_Vikingos.obj");
	casilla26arbusto = Model();
	casilla26arbusto.LoadModel("Models/arbusto.obj");
	casilla27panal = Model();
	casilla27panal.LoadModel("Models/panal.obj");
	casilla28chimuelo = Model();
	casilla28chimuelo.LoadModel("Models/chimuelo.obj");
	casilla29arbol = Model();
	casilla29arbol.LoadModel("Models/arbol.obj");
	casilla30cofre = Model();
	casilla30cofre.LoadModel("Models/cofre.obj");
	casilla31rompehuesos = Model();
	casilla31rompehuesos.LoadModel("Models/rompehuesos.obj");
	casilla32tormenta = Model();
	casilla32tormenta.LoadModel("Models/tormenta.obj");
	casilla33pilar = Model();
	casilla33pilar.LoadModel("Models/pahalo.obj");
	casilla34marin = Model();
	casilla34marin.LoadModel("Models/Marin.obj");
	casilla35huevo = Model();
	casilla35huevo.LoadModel("Models/BuffalordEgg.obj");
	casilla36sc = Model();
	casilla36sc.LoadModel("Models/schalo.obj");
	casilla37moblin = Model();
	casilla37moblin.LoadModel("Models/moblin.obj");
	casilla38patan = Model();
	casilla38patan.LoadModel("Models/Snotlout.obj");
	casilla39halo = Model();
	casilla39halo.LoadModel("Models/halo.obj");
	casilla40zora = Model();
	casilla40zora.LoadModel("Models/zora.obj");
	//==================================================

	/////Tablero///////////////
	Casilla_1 = Model();
	Casilla_1.LoadModel("Models/casilla1.obj");
	Casilla_2 = Model();
	Casilla_2.LoadModel("Models/casilla2.obj");
	Casilla_3 = Model();
	Casilla_3.LoadModel("Models/casilla3.obj");
	Casilla_4 = Model();
	Casilla_4.LoadModel("Models/casilla4.obj");
	Casilla_5 = Model();
	Casilla_5.LoadModel("Models/casilla5.obj");
	Casilla_6 = Model();
	Casilla_6.LoadModel("Models/casilla6.obj");
	Casilla_7 = Model();
	Casilla_7.LoadModel("Models/casilla7.obj");
	Casilla_8 = Model();
	Casilla_8.LoadModel("Models/casilla8.obj");
	Casilla_9 = Model();
	Casilla_9.LoadModel("Models/casilla9.obj");
	Casilla_10 = Model();
	Casilla_10.LoadModel("Models/casilla10.obj");
	Casilla_11 = Model();
	Casilla_11.LoadModel("Models/casilla11.obj");
	Casilla_12 = Model();
	Casilla_12.LoadModel("Models/casilla12.obj");
	Casilla_13 = Model();
	Casilla_13.LoadModel("Models/casilla13.obj");
	Casilla_14 = Model();
	Casilla_14.LoadModel("Models/casilla14.obj");
	Casilla_15 = Model();
	Casilla_15.LoadModel("Models/casilla15.obj");
	Casilla_16 = Model();
	Casilla_16.LoadModel("Models/casilla16.obj");
	Casilla_17 = Model();
	Casilla_17.LoadModel("Models/casilla17.obj");
	Casilla_18 = Model();
	Casilla_18.LoadModel("Models/casilla18.obj");
	Casilla_19 = Model();
	Casilla_19.LoadModel("Models/casilla19.obj");
	Casilla_20 = Model();
	Casilla_20.LoadModel("Models/casilla20.obj");
	Casilla_21 = Model();
	Casilla_21.LoadModel("Models/casilla21.obj");
	Casilla_22 = Model();
	Casilla_22.LoadModel("Models/casilla22.obj");
	Casilla_23 = Model();
	Casilla_23.LoadModel("Models/casilla23.obj");
	Casilla_24 = Model();
	Casilla_24.LoadModel("Models/casilla24.obj");
	Casilla_25 = Model();
	Casilla_25.LoadModel("Models/casilla25.obj");
	Casilla_26 = Model();
	Casilla_26.LoadModel("Models/casilla26.obj");
	Casilla_27 = Model();
	Casilla_27.LoadModel("Models/casilla27.obj");
	Casilla_28 = Model();
	Casilla_28.LoadModel("Models/casilla28.obj");
	Casilla_29 = Model();
	Casilla_29.LoadModel("Models/casilla29.obj");
	Casilla_30 = Model();
	Casilla_30.LoadModel("Models/casilla30.obj");
	Casilla_31 = Model();
	Casilla_31.LoadModel("Models/casilla31.obj");
	Casilla_32 = Model();
	Casilla_32.LoadModel("Models/casilla32.obj");
	Casilla_33 = Model();
	Casilla_33.LoadModel("Models/casilla33.obj");
	Casilla_34 = Model();
	Casilla_34.LoadModel("Models/casilla34.obj");
	Casilla_35 = Model();
	Casilla_35.LoadModel("Models/casilla35.obj");
	Casilla_36 = Model();
	Casilla_36.LoadModel("Models/casilla36.obj");
	Casilla_37 = Model();
	Casilla_37.LoadModel("Models/casilla37.obj");
	Casilla_38 = Model();
	Casilla_38.LoadModel("Models/casilla38.obj");
	Casilla_39 = Model();
	Casilla_39.LoadModel("Models/casilla39.obj");
	Casilla_40 = Model();
	Casilla_40.LoadModel("Models/casilla40.obj");
	/////////////////////////////////////////////
	//////////////PErsonaje/////////////////
	// Model BrazoDH;
	BrazoIH = Model();
	BrazoIH.LoadModel("Models/BrazoI.obj");
	BrazoDH = Model();
	BrazoDH.LoadModel("Models/BrazoD.obj");
	CuerpoH = Model();
	CuerpoH.LoadModel("Models/CuerpoH.obj");
	PiernaDH = Model();
	PiernaDH.LoadModel("Models/PiernaD.obj");
	PiernaIH = Model();
	PiernaIH.LoadModel("Models/PiernaI.obj");
	esferaPI = Model();
	esferaPI.LoadModel("Models/EsferaPI.obj");
	esferaPD = Model();
	esferaPD.LoadModel("Models/EsferaPD.obj");
	esferaBI = Model();
	esferaBI.LoadModel("Models/EsferaI.obj");
	esferaBD = Model();
	esferaBD.LoadModel("Models/EsferaD.obj");
	////////////////////////////////////////////

   //////////////Dados//////////////////////////
	Dado8 = Model();
	Dado8.LoadModel("Models/D8.obj");
	Dado4 = Model();
	Dado4.LoadModel("Models/D4.obj");
	///////////////////////////////////////////


	lampara = Model();
	lampara.LoadModel("Models/lampara.obj");
	dirigible = Model();
	dirigible.LoadModel("Models/dirigible.obj");
	Hdirigible = Model();
	Hdirigible.LoadModel("Models/heliceDirigible.obj");
	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, 0.0f, -1.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f,
		-6.0f, 1.5f, 1.5f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	unsigned int spotLightCount = 0;
	//linterna
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		5.0f);
	spotLightCount++;

	//luz fija
	spotLights[1] = SpotLight(0.0f, 1.0f, 0.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;

	//se crean mas luces puntuales y spotlight 

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
	//inicializando las variables del helicoptero
	movH = -20.0f;
	movHZ = 25;
	movHOffset = .3f;
	rotHelices = 0.0f;
	rotHelicesOffset = 25.0f;
	i = 0;
	rot1 = true;
	rot2 = false;
	rot3 = false;
	rot4 = false;
	vuelta = 0;
	rot = 0;
	//=====================================================================
	//inicializando las variables de de los dados
	rotx = 0;
	rotz = 0;
	roty = 0;
	rotx8 = 0;
	rotz8 = 0;
	roty8 = 0;
	subeD = 20.0f;
	subeDOffset = .5f;
	rotDado = 0.0f;
	rotDadoOffset = 7.0f;
	//=====================================================================
	//inicializando las variables del dirigible
	movD = 75.0f;
	movDZ = 25.0f;
	movDOffset = .3f;
	rotHelicesD = 0.0f;
	rotHelicesDOffset = 25.0f;
	j = 0;
	rot5 = true;
	rot6 = false;
	rot7 = false;
	rot8 = false;
	vuelta2 = 0;
	rotD = 0;
	asignacion = false;
	//=====================================================================
	//inicializando las variables de la animacion de Hipo
	movHipo = 0.0f;
	sumDado = 0.0f;
	casillas = 0;
	movx = 3.9;
	movz = -3.9;
	restante = 0;
	rotH = true;
	rotH2 = false;
	rotH3 = false;
	rotH4 = false;
	valor = false;

	/*arrancar = glfwGetTime();
	arrancar = glfwSetTime(0);*/
	////Loop mientras no se cierra la ventana
	double tiempoActual = glfwGetTime();
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		//Recibir eventos del usuario
		glfwPollEvents();
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();

		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		// luz ligada a la cámara de tipo flash
		//sirve para que en tiempo de ejecución (dentro del while) se cambien propiedades de la luz
		glm::vec3 lowerLight = camera.getCameraPosition();
		lowerLight.y -= 0.3f;
		spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());

		//información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		shaderList[0].SetSpotLights(spotLights, spotLightCount);



		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::mat4 modelaux2(1.0);
		glm::mat4 modelaux3(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[2]->RenderMesh();




		//Helicoptero
		if (rot1) {
			if (movH < 75) {
				if (vuelta == 0) {
					rot = -90;
					vuelta++;
				}

				movH += movHOffset * deltaTime;
				rotHelices -= rotHelicesOffset * deltaTime;
			}
			else {
				rot2 = true;
				rot1 = false;
				rot += 90;
			}
		}
		else if (rot2) {
			if (movHZ > -75) {

				movHZ -= movHOffset * deltaTime;
				rotHelices -= rotHelicesOffset * deltaTime;
			}
			else {
				rot3 = true;
				rot2 = false;
				rot += 90;
			}
		}
		else if (rot3) {
			if (movH > -20) {

				movH -= movHOffset * deltaTime;
				rotHelices -= rotHelicesOffset * deltaTime;
			}
			else {
				rot4 = true;
				rot3 = false;
				rot += 90;
			}
		}
		else if (rot4) {
			if (movHZ < 25) {

				movHZ += movHOffset * deltaTime;
				rotHelices -= rotHelicesOffset * deltaTime;
			}
			else {
				rot1 = true;
				rot4 = false;
				rot += 90;
			}
		}
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(movH, 20.0f, movHZ));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, rot * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		modelaux = model;
		modelaux2 = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cuerpoHelicoptero.RenderModel();
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 4.5f, -6.5f));
		model = glm::rotate(model, rotHelices * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		/*model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));*/
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		HSHelicoptero.RenderModel();
		model = modelaux2;
		model = glm::translate(model, glm::vec3(-0.750f, -0.4f, 25.95f));
		/*model = glm::rotate(model, -90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));*/
		model = glm::rotate(model, rotHelices * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		HTHelicoptero.RenderModel();


		//=========================PERSONAJES=========================
		//Personaje - Link
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(movx, 0.225f, movz));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Link.RenderModel();

		//=========================MODELOS CASILLAS==================
//Casilla 2 - 343 Guilty Spark
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -10.3f));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla2spark.RenderModel();

		//Casilla 3 - Anti-Kirby
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -15.25f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla3kirby.RenderModel();

		//Casilla 4 - Flor del dragón
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, 1.39f, -20.2f));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla4flor.RenderModel();

		//Casilla 5 - Soldado ODST
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -25.15f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla5odst.RenderModel();

		//Casilla 6 - Conejo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -30.1f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla6conejo.RenderModel();

		//Casilla 7 - Astrid
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -35.05f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla7astrid.RenderModel();

		//Casilla 8 - Soldado Elite
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -40.0f));
		model = glm::scale(model, glm::vec3(3.5f, 3.5f, 3.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla8elite.RenderModel();

		//Casilla 9 - Búho
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -44.95f));
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla9buho.RenderModel();

		//Casilla 10 - Estoico
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -49.9f));
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla10estoico.RenderModel();

		//Casilla 11 - Spartan-IV - Esquina 2
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-4.9f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla11cuatro.RenderModel();

		//Casilla 12 - Octorok
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(10.3f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla12pulpo.RenderModel();

		//Casilla 13 - Bocón
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(15.25f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla13bocon.RenderModel();

		//Casilla 14 - Caveman
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(20.2f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla14apeman.RenderModel();

		//Casilla 15 - Cuco
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.15f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(5.5f, 5.5f, 5.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla15cuco.RenderModel();

		//Casilla 16 - Brutacio
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.1f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(4.5, 4.5f, 4.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla16brutacio.RenderModel();

		//Casilla 17 - Espora Flood
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.05f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla17flood.RenderModel();

		//Casilla 18 - Mutt
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(5.5f, 5.5f, 5.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla18mutt.RenderModel();

		//Casilla 19 - Brutilda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(44.95f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla19brutilda.RenderModel();

		//Casilla 20 - Rata
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.9f, -0.39f, -64.3f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla20rata.RenderModel();

		//Casilla 21 - Tienda de Herramientas - Esquina 3
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(3.75f, 3.75f, 3.75f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla21tienda.RenderModel();

		//Casilla 22 - Patapez
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -49.9f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla22patapez.RenderModel();

		//Casilla 23 - Flores Rojas
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -44.95f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla23flores.RenderModel();

		//Casilla 24 - Piña
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, 1.39f, -40.0f));
		model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla24pina.RenderModel();

		//Casilla 25 - Casa
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -35.05f));
		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla25casa.RenderModel();

		//Casilla 26 - Arbustos
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -30.1f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla26arbusto.RenderModel();

		//Casilla 27 - Panal
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, 1.0f, -25.15f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla27panal.RenderModel();

		//Casilla 28 - Chimuelo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -20.2f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla28chimuelo.RenderModel();

		//Casilla 29 - Árbol
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -15.25f));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla29arbol.RenderModel();

		//Casilla 30 - Cofre
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, -0.39f, -10.3f));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla30cofre.RenderModel();

		//Casilla 31 - Rompe Huesos - Esquina 4
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(64.3f, 1.0f, -3.9f));
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.15f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla31rompehuesos.RenderModel();

		//Casilla 32 - Tormenta
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.9f, 1.0f, 5.9f));
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla32tormenta.RenderModel();

		//Casilla 33 - Pillar de Autumn
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(44.95f, 0.39f, 5.9f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla33pilar.RenderModel();

		//Casilla 34 - Marin
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -0.39f, 5.9f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(4.5f, 4.5f, 4.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla34marin.RenderModel();

		//Casilla 35 - Nido huevo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.05f, -0.39f, 5.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla35huevo.RenderModel();

		//Casilla 36 - Supercarguero
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.1f, -0.39f, 5.9f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla36sc.RenderModel();

		//Casilla 37 - Moblin
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.15f, -0.39f, 5.9f));
		model = glm::scale(model, glm::vec3(3.5f, 3.5f, 3.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla37moblin.RenderModel();

		//Casilla 38 - Patán
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(20.2f, -0.39f, 5.9f));
		model = glm::scale(model, glm::vec3(3.5f, 3.5f, 3.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla38patan.RenderModel();

		//Casilla 39 - Instalación 04
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(15.25f, 6.39f, 5.9f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla39halo.RenderModel();

		//Casilla 40 - Zora
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(10.3f, -0.39f, 5.9f));
		model = glm::scale(model, glm::vec3(3.5f, 3.5f, 3.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		casilla40zora.RenderModel();

		//=========================TABLERO=========================
		//Casilla 1 - Salida - Esquina 1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_1.RenderModel();

		//Casilla 2 - 343 Guilty Spark
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -10.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_2.RenderModel();

		//Casilla 3 - Anti-Kirby
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -15.25f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_3.RenderModel();

		//Casilla 4 - Flor del dragón
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -20.2f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_4.RenderModel();

		//Casilla 5 - Soldado ODST
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -25.15f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_5.RenderModel();

		//Casilla 6 - Conejo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -30.1f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_6.RenderModel();

		//Casilla 7 - Astrid
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -35.05f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_7.RenderModel();

		//Casilla 8 - Soldado Elite
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -40.0f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_8.RenderModel();

		//Casilla 9 - Búho
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -44.95f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_9.RenderModel();

		//Casilla 10 - Estoico
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -49.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_10.RenderModel();

		//Casilla 11 - Spartan-IV - Esquina 2
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(3.9f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_11.RenderModel();

		//Casilla 12 - Octorok
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(10.3f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_12.RenderModel();

		//Casilla 13 - Bocón
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(15.25f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_13.RenderModel();

		//Casilla 14 - Caveman
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(20.2f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_14.RenderModel();

		//Casilla 15 - Cuco
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.15f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_15.RenderModel();

		//Casilla 16 - Brutacio
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.1f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_16.RenderModel();

		//Casilla 17 - Espora Flood
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.05f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_17.RenderModel();

		//Casilla 18 - Mutt
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_18.RenderModel();

		//Casilla 19 - Brutilda
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(44.95f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_19.RenderModel();

		//Casilla 20 - Rata
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.9f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_20.RenderModel();

		//Casilla 20 - Tienda de Herramientas - Esquina 3
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -56.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_21.RenderModel();

		//Casilla 22 - Patapez
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -49.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_22.RenderModel();

		//Casilla 23 - Flores Rojas
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -44.95f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_23.RenderModel();

		//Casilla 24 - Piña
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -40.0f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_24.RenderModel();

		//Casilla 25 - Casa
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -35.05f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_25.RenderModel();

		//Casilla 26 - Árboles
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -30.1f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_26.RenderModel();

		//Casilla 27 - Panal
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -25.15f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_27.RenderModel();

		//Casilla 28 - Chimuelo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -20.2f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_28.RenderModel();

		//Casilla 29 - Árboles
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -15.25f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_29.RenderModel();

		//Casilla 30 - Cofre
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -10.3f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_30.RenderModel();

		//Casilla 31 - Rompe Huesos - Esquina 4
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.3f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_31.RenderModel();

		//Casilla 32 - Tormenta
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(49.9f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_32.RenderModel();

		//Casilla 33 - Pillar de Autumn
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(44.95f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_33.RenderModel();

		//Casilla 34 - Marin
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(40.0f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_34.RenderModel();

		//Casilla 35 - Nido huevo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(35.05f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_35.RenderModel();

		//Casilla 36 - Supercarguero
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.1f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_36.RenderModel();

		//Casilla 37 - Moblin
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.15f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_37.RenderModel();

		//Casilla 38 - Patán
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(20.2f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_38.RenderModel();

		//Casilla 39 - Instalación 04
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(15.25f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_39.RenderModel();

		//Casilla 40 - Zora
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(10.3f, -0.39f, -3.9f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Casilla_40.RenderModel();


		/////////////////////////Dados///////////////////////////////////////////
		//bloque de codigo para que lso dados muestren sus caras de forma aleatori
		if (mainWindow.getTURN_ON_OFF3() == true) {
			if (subeD > 1) {
				subeD -= subeDOffset * deltaTime;
				rotDado -= rotDadoOffset * deltaTime;
				rotx = rotDado;
				rotz = rotDado;
				rotx8 = rotDado;
				rotz8 = rotDado;
				asignacion = false;
			}
			else if (subeD < 1 && !asignacion) {
				randomNum = random_number(1, 4);
				rotx = 0;
				rotz = 0;
				roty = 0;
				rotx8 = 0;
				rotz8 = 0;
				roty8 = 0;
				randomNum8 = random_number(1, 8);

				Giro rotSelect = Vista_Caras_4[randomNum - 1];
				Giro rotSelect2 = Vista_Caras_8[randomNum8 - 1];
				sumDado = randomNum + randomNum8;
				sumDado = sumDado * 5;
				printf("Suma de dados: %f\n", sumDado);
				rotx = rotSelect.x;
				rotz = rotSelect.z;
				roty = rotSelect.y;
				rotx8 = rotSelect2.x;
				rotz8 = rotSelect2.z;
				roty8 = rotSelect2.y;
				asignacion = true;
				valor = true;
			}


		}
		else if (mainWindow.getTURN_ON_OFF4() == true) {
			if (subeD < 20) {
				subeD += subeDOffset * deltaTime;
				rotx = 0;
				rotz = 0;
				roty = 0;
				rotx8 = 0;
				rotz8 = 0;
				roty8 = 0;
			}
		}



		//dado 4
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(30.0f, subeD, -015.0f));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, rotx * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, roty * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotz * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		D4.UseTexture();
		meshList[5]->RenderMesh();



		//////dado 8
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, subeD, -015.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, rotx8 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, roty8 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotz8 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Dado8.RenderModel();
		//=======================================================
		////////////////////ILUMINACION/////////////////////////////////////////
		//lampara 1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.6, 0.1f, -0.75));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampara.RenderModel();
		//lampara 2
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(59.4f, 0.1f, -0.75));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampara.RenderModel();
		//lampara 3
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.6, 0.1f, -59.4f));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampara.RenderModel();
		//lampara 4
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(59.4f, 0.1f, -59.4f));
		model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		lampara.RenderModel();
		//////////////////////////////////////////////////////////////////////////////////
		// 
		// 
		// //animacion dirigible//
		if (rot5) {
			if (movDZ > -75) {
				if (vuelta2 == 0) {
					rotD = 180;
					vuelta2++;
				}

				movDZ -= movDOffset * deltaTime;
				rotHelicesD -= rotHelicesDOffset * deltaTime;
			}
			else {
				rot6 = true;
				rot5 = false;
				rotD += 90;
			}
		}
		else if (rot6) {
			if (movD > -20) {

				movD -= movDOffset * deltaTime;
				rotHelicesD -= rotHelicesDOffset * deltaTime;
			}
			else {
				rot7 = true;
				rot6 = false;
				rotD += 90;
			}
		}
		else if (rot7) {
			if (movDZ < 25) {

				movDZ += movDOffset * deltaTime;
				rotHelicesD -= rotHelicesDOffset * deltaTime;
			}
			else {
				rot8 = true;
				rot7 = false;
				rotD += 90;
			}
		}
		else if (rot8) {
			if (movD < 75) {

				movD += movDOffset * deltaTime;
				rotHelicesD -= rotHelicesDOffset * deltaTime;
			}
			else {
				rot5 = true;
				rot8 = false;
				rotD += 90;
			}
		}
		// //Dirigible referencia inicial 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(movD, 18.0f, movDZ));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, rotD * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		modelaux = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		dirigible.RenderModel();

		//Hélice Dirigible 1
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.57f, 3.1f, 0.85f));
		model = glm::rotate(model, rotHelicesD * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hdirigible.RenderModel();

		//Hélice Dirigible 2
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.9f, -0.54f, 0.85f));
		model = glm::rotate(model, rotHelicesD * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hdirigible.RenderModel();

		//Hélice Dirigible 3
		model = modelaux;
		model = glm::translate(model, glm::vec3(2.1f, -0.46f, 0.85f));
		model = glm::rotate(model, rotHelicesD * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hdirigible.RenderModel();
		//=======================================================
		//Recorrido en el tablero , falta ajustar la rotacion 
		//ajustar rotacions de brazos, piernas
		//que se asemeje el movimiento de caminata y no de teletransportacion
		if (valor) {
			if (rotH) {
				if ((sumDado + (-1 * movz)) < 56.4) {
					movz = movz - sumDado;
				}
				else {
					restante = sumDado + (-1 * movz) - 56.4;
					movz = -56.4;
					movx = movx + restante;
					rotH = false;
					rotH2 = true;
					rotHipo += 90;
				}
			}
			else if (rotH2) {
				if ((sumDado + movx) < 56.4) {
					movx = movx + sumDado;
				}
				else {
					movx = 56.4;
					restante = sumDado + movx - 56.4;
					movz = movz + restante;
					rotH2 = false;
					rotH3 = true;
					rotHipo += 90;
				}
			}
			else if (rotH3) {
				if ((sumDado + movz) < -3.9) {
					movz = movz + sumDado;
				}
				else {
					movz = -3.9;
					restante = sumDado + movz - 3.9;
					movx = movx - restante;
					rotH3 = false;
					rotH4 = true;
					rotHipo += 90;
				}
			}
			else if (rotH4) {
				if ((sumDado - movx) > 3.9) {
					movx = movx - sumDado;
				}
				else {
					movx = 3.9;
					restante = movx - sumDado - 3.9;
					movz = movz + restante;
					rotH4 = false;
					rotH = true;
					rotHipo += 90;
				}
			}
			valor = false;
		}


		//// //Hipo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(movx, 3.1f, movz));
		//model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));

		////model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//modelaux = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//CuerpoH.RenderModel();
		//////esferaBD
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(0.175f, 0.425f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//esferaBD.RenderModel();
		//////BrazoD
		//model = modelaux2;
		//model = glm::translate(model, glm::vec3(-0.35f, 0.0f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//BrazoDH.RenderModel();

		//////esferaBI
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(-0.15f, 0.425f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//esferaBI.RenderModel();

		//////BrazoI
		//model = modelaux2;
		//model = glm::translate(model, glm::vec3(0.35f, 0.0f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//BrazoIH.RenderModel();

		//////esferaPD
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(0.085f, -0.065f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//esferaBD.RenderModel();
		////////PiernaD
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(-0.085f, -0.1f, 0.05f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//PiernaDH.RenderModel();


		//////esferaPI
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(-0.065f, -0.065f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//esferaBI.RenderModel();
		////////PiernaI
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(0.105f, -0.1f, 0.0f));
		//modelaux2 = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//PiernaIH.RenderModel();
		////=========================================================

		glDisable(GL_BLEND);
		tiempoActual = glfwGetTime();
		srand(time(0));




		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}