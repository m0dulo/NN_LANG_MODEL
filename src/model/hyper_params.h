#ifndef NN_LANG_MODEL_SRC_MODEL_HYPER_PARAMS_H_
#define NN_LANG_MODEL_SRC_MODEL_HYPER_PARAMS_H_

#pragma once;

#include "N3LDG.h"
#include "options.h"

struct HyperParams {
private:
    bool bAssigned_;
public:
    int batch_size_;

    dtype nn_regular_;
    dtype ada_alpha_;
    dtype ada_eps_;

    int hidden_size_;
    int word_context_;
    int word_window_;
    int window_output;
    dtype drop_prob_;

    int word_dim_;
    int label_size_;
    int input_size_;

    HyperParams() {
        bAssigned_ = false;
        batch_size_ = 1;
    }

    void setParams(Options &op) {
        nn_regular_ = 
    }

};

#endif // NN_LANG_MODEL_SRC_MODEL_HYPER_PARAMS_H_