#ifndef BASIC_INSTANCE_H_
#define BASIC_INSTANCE_H_

#pragma once;

#include "N3LDG.h"

class Instance {
public:
    std::vector<std::string> m_words_;
    std::vector<std::string> m_sparse_feats_;
    std::string m_label_;

    void clear() {
        m_words_.clear();
        m_sparse_feats_.clear();
        m_label_.clear();
    }

    void evaluate(const std::string &predict_label, Metric &eval) const {
        if (predict_label == m_label_)
            eval.correct_label_count++;
        eval.overall_label_count++;
    }

    void copyValuesFrom(const Instance &anInstance) {
        allocate(anInstance.size());
        m_label_ = anInstance.m_label_;
        m_words_ = anInstance.m_words_;
        m_sparse_feats_ = anInstance.m_sparse_feats_;
    }

    void assignLabel(const std::string &result_label) {
        m_label_ = result_label;
    }

    int size() const {
        return m_words_.size();
    }

    void allocate(int len) {
        clear();
        m_words_.resize(len);
    }
};

#endif // BASIC_INSTANCE_H_