#ifndef NN_LANG_MODEL_SRC_MODEL_COMPUTION_GRAPH_H_
#define NN_LANG_MODEL_SRC_MODEL_COMPUTION_GRAPH_H_

#include "hyper_params.h"
#include "model_params.h"

struct GraphBuilder {
    DynamicLSTMBuilder encoder;
    std::vector<Node *> lookup_nodes;

    void forward(Graph &graph, ModelParams )
};



#endif // NN_LANG_MODEL_SRC_MODEL_COMPUTION_GRAPH_H_