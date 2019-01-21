#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertexm;

Vertexm vertex[12];
GLubyte triangles[8];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	//triangle 1
	vertex[0].coordinate[0] = -0.5f;
	vertex[0].coordinate[1] = -0.5f;
	vertex[0].coordinate[2] = 0.0f;

	vertex[1].coordinate[0] = -0.5f;
	vertex[1].coordinate[1] = 0.5f;
	vertex[1].coordinate[2] = 0.0f;


	vertex[2].coordinate[0] = 0.5f;
	vertex[2].coordinate[1] = 0.5f;
	vertex[2].coordinate[2] = 0.0f;

	//triangle 2
	vertex[3].coordinate[0] = 0.5f; 
	vertex[3].coordinate[1] = 0.5f;  
	vertex[3].coordinate[2] = 0.0f;


	vertex[4].coordinate[0] = 0.5f; 
	vertex[4].coordinate[1] = -0.5f;  
	vertex[4].coordinate[2] = 0.0f;

	vertex[5].coordinate[0] = -0.5f; 
	vertex[5].coordinate[1] = -0.5f;  
	vertex[5].coordinate[2] = 0.0f;

	//triangle 3
	vertex[6].coordinate[0] = -0.5;
	vertex[6].coordinate[1] = -0.5;
	vertex[6].coordinate[2] = 0;

	vertex[7].coordinate[0] = -0.5;
	vertex[7].coordinate[1] = 0.5;
	vertex[7].coordinate[2] = 0;

	vertex[8].coordinate[0] = -0.5;
	vertex[8].coordinate[1] = -0.5;
	vertex[8].coordinate[2] = -1;

	//trinagle 4
	vertex[9].coordinate[0] = -.5;
	vertex[9].coordinate[1] = .5;
	vertex[9].coordinate[2] = 0;

	vertex[10].coordinate[0] = -.5;
	vertex[10].coordinate[1] = .5;
	vertex[10].coordinate[2] = -1;

	vertex[11].coordinate[0] -.5;
	vertex[11].coordinate[1] -.5;
	vertex[11].coordinate[2] - 1;

	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 1;
	vertex[6].color[1] = 0;
	vertex[6].color[2] = 0;

	vertex[7].color[0] = 1;
	vertex[7].color[1] = 0;
	vertex[7].color[2] = 0;

	vertex[8].color[0] = 1;
	vertex[8].color[1] = 0;
	vertex[8].color[2] = 0;

	vertex[9].color[0] = 0;
	vertex[9].color[1] = 0;
	vertex[9].color[2] = 1;

	vertex[10].color[0] = 0;
	vertex[10].color[1] = 0;
	vertex[10].color[2] = 1;

	vertex[11].color[0] = 0;
	vertex[11].color[1] = 0;
	vertex[11].color[2] = 1;
	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;
	triangles[6] = 6;   triangles[7] = 7;

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertexm) * 12, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 8, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R));
	{
		rotate();
	}
	//if (elapsed.asSeconds() >= 1.0f)
	//{
	//	clock.restart();

	//	if (!flip)
	//	{
	//		flip = true;
	//	}
	//	else
	//		flip = false;
	//}

	//if (flip)
	//{
	//	rotationAngle += 0.005f;

	//	if (rotationAngle > 360.0f)
	//	{
	//		rotationAngle -= 360.0f;
	//	}
	//}

	////Change vertex data
	//vertex[0].coordinate[0] += -0.0001f;
	//vertex[0].coordinate[1] += -0.0001f;
	//vertex[0].coordinate[2] += -0.0001f;

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 12, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertexm), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertexm), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

void Game::rotate()
{
	MyVector3 vect;
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			
		}
	}
}

