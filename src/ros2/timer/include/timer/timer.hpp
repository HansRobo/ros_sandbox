// Copyright (c) 2021 Kotaro Yoshimoto
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef TIMER__TIMER_HPP_
#define TIMER__TIMER_HPP_

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "timer/visibility_control.h"

class TimerComposite : public rclcpp::Node
{
public:
  COMPOSITION_PUBLIC
  explicit TimerComposite(const rclcpp::NodeOptions & options) : rclcpp::Node("timer_node",options){
    using namespace std::chrono_literals;
    timer_ = create_wall_timer(1s,std::bind(&ReceivePlanner::timerCallback, this));
    timer_ = create_wall_timer(1s,[](){
      std::cout << "Hello World! This is from a lambda function" << std::endl;
    })
  }

  void timerCallback(){
    std::cout << "Hello World! This is from a member function" << std::endl;
  }
private:
  rclcpp::TimerBase::SharedPtr timer_member_func_;
  rclcpp::TimerBase::SharedPtr timer_lambda_func_;
};

#endif  // TIMER__TIMER_HPP_
