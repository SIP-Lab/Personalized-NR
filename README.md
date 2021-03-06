# Personalized Noise Reduction and Compression Smartphone App for Hearing Enhancement

This GitHub repository is the code accompaniment of the following paper:
> **A Real-Time Personalized Noise Reduction Smartphone App for Hearing Enhancement**<br>
> Nasim Alamdari, Shashank Yaraganalu, and Nasser Kehtarnavaz - University of Texas at Dallas<br>
> https://ieeexplore.ieee.org/abstract/document/8615620<br>
>
> **Abstract:** This paper presents the development of a personalized noise reduction app that is designed to run in real-time with low-latency on smartphone platforms for hearing enhancement purposes. The personalization is achieved by using an unsupervised noise classifier together with a personalized gain adjustment. After applying a Wiener filtering noise reduction, gains in five frequency bands are adjusted by the user to achieve personalized noise reduction depending on the noise environment identified by the classifier. The other signal processing modules of the app include voice activity detection and compression. Publicly available datasets of speech signals and commonly encountered noise signals are used to test the effectiveness of the app. The results obtained by computing a widely used objective speech quality measure indicate the effectiveness of the app for noise reduction.

## Resources

Supporting materials related to this work are available via the following links:

|**Link**|Description
|:-------|:----------
|https://ieeexplore.ieee.org/abstract/document/8615620| IEEE Manuscript
|http://www.utdallas.edu/~kehtar/PersonalizedNRapp.mp4| Videoclip demonstrating the Personalized Noise Reduction app running in real-time on smartphone platforms


## Getting Started

A [User's Guide](Users-Guide-PersonalizedNoiseReduction.pdf) is provided which describes how to run the codes of the personalized noise reduction together with compression on smartphone platforms.

## Requirement
1. To run the Android version of the Personalized Noise Reduction app, it is necessary to have Superpowered SDK which can be obtained from the following link: https://superpowered.com.
Then, need to add the path of Superpowered in gradle/local.properties:
    
        superpowered.dir = /.../SuperpoweredSDK/Superpowered

2. To run the iOS version of the Personalized Noise Reduction app, it is necessary to have Tensorflow C++ API for the Voice Activity Detection (VAD). The Tensorflow API can be downloaded or cloned from this link: https://www.tensorflow.org/install/

## License and Citation
The codes are licensed under MIT license.

For any utilization of the code content of this repository, the following paper needs to get cited by the user:

- N. Alamdari, S. Yaraganalu, and N. Kehtarnavaz, "A real-time personalized adaptive noise reduction smartphone app for realistic audio environments," Proceedings of IEEE Signal Processing in Medicine and Biology Symposium (SPMB), Philadelphia, PA, Dec 2018.

