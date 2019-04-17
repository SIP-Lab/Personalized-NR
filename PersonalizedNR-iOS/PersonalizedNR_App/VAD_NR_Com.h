//
//  NoiseReduction.h
//  NoiseReduction
//
//  Created by Abhishek Sehgal on 8/14/17.
//  Modified by Nasim Alamdari on 07/30/2018
//  Copyright © 2017 SIPLab. All rights reserved.
//

#ifndef VAD_NR_Com_h
#define VAD_NR_Com_h

#include <stdio.h>
#include <math.h>
#include "FIRFilter.h"
#include "MelSpectrogram.h"
#include "Transforms.h"
#include "SPLBuffer.h"
#include "Settings.h"
#include "rt_nonfinite.h"
#include "wiener_ADAPTIVE_NE.h"
#include "wiener_ADAPTIVE_NE_terminate.h"
#include "wiener_ADAPTIVE_NE_initialize.h"
#include "DynamicRangeFiveBandCompression.h"
#include "DynamicRangeFiveBandCompression_initialize.h"
#include "DynamicRangeFiveBandCompression_terminate.h"
#include "Art2FusionClassifier.h"
#include "SubbandFeatures.h"
#include "Equalizer.h"


extern float dataIn[20];

#define DECIMATION_FACTOR 3
#define EPS 1.0e-7
#define S2F 3.051757812500000e-05f
#define F2S 32768

#define NFILT               40
#define FREQLOW             300
#define FREQHIGH            8000

typedef struct VADNoiseReductionCompression {
    
    int stepSize;
    int decimatedStepSize;
    int samplingFrequency;
    
    float* input;
    float* downsampled;
    float* decimated;
    float* processed;
    float* frame;
    
    float* compressed;
    
    float* interpolated;
    float* output;
    
    long* memoryPointer;
    
    MelSpectrogram* melSpectrogram;
    SubbandFeatures* sbf;
    Transform* fft;
    
    
    FIR* downsampleFilter;
    FIR* interpolationFilter;
    // For audio level
    SPLBuffer* spl;
    
    //for classifier
    int firstFrame;
    int count;
    int VADClass;
    int ClusterLabel;
    int previousDetectedClass;
    int totalClusters;
    int warmUp;
    const char* className;
    float* AllFeaturesVector;
    float* sumBufferMFSC;
    Equalizer* Equalization;
    //--------- Art2 Noise Classifier --------------
    int NewClusterCreationBufferSize;
    int DecisionSmoothingBufferSize;
    Art2FusionParallel* Art2Fusion;
    //----------------------------------------------
    
} VADNoiseReductionCompression;


VADNoiseReductionCompression* initVAD_NoiseReduction_Compression(Settings* settings, const char *NoiseClassifierFile, const char *UserBandGainsFile);
void doNoiseReduction_Compression_withVAD(VADNoiseReductionCompression *_ptr, short *_in, short* _out, Settings* settings);
void destroyVAD_NoiseReduction_Compression(VADNoiseReductionCompression** _ptr);
//int getClusterLabel (VADNoiseReductionCompression *_ptr);
//int getPreviousClusterLabel (VADNoiseReductionCompression *_ptr);
//int getTotalClusters(VADNoiseReductionCompression *_ptr);
#endif /* VAD_NR_Com_h */
