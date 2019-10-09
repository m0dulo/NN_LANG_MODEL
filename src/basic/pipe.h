#ifndef BASIC_PIPE_H_
#define BASIC_PIPE_H_

#pragma once;

#include "instance.h"
#include "instance_reader.h"
#include "instance_writer.h"

class Pipe {
protected:
    Reader *m_reader_;
    Writer *m_writer_;
public:
    int max_sentence_size_;

    Pipe() {
        m_reader_ = new InstanceReader();
        m_writer_ = new InstanceWriter();
        max_sentence_size_ = 256;
    }

    ~Pipe() {
        if (m_reader_)
            delete m_reader_;
        if (m_writer_)
            delete m_writer_;
    }

    int init_inputFile(const char *filename) {
        if (0 != m_reader_ -> startRead(filename))
            return -1;
        return 0;
    }

    void uninit_inputFile() {
        if (m_writer_)
            m_reader_ -> finishRead();
    }

    int init_outputFile(const char *filename) {
        if (0 != m_writer_-> startWrite(filename))
            return -1;
        return 0;
    }

    void uninit_outputFile() {
        if (m_writer_)
            m_writer_ -> finishWrite();
    }

    Instance *nextInstance() {
        Instance *pInstance = m_reader_ -> getNext();
        if (!pInstance)
            return 0;
        return pInstance;
    }

    void readInstances(const std::string &m_infile, std::vector<Instance> &vec_instances, int maxInstance = -1) {
        vec_instances.clear();
        init_inputFile(m_infile.c_str());
        Instance *pInstance = nextInstance();

        int instance_num = 0;

        while (pInstance) {
            Instance train_instance;
            train_instance.copyValuesFrom(*pInstance);
            vec_instances.push_back(train_instance);
            instance_num++;

            if (instance_num == maxInstance) {
                break;
            }

            pInstance = nextInstance();
        }
        uninit_inputFile();
        std::cout << std::endl;
        std::cout << "Instance Num: " << instance_num << std::endl; 
    }


};

#endif // BASIC_PIPE_H_