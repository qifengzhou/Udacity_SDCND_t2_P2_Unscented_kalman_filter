#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    VectorXd rmse(4);
    rmse << 0,0,0,0;

    // Check the validity of the inputs:
    // the estimation vector size should not be zero
    // the estimation vector size should equal the ground truth vector
    if (estimations.size() != ground_truth.size() || estimations.size() == 0){
        cout << "Invalid estimation or ground_truth data" << endl;
        return rmse;
    }

    //accumulate squared residuals
    for (unsigned int i = 0; i < estimations.size(); ++i){
        VectorXd residual = estimations[i] - ground_truth[i];
        //coefficient-wise mutiplication
        residual = residual.array()*residual.array();
        rmse += residual;
    }

    //calculate the mean
    rmse = rmse/estimations.size();
    cout<<estimations.size()<<"\n";
    //calculate the squared root
    rmse = rmse.array().sqrt();
    return rmse;

}
