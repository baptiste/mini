#include "a.h"
#include <iostream>
#include "Rcpp.h"

using namespace Rcpp ;
using namespace std;

  
void progress_bar(double x, double N)
  {
    // how wide you want the progress meter to be
    int totaldotz=40;
    double fraction = x / N;
    // part of the progressmeter that's already "full"
    int dotz = round(fraction * totaldotz);
    
    // create the "meter"
    int ii=0;
     Rprintf("%3.0f%% [",fraction*100);
    // part  that's full already
    for ( ; ii < dotz;ii++) {
      Rcpp::Rcout << "=";
    }
    // remaining part (spaces)
    for ( ; ii < totaldotz;ii++) {
       Rprintf(" ");
    }
    // and back to line begin - 
    // do not forget the fflush to avoid output buffering problems!
    Rprintf("]\r");
    // fflush(stdout);
  }
  

RCPP_MODULE(a){
       Rcpp::function( "progress_bar", &progress_bar, 
		       "Progress bar" ) ;
}
