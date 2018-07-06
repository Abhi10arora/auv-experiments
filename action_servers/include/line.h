#ifndef LINE_H
#define LINE_H

#include <ros/ros.h>

#include <action_servers/sidewardPIDAction.h>
#include <action_servers/anglePIDAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include <geometry_msgs/PointStamped.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>

#include <boost/thread.hpp>
#include <string>

#include <move_forward_server.h>
#include <straight_server.h>

class lineTask {
public:
    lineTask(double);
    ~lineTask();
    void setActive(bool);
    void angleCB(const geometry_msgs::Pose2D::ConstPtr &_msg);

private:
    actionlib::SimpleActionClient<action_servers::sidewardPIDAction> sidewardPIDClient;
    actionlib::SimpleActionClient<action_servers::anglePIDAction> anglePIDAction;
    moveForward move_forward_;
    moveStraight move_straight_;
    ros::Subscriber sub_;
    ros::NodeHandle nh_;
    double angle;
    boost::thread* spin_thread;
    action_servers::sidewardPIDGoal sideward_PID_goal;
    action_servers::upwardPIDGoal upward_PID_goal;
    action_servers::anglePIDGoal angle_PID_goal;

};
#endif // LINE_H
