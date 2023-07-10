#ifndef CPP4_3D_VIEWER_V2_0_1_SRC_CONTROLLER_SINGLETON_H_
#define CPP4_3D_VIEWER_V2_0_1_SRC_CONTROLLER_SINGLETON_H_

#include "controller.h"

namespace s21 {

class Singleton {
 public:
  static Singleton* Instance() {
    static Singleton* instance = new Singleton;
    return instance;
  }
  Controller* GetController() { return controller; }

 protected:
  Singleton() { controller = new Controller(); }
  ~Singleton() { delete controller; }

 private:
  Controller* controller;
};
}  // namespace s21

#endif  // CPP4_3D_VIEWER_V2_0_1_SRC_CONTROLLER_SINGLETON_H_
