#ifndef BASIC_EXAMPLE_H_
#define BASIC_EXAMPLE_H_

#pragma once;

#include <iostream>
#include <vector>

class Feature {
public:
    std::vector<std::string> m_words_;
    std::vector<std::string> m_sparse_feats_;

    void clear() {
        m_words_.clear();
        m_sparse_feats_.clear();
    }
};

class Example {
public:
    Feature m_feature_;
    std::vector<dtype> m_label_;

    void clear() {
        m_feature_.clear();
        m_label_.clear();
    }

};

#endif // BASIC_EXAMPLE_H_