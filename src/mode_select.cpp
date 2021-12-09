#include <pluginlib/class_list_macros.h>

#include <control_panel_plugin/mode_select.h>
#include <control_panel_plugin/robot_status.h>
#include "ui_mode_select.h"

namespace control_panel_plugin
{

modeSelect::modeSelect(QWidget *parent) : Panel(parent), ui(new Ui::mode_selectUI())
{
    ui->setupUi(this);

    pubpose.pose.covariance[0]=0.25;
    pubpose.pose.covariance[7]=0.25;
    pubpose.pose.covariance[35]=0.06853891945200942;
}

modeSelect::~modeSelect() = default;

void modeSelect::onInitialize()
{
    connect(ui->run, SIGNAL(clicked()), this, SLOT(startButtonClicked()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(stopButtonClicked()));
    connect(ui->dial_delay, SIGNAL(valueChanged(int)), this, SLOT(dialValueChanged(int)));
    connect(ui->poseEstimate, SIGNAL(clicked()), this, SLOT(poseEstimateButtonClicked()));
    connect(ui->spinBox_wayPoint, SIGNAL(valueChanged(int)), this, SLOT(wayPointNumberChanged(int)));
    connect(ui->restart, SIGNAL(clicked()), this, SLOT(restartButtonClicked()));
    connect(ui->lineEdit_wpTopic, SIGNAL(textChanged()), this, SLOT(wpTopic_lineEditChanged()));
    //connect(ui-> (qt object name) , SIGNAL( object action ), this, SLOT( function ));

    mode_pub = nh.advertise<std_msgs::String>("mode_select/mode", 1);
    initial_pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose", 1);
    parentWidget()->setVisible(true);
}

void modeSelect::onEnable()
{
    show();
    parentWidget()->show();
}

void modeSelect::onDisable()
{
    hide();
    parentWidget()->hide();
}

void modeSelect::startButtonClicked()
{
    message.data = robot_status_str(robot_status::run);
    
    run_timer = nh.createTimer(ros::Duration(delayTime), &modeSelect::runPublish, this, true);
}

void modeSelect::runPublish(const ros::TimerEvent& e)
{
    message.data = robot_status_str(robot_status::run);
    mode_pub.publish(message);
    //run_timer.stop();

    ROS_INFO("mode : run");
}

void modeSelect::stopButtonClicked()
{
    message.data = robot_status_str(robot_status::stop);
    mode_pub.publish(message);
}

void modeSelect::dialValueChanged(int value)
{
    ui->lcdNumber_delay->display(value);
    delayTime = value;
    ROS_INFO("next command sent after %d s",value);
}

void modeSelect::poseEstimateButtonClicked()
{
    static geometry_msgs::Pose pose;
    pose.position.x = 0.0f;
    pose.position.y = 0.0f;
    pose.position.z = 0.0f;
    pose.orientation.w = 1.0f;
    pose.orientation.x = 0.0f;
    pose.orientation.y = 0.0f;
    pose.orientation.z = 0.0f;

    pubpose.pose.pose = pose;
    pubpose.header.stamp = ros::Time::now();
    pubpose.header.frame_id = "base_link";

    initial_pub.publish(pubpose);
}

}//namespace control_panel_plugin

PLUGINLIB_EXPORT_CLASS(control_panel_plugin::modeSelect, rviz::Panel )

