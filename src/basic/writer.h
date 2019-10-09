#ifndef BASIC_WRITER_H_
#define BASIC_WRITER_H_

#pragma once;

#include <fstream>
#include <iostream>
#include "instance.h"

class Writer {
protected:
    std::ofstream m_outf_;

public:
    int startWrite(const char *filename) {
        m_outf_.open(filename);
        if (!m_outf_) {
            std::cout << "Writer::startWrite() open file err" << filename << endl;
            return -1;
        }

        return 0;
    }

    void finishWrite() {
        m_outf_.close();
    }

    virtual int write(const Instance *pInstance) = 0;

    virtual ~Writer() {
        if (m_outf_.is_open()) 
            m_outf_.close();
    }
};

#endif // BASIC_WRITER_H_