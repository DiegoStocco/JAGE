#include <stdio.h>

#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include "errors.h"

// Function to be executed on every GL error occurrence
static void GLAPIENTRY MessageCallbackGL (
                 GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

void enable_gl_errors()
{
  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback(MessageCallbackGL, 0);
}

// Function to be executed on every GLFW error occurrence
static void MessageCallbackGLFW(int error, const char* description)
{
  fprintf(stderr, "GLFW Error: %s\n", description);
}

void enable_glfw_errors()
{
    glfwSetErrorCallback(MessageCallbackGLFW);
}
