# proto2rosbag

## 一、安装教程

```
# 添加ROS源
sudo add-apt-repository ppa:ros-for-jammy/noble
# 更新源
sudo apt update -y && sudo apt upgrade -y
# 安装ROS包
sudo apt install ros-noetic-desktop-full -y
```

## 二、创建ROS项目

```
# 创建工作空间
mkdir -p demo/src
cd demo

# 初始化工作空间
catkin_make

# 创建功能包
cd src
catkin_create_pkg demo roscpp rosmsg
```


## 三、示例代码

### 1、写入bag文件

```
int main(int argc, char *argv[]) {
    ros::init(argc, argv, "demo");
    ros::NodeHandle nh;
    std::cout << "Hello, World!" << std::endl;
    rosbag::Bag bag;
    bag.open("build/demo.bag", rosbag::bagmode::Write);
    demo_msgs::User ros_msg;
    ros_msg.name = "demo";
    ros_msg.age = 26;
    std::string topic = "myTopic"; 
    bag.write(topic, ros::Time::now(), ros_msg);
    bag.write(topic, ros::Time::now(), ros_msg);
    bag.write(topic, ros::Time::now(), ros_msg);
    bag.write(topic, ros::Time::now(), ros_msg);
    bag.write(topic, ros::Time::now(), ros_msg);
    bag.close();
    ros::spinOnce();
    
    return 0;
}
```