//
// Created by Michał Łaszczewski on 06/09/16.
//

#ifndef FGFX_CONFIG_H
#define FGFX_CONFIG_H

#ifdef EMSCRIPTEN
  #include <emscripten.h>
  #define fgfx_log(...) emscripten_log(EM_LOG_ERROR, __VA_ARGS__)
  #define FGFX_API EMSCRIPTEN_KEEPALIVE
#endif
#ifndef EMSCRIPTEN
  #include <stdio.h>
  #define fgfx_log(...) printf(__VA_ARGS__); printf("\n");
  #define FGFX_API
#endif

#ifdef __USE_OPENGL
  #include <OpenGL/gl.h>

#endif
#ifndef __USE_OPENGL
  #include <GLES2/gl2.h>
  #include <EGL/egl.h>
#endif

#endif //BRICKS_CONFIG_H