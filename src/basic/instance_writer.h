#ifndef BASIC_INSTANCE_WRITER_H_
#define BASIC_INSTANCE_WRITER_H_

#pragma once;

#include <sstream>
#include "writer.h"

class InstanceWriter : public Writer {
public:
    int writer(const Instance *pInstance) {
        if (!m_outf_.is_open())
            return -1;
        const std::string &label = pInstance -> m_label_;
        m_outf_ << label << "\t";
        std::vector<std::string> words = pInstance -> m_words_;
        int word_size = words.size();
        for (int idx = 0; idx < word_size; ++idx) {
            m_outf_ << words.at(idx) << " ";
        }
        m_outf_ << std::endl;
        return 0;
    }
};

#endif // BASIC_INSTANCE_WRITER_H_