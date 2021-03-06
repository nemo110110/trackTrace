#ifndef UTIL_SIFT_H
#define UTIL_SIFT_H

#include <opencv2/core/core.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

class UTIL_Sift
{
private:
    static void sifts(const cv::Mat &img,
               int keyPointSize,
               int density,
               bool rSift,
               bool filterDescriptors,
               float thresholdFilter,
               cv::Mat &descriptors,
               std::vector<cv::KeyPoint> &keyPoints);
    static void siftsRegions(const cv::Mat &img,
                      int keyPointSize,
                      int density,
                      bool rSift,
                      bool filterDescriptors,
                      float thresholdFilter,
                      cv::Mat &descriptors,
                      std::vector<cv::KeyPoint> &keyPoints);
public:
    static void createKeyPoints(const cv::Mat &img,
                                int keyPointSize,
                                int density,
                                std::vector<cv::KeyPoint> &keyPoints);
    static void siftsGrid(const cv::Mat &img,
                          int keyPointSize,
                          int density,
                          std::vector<cv::KeyPoint> &keyPoints,
                          cv::Mat &descriptors);
    static void computeSift(const cv::Mat &img,
                            std::vector<cv::KeyPoint> &keyPoints,
                            cv::Mat &descriptors);
    static void siftsAutodetec(const cv::Mat &img,
                               std::vector<cv::KeyPoint> &keyPoints,
                               cv::Mat &descriptors);
    static void filterDescriptorsSift(cv::Mat &descriptors,
                                      std::vector<cv::KeyPoint> &keyPoints,
                                      float threshold);
    static void computeAndDetectSift(const cv::Mat &img,
                                     std::vector<cv::KeyPoint> &keyPoints,
                                     cv::Mat &descriptors,
                                     std::vector<float> &scores);
    static void scoresDescriptorsSift(cv::Mat &descriptors,
                                      std::vector<float> &scores);

    static void descriptorsSift(const cv::Mat &img,
                          int keyPointSize,
                          int density,
                          bool rSift,
                          bool filterDescriptors,
                          float thresholdFilter,
                          bool region,
                          cv::Mat &descriptors,
                          std::vector < cv::KeyPoint > &keyPoints);

    static void rootSift(cv::Mat &descriptors);

    static void saveDescriptorsSiftDir(std::vector<std::string> &files,
                                       int keyPointSize,
                                       int density,
                                       bool rSift,
                                       bool filterDescriptors,
                                       bool region,
                                       float thresholdFilter);

    static void saveDescriptorsSiftPCADir(std::vector<std::string> &files,
                                          int keyPointSize,
                                          int density,
                                          bool rSift,
                                          bool filterDescriptors,
                                          float thresholdFilter,
                                          bool region,
                                          cv::PCA &pca);


};

#endif // UTIL_SIFT_H
