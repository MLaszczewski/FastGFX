#ifndef TextureTransitionLAYER_H
#define TextureTransitionLAYER_H

#include "Texture.h"
#include "TextureTransitionBuffer.h"
#include "Layer.h"
#include <glm/glm.hpp>
#include <vector>
#include <map>
#include <string>
#include <memory>

#include "shaders.h"

namespace fgfx {

  class Engine;

  class TextureTransitionLayer : public Layer {
  protected:
    std::vector<TextureTransitionBuffer*> buffers;

    friend class Engine;
    friend class TextureTransitionBuffer;

    static GLuint textureTransitionProgram;
    static GLuint textureTransitionProgramAttribPosition;
    static GLuint textureTransitionProgramAttribColor;
    static GLuint textureTransitionProgramAttribCoord1;
    static GLuint textureTransitionProgramAttribCoord2;
    static GLuint textureTransitionProgramUniformCameraMatrix;
    static GLuint textureTransitionProgramUniformSampler;

    static void initializeTextureTransitionProgram();
    void beginDraw(glm::mat4 cameraMatrix);
    void endDraw();
  public:
    TextureTransitionLayer(Engine* enginep);

    void bufferTextureTransitionPoint(const std::shared_ptr<Texture>& texture, glm::vec2 point, glm::vec4 color,
                                      glm::vec3 coord1, glm::vec3 coord2);
    void bufferTextureTransitionPoint(const std::shared_ptr<Texture>& texture, glm::vec3 point, glm::vec4 color,
                                      glm::vec3 coord1, glm::vec3 coord2);
    TextureTransitionBuffer* getBuffer(int textureId);
    TextureTransitionBuffer* getBuffer(const std::shared_ptr<Texture>& texture);

    virtual void reset() override ;
    virtual void upload() override ;
    virtual void render(glm::mat4 cameraMatrix) override ;
  };

}
#endif // TextureTransitionLAYER_H
