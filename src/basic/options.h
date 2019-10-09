#ifndef BASIC_OPTIONS_H_
#define BASIC_OPTIONS_H_

#pragma once;

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "N3LDG.h"

class Options {
public:
    int word_cut_off_;
    int feat_cut_off_;
    dtype init_range_;
    int max_iter_;
    int batch_size_;
    dtype ada_eps_;
    dtype ada_alpha_;
    dtype reg_parameter_;
    dtype drop_prob_;

    int hidden_size_;
    int word_emb_size_;
    int word_context_;
    bool word_emb_fine_tune_;

    int cnn_layer_size_;
    int verbose_iter_;
    bool save_inter_mediate_;
    bool train_;
    int max_instance_;
    std::vector<std::string> test_files_;
    std::string out_best_;
    bool seg_;

    std::string word_file_;

    Options() {
        word_cut_off_ = 0;
        feat_cut_off_ = 0;
        init_range_ = 0.01;
        max_iter_ = 1000;
        batch_size_ = 1;
        ada_eps_ = 1e-6;
        ada_alpha_ = 0.01;
        reg_parameter_ = 1e-8;
        drop_prob_ = 0.0;

        hidden_size_ = 100;
        word_emb_size_ = 50;
        word_context_ = 2;
        word_emb_fine_tune_ = true;

        cnn_layer_size_ = 2;
        verbose_iter_ = 100;
        save_inter_mediate_ = true;
        train_ = false;
        max_instance_ = -1;
        test_files_.clear();
        out_best_ = "";
        seg_ = false;

        word_file_ = "";
    }

    void setOptions(const std::vector<std::string> &vec_option) {
        int i = 0;
        for (; i < vec_option.size(); ++i) {
            std::pair<std::string, std::string> pr;
            string2pair(vec_option.at(i), pr, '=');
           if (pr.first == "wordCutOff")
                word_cut_off_ = atoi(pr.second.c_str());
            if (pr.first == "featCutOff")
                feat_cut_off_ = atoi(pr.second.c_str());
            if (pr.first == "initRange")
                init_range_ = atof(pr.second.c_str());
            if (pr.first == "maxIter")
                max_iter_ = atoi(pr.second.c_str());
            if (pr.first == "batchSize")
                batch_size_ = atoi(pr.second.c_str());
            if (pr.first == "adaEps")
                ada_eps_ = atof(pr.second.c_str());
            if (pr.first == "adaAlpha")
                ada_alpha_ = atof(pr.second.c_str());
            if (pr.first == "regParameter")
                reg_parameter_ = atof(pr.second.c_str());
            if (pr.first == "dropProb")
                drop_prob_ = atof(pr.second.c_str());
            if (pr.first == "hiddenSize")
                hidden_size_ = atoi(pr.second.c_str());
            if (pr.first == "wordcontext")
                word_context_ = atoi(pr.second.c_str());
            if (pr.first == "wordEmbSize")
                word_emb_size_ = atoi(pr.second.c_str());
            if (pr.first == "wordEmbFineTune")
                word_emb_fine_tune_ = (pr.second == "true") ? true : false;
            if (pr.first == "cnnLayerSize")
                cnn_layer_size_ = atoi(pr.second.c_str());
            if (pr.first == "verboseIter")
                verbose_iter_ = atoi(pr.second.c_str());
            if (pr.first == "train")
                train_ = (pr.second == "true") ? true : false;
            if (pr.first == "saveIntermediate")
                save_inter_mediate_ = (pr.second == "true") ? true : false;
            if (pr.first == "maxInstance")
                max_instance_ = atoi(pr.second.c_str());
            if (pr.first == "testFile")
                test_files_.push_back(pr.second);
            if (pr.first == "outBest")
                out_best_ = pr.second;
            if (pr.first == "seg")
                seg_ = (pr.second == "true") ? true : false;
            if (pr.first == "wordFile")
                word_file_ = pr.second;
        }
    }

     void showOptions() {
        std::cout << "wordCutOff = " << word_cut_off_ << std::endl;
        std::cout << "featCutOff = " << feat_cut_off_ << std::endl;
        std::cout << "initRange = " << init_range_ << std::endl;
        std::cout << "maxIter = " << max_iter_ << std::endl;
        std::cout << "batchSize = " << batch_size_ << std::endl;
        std::cout << "adaEps = " << ada_eps_ << std::endl;
        std::cout << "adaAlpha = " << ada_alpha_ << std::endl;
        std::cout << "regParameter = " << reg_parameter_ << std::endl;
        std::cout << "dropProb = " << drop_prob_ << std::endl;

        std::cout << "hiddenSize = " << hidden_size_ << std::endl;
        std::cout << "wordEmbSize = " << word_emb_size_ << std::endl;
        std::cout << "wordcontext = " << word_context_ << std::endl;
        std::cout << "wordEmbFineTune = " << word_emb_size_ << std::endl;

        std::cout << "cnnLayerSize = " << cnn_layer_size_ << std::endl;
        std::cout << "verboseIter = " << verbose_iter_ << std::endl;
        std::cout << "saveItermediate = " << save_inter_mediate_ << std::endl;
        std::cout << "train = " << train_ << std::endl;
        std::cout << "maxInstance = " << max_instance_ << std::endl;
        for (int idx = 0; idx < test_files_.size(); idx++) {
            std::cout << "testFile = " << test_files_.at(idx) << std::endl;
        }
        std::cout << "outBest = " << out_best_ << std::endl;
        std::cout << "seg = " << seg_ << std::endl;
        std::cout << "wordFile = " << word_file_ << std::endl;
    }

    void load(const std::string &in_file) {
        std::ifstream inf;
        inf.open(in_file.c_str());
        std::vector<std::string> vec_line;
        while (1) {
            std::string str_line;
            if (!my_getline(inf, str_line)) {
                break;
            }
            if (str_line.empty()) {
                continue;
            }
            vec_line.push_back(str_line);
        }
        inf.close();
        setOptions(vec_line);
    }
};

#endif //  BASIC_OPTIONS_H_
