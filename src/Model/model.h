#ifndef CPP4_3D_VIEWER_V2_0_1_SRC_MODEL_MODEL_H_
#define CPP4_3D_VIEWER_V2_0_1_SRC_MODEL_MODEL_H_

#include <locale.h>

#include <cmath>
#include <cstring>
#include <fstream>
#include <vector>

namespace s21 {
class Model {
 public:
  /// @brief Главная функция
  /// @param filename name obj file
  /// @return error
  void Parse(std::string filename);

  /// @brief Функция нахождения min and max
  /// @param counter_axis counter of current axis
  /// @param coord current coordinate
  void MinMaxCoord(int counter_axis, double coord);

  /// @brief Функция установки модели по центру экрана
  void SettingToCenter();

  /// @brief Функция масштабирования
  /// coefficient of scale
  /// @param scale scale
  void SetScale(double scale);

  /// @brief Функция сдвига по X
  /// @param angle
  void RotationX(double angle);

  /// @brief Функция сдвига по Y
  /// @param angle
  void RotationY(double angle);

  /// @brief Функция сдвига по Z
  /// @param angle
  void RotationZ(double angle);

  /// @brief Функция перемещения модели
  /// @param a coefficient
  /// @param i axis
  void Move(double a, unsigned i);

  /// @brief Функция получения точек и полигонов модели
  /// @return pair of array
  std::pair<double*, unsigned*> GetArr();

  /// @brief Получение размеров массива
  /// @return pair size
  std::pair<unsigned, unsigned> GetSize();

  Model() = default;

  ~Model() = default;

 private:
  std::vector<double> vertex_vector_;
  std::vector<unsigned> polygons_vector_;
  double minmaxX_[2] = {0};
  double minmaxY_[2] = {0};
  double minmaxZ_[2] = {0};
  double Normalize();
  void ParseVertex(char* ptr);
  void ParsePolygons(char* ptr);
};
}  // namespace s21

#endif  // CPP4_3D_VIEWER_V2_0_1_SRC_MODEL_MODEL_H_
