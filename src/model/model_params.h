#ifndef NN_LANG_MODEL_SRC_MODEL_MODEL_PARAMS_H_
#define NN_LANG_MODEL_SRC_MODEL_MODEL_PARAMS_H_

#include "hyper_params.h"

struct ModelParams {
    Alphabet word_alpha;
    LookupTable lookup_table;
    LSTM1Params lstm_params;
    UniParams linear_params;

    bool init(HyperParams &op) {
        if (lookup_table.nVSize <= 0) {
            return false;
        }
        op.word_dim_ = lookup_table.nDim;
        lstm_params.init(op.hidden_size_, op.word_dim_);
        linear.init(op.word_dim_, op.hidden_size_, false);

        return true;
    }

    void exportModelParams(ModelUpdate &ada) {
        lookup_table.exportAdaParams(ada);
        lstm_params.exportAdaParams(ada);
        linear_params.exportAdaParams(ada);
    } 
};

#endif // NN_LANG_MODEL_SRC_MODEL_MODEL_PARAMS_H_