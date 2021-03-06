#include "Layer.h"


namespace fgfx {

  Layer::Layer(Engine *enginep) :  engine(enginep), composition(2),
    frozen(false), visible(true), camera(false) {
  }

  Layer::~Layer() {
  }

  void Layer::setFrozen(bool frozenp) {
    frozen = frozenp;
  }
  void Layer::setComposition(int compositionp) {
    composition = compositionp;
  }
  void Layer::setCamera(bool camerap) {
    camera = camerap;
  }
  void Layer::setVisible(bool visiblep) {
    visible = visiblep;
  }

  bool Layer::isVisible() {
    return visible;
  }

};
