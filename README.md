## Just Another Game Engine

### Dependencies:
#### Libraries:
- glfw
- glew
- glm

#### Tools:
- clang (gcc does not work at the moment)
- ar

### How to build:
#### Linux:

Run the makefile:
```
cd JAGE
make
```
Now you can link the resulting jage.a file with your application.
*Note: You need to specify the -lglfw -lGLEW -lGL flags.*
``` clang++ jage.a your_application.cpp -lglfw -lGLEW -lGL -o your_application ```

#### Windows:
You're a loser
