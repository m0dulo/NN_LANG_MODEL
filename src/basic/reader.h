#ifndef BASIC_READER_H_
#define BASIC_READER_H_

#pragma once;

#include <fstream>
#include <iostream>
#include "instance.h"

class Reader {
protected:
    std::ifstream m_inf_;
    int m_instance_num_;
    Instance m_instance_;
public:
    int startRead(const char *filename) {
        if (m_inf_.is_open()) {
            m_inf_.close();
            m_inf_.clear();
        }
        m_inf_.open(filename);

        if (!m_inf_.is_open()) {
            std::cout << "Reader::startRead() open file err!" << filename << std::endl;
            return -1;
        }
        return 0;
    }

    void finishRead() {
        if (m_inf_.is_open()) {
            m_inf_.close();
            m_inf_.clear();
        }
    }

    virtual ~Reader() {
        if (m_inf_.is_open())
            m_inf_.close();
    }

    virtual Instance *getNext() = 0;
};

#endif // BASIC_READER_H_