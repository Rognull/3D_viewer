#include "decorator.h"

namespace s21 {
std::pair<double *, unsigned *> Decorator::Convert(Model *model,
                                                   std::string filename) {
  try {
    model->Parse(filename);
  } catch (std::exception &ex) {
    std::cout << "Error " << ex.what() << std::endl;
  }

  return model->GetArr();
}
}  // namespace s21
