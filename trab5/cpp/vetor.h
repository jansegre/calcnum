#ifndef CALCNUM_VETOR_H
#define CALCNUM_VETOR_H

#include <iostream>

using std::ostream;
using std::istream;

// Vetor de ordem n de elementos do tipo T
template<typename T>
class VetorT {
 public:
  VetorT(const int n) : n_(n), vetor_(new T[n]) {}
  ~VetorT() { delete[] vetor_; }

  // Operador para acessar o elemento i, chamando v(i),
  // Se i estiver fora tamanho do vetor o comportamento
  // não é definido, pode ocorrer erro de acesso na memória
  T &operator()(const int i) { return vetor_[i - 1]; }
  T operator()(const int i) const { return vetor_[i - 1]; }

  // Método para ler a ordem do vetor.
  inline int n() const { return n_; }

 private:
  int n_;
  T *vetor_;
};

// Definindo como imprimir um vetor
template<typename T>
ostream& operator<< (ostream& out, const VetorT<T> &vetor) {
  out << '[';
  for (int i = 1; i < vetor.n(); ++i)
    out << vetor(i) << ", ";
  out << vetor(vetor.n());
  out << ']';
  return out;
}

// Definindo como ler um vetor
template<typename T>
istream& operator>> (istream& in, VetorT<T> &vetor) {
  int n = vetor.n();
  for (int i = 1; i <= n; ++i)
    in >> vetor(i);
  return in;
}

#ifdef USAR_FLOAT
typedef VetorT<float> Vetor;
#elif USAR_LONG_DOUBLE
typedef VetorT<long double> Vetor;
#else
typedef VetorT<double> Vetor;
#endif

#endif

