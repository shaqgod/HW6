#include<ros/ros.h>
#include<stdio.h>
#include<stdlib.h>
#include <std_srvs/Empty.h>

void show_all_bg_color(ros::NodeHandle NodeHandler)
{
    int bg_color_r, bg_color_g, bg_color_b;
    NodeHandler.getParam("/background_r", bg_color_r);
    NodeHandler.getParam("/background_g", bg_color_g);
    NodeHandler.getParam("/background_b", bg_color_b);

    
    ROS_INFO("bg_color_r = %d", bg_color_r);
    ROS_INFO("bg_color_g = %d", bg_color_g);
    ROS_INFO("bg_color_b = %d", bg_color_b);
}

void set_bg_color(ros::NodeHandle NodeHandler, int r, int g, int b)
{
    NodeHandler.setParam("/background_b", b);
    NodeHandler.setParam("/background_g", g);
    NodeHandler.setParam("/background_r", r);
    // NodeHandler.setParam("/self_param1", b);
}


int main( int argc, char ** argv ) 
{
    ros::init(argc, argv, "rw_turtle_bg_color");
    ros::NodeHandle nh;
    
    // 等待clear服務啟動
    ros::service::waitForService("clear");

    // setting parameter
    show_all_bg_color(nh);
    set_bg_color(nh, 50, 150, 120);
    system("rosparam load /home/shaq/gitHW/src/HW5/config/turtle_color.yaml");
    show_all_bg_color(nh);

    // 輸出與載入設定好的參數
    system("rosparam dump /home/shaq/gitHW/src/HW5/config/turtle_color.yaml");
    
    // 宣告與呼叫service
    ros::ServiceClient clear_client = nh.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty srv;
    clear_client.call(srv);


    
}





