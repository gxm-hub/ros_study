#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>



int main(int argc,char **argv)
{
   //std::cout<<"Hello world"<<std::endl;
    ros::init(argc, argv,"client");
    //add_two_ints_client文件名
    if(argc!=3)
    {
        ROS_INFO("usage: client X,Y");
        return 1;
    }
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
    //<begin... 模板 >(add_two_ints这里是发布到结点上)
    beginner_tutorials::AddTwoInts srv;
    srv.request.a=atol(argv[1]);
    srv.request.b=atol(argv[2]);
    if(client.call(srv))
    {
        ROS_INFO("c: %ld",(long int)srv.response.c);
//类似于printf,ros还有info，error
    }
    else
    {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
    }
    return 0;  
}
