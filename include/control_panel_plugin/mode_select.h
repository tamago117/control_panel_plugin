#pragma once

#ifndef Q_MOC_RUN
    #include <ros/ros.h>
#endif

#include <rviz/panel.h>
#include <std_msgs/String.h>

namespace Ui {
class mode_select;
}

namespace control_panel_plugin{

class modeSelect : public rviz::Panel
{
    Q_OBJECT
public:
    modeSelect(QWidget *parent = nullptr);
    ~modeSelect() override;

    void onInitialize() override;
    void onEnable();
    void onDisable();

private Q_SLOTS:
    void startButtonClicked();
    void stopButtonClicked();

protected:
    Ui::mode_select* ui;
    std_msgs::String message;

    ros::NodeHandle nh;
    ros::Publisher pub;
};

}//namespace control_panel_plugin


