#ifndef BASIC_INSTANCE_READER_H_
#define BASIC_INSTANCE_READER_H_

#pragma once;

#include "reader.h"
#include "N3LDG.h"
#include <sstream>

class InstanceReader : public Reader {
    Instance *getNext() {
        m_instance_.clear();
        std::string m_str_line;
        if (!my_getline(m_inf_, m_str_line))
            return nullptr;
        if (m_str_line.empty())
            return nullptr;
        std::vector<std::string> vec_info;
        split_bychars(m_str_line, vec_info, "\t");
        m_instance_.m_label_ = vec_info.at(0);

        split_bychar(vec_info.at(1), m_instance_.m_words_, ' ');
        return &m_instance_;
    }
};

#endif // BASIC_INSTANCE_READER_H_