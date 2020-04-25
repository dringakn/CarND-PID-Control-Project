# Car Steering Angle Control Using PID-Controller
![Example][video1]
**Overview**

The goal of this project is to keep the car driving in the middle of the road, between the middle of lanes. For the purpose of automatic car steering control, a classical PID control algorithm is implemented using C++. For the code implementation the reader may refer ![Main][MainCode] and ![PID][PIDCode]

---

[MainCode]: https://github.com/dringakn/CarND-PID-Control-Project/blob/master/src/main.cpp

[PIDCode]: https://github.com/dringakn/CarND-PID-Control-Project/blob/master/src/PID.cpp

[//]: # (Image References)

<!-- [image1]: ./examples/.png "Image" -->
[video1]: ./examples/Car_Steering_Angle_Control_Using_PID-Controller.gif "Video"

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Reflection:

The response of the vehicle control depends on the parameters (Kp, Ki, Kd). In order to tune the values the parameters are passed as command line arguments.

Here are some guidlines for the tunning:
 * The value of Kp react to the CTE (Cross Tracke Error), i.e. the vehicle offset from the middle of the lanes. The higher the value, the more stronger the car will react on the error. A too much higher value results into oscillatory behaviours.
 * The value of Kd helps to supress the oscillations. The higher the value, the stronger it damps the oscillation. However, care must be taken in case the inputs are noise, which may leads to destablization.
 * Only the values of Kp and Kd are not enought to bring the vehicle to steady state, i.e. the middle of the lanes. Th value of Ki help to bring it to center position. The  higher the value, the stronger it reacts. However, if the value is too high, it bring unstablity (Oscillatory behaviour).
 * Another important parameters is the ILimit. This is to limit the error due to integration. Sometimes, it is also called integral wind-up error. In case if the error is keep-on increasing, it leads to unbounded growth of the error, which may takes a lot of time to come back to zero, therefor, may leads to unstability.
 * Ofcourse, these values assumes that the response of our car remains same throughout it's life. However, in case of wear and tear and external disturbances (road/evniorment constions, winds, slippary road, snow etc). It's response must be tunned. Therefore, to overcome these limitations, one may use adaptive PID tunning parameters.
 * Currently, the parameters are tunned by hit and trial method. First the Kp values are increased until a oscillatory response is observed, while keeping the other two to zero. Then the Kd value is increased until oscillatory response is damped while keeping the same Kp value. And finally, the Ki value is increased until stead-state error is minimized. For more information the reader may look at Ziegler Nichlos method for tunning.
