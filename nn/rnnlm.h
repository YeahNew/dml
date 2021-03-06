/* ========================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename : rnnlm.h
 *   author   : liuzhiqiangruc@126.com
 *   date     : 2016-12-07
 *   info     : rnnlm implemtation using sgd per token
 * ======================================================== */

#ifndef _RNNLM_H
#define _RNNLM_H

#include "hsoft.h"
#include "tsdata.h"
#include "rnn_config.h"

typedef struct _rnn_lm{
    TSD       * ds;         // data set for training
    HSoft     * hsf;        // hierarchical soft max optimized
    struct {
        double *u;          // input embeddings
        double *w;          // shared rec parameter
        double *s;          // last k hidden status
    } rnn;                  // model parameters
    RNNConfig * rc;         // rnnlm command line configure
} RNNLM;


// create a rnnlm model
// init the rnnlm environment using command line
RNNLM * rnn_create(int argc, char *argv[]);

// start status of rnnlm
int     rnn_init  (RNNLM * rnnlm);

// learn the rnnlm model parameters
void    rnn_learn (RNNLM * rnnlm);




#endif //RNNLM_H
