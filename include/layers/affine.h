#ifndef INCLUDE_LAYERS_AFFINE_H_
#define INCLUDE_LAYERS_AFFINE_H_

#include <string>

#include "layers/param_layer.h"
#include "transforms/activation.h"
#include "utils/common.h"

namespace blitz {

template<template <typename> class TensorType, typename DType>
class Affine : public ParamLayer<TensorType, DType> {
 public:
  explicit Affine(
    const string& name, const string& filler_name,
    const string& optimizer_name,
    shared_ptr<Activation<TensorType, DType> > activation,
    size_t nout, const string& kernel = "blas") :
    ParamLayer<TensorType, DType>(name, filler_name,
    optimizer_name, activation), nout_(nout), kernel_(kernel) {}
  ~Affine() {}

  virtual void InitImpl(const Shape& input_shape);
  virtual void ForwardPropImpl(shared_ptr<TensorType<DType> > forward_input);
  virtual void BackwardPropImpl(shared_ptr<TensorType<DType> > backward_input);

 private:
  size_t nout_;

  const string kernel_;

  DISABLE_COPY_AND_ASSIGN(Affine);
};

}  // namespace blitz

#endif  // INCLUDE_LAYERS_AFFINE_H_