#include <pluginlib/class_list_macros.h>
#include <std_msgs/String.h>

#include <control_panel_plugin/mode_select.h>
#include "control_panel_plugin/ui_mode_select.h"

namespace control_panel_plugin
{

modeSelect::modeSelect(QWidget *parent) : Panel(parent), ui(new Ui::mode_select())
{
    ui->setupUi(this);
}

modeSelect::~modeSelect() = default;

void modeSelect::onInitialize()
{
    connect(ui->run, SIGNAL(clicked()), this, SLOT(startButtonClicked()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(stopButtonClicked()));
    //connect(ui-> (qt object name) , SIGNAL( object action ), this, SLOT( function ));

    pub = nh.advertise<std_msgs::String>("mode_select/mode", 1);
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
    message.data = "run";
    pub.publish(message);
}

void modeSelect::stopButtonClicked()
{
    message.data = "stop";
    pub.publish(message);
}

}//namespace control_panel_plugin

PLUGINLIB_EXPORT_CLASS(control_panel_plugin::modeSelect, rviz::Panel )

