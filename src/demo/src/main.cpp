#include <iostream>
#include <ros/ros.h>
#include <rosbag/bag.h>

#include "remap.h"

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "demo");
    ros::NodeHandle nh;

    proto::User pb_user;
    pb_user.set_name("pb_user");
    pb_user.set_age(20);
    demo::User ros_user;
    RemapFunc<proto::User, demo::User>(pb_user, ros_user);
    std::cout << "RemapFunc name: " << ros_user.name << ", age: " << ros_user.age << std::endl;

    proto::Data pb_data;
    pb_data.set_data("pb_data");
    demo::Data ros_data;
    RemapFunc<proto::Data, demo::Data>(pb_data, ros_data);
    std::cout << "RemapFunc data: " << ros_data.data << std::endl;

    std::string topic_user = "ros_user";
    std::string topic_data = "ros_data";
    rosbag::Bag bag;
    bag.open("build/demo.bag", rosbag::bagmode::Write);
    ros::Rate rate(1);
    bag.write(topic_user, ros::Time::now(), ros_user);
    rate.sleep();
    bag.write(topic_data, ros::Time::now(), ros_data);
    rate.sleep();
    bag.close();

    ros::spinOnce();
    
    return 0;
}
